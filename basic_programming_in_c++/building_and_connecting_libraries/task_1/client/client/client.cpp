#include <iostream>
#include <string>
#include "Greeter.h"


int main()
{
    Greeter::Greeter greeter;
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    greeter.greet(name);
}