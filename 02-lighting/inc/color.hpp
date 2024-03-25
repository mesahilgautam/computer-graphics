#pragma once

#include "vec3.hpp"
#include <iostream>

void PaintCanvasPixel(const color& rPixelColor)
{
    std::cout << 
        static_cast<int>(rPixelColor.x()) << ' ' << 
        static_cast<int>(rPixelColor.y()) << ' ' << 
        static_cast<int>(rPixelColor.z()) << '\n';
}
