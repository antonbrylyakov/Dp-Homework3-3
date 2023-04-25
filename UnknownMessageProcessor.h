#pragma once
#include "LogMessageProcessor.h"

class UnknownMessageProcessor : public LogMessageProcessor
{
public:
	UnknownMessageProcessor();
	UnknownMessageProcessor(std::unique_ptr<LogMessageProcessor> next);
protected:
	void DoProcess(const LogMessage& msg);
};