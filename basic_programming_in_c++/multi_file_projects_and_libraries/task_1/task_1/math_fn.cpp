#include "math.h"

int Addition(int num_1, int num_2) {
	return num_1 + num_2;
};

int Substraction(int num_1, int num_2) {
	return num_1 - num_2;
};

int Multiplication(int num_1, int num_2) {
	return num_1 * num_2;
};

int Division(int num_1, int num_2) {
	return num_1 / num_2;
};

int Power(int num_1, int num_2) {
	for (int i = 0; i < num_2 - 1; i++)
	{
		num_1 *= num_1;
	}
	return num_1;
};