#include "Prototype.h"
#include "Logger.h"
void PrototypeClass::Process()
{
	Logger::writeLogW(L"Process �Լ��� �� ������ �ؾ� �մϴ�. File : ");
}

void setFactoryFunction(std::function<std::shared_ptr<PrototypeClass>()> funcMakeShared, eClassKey eClassKey)
{
	if (eClassKey ==eClassKey::eMustBeOverride)
	{
		return;
	}
	if (ConstructorMap.find(eClassKey) == ConstructorMap.end())
	{
		ConstructorMap[eClassKey] = funcMakeShared;
	}
};

std::shared_ptr<PrototypeClass> makeConcrete(eClassKey eClassKey)
{
	auto Target = ConstructorMap.find(eClassKey);
	if (Target != ConstructorMap.end())
	{
		return Target->second();
	}
	return nullptr;
}

