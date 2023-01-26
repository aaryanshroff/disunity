#include "gamestatemachine.h"

void GameStateMachine::pushState(GameState *state) {
  states.push_back(state);
  states.back()->onEnter();
}

void GameStateMachine::changeState(GameState *state) {
  if (!states.empty()) {
    if (states.back()->getStateID() == state->getStateID()) {
      return;
    }
    states.back()->onExit();
    states.pop_back();
  }
  states.push_back(state);
  states.back()->onEnter();
}

void GameStateMachine::popState() {
  if (!states.empty()) {
    states.back()->onExit();
    states.pop_back();
  }
}
