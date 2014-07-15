#include "Log.h"

using namespace std;

loglevel_e Log::log_level = ERROR;

void Log::error(std::string sender, std::string message)
{
	write(ERROR, sender, message);
}

void Log::info(std::string sender, std::string message)
{
	write(INFO, sender, message);
}

void Log::warning(std::string sender, std::string message)
{
	write(WARNING, sender, message);
}

void Log::write(loglevel_e level, std::string sender, std::string message)
{
	static bool freshRun = true;
	if(log_level < level) { return; }
	
	time_t cur_time;
	time(&cur_time);
	struct tm *time_info;
	time_info = localtime(&cur_time);
	
	std::string type = "UNKNOWN";
	if(level == ERROR) { type = "ERROR"; }
	if(level == WARNING) { type = "WARNING"; }
	if(level == INFO) { type = "INFO"; }
	
	std::stringstream timestring;
	timestring << "[" << sender << "][" << type << "](";
	timestring << time_info->tm_hour << ":" << time_info->tm_min << ":" << time_info->tm_sec << "): ";
	timestring << message; 
	
	cout << timestring.str() << endl;
	
	// Open log file
	ofstream logout;
	if(freshRun) 
	{
		logout.open("game_log.txt", ios::out);
		freshRun = false;
	}
	else
	{
		logout.open("game_log.txt", ios::app);
	}
	
	if(!logout.is_open())
	{
		return;
	}
	
	
	logout << timestring.str() << endl;
	logout.flush();
	logout.close();
}
