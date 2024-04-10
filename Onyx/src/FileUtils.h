#pragma once

#include <iostream>
#include <vector>

namespace Onyx
{
	namespace FileUtils
	{
		/*
			@brief Reads the file and returns the result.
			@param path The path of the file.
			@return The contents of the file as a string.
		 */
		std::string Read(const std::string& path);

		/*
			@brief Reads the file and returns the result.
			@param path The path of the file.
			@return The contents of the file as a string literal.
		 */
		const char* ReadLiteral(const std::string& path);

		/*
			@brief Reads the file and returns the result.
			@param path The path of the file.
			@return The contents of the file as a vector of string lines.
		 */
		std::vector<std::string> ReadLines(const std::string& path);

		/*
			@brief Writes to the file from a string.
			@param path The path of the file.
			@param text The text to write to the file.
			@param append Whether to append the text to the file, or overwrite all its contents.
		 */
		void Write(const std::string& path, const std::string& text, bool append);
	}
}
