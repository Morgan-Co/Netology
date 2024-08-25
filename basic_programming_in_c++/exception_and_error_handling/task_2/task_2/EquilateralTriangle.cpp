#include "EquilateralTriangle.h"
#include "InvalidFigure.h"

EquilateralTriangle::EquilateralTriangle(double side)
    : Triangle(side, side, side, 60, 60, 60) {
    name = "Equilateral Triangle";
    if (a != b || a != c || b != c) throw InvalidFigure("Error creating the shape. Reason: the sides are not equal to each other");
    if (A != 60 && B!= 60 && C != 60) throw InvalidFigure("Error creating the shape. Reason: the angles are not equal to 60");
};