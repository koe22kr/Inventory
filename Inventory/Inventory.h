#pragma once
#include "Item.h"
#include <vector>

#include <string>

namespace gn
{
	static size_t InventoryMaxSize = 40;
}

class Inventory
{
	
	std::vector<BaseItem> ItemVec;
	bool swapItem(int base, int target);
	bool pushItem(BaseItem& item);
	bool removeItem(int idx);
	bool useItem(int idx);
	bool indexIsValid(int idx);
	
	
	
	Inventory()
	{
		ItemVec.resize(gn::InventoryMaxSize);
	}
};

