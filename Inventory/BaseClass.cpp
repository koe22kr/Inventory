#include "BaseClass.h"
#include "Logger.h"
void BaseClass::Process()
{
	Logger::writeLogW(L"Process 함수는 꼭 재정의 해야 합니다. File : ");
}
