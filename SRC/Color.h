//
// Created by amagood on 2020/4/21.
//

#ifndef THENEXTWEEKEND_COLOR_H
#define THENEXTWEEKEND_COLOR_H

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include "vec3.h"

double cauchyRefractionIndex(double lambda, double B, double C);
void XYZ2RGB(float X, float Y, float Z, float *R, float *G, float *B);
void RGB2XYZ(float R, float G, float B, float *X, float *Y, float *Z);

class spectralTable
{
private:
    static __gnu_pbds::gp_hash_table<int, vec3> table;

public:
    inline spectralTable();
    [[nodiscard]] inline vec3 getXYZ(int lambda);

};


#endif //THENEXTWEEKEND_COLOR_H
