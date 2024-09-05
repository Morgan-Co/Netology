#include <iostream>
#include <string>
#include "Shapes.h"

void print_info(Shapes::Figure* figure) {
    figure->print_info();
    std::cout << "\n";
}

int main()
{
    Shapes::Triangle triangle(10, 20, 30, 50, 60, 70);
    Shapes::RightTriangle right_triangle(10, 20, 30, 50, 60);
    Shapes::IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    Shapes::EquilateralTriangle equilateral_triangle(30);

    Shapes::Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Shapes::Rectangle rectangle(10, 20);
    Shapes::Square square(30);
    Shapes::Parallelogram parallelogram(20, 30, 40, 50);
    Shapes::Rhombus rhombus(30, 40, 50);


    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);
}
