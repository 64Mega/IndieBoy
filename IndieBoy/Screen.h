#ifndef SCREEN_H
#define SCREEN_H

// A "Screen" is basically equivalent to the concept of a "Menu Screen" or "Pause Screen",
// to a certain degree.
// Each maintains its own state of execution, and in some cases execution can cascade down
// to the next level (Allowing for multi-layer screens/windows).
// Each Screen contains an ObjectRegistry of its own, so to add GameObjects to a specific Screen
// you add them to that Screen's registry.

#include <vector>

class Screen
{
private:
	static std::vector<Screen*> 			screen_list;
public:
	bool									finished = false; // Set to true to auto-kill the screen
	bool									cascade  = false; // Can screens below this one render or update?
	
	ObjectRegistry							objectRegistry;
	
											Screen();
	virtual 								~Screen();
	virtual void							onUpdate(bool cascaded = false);
	
	////////////////
	//STATIC METHODS
	
	static void								addScreen(Screen* screen);
	static Screen* 							getTopScreen();
	static std::vector<Screen*>::iterator 	getTopScreenIter();
	static void								updateScreens();
	static void								removeTopScreen();

};

#endif // SCREEN_H
