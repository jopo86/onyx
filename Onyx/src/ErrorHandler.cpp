#pragma warning(disable: 4267)

#include "ErrorHandler.h"

#include <string>

#include "Core.h"

std::string Onyx::Error::toString() const
{
	std::string msg;
	msg += "Onyx Error\n";
	msg += "----------\n";
	msg += "Source Function: " + sourceFunction + "\n";
	msg += "Message:         " + message + "\n";
	if (howToFix != "") msg += "How to fix:      " + howToFix + "\n";
	return msg;
}

std::string Onyx::GLError::toString() const
{
	std::string msg;
	msg += "OpenGL Error\n";
	msg += "------------\n";
	msg += "Source:  " + file + " (" + std::to_string(line) + ")\n";
	msg += "Error:   " + std::string(glErrorToString(code)) + "\n";
	return msg;
}

std::string Onyx::Warning::toString() const
{
	std::string msg;
	msg += "Onyx Warning\n";
	msg += "------------\n";
	msg += "Source Function: " + sourceFunction + "\n";
	msg += "Message:         " + message + "\n";
	std::string sev;
	switch (severity)
	{
		case Severity::Null: sev = "Not Specified\n"; break;
		case Severity::Low: sev = "Low\n"; break;
		case Severity::Med: sev = "Medium\n"; break;
		case Severity::High: sev = "High\n"; break;
	};
	msg += "Severity:        " + sev;
	return msg;
}

Onyx::ErrorHandler::ErrorHandler()
{
	m_logWarnings = m_logErrors = false;
	m_minSeverity = Warning::Severity::Null;
	m_errorCallback = nullptr;
	m_warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors)
{
	m_logWarnings = logWarnings;
	m_logErrors = logErrors;
	m_minSeverity = Warning::Severity::Null;
	m_errorCallback = nullptr;
	m_warningCallback = nullptr;
}

Onyx::ErrorHandler::ErrorHandler(bool logWarnings, bool logErrors, Warning::Severity minWarningSeverity)
{
	m_logWarnings = logWarnings;
	m_logErrors = logErrors;
	m_minSeverity = minWarningSeverity;
	m_errorCallback = nullptr;
	m_warningCallback = nullptr;
}

void Onyx::ErrorHandler::warn(const Warning& warning)
{
	if (m_logWarnings&& warning.severity >= m_minSeverity) std::cout << warning.toString() << "\n\n";
	m_warningList.push_back(warning);
	if (m_warningCallback != nullptr) m_warningCallback(warning);
}

void Onyx::ErrorHandler::err(const Error& error)
{
	if (m_logErrors) std::cout << error.toString() << "\n\n";
	m_errorList.push_back(error);
	if (m_errorCallback != nullptr) m_errorCallback(error);
}

bool Onyx::ErrorHandler::logsWarnings() const
{
	return m_logWarnings;
}

bool Onyx::ErrorHandler::logsErrors() const
{
	return m_logErrors;
}

const std::vector<Onyx::Warning>& Onyx::ErrorHandler::getWarningList() const
{
	return m_warningList;
}

const std::vector<Onyx::Error>& Onyx::ErrorHandler::getErrorList() const
{
	return m_errorList;
}

void Onyx::ErrorHandler::setLogWarnings(bool logWarnings)
{
	m_logWarnings = logWarnings;
}

void Onyx::ErrorHandler::setLogErrors(bool logErrors)
{
	m_logErrors = logErrors;
}

void Onyx::ErrorHandler::setWarningCallback(void (*callback)(const Warning&))
{
	m_warningCallback = callback;
}

void Onyx::ErrorHandler::setErrorCallback(void (*callback)(const Error&))
{
	m_errorCallback = callback;
}
