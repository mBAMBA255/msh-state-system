#include "MySmartHome.h"
#include "NormalState.h"

MySmartHome::MySmartHome() {
    // Create the default state
    currentState = new NormalState();

    // Add the initial state to the state list (snapshot)
    stateList.push_back(currentState);
}

void showCurrentState();
#include <iostream>

void MySmartHome::showCurrentState() {
    std::cout << "Current state initialized." << std::endl;
}
