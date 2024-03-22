#pragma once
#include "vec3.hpp"
#include "data.hpp"

#include <limits>
#include <cmath>
#include <vector>

class ray
{
public:
    ray(point3 origin, const vec3& direction)
        :orig(origin), dir(direction)
    {}

    vec3 direction() const { return dir; }
    point3 origin() const { return orig; }

public:
    point3 orig;
    vec3 dir;
};

inline vec3 operator-(const point3& pf, const point3& pi)
{
    return vec3(pf.x() - pi.x(), pf.y() - pi.y(), pf.z() - pi.z());
}

color TraceRay(const ray& ray, double t1, double t2)
{
    std::vector<Sphere> vSceneSpheres = GetSpheres();

    Sphere* pClosestIntersectingSphere = nullptr;
    double nNearestSolution = std::numeric_limits<double>::max();

    for (size_t i = 0; i < vSceneSpheres.size(); ++i)
    {
        /*
         * The below code comes from solution of the ray and sphere equations
         * P = O + t(V - O) and dist(P, C) = r
         */
        vec3 CO = aCameraPosition - vSceneSpheres[i].center;

        double a = dot(ray.direction(), ray.direction());
        double b = 2 * dot(ray.direction(), CO);
        double c = dot(CO, CO) - vSceneSpheres[i].radius * vSceneSpheres[i].radius;

        double nDiscriminant = b*b - 4*a*c;
        if (nDiscriminant >= 0)
        {
            double nSolution1 = -b + std::sqrt(nDiscriminant) / (2 * a);
            if (nSolution1 <= nNearestSolution && nSolution1 >= t1 && nSolution1 <= t2)
            {
                pClosestIntersectingSphere = &(vSceneSpheres[i]);
                nNearestSolution = nSolution1;
            }

            double nSolution2 = -b - std::sqrt(nDiscriminant) / 2 * a;
            if (nSolution2 <= nNearestSolution && nSolution1 >= t1 && nSolution1 <= t2)
            {
                pClosestIntersectingSphere = &(vSceneSpheres[i]);
                nNearestSolution = nSolution2;
            }
        }
    }

    if (pClosestIntersectingSphere)
        return pClosestIntersectingSphere->fill;
    else
        return background_color;
}

