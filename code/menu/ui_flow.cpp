#include "ui_flow.h"
#include "../app.h"
#include "menu.h"

// technically it is part of the class App, but for simplification’s sake, it is on another file

// Reusable header
static const std::string HEADER =  "========================================\n"
                                   "  Truck Delivery Packing Optimization   \n"
                                   "developed by Casemiro, Rafael and Sebastiao\n"
                                   "========================================\n";

/**
 * Display Main Menu
 * @param app App instance
 * @return Chosen option
 */
int UI::show_main_menu(const App& app) {

    std::string selec = "ALGORITHM: " + app.get_algorithm_name() + '\n' + "DATASET: " + app.get_dataset_name() + '\n';

    Menu main_menu
    (
        {
            "0. What we have done",
            "1. Select an algorithm",
            "2. Select a data set",
            "3. Solve 0/1 Knapsack Problem",
            "4. Generate performance report (CSV)",
            "5. Exit program"
        },
        HEADER,
        selec
    );

    return main_menu.run();
}

/**
 * 
 * @return
 */
int UI::show_info_menu() {

    Menu functionalities(
        {"0. Go back to Main Menu"
        },
        "- Good interactive menu\n"
                  "- Brute Force approach\n"
                  "- Brute-Force Backtracking Approach\n"
                  "- Dynamic Programming approach\n"
                  "- Greedy approach"
    );

    return functionalities.run();
}

/**
 *
 * @return
 */
int UI::show_dataset_menu() {

    std::string cont = "For running Custom Dataset, it has to be inside /data/datasets and be the 11th";

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
            "11. Custom Dataset"
        },
        cont
    );

    return dataset.run();
}

/**
 *
 * @return
 */
int UI::show_algorithm_menu() {

    Menu algorithms (
        {
        "0. Go back to Main Menu",
        "1. Brute-Force Approach",
        "2. Brute-Force Backtracking Approach",
        "3. Dynamic Programming Approach",
        "4. Greedy Approach",
        }
    );

    return algorithms.run();
}

/**
 *
 * @param result
 * @param total_duration
 * @return
 */
int UI::show_results_menu(ReturnResult result, const std::chrono::microseconds &total_duration) {

    std::string content;

    if (result.pallets.size() != 0) {
        content += "Selected Pallet:\n";

        //selected pallets
        for (const auto& pallet : result.pallets) {
            content += std::to_string(pallet.get_id()) + ", " + std::to_string(pallet.get_weight()) + ", " + std::to_string(pallet.get_value()) + '\n';
        }

        content += "\nNumber of pallets: " + std::to_string(result.pallets.size()) + "\n";
        content += "Total weight: " + std::to_string(result.total_weight) + "\n";
        content += "Total value: " + std::to_string(result.total_value) + "\n";
    } else {
        content += "Not able to solve :(";
    }



    content += "\nTime elapsed: " + std::to_string(total_duration.count()) + " \u00B5s";

    Menu results(
        {
        "0. Go back to Main Menu"
        }, content
    );

    return results.run();
}

/**
 *
 * @return
 */
int UI::show_performance_data() {

    std::string content = "Data loaded in the csv";

    Menu performance_data(
        {
        "0. Go back to Main Menu"
        }, content
    );

    return performance_data.run();
}
