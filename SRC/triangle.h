//
// Created by amagood on 2020/3/25.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "hittable.h"

using namespace std;
vec3 center(200.0, 250.0, 300.0);

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

};

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
    if(u<000||u>1.0)
        return false;
    vec3 q = cross(s,edge1);
    double v = f * dot(r.direction(),q);
    if(v<0.0||u+v>1.0)
        return false;

    float t = f * dot(edge2, q);
    if(t>0.0000001)
    {
        //outPoint = r.origin() + r.direction() * t;
        rec.p = r.origin() + r.direction() * t;
        rec.t = t;
        rec.u = v;
        rec.v = u;
        //rec.p = r.point_at_parameter(rec.t);
        vec3 tmp = (rec.p - center);
        tmp.make_unit_vector();

        vec3 normal = unit_vector(cross(edge1,edge2));
        if(acos(dot(normal, tmp)) > 90.0 *M_PI/180.0)
            normal *= -1;
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

    box = aabb(vec3(minX,minY,minZ), vec3(maxX,maxY,maxZ));
}

#endif //TRIANGLE_H
