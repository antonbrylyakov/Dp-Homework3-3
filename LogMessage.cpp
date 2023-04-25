#include "LogMessage.h"

LogMessage::LogMessage(LogMessageType type, const std::string& message): m_type(type), m_message(message)
{
}

LogMessageType LogMessage::type() const
{
	return m_type;
}

const std::string& LogMessage::message() const
{
	return m_message;
}
