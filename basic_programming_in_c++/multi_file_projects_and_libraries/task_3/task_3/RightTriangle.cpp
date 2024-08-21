#include "RightTriangle.h"

RightTriangle::RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB)
    : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {
    name = "Right Triangle";
};