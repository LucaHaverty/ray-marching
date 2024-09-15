#pragma once

#include "../vec3/vec3.h"
#include "../utils/utils.h"

typedef struct Sphere
{
    Vec3 position;
    double radius;
} Sphere;

static inline Sphere sphere_create(double radius, double x, double y, double z)
{
    Vec3 vec = {x, y, z};
    Sphere new_sphere = {vec, radius};
    return new_sphere;
}

static inline double distance_to_sphere(const Vec3 *origin, const Sphere *sphere)
{
    double dx = origin->x - sphere->position.x;
    double dy = origin->y - sphere->position.y;
    double dz = origin->z - sphere->position.z;

    return sqrt(dx * dx + dy * dy + dz * dz) - sphere->radius;
}

static inline double distance_to_closest_sphere(const Vec3 *origin, const Sphere spheres[], int numSpheres)
{
    double minDist = INFINITY;

    for (int i = 0; i < numSpheres; i++)
    {
        minDist = fmin(distance_to_sphere(origin, &spheres[i]), minDist);
    }

    return minDist;

    // double dist1 = distance_to_sphere(origin, &spheres[0]);
    // double dist2 = distance_to_sphere(origin, &spheres[1]);
    // return smoothMin(dist1, dist2, 1.5);
}
