// Input.h 

#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"
#include "character2.h"
#include "zombie2.h"
#include "timer.h"
#include "GameUI.h"
#include "Die.h"
#include "DiceClass.h"

class Input
{
// Methods
public:
   Input();
   ~Input();

   // Call this before any other methods
   void readInput();

   bool * getInput();

   // Check this each frame
   bool windowClosed();

   //void handleKeyBoardInput();

// Data
private:
   SDL_Event m_event;
   bool m_keysHeld[323]; 
   bool m_windowClosed;
};

#endif
