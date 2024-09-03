#include "Rhombus.h"

Rhombus::Rhombus(double side, double angleA, double angleB)
    : Parallelogram(side, side, angleA, angleB) {
    name = "Rhombus";
};