#include "MySmartHome.h"
#include "NormalState.h"
#include "HighPerformanceState.h"
#include "LowPowerState.h"
#include "SleepState.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

void logEvent(const std::string& message) {
    std::ofstream logFile("state_log.txt", std::ios::app);
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        logFile << std::ctime(&now) << " - " << message << std::endl;
    }
}

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
    logEvent("State changed");
}

void MySmartHome::restorePreviousState() {
    if (currentStateIndex > 0) {
        currentStateIndex--;                  // move back
        currentState = stateList[currentStateIndex]; // restore snapshot
        std::cout << "Restored to previous state." << std::endl;
        currentState->applySettings();
        logEvent("State restored");
    } else {
        std::cout << "Already at the first state." << std::endl;
        logEvent("State restore attempted at base state");
    }
}

void MySmartHome::showStateMenu() {
    char choice;
    std::cout << "\n--- Change State Menu ---\n";
    std::cout << "(N) Normal\n(H) High Performance\n(L) Low Power\n(S) Sleep\n(P) Previous State\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice) {
        case 'N': case 'n': transitionTo(new NormalState()); break;
        case 'H': case 'h': transitionTo(new HighPerformanceState()); break;
        case 'L': case 'l': transitionTo(new LowPowerState()); break;
        case 'S': case 's': transitionTo(new SleepState()); break;
        case 'P': case 'p': restorePreviousState(); break;
        default: std::cout << "Invalid choice.\n";
    }
}
