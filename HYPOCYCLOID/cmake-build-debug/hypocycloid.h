#ifndef TASK1_HYPOCYCLOID_H
#define TASK1_HYPOCYCLOID_H
//#include "gtest\gtest_prod.h"
#include <cmath>

namespace Prog2{
    struct Point{
        double x, y;
    };

    class Hypocycloid{
    private:
        double R, r;
        int flag;        // h -> задание -1 если внутри +1 усли снаружее

    public:
        Hypocycloid(double Rad = 1, double rad = 1, int sign = 1);

        Hypocycloid& setR(double R0);
        Hypocycloid& setr(double r0);
        Hypocycloid& setH(int h0);

        double getR() const{ return R; }
        double getr() const{ return r; }
        double getH() const{ return flag; }

        Point Coordinates(double angle) const;
        double limited_Radius() const{ return R; }
        double curvature_Radius() const{ return R + 2 * r; }
        void check_Type(double d) const;
        double area(double angle) const;
        double full_area() const{return 3.14 * (R - r) * (R - 2*r);}
        double arc_length(double angle) const;
        double full_arc_length() const{return 8 * (R - r); };
    };
}
#endif //TASK1_HYPOCYCLOID_H
