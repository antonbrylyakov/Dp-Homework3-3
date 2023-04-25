#pragma once
#include <string>
#include <mutex>
#include "LogCommand.h"

class ConsoleLogCommand : public LogCommand
{
public:
	virtual void print(const std::string& message) override;
protected:
	// Консоль одна, доступ из разных потоков будет блокироваться статическим мьютексом
	inline static std::mutex m_sync;
};