#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "gameobject.h"
#include "gamestate.h"
#include <string>
#include <vector>

class MenuState : public GameState {
  static const std::string menuID;

  std::vector<GameObject *>
      gameObjects; // pointer because we want to use polymorphism

  // callback functions for MenuButtons
  static void menuToPlay(); // need to be static because our callback
                            // functionality only supports static functions
  static void exitFromMenu();

public:
  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  // getters
  virtual std::string getStateID() const;

}; // class MenuState

#endif
