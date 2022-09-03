#ifndef _LOADER_PARAMS_
#define _LOADER_PARAMS_

#include <string>

class LoaderParams
{
    int x;
    int y;
    int width;
    int height;
    std::string textureID;

public:
    // ctor
    LoaderParams(int x, int y, int width, int height, std::string textureID);

    // getters
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::string getTextureID() const { return textureID; }
};

#endif