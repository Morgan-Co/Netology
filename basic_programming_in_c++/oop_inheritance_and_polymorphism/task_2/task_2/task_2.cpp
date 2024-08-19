#include <iostream>

class Figure {
public:
    virtual void print_info() = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC) 
        : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC) {}
    void print_info() override {
        std::cout << "Triangle:\n";
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB) 
        : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {}

    void print_info() override {
        std::cout << "Right Triangle:\n";
        Triangle::print_info();
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB) 
        : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {}

    void print_info() override {
        std::cout << "Isocelse Triangle:\n";
        Triangle::print_info();
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) 
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() override {
        std::cout << "Equilateral Triangle:\n";
        Triangle::print_info();
    }
};

class Quadrilateral: public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double sideA, double sideB, double sideC, double sideD,
                  double angleA, double angleB, double angleC, double angleD) 
        : a(sideA), b(sideB), c(sideC), d(sideD),
          A(angleA), B(angleB), C(angleC), D(angleD) {}

    void print_info() override {
        std::cout << "Quadrilateral:\n";
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << "D=" << D << std::endl;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double sideA, double sideB) 
        : Quadrilateral(sideA, sideB, sideA, sideB, 90, 90, 90, 90) {}

    void print_info() override {
        std::cout << "Rectangle:\n";
        Quadrilateral::print_info();
    }
};

class Square : public Rectangle {
public:
    Square(double side) 
        : Rectangle(side, side) {}

    void print_info() override {
        std::cout << "Square:\n";
        Rectangle::print_info();
    };
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double sideA, double sideB, double angleA, double angleB) 
        : Quadrilateral(sideA, sideB ,sideA, sideB, angleA, angleB, angleA, angleB) {}

    void print_info() override {
        std::cout << "Parallelogram:\n";
        Quadrilateral::print_info();
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double angleA, double angleB) 
        : Parallelogram(side, side, angleA, angleB) {}

    void print_info() override {
        std::cout << "Rhombus:\n";
        Parallelogram::print_info();
    }
};

void print_info(Figure* figure) {
    figure->print_info();
    std::cout << "\n";
}


int main()
{
    Triangle triangle(10, 20, 30, 50, 60 ,70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(30);
    Parallelogram parallelogram(20, 30 ,40 ,50);
    Rhombus rhombus(30, 40, 50);


    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);
}

