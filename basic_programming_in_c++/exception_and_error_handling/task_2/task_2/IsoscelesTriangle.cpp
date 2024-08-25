#include "IsoscelesTriangle.h"
#include "InvalidFigure.h"

IsoscelesTriangle::IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB)
    : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {
    name = "Isosceles Triangle";
    if (a != c) throw InvalidFigure("Error creating the shape. Reason: side 'a' is not equal to side 'c'");
    if (A != C) throw InvalidFigure("Error creating the shape. Reason: Angle A is not equal to angle C");
};