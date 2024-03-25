#pragma once

#include "vec3.hpp"
#include <limits>
#include <vector>

double nAspectRatio = 1.0;

double nCanvasWidth = 300;
double nCanvasHeight = nCanvasWidth / nAspectRatio;

double nViewportWidth = 1.0;
double nViewportHeight = nViewportWidth / nAspectRatio;

point3 nCameraPosition = point3(0, 0, 0);
double nFocalLength = 1.0;

double nNearestPoint = nFocalLength;
double nFurthestPoint = std::numeric_limits<double>::max();

color aBackgroundColor(0, 0, 0);

point3 CanvasToViewport(const point3& rCanvasPoint)
{
    double x = rCanvasPoint.x() * (nViewportWidth / nCanvasWidth);
    double y = rCanvasPoint.y() * (nViewportHeight / nCanvasHeight);
    double z = nFocalLength;
    return point3(x, y, z);
}

struct Sphere
{
    point3 aCenter;
    double nRadius;
    color aFill;
};

std::vector<Sphere> GetSceneSpheres()
{
    std::vector<Sphere> vSceneSpheres;
    vSceneSpheres.push_back(Sphere{point3(0, -1, 3), 1, color(255, 0, 0)});
    vSceneSpheres.push_back(Sphere{point3(2, 0, 4), 1, color(0, 0, 255)});
    vSceneSpheres.push_back(Sphere{point3(-2, 0, 4), 1, color(0, 255, 0)});
    return vSceneSpheres;
}
