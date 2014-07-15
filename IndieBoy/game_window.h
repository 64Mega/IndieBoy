#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <config_file.h>

class GameWindow
{
public:
	float					framerate;
	bool					fullscreen;
	int						native_width;
	int						native_height;
	float 					scale;
	std::string			title;
	sf::RenderWindow 		*window;
	
	void					create();
	void					setupFromConfig(ConfigFile& config);

							GameWindow();
							~GameWindow();
	
	bool 					refresh();
	void					render();
};

#endif // GAMEWINDOW_H
