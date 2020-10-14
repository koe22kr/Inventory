#pragma once
#include <map>
#include <functional>
#include <iostream>
#include "Initializer.h"
enum class eClassKey
{
	eMustBeOverride = 0,
	eTEST1,
	eTEST2,
	eClassKeySize,
};

class PrototypeClass
{

public:
	eClassKey Key = eClassKey::eMustBeOverride;

	void setClassTypeName() {};
	
	eClassKey getClassKey() noexcept { return Key; };
	void setClassKey(eClassKey eKey) noexcept { Key = eKey; };
	PrototypeClass() {};
	PrototypeClass(eClassKey eKey):Key(eKey) {};
	virtual void Init();
	//////////////////////
	//재정의 해야함
	virtual void Process();
	//재정의 해야함
	//std::shared_ptr<PrototypeClass> makeShared() { return std::make_shared<>(); };
	
};
static std::map<eClassKey, std::function<std::shared_ptr<PrototypeClass>()>> ConstructorMap;
void setFactoryFunction(std::function<std::shared_ptr<PrototypeClass>()> funcMakeShared,eClassKey eClassKey);


static std::map<eClassKey, funcMakeShared> ConstructorMap2; 

//must check nullptr;
std::shared_ptr<PrototypeClass> makeConcrete(eClassKey eClassKey);

#define SETTING(_className,_eClassKey) ConstructorMap.emplace(std::make_pair(_eClassKey,[]() { return std::make_shared<_className>();}));
#define SETTINGA(_className,_eClassKey) ConstructorMap.emplace(std::make_pair(_eClassKey,[]() { return std::make_shared<_className>();}));



#define SETTING2(_prototypeclass) SETTING3(_prototypeclass)
#define SETTING3(_prototypeclass) int _prototypeclass



template<class proto>
void makeSharedClass(eClassKey eKey)
{
	if (eKey == eClassKey::eMustBeOverride)
	{
		return;
	}
	ConstructorMap2[eKey] = []() { return std::make_shared<proto>(eKey); }
}

class TEST1 : public PrototypeClass
{
public:
	TEST1() { setClassKey(eClassKey::eTEST1); };
	void Process() override { std::cout << "TEST1" << std::endl; };
};


class TEST2 : public PrototypeClass
{
public:
	funcMakeShared FuncMakeShared;
	TEST2() { setClassKey(eClassKey::eTEST2); };
	void Process() override { std::cout << "TEST2" << std::endl; };
	void Init()
	{
		
		FuncMakeShared = makeSharedClass<TEST2>(eClassKey::eTEST2);
		MakeSharedInitializer.pushInitialize(Key, FuncMakeShared);
	}
};
