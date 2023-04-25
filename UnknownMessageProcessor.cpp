#include "UnknownMessageProcessor.h"
#include <stdexcept>

UnknownMessageProcessor::UnknownMessageProcessor():
	UnknownMessageProcessor(std::move(std::unique_ptr<LogMessageProcessor>()))
{
}

UnknownMessageProcessor::UnknownMessageProcessor(std::unique_ptr<LogMessageProcessor> next):
	LogMessageProcessor(LogMessageType::Unknown, std::move(next))
{
}

void UnknownMessageProcessor::DoProcess(const LogMessage& msg)
{
	throw std::runtime_error("Необработанное сообщение: '" + msg.message() + "'");
}
