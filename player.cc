#include "player.h"
#include "inputhandler.h"
#include <SDL2/SDL.h> // SDL_GetTicks()
#include <iostream>
using namespace std;

Player::Player(const LoaderParams *params) : SDLGameObject{params} {}

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    velocity.setX(2);
  }

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    velocity.setX(-2);
  }

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    velocity.setY(-2);
  }

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
    velocity.setY(2);
  }

  SDLGameObject::update();
}

void Player::clean() {}
