#pragma once

#include "../sphere/sphere.h"
#include "../camera/camera.h"

typedef struct Scene
{
    Camera camera;
    int sphereCount;
    Sphere spheres[];

} Scene;

static inline Scene *scene_create(Camera camera, Sphere spheres[], int sphereCount)
{
    Scene *newScene = (Scene *)malloc(sizeof(Scene) + sizeof(Sphere) * sphereCount);

    newScene->camera = camera;
    newScene->sphereCount = sphereCount;

    // Copy the passed array of spheres into the flexible array member
    for (int i = 0; i < sphereCount; i++)
    {
        newScene->spheres[i] = spheres[i];
    }

    return newScene;
}

void scene_cast_ray(Scene *scene, const Vec3 *origin, const Vec3 *direction);
void scene_render(Scene *scene);