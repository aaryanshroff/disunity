#include "player.h"
#include "inputhandler.h"
#include <SDL2/SDL.h> // SDL_GetTicks()
#include <iostream>
using namespace std;

Player::Player(const LoaderParams *params) : SDLGameObject{params} {}

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
  // to stop the player from moving when no key is pressed
  // velocity.setX(0);
  // velocity.setY(0);

  // if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
  //   velocity.setX(2);
  // }
  //
  // if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
  //   velocity.setX(-2);
  // }
  //
  // if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
  //   velocity.setY(-2);
  // }
  //
  // if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
  //   velocity.setY(2);
  // }
  handleInput();

  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {
  // cout << "Player::handleInput()" << endl;
  Vector2D *target = TheInputHandler::Instance()->getMousePosition();
  velocity = (*target - position) / 50; // / 50 is to slow down the speed
}
