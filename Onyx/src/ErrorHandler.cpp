#include "ErrorHandler.h"

#include "Core.h"

Onyx::ErrorHandler::ErrorHandler()
{
	logWarnings = logErrors = crashOnError = false;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors, bool crashOnError)
{
	this->logWarnings = logWarnings;
	this->logErrors = logErrors;
	this->crashOnError = crashOnError;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

void Onyx::ErrorHandler::warn(const std::string& msg)
{
	if (logWarnings) std::cout << "Onyx Warning: " << msg << "\n";
	warningList.push_back(msg);
	allMessageList.push_back(msg);
	if (warningCallback != nullptr) warningCallback(msg);
}

void Onyx::ErrorHandler::err(const std::string& msg)
{
	if (logErrors) std::cout << "Onyx Error: " << msg << "\n";
	errorList.push_back(msg);
	allMessageList.push_back(msg);
	if (errorCallback != nullptr) errorCallback(msg);
	if (crashOnError) {
		Terminate();
		exit(1);
	}
}

bool Onyx::ErrorHandler::logsWarnings() const
{
	return logWarnings;
}

bool Onyx::ErrorHandler::logsErrors() const
{
	return logErrors;
}

bool Onyx::ErrorHandler::crashesOnError() const
{
	return crashOnError;
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

void Onyx::ErrorHandler::setLogWarnings(bool logWarnings)
{
	this->logWarnings = logWarnings;
}

void Onyx::ErrorHandler::setLogErrors(bool logErrors)
{
	this->logErrors = logErrors;
}

void Onyx::ErrorHandler::setCrashOnError(bool crashOnError)
{
	this->crashOnError = crashOnError;
}

void Onyx::ErrorHandler::setWarningCallback(void (*callback)(std::string))
{
	warningCallback = callback;
}

void Onyx::ErrorHandler::setErrorCallback(void (*callback)(std::string))
{
	errorCallback = callback;
}
