#include <iostream>
// vvv imported in texturemanager.h
// #include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // IMG_Load, IMG_GetError
#include "texturemanager.h"
using namespace std;

// static member variable `instance` needs to be defined outside of class
TextureManager *TextureManager::instance = nullptr;

bool TextureManager::load(string filePath, string id, SDL_Renderer *renderer)
{
    // IMG_Load returns a surface, but we will convert it to a texture later
    //   since textures use hardware acceleration
    SDL_Surface *tempSurface = IMG_Load(filePath.c_str()); // .c_str() because IMG_Load expects a char *
    if (tempSurface == nullptr)
    {
        cout << "IMG_Load Error: " << IMG_GetError() << endl;
        return false;
    }

    // Convert surface to texture since textures use hardware acceleration
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    // Destroy the temporary surface
    SDL_FreeSurface(tempSurface);

    if (texture == nullptr)
    {
        cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
        return false;
    }

    textureMap[id] = texture;

    return true;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;

    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = destinationRectangle.w = width;
    sourceRectangle.h = destinationRectangle.h = height;

    destinationRectangle.x = x;
    destinationRectangle.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &sourceRectangle, &destinationRectangle, 0, 0, flip); // the 0, 0 is for rotation
                                                                                                     // (we _don't_ want to rotate so we ask the function to
                                                                                                     // rotate 0 degrees about the centre 0)
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;

    sourceRectangle.x = width * currentFrame;
    sourceRectangle.y = height * (currentRow - 1);
    sourceRectangle.w = destinationRectangle.w = width;
    sourceRectangle.h = destinationRectangle.h = height;
    destinationRectangle.x = x;
    destinationRectangle.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &sourceRectangle, &destinationRectangle, 0, 0, flip); // the 0, 0 is for rotation
                                                                                                     // (we _don't_ want to rotate so we ask the function to
                                                                                                     // rotate 0 degrees about the centre 0)
}