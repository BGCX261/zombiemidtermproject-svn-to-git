#include "keyBoardHandler.h"

void keyBoardHandler::keyBoardInput()
{
	bool * keysHeld = g_input->getInput();
	

	if (keysHeld[SDLK_ESCAPE])
   {
	   isRunning = false;
   }

   if (keysHeld[SDLK_LEFT])
   {
      g_spritePlayer->moveLeft();
   }
   else if (keysHeld[SDLK_RIGHT])
   {
      g_spritePlayer->moveRight();
   }
   else if (keysHeld[SDLK_UP])
   {
	   g_spritePlayer->moveUp();
   }
   else if (keysHeld[SDLK_DOWN])
   {
	   g_spritePlayer->moveDown();
   }
   else if(keysHeld[SDLK_SPACE])
   {
	   g_zombie->lifeOutCome();
   }
   else if (keysHeld[SDLK_k])
   {
	   //m_ui->debug_addLine();
	   m_ui->addDice(m_diceclass->rollDice(0));
   }
   else 
   {
	   g_spritePlayer->stopMoving();
	}

}

keyBoardHandler::keyBoardHandler(Input* inputs, Character* spritePlayer, zombie* zombieCPU, GameUI* a_ui, DiceClass* a_diceclass): g_input(inputs), g_spritePlayer(spritePlayer), g_zombie(zombieCPU), m_ui(a_ui), m_diceclass(a_diceclass)
{
	isRunning = true;
}

bool keyBoardHandler::getIsRunning()
{
	return isRunning;
}
keyBoardHandler::~keyBoardHandler()
{
	delete g_input;
	delete g_spritePlayer;
	delete g_zombie;
}