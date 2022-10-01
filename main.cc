#include <iostream>
// vvv included in game.h
// #include <SDL2/SDL.h>
#include "game.h"
using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS; // Number of milliseconds in a second divided by FPS

int main()
{
	if (!TheGame::Instance()->init("Pong", 100, 100, 640, 480, SDL_WINDOW_SHOWN))
	{
		cout << "TheGame::Instance()->init() failed: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}

	while (TheGame::Instance()->isRunning())
	{
		Uint32 frameStart = SDL_GetTicks();

		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();

		Uint32 frameTime = SDL_GetTicks() - frameStart; // Time it took to render the frame

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay(static_cast<int>(DELAY_TIME - frameTime)); // Delay the frame to match the FPS
		}

		SDL_Delay(10);
	}

	TheGame::Instance()->clean();

	return EXIT_SUCCESS;
}
