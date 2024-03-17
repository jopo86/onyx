#pragma once

#include <iostream>
#include <string>
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
			@brief Creates a new ErrorHandler object with both logging and throwing disabled.
		 */

		ErrorHandler();
		/*
			@brief Creates a new ErrorHandler object with the specified logging and throwing settings.
			@param logging Whether to log all errors.
			@param throwing Whether to throw all errors.
		 */
		ErrorHandler(bool logging, bool throwing);

		/*
			@brief Passes an error to the handler.
			This is just used by the library, it shouldn't really be used by the user.
			@param error The error to pass.
		 */
		void err(std::string error);

		/*
			@brief Changes the logging setting.
			@param enabled Whether to log all errors.
		 */
		void setLogging(bool enabled);

		/*
			@brief Changes the throwing setting.
			@param enabled Whether to throw all errors.
		 */
		void setThrowing(bool enabled);

		/*
			@brief Gets all errors that have been passed.
			@return A vector containing each error as a string.
		 */
		std::vector<std::string> getErrors();

		/*
			@brief Gets the last error that was passed.
			@return The most recently passed error as a string.
		 */
		std::string getLastError();

		/*
			@brief Gets the logging setting.
			@return Whether logging is enabled.
		 */
		bool isLogging();

		/*
			@brief Gets the throwing setting.
			@return Whether throwing is enabled.
		 */
		bool isThrowing();

	private:
		std::vector<std::string> errors;

		bool logging;
		bool throwing;
	};
}