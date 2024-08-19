```
#include <iostream>
#include <string>

class Figure {
private:
    std::string name;
    int sides_count;

public:

    Figure(std::string name, int sides_count) 
        : name(name), sides_count(sides_count) {}

    int get_sides_count() {
        return this->sides_count;
    }
    std::string get_name() {
        return this->name;
    }
};

class Triangle : public Figure {
public:
    Triangle(std::string name, int sides_count) 
        : Figure(name, sides_count) {}
};

class Quadrangle : public Figure {
public:
    Quadrangle(std::string name, int sides_count)
        : Figure(name, sides_count) {}
};

int main()
{
    Figure figure("Figure", 0);
    Triangle triangle("Triangle", 3);
    Quadrangle quadrangle("Quadrangle", 4);

    std::cout << "Sides count: " << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;
}
```