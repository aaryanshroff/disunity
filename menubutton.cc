#include "menubutton.h"
#include "inputhandler.h"
#include <iostream>
using namespace std;

MenuButton::MenuButton(
    const LoaderParams *params,
    void (*callback)()) // pointer to a void function with no arguments
    : SDLGameObject{params}, callback{callback} { // call parent constructor
  // start at frame 0
  currentFrame = MOUSE_OUT; // currentFrame in SDLGameObject
}

void MenuButton::draw() {
  SDLGameObject::draw(); // use parent class to draw
}

void MenuButton::update() {
  Vector2D *pMousePos = TheInputHandler::Instance()->getMousePosition();

  // if mouse is within bounds of button
  if (pMousePos->getX() < (position.getX() + width) &&
      pMousePos->getX() > position.getX() &&
      pMousePos->getY() < (position.getY() + height) &&
      pMousePos->getY() > position.getY()) {
    currentFrame = MOUSE_OVER;
    // if mouse is clicked
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
      currentFrame = CLICKED;

      cout << "clicked" << endl;
      callback(); // call the callback function
      cout << "callback called" << endl;
      released = false;
    } else { // must release before next callback
      released = true;
      currentFrame = MOUSE_OVER;
    }
  } else {
    currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean() {
  SDLGameObject::clean(); // call parent clean
}
