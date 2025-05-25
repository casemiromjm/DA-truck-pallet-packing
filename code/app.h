#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include <chrono>

#include "menu/state.h"
#include "data_structures/truck.h"

//store the data to the output
struct ReturnResult {
    std::vector<Pallet> pallets;
    double total_weight = 0.0;
    double total_value = 0.0;
};

class App {
public:
    enum class Algorithm {
        NONE,
        BRUTE_FORCE,
        BRUTE_FORCE_BACKTRACKING,
        DYNAMIC,
        GREEDY,
    };

    enum class Dataset {
        NONE,
        DATASET1,
        DATASET2,
        DATASET3,
        DATASET4,
        DATASET5,
        DATASET6,
        DATASET7,
        DATASET8,
        DATASET9,
        DATASET10,
        CUSTOM_DATASET
    };

    App();
    State::StateID get_app_state() const;

    Algorithm get_algorithm() const;
    std::string get_algorithm_name() const;
    void set_algorithm(Algorithm alg);

    Dataset get_dataset() const;
    std::string get_dataset_name() const;
    void set_dataset(Dataset data);

    Truck get_truck() const;

    void read_dataset();

    void run();

    static std::string convert_num_str(int num);  // auxiliary function

private:
    State app_state;
    std::vector<std::string> algorithm_names = {
        "None",
        "Brute-Force",
        "Brute-Force Backtracking",
        "Dynamic Programming",
        "Greedy",
    };

    std::vector<std::string> dataset_names = {
        "None",
        "Example 1",
        "Example 2",
        "Example 3",
        "Example 4",
        "Example 5",
        "Example 6",
        "Example 7",
        "Example 8",
        "Example 9",
        "Example 10",
        "Custom"
    };

    Algorithm chosen_algorithm = Algorithm::NONE;
    Dataset chosen_dataset = Dataset::NONE;

    Truck truck;

    std::chrono::microseconds total_duration{0};

    ReturnResult run_brute_force();
    ReturnResult run_dp();
    ReturnResult run_greedy();
    ReturnResult run_brute_force_backtracking();
};

#endif
