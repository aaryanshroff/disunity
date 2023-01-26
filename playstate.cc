#include "playstate.h"
#include <iostream>
using namespace std;

const string PlayState::playID = "PLAY";

string PlayState::getStateID() const { return playID; }

void PlayState::update() {}

void PlayState::render() {}

bool PlayState::onEnter() {
  cout << "Entering PlayState" << endl;
  return true;
}

bool PlayState::onExit() {
  cout << "Exiting PlayState" << endl;
  return true;
}
