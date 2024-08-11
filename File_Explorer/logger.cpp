#include "logger.h"

Logger::Logger(const std::string& filename) : logFile(filename, std::ios::out | std::ios::app) {
	if(!logFile.is_open()) {
		std::cerr<<"Unable to open log file: "<<filename<<std::endl;
	}
}

Logger::~Logger() {
	if(logFile.is_open()) {
		logFile.close();
	}
}

void Logger::log(LogLevel level, const std::string& message) {
	if(logFile.is_open()) {
		logFile<<getCurrentTime()<<" "<<getLevelString(level)<<": "<<message<<std::endl;
	} else {
		std::cerr<<"Log file is not open"<<std::endl;
	}
}

std::string Logger::getCurrentTime() {
	std::time_t now = std::time(nullptr);
	char buf[100];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buf);
}

std::string Logger::getLevelString(LogLevel level) {
	switch(level) {
		case DEBUG: return "DEBUG";
		case INFO: return "INFO";
		case WARNING: return "WARNING";
		case ERROR: return "ERROR";
		case CRITICAL: return "CRITICAL";
		default: return "UNKNOWN";
	}
}


