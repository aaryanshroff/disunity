#include "playstate.h"
#include "game.h"
#include "gameobject.h"
#include "loaderparams.h"
#include "texturemanager.h"
#include <iostream>
using namespace std;

const string PlayState::playID = "PLAY";

string PlayState::getStateID() const { return playID; }

void PlayState::update() {
  for (auto &gameObject : gameObjects) {
    gameObject->update();
  }
}

void PlayState::render() {
  for (auto &gameObject : gameObjects) {
    gameObject->draw();
  }
}

bool PlayState::onEnter() {
  // Load textures
  // TODO: Throw an exception instead
  if (!TheTextureManager::Instance()->load(
          "assets/zombie_idle_sheet.png", "zombie",
          TheGame::Instance()->getRenderer())) {
    return false;
  }

  GameObject *player =
      new Player(new LoaderParams(100, 100, 128, 82, "zombie"));

  gameObjects.push_back(player);

  cout << "Entering PlayState" << endl;
  return true;
}

bool PlayState::onExit() {
  cout << "Exiting PlayState" << endl;
  return true;
}
