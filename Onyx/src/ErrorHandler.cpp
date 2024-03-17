#include "ErrorHandler.h"

Onyx::ErrorHandler::ErrorHandler()
{
	errors = {};
	logging = false;
	throwing = false;
}

Onyx::ErrorHandler::ErrorHandler(bool logging, bool throwing)
{
	errors = {};
	this->logging = logging;
	this->throwing = throwing;
}

void Onyx::ErrorHandler::err(std::string error)
{
	errors.push_back(error);
	if (logging) std::cout << "Onyx error: " << error << "\n";
	if (throwing) throw std::runtime_error(error);
}

void Onyx::ErrorHandler::setLogging(bool enabled)
{
	logging = enabled;
}

void Onyx::ErrorHandler::setThrowing(bool enabled)
{
	throwing = enabled;
}

std::vector<std::string> Onyx::ErrorHandler::getErrors()
{
	return errors;
}

std::string Onyx::ErrorHandler::getLastError()
{
	return errors[errors.size() - 1];
}

bool Onyx::ErrorHandler::isLogging()
{
	return logging;
}

bool Onyx::ErrorHandler::isThrowing()
{
	return throwing;
}
