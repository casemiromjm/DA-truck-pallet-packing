#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

#include "state.h"
#include "truck.h"

class App {
public:

    enum class Algorithm {
        NONE,
        BRUTE_FORCE,
        DYNAMIC,
        GREEDY,
        ILP
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
        DATASET10
    };

    App();
    State::StateID get_app_state() const;

    Algorithm get_algorithm() const;
    std::string get_algorithm_name() const;
    void set_algorithm(Algorithm alg);

    Dataset get_dataset() const;
    std::string get_dataset_name() const;
    void set_dataset(Dataset data);

    void read_dataset();

    void run();

private:
    State app_state;
    std::vector<std::string> algorithm_names = {
        "None",
        "Brute-Force",
        "Dynamic Programming",
        "Greedy",
        "ILP"
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
    };

    Algorithm chosen_algorithm = Algorithm::NONE;
    Dataset chosen_dataset = Dataset::NONE;

    Truck truck;

    std::string convert_num_str(int num);  // auxiliary function

    std::vector<Pallet> run_brute_force() const; //novo
};

#endif
