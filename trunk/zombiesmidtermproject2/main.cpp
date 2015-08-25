#include "SDLGraphics.h"
#include "Input.h"
#include "Defines.h"
#include "Character2.h"
#include "zombie2.h"
#include "Timer.h"
#include "constants.h"
#include "keyBoardHandler.h"
#include "Die.h"
#include "GameUI.h"
#include "DiceClass.h"

int main(int argc, char **argv)
{
   SDLGraphics* g_graphics = NULL;
   Die* g_die = NULL;
   Input* g_input = NULL;
   Character* g_spritePlayer = NULL;
   zombie* g_zombie = NULL;
   Timer* g_timer = NULL;
   keyBoardHandler* g_keyBoard = NULL;
   bool gameIsRunning = true;
   GameUI* m_ui = NULL;
   DiceClass* m_diceclass = NULL;
   
   g_graphics = new SDLGraphics(WINDOW_WIDTH, WINDOW_HEIGHT,
                                WINDOW_TITLE,
                                BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE);
   g_die = new Die(0,0);
   m_diceclass = new DiceClass;

   g_spritePlayer = new Character(g_graphics,
                             SPRITE_PLAYER_IMAGE_X, SPRITE_PLAYER_IMAGE_Y,
                             SPRITE_PLAYER_IMAGE_WIDTH, SPRITE_PLAYER_IMAGE_HEIGHT,
                             TRANSPARENT_RED, TRANSPARENT_GREEN, TRANSPARENT_BLUE,
                             SPRITE_PLAYER_BITMAP_FILE_NAME, 
                             SPRITE_PLAYER_START_X, SPRITE_PLAYER_START_Y,
                             SPRITE_PLAYER_SPEED);
   g_zombie = new zombie(g_graphics, g_die,0,
						ZOMBIE_SPRITE_IMAGE_X,ZOMBIE_SPRITE_IMAGE_Y,
						ZOMBIE_SPRITE_IMAGE_WIDTH,ZOMBIE_SPRITE_IMAGE_HEIGHT,
						TRANSPARENT_RED,TRANSPARENT_GREEN,TRANSPARENT_BLUE,
						ZOMBIE_SPRITE_BITMAP_FILE_NAME,ZOMBIE_SPRITE_START_X,
						ZOMBIE_SPRITE_START_Y,ZOMBIE_SPRITE_SPEED);

   g_input = new Input();

   m_ui = new GameUI();
   g_keyBoard = new keyBoardHandler(g_input, g_spritePlayer, g_zombie, m_ui, m_diceclass);


   g_timer = new Timer();


   while (gameIsRunning)
   {
      float deltaTime = g_timer->timeSinceLastFrame(); 

      // Handle input
      g_input->readInput();

	  if (g_input->windowClosed()|| g_keyBoard->getIsRunning() == false)
      {
		  gameIsRunning = false;
      }
	  

	  g_keyBoard->keyBoardInput(); 

      // Handle game logic
      g_spritePlayer->update(deltaTime);
	  g_zombie->update(deltaTime);

      // Draw the scene
      g_graphics->beginScene();

	  g_zombie->randomMovement();

      g_spritePlayer->draw();
	  g_zombie->draw();
	  m_ui->displayText(g_graphics);
      g_graphics->endScene(); 

      // Give the computer a break (optional) 
      SDL_Delay(1);
   }

   delete g_timer;
   delete g_spritePlayer;
   delete g_graphics;
   delete g_input;
   delete g_zombie;
   delete g_die;

   return 0;
}





