#include <iostream>
#include <cmath>

#include "hypocycloid.h"

using namespace Prog2;

Hypocycloid::Hypocycloid(double Rad, double rad, int sign)
{
    if (Rad < 0 || rad < 0)
        throw std::runtime_error("invalid parameters");
    R = Rad; r = rad;
}

Hypocycloid& Hypocycloid::setR(double R0)
{
    if (R0 < 0)
        throw std::runtime_error("invalid radius");
    R = R0;
    return *this;
}

Hypocycloid& Hypocycloid::setr(double r0)
{
    if (r0 < 0)
        throw std::runtime_error("invalid radius");
    r = r0;
    return *this;
}

Hypocycloid& Hypocycloid::setH(int h0)
{
    if (h0 != 1 && h0 != -1)
        throw std::runtime_error("invalid value");
    flag = h0;
    return *this;
}

Point Hypocycloid::Coordinates(double angle) const
{
    if(R < 0 || r < 0 || angle < 0)
        throw std::runtime_error("invalid radius or degree");
    double k = R / r;
    double coord_X = r * ( k - 1 ) * cos( angle ) + r * cos( ( k - 1 ) * angle );
    double coord_Y = r * ( k - 1 ) * sin( angle ) - r * sin( ( k - 1 ) * angle );
    Point res;
    res.x = coord_X;
    res.y = coord_Y;
    return res;
}

void Hypocycloid::check_Type(double d) const
{
    if(d < 0)
        throw std::runtime_error("illegal argument");

    if(d == r) std::cout << "Common Hypocycloid" << std::endl;
    else if(d > r) std::cout << "Elongated Hypocycloid" << std::endl;
    else std::cout << "Shortened Hypocycloid" << std::endl;
}

double Hypocycloid::area(double angle) const
{
    if(R < 0 || r < 0 || angle < 0)
        throw std::runtime_error("invalid radius or degree");

    double k = R / r;
    double s;
    s = fabs(k - 1) * fabs(k - 2) * angle * r * r;

    return s;
}

double Hypocycloid::arc_length(double angle) const
{
    if(R < 0 || r < 0 || angle < 0)
        throw std::runtime_error("invalid radius or degree");

    double k = R / r;
    double l;
    l = 8 * fabs(k - 1) * r;

    return l;
}