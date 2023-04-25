#include "ErrorProcessor.h"

ErrorProcessor::ErrorProcessor(const std::string& fileName, std::unique_ptr<LogMessageProcessor> next): 
	LogMessageProcessor(LogMessageType::Error, std::move(next)),
	m_command(fileName)
{
	
}

ErrorProcessor::ErrorProcessor(const std::string& fileName):
	ErrorProcessor(fileName, std::move(std::unique_ptr<LogMessageProcessor>()))
{
}

void ErrorProcessor::DoProcess(const LogMessage& msg)
{
	m_command.print(msg.message());
}
