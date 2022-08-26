#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
	// SDL_Init() returns -1 on error.
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}
	
	// 1st argument is window title. 2nd and 3rd arguments are x and y coordinates where the window is created.
	// Since we do not care where it is created, we pass in SDL_WINDOWPOS_UNDEFINED.
	SDL_Window *window = SDL_CreateWindow("SDL Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if ( window == NULL ) {
		cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}

	// Get window surface so we can draw to it.	
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	
	SDL_UpdateWindowSurface(window);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
