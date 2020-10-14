#include "Inventory.h"
#include "Prototype.h"
#include <iostream>

int main()
{
    SETTING(TEST1, eClassKey::eTEST1);

    //SETTING(PrototypeClass);

    auto Test1 = makeConcrete(eClassKey::eTEST1);
    auto Test2 = makeConcrete(eClassKey::eTEST2);
    auto Test3 = makeConcrete(eClassKey::eMustBeOverride);

    auto e1 = Test1->getClassKey();
    auto e2 = Test2->getClassKey();
    auto e3 = Test3->getClassKey();
    
    Test1->Process();
    Test2->Process();
    Test3->Process();
    SETTING2(PrototypeClass);
    return 1;
}