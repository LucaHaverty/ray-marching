#pragma once

typedef struct Vec3
{
    double x;
    double y;
    double z;
} Vec3;

static inline Vec3 vec3_create(double x, double y, double z)
{
    Vec3 newVector = {x, y, z};
    return newVector;
}

static inline void vec3_add(Vec3 *a, const Vec3 *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

static inline void vec3_multiply_scalar(Vec3 *a, double scalar)
{
    a->x *= scalar;
    a->y *= scalar;
    a->z *= scalar;
}

static inline Vec3 vec3_multiply_scalar_copy(const Vec3 *a, double scalar)
{
    return vec3_create(a->x * scalar, a->y * scalar, a->z * scalar);
}

void vec3_step(Vec3 *a, const Vec3 *direction, double stepSize);