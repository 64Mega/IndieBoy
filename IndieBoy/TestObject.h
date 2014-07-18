#ifndef TESTOBJECT_H
#define TESTOBJECT_H

#include "game_object.h" // Base class: GameObject

class TestObject : public GameObject
{
public:
	static ObjectRegistry 			registry;

									TestObject();
	virtual 						~TestObject();

public:
	virtual void 					onDeath();
	virtual void 					onInstance();
	virtual void 					onUpdate();
	virtual ObjectRegistry& 		getRegistry();
};

#endif // TESTOBJECT_H
