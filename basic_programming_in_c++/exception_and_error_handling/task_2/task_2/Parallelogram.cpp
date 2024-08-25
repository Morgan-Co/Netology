#include "Parallelogram.h"
#include "InvalidFigure.h"

Parallelogram::Parallelogram(double sideA, double sideB, double angleA, double angleB)
    : Quadrilateral(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) {
    name = "Parallelogram";

    if (a != c && b != d) throw InvalidFigure("Error creating the shape. Reason: the sides are not equal in pairs");
    if (A != C && B != D) throw InvalidFigure("Error creating the shape. Reason: the angles are not equal in pairs");
};