#include <iostream>
#include "Triangle.h"

Triangle::Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
    : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC) {
    name = "Triangle";
}

void Triangle::print_info() {
    std::cout << name << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
}