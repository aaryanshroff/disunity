#include <iostream>
#include "player.h"
using namespace std;

void Player::load(int x, int y, int width, int height, string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer *renderer)
{
    GameObject::draw(renderer);
}

void Player::update()
{
    x -= 1;
}

void Player::clean()
{
    GameObject::clean();
    cout << "clean player" << endl;
}
