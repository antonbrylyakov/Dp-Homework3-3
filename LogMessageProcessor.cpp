#include "LogMessageProcessor.h"

void LogMessageProcessor::Process(const LogMessage& msg)
{
	if (msg.type() == m_type)
	{
		DoProcess(msg);
	}

	if (m_next)
	{
		m_next->Process(msg);
	}
}

LogMessageProcessor::LogMessageProcessor(LogMessageType forType, std::unique_ptr<LogMessageProcessor> next): m_type(forType), m_next(std::move(next))
{
}
