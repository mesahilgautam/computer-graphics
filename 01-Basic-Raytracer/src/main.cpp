#include <iostream>
#include <limits>
#include "../inc/ray.hpp"
#include "../inc/color.hpp"
#include "../inc/vec3.hpp"
#include "../inc/data.hpp"

/*
 * The most important thing while writting anything related to graphics is to
 * be absolutely sure about what coordinate system/orientation o follow, and
 * make it sure that all the entities involved in it like the camera, viewport, 
 * objects etc follow that convention.
 *
 * The easiest way to confirm this is to get a sphere printed in the middle of
 * the image. (or maybe right will be better)
 *
 * Here I am assuming that the +x axis goes towards the right side, the +y axis
 * goes up, and the +z axis goes into the computer screen. So the origin of the 
 * coordinate system lies on the center of the screen.
 */

int main()
{
    std::cout << "P3\n" << nCanvasWidth << ' ' << nCanvasHeight << "\n255\n";

    for (double y = nCanvasHeight / 2; y >= -nCanvasHeight / 2; --y)
    {
        for (double x = -nCanvasWidth / 2; x <= nCanvasWidth / 2; ++x)
        {
            point3 aViewportPoint = CanvasToViewport(point3(x, y, 0));
            ray aRay(nCameraPosition, aViewportPoint - nCameraPosition);
            color aPixelColor = TraceRay(aRay, nFocalLength, std::numeric_limits<double>::max());
            PaintCanvasPixel(aPixelColor);
        }
    }
}
