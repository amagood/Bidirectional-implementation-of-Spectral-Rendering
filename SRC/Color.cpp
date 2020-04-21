//
// Created by amagood on 2020/4/21.
//

#include "Color.h"
#include <cmath>

#define CLAMP0255_XY(x, y) (((x) < 0) ? 0 : ((x) > (y) ? (y) : (x)))

double cauchyRefractionIndex(double lambda, double B, double C)
{
    return  B + C / pow(lambda, 2.0);
}


void RGB2XYZ(float R, float G, float B, float *X, float *Y, float *Z)
{
    *X = 0.412453f * R + 0.357580f * G + 0.180423f * B;
    *Y = 0.212671f * R + 0.715160f * G + 0.072169f * B;
    *Z = 0.019334f * R + 0.119193f * G + 0.950227f * B;
}


void XYZ2RGB(float X, float Y, float Z, float *R, float *G, float *B)
{
    float RR, GG, BB;
    RR =  3.240479f * X - 1.537150f * Y - 0.498535f * Z;
    GG = -0.969256f * X + 1.875992f * Y + 0.041556f * Z;
    BB =  0.055648f * X - 0.204043f * Y + 1.057311f * Z;

    *R = CLAMP0255_XY(RR, 1.0f);
    *G = CLAMP0255_XY(GG, 1.0f);
    *B = CLAMP0255_XY(BB, 1.0f);
}

