#pragma once
#include <cmath>
#include <stdexcept>

class vec3 
{
public:
    vec3()
        :e { 0, 0, 0 }
    {}

    vec3(double i, double j, double k)
        : e { i, j, k }
    {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    double LengthSquared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    double Length() const
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

using point3 = vec3;
using color = vec3;

inline vec3 operator-(const point3 &p1, const point3 &p2)
{
    return vec3(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
}
