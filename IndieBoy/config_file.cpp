#include "config_file.h"
#include <log.h>

// Reads and writes configuration files in a very manageable way

using namespace std;

bool ConfigFile::_load(std::string cfgName)
{
	ifstream fin;
	fin.open(cfgName.c_str(), ios::in);
	
	if(!fin.is_open()) return false;
	
	// Read each line one at a time
	string buffer;
	vector<string> lines;
	while(!fin.eof())
	{
		getline(fin, buffer);
		
		// Skip lines beginning with #, or blank lines
		if(buffer.length() == 0) { continue; }
		if(buffer[0] == '#') { continue; }
		
		// Split remaining lines, skip invalid ones
		vector<string> splits = MIO::split(buffer,':');
		if(splits.size() != 3) { continue; }
		
		char type = splits[0][0];
		switch(type)
		{
			case 'b': 
				keys_bool.push_back(splits[1]);
				vals_bool.push_back(MIO::lower(splits[2]) == "true");
				break;
			case 'c':
				keys_char.push_back(splits[1]);
				vals_char.push_back(splits[2][0]);
				break;
			case 'i':
				keys_int.push_back(splits[1]);
				vals_int.push_back(atoi(splits[2].c_str()));
				break;
			case 's':
				keys_string.push_back(splits[1]);
				vals_string.push_back(splits[2]);
				break;
			default:
				break;
		};
	}
	
	fin.close();
	
	return true;
}

ConfigFile::ConfigFile()
{
	// Open and read the default config.cfg file
	if(!_load("config.cfg"))
	{
		Log::warning("ConfigFile", "Couldn't find/open config.cfg, using defaults.");
	}
	else
	{
		Log::info("ConfigFile", "Loaded config.cfg");
	}
}

ConfigFile::~ConfigFile()
{
}

ConfigFile::ConfigFile(std::string cfgName)
{
	if(!_load(cfgName))
	{
		Log::warning("ConfigFile", "Couldn't find/open " + cfgName + ", using defaults.");
	}
	else
	{
		Log::info("ConfigFile", "Loaded " + cfgName);
	}
}

void ConfigFile::commit(std::string cfgName)
{
	ofstream fout;
	fout.open(cfgName.c_str(), ios::out);
	
	if(!fout.is_open())
	{
		Log::warning("ConfigFile", "Couldn't open " + cfgName + " for writing. Configuration will not be saved.");
		return;
	}
	
	// Write all config values
	for(unsigned int i = 0; i < keys_bool.size(); i++)
	{
		stringstream tmp;
		string type = vals_bool[i] ? "true" : "false";
		tmp << "b:" << keys_bool[i] << ":" << type;
		
		fout << tmp.str() << endl;
	}
	for(unsigned int i = 0; i < keys_char.size(); i++)
	{
		stringstream tmp;
		tmp << "c:" << keys_char[i] << ":" << vals_char[i];
		
		fout << tmp.str() << endl;
	}
	for(unsigned int i = 0; i < keys_int.size(); i++)
	{
		stringstream tmp;
		tmp << "i:" << keys_int[i] << ":" << vals_int[i];
		
		fout << tmp.str() << endl;
	}
	for(unsigned int i = 0; i < keys_string.size(); i++)
	{
		stringstream tmp;
		tmp << "s:" << keys_string[i] << ":" << vals_string[i];
		
		fout << tmp.str() << endl;
	}
	
	fout.close();
}

bool ConfigFile::readBool(std::string key, bool def)
{
	for(unsigned int i = 0; i < keys_bool.size(); i++)
	{
		if(keys_bool[i] == key) { return vals_bool[i]; }
	}
	return def;
}

char ConfigFile::readChar(std::string key, char def)
{
	for(unsigned int i = 0; i < keys_char.size(); i++)
	{
		if(keys_char[i] == key) { return vals_char[i]; }
	}
	return def;
}

int ConfigFile::readInt(std::string key, int def)
{
	for(unsigned int i = 0; i < keys_int.size(); i++)
	{
		if(keys_int[i] == key) { return vals_int[i]; }
	}
	return def;
}

std::string ConfigFile::readString(std::string key, std::string def)
{
	for(unsigned int i = 0; i < keys_string.size(); i++)
	{
		if(keys_string[i] == key) { return vals_string[i]; }
	}
	return def;
}

void ConfigFile::refresh(std::string cfgName)
{
	// Clear vectors and reload from config
	while(keys_bool.size() > 0) 
	{
		keys_bool.pop_back();
		vals_bool.pop_back();
	}
	while(keys_char.size() > 0) 
	{
		keys_char.pop_back();
		vals_char.pop_back();
	}
	while(keys_int.size() > 0) 
	{
		keys_int.pop_back();
		vals_int.pop_back();
	}
	while(keys_string.size() > 0) 
	{
		keys_string.pop_back();
		vals_string.pop_back();
	}
	
	_load(cfgName);
}

void ConfigFile::writeBool(std::string key, bool val)
{
	for(unsigned int i = 0; i < keys_bool.size(); i++)
	{
		if(keys_bool[i] == key) 
		{
			vals_bool[i] = val;
			return;
		}
	}
	
	keys_bool.push_back(key);
	vals_bool.push_back(val);
}

void ConfigFile::writeChar(std::string key, char val)
{
	for(unsigned int i = 0; i < keys_char.size(); i++)
	{
		if(keys_char[i] == key) 
		{
			vals_char[i] = val;
			return;
		}
	}
	
	keys_char.push_back(key);
	vals_char.push_back(val);
}

void ConfigFile::writeInt(std::string key, int val)
{
	for(unsigned int i = 0; i < keys_int.size(); i++)
	{
		if(keys_int[i] == key) 
		{
			vals_int[i] = val;
			return;
		}
	}
	
	keys_int.push_back(key);
	vals_int.push_back(val);
}

void ConfigFile::writeString(std::string key, std::string val)
{
	for(unsigned int i = 0; i < keys_string.size(); i++)
	{
		if(keys_string[i] == key) 
		{
			vals_string[i] = val;
			return;
		}
	}
	
	keys_string.push_back(key);
	vals_string.push_back(val);
}
