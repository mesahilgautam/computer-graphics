#include "../inc/data.hpp"
#include "../inc/vec3.hpp"
#include "../inc/ray.hpp"
#include <limits>

int main()
{
    std::cout << "P3\n" << nCanvasWidth << ' ' << nCanvasHeight << "\n255\n";

    for (double y = nCanvasHeight / 2; y >= - nCanvasHeight / 2; --y)
    {
        for (double x = - nCanvasWidth / 2; x <= nCanvasWidth / 2; ++x)
        {
            /*
             * We find the point on the viewport, which is equivalent of this
             * point, if the viewport is scaled up/down to the canvas's dimentions
             */

            point3 aViewportPoint = CanvasToViewport(point3{ x, y, 0 });
            ray aTracedRay(aCameraPosition, aViewportPoint - aCameraPosition);
            color aPixelColor = TraceRay(aTracedRay, nFocalLength, std::numeric_limits<double>::max());
            PaintCanvasPixel(aPixelColor);
        }
    }

}
