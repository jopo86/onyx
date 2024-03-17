#pragma once

#include <string>
#include <fstream>

#include "Core.h"

namespace Onyx
{

	/*
		@brief A class to represent a file, providing reading and writing access.
	 */
	class File
	{
	public:
		/*
			@brief Creates an empty File object.
			Trying to use a file constructed like this will most likely cause errors.
		 */
		File();

		/*
			@brief Creates a new File object from the specified file path.
			This function may cause errors, it is recommended to use the overload with an error handler.
			@param path The path of the file.
		 */
		File(std::string path);

		/*
			@brief Reads the file and returns the result.
			@return The contents of the file as a string literal.
		 */
		const char* readLiteral();

		/*
			@brief Reads the file and returns the result.
			@return The contents of the file as a string.
		 */
		std::string read();

		/*
			@brief Reads the file and returns the result.
			@return The contents of the file as a vector of string lines.
		 */
		std::vector<std::string> readLines();

		/*
			@brief Writes to the file from a string literal.
			@param text The text to write to the file.
			@param append Whether to append the text to the file, or overwrite all its contents.
		 */
		void write(const char* text, bool append);

		/*
			@brief Writes to the file from a string.
			@param text The text to write to the file.
			@param append Whether to append the text to the file, or overwrite all its contents.
		 */
		void write(std::string text, bool append);

		/*
			@brief Gets the path of the file.
			@return The path of the file.
		 */
		std::string getPath();

	private:
		std::string path;

		std::ifstream fileIn;
		std::ofstream fileOut;
	};
}
