#include "ui_flow.h"
#include "app.h"

static const std::string HEADER = "========================================\n"
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
            "3. Finish program"
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
            "0. Example Dataset 1",
            "1. Example Dataset 2",
            "2. Example Dataset 3",
            "3. Example Dataset 4",
            "4. Go back to Main Menu"
        }
    );

    return dataset.run();
}

int UI::show_algorithm_menu(State& app_state) {
    app_state.update_state(State::StateID::ALGORITHM);
    Menu algorithms (
        {
        "0. Brute-Force Approach",
        "1. Dynamic Programming Approach",
        "2. Greedy Approach",
        "3. Integer Linear Programming Approach",
        "4. Go back to Main Menu"
        }
    );

    return algorithms.run();
}

int UI::show_results_menu(State& app_state) {
    //TODO
    return 0;
}
