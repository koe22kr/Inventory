#include "Prototype.h"
#include "Logger.h"
void PrototypeClass::Process()
{
	Logger::writeLogW(L"Process 함수는 꼭 재정의 해야 합니다. File : ");
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

