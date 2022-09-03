#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <string>

// Forward declarations
class LoaderParams;
//

class GameObject
{
protected:
    GameObject(const LoaderParams *params);
    virtual ~GameObject();

public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif