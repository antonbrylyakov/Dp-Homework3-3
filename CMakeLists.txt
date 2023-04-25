cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(Homework)
add_executable(homework main.cpp "LogCommand.h"   "ConsoleLogCommand.h" "ConsoleLogCommand.cpp" "FileLogCommand.h" "FileLogCommand.cpp" "LogMessageType.h" "LogMessage.h" "LogMessage.cpp" "LogMessageProcessor.h" "LogMessageProcessor.cpp" "FatalErrorProcessor.h" "FatalErrorProcessor.cpp" "ErrorProcessor.h" "ErrorProcessor.cpp" "WarningProcessor.h" "WarningProcessor.cpp" "UnknownMessageProcessor.h" "UnknownMessageProcessor.cpp")