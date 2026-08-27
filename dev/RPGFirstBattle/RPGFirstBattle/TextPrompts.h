#pragma once
#include <string>
#include <iostream>
#include "Heroes.h"
class TextPrompts
{
public:
	static void DisplayMessage(std::string message);//Has a simple text box around the text, just for looks
	static void PressEnterToContinue(); //Instruct the user to hit Enter
	static void GameIntro(Heroes& hero, std::string& heroName);//Intro to the game 
};

