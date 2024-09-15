#pragma once

typedef struct CameraBounds
{
    int minX;
    int maxX;
    int minY;
    int maxY;
} CameraBounds;

typedef struct Camera
{
    Vec3 origin;
    Vec3 direction; // FIXME: implementation
    CameraBounds bounds;
    double fieldOfView; // FIXME: implementation
    double aspectRatio; // width / height FIXME: implementation
} Camera;

static inline CameraBounds *camera_bounds_create(int minX, int maxX, int minY, int maxY)
{
    CameraBounds *bounds = (CameraBounds *)malloc(sizeof(CameraBounds));
    bounds->minX = minX;
    bounds->maxX = maxX;
    bounds->minY = minY;
    bounds->maxY = maxY;

    return bounds;
}

static inline Camera camera_create(Vec3 origin, Vec3 direction, int resolutionX, int resolutionY)
{
    CameraBounds bounds = {-(int)floor(resolutionX / 2), (int)ceil(resolutionX / 2) - 1,
                           -(int)floor(resolutionY / 2), (int)ceil(resolutionY / 2) - 1};

    Camera camera = {origin, direction, bounds, 75, 1};
    return camera;
}
