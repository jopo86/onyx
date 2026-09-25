#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace onyx
{

	/*
		@brief A struct to represent an error.
	 */
	struct Error
	{
		/*
			@brief The name of the function the error came from.
		 */
		std::string source_function = "";

		/*
			@brief The error message.
		 */
		std::string message = "";

		/*
			@brief How to fix the error.
		 */
		std::string how_to_fix = "";

		/*
			@brief Converts the error to a string.
			@return A string representation of the error.
		 */
		std::string to_string() const;
	};

	/*
		@brief A struct to represent a warning.
	 */
	struct Warning
	{
		/*
			@brief An enum class to represent the severity of a warning.
		 */
		enum class Severity
		{
			Null,
			Low,
			Med,
			High
		};

		/*
			@brief The name of the function the warning came from.
		 */
		std::string source_function = "";

		/*
			@brief The warning message.
		 */
		std::string message = "";

		/*
			@brief How to fix the warning.
		 */
		std::string how_to_fix = "";

		/*
			@brief The severity of the warning.
		 */
		Severity severity = Severity::Null;

		/*
			@brief Converts the warning to a string.
			@return A string representation of the warning.
		 */
		std::string to_string() const;
	};

	/*
		@brief A class for handling errors that occur internally in the library.
	 */
	class ErrorHandler
	{
	public:
		/*
			@brief Creates a new ErrorHandler object with all settings set to false.
		 */
		ErrorHandler();

		/*
			@brief Creates a new ErrorHandler object with the specified settings.
			@param log_warnings Whether to log warnings.
			@param log_errors Whether to log errors.
		 */
		ErrorHandler(bool log_warnings, bool log_errors);

		/*
			@brief Creates a new ErrorHandler object with the specified settings.
			@param log_warnings Whether to log warnings.
			@param log_errors Whether to log errors.
			@param min_warning_severity The minimum severity a warning must have to be logged.
		 */
		ErrorHandler(bool log_warnings, bool log_errors, Warning::Severity min_warning_severity);

		/*
			@brief Passes a warning to the handler.
			This is just used by the library, it shouldn't really be used by the user.
			@param warning The warning to pass.
		 */
		void warn(const Warning& warning);

		/*
			@brief Passes an error to the handler.
			This is just used by the library, it shouldn't really be used by the user.
			@param error The error message to pass.
		 */
		void err(const Error& error);

		/*
			@brief Gets whether the handler logs warnings.
			@return Whether the handler logs warnings.
		 */
		bool logs_warnings() const;

		/*
			@brief Gets whether the handler logs errors.
			@return Whether the handler logs errors.
		 */
		bool logs_errors() const;

		/*
			@brief The maximum number of warnings and of errors the handler keeps in its history.
			Once a list is full, the oldest entry is discarded to make room for the newest.
		 */
		static constexpr std::size_t max_history = 256;

		/*
			@brief Gets the list of warnings that have been passed to the handler.
			Only the most recent `max_history` warnings are kept, oldest first.
			@return The list of warnings that have been passed to the handler.
		 */
		const std::vector<Warning>& get_warning_list() const;

		/*
			@brief Gets the list of errors that have been passed to the handler.
			Only the most recent `max_history` errors are kept, oldest first.
			@return The list of errors that have been passed to the handler.
		 */
		const std::vector<Error>& get_error_list() const;

		/*
			@brief Sets whether the handler logs warnings.
			@param new_log_warnings Whether the handler should log warnings.
		 */
		void set_log_warnings(bool new_log_warnings);

		/*
			@brief Sets whether the handler logs errors.
			@param new_log_errors Whether the handler should log errors.
		 */
		void set_log_errors(bool new_log_errors);

		/*
			@brief Sets the callback function to call when an error is passed to the handler.
			@param callback The callback function to call when an error is passed to the handler.
		 */
		void set_error_callback(void (*callback)(const Error&));

		/*
			@brief Sets the callback function to call when a warning is passed to the handler.
			@param callback The callback function to call when a warning is passed to the handler.
		 */
		void set_warning_callback(void (*callback)(const Warning&));

	private:
		std::vector<Warning> warning_list;
		std::vector<Error> error_list;

		bool log_warnings;
		bool log_errors;
		Warning::Severity min_severity;

		void (*error_callback)(const Error&);
		void (*warning_callback)(const Warning&);
	};
}
