#include "MySmartHome.h"
#include "NormalState.h"
#include <iostream>

MySmartHome::MySmartHome() {
    // Create the default state
    currentState = new NormalState();

    // Add the initial state to the state list (snapshot)
    stateList.push_back(currentState);
}

void MySmartHome::showCurrentState() {
    std::cout << "Current state initialized." << std::endl;
}

// LLR33: Transition to a new state with snapshot
void MySmartHome::transitionTo(State* newState) {
    if (currentState != nullptr) {
        // Save current state in the list (snapshot)
        stateList.push_back(currentState);
        std::cout << "Snapshot of current state saved." << std::endl;
    }

    // Apply the new state
    currentState = newState;
    std::cout << "Transitioned to new state." << std::endl;
}