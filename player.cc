#include <iostream>
#include <SDL2/SDL.h> // SDL_GetTicks()
#include "player.h"
using namespace std;

Player::Player(const LoaderParams *params) : SDLGameObject{params} {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    x -= 1;
    currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {}