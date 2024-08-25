#include "RightTriangle.h"
#include "InvalidFigure.h"

RightTriangle::RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB)
    : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {
    name = "Right Triangle";
    if (C != 90) throw InvalidFigure("Error creating the shape. Reason: angle C is not equal to 90");
};