#ifndef _PLAY_STATE_H_
#define _PLAY_STATE_H_

#include "gamestate.h"

class PlayState : public GameState {
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
