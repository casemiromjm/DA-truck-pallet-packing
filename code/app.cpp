#include "app.h"

#include "csv.h"
#include "truck.h"
#include "ui_flow.h"

App::App(): truck(0,0) {}


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
    Csv file;

    const std::string dataset_num = convert_num_str((int)get_dataset()+1);

    // como estamos simulando o terminal do sistema no clion, é preciso considerar q o ./code vem da pasta cmake-build-debug, por isso o path relativo volta assim

    // read truck and pallets file
    file.readCSV("../data/datasets/TruckAndPallets_" + dataset_num + ".csv");

    Truck t (std::stod(file.getData()[0][0]), std::stod(file.getData()[0][1]));

    // read pallets file
    file.readCSV("../data/datasets/Pallets_" + dataset_num + ".csv");

    for (auto pallet : file.getData()) {

        Pallet p (std::stoi(pallet[0]), std::stod(pallet[1]), std::stod(pallet[2]));

        t.add_available_pallet(p);
    }

    // "returns" the truck to "main" context
    truck = t;
}

/**
 * Converts an int to a string and expands to two digits when necessary
 * @param num Conversion target
 * @return Converted num
 */
std::string App::convert_num_str(int num) {
    if (abs(num) > 10) {
        return std::to_string(num);
    }

    return "0"+std::to_string(num);
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
                read_dataset();
                break;

            case State::StateID::RESULTS:
                //TODO
                break;

                // finish program opt
            case State::StateID::FINISHED:
                return;
        }
    }
}

