#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class Logger {
	public:
		Logger(const std::string& filename);
		~Logger();
		void log(LogLevel level, const std::string& message);

	private:
		std::ofstream logFile;
		std::string getCurrentTime();
		std::string getLevelString(LogLevel level);
};

#endif // LOGGER_H

