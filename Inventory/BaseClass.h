#pragma once

#include <vector>
#include <functional>
#include <iostream>
namespace ge
{
	enum eClassKey : unsigned int
	{
		eMustBeOverride = 0,
		eTEST1,
		eTEST2,
		eClassKeySize,
	};
}
class BaseClass
{
	ge::eClassKey Key;
public:
	void setClassKey(ge::eClassKey eKey) { Key = eKey; };
	ge::eClassKey getClassKey() noexcept { return Key; };
	
	//������ �ؾ���
	BaseClass() { setClassKey(ge::eClassKey::eMustBeOverride); };
	//������ �ؾ���
	virtual void Process();
	
};

class BaseClassManager
{
public:

	std::vector<BaseClass*> Items;
	void Init() {};
	
private:

};

//class SampleClass : public BaseClass
//{
//public:
//	//������ �ؾ���
//	SampleClass() { setClassKey(eClassKey::eTEST1); };
//	//������ �ؾ���
//	void Process() override {/*...*/};
//
//private:
//
//};