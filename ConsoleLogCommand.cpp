#include <iostream>
#include "ConsoleLogCommand.h"


void ConsoleLogCommand::print(const std::string& message)
{
	std::lock_guard lk(m_sync);
	std::cout << message << std::endl;
}
