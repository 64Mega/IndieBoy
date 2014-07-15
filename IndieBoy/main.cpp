#include <cstdio>
#include <iostream>
#include <gl/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <log.h>
#include <config_file.h>
#include <game_window.h>

int main(int argc, char **argv)
{
	Log::log_level = ERROR;
	
	ConfigFile config;
	GameWindow gameWindow; 
	
	gameWindow.setupFromConfig(config);
	gameWindow.create();

	while(gameWindow.refresh())
	{
		glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glVertex2i(0,0);
			glVertex2i(80,0);
			glVertex2i(80,72);
			glVertex2i(0,72);
		glEnd();
		gameWindow.render();
	}

	config.commit("config.cfg");
	
	Log::info("Main", "Exiting cleanly");
	return 0;
}
