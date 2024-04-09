#include "FileUtils.h"

std::string Onyx::FileUtils::Read(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open()) Onyx::Err("File not found (or access denied): \"" + path + "\"");

	std::string contents = "";
	std::string line = "";

	while (std::getline(file, line)) contents += line + "\n";

	file.close();

	return contents;
}

const char* Onyx::FileUtils::ReadLiteral(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open()) Onyx::Err("File not found (or access denied): \"" + path + "\"");

	std::string* contents = new std::string("");
	AddMalloc(contents, false);
	std::string line = "";

	while (std::getline(file, line)) *contents += line + "\n";

	file.close();

	return contents->c_str();
}

std::vector<std::string> Onyx::FileUtils::ReadLines(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open()) Onyx::Err("File not found (or access denied): \"" + path + "\"");

	std::vector<std::string> lines;
	std::string line = "";

	while (std::getline(file, line)) lines.push_back(line);

	file.close();

	return lines;
}

void Onyx::FileUtils::Write(std::string path, std::string text, bool append)
{
	std::ofstream file;
	if (append) file.open(path, std::ios::app);
	else file.open(path);

	file << text;

	file.close();
}
