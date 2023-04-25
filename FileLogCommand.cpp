#include <fstream>
#include <locale>
#include "FileLogCommand.h"

FileLogCommand::FileLogCommand(const std::string& filePath):m_fileName(filePath)
{
}

void FileLogCommand::print(const std::string& message)
{
	std::lock_guard lk(m_sync);
	std::ofstream of(m_fileName, std::ios_base::app);
	of.imbue(std::locale(".1251"));
	of << message << std::endl;
	of.close();
}
