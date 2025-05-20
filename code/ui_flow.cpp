#include "ui_flow.h"
#include "app.h"
#include "menu.h"

// technically it is part of the class App, but for simplification’s sake, it is on another file

static const std::string HEADER =  "========================================\n"
                                   "  Truck Delivery Packing Optimization   \n"
                                   "developed by Casemiro, Rafael and Sebastiao\n"
                                   "========================================\n";

int UI::show_main_menu(const App& app) {

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

int UI::show_info_menu() {

    Menu functionalities(
        {"0. Go back to Main Menu"
        },
        "- Good interactive menu\n- Brute force approach\n- Dynamic programming approach\n"
    );

    return functionalities.run();
}

int UI::show_dataset_menu() {

    Menu dataset(
        {
            "0. Go back to Main Menu",
            "1. Example Dataset 1",
            "2. Example Dataset 2",
            "3. Example Dataset 3",
            "4. Example Dataset 4",
            "5. Example Dataset 5",
            "6. Example Dataset 6",
            "7. Example Dataset 7",
            "8. Example Dataset 8",
            "9. Example Dataset 9",
            "10. Example Dataset 10",
        }
    );

    return dataset.run();
}

int UI::show_algorithm_menu() {

    Menu algorithms (
        {
        "0. Go back to Main Menu",
        "1. Brute-Force Approach",
        "2. Dynamic Programming Approach",
        "3. Greedy Approach",
        "4. Integer Linear Programming Approach",
        }
    );

    return algorithms.run();
}

int UI::show_results_menu(std::vector<Pallet> result, const std::chrono::microseconds &total_duration) {

    std::string content;
    std::string final_duration = "Time elapsed: " + std::to_string(total_duration.count());

    for (int i = 0; i < result.size(); i++) {
        content += std::to_string(result[i].get_id()) + ", "  + std::to_string(result[i].get_weight()) + ", " + std::to_string(result[i].get_value()) + '\n';
    }

    content += '\n' + final_duration + " µs";

    Menu results(
        {
        "0. Go back to Main Menu"
        }, content
    );

    return results.run();
}

