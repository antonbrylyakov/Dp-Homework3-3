#pragma once
#include "LogMessageProcessor.h"

class FatalErrorProcessor : public LogMessageProcessor
{
public:
	FatalErrorProcessor();
	FatalErrorProcessor(std::unique_ptr<LogMessageProcessor> next);
protected:
	void DoProcess(const LogMessage& msg);
};
