#ifndef APP_H
#define APP_H

#include "state.h"

class App {
public:
    App();
    State::StateID get_app_state() const;
    int get_algorithm() const;
    void set_algorithm(const int& alg);
    int get_dataset() const;
    void set_dataset(const int& dataset);
    void run();

private:
    State app_state;
    int chosen_algorithm;
    int chosen_dataset;
};

#endif
