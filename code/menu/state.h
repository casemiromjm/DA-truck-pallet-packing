#ifndef STATE_H
#define STATE_H

class State {
public:
    enum class StateID {
        // main menu
        MAIN,
        // info about what we implemented
        INFO,
        // choose algorithm screen
        ALGORITHM,
        // reading dataset screen
        DATASET,
        // show results screen
        RESULTS,
        // construct the performance CSV
        DATA_CONSTRUCT,
        FINISHED
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

