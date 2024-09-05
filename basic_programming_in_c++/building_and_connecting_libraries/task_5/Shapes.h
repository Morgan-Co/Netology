#pragma once
//#ifdef SHAPES_EXPORTS
//#define SHAPES_API __declspec(dllexport)
//#else
//#define SHAPES_API __declspec(dllimport)
//#endif // SHAPES_EXPORTS

#include <string>

namespace Shapes {
	class Figure {
	protected:
		std::string name;
	public:
		 virtual void print_info() = 0;
		 Figure();
	};

	class Triangle : public Figure {
	protected:
		double a, b, c;
		double A, B, C;
	public:
		 Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC);
		 void print_info() override;
	};

	class RightTriangle : public Triangle {
	public:
		 RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB);
	};

	class IsoscelesTriangle : public Triangle {
	public:
		 IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB);
	};

	class EquilateralTriangle : public Triangle {
	public:
		 EquilateralTriangle(double side);
	};

	class Quadrilateral : public Figure {
	protected:
		double a, b, c, d;
		double A, B, C, D;
	public:
		 Quadrilateral(double sideA, double sideB, double sideC, double sideD,
			double angleA, double angleB, double angleC, double angleD);
		 void print_info() override;
	};

	class Rectangle : public Quadrilateral {
	public:
		 Rectangle(double sideA, double sideB);
	};

	class Square : public Rectangle {
	public:
		 Square(double side);
	};

	class Parallelogram : public Quadrilateral {
	public:
		 Parallelogram(double sideA, double sideB, double angleA, double angleB);
	};

	class Rhombus : public Parallelogram {
	public:
		 Rhombus(double side, double angleA, double angleB);
	};

}
