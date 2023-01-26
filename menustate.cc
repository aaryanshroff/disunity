#include "menustate.h"
#include <iostream>
using namespace std;

const string MenuState::menuID = "MENU";

string MenuState::getStateID() const { return menuID; }

void MenuState::update() {}

void MenuState::render() {}

bool MenuState::onEnter() {
  cout << "Entering MenuState" << endl;
  return true;
}

bool MenuState::onExit() {
  cout << "Exiting MenuState" << endl;
  return true;
}
