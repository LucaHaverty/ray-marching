#pragma once

static inline Vec3 spherical_coordinates_to_vector(float theta, float phi, float radius)
{
    Vec3 vector;

    vector.x = radius * sin(phi) * cos(theta);
    vector.y = radius * sin(phi) * sin(theta);
    vector.z = radius * cos(phi);

    return vector;
}

static inline float smoothMin(float d1, float d2, float k)
{
    float h = fmax(k - fabsf(d1 - d2), 0.0) / k;
    return fminf(d1, d2) - h * h * h * k * (1.0 / 6.0);
}
