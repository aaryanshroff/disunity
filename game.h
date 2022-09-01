#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h> // cannot use forward declaration since SDL_Rect is not a pointer

class Game
{
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    bool running;
    int currentFrame;

public:
    bool init(const char *title, int x, int y, int width, int height, SDL_WindowFlags flags);
    void update();
    void render();
    void handleEvents();
    void clean();

    // getters
    bool isRunning() const;
}; // class Game

#endif // _GAME_H_