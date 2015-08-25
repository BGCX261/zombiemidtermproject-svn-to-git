#include "GameUI.h"

void GameUI::displayText(SDLGraphics * a_graphics)
{
	//5 lines of text, print them all
	for (int j = 0; j < 5; ++j)
	{
		if (text_to_print[j].empty())
			break;
		else
		{
			a_graphics->drawText(
				text_to_print[j].c_str(),	//String to print
				32,							//Size of text
				15,							//x position
				(500 - (j*40)),				//y position
				255, 255, 255,				//Foreground text color
				0, 0, 0);					//Background text color
		}
	}
}

void GameUI::moveText()
{
	text_to_print[4].clear();
	text_to_print[4] = text_to_print[3];
	text_to_print[3] = text_to_print[2];
	text_to_print[2] = text_to_print[1];
	text_to_print[1] = text_to_print[0];
	text_to_print[0].clear();
}

void GameUI::addDice(int num)
{
	char temp[2];
	moveText();
	text_to_print[0] = "Player 0 rolled a ";
	text_to_print[0].append(itoa(num, temp, 10));
}