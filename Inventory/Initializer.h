#pragma once
#include <queue>
#include <memory>

class PrototypeClass;
enum class eClassKey;
using funcMakeShared = std::shared_ptr<PrototypeClass>(*)(eClassKey eKey);

// 상속받은 객체로 종류별로 처리하는 방식을 취하되, 일단 빠르게 테스트 하기 위해서 이것만으로 사용.
class Initializer
{
public:
    std::queue<std::pair<eClassKey, funcMakeShared>> MakeSharedQueue;
    void pushInitialize(eClassKey eKey, funcMakeShared func);
    void doInit();
};

Initializer MakeSharedInitializer;