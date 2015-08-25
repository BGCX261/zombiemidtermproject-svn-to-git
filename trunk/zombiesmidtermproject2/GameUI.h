//This will only work with Adam's version of SDLGraphics.
//Current version only supports printing text ingame
//used for displaying dice rolls and events
#ifndef GAMEUI_H
#define GAMEUI_H
#include "SDLGraphics.h"

class GameUI
{
private:
	string text_to_print[5];

	
public:
	GameUI(){
		text_to_print[0] = "Lawl";
	}

	void displayText(SDLGraphics * a_graphics);
	void moveText();

	void addDice(int num);

	void debug_addLine(){
		for (int j = 0; j < 5; ++j)
		{
			if (text_to_print[j].empty())
			{
				text_to_print[j] = text_to_print[j-1];
				break;
			}
		}
	}
};

#endif