#include "game.h"
#include "gameobject.h"
#include "inputhandler.h"
#include "loaderparams.h"
#include "menustate.h"
#include "playstate.h"
#include "texturemanager.h"
#include <SDL2/SDL_image.h> // IMG_Load (not needed in game.h)
#include <iostream>         // std::cout
using namespace std;

Game *Game::instance = nullptr;

Game *Game::Instance() {
  if (instance == nullptr) {
    instance = new Game();
  }
  return instance;
}

Game::Game(){};

bool Game::init(const char *title, int x, int y, int width, int height,
                SDL_WindowFlags flags) {
  // returns 0 on success
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    // ***** TODO: throw exception instead *****
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return false;
    //
  }

  // else successfully initialized SDL
  cout << "SDL_Init success" << endl;

  sdl_window = SDL_CreateWindow(title, x, y, width, height, flags);

  if (sdl_window == nullptr) {
    // ***** TODO: throw exception instead *****
    cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    return false;
  }

  // else successfully created window
  cout << "SDL_CreateWindow success" << endl;

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);

  if (sdl_renderer == nullptr) {
    // ***** TODO: throw exception instead *****
    cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
    return false;
  }

  // else successfully created renderer
  cout << "SDL_CreateRenderer success" << endl;

  // window will be cleared to this colour on render()
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);

  // Load textures
  if (!TheTextureManager::Instance()->load("assets/zombie_idle_sheet.png",
                                           "zombie", sdl_renderer)) {
    cout << "TheTextureManager::Instance()->load() failed to load" << endl;
    return false;
  }

  // AFTER loading textures, create game objects that use those textures (by
  // referencing their ID. in this case, the ID is `zombie`)
  gameObjects.push_back(
      new Player(new LoaderParams(100, 100, 430, 519, "zombie")));

  gameStateMachine = new GameStateMachine();
  gameStateMachine->changeState(new MenuState());

  running = true;

  return true;
}

void Game::update() { gameStateMachine->update(); };

void Game::render() {
  SDL_RenderClear(sdl_renderer); // clear to the draw color set in init()

  gameStateMachine->render();

  SDL_RenderPresent(sdl_renderer);
}

void Game::handleEvents() {
  TheInputHandler::Instance()->update();

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
    gameStateMachine->changeState(new PlayState());
  }
}

void Game::clean() {
  cout << "Cleaning game" << endl;
  TheInputHandler::Instance()->clean();
  SDL_DestroyWindow(sdl_window);
  SDL_DestroyRenderer(sdl_renderer);
  SDL_Quit();
}

void Game::quit() { running = false; }

// getters
bool Game::isRunning() const { return running; }

SDL_Renderer *Game::getRenderer() const { return sdl_renderer; }

GameStateMachine *Game::getStateMachine() const { return gameStateMachine; }
