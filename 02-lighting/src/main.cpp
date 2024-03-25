#include <iostream>
#include "../inc/data.hpp"
#include "../inc/color.hpp"
#include "../inc/vec3.hpp"
#include "../inc/ray.hpp"


int main()
{
    std::cout << "P3\n" << nCanvasWidth << ' ' << nCanvasHeight << "\n255\n";

    /*
     * Note that when using coordinate systems like this one, it's easy to not know
     * that putting an equality here in < or > can lead to skewed image
     */

    for (double y = nCanvasHeight / 2; y > -nCanvasHeight / 2; --y)
    {
        for (double x = -nCanvasWidth / 2; x < nCanvasWidth / 2; ++x)
        {
            /*
             * Here I will convert this point from the canvas to the equivalent
             * point on the viewport.
             */
            point3 aViewportPoint = CanvasToViewport(point3(x, y, 0));

            /*
             * Once I found that viewport point, then I would create a ray from
             * the nCameraPosition to that point 
             */
            ray aRay(nCameraPosition, aViewportPoint - nCameraPosition);

            /*
             * And then I will extend that ray from the nCameraPosition through the viewport point
             * towards the scene, and find the first object that intersects with that ray.
             * That point on the viewport will have the object's color.
             */
            color aPixelColor = TraceRay(aRay, nNearestPoint, nFurthestPoint);
            PaintCanvasPixel(aPixelColor);
        }
    }
}
