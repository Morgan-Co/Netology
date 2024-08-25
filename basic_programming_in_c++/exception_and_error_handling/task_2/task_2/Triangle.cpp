#include <iostream>
#include "Triangle.h"
#include "InvalidFigure.h"

void Triangle::base_check() {
    if (sides_count != 3) throw InvalidFigure("Error creating the shape. Reason: the number of sides is not equal to 3");
    if ((A + B + C) != 180) throw InvalidFigure("Error creating the shape. Reason: the sum of the angles is not equal to 180");
};

Triangle::Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
    : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC) {
    name = "Triangle";
    sides_count = 3;
    base_check();
}

void Triangle::print_info() {
    std::cout << name << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
}