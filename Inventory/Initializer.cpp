#include "Initializer.h"
#include "Prototype.h"


void Initializer::doInit()
{
	while (MakeSharedQueue.size())
	{
		eClassKey Key = MakeSharedQueue.front().first;
		MakeSharedQueue.front().second(Key);
		
	}
   
}


void Initializer::pushInitialize(eClassKey eKey, funcMakeShared func)
{
	MakeSharedQueue.push(std::make_pair(eKey, func));
}
