#pragma once
#include <queue>
#include <memory>

class PrototypeClass;
enum class eClassKey;
using funcMakeShared = std::shared_ptr<PrototypeClass>(*)(eClassKey eKey);

// ��ӹ��� ��ü�� �������� ó���ϴ� ����� ���ϵ�, �ϴ� ������ �׽�Ʈ �ϱ� ���ؼ� �̰͸����� ���.
class Initializer
{
public:
    std::queue<std::pair<eClassKey, funcMakeShared>> MakeSharedQueue;
    void pushInitialize(eClassKey eKey, funcMakeShared func);
    void doInit();
};

Initializer MakeSharedInitializer;