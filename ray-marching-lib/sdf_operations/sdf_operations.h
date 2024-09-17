#pragma once

#include <math.h>

static inline float sdf_op_union(float a, float b)
{
    return fminf(a, b);
}

static inline float sdf_op_smooth_union(float a, float b, float k)
{
    float h = fmax(k - fabsf(a - b), 0.0) / k;
    return fminf(a, b) - h * h * h * k * (1.0 / 6.0);
}

// TODO: subtraction
// TODO: intersection