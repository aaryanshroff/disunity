#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "gamestate.h"
#include <string>

class MenuState : public GameState {
public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  // getters
  virtual std::string getStateID() const;

private:
  static const std::string menuID;

}; // class MenuState

#endif
