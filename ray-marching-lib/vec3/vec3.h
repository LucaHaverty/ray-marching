#pragma once

#include <math.h>

typedef struct Vec3
{
    float x;
    float y;
    float z;
} Vec3;

/** Creates a new vector with the given components. */
static inline Vec3 vec3_create(float x, float y, float z)
{
    Vec3 newVector = {x, y, z};
    return newVector;
}

/** Adds two vectors, storing the result in vector 'a'.
 *
 * @param a the first vector that will store the result.
 * @param b the second vector to add to 'a'.
 */
static inline void vec3_add(Vec3 *a, const Vec3 *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

/** Subtracts two vectors, storing the result in vector 'a'.
 *
 * @param a the first vector that will store the result.
 * @param b the second vector to subtract from 'a'.
 */
static inline void vec3_subtract(Vec3 *a, const Vec3 *b)
{
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
}

/** Adds two vectors, storing the result as a new vector.
 *
 * @param a the first input vector.
 * @param b the second input vector.
 *
 * @returns A new vector resulting from the addition.
 */
static inline Vec3 vec3_add_copy(Vec3 *a, const Vec3 *b)
{
    return vec3_create(a->x + b->x, a->y + b->y, a->z + b->z);
}

/** Subtracts two vectors, storing the result as a new vector.
 *
 * @param a the first input vector.
 * @param b the second input vector.
 *
 * @returns A new vector resulting from the subtraction.
 */
static inline Vec3 vec3_subtract_copy(Vec3 *a, const Vec3 *b)
{
    return vec3_create(a->x - b->x, a->y - b->y, a->z - b->z);
}
/** Multiplies two vectors, storing the result in vector 'a'.
 *
 * @param a the first vector that will store the result.
 * @param b the second vector to multiply 'a' by.
 */
static inline void vec3_multiply_scalar(Vec3 *a, float scalar)
{
    a->x *= scalar;
    a->y *= scalar;
    a->z *= scalar;
}

/** Multiples two vectors, returning the result as a new vector.
 *
 * @param a the first input vector.
 * @param b the second input vector.
 *
 * @returns A new vector resulting from the multiplication.
 */
static inline Vec3 vec3_multiply_scalar_copy(const Vec3 *a, float scalar)
{
    return vec3_create(a->x * scalar, a->y * scalar, a->z * scalar);
}

/** Takes a step from a coordinate point in a direction by a certain step size. Stores the result in vector 'a'.
 *
 * @param a the initial coordinate point.
 * @param direction a normalized vector representing the direction to step.
 * @param stepSize the distance to travel in the given direction.
 */
static inline void vec3_step(Vec3 *a, const Vec3 *direction, float stepSize)
{
    Vec3 step = vec3_multiply_scalar_copy(direction, stepSize);
    vec3_add(a, &step);
}

// TODO: comment
static inline float vec3_magnitude(Vec3 *a)
{
    float dx = a->x;
    float dy = a->y;
    float dz = a->z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

// TODO: comment
static inline float vec3_distance(Vec3 *a, Vec3 *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}