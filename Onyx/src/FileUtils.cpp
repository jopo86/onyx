#include "FileUtils.h"

#include <fstream>
#include <string>

#include "Core.h"

void onyx_add_malloc(void*, bool);
bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);

std::string Onyx::FileUtils::Read(const std::string& path)
{
	std::ifstream file(path);
	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::FileUtils::Read(const std::string& path)",
				.message = "File not found (or access denied): \"" + path + "\"",
				.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		return "";
	}

	std::string contents = "";
	std::string line = "";

	while (std::getline(file, line)) contents += line + "\n";

	file.close();

	return contents;
}

const char* Onyx::FileUtils::ReadLiteral(const std::string& path)
{
	std::ifstream file(path);
	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
			.sourceFunction = "Onyx::FileUtils::ReadLiteral(const std::string& path)",
			.message = "File not found (or access denied): \"" + path + "\"",
			.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		return "";
	}

	std::string* contents = new std::string("");
	onyx_add_malloc(contents, false);
	std::string line = "";

	while (std::getline(file, line)) *contents += line + "\n";

	file.close();

	return contents->c_str();
}

std::vector<std::string> Onyx::FileUtils::ReadLines(const std::string& path)
{
	std::ifstream file(path);
	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
			   .sourceFunction = "Onyx::FileUtils::ReadLines(const std::string& path)",
			   .message = "File not found (or access denied): \"" + path + "\"",
			   .howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		return {};
	}

	std::vector<std::string> lines;
	std::string line = "";

	while (std::getline(file, line)) lines.push_back(line);

	file.close();

	return lines;
}

void Onyx::FileUtils::Write(const std::string& path, const std::string& text, bool append)
{
	std::ofstream file;
	if (append) file.open(path, std::ios::app);
	else file.open(path);

	file << text;

	file.close();
}

bool Onyx::FileUtils::FileExists(const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open()) return false;
	file.close();
	return true;
}
