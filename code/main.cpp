#include <iostream>
#include "menu.h"

int main() {
    int x = 10;

    Menu main_menu({
        "0. What we have done",
        "1. Select a data set"
    });

    main_menu.print_menu_header();

    main_menu.print_options();
    //main_menu.refresh_screen();

    while (x > 0) {
        char option;

        switch (option) {
            case KEY_UP :
                break;

            case KEY_DOWN :
                break;

            case KEY_ENTER :
                break;
        }
    }

    return 0;
}