#include "game_object.h"
#include <iostream>

using namespace std;

ObjectRegistry GameObject::registry;

GameObject::GameObject()
{
	GameObject::registry.add(this);
	dead = false;
}

GameObject::~GameObject()
{
}

void GameObject::onDeath()
{
}

void GameObject::onInstance()
{
}

void GameObject::onUpdate()
{
	GameObject::registry.iterate([this](GameObject& other){
		if(collides(*this, other))
		{
			if(!dead)
			{
				cout << "THERE WAS A COLLISION!" << endl;
				dead = true;
			}
		}
	});
}

ObjectRegistry& GameObject::getRegistry()
{
	return registry;
}

bool GameObject::collides(const GameObject& first, const GameObject& second)
{
	int bb1_width  = first.bounding_box.right - first.bounding_box.left;
	int bb1_height = first.bounding_box.bottom - first.bounding_box.top;
	int bb2_width  = second.bounding_box.right - second.bounding_box.left;
	int bb2_height = second.bounding_box.bottom - second.bounding_box.top;
	
	int t1lx = first.position.x + first.bounding_box.left;
	int t1ly = first.position.y + first.bounding_box.top;
	int t2lx = second.position.x + second.bounding_box.left;
	int t2ly = second.position.y + second.bounding_box.top;
	
	return !(t1lx + bb1_width  < t2lx 			  || 
			 t1lx 			   > t2lx + bb2_width ||
			 t1ly + bb1_height < t2ly 			  ||
			 t1ly 			   > t2ly + bb2_height);
}
