#pragma once

#include <string>

struct Result
{
	Result();
	Result(std::string test, bool success, std::string message);

	void verify(std::string param, int actual, int expected);
	void verify(std::string param, float actual, float expected);
	void verify(std::string param, std::string actual, std::string expected);
	void verify(std::string param, bool actual, bool expected);

	std::string test;
	bool success;
	std::string message;
};
