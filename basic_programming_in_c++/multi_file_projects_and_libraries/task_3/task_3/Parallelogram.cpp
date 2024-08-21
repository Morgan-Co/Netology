#include "Parallelogram.h"

Parallelogram::Parallelogram(double sideA, double sideB, double angleA, double angleB)
    : Quadrilateral(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) {
    name = "Parallelogram";
};