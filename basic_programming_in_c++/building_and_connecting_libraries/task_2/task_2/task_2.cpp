#include <iostream>
#include <string>
#include "Leaver.h"

int main()
{
    std::string name;
    Leaver::Leaver leaver;

    std::cout << "Enter your name: ";
    std::cin >> name;

    leaver.leave(name);
}

