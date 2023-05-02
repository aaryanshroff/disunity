#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "gamestate.h"
#include <vector>

class GameObject;

class PlayState : public GameState {
  std::vector<GameObject *> gameObjects;

public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  // getters
  virtual std::string getStateID() const;

private:
  static const std::string playID;
}; // class PlayState

#endif
