#include <iostream>
#include "Quadrilateral.h"
#include "InvalidFigure.h"

void Quadrilateral::base_check() {
    if (sides_count != 4) throw InvalidFigure("Error creating the shape. Reason: the number of sides is not equal to 4");
    if ((A+B+C+D) !=360 ) throw InvalidFigure("Error creating the shape. Reason: the sum of the angles is not equal to 360");
}

Quadrilateral::Quadrilateral(double sideA, double sideB, double sideC, double sideD,
    double angleA, double angleB, double angleC, double angleD)
    : a(sideA), b(sideB), c(sideC), d(sideD),
    A(angleA), B(angleB), C(angleC), D(angleD) {
    name = "Quadrilateral";
    sides_count = 4;
    base_check();
}

void Quadrilateral::print_info() {
    std::cout << name << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
}