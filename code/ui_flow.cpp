#include "ui_flow.h"
#include "app.h"
#include "menu.h"

// technically it is part of the class App, but for simplification’s sake, it is on another file

static const std::string HEADER =  "========================================\n"
                                   "  Truck Delivery Packing Optimization   \n"
                                   "developed by Casemiro, Rafael and Sebastiao\n"
                                   "========================================\n";

int UI::show_main_menu(State& app_state, const App& app) {
    app_state.update_state(State::StateID::MAIN);

    std::string selec = "ALGORITHM: " + app.get_algorithm_name() + '\n' + "DATASET: " + app.get_dataset_name() + '\n';

    Menu main_menu
    (
        {
            "0. What we have done",
            "1. Select an algorithm",
            "2. Select a data set",
            "3. Calculate Knapsack Solution",
            "4. Finish program"
        },
        HEADER,
        selec
    );

    return main_menu.run();
}

int UI::show_info_menu(State& app_state) {
    app_state.update_state(State::StateID::INFO);
    Menu functionalities(
        {"0. Go back to Main Menu"
        },
        "- Good interactive menu\n"
    );

    return functionalities.run();
}

int UI::show_dataset_menu(State& app_state) {
    app_state.update_state(State::StateID::DATASET);
    Menu dataset(
        {
            "1. Example Dataset 1",
            "2. Example Dataset 2",
            "3. Example Dataset 3",
            "4. Example Dataset 4",
            "0. Go back to Main Menu"
        }
    );

    return dataset.run();
}

int UI::show_algorithm_menu(State& app_state) {
    app_state.update_state(State::StateID::ALGORITHM);
    Menu algorithms (
        {
        "1. Brute-Force Approach",
        "2. Dynamic Programming Approach",
        "3. Greedy Approach",
        "4. Integer Linear Programming Approach",
        "0. Go back to Main Menu"
        }
    );

    return algorithms.run();
}

int UI::show_results_menu(State& app_state) {
    app_state.update_state(State::StateID::RESULTS);
    //TODO
    return 0;
}
