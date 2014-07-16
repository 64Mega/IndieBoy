#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

// Static Input handler

#include <log.h>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

typedef sf::Keyboard KB;

class InputHandler
{
private:
	static bool 			_keystate[(int)sf::Keyboard::KeyCount];
public:
	static bool			isKeyDown(sf::Keyboard::Key key);
	static bool 			isKeyPressed(sf::Keyboard::Key key);
};

#endif // INPUTHANDLER_H
