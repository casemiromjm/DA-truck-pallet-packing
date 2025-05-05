#include "menu.h"
#include "state.h"
#include "ui_flow.h"

int main() {

    State app_state;

    int chosen_dataset;
    int chosen_algorithm;
    // main app loop
    while (true) {
        int choice = UI::show_main_menu(app_state);
        switch (choice) {
            // implemented functionalities
            case 0:
                UI::show_info_menu(app_state);
            break;

            // select data set
            case 1:
                chosen_dataset = UI::show_dataset_menu(app_state);
            break;

            // select algorithm
            case 2:
                chosen_algorithm = UI::show_algorithm_menu(app_state);
            break;

            // finish program opt
            case 3:
            return 0;
        }
    }
}
