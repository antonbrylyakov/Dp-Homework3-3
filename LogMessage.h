#pragma once
#include <string>
#include "LogMessageType.h"

class LogMessage
{
public:
    LogMessage(LogMessageType type, const std::string& message);
    LogMessageType type() const;
    const std::string& message() const;
protected:
    LogMessageType m_type;
    std::string m_message;
};