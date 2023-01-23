#ifndef _INPUT_HANDLER_
#define _INPUT_HANDLER_

#include <SDL2/SDL.h>

class InputHandler {
  static InputHandler *instance;

  // private ctor to enable singleton pattern.
  // to instantiate, use the static instance() method instead.
  InputHandler();

  Uint8 *keyStates;

  void onKeyDown();
  void onKeyUp();

public:
  static InputHandler *Instance();

  void update();
  void clean();

  // getters
  bool isKeyDown(SDL_Scancode key) const;

}; // class InputHandler

#endif
