#pragma once

#include <iostream>
#include <vector>

namespace Onyx
{

	/*
		@brief A class for handling errors that occur internally in the library.
		The handler decides what to do with the errors based on the logging/throwing settings set by the user.
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
		ErrorHandler(bool logWarnings, bool logErrors, bool crashOnError);

		/*
			@brief Passes a warning to the handler.
			This is just used by the library, it shouldn't really be used by the user.
			@param msg The warning message to pass.
		 */
		void warn(const std::string& msg);

		/*
			@brief Passes an error to the handler.
			This is just used by the library, it shouldn't really be used by the user.
			@param msg The error message to pass.
		 */
		void err(const std::string& msg);

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
			@brief Gets whether the handler throws errors.
			@return Whether the handler throws errors.
		 */
		bool crashesOnError() const;

		/*
			@brief Gets the list of warnings that have been passed to the handler.
			@return The list of warnings that have been passed to the handler.
		 */
		const std::vector<std::string>& getWarningList() const;

		/*
			@brief Gets the list of errors that have been passed to the handler.
			@return The list of errors that have been passed to the handler.
		 */
		const std::vector<std::string>& getErrorList() const;

		/*
			@brief Gets the list of all messages (errors and warnings) that have been passed to the handler.
			@return The list of all messages that have been passed to the handler.
		 */
		const std::vector<std::string>& getAllMessageList() const;

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
			@brief Sets whether the handler throws errors.
			@param crashOnError Whether the handler should throw errors.
		 */
		void setCrashOnError(bool crashOnError);

		/*
			@brief Sets the callback function to call when an error is passed to the handler.
			@param callback The callback function to call when an error is passed to the handler.
		 */
		void setErrorCallback(void (*callback)(std::string));

		/*
			@brief Sets the callback function to call when a warning is passed to the handler.
			@param callback The callback function to call when a warning is passed to the handler.
		 */
		void setWarningCallback(void (*callback)(std::string));

	private:
		std::vector<std::string> warningList;
		std::vector<std::string> errorList;
		std::vector<std::string> allMessageList;

		bool logWarnings;
		bool logErrors;
		bool crashOnError;

		void (*errorCallback)(std::string);
		void (*warningCallback)(std::string);
	};
}