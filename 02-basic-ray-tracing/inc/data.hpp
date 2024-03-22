#pragma once

#include "vec3.hpp"
#include <vector>

double nAspectRatio = 1.0;

double nViewportWidth = 1.0;
double nViewportHeight = nViewportWidth / nAspectRatio;

point3 aCameraPosition{ 0, 0, 0 };
double nFocalLength = 1.0;

color background_color(255, 255, 255);

/*
 * The canvas can be of any size. It doesn't matter until
 * the viewport and the canvas are in the same aspect_ratio
 */

double nCanvasWidth = 300.0;
double nCanvasHeight = nCanvasWidth / nAspectRatio;


point3 CanvasToViewport(const point3& rCanvasPoint)
{
    double x = rCanvasPoint.x() * (nViewportWidth / nCanvasWidth);
    double y = rCanvasPoint.y() * (nViewportWidth / nCanvasWidth); 
    return point3{ x, y, nFocalLength };
}

void PaintCanvasPixel(const color& rPixelColor)
{
    std::cout << rPixelColor.x() << ' ' << rPixelColor.y() << ' ' << rPixelColor.z() << '\n';
}

struct Sphere
{
    double radius;
    point3 center;
    color fill;
};

std::vector<Sphere> GetSpheres()
{
    std::vector<Sphere> vSceneSpheres;

    vSceneSpheres.push_back(Sphere{ 1, point3{ 0, -1, 3 }, color(255, 0, 0) });
    vSceneSpheres.push_back(Sphere{ 1, point3{ 2, 0, 4 }, color(0, 0, 255) });
    vSceneSpheres.push_back(Sphere{ 1, point3{ -2, 0, 4 }, color(0, 255, 0) });

    return vSceneSpheres;
}
