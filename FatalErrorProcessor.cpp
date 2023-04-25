#include "FatalErrorProcessor.h"
#include <stdexcept>

FatalErrorProcessor::FatalErrorProcessor():
	FatalErrorProcessor(std::move(std::unique_ptr<LogMessageProcessor>()))
{
}

FatalErrorProcessor::FatalErrorProcessor(std::unique_ptr<LogMessageProcessor> next): LogMessageProcessor(LogMessageType::FatalError, std::move(next))
{
}

void FatalErrorProcessor::DoProcess(const LogMessage& msg)
{
	throw std::runtime_error(msg.message());
}
