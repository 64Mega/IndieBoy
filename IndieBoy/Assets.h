#ifndef ASSETS_H
#define ASSETS_H

// Static class that does several things related to game assets

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Assets
{
private:
	static std::vector<std::string>		keys_graphics;
	static std::vector<sf::Texture*>	vals_graphics;
public:
	static std::string 					path_graphics;
	static std::string					path_sounds;
	static std::string					path_music;
	
	static void							load();
	static void 						release();
	
	static sf::Texture*					getGraphic(std::string fname);
};

#endif // ASSETS_H
