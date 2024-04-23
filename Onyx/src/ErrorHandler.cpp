#pragma warning(disable: 4267)

#include "ErrorHandler.h"

#include "Core.h"

std::string Onyx::Error::toString() const
{
	int maxLen = 0;
	std::vector<std::string> lines;
	lines.push_back("Onyx Error");
	lines.push_back("Source Function: " + sourceFunction + "");
	lines.push_back("Message:         " + message + "");
	if (howToFix != "") lines.push_back("How to fix:      " + howToFix + "");
	for (const std::string& line : lines)
	{
		if (line.length() > maxLen) maxLen = line.length();
	}
	std::string msg = lines[0] + "\n";
	for (int i = 0; i < maxLen; i++) msg += "-";
	for (int i = 1; i < lines.size(); i++) msg += "\n" + lines[i];
	msg += "\n";
	for (int i = 0; i < maxLen; i++) msg += "-";
	return msg;
}

std::string Onyx::Warning::toString() const
{
	int maxLen = 0;
	std::vector<std::string> lines;
	lines.push_back("Onyx Error");
	lines.push_back("Source Function: " + sourceFunction + "");
	lines.push_back("Message:         " + message + "");
	std::string sev;
	switch (severity)
	{
		case Severity::Null: sev = "Not Specified"; break;
		case Severity::Low: sev = "Low"; break;
		case Severity::Med: sev = "Med"; break;
		case Severity::High: sev = "High"; break;
	};
	lines.push_back("Severity:        " + sev);
	if (howToFix != "") lines.push_back("How to fix:      " + howToFix + "");
	for (const std::string& line : lines)
	{
		if (line.length() > maxLen) maxLen = line.length();
	}
	std::string msg = lines[0] + "\n";
	for (int i = 0; i < maxLen; i++) msg += "-";
	for (int i = 1; i < lines.size(); i++) msg += "\n" + lines[i];
	msg += "\n";
	for (int i = 0; i < maxLen; i++) msg += "-";
	return msg;
}

Onyx::ErrorHandler::ErrorHandler()
{
	logWarnings = logErrors = false;
	minSeverity = Warning::Severity::Null;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors)
{
	this->logWarnings = logWarnings;
	this->logErrors = logErrors;
	minSeverity = Warning::Severity::Null;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors, Warning::Severity minWarningSeverity)
{
	this->logWarnings = logWarnings;
	this->logErrors = logErrors;
	minSeverity = minWarningSeverity;
	errorCallback = nullptr;
	warningCallback = nullptr;
}

void Onyx::ErrorHandler::warn(const Warning& warning)
{
	if (logWarnings && warning.severity >= minSeverity) std::cout << warning.toString() << "\n\n";
	warningList.push_back(warning);
	if (warningCallback != nullptr) warningCallback(warning);
}

void Onyx::ErrorHandler::err(const Error& error)
{
	if (logErrors) std::cout << error.toString() << "\n\n";
	errorList.push_back(error);
	if (errorCallback != nullptr) errorCallback(error);
}

bool Onyx::ErrorHandler::logsWarnings() const
{
	return logWarnings;
}

bool Onyx::ErrorHandler::logsErrors() const
{
	return logErrors;
}

const std::vector<Onyx::Warning>& Onyx::ErrorHandler::getWarningList() const
{
	return warningList;
}

const std::vector<Onyx::Error>& Onyx::ErrorHandler::getErrorList() const
{
	return errorList;
}

void Onyx::ErrorHandler::setLogWarnings(bool logWarnings)
{
	this->logWarnings = logWarnings;
}

void Onyx::ErrorHandler::setLogErrors(bool logErrors)
{
	this->logErrors = logErrors;
}

void Onyx::ErrorHandler::setWarningCallback(void (*callback)(const Warning&))
{
	warningCallback = callback;
}

void Onyx::ErrorHandler::setErrorCallback(void (*callback)(const Error&))
{
	errorCallback = callback;
}
