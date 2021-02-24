#include "Log.hpp"

#include <ctime>
#include <cstdarg>

LogMessage::LogMessage(LogSeverity severity, const std::string& message) :
	_severity(severity),
	_message(message) {}

void Log::SaveMessage(LogSource src, LogSeverity sev, const char* fmt, ...) {
	char buffer[1024];

	va_list argptr;
	va_start(argptr, fmt);

	vsprintf(buffer, fmt, argptr);

	va_end(argptr);

	std::string ss;
	switch (src) {
	case LogSource::NEO_DOA:
		ss.append("[NeoDoa]");
		break;
	case LogSource::CLIENT:
		ss.append("[Client]");
		break;
	default:
		ss.append("[SRC ??]");
		break;
	};
	ss.append(buffer);
	_messages.push_back({ sev, ss });
}

#define RESET	"\033[0m"				// Ordinary console...
#define DATE	"\033[96m"				// Date/Time
#define WHITE	"\033[97m"				// TRACE
#define GREEN	"\033[92m"				// INFO
#define ORANGE	"\033[33m"				// WARNING
#define RED		"\033[31m"				// ERROR
#define REDF	"\033[30m\u001b[41m"	// FATAL

void Log::Print(LogSource src, LogSeverity sev, const char* fmt, ...) {
	const char* type;
	switch (sev) {
	case LogSeverity::TRACE:
		type = WHITE "[TRACE]:" RESET "\t ";
		break;
	case LogSeverity::INFO:
		type = GREEN "[INFO]:" RESET "\t ";
		break;
	case LogSeverity::WARNING:
		type = ORANGE "[WARNING]:" RESET " ";
		break;
	case LogSeverity::ERRO:
		type = RED "[ERROR]:" RESET "\t ";
		break;
	case LogSeverity::FATAL:
		type = REDF "[FATAL]:" RESET "\t ";
		break;
	default:
		type = "??!";
		break;
	}

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), DATE "[%d-%m-%Y %H:%M:%S]" RESET " ", timeinfo);

	std::string ss;
	ss.append(buffer).append(type);
	switch (src) {
	case LogSource::NEO_DOA:
		ss.append("[NeoDoa]");
		break;
	case LogSource::CLIENT:
		ss.append("[Client]");
		break;
	default:
		ss.append("[SRC ??]");
		break;
	};
	ss.append(fmt).append("\n");

	va_list argptr;
	va_start(argptr, fmt);

	vprintf(ss.c_str(), argptr);

	va_end(argptr);
}

void Log::Clear() {
	_messages.clear();
}
