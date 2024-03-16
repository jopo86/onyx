#include "Result.h"

Result::Result()
{
	test = "";
	success = false;
	message = "";
}

Result::Result(std::string test, bool success, std::string message)
{
	this->test = test;
	this->success = success;
	this->message = message;
}

void Result::verify(std::string param, int actual, int expected)
{
	if (expected != actual)
	{
		success = false;
		message +=
			param + " - " +
			"expected: " + std::to_string(expected) + ", " +
			"actual: " + std::to_string(actual) +
			"\n";
	}
}

void Result::verify(std::string param, float actual, float expected)
{
	if (expected != actual)
	{
		success = false;
		message +=
			param + " - " +
			"expected: " + std::to_string(expected) + ", " +
			"actual: " + std::to_string(actual) +
			"\n";
	}
}

void Result::verify(std::string param, std::string actual, std::string expected)
{
	if (expected != actual)
	{
		success = false;
		message +=
			param + " - " +
			"expected: \"" + expected + "\", " +
			"actual: \"" + actual + "\"" +
			"\n";
	}
}

void Result::verify(std::string param, bool actual, bool expected)
{
	if (expected != actual)
	{
		success = false;
		message +=
			param + " - " +
			"expected: " + (expected ? "true" : "false") + ", " +
			"actual: " + (actual ? "true" : "false") +
			"\n";
	}
}
