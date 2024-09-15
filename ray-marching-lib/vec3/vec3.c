#include "vec3.h"

void vec3_step(Vec3 *a, const Vec3 *direction, float stepSize)
{
    Vec3 step = vec3_multiply_scalar_copy(direction, stepSize);
    vec3_add(a, &step);
}