#include <iostream>

#include "menu.h"

int main() {

    Menu main_menu({
        "0. What we have done",
        "1. Select a data set",
        "2. Select an algorithm",
        "3. Finish program"
    });

    // needs to use states to make the header consistent
    main_menu.print_menu_header();

    main_menu.run();

    return 0;
}