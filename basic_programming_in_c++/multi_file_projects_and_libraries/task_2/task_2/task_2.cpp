#include <iostream>
#include "counter.h"

int main()
{
    Counter counter;
    for (int i = 0; i < 4; i++)
    {
        char is_initial_value = ' ';
        std::cout << "Do you want to set the initial value? (yes - y | no - n): ";
        std::cin >> is_initial_value;
        if (is_initial_value == 'y') {
            int initial_value;
            std::cout << "Enter the initial value: ";
            std::cin >> initial_value;
            counter.set_initial_value(initial_value);
            break;
        }
        else {
            std::cout << "Incorrect Input!" << std::endl;
        }
    }


    char command;
    do
    {
        std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
        std::cin >> command;
        if (command == '+')
        {
            counter.increase_value();
        }
        else if (command == '-') {
            counter.decrease_value();
        }
        else if (command == '=') {
            counter.show_value();
        }
    } while (command != 'x');
    std::cout << "Goodbye!" << std::endl;
}