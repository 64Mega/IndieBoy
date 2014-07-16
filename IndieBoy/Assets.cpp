#include "Assets.h"
#include <dirent.h>
#include <mio.h>
#include <log.h>

std::vector<std::string>	Assets::keys_graphics;
std::vector<sf::Texture*>	Assets::vals_graphics;

std::string 				Assets::path_graphics = "graphics/";
std::string					Assets::path_sounds = "sounds/";
std::string					Assets::path_music = "music/";

using namespace std;

void Assets::load()
{
	// Load all graphics
	struct dirent *d_ent;
	DIR *dir;
	
	dir = opendir(path_graphics.c_str());
	if(!dir)
	{
		Log::error("Assets","Couldn't load path " + path_graphics);
		return;
	}
	
	while((d_ent = readdir(dir)) != NULL)
	{
		vector<string> frag = MIO::split(string(d_ent->d_name), '.');
		if(frag.size() < 2) { continue; }
		if(!(MIO::lower(frag.back()) == "png")) { continue; }
		
		sf::Texture *tmp = new sf::Texture();
		tmp->loadFromFile(path_graphics + string(d_ent->d_name));
		tmp->setSmooth(false);
		
		keys_graphics.push_back(d_ent->d_name);
		vals_graphics.push_back(tmp);
		
		Log::info("Assets","Loaded " + path_graphics + string(d_ent->d_name));
	}
}

void Assets::release()
{
	Log::info("Assets","Releasing assets");
	while(vals_graphics.size() > 0)
	{
		sf::Texture *tmp = vals_graphics.back();
		vals_graphics.pop_back();
		delete tmp;
	}
	Log::info("Assets","Released graphics");
}

sf::Texture* Assets::getGraphic(std::string fname)
{
	for(unsigned int i = 0; i < keys_graphics.size(); i++)
	{
		if(keys_graphics[i] == fname) 
		{
			return vals_graphics[i];
		}
	}
	
	Log::error("Assets", "No graphic '" + fname + "' found in lists.");
	return nullptr;
}
