#include "loaderparams.h"
#include "game.h"
// vvv included in sdlgameobject.h
// #include "gameobject.h"
#include "sdlgameobject.h"
#include "texturemanager.h"

using namespace std;

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject{params}, position{static_cast<float>(params->getX()), static_cast<float>(params->getY())}, velocity{0, 0}, acceleration{0, 0}, width{params->getWidth()}, height{params->getHeight()}, currentRow{1}, currentFrame{1}, textureID{params->getTextureID()} {}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, static_cast<int>(position.getX()), static_cast<int>(position.getY()), width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;
}

void SDLGameObject::clean() {}