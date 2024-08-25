#include <iostream>
#include <string>

#include "InvalidFigure.h"

#include "Figure.h"

#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"

#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

void print_info(Figure* figure) {
    figure->print_info();
    std::cout << "\n";
}


int main()
{
    try
    {
        Triangle triangle(10, 20, 30, 50, 30, 70);
        print_info(&triangle);

    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        RightTriangle right_triangle(10, 20, 30, 30, 60);
        print_info(&right_triangle);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        IsoscelesTriangle isosceles_triangle(10, 20, 55, 70);
        print_info(&isosceles_triangle);

    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        EquilateralTriangle equilateral_triangle(30);
        print_info(&equilateral_triangle);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        Quadrilateral quadrilateral(10, 20, 30, 40, 100, 60, 70, 130);
        print_info(&quadrilateral);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        Rectangle rectangle(10, 20);
        print_info(&rectangle);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        Square square(30);
        print_info(&square);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try
    {
        Parallelogram parallelogram(20, 30, 80, 100);
        print_info(&parallelogram);
    }
    catch (const InvalidFigure& ex)
    {

        std::cout << ex.what() << std::endl;

    }

    try
    {
        Rhombus rhombus(30, 80, 100);
        print_info(&rhombus);
    }
    catch (const InvalidFigure& ex)
    {
        std::cout << ex.what() << std::endl;
    }

}

