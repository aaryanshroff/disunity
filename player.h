#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "gameobject.h"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer *renderer);
    void update();
    void clean();
};

#endif