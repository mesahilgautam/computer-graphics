#pragma once

#include "vec3.hpp"
#include <iostream>


void PaintCanvasPixel(const color & rColor)
{
    std::cout << rColor.x() << ' '
        << rColor.y() << ' '
        << rColor.z() << '\n';
}
