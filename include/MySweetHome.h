void transitionTo(State* newState);

private:
    int currentStateIndex;  // points to current state in stateList

public:
    void restorePreviousState();
