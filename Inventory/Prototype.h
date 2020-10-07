#pragma once
#include <map>
#include <functional>

class PrototypeClass;
enum class eConcreteClassType
{
	eConcreteClass = 1,
};
static std::map<int, std::function<PrototypeClass()>> CloneMap;
void setPrototype(PrototypeClass prototypeClass, eConcreteClassType eClassType);


class PrototypeClass
{
	eConcreteClassType Type = eConcreteClassType::eConcreteClass;
public:
	void setClassTypeName() {};
	PrototypeClass clone() { return *this; };
	virtual ~PrototypeClass() {};
};


