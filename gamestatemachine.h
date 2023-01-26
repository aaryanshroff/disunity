// Finite State Machine for the game

#ifndef _GAME_STATE_MACHINE_H_
#define _GAME_STATE_MACHINE_H_

#include "gamestate.h"
#include <vector>

class GameStateMachine {
public:
  void update();
  void render();

  void pushState(GameState *state);
  void changeState(GameState *state);
  void popState();

private:
  std::vector<GameState *> states;
}; // class GameStateMachine

#endif
