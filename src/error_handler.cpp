#include <onyx/error_handler.hpp>

#include <string>
#include <iostream>

#include <onyx/core.hpp>

std::string onyx::Error::to_string() const
{
	std::string msg;
	msg += "Onyx Error\n";
	msg += "----------\n";
	msg += "Source Function: " + source_function + "\n";
	msg += "Message:         " + message + "\n";
	if (how_to_fix != "") msg += "How to fix:      " + how_to_fix + "\n";
	return msg;
}

std::string onyx::GLError::to_string() const
{
	std::string msg;
	msg += "OpenGL Error\n";
	msg += "------------\n";
	msg += "Source:  " + file + " (" + std::to_string(line) + ")\n";
	msg += "Error:   " + std::string(GL_ERROR_TO_STRING(code)) + "\n";
	return msg;
}

std::string onyx::Warning::to_string() const
{
	std::string msg;
	msg += "Onyx Warning\n";
	msg += "------------\n";
	msg += "Source Function: " + source_function + "\n";
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

onyx::ErrorHandler::ErrorHandler()
{
	this->log_warnings = this->log_errors = false;
	this->min_severity = Warning::Severity::Null;
	this->error_callback = nullptr;
	this->warning_callback = nullptr;
}

onyx::ErrorHandler::ErrorHandler(bool log_warnings, bool log_errors)
{
	this->log_warnings = log_warnings;
	this->log_errors = log_errors;
	this->min_severity = Warning::Severity::Null;
	this->error_callback = nullptr;
	this->warning_callback = nullptr;
}

onyx::ErrorHandler::ErrorHandler(bool log_warnings, bool log_errors, Warning::Severity min_warning_severity)
{
	this->log_warnings = log_warnings;
	this->log_errors = log_errors;
	this->min_severity = min_warning_severity;
	this->error_callback = nullptr;
	this->warning_callback = nullptr;
}

void onyx::ErrorHandler::warn(const Warning& warning)
{
	if (this->log_warnings && warning.severity >= this->min_severity) std::cout << warning.to_string() << "\n\n";
	if (this->warning_list.size() >= ErrorHandler::max_history) this->warning_list.erase(this->warning_list.begin());
	this->warning_list.push_back(warning);
	if (this->warning_callback != nullptr) warning_callback(warning);
}

void onyx::ErrorHandler::err(const Error& error)
{
	if (this->log_errors) std::cout << error.to_string() << "\n\n";
	if (this->error_list.size() >= ErrorHandler::max_history) this->error_list.erase(this->error_list.begin());
	this->error_list.push_back(error);
	if (this->error_callback != nullptr) error_callback(error);
}

bool onyx::ErrorHandler::logs_warnings() const
{
	return this->log_warnings;
}

bool onyx::ErrorHandler::logs_errors() const
{
	return this->log_errors;
}

const std::vector<onyx::Warning>& onyx::ErrorHandler::get_warning_list() const
{
	return this->warning_list;
}

const std::vector<onyx::Error>& onyx::ErrorHandler::get_error_list() const
{
	return this->error_list;
}

void onyx::ErrorHandler::set_log_warnings(bool new_log_warnings)
{
	this->log_warnings = new_log_warnings;
}

void onyx::ErrorHandler::set_log_errors(bool new_log_errors)
{
	this->log_errors = new_log_errors;
}

void onyx::ErrorHandler::set_warning_callback(void (*callback)(const Warning&))
{
	this->warning_callback = callback;
}

void onyx::ErrorHandler::set_error_callback(void (*callback)(const Error&))
{
	this->error_callback = callback;
}
