#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>


class ini_parser {
private:
	std::ifstream m_file;

	void remove_comments(std::string& line);

	void trim_spaces(std::string& line);

	void get_variable_name(std::string& line);

	std::string generate_line(const std::string& line);

public:
	ini_parser(std::string file_name);

	std::string get_value(std::string input_data);

	void print_file();

	~ini_parser();
};