#pragma once
#include "Figure.h"

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double sideA, double sideB, double sideC, double sideD,
        double angleA, double angleB, double angleC, double angleD);
    void print_info() override;
};