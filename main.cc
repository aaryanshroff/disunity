#include "game.h"
using namespace std;

int main()
{
	Game g;
	g.init("Pong", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	while (g.isRunning())
	{
		g.handleEvents();
		g.update();
		g.render();

		SDL_Delay(10);
	}

	g.clean();

	return EXIT_SUCCESS;
}
