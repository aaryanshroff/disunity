#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sdlgameobject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams *params);

    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif