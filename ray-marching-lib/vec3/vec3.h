#pragma once

typedef struct Vec3
{
    float x;
    float y;
    float z;
} Vec3;

static inline Vec3 vec3_create(float x, float y, float z)
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

static inline void vec3_multiply_scalar(Vec3 *a, float scalar)
{
    a->x *= scalar;
    a->y *= scalar;
    a->z *= scalar;
}

static inline Vec3 vec3_multiply_scalar_copy(const Vec3 *a, float scalar)
{
    return vec3_create(a->x * scalar, a->y * scalar, a->z * scalar);
}

void vec3_step(Vec3 *a, const Vec3 *direction, float stepSize);