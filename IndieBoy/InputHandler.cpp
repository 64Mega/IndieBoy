#include "InputHandler.h"

bool InputHandler::_keystate[sf::Keyboard::KeyCount];

bool InputHandler::isKeyDown(sf::Keyboard::Key key)
{
	_keystate[key] = sf::Keyboard::isKeyPressed(key);
	return _keystate[key];
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key)
{
	bool newstate = sf::Keyboard::isKeyPressed(key);
	bool oldstate = _keystate[key];
	_keystate[key] = newstate;
	if(oldstate == false && newstate == true) { return true; }
	
	return false;
}
