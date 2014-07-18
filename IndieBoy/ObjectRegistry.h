#ifndef OBJECTREGISTRY_H
#define OBJECTREGISTRY_H

#include <functional>
#include <vector>
#include <string>

class GameObject;

typedef std::vector<GameObject*>::iterator objreg_iterator;

class ObjectRegistry
{
private:
	std::vector<GameObject*> 		g_list;
public:
									ObjectRegistry();
									~ObjectRegistry();
	
	void							add(GameObject* obj);
	void							cullDeads();
	int								getNumObjects(); 
	
	void							iterate(std::function<void (const GameObject*)> func);
};

#endif // OBJECTREGISTRY_H
