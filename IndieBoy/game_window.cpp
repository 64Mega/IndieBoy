#include "game_window.h"
#include <log.h>
#include <gl/gl.h>

GameWindow::GameWindow()
{
	this->window = nullptr;
	
	native_width = 500;
	native_height = 500;
	scale = 1.0F;
	fullscreen = false;
	framerate = 60;
	title = "Uninitialized!!";
}

GameWindow::~GameWindow()
{
	if(window)
	{
		delete window;
	}
}

void GameWindow::create()
{
	Log::info("GameWindow", "Creating GameWindow");
	
	if(this->window != nullptr)
	{
		// Re-create window
		sf::Uint32 style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;
		
		window->create(sf::VideoMode(native_width*scale, native_height*scale), title, style);
		window->setFramerateLimit(framerate);
	}
	else
	{
		sf::Uint32 style = fullscreen ? sf::Style::Fullscreen : sf::Style::Default;
		window = new sf::RenderWindow(sf::VideoMode(native_width*scale, native_height*scale), title, style);
		window->setFramerateLimit(framerate);
	}
	
	// Set up GL settings
	glMatrixMode(GL_PROJECTION);
	glViewport(0,0,native_width*scale,native_height*scale);
	glOrtho(0,native_width,native_height,0,-100,100);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

bool GameWindow::refresh()
{
	if(!window->isOpen()) { return false; }
	glClearColor(0.0F,0.0F,0.0F,1.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window->close();
			return false;
		}
	}
	
	return true;
}

void GameWindow::render()
{
	if(window)
	{
		window->display();
	}
}

void GameWindow::setupFromConfig(ConfigFile& config)
{
	Log::info("GameWindow","Getting window configuration from file");
	
	this->native_width = config.readInt("NativeWidth", 160);
	this->native_height = config.readInt("NativeHeight", 144);
	this->framerate = (float) config.readInt("FixedFramerate",60);
	this->scale = (float) config.readInt("Scale", 100) / 100.0F;
	this->fullscreen = config.readBool("Fullscreen", false);
	this->title = config.readString("WindowTitle", "IndieBoy");
	
	// Re-save all values to config
	config.writeInt("NativeWidth", native_width);
	config.writeInt("NativeHeight", native_height);
	config.writeInt("FixedFramerate", (int) framerate);
	config.writeInt("Scale", (int)(scale*100));
	config.writeBool("Fullscreen", fullscreen);
	config.writeString("WindowTitle", title);
}
