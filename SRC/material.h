#ifndef MATERIALH
#define MATERIALH
//==================================================================================================
// Written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is distributed
// without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication along
// with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==================================================================================================

#include "hittable.h"
#include "ray.h"
#include "texture.h"
#include "random.h"
#include "Color.h"

float schlick(float cosine, float ref_idx) {
    float r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}

bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted) {
    vec3 uv = unit_vector(v);
    float dt = dot(uv, n);
    float discriminant = 1.0 - ni_over_nt*ni_over_nt*(1-dt*dt);
    if (discriminant > 0) {
        refracted = ni_over_nt*(uv - n*dt) - n*sqrt(discriminant);
        return true;
    }
    else
        return false;
}


vec3 reflect(const vec3& v, const vec3& n) {
     return v - 2*dot(v,n)*n;
}


vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0*vec3(random_double(),random_double(),random_double()) - vec3(1,1,1);
    } while (dot(p,p) >= 1.0);
    return p;
}


class material  {
    public:
        bool isLaser = false;
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
        virtual vec3 emitted(float u, float v, const vec3& p) const {
            return vec3(0,0,0); }
};

class diffuse_light : public material  {
    public:
        //bool isLaser = true;
        diffuse_light(texture *a) : emit(a) {
            isLaser = true;
        }
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const { return false; }
        virtual vec3 emitted(float u, float v, const vec3& p) const { return emit->value(u, v, p); }
        texture *emit;
};


class isotropic : public material {
    public:
        isotropic(texture *a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const  {
             scattered = ray(rec.p, random_in_unit_sphere(), r_in.ray_wavelength(), r_in.time());
             attenuation = albedo->value(rec.u, rec.v, rec.p);
             return true;
        }
        texture *albedo;
};

class lambertian : public material {
    public:
        lambertian(texture *a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const  {
             vec3 target = rec.p + rec.normal + random_in_unit_sphere();
             scattered = ray(rec.p, target-rec.p, r_in.ray_wavelength(), r_in.time());
             attenuation = albedo->value(rec.u, rec.v, rec.p);
             return true;
        }

        texture *albedo;
};

class metal : public material {
    public:
        metal(const vec3& a, float f) : albedo(a) { if (f < 1) fuzz = f; else fuzz = 1; }
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const  {
            vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
            scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere(), r_in.ray_wavelength(), r_in.time());
            attenuation = albedo;
            return (dot(scattered.direction(), rec.normal) > 0);
        }
        vec3 albedo;
        float fuzz;
};

class dielectric : public material {
public:
    dielectric(int ri) : glass_type(ri) {} // 0~5
    double B_C[6][2] = {{1.4580, 0.00354},{1.5046, 0.00420},{1.5220, 0.00459},{1.5690, 0.00531},{1.6700, 0.00743},{1.7280, 0.01342}};
    virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const  {
        vec3 outward_normal;
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        float ni_over_nt = cauchyRefractionIndex(r_in.ray_wavelength()/1000.0, B_C[glass_type][0], B_C[glass_type][1]);
        attenuation = vec3(1.0, 1.0, 1.0);
        vec3 refracted;
        float reflect_prob;
        float cosine;
        if (dot(r_in.direction(), rec.normal) > 0) {
            outward_normal = -rec.normal;
            //ni_over_nt = ref_idx;
            cosine = ni_over_nt * dot(r_in.direction(), rec.normal) / r_in.direction().length();
        }
        else {
            outward_normal = rec.normal;
            ni_over_nt = 1.0 / ni_over_nt;
            cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
        }
        if (refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) {
            reflect_prob = schlick(cosine, ni_over_nt);
        }
        else {
            scattered = ray(rec.p, reflected, r_in.ray_wavelength(), r_in.time());
            reflect_prob = 1.0;
        }
        if (random_double() < reflect_prob) {
            scattered = ray(rec.p, reflected, r_in.ray_wavelength(), r_in.time());
        }
        else {
            scattered = ray(rec.p, refracted, r_in.ray_wavelength(), r_in.time());
        }
        return true;
    }

    float ref_idx;
    int glass_type;
};

#endif

