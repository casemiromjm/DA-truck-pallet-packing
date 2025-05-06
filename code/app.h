#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

#include "state.h"

class App {
public:

    enum class Algorithm {
        BRUTE_FORCE = 0,
        DYNAMIC,
        GREEDY,
        ILP,
        NONE = -1
    };

    enum class Dataset {
        DATASET1,
        DATASET2,
        DATASET3,
        DATASET4,
        NONE
    };

    App();
    State::StateID get_app_state() const;

    Algorithm get_algorithm() const;
    std::string get_algorithm_name() const;
    void set_algorithm(Algorithm alg);

    Dataset get_dataset() const;
    std::string get_dataset_name() const;
    void set_dataset(Dataset data);

    void run();

private:
    State app_state;
    std::vector<std::string> algorithm_names = {
        "Brute-Force",
        "Dynamic Programming",
        "Greedy",
        "ILP",
        "None"
    };

    std::vector<std::string> dataset_names = {
        "Example 1",
        "Example 2",
        "Example 3",
        "Example 4",
        "None"
    };

    Algorithm chosen_algorithm = Algorithm::NONE;
    Dataset chosen_dataset = Dataset::NONE;
};

#endif
