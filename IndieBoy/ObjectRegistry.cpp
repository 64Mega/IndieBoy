#include "ObjectRegistry.h"
#include <game_object.h>

ObjectRegistry::ObjectRegistry()
{
	
}

ObjectRegistry::~ObjectRegistry()
{
}

void ObjectRegistry::add(GameObject* obj)
{
	g_list.push_back(obj);
}

void ObjectRegistry::iterate(std::function<void (GameObject&)> func)
{
	for(unsigned int i = 0; i < g_list.size(); i++)
	{
		func(*g_list[i]);
	}
}

void ObjectRegistry::cullDeads()
{
	for(objreg_iterator iter = g_list.begin(); iter != g_list.end(); iter++)
	{
		if(!(*iter)->dead) { continue; }
		
		GameObject* dptr = *iter;
		iter = g_list.erase(iter);
		delete dptr;
		if(iter == g_list.end()) { break; }
	}
}

int ObjectRegistry::getNumObjects()
{
	return g_list.size();
}
