#include "inputhandler.h"
#include "game.h"

InputHandler::InputHandler() {}

void InputHandler::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      TheGame::Instance()->quit();
      break;
    case SDL_KEYDOWN:
      onKeyDown();
      break;
    case SDL_KEYUP:
      onKeyUp();
      break;

    default:
      break;
    }
  }
}
