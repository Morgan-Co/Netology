```
#include <iostream>
#include "math_fn.h"


int main()
{
	int num_1, num_2;
	int operation;
	std::cout << "Enter the first num: ";
	std::cin >> num_1;
	std::cout << "Enter the second num: ";
	std::cin >> num_2;
	std::cout << "Select an operation (1 - addition, 2 - substraction, 3 - multiplication, 4 - division, 5 - power): ";
	std::cin >> operation;

	switch (operation)
	{
	case 1: {
		std::cout << num_1 << " + " << num_2 << " = " << Addition(num_1, num_2);
		break;
	}
	case 2: {
		std::cout << num_1 << " - " << num_2 << " = " << Substraction(num_1, num_2);
		break;
	}
	case 3: {
		std::cout << num_1 << " * " << num_2 << " = " << Multiplication(num_1, num_2);
		break;
	}
	case 4: {
		std::cout << num_1 << " / " << num_2 << " = " << Division(num_1, num_2);
		break;
	}
	case 5: {
		std::cout << num_1 << " ^ " << num_2 << " = " << Power(num_1, num_2);
		break;
	}
	default:
		break;
	}
}
```