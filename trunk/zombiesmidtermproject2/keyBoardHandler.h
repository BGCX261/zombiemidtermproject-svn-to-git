#ifndef KEY_BOARD_HANDLER_H
#define KEY_BOARD_HANDLER_H

#include "input.h"

class keyBoardHandler
{
public:
	void keyBoardInput();
	keyBoardHandler(Input* inputs, Character* spritePlayer, zombie* zombieCPU, GameUI* a_ui, DiceClass* a_diceclass);
	bool getIsRunning();
	~keyBoardHandler();

private:
	bool isRunning;
	Input * g_input;
	Character * g_spritePlayer;
	zombie* g_zombie;
	GameUI* m_ui;
	DiceClass* m_diceclass;

};

#endif