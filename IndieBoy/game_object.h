#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Defines the base game object that all others will inherit from

typedef struct
{
	float x, y;
}position_t;

class GameObject
{
public:

						GameObject();
						~GameObject();
						
	
				
	position_t			position;
};

#endif // GAMEOBJECT_H
