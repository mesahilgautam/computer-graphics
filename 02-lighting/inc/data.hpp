#pragma once

#include "vec3.hpp"
#include <limits>
#include <variant>
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

color aBackgroundColor(255, 255, 255);

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
    vSceneSpheres.push_back(Sphere{point3(0, -5001, 0), 5000, color(255, 255, 0)});
    return vSceneSpheres;
}

enum LightType
{
    AMBIENT,
    POINT,
    DIRECTIONAL,
};

struct Light
{
    LightType aType;
    double nIntensity;
    point3 aPosition;
    vec3 aDirection;
};

std::vector<Light> GetSceneLightSources()
{
    std::vector<Light> vLightSources;
    vLightSources.push_back(Light{AMBIENT, 0.2, point3(), vec3()});
    vLightSources.push_back(Light{POINT, 0.5, point3(2, 1, 0), vec3()});
    vLightSources.push_back(Light{DIRECTIONAL, 0.2, point3(), vec3(1, 4, 4)});
    return vLightSources;
}
