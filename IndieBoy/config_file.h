#ifndef CONFIGFILE_H
#define CONFIGFILE_H

/* Reads and writes configuration files in a very manageable way
 */
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <mio.h>

class ConfigFile
{
private:
	std::vector<std::string> 	keys_bool,
								keys_char,
								keys_int,
								keys_string;
								
	std::vector<bool>			vals_bool;
	std::vector<char>			vals_char;
	std::vector<int>			vals_int;
	std::vector<std::string>	vals_string;
	
	bool 		_load(std::string cfgName);
public:
				ConfigFile(std::string cfgName);
				ConfigFile();
				~ConfigFile();
	
	void 		commit(std::string cfgName);
	void 		refresh(std::string cfgName);
	
	void 		writeBool(std::string key, bool val);
	void 		writeChar(std::string key, char val);
	void 		writeInt(std::string key, int val);
	void 		writeString(std::string key, std::string val);
	
	bool		readBool(std::string key, bool def);
	char 		readChar(std::string key, char def);
	int 		readInt(std::string key, int def);
	std::string	readString(std::string key, std::string def);
};

#endif // CONFIGFILE_H
