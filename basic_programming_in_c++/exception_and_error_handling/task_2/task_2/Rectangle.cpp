#include "Rectangle.h"
#include "InvalidFigure.h"

Rectangle::Rectangle(double sideA, double sideB)
    : Quadrilateral(sideA, sideB, sideA, sideB, 90, 90, 90, 90) {
    name = "Rectangle";
    if ((a != c) && (b != d)) throw InvalidFigure("Error creating the shape. Reason: the sides are not equal in pairs");
}