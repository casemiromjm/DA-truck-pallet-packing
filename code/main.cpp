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

    int choice;
    while ( (choice = main_menu.run(app_state)) != 3) {
        switch (choice) {
            // implemented functionalities
            case 0:
            break;

            // select data set
            case 1:
            break;

            // select algorithm
            case 2:
            break;
        }
    }

    return 0;
}