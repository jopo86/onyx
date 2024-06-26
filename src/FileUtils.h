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
			@param result A pointer to a boolean that will be set to true if the file was read successfully, and false otherwise.
			@return The contents of the file as a string.
		 */
		std::string Read(const std::string& path, bool* result = nullptr);

		/*
			@brief Reads the file and returns the result.
			@param path The path of the file.
			@param result A pointer to a boolean that will be set to true if the file was read successfully, and false otherwise.
			@return The contents of the file as a string literal.
		 */
		const char* ReadLiteral(const std::string& path, bool* result = nullptr);

		/*
			@brief Reads the file and returns the result.
			@param path The path of the file.
			@param result A pointer to a boolean that will be set to true if the file was read successfully, and false otherwise.
			@return The contents of the file as a vector of string lines.
		 */
		std::vector<std::string> ReadLines(const std::string& path, bool* result = nullptr);

		/*
			@brief Writes to the file from a string.
			@param path The path of the file.
			@param text The text to write to the file.
			@param append Whether to append the text to the file, or overwrite all its contents.
		 */
		void Write(const std::string& path, const std::string& text, bool append);

		/*
			@brief Determines whether a file exists.
			@param path The path of the file.
			@return True if the file exists, and false otherwise.
		 */
		bool FileExists(const std::string& path);
	}
}
