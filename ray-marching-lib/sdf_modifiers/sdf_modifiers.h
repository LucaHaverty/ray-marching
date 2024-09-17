#pragma once

#include "../vec3/vec3.h"
#include "../quaternion/quaternion.h"

static inline Vec3 sdf_mod_translate(Vec3 *point, Vec3 *translation)
{
    return vec3_add_copy(point, translation);
}

// TODO: rotate