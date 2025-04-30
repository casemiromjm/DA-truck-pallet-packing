#include "menu.h"

using namespace std;

Menu::Menu(const std::vector<std::string> &options) {
    this->options = options;
}

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
void Menu::refresh_screen() {
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

void Menu::previous_option() {
    current_option--;

    if (current_option > options.size() - 1) {
        current_option = 0;
    }
}

void Menu::next_option() {
    current_option++;

    if (current_option < 0) {
        current_option = options.size() - 1;
    }
}

bool Menu::is_selected(int i) {
    if (current_option == i) {
        return true;
    }

    return false;
}



