#include "gameobject.h"
#include "texturemanager.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->textureID = textureID;

    currentRow = 1;
    currentFrame = 1;
}

void GameObject::draw(SDL_Renderer *renderer)
{
    TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, renderer);
}

void GameObject::update()
{
    x += 1;
}

void GameObject::clean()
{
    // TODO
}
