#include <onyx/file_utils.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <utility>

#include <onyx/core.hpp>
#include "internal.hpp"

std::string onyx::file_utils::read(const std::string& path, bool* result)
{
	std::ifstream file(path, std::ios::binary);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::file_utils::read(const std::string& path)",
				.message = "File not found (or access denied): \"" + path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return "";
	}

	std::ostringstream contents;
	contents << file.rdbuf();

	if (result != nullptr) *result = true;
	return contents.str();
}

const char* onyx::file_utils::read_literal(const std::string& path, bool* result)
{
	bool read_result = false;
	std::string text = read(path, &read_result);
	if (!read_result)
	{
		if (result != nullptr) *result = false;
		return "";
	}

	std::string* contents = new std::string(std::move(text));
	onyx_add_malloc(contents, false);

	if (result != nullptr) *result = true;
	return contents->c_str();
}

std::vector<std::string> onyx::file_utils::read_lines(const std::string& path, bool* result)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		onyx_err(Error{
			   .source_function = "onyx::file_utils::read_lines(const std::string& path)",
			   .message = "File not found (or access denied): \"" + path + "\"",
			   .how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		if (result != nullptr) *result = false;
		return {};
	}

	std::vector<std::string> lines;
	std::string line = "";

	while (std::getline(file, line)) lines.push_back(line);

	file.close();

	if (result != nullptr) *result = true;
	return lines;
}

void onyx::file_utils::write(const std::string& path, const std::string& text, bool append)
{
	std::ofstream file;
	if (append) file.open(path, std::ios::app);
	else file.open(path);

	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::file_utils::write(const std::string& path, const std::string& text, bool append)",
				.message = "Failed to open file for writing: \"" + path + "\"",
				.how_to_fix = "Ensure the directory exists, the file is not locked by another process, and write access is not denied."
			}
		);
		return;
	}

	file << text;
	file.close();

	if (file.fail())
	{
		onyx_err(Error{
				.source_function = "onyx::file_utils::write(const std::string& path, const std::string& text, bool append)",
				.message = "Failed to write to file: \"" + path + "\"",
				.how_to_fix = "Ensure there is enough disk space and write access is not denied."
			}
		);
	}
}

bool onyx::file_utils::file_exists(const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open()) return false;
	file.close();
	return true;
}

std::string onyx::file_utils::get_dir(const std::string& filepath)
{
	size_t last_slash_pos = filepath.find_last_of("/\\");
    return (std::string::npos == last_slash_pos)? "" : filepath.substr(0, last_slash_pos);
}
