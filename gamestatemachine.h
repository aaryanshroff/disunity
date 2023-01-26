// Finite State Machine for the game

#ifndef _GAME_STATE_MACHINE_H_
#define _GAME_STATE_MACHINE_H_

#include "gamestate.h"

class GameStateMachine {
public:
  void update();
  void render();

  void pushState(GameState *state);
  void changeState(GameState *state);
  void popState();

}; // class GameStateMachine

#endif
