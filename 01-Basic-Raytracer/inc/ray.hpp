#pragma once

#include "vec3.hpp"
#include <iostream>
#include "data.hpp"
#include <cmath>
#include <limits>
#include <vector>


class ray
{
public:
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

public:
    point3 orig;
    vec3 dir;
};


color TraceRay(const ray& rRay, double t1, double t2)
{
    std::vector<Sphere> vSceneSpheres = GetSceneSpheres();
    Sphere* pNearestSphere = nullptr;
    double nNearestPoint = std::numeric_limits<double>::max();

    for (size_t i = 0; i < vSceneSpheres.size(); ++i)
    {
        vec3 CO = nCameraPosition - vSceneSpheres[i].center;
        double a = dot(rRay.direction(), rRay.direction());
        double b = 2 * dot(rRay.direction(), CO);
        double c = dot(CO, CO) - vSceneSpheres[i].radius * vSceneSpheres[i].radius;

        double nDiscriminant = b*b - 4*a*c;
        if (nDiscriminant >= 0)
        {
            double nSolution1 = -b + std::sqrt(nDiscriminant) / (2 * a);
            if (nSolution1 <= nNearestPoint && nSolution1 >= t1 && nSolution1 <= t2)
            {
                nNearestPoint = nSolution1;
                pNearestSphere = &(vSceneSpheres[i]);
            }

            double nSolution2 = -b - std::sqrt(nDiscriminant) / (2 * a);
            if (nSolution2 <= nNearestPoint && nSolution2 >= t1 && nSolution2 <= t2)
            {
                nNearestPoint = nSolution2;
                pNearestSphere = &(vSceneSpheres[i]);
            }
        }
    }

    if (pNearestSphere)
        return pNearestSphere->fill;
    else
        return aBackgroundColor;
}

