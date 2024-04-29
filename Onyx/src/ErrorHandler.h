#pragma once

#include <iostream>
#include <vector>

namespace Onyx
{

	/*
		@brief A struct to represent an error.
	 */
	struct Error
	{
		/*
			@brief The name of the function the error came from.
		 */
		std::string sourceFunction = "";

		/*
            @brief The error message.
         */
		std::string message = "";

		/*
            @brief How to fix the error.
         */
		std::string howToFix = "";

		/*
            @brief Converts the error to a string.
            @return A string representation of the error.
         */
		std::string toString() const;
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
		std::string sourceFunction = "";

		/*
            @brief The warning message.
         */
		std::string message = "";

		/*
            @brief How to fix the warning.
         */
		std::string howToFix = "";

		/*
            @brief The severity of the warning.
         */
		Severity severity = Severity::Null;

		/*
            @brief Converts the warning to a string.
            @return A string representation of the warning.
         */
		std::string toString() const;
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
			@param logWarnings Whether to log warnings.
			@param logErrors Whether to log errors.
			@param crashOnError Whether to throw errors.
		 */
		ErrorHandler(bool logWarnings, bool logErrors);

		/*
			@brief Creates a new ErrorHandler object with the specified settings.
			@param logWarnings Whether to log warnings.
			@param logErrors Whether to log errors.
			@param crashOnError Whether to throw errors.
		 */
		ErrorHandler(bool logWarnings, bool logErrors, Warning::Severity minWarningSeverity);

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
		bool logsWarnings() const;

		/*
			@brief Gets whether the handler logs errors.
			@return Whether the handler logs errors.
		 */
		bool logsErrors() const;

		/*
			@brief Gets the list of warnings that have been passed to the handler.
			@return The list of warnings that have been passed to the handler.
		 */
		const std::vector<Warning>& getWarningList() const;

		/*
			@brief Gets the list of errors that have been passed to the handler.
			@return The list of errors that have been passed to the handler.
		 */
		const std::vector<Error>& getErrorList() const;

		/*
			@brief Sets whether the handler logs warnings.
			@param logWarnings Whether the handler should log warnings.
		 */
		void setLogWarnings(bool logWarnings);

		/*
			@brief Sets whether the handler logs errors.
			@param logErrors Whether the handler should log errors.
		 */
		void setLogErrors(bool logErrors);

		/*
			@brief Sets the callback function to call when an error is passed to the handler.
			@param callback The callback function to call when an error is passed to the handler.
		 */
		void setErrorCallback(void (*callback)(const Error&));

		/*
			@brief Sets the callback function to call when a warning is passed to the handler.
			@param callback The callback function to call when a warning is passed to the handler.
		 */
		void setWarningCallback(void (*callback)(const Warning&));

	private:
		std::vector<Warning> m_warningList;
		std::vector<Error> m_errorList;

		bool m_logWarnings;
		bool m_logErrors;
		Warning::Severity m_minSeverity;

		void (*m_errorCallback)(const Error&);
		void (*m_warningCallback)(const Warning&);
	};
}
