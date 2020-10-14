#include "Inventory.h"
#include <algorithm>

bool Inventory::indexIsValid(int idx)
{
	if (idx < 0 || idx >= ItemVec.size())
	{
		return false;
	}
	return true;
}

bool Inventory::swapItem(int base, int target)
{
	if (indexIsValid(base)|| indexIsValid(target))
	{
		std::swap(ItemVec[base], ItemVec[target]);
		return true;
	}
	return false;
};

bool Inventory::pushItem(BaseItem& item)
{
	for (uint32_t idx = 0; idx < ItemVec.size(); idx++)
	{
		if (ItemVec[idx].getState().isEmpty())
		{
			ItemVec[idx] = item;
			return true;
		}
	}
	return false;
}
bool Inventory::removeItem(int idx)
{
	if (indexIsValid(idx))
	{
		ItemVec[idx] = BaseItem();
		return true;
	}
	return false;
}
bool Inventory::useItem(int idx)
{
	if (indexIsValid(idx))
	{
		if (ItemVec[idx].process())
		{
			return true;
		}
	}
	return false;
}