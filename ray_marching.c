#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

#include "ray-marching-lib/vec3/vec3.h"
#include "ray-marching-lib/sphere/sphere.h"
#include "ray-marching-lib/camera/camera.h"
#include "ray-marching-lib/ray_result/ray_result.h"
#include "ray-marching-lib/utils/utils.h"
#include "ray-marching-lib/scene/scene.h"

const float MIN_STEP = 0.0001;
const float MAX_STEP = 1000;
const float PI = 3.14159265358979323846; // More precise PI value

RayResult cast_ray(const Scene *scene, const Vec3 *direction)
{
    // numSpheres = sizeof(spheres) / sizeof(spheres[0]);
    Vec3 origin = scene->camera.origin;
    Vec3 currentPos = vec3_create(origin.x, origin.y, origin.z);
    int numSteps = 0;

    while (1)
    {
        float stepSize = distance_to_closest_sphere(&currentPos, scene->spheres, scene->sphereCount);

        if (stepSize < MIN_STEP)
        {
            return ray_result_create(1, numSteps);
        }
        else if (stepSize > MAX_STEP)
        {
            return ray_result_create(0, numSteps);
        }

        vec3_step(&currentPos, direction, stepSize);
        numSteps++;
    }
}

void print_rgb_color(int r, int g, int b, char *buffer, size_t *pos)
{
    *pos += sprintf(buffer + *pos, "\033[38;2;%d;%d;%d;1m\xDB\xDB\033[0m", r, g, b);
}

int main()
{
    Sphere spheres[2];
    spheres[0] = sphere_create(1, 5, -1, 0);
    spheres[1] = sphere_create(1, 5, 1, 0);

    Vec3 origin = vec3_create(0, 0, 0);

    Camera cam = camera_create(origin, vec3_create(1, 0, 0), 50, 50);

    Scene *scene = scene_create(cam, spheres, sizeof(spheres) / sizeof(spheres[0]));

    // TODO: automatically determine buffer size
    char buffer[100000]; // Adjust size as needed
    size_t buffer_size = sizeof(buffer);

    size_t pos = 0;

    memset(buffer, 0, buffer_size);

    float r = (float)rand() / (float)RAND_MAX;
    float g = (float)rand() / (float)RAND_MAX;
    float b = (float)rand() / (float)RAND_MAX;

    for (int y = cam.bounds.minY; y < cam.bounds.maxY; y++)
    {
        float phi = y * (PI / 180.0) + PI / 2;
        for (int x = cam.bounds.minX; x < cam.bounds.maxX; x++)
        {
            float theta = x * (PI / 180.0);

            Vec3 direction = spherical_coordinates_to_vector(theta, phi, 1);

            RayResult result = cast_ray(scene, &direction);
            if (result.hitScene)
            {
                int color = fmax(255 - result.numSteps * 10, 0);
                print_rgb_color((int)(r * color), (int)(g * color), (int)(b * color), buffer, &pos);
            }
            else
            {
                pos += sprintf(buffer + pos, "  ");
            }
        }
        buffer[pos++] = '\n';
    }

    buffer[pos] = '\0'; // Null-terminate the buffer
    system("cls");
    printf("%s", buffer); // Print the entire buffer at once

    // Sleep(50);
    return 0;
}