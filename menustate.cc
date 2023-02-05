#include "menustate.h"
#include "game.h"
#include "loaderparams.h"
#include "menubutton.h"
#include "playstate.h"
#include "texturemanager.h"
#include <iostream>
using namespace std;

const string MenuState::menuID = "MENU";

string MenuState::getStateID() const { return menuID; }

void MenuState::update() {
  for (GameObject *gameObject : gameObjects) {
    gameObject->update();
  }
}

void MenuState::render() {
  for (GameObject *gameObject : gameObjects) {
    gameObject->draw();
  }
}

bool MenuState::onEnter() {
  // load textures safely
  if (!TextureManager::Instance()->load("assets/button.png", "playbutton",
                                        Game::Instance()->getRenderer())) {
    return false;
  }

  if (!TextureManager::Instance()->load("assets/exit.png", "exitbutton",
                                        Game::Instance()->getRenderer())) {
    return false;
  }

  // create game objects
  // TODO: Use smart pointers
  GameObject *playButton = new MenuButton(
      new LoaderParams(100, 100, 400, 100, "playbutton"), menuToPlay);
  GameObject *exitButton = new MenuButton(
      new LoaderParams(100, 300, 400, 100, "exitbutton"), exitFromMenu);

  // add game objects to vector
  gameObjects.push_back(playButton);
  gameObjects.push_back(exitButton);

  cout << "Entering MenuState" << endl;
  return true;
}

bool MenuState::onExit() {
  for (GameObject *gameObject : gameObjects) {
    gameObject->clean();
  }

  gameObjects.clear();

  TextureManager::Instance()->clearFromTextureMap("playbutton");
  TextureManager::Instance()->clearFromTextureMap("exitbutton");

  cout << "Exiting MenuState" << endl;
  return true;
}

void MenuState::menuToPlay() {
  cout << "Play button clicked" << endl;
  Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu() {
  cout << "Exit button clicked" << endl;
  Game::Instance()->quit();
}
