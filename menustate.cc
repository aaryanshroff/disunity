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
  for (const auto &gameObject : gameObjects) {
    gameObject->update();
  }
}

void MenuState::render() {
  for (const auto &gameObject : gameObjects) {
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
  std::unique_ptr<GameObject> playButton =
      std::make_unique<MenuButton>(MenuButton(
          new LoaderParams(100, 100, 400, 100, "playbutton"), menuToPlay));
  std::unique_ptr<GameObject> exitButton =
      std::make_unique<MenuButton>(MenuButton(
          new LoaderParams(100, 300, 400, 100, "exitbutton"), exitFromMenu));

  // add game objects to vector
  gameObjects.push_back(std::move(playButton));
  gameObjects.push_back(std::move(exitButton));

  cout << "Entering MenuState" << endl;
  return true;
}

bool MenuState::onExit() {
  for (const auto &gameObject : gameObjects) {
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
