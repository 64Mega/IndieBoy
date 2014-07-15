#ifndef LOG_H
#define LOG_H

// Static Logging class
// Allows for easy simultaneous logging to both console and file, with timestamps

#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

enum loglevel_e
{
	ERROR = 0,
	WARNING,
	INFO
};

class Log
{
public:
	static loglevel_e 		log_level;
	
	static void				write(loglevel_e level, std::string sender, std::string message);
	static void				warning(std::string sender, std::string message);
	static void				error(std::string sender, std::string message);
	static void				info(std::string sender, std::string message);
};

#endif // LOG_H
