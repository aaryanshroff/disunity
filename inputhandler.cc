#include "inputhandler.h"
#include "game.h"

InputHandler::InputHandler() {}

InputHandler *InputHandler::instance = nullptr;

InputHandler *InputHandler::Instance() {
  return instance == nullptr ? instance = new InputHandler() : instance;
}

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

void InputHandler::clean() {}

void InputHandler::onKeyUp() { keyStates = SDL_GetKeyboardState(0); }

void InputHandler::onKeyDown() { keyStates = SDL_GetKeyboardState(0); }

bool InputHandler::isKeyDown(SDL_Scancode key) const {
  return keyStates != 0 && keyStates[key] == 1;
}
