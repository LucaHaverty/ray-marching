#pragma once

#include "../vec3/vec3.h"
#include "../utils/utils.h"

typedef struct Sphere
{
    Vec3 position;
    float radius;
} Sphere;

static inline Sphere sphere_create(float radius, float x, float y, float z)
{
    Vec3 vec = {x, y, z};
    Sphere new_sphere = {vec, radius};
    return new_sphere;
}

static inline float distance_to_sphere(const Vec3 *origin, const Sphere *sphere)
{
    float dx = origin->x - sphere->position.x;
    float dy = origin->y - sphere->position.y;
    float dz = origin->z - sphere->position.z;

    return sqrt(dx * dx + dy * dy + dz * dz) - sphere->radius;
}

static inline float distance_to_closest_sphere(const Vec3 *origin, const Sphere spheres[], int numSpheres)
{
    float minDist = INFINITY;

    for (int i = 0; i < numSpheres; i++)
    {
        minDist = fminf(distance_to_sphere(origin, &spheres[i]), minDist);
    }

    return minDist;

    // float dist1 = distance_to_sphere(origin, &spheres[0]);
    // float dist2 = distance_to_sphere(origin, &spheres[1]);
    // return smoothMin(dist1, dist2, 1.5);
}
