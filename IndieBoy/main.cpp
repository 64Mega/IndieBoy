#include <cstdio>
#include <iostream>
#include <gl/gl.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <game.h>
#include <sprite.h>

#include <game_object.h>
#include <testobject.h>

#include <dirent.h>

using namespace std;

int main(int argc, char **argv)
{
	Log::log_level = ERROR;
	
	ConfigFile config;
	GameWindow gameWindow; 
	
	Log::log_level = (loglevel_e) config.readInt("LogLevel",0);
	
	gameWindow.setupFromConfig(config);
	gameWindow.create(config);
	
	Assets::load();
	
	Sprite testSprite;
	testSprite.setGraphic(Assets::getGraphic("rat_idle_18.png"), 16, 16);
	testSprite.speed = 0.25F;
	
	while(gameWindow.refresh())
	{
		if(InputHandler::isKeyDown(KB::Escape))
		{
			gameWindow.close();
		}
		
		// Window scaling
		if(InputHandler::isKeyPressed(KB::F5))
		{
				 if(gameWindow.scale == 1.0F) { gameWindow.scale = 2.0F; }
			else if(gameWindow.scale == 2.0F) { gameWindow.scale = 3.0F; }
			else if(gameWindow.scale == 3.0F) { gameWindow.scale = 4.0F; }
			else if(gameWindow.scale == 4.0F) { gameWindow.scale = 5.0F; }
			else if(gameWindow.scale == 5.0F) { gameWindow.scale = 1.0F; }
			
			gameWindow.create(config);
		}
		
		testSprite.render(64,64);
		
		gameWindow.render();
	}

	config.commit("config.cfg");
	
	Assets::release();
	
	Log::info("Main", "Exiting cleanly");
	return 0;
}



