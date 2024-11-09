#include <iostream>

template <typename T>
class unique_ptr {
private:
	T* m_ptr;
public:
	explicit unique_ptr(T* ptr = nullptr) : m_ptr(ptr) {}

	unique_ptr(const unique_ptr&) = delete;

	unique_ptr& operator=(const unique_ptr&) = delete;

	unique_ptr(unique_ptr&& other) noexcept : m_ptr(other.m_ptr) {
		other.m_ptr = nullptr;
	}

	unique_ptr& operator=(unique_ptr&& other) noexcept {
		if (this != &other)
		{
			delete m_ptr;
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}

		return *this;
	}

	T& operator*() {
		return *m_ptr;
	}

	T* operator->() {
		return m_ptr;
	}

	T* release() {
		T* temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}

	void reset(T* ptr = nullptr) {
		delete m_ptr;
		m_ptr = ptr;
	}

	~unique_ptr() {
		delete m_ptr;
	}
};

int main() {
	unique_ptr<int> ptr(new int(10));
	std::cout << *ptr << std::endl;

	int* released_ptr = ptr.release();

	std::cout << *released_ptr << std::endl;

	delete released_ptr;

	return 0;
}