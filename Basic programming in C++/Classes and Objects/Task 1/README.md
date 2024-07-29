## Code

```
#include <iostream>

class Calculator {
private:
    double num_1, num_2;
public:
    double add() {
        return num_1 + num_2;
    }
    double multiply() {
        return num_1 * num_2;
    }
    double substract_1_2() {
        return num_2 - num_1;
    }
    double substract_2_1() {
        return num_1 - num_2;
    }
    double divide_1_2() {
        return num_2 / num_1;
    }
    double divide_2_1() {
        return num_1 / num_2;
    }
    bool set_num_1(double num_1) {
        if (!num_1) return false;
        this->num_1 = num_1;
        return true;
    }
    bool set_num_2(double num_2) {
        if (!num_2) {
            std::cout << "Incorrect input!" << std::endl;
            return false;
        };
        this->num_2 = num_2;
        return true;
    }
};

int main()
{
    Calculator calculator;
    double num_1, num_2;
    while (true) {
        while (true)
        {
            std::cout << "Enter num1: ";
            std::cin >> num_1;
            if (num_1) {
                calculator.set_num_1(num_1);
                break;
            }
            std::cout << "Incorrect Input!" << std::endl;
        }

        while (true)
        {
            std::cout << "Enter num2: ";
            std::cin >> num_2;
            if (num_2) {
                calculator.set_num_2(num_2);
                break;
            }
            std::cout << "Incorrect Input!" << std::endl;
        }

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.substract_2_1() << std::endl;
        std::cout << "num2 - num1 = " << calculator.substract_1_2() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_2_1() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_1_2() << std::endl;
    }
};
   

```