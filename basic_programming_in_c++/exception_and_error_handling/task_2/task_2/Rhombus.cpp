#include "Rhombus.h"
#include "InvalidFigure.h"

Rhombus::Rhombus(double side, double angleA, double angleB)
    : Parallelogram(side, side, angleA, angleB) {
    name = "Rhombus";
    if (a != b && a != c && a != d && b != c && b != d && d != c) throw InvalidFigure("Error creating the shape. Reason: the sides are not equal to each other");
};