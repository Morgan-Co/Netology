#include <iostream>
#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(double sideA, double sideB, double sideC, double sideD,
    double angleA, double angleB, double angleC, double angleD)
    : a(sideA), b(sideB), c(sideC), d(sideD),
    A(angleA), B(angleB), C(angleC), D(angleD) {
    name = "Quadrilateral";
}

void Quadrilateral::print_info() {
    std::cout << name << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}