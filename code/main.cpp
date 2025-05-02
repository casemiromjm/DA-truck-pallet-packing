#include <iostream>
#include "menu.h"

int main() {
    int x = 10;

    Menu main_menu({
        "0. What we have done",
        "1. Select a data set",
        "2. Select an algorithm",
        "3. Finish program"
    });

    while (x > 0) {

        main_menu.print_menu_header();
        main_menu.print_options();

        char option;
        std::cin >> option;

        switch (option) {
            case KEY_UP :
                main_menu.previous_option();
                break;

            case KEY_DOWN :
                main_menu.next_option();
                break;

            case KEY_ENTER :
                break;

            default:
                break;
        }

        main_menu.refresh_screen();
        x--;
    }

    return 0;
}