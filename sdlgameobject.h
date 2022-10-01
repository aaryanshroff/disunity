#ifndef _SDL_GAME_OBJECT_H_
#define _SDL_GAME_OBJECT_H_

#include <string>
#include "gameobject.h"
#include "vector.h"

class LoaderParams;

class SDLGameObject : public GameObject
{
protected:
    Vector2D position;
    Vector2D velocity;

    int width;
    int height;

    int currentRow;
    int currentFrame;

    std::string textureID;

public:
    SDLGameObject(const LoaderParams *params);

    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif