//
// Created by amagood on 2020/3/25.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "hittable.h"

using namespace std;
vec3 center(277.5,100.0,250.0);

class Triangle : public hittable
{
private:
    vector<vec3> points;
    material *mat_ptr;

public:
    Triangle()= default;
    Triangle(vector<vec3> pointsInput, material *m)
    {
        points = pointsInput;
        mat_ptr = m;
    }
    bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const final;
    bool bounding_box(float t0, float t1, aabb& box) const final;
    [[nodiscard]] double shalloest() const final
    {
        double a = points[0].z(), b = points[1].z(), c = points[2].z();
        return (a<b)? (a<c?a:c) : (b<c?b:c);
    }

    string getShapeInfo() const final;

};
string Triangle::getShapeInfo() const
{
    return "triangle";
}
bool Triangle::hit(const ray& r, float tmin, float tmax, hit_record& rec) const
{
    vec3 edge1 = points[1] - points[0];
    vec3 edge2 = points[2] - points[0];
    vec3 h = cross(r.direction(),edge2);
    double a = dot(edge1,h);

    if(fabs(a)<0.0000001)
        return false;
    double f = 1.0/a;
    vec3 s = r.origin() - points[0];
    double u = f * (dot(s,h));
    if(u<0.0||u>1.0)
        return false;
    vec3 q = cross(s,edge1);
    double v = f * dot(r.direction(),q);
    if(v<0.0||u+v>1.0)
        return false;

    float t = f * dot(edge2, q);
    if(t>0.0)
    {
        //outPoint = r.origin() + r.direction() * t;
        //rec.p = r.origin() + r.direction() * t;
        rec.p = r.point_at_parameter(t);
        rec.t = t;
        rec.u = u;
        rec.v = v;
        //rec.p = r.point_at_parameter(rec.t);
        vec3 tmp = (rec.p - center);
        tmp.make_unit_vector();

        vec3 normal = unit_vector(cross(edge1,edge2));
        if(dot(normal, tmp) < 0)
        {
            normal *= -1;
        }
        rec.normal = normal;
        //rec.normal = unit_vector(cross(edge1,edge2));
        rec.mat_ptr = mat_ptr;
        return true;
    }
    return false;
}
float min3(float a,float b, float c)
{
    float minAB=a<b?a:b;
    return minAB<c?minAB:c;
}
float max3(float a,float b, float c)
{
    float maxAB = a>b?a:b;
    return maxAB>c?maxAB:c;
}
bool Triangle::bounding_box(float t0, float t1, aabb& box) const
{
    float minX = min3(points[0].x(),points[1].x(),points[2].x());
    float minY = min3(points[0].y(),points[1].y(),points[2].y());
    float minZ = min3(points[0].z(),points[1].z(),points[2].z());

    float maxX = max3(points[0].x(),points[1].x(),points[2].x());
    float maxY = max3(points[0].y(),points[1].y(),points[2].y());
    float maxZ = max3(points[0].z(),points[1].z(),points[2].z());

    box = aabb(vec3(300.0,5.0,50.0), vec3(400.0,305.0,136.6));
    return true;
}

#endif //TRIANGLE_H
