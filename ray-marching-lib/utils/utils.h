#pragma once

static inline Vec3 spherical_coordinates_to_vector(float theta, float phi, float radius)
{
    Vec3 vector;

    vector.x = radius * sin(phi) * cos(theta);
    vector.y = radius * sin(phi) * sin(theta);
    vector.z = radius * cos(phi);

    return vector;
}
