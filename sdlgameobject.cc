#include "loaderparams.h"
#include "game.h"
// vvv included in sdlgameobject.h
// #include "gameobject.h"
#include "sdlgameobject.h"
#include "texturemanager.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject{params}
{
    x = params->getX();
    y = params->getY();
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update() {}

void SDLGameObject::clean() {}