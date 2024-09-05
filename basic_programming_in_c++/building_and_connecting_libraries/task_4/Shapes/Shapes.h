#pragma once
#ifdef SHAPES_EXPORTS
#define SHAPES_API __declspec(dllexport)
#else
#define SHAPES_API __declspec(dllimport)
#endif // SHAPES_EXPORTS

#include <string>

namespace Shapes {
	class Figure {
	protected:
		std::string name;
	public:
		SHAPES_API virtual void print_info() = 0;
		SHAPES_API Figure();
	};

	class Triangle : public Figure {
	protected:
		double a, b, c;
		double A, B, C;
	public:
		SHAPES_API Triangle(double sideA, double sideB, double sideC, double angleA, double angleB, double angleC);
		SHAPES_API void print_info() override;
	};

	class RightTriangle : public Triangle {
	public:
		SHAPES_API RightTriangle(double sideA, double sideB, double sideC, double angleA, double angleB);
	};

	class IsoscelesTriangle : public Triangle {
	public:
		SHAPES_API IsoscelesTriangle(double sideA, double sideB, double angleA, double angleB);
	};

	class EquilateralTriangle : public Triangle {
	public:
		SHAPES_API EquilateralTriangle(double side);
	};

	class Quadrilateral : public Figure {
	protected:
		double a, b, c, d;
		double A, B, C, D;
	public:
		SHAPES_API Quadrilateral(double sideA, double sideB, double sideC, double sideD,
			double angleA, double angleB, double angleC, double angleD);
		SHAPES_API void print_info() override;
	};

	class Rectangle : public Quadrilateral {
	public:
		SHAPES_API Rectangle(double sideA, double sideB);
	};

	class Square : public Rectangle {
	public:
		SHAPES_API Square(double side);
	};

	class Parallelogram : public Quadrilateral {
	public:
		SHAPES_API Parallelogram(double sideA, double sideB, double angleA, double angleB);
	};

	class Rhombus : public Parallelogram {
	public:
		SHAPES_API Rhombus(double side, double angleA, double angleB);
	};

}
