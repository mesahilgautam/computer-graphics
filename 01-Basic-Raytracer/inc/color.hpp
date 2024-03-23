#pragma once

#include "vec3.hpp"
#include <iostream>

void PaintCanvasPixel(const color &rPixelColor) 
{
    std::cout << rPixelColor.x() << ' ' << rPixelColor.y() << ' ' << rPixelColor.z() << '\n';
}
