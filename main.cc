#include <iostream>
// vvv included in game.h
// #include <SDL2/SDL.h>
#include "game.h"
using namespace std;

int main()
{
	if (!TheGame::Instance()->init("Pong", 100, 100, 640, 480, SDL_WINDOW_SHOWN))
	{
		cout << "TheGame::Instance()->init() failed: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}

	while (TheGame::Instance()->isRunning())
	{
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();

		SDL_Delay(10);
	}

	TheGame::Instance()->clean();

	return EXIT_SUCCESS;
}
