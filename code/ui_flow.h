#ifndef UI_FLOW_H
#define UI_FLOW_H

#include "app.h"
#include "state.h"

namespace UI {
    int show_main_menu(const App& app);
    int show_info_menu();
    int show_dataset_menu();
    int show_algorithm_menu();
    int show_results_menu(std::vector<Pallet> result, const std::chrono::microseconds &total_duration);
}

#endif
