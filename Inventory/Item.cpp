#include "Item.h"

#include <iostream>



//BaseItem&& EquipItem::Create()
//{
//    return std::move(*this);
//}

bool EquipItem::process()
{
        //Equip process
        std::cout << "Equip" << std::endl;
        return true;
}

    //////////////////////////////////////////
//BaseItem&& UseItem::Create()
//{
//    return std::move(*this);
//}

bool UseItem::process()
{
    //Use Process
    std::cout << "Use" << std::endl;
    return true;
}

//////////////////////////////////////////

//BaseItem&& EtcItem::Create()
//{
//    return std::move(*this);
//
//}

bool EtcItem::process()
{
    //Etc Process
    std::cout << "Etc" << std::endl;
    return true;
}

