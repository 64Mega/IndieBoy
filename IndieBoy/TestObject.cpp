#include "TestObject.h"

ObjectRegistry TestObject::registry;

TestObject::TestObject() : GameObject()
{
	TestObject::registry.add(this);
	dead = false;
}

TestObject::~TestObject()
{
}

void TestObject::onDeath()
{
}
void TestObject::onInstance()
{
}
void TestObject::onUpdate()
{
}

ObjectRegistry& TestObject::getRegistry()
{
	return registry;
}
