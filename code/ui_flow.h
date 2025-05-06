#ifndef UI_FLOW_H
#define UI_FLOW_H

#include "app.h"
#include "menu.h"
#include "state.h"

namespace UI {
    int show_main_menu(State& app_state, const App& app);
    int show_info_menu(State& app_state);
    int show_dataset_menu(State& app_state);
    int show_algorithm_menu(State& app_state);
    int show_results_menu(State& app_state);
}

#endif
