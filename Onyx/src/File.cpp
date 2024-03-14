#include "File.h"

Onyx::File::File()
{
	path = "";
}

Onyx::File::File(std::string path)
{
	this->path = path;
}

Onyx::File::File(std::string path, ErrorHandler &errorHandler)
{
	this->path = path;
	fileIn.open(path);
	if (!fileIn.is_open()) errorHandler.err("warning - file was not found: \"" + std::string(path) + "\"\nIf your purpose was to create a new file, you may ignore this.");
	fileIn.close();
}

const char* Onyx::File::readLiteral()
{
	fileIn.open(path);

	std::string* contents = new std::string("");
	std::string line = "";

	while (std::getline(fileIn, line)) contents->operator+=(line + "\n");

	fileIn.close();

	return contents->c_str();
}

std::string Onyx::File::read()
{
	fileIn.open(path);

	std::string contents = "";
	std::string line = "";

	while (std::getline(fileIn, line)) contents += line + "\n";

	fileIn.close();

	return contents;
}

std::vector<std::string> Onyx::File::readLines()
{
	fileIn.open(path);

	std::vector<std::string> lines;
	std::string line = "";

	while (std::getline(fileIn, line)) lines.push_back(line);

	fileIn.close();

	return lines;
}

void Onyx::File::write(const char *text, bool append)
{
	fileOut.open(path);
	
	if (append) fileOut << text;
	else fileOut << read() << text;

	fileOut.close();
}

void Onyx::File::write(std::string text, bool append)
{
	fileOut.open(path);
						  
	if (append) fileOut << text;
	else fileOut << read() << text;

	fileOut.close();
}

std::string Onyx::File::getPath()
{
	return path;
}
