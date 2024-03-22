#pragma once

#include <iostream>
#include <cmath>

class vec3 
{
public:
    vec3()
        :e {0, 0, 0}
    {}

    vec3(double i, double j, double k)
        :e {i, j, k}
    {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    double LengthSquared() 
    { 
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; 
    }

    double Length()
    {
        return std::sqrt(LengthSquared());
    }

public:
    double e[3];
};

inline double dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline std::ostream& operator<<(std::ostream& out, const vec3& point)
{
    return out << point.x() << " " << point.y() << " " << point.z();
}


using color = vec3;
using point3 = vec3;
