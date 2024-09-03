#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(double side)
    : Triangle(side, side, side, 60, 60, 60) {
    name = "Equilateral Triangle";
};