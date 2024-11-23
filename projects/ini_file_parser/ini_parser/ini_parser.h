#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include <vector>
#include <unordered_map>


class ini_parser {
private:
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m_file;

	void remove_comments(std::string& line);

	void trim_spaces(std::string& line);

	bool is_valid_section(const std::string& line);

	bool is_valid_variable(const std::string& line);

	std::string get_value_template(std::string input_data);

public:
	ini_parser(std::string file_name);

	template <typename T>
	T get_value(std::string input_data);
};