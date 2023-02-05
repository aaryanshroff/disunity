#ifndef _MENUBUTTON_H_
#define _MENUBUTTON_H_

#include "sdlgameobject.h"
class MenuButton : public SDLGameObject {
  enum buttonState { MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2 };
  void (*callback)(); // pointer to a void function with no arguments
  bool released;

public:
  MenuButton(const LoaderParams *params, void (*callback)());

  virtual void draw();
  virtual void update();
  virtual void clean();

}; // class MenuButton

#endif
