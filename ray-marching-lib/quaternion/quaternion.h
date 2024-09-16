#pragma once

#include <math.h>
#include "../vec3/vec3.h"

typedef struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
} Quaternion;

/** Created a new quaternion with the given components. */
static inline Quaternion quat_create(float x, float y, float z, float w)
{
    Quaternion newQuat = {x, y, z, w};
    return newQuat;
}

/** Multiplies a quaternion by a vector, effectively rotating the vector by the angle represented in the quaternion.
 *
 * @param quaternion a quaternion representing an angle.
 * @param vec3 a vector to be rotated by the input quaternion.
 *
 * @returns The resulting vector after the multiplication.
 */
static inline vec3 quat_multiply_vec3(Quaternion quaternion, Vec3 vec3)
{
    // Quaternion components
    float qx = quaternion.x;
    float qy = quaternion.y;
    float qz = quaternion.z;
    float qw = quaternion.w;

    // Vector as quaternion with w = 0
    Quaternion vec_quat = {vec3.x, vec3.y, vec3.z, 0};

    // Quaternion multiplication (q * vec)
    Quaternion res1;
    res1.x = qw * vec_quat.x + qx * vec_quat.w + qy * vec_quat.z - qz * vec_quat.y;
    res1.y = qw * vec_quat.y - qx * vec_quat.z + qy * vec_quat.w + qz * vec_quat.x;
    res1.z = qw * vec_quat.z + qx * vec_quat.y - qy * vec_quat.x + qz * vec_quat.w;
    res1.w = -qx * vec_quat.x - qy * vec_quat.y - qz * vec_quat.z;

    // Inverse quaternion (conjugate since quaternions are normalized)
    Quaternion inv_quat = {-qx, -qy, -qz, qw};

    // Quaternion multiplication (res1 * q^-1)
    Quaternion res2;
    res2.x = res1.w * inv_quat.x + res1.x * inv_quat.w + res1.y * inv_quat.z - res1.z * inv_quat.y;
    res2.y = res1.w * inv_quat.y - res1.x * inv_quat.z + res1.y * inv_quat.w + res1.z * inv_quat.x;
    res2.z = res1.w * inv_quat.z + res1.x * inv_quat.y - res1.y * inv_quat.x + res1.z * inv_quat.w;

    // Return resulting vector
    Vec3 result = {res2.x, res2.y, res2.z};
    return result;
}

/** Converts a euler representation of an angle to a quaternion.
 *
 * @param euler a euler angle in radians.
 *
 * @returns A quaternion equivalent to the euler angle.
 */
static inline Quaternion quat_from_euler(Vec3 euler)
{
    // Compute half-angles
    float cy = cosf(euler.y * 0.5f); // Yaw
    float sy = sinf(euler.y * 0.5f);
    float cp = cosf(euler.x * 0.5f); // Pitch
    float sp = sinf(euler.x * 0.5f);
    float cr = cosf(euler.z * 0.5f); // Roll
    float sr = sinf(euler.z * 0.5f);

    Quaternion q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}
