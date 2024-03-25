#pragma once

#include "vec3.hpp"
#include <vector>

double nAspectRatio = 1.0;

point3 nCameraPosition(0, 0, 0);
double nFocalLength = 1.0;

double nViewportWidth = 1.0;
double nViewportHeight = nViewportWidth / nAspectRatio;

double nCanvasWidth = 300;
double nCanvasHeight = nCanvasWidth / nAspectRatio;

color aBackgroundColor(255, 255, 255);

point3 CanvasToViewport(const point3& rCanvasPoint)
{
    double nViewportX = rCanvasPoint.x() * (nViewportWidth / nCanvasWidth);
    double nViewportY = rCanvasPoint.y() * (nViewportHeight / nCanvasHeight);
    return point3{nViewportX, nViewportY, nFocalLength};
}

struct Sphere
{
    point3 center;
    double radius;
    color fill;
};

std::vector<Sphere> GetSceneSpheres()
{
    std::vector<Sphere> aSceneSpheres;
    aSceneSpheres.push_back(Sphere{point3{0, -1, 3}, 1, color{255, 0, 0}});
    aSceneSpheres.push_back(Sphere{point3{2, 0, 4}, 1, color{0, 0, 255}});
    aSceneSpheres.push_back(Sphere{point3{-2, 0, 4}, 1, color{0, 255, 0}});
    return aSceneSpheres;
}
