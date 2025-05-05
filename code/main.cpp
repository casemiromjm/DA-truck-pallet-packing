#include <iostream>

#include "menu.h"
#include "state.h"

int main() {

    State app_state;

    Menu main_menu({
        "0. What we have done",
        "1. Select a data set",
        "2. Select an algorithm",
        "3. Finish program"
        },
    "========================================\n"
            "  Truck Delivery Packing Optimization   \n"
            "developed by Casemiro, Rafael and Sebastiao\n"
            "========================================\n"
    );

    while (true) {
        // could use == operator
        if (app_state.check_curr_state(State::MAIN)) {
        }
    }

    return 0;
}