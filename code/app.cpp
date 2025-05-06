#include "app.h"

#include "ui_flow.h"

App::App() = default;


State::StateID App::get_app_state() const {
    return app_state.get_curr_state();
}

int App::get_algorithm() const {
    return chosen_algorithm;
}

int App::get_dataset() const {
    return chosen_dataset;
}

void App::set_dataset(const int& dataset) {
    chosen_dataset = dataset;
}

void App::set_algorithm(const int &alg) {
    chosen_algorithm = alg;
}


void App::run() {

    // main app loop
    while (true) {
        switch (int choice = UI::show_main_menu(app_state)) {
            // implemented functionalities
            case 0:
                UI::show_info_menu(app_state);
                break;

                // select data set
            case 1:
                 set_dataset(UI::show_dataset_menu(app_state));
                break;

                // select algorithm
            case 2:
                set_algorithm(UI::show_algorithm_menu(app_state));
                break;

                // finish program opt
            case 3:
                return;
        }
    }
}

