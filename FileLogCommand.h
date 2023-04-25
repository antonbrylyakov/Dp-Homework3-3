#pragma once
#include <mutex>
#include "LogCommand.h"


class FileLogCommand : public LogCommand
{
public:
	FileLogCommand(const std::string& filePath);
	virtual void print(const std::string& message) override;
protected:
	std::string m_fileName;
	// Для простоты предполагаем, что у нас будет не более одного файла логов.
	// Поэтому используем статический мьютекс
	// Иначе можно использовать named_mutex из boost, запись в лог отдельным потоком, блокировка файлов в стиле C и т д.
	inline static std::mutex m_sync;
};
