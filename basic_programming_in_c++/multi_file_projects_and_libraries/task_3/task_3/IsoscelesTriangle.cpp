#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB)
    : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {
    name = "Isosceles Triangle";
};