#pragma once

typedef struct RayResult
{
    int hitScene;
    int numSteps;
} RayResult;

static inline RayResult ray_result_create(int hitScene, int numSteps)
{
    RayResult result = {hitScene, numSteps};
    return result;
}
