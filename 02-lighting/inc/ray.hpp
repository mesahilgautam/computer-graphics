#pragma once

#include <iostream>
#include "vec3.hpp"
#include "data.hpp"
#include <cmath>
#include <limits>
#include <vector>


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

double ComputeLighting(const point3& rScenePoint, const vec3& rNormalAtScenePoint)
{
    double nIntensity = 0.0;
    std::vector<Light> vSceneLightSources = GetSceneLightSources();
    for (size_t i = 0; i < vSceneLightSources.size(); ++i)
    {
        /*
         * I have a feeling that a switch case here would do more justice,
         * but considering the situation, this thing works.
         */
        if (vSceneLightSources[i].aType == AMBIENT)
        {
            nIntensity += vSceneLightSources[i].nIntensity;
        }
        else
        {
            vec3 aLightVec;
            if (vSceneLightSources[i].aType == POINT)
            {
                aLightVec = vSceneLightSources[i].aPosition - rScenePoint;
            }
            else
            {
                // DIRECTIONAL
                aLightVec = vSceneLightSources[i].aDirection;
            }
            double NDotL = Dot(rNormalAtScenePoint, aLightVec);
            if (NDotL > 0)
                nIntensity += vSceneLightSources[i].nIntensity * NDotL /
                    (rNormalAtScenePoint.length() * aLightVec.length());
        }
    }
    return nIntensity;
}

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
    {
        point3 aIntersectionPoint = nCameraPosition + nClosestIntersectionPoint * (aRay.direction() / aRay.direction().length()) ;
        vec3 aSurfaceNormalDirection = aIntersectionPoint - pClosestSphere->aCenter;
        vec3 aSurfaceNormal = aSurfaceNormalDirection / aSurfaceNormalDirection.length();
        return pClosestSphere->aFill * ComputeLighting(aIntersectionPoint, aSurfaceNormal);
    }
    else
    {
        return aBackgroundColor;
    }
}

