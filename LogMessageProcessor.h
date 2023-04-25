#pragma once
#include <memory>
#include "LogMessage.h"

class LogMessageProcessor
{
public:
	virtual ~LogMessageProcessor() = default;
	void Process(const LogMessage& msg);
protected:
	LogMessageType m_type;
	std::unique_ptr<LogMessageProcessor> m_next;
	// Тот факт, что каждый обработчик обрабатывает один тип сообщения, заложим в базовый класс
	LogMessageProcessor(LogMessageType forType, std::unique_ptr<LogMessageProcessor> next);
	virtual void DoProcess(const LogMessage& msg) = 0;
};