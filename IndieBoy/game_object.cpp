#include "game_object.h"

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
}

ObjectRegistry& GameObject::getRegistry()
{
	return registry;
}
