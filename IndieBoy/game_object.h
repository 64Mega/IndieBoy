#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Defines the base game object that all others will inherit from

#include <objectregistry.h>
#include <boundingbox.h>

typedef struct
{
	float x, y;
}position_t;

class GameObject
{
public:
	static ObjectRegistry 			registry;
	
	static bool						collides(const GameObject& first, const GameObject& second);
	
									GameObject();
	virtual							~GameObject();
						
	virtual void					onUpdate();
	virtual void					onInstance();
	virtual void					onDeath();
	
	virtual ObjectRegistry& 		getRegistry();
				
	BoundingBox						bounding_box;
	position_t						position;
	bool							dead;
};

#endif // GAMEOBJECT_H
