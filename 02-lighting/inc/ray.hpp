#pragma once
#include "vec3.hpp"
#include "data.hpp"
#include <cmath>
#include <limits>


/*
 * A RAY is a vector with one end fixed on some place, and other end
 * just having a direction, and can extend to any length :)
 */
class ray
{
public:
    ray(const point3 &rOrigin, const vec3& rDirection )
        :orig(rOrigin), dir(rDirection)
    {}

    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

public:
    point3 orig;
    vec3 dir;
};

color TraceRay(const ray& aRay, double nLeastDistance, double nMostDistnace)
{
    std::vector<Sphere> vSceneSpheres = GetSceneSpheres();
    Sphere* pClosestSphere = nullptr;
    double nClosestIntersectionPoint = std::numeric_limits<double>::max();

    for (size_t i = 0; i < vSceneSpheres.size(); ++i)
    {
        vec3 CO = nCameraPosition - vSceneSpheres[i].aCenter;
        /*
         * It is quite easy to forget which one to subtract from which one.
         * If it's CO then that means from C to O meaning O - C;
         */
        double a = Dot(aRay.direction(), aRay.direction());
        double b = 2 * Dot(CO, aRay.direction());
        double c = Dot(CO, CO) - vSceneSpheres[i].nRadius * vSceneSpheres[i].nRadius;

        double nDiscriminant = b*b - 4*a*c;
        if (nDiscriminant >= 0)
        {
            double nSolution1 = -b + std::sqrt(nDiscriminant) / 2*a;
            if (nSolution1 <= nMostDistnace && nSolution1 >= nLeastDistance && nSolution1 <= nClosestIntersectionPoint)
            {
                pClosestSphere = &(vSceneSpheres[i]);
                nClosestIntersectionPoint = nSolution1;
            }

            double nSolution2 = -b - std::sqrt(nDiscriminant) / 2*a;
            if (nSolution2 <= nMostDistnace && nSolution2 >= nLeastDistance && nSolution2 <= nClosestIntersectionPoint)
            {
                pClosestSphere = &(vSceneSpheres[i]);
                nClosestIntersectionPoint = nSolution2;
            }
        }
    }

    if (pClosestSphere)
        return pClosestSphere->aFill;
    else
        return aBackgroundColor;
}
