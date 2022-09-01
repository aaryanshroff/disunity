#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <string>

// Forward declarations
class SDL_Renderer;
//

class GameObject
{
protected:
    std::string textureID;

    int currentFrame;
    int currentRow;

    int x;
    int y;

    int width;
    int height;

public:
    virtual void load(int x, int y, int width, int height, std::string textureID);
    virtual void draw(SDL_Renderer *renderer);
    virtual void update();
    virtual void clean();
};

#endif