#include "app.h"

#include "utils/csv.h"
#include "data_structures/truck.h"
#include "menu/ui_flow.h"

#include "algorithms/brute_force.h"
#include "algorithms/dynamic_prog.h"
#include "algorithms/greedy.h"

#include "performance_data/performance_data.h"

App::App(): truck(0,0) {}

State::StateID App::get_app_state() const {
    return app_state.get_curr_state();
}

App::Algorithm App::get_algorithm() const {
    return chosen_algorithm;
}

std::string App::get_algorithm_name() const {

    return algorithm_names[(int)get_algorithm()];
}

App::Dataset App::get_dataset() const {
    return chosen_dataset;
}

std::string App::get_dataset_name() const {

    return dataset_names[(int)get_dataset()];
}

void App::set_algorithm(Algorithm alg) {
    chosen_algorithm = alg;
}

void App::set_dataset(Dataset data) {
    chosen_dataset = data;
}

Truck App::get_truck() const {
    return truck;
}

void App::read_dataset() {
    Csv file;

    const std::string dataset_num = convert_num_str((int)get_dataset());

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
    if (abs(num) >= 10) {
        return std::to_string(num);
    }

    return "0"+std::to_string(num);
}

ReturnResult App::run_brute_force() {
    bool mock_validrun = true;
    return brute_force_packing(truck, total_duration, mock_validrun);
}

ReturnResult App::run_dp() {
    bool mock_validrun = true;
    return dp_packing(truck, total_duration, mock_validrun);
}

ReturnResult App::run_greedy() {
    bool mock_validrun = true;
    return greedy_packing(truck, total_duration, mock_validrun);
}

ReturnResult App::run_brute_force_backtracking() {
    bool mock_validrun = true;
    return brute_force_backtracking(truck, total_duration, mock_validrun);
}

void App::run() {
    while (true) {
        switch (app_state.get_curr_state()) {
            case State::StateID::MAIN: {
                int choice = UI::show_main_menu(*this);
                switch (choice) {
                    case 0: app_state.update_state(State::StateID::INFO); break;
                    case 1: app_state.update_state(State::StateID::ALGORITHM); break;
                    case 2: app_state.update_state(State::StateID::DATASET); break;
                    case 3: app_state.update_state(State::StateID::RESULTS); break;
                    case 4: app_state.update_state(State::StateID::DATA_CONSTRUCT); break;
                    case 5: app_state.update_state(State::StateID::FINISHED); break;
                }
                break;
            }

            case State::StateID::INFO: {
                int choice = UI::show_info_menu();
                if (choice == 0) app_state.update_state(State::StateID::MAIN);
                break;
            }

            case State::StateID::ALGORITHM: {
                int choice = UI::show_algorithm_menu();
                if (choice == 0) {
                    app_state.update_state(State::StateID::MAIN);
                } else {
                    set_algorithm(static_cast<Algorithm>(choice));
                    app_state.update_state(State::StateID::MAIN);
                }
                break;
            }

            case State::StateID::DATASET: {
                int choice = UI::show_dataset_menu();
                if (choice == 0) {
                    app_state.update_state(State::StateID::MAIN);
                } else {
                    set_dataset(static_cast<Dataset>(choice));
                    read_dataset();
                    app_state.update_state(State::StateID::MAIN);
                }
                break;
            }

            case State::StateID::RESULTS: {
                ReturnResult result;

                if (chosen_algorithm == Algorithm::BRUTE_FORCE) {
                    result = run_brute_force();
                }

                else if (chosen_algorithm == Algorithm::BRUTE_FORCE_BACKTRACKING) {
                    result = run_brute_force_backtracking();
                }

                else if (chosen_algorithm == Algorithm::DYNAMIC) {

                    result = run_dp();
                }

                else if (chosen_algorithm == Algorithm::GREEDY) {

                    result = run_greedy();
                }

                int choice = UI::show_results_menu(result, total_duration);
                if (choice == 0) {
                    app_state.update_state(State::StateID::MAIN);
                }

                break;
            }

            case State::StateID::DATA_CONSTRUCT: {
                generate_performance_csv(*this);

                int choice = UI::show_performance_data();

                if (choice == 0) {
                    app_state.update_state(State::StateID::MAIN);
                }
                break;
            }

            case State::StateID::FINISHED:
                return; // Encerra o programa
        }
    }
}
