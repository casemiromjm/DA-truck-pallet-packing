#include "ui_flow.h"

int UI::show_main_menu(State& app_state) {
    app_state.update_state(State::MAIN);

    Menu main_menu
    (
        {
            "0. What we have done",
            "1. Select a data set",
            "2. Select an algorithm",
            "3. Finish program"
        },

"========================================\n"
        "  Truck Delivery Packing Optimization   \n"
        "developed by Casemiro, Rafael and Sebastiao\n"
        "========================================\n"
    );

    return main_menu.run();
}

int UI::show_info_menu(State& app_state) {
    app_state.update_state(State::INFO);
    Menu functionalities(
        {"0. Go back to Main Menu"
        },
        "- Good interactive menu\n"
    );

    return functionalities.run();
}

int UI::show_dataset_menu(State& app_state) {
    app_state.update_state(State::DATASET);
    Menu dataset(
        {
            "0. Dataset 1",
            "1. Dataset 2",
            "2. Dataset 3",
            "3. Dataset 4",
            "4. Go back to Main Menu"
        }
    );

    return dataset.run();
}

int UI::show_algorithm_menu(State& app_state) {
    app_state.update_state(State::DATASET);
    Menu algorithms (
        {
        "0. Brute-Force Approach",
        "1. Dynamic Progamming Approach",
        "2. Greedy Approach",
        "3. Integer Linear Programming Approach",
        "4. Go back to Main Menu"
        }
    );

    return algorithms.run();
}

int UI::show_results_menu(State& app_state) {
    //TODO
}
