#ifndef _INPUT_HANDLER_
#define _INPUT_HANDLER_

#include "vector.h"
#include <SDL2/SDL.h>
#include <vector>

class InputHandler {
  enum mouseButtons { LEFT = 0, MIDDLE = 1, RIGHT = 2 };

  // singleton pattern
  static InputHandler *instance;

  // private ctor to enable singleton pattern.
  // to instantiate, use the static instance() method instead.
  InputHandler();

  const Uint8 *keyStates;

  void onKeyDown();
  void onKeyUp();
  void onMouseMove(SDL_Event &event);
  void onMouseButtonDown(SDL_Event &event);
  void onMouseButtonUp(SDL_Event &event);

  std::vector<bool> mouseButtonStates;
  Vector2D *mousePosition;

public:
  static InputHandler *Instance();

  void update();
  void clean();
  void reset();

  // getters
  bool isKeyDown(SDL_Scancode key) const;
  bool getMouseButtonState(int buttonNumber) const;
  Vector2D *getMousePosition() const;

  // dtor
  ~InputHandler();

}; // class InputHandler

typedef InputHandler TheInputHandler; // alias to indicate singleton

#endif
