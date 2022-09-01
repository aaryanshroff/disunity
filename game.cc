#include <iostream>         // std::cout
#include <SDL2/SDL_image.h> // IMG_Load (not needed in game.h)
#include "game.h"
using namespace std;

bool Game::init(const char *title, int x, int y, int width, int height, SDL_WindowFlags flags)
{
    // returns 0 on success
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        // ***** TODO: throw exception instead *****
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return false;
        //
    }

    // else successfully initialized SDL
    cout << "SDL_Init success" << endl;

    sdl_window = SDL_CreateWindow(title, x, y, width, height, flags);

    if (sdl_window == nullptr)
    {
        // ***** TODO: throw exception instead *****
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return false;
    }

    // else successfully created window
    cout << "SDL_CreateWindow success" << endl;

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);

    if (sdl_renderer == nullptr)
    {
        // ***** TODO: throw exception instead *****
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return false;
    }

    // else successfully created renderer
    cout << "SDL_CreateRenderer success" << endl;
    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);

    running = true;

    // Load Zombie spritesheet
    SDL_Surface *tempSurface = IMG_Load("assets/zombie_idle_sheet.png");
    // Convert surface to texture since textures use hardware acceleration
    texture = SDL_CreateTextureFromSurface(sdl_renderer, tempSurface);
    // Delete the temporary surface
    SDL_FreeSurface(tempSurface);

    destinationRectangle.w = sourceRectangle.w = 430;
    destinationRectangle.h = sourceRectangle.h = 519;
    destinationRectangle.x = sourceRectangle.x = 0;
    destinationRectangle.y = sourceRectangle.y = 0;

    return true;
}

void Game::update()
{
    sourceRectangle.x = 430 * int(((SDL_GetTicks() / 100) % 15));
}; // empty for now

void Game::render()
{
    SDL_RenderClear(sdl_renderer);
    SDL_RenderCopyEx(sdl_renderer, texture, &sourceRectangle, &destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(sdl_renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    cout << "Cleaning game" << endl;
    SDL_DestroyWindow(sdl_window);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_Quit();
}

// getters
bool Game::isRunning() const
{
    return running;
}