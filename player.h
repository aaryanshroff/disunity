#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sdlgameobject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams *params);

    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
};

#endif