#pragma once
#include "LogMessageProcessor.h"
#include "ConsoleLogCommand.h"

class WarningProcessor : public LogMessageProcessor
{
public:
	WarningProcessor();
	WarningProcessor(std::unique_ptr<LogMessageProcessor> next);
protected:
	ConsoleLogCommand m_command;
	void DoProcess(const LogMessage& msg);
};