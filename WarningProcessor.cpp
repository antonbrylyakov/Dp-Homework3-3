#include "WarningProcessor.h"

WarningProcessor::WarningProcessor():
	WarningProcessor(std::move(std::unique_ptr<LogMessageProcessor>()))
{
}

WarningProcessor::WarningProcessor(std::unique_ptr<LogMessageProcessor> next)
	:LogMessageProcessor(LogMessageType::Warning, std::move(next)),
	m_command()
{
}

void WarningProcessor::DoProcess(const LogMessage& msg)
{
	m_command.print(msg.message());
}
