#pragma once
class Counter {
private:
	int value = 1;
public:
	void set_initial_value(int initial_value);
	void increase_value();
	void decrease_value();
	void show_value();
};