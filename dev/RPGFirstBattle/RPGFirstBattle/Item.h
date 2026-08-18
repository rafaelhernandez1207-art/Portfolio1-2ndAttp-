#pragma once
#include <string>
class Item
{
	std::string mItemName;

public:
	Item();

	std::string GetName();
	void SetName(std::string itemName);
};

