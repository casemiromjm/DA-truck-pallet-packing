#include "menu.h"

using namespace std;

Menu::Menu() = default;
Menu::~Menu() = default;

/**
 * Prints the Menu header to the screen
 */
void Menu::print_menu_header() {
    cout << "========================================\n"
            "  Truck Delivery Packing Optimization   \n"
            "developed by Casemiro, Rafael and Sebastiao\n"
            "========================================\n"
    << endl;
}

/**
 * Clears the screen
 */
void Menu::clear_screen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear screen
}

/**
 * Prints Menu options to the screen
 */
void Menu::print_options() {
    for (const auto& opt : options) {
        cout << opt << endl;
    }
}

void Menu::run() {
    //TODO
}


