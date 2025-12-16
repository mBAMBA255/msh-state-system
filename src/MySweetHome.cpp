#include "MySmartHome.h"
#include "NormalState.h"
#include <iostream>

MySmartHome::MySmartHome() {
    // Create the default state
    currentState = new NormalState();

    // Add the initial state to the state list (snapshot)
    stateList.push_back(currentState);

    // Set index pointer for current state
    currentStateIndex = 0;  // first snapshot
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

void MySmartHome::restorePreviousState() {
    if (currentStateIndex > 0) {
        currentStateIndex--;                  // move back
        currentState = stateList[currentStateIndex]; // restore snapshot
        std::cout << "Restored to previous state." << std::endl;
    } else {
        std::cout << "Already at the first state." << std::endl;
    }
}
