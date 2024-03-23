#include <iostream>
#include "../inc/ray.hpp"
#include "../inc/color.hpp"
#include "../inc/vec3.hpp"
#include "../inc/data.hpp"


int main()
{
    std::cout << "P3\n" << nCanvasWidth << ' ' << nCanvasHeight << "\n255\n";

    for (double y = nCanvasHeight / 2; y >= -nCanvasHeight / 2; --y)
    {
        for (double x = -nCanvasWidth / 2; x <= nCanvasWidth / 2; ++x)
        {
            point3 aViewportPoint = CanvasToViewport(point3(x, y, 0));
            ray aRay(nCameraPosition, aViewportPoint - nCameraPosition);
            color aPixelColor = TraceRay(aRay);
            PaintCanvasPixel(aPixelColor);

        }
    }
}
