#ifndef STATE_H
#define STATE_H

class State {
public:
    enum class StateID {
        // main menu
        MAIN,
        // info about what we implemented
        INFO,
        // reading dataset screen
        DATASET,
        // choose algorithm screen
        ALGORITHM,
        // show results screen
        RESULTS
    };

    State();
    void update_state(const StateID& new_state);
    bool check_curr_state(const StateID& state) const;
    StateID get_curr_state() const;
    bool operator==(const StateID& s) const;

private:
    StateID current_state;

};

#endif

