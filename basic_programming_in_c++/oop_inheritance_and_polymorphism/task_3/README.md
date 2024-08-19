```
#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count = 0;
    std::string name = "Figure";
public:
    Figure(std::string name) : name(name) {}
    virtual void print_info() {
        std::cout << "Figure:\n";
        if (check()) {
            std::cout << "Right\n";
        }
        else {
            std::cout << "Wrong\n";
        }
        std::cout << "Sides Count: " << sides_count << std::endl;
    };
    virtual bool check() {
        if (sides_count == 0) return true;
        return false;
    };
};

class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
        : a(sideA), b(sideB), c(sideC), A(angleA), B(angleB), C(angleC), Figure("Triangle") {
        this->sides_count = 3;
    }
    bool check() override {
        if (sides_count == 3 && (A + B + C) == 180) return true;
        return false;
    }
    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Right" : "Wrong") << std::endl;
        std::cout << "Sides Count: " << sides_count << std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB)
        : Triangle(sideA, sideB, sideC, angleA, angleB, 90) {
        name = "Right Triangle";
    }

    bool check() override {
        if (Triangle::check() && C == 90) return true;
        return false;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB)
        : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) {
        name = "Isosceles Triangle";
    }

    bool check() override {
        if (Triangle::check() && (a == c || a == b || b == c) && (A == B || A == C || C == B)) return true;
        return false;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Equilateral Triangle";
    }

    bool check() override {
        if (Triangle::check() && (a == b && a == c && b ==c) && (A == 60 && B == 60 && C == 60)) return true;
        return false;
    }
};

class Quadrilateral : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double sideA, double sideB, double sideC, double sideD,
        double angleA, double angleB, double angleC, double angleD)
        : a(sideA), b(sideB), c(sideC), d(sideD),
        A(angleA), B(angleB), C(angleC), D(angleD), Figure("Quadrilateral") {
        sides_count = 4;
    }

    bool check() override {
        if (sides_count == 4 && (A + B + C + D) == 360) return true;
        return false;
    }

    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Right" : "Wrong") << std::endl;
        std::cout << "Sides Count: " << sides_count << std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double sideA, double sideB)
        : Quadrilateral(sideA, sideB, sideA, sideB, 90, 90, 90, 90) {
        name = "Rectangle";
    }

    bool check() override {
        if (Quadrilateral::check() 
            && (a == c && b == d)
            && (A == 90 && B == 90 && C == 90 && D == 90)) return true;
        return false;
    }
};

class Square : public Rectangle {
public:
    Square(double side)
        : Rectangle(side, side) {
        name = "Square";
    }

    bool check() override {
        if (Rectangle::check() 
            && (a==b && a==c && a==d && b==c && b==d && d==c)) return true;
        return false;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double sideA, double sideB, double angleA, double angleB)
        : Quadrilateral(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) {
        name = "Parallelogram";
    }
    

    bool check() override {
        if (Quadrilateral::check()
            && (a == c && b == d) && (A == C && B == D)) return true;
        return false;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double angleA, double angleB)
        : Parallelogram(side, side, angleA, angleB) {
        name = "Rhombus";
    }

    bool check() override {
        if (Parallelogram::check() && (a == b && a == c && a == d && b == c && b == d && d == c)) return true;
        return false;
    }
};

void print_info(Figure* figure) {
    figure->print_info();
    std::cout << "\n";
}


int main()
{
    Figure figure("Figure");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 30, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 40, 100);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(30);
    Parallelogram parallelogram(20, 30, 80, 100);
    Rhombus rhombus(30, 80, 100);

    print_info(&figure);
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
```