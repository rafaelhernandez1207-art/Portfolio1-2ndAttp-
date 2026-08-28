#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "Heroes.h"
class SaveAndLoad
{
public:
	static void SavePlayer(std::vector<Heroes>& heroes);
	static void LoadGame(std::vector<Heroes>& heroes);
};

