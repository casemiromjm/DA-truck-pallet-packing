#include "state.h"

State::State() {
    current_state = MAIN;
}

State::StateID State::get_curr_state() const {
    return current_state;
}

bool State::check_curr_state(const StateID& state) const {
    return current_state == state;
}

void State::update_state(const StateID& new_state) {
    current_state = new_state;
}

bool State::operator==(const StateID& s) const {
    return current_state == s;
}