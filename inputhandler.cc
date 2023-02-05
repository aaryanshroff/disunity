#include "inputhandler.h"
#include "game.h"
#include "vector.h"

InputHandler::InputHandler() : mousePosition(new Vector2D{2, 2}) {
  // all mouse buttons are initially released
  for (int i = 0; i < 3; ++i) {
    mouseButtonStates.push_back(false);
  }
}

// TODO: Does this need to be a pointer?
InputHandler::~InputHandler() { delete mousePosition; }

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
    case SDL_MOUSEMOTION:
      onMouseMove(event);
      break;
    case SDL_MOUSEBUTTONDOWN:
      onMouseButtonDown(event);
      break;
    case SDL_MOUSEBUTTONUP:
      onMouseButtonUp(event);
      break;
    default:
      break;
    }
  }
}

void InputHandler::clean() {}

void InputHandler::reset() {
  // reset mouse button states
  for (int i = 0; i < 3; ++i) {
    mouseButtonStates[i] = false;
  }
}

// handlers

void InputHandler::onKeyUp() { keyStates = SDL_GetKeyboardState(0); }

void InputHandler::onKeyDown() { keyStates = SDL_GetKeyboardState(0); }

void InputHandler::onMouseMove(SDL_Event &event) {
  mousePosition->setX(event.motion.x);
  mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event &event) {
  if (event.button.button == SDL_BUTTON_LEFT) {
    mouseButtonStates[LEFT] = true;
  }
  if (event.button.button == SDL_BUTTON_MIDDLE) {
    mouseButtonStates[MIDDLE] = true;
  }
  if (event.button.button == SDL_BUTTON_RIGHT) {
    mouseButtonStates[RIGHT] = true;
  }
}

void InputHandler::onMouseButtonUp(SDL_Event &event) {
  if (event.button.button == SDL_BUTTON_LEFT) {
    mouseButtonStates[LEFT] = false;
  }
  if (event.button.button == SDL_BUTTON_MIDDLE) {
    mouseButtonStates[MIDDLE] = false;
  }
  if (event.button.button == SDL_BUTTON_RIGHT) {
    mouseButtonStates[RIGHT] = false;
  }
}

// getters

bool InputHandler::isKeyDown(SDL_Scancode key) const {
  return keyStates != 0 && keyStates[key] == 1;
}

bool InputHandler::getMouseButtonState(int buttonNumber) const {
  return mouseButtonStates[buttonNumber];
}

Vector2D *InputHandler::getMousePosition() const { return mousePosition; }
