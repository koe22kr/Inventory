#include "Prototype.h"


void setPrototype(PrototypeClass prototypeClass, eConcreteClassType eClassType)
{
	std::function<PrototypeClass()> makePrototype = [&]() {	return prototypeClass.clone(); };
	CloneMap[eClassType] = makePrototype;
};