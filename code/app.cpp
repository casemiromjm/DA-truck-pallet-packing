#include "app.h"

#include "csv.h"
#include "ui_flow.h"

App::App() = default;


State::StateID App::get_app_state() const {
    return app_state.get_curr_state();
}

App::Algorithm App::get_algorithm() const {
    return chosen_algorithm;
}

std::string App::get_algorithm_name() const {
    if (chosen_algorithm == Algorithm::NONE) {
        return algorithm_names.back();
    }

    return algorithm_names[(int)get_algorithm()];
}

App::Dataset App::get_dataset() const {
    return chosen_dataset;
}

std::string App::get_dataset_name() const {
    if (chosen_dataset == Dataset::NONE) {
        return dataset_names.back();
    }

    return dataset_names[(int)get_dataset()];
}

void App::set_algorithm(Algorithm alg) {
    chosen_algorithm = alg;
}

void App::set_dataset(Dataset data) {
    chosen_dataset = data;
}

void App::read_dataset() {
    Csv csv;
    //TODO
}


void App::run() {

    // main app loop
    while (true) {
        switch ((State::StateID)UI::show_main_menu(app_state, *this)) {
            // implemented functionalities
            case State::StateID::INFO:
                UI::show_info_menu(app_state);
                break;

            // select algorithm
            case State::StateID::ALGORITHM:
                set_algorithm((Algorithm)UI::show_algorithm_menu(app_state));
                break;

                // select dataset
            case State::StateID::DATASET:
                set_dataset((Dataset)UI::show_dataset_menu(app_state));
                break;

            case State::StateID::RESULTS:
                break;

                // finish program opt
            case State::StateID::FINISHED:
                return;
        }
    }
}

