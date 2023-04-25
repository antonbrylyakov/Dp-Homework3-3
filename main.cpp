#include <iostream>
#ifdef _WIN32
#include "windows.h"
#endif

#include "FatalErrorProcessor.h"
#include "ErrorProcessor.h"
#include "WarningProcessor.h"
#include "UnknownMessageProcessor.h"

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef _WIN32
	SetConsoleCP(1251);
#endif

	auto unknownMessageProcessor = std::make_unique<UnknownMessageProcessor>();
	auto warningProcessor = std::make_unique<WarningProcessor>(std::move(unknownMessageProcessor));
	auto errorProcessor = std::make_unique<ErrorProcessor>("log.txt", std::move(warningProcessor));
	auto messageProcessorChain = std::make_unique<FatalErrorProcessor>(std::move(errorProcessor));

	{
		auto msg = LogMessage(LogMessageType::Warning, "Предупреждение!");
		messageProcessorChain->Process(msg);
	}

	{
		auto msg = LogMessage(LogMessageType::Error, "Ошибка!");
		messageProcessorChain->Process(msg);
	}

	{
		try
		{
			auto msg = LogMessage(LogMessageType::FatalError, "Фатальная ошибка!");
			messageProcessorChain->Process(msg);
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	{
		try
		{
			auto msg = LogMessage(LogMessageType::Unknown, "Неизвестная ошибка!");
			messageProcessorChain->Process(msg);
		}
		catch (std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	return 0;
}