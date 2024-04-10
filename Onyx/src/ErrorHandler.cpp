#include "ErrorHandler.h"

Onyx::ErrorHandler::ErrorHandler()
{
	logWarnings = logErrors = throwErrors = false;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors, bool throwErrors)
{
	this->logWarnings = logWarnings;
	this->logErrors = logErrors;
	this->throwErrors = throwErrors;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

void Onyx::ErrorHandler::warn(std::string msg)
{
	if (logWarnings) std::cout << "Onyx Warning: " << msg << "\n";
	warningList.push_back(msg);
	allMessageList.push_back(msg);
	if (warningCallback != nullptr) warningCallback(msg);
}

void Onyx::ErrorHandler::err(std::string msg)
{
	if (logErrors) std::cout << "Onyx Error: " << msg << "\n";
	errorList.push_back(msg);
	allMessageList.push_back(msg);
	if (errorCallback != nullptr) errorCallback(msg);
	if (throwErrors) throw std::runtime_error(msg);

}

bool Onyx::ErrorHandler::logsWarnings() const
{
	return logWarnings;
}

bool Onyx::ErrorHandler::logsErrors() const
{
	return logErrors;
}

bool Onyx::ErrorHandler::throwsErrors() const
{
	return throwErrors;
}

const std::vector<std::string>& Onyx::ErrorHandler::getWarningList() const
{
	return warningList;
}

const std::vector<std::string>& Onyx::ErrorHandler::getErrorList() const
{
	return errorList;
}

const std::vector<std::string>& Onyx::ErrorHandler::getAllMessageList() const
{
	return allMessageList;
}

void Onyx::ErrorHandler::setLogsWarnings(bool logWarnings)
{
	this->logWarnings = logWarnings;
}

void Onyx::ErrorHandler::setLogsErrors(bool logErrors)
{
	this->logErrors = logErrors;
}

void Onyx::ErrorHandler::setThrowsErrors(bool throwErrors)
{
	this->throwErrors = throwErrors;
}

void Onyx::ErrorHandler::setWarningCallback(void (*callback)(std::string))
{
	warningCallback = callback;
}

void Onyx::ErrorHandler::setErrorCallback(void (*callback)(std::string))
{
	errorCallback = callback;
}
