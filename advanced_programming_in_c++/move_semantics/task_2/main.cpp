#include <iostream>
#include <string>


class big_integer {
private:
	std::string m_num;
public:
	big_integer(const std::string& num) : m_num(num) {
		while (m_num.size() > 1 && m_num[0] == '0') {
			m_num.erase(0, 1);
		}
	}

	big_integer(big_integer&& other) noexcept : m_num(std::move(other.m_num)) {}

	big_integer& operator=(big_integer&& other) noexcept {
		if (this != &other) {
			m_num = std::move(other.m_num);
		}
		return *this;
	}

	big_integer operator+(const big_integer& other) const {
		std::string result = "";
		int carry = 0;
		int i = m_num.size() - 1, j = other.m_num.size() - 1;
		while (i >= 0 || j >=0 || carry) {
			int digit1 = i >= 0 ? m_num[i--] - '0' : 0;
			int	digit2 = j >= 0 ? other.m_num[j--] - '0' : 0;
			int sum = digit1 + digit2 + carry;
			result.push_back((sum % 10) + '0');
			carry = sum / 10;
		}
		std::reverse(result.begin(), result.end());
		return big_integer(result);
	}

	big_integer operator*(int multiplier) const {
		std::string result;
		int carry = 0;

		for (int i = m_num.size() - 1; i >= 0; i--) {
			int digit = m_num[i--] - '0';
			int product = digit * multiplier + carry;
			result.push_back((product % 10) + '0');
			carry = product / 10;
		}
		if (carry) {
			result.push_back(carry + '0');
		}
		std::reverse(result.begin(), result.end());
		return big_integer(result);
	}

	friend std::ostream& operator<<(std::ostream& os, const big_integer& obj) {
		os << obj.m_num;
		return os;
	}
};

int main() {
	auto number1 = big_integer("1244234");
	auto number2 = big_integer("324234");

	auto result = number1 + number2;

	std::cout<< result << std::endl;
}