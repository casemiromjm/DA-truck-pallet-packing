#include <iostream>
#include "menu.h"

int main() {
    Menu main_menu({
        "0. What we have done",
        "1. Select a data set"
    });

    main_menu.print_menu_header();

    main_menu.print_options();
    //main_menu.refresh_screen();


    return 0;
}