#include "Shapes.h"
#include <iostream>

namespace Shapes {
	Figure::Figure() {
		name = "Figure";
	}

    Triangle::Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
        : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC) {
        name = "Triangle";
    }

    void Triangle::print_info() {
        std::cout << name << ":\n";
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    RightTriangle::RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB)
        : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {
        name = "Right Triangle";
    };

    IsoscelesTriangle::IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB)
        : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {
        name = "Isosceles Triangle";
    };

    EquilateralTriangle::EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Equilateral Triangle";
    };

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

    Rectangle::Rectangle(double sideA, double sideB)
        : Quadrilateral(sideA, sideB, sideA, sideB, 90, 90, 90, 90) {
        name = "Rectangle";
    }

    Square::Square(double side)
        : Rectangle(side, side) {
        name = "Square";
    }

    Parallelogram::Parallelogram(double sideA, double sideB, double angleA, double angleB)
        : Quadrilateral(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) {
        name = "Parallelogram";
    };

    Rhombus::Rhombus(double side, double angleA, double angleB)
        : Parallelogram(side, side, angleA, angleB) {
        name = "Rhombus";
    };
}