#include <iostream>

#define MODE 5
#ifndef MODE
    #error "It is necessary to define the MODE"
#endif

#if MODE == 1
int add(int a, int b) {
    return a + b;
}
#endif


int main()
{
#if MODE == 0
    std::cout << "I work in training mode" << std::endl;
#elif MODE == 1
    std::cout << "I'm working in combat mode\n";
    int a, b;
    std::cout << "Enter the first num: ";
    std::cin >> a;
    std::cout << "Enter the second num: ";
    std::cin >> b;
    std::cout << "The result of add: " << add(a, b) << std::endl;
#else
    std::cout << "Unknown mode\n";
#endif
}