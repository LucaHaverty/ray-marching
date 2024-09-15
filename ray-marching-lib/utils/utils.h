#pragma once

static inline Vec3 spherical_coordinates_to_vector(double theta, double phi, double radius)
{
    Vec3 vector;

    vector.x = radius * sin(phi) * cos(theta);
    vector.y = radius * sin(phi) * sin(theta);
    vector.z = radius * cos(phi);

    return vector;
}

static inline double smoothMin(double d1, double d2, double k)
{
    double h = fmax(k - fabs(d1 - d2), 0.0) / k;
    return fmin(d1, d2) - h * h * h * k * (1.0 / 6.0);
}
