```
#include <iostream>
#include <string>

class bad_length : public std::exception {
public:
    const char* what() const override {
        return "You have entered a word of forbidden length";
    }
};

int str_length(std::string &str, int forbidden_length) {
    if (str.length() == forbidden_length) throw bad_length();
    return str.length();
}

int main()
{
	int forbidden_length;
	std::cout << "Enter the forbidden length: ";
	std::cin >> forbidden_length;
	while (true)
	{
		std::string str;
		std::cout << "Enter a word: ";
		std::cin >> str;
		try
		{
			std::cout << "Length of the word " << '"' << str << '"' << ": " << str_length(str, forbidden_length) << std::endl;
		}
		catch (const bad_length& e)
		{
			std::cout << e.what() << std::endl;
			break;
		}
	}
}
```