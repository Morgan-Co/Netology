#include "Rectangle.h"

Rectangle::Rectangle(double sideA, double sideB)
    : Quadrilateral(sideA, sideB, sideA, sideB, 90, 90, 90, 90) {
    name = "Rectangle";
}