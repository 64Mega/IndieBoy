#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Defines the base game object that all others will inherit from

#include <objectregistry.h>

typedef struct
{
	float x, y;
}position_t;

class GameObject
{
public:
	static ObjectRegistry 			registry;
	
									GameObject();
	virtual							~GameObject();
						
	virtual void					onUpdate();
	virtual void					onInstance();
	virtual void					onDeath();
	
	virtual ObjectRegistry& 		getRegistry();
				
	position_t						position;
	bool							dead;
};

#endif // GAMEOBJECT_H
