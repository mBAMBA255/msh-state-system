#ifndef MYSMARTHOME_H
#define MYSMARTHOME_H

#include "State.h"
#include <vector>

class MySmartHome {
private:
    State* currentState;
    std::vector<State*> stateList;
    int currentStateIndex;   // state index pointer

public:
    MySmartHome();

    void transitionTo(State* newState);
    void restorePreviousState();
    void showStateMenu();    // <-- ADD THIS
    void showCurrentState(); // if you already had it, keep it
};
#endif
