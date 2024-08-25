#include "Square.h"
#include "InvalidFigure.h"

Square::Square(double side)
    : Rectangle(side, side) {
    name = "Square";
    if (a != b && a != c && a != d && b != c && b != d && d != c) throw InvalidFigure("Error creating the shape. Reason: the sides are not equal to each other");
}