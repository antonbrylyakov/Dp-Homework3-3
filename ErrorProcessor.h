#pragma once
#include "LogMessageProcessor.h"
#include "FileLogCommand.h"

class ErrorProcessor : public LogMessageProcessor
{
public:
	ErrorProcessor(const std::string& fileName, std::unique_ptr<LogMessageProcessor> next);
	ErrorProcessor(const std::string& fileName);
protected:
	FileLogCommand m_command;
	void DoProcess(const LogMessage& msg);
};