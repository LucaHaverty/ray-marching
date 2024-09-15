#pragma once

typedef struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
} Quaternion;

static inline Quaternion quat_create(float x, float y, float z, float w)
{
    Quaternion newVector = {x, y, z};
    return newVector;
}
