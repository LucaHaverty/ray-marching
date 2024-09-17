#pragma once

#include "../vec3/vec3.h"
#include "../quaternion/quaternion.h"

static inline float sdf_prim_sphere(Vec3 *point, float radius)
{
    return vec3_magnitude(point) - radius;
}

// static inline float sdf_prim_box(Vec3 point, Vec3 scale)
// {
//     Vec3 q = fabsf(p) - vec3_multiply_scalar(scale, 0.5);
//     return length(fmaxf(q, 0.0)) + fminf(fmaxf(q.x, fmaxf(q.y, q.z)), 0.0);
// }