#pragma once

#include "vec3.hpp"
#include "data.hpp"
#include <vector>


class ray
{
public:
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    point3 origin() { return orig; }
    vec3 direction() { return dir; }

public:
    point3 orig;
    vec3 dir;
};


color TraceRay(const ray& rRay)
{
    std::vector<Sphere> rSceneSpheres;
    for (int i = 0; i < rSceneSpheres.size(); ++i)
    {

    }
}
