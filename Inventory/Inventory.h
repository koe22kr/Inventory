#pragma once
#include "Item.h"
#include <vector>

#include <string>

namespace ge
{
	enum eInventory
	{
		InventoryMaxSize = 40,
	};
}

class Inventory
{
	std::vector<BaseItem> ItemVec;
	Inventory()
	{
		ItemVec.resize(ge::InventoryMaxSize);
	}

};


template<class _type>
_type Create(std::string _typename)
{
	_typename.c_str();
}