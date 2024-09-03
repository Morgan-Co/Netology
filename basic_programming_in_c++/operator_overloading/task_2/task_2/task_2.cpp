#include <iostream>
#include <numeric>

class Fraction {
	int numerator_;
	int denominator_;

	void reduce() {
		int gcd = std::gcd(numerator_, denominator_);
		numerator_ /= gcd;
		denominator_ /= gcd;
	}

public:
	Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
		if (denominator_ == 0) {
			throw std::invalid_argument("Denominator cannot be zero.");
		}
		reduce();
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
		os << fraction.numerator_ << '/' << fraction.denominator_;
		return os;
	}

	Fraction operator+(const Fraction& other) const {
		int num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
		int den = denominator_ * other.denominator_;
		return Fraction(num, den);
	}

	Fraction operator-(const Fraction& other) const {
		int num = numerator_ * other.denominator_ - other.numerator_ * denominator_;
		int den = denominator_ * other.denominator_;
		return Fraction(num, den);
	}
	Fraction operator*(const Fraction& other) const {
		int num = numerator_ * other.numerator_;
		int den = denominator_ * other.denominator_;
		return Fraction(num, den);
	}
	Fraction operator/(const Fraction& other) const {
		int num = numerator_ * other.denominator_;
		int den = denominator_ * other.numerator_;
		return Fraction(num, den);
	}
	Fraction operator-() const {
		return Fraction(-numerator_, denominator_);
	}
	Fraction& operator++() {
		numerator_ += denominator_;
		return *this;
	}

	Fraction operator++(int) {
		Fraction temp = *this;
		numerator_ += denominator_;
		return temp;
	}
	Fraction& operator--() {
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator--(int) {
		Fraction temp = *this;
		numerator_ -= denominator_;
		return temp;
	}
};

int main() {
	int fraction_1[2];
	int fraction_2[2];

	std::cout << "Enter the numenator of the fraction 1: ";
	std::cin >> fraction_1[0];
	std::cout << "Enter the denominator of the fraction 1: ";
	std::cin >> fraction_1[1];
	Fraction fraction1(fraction_1[0], fraction_1[1]);

	std::cout << "Enter the numenator of the fraction 2: ";
	std::cin >> fraction_2[0];
	std::cout << "Enter the denominator of the fraction 2: ";
	std::cin >> fraction_2[1];
	Fraction fraction2(fraction_2[0], fraction_2[1]);


	std::cout << fraction1 << " + " << fraction2 << " = " << fraction1 + fraction2 << std::endl;
	std::cout << fraction1 << " - " << fraction2 << " = " << fraction1 - fraction2 << std::endl;
	std::cout << fraction1 << " * " << fraction2 << " = " << fraction1 * fraction2 << std::endl;
	std::cout << fraction1 << " / " << fraction2 << " = " << fraction1 / fraction2 << std::endl;

	std::cout << "++" << fraction1 << " * " << fraction2 << " = " << ++fraction1 * fraction2 << std::endl;
	std::cout << "The value of the fraction 1 = " << fraction1 << std::endl;

	std::cout << fraction1 << "--" << " * " << fraction2 << " = " << fraction1-- * fraction2 << std::endl;
	std::cout << "The value of the fraction 1 = " << fraction1 << std::endl;

}