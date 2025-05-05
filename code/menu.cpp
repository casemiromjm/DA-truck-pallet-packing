#include "menu.h"

using namespace std;

Menu::Menu(const std::vector<std::string> &options) {
    this->options = options;
    current_option = 0;
}

Menu::Menu(const std::vector<std::string> &options, const std::string content) {
    this->options = options;
    this->content = content;
    current_option = 0;
}

Menu::~Menu() = default;

/**
 * Prints the Menu header to the screen
 */
void Menu::print_content() const {
    cout << content << endl;
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
    for (int i = 0; i < options.size(); i++) {
        if (is_selected(i)) {
            print_selected();
        }
        cout << options[i] << endl;
    }
}

void Menu::previous_option() {
    current_option--;

    if (current_option < 0) {
        current_option = options.size() - 1;
    }
}

void Menu::next_option() {
    current_option++;

    if (current_option > options.size() - 1) {
        current_option = 0;
    }
}

bool Menu::is_selected(const int& i) {
    if (current_option == i) {
        return true;
    }

    return false;
}

void Menu::print_selected() {
    cout << "--> ";
}

int Menu::getch() {
#ifdef _WIN32
    return _getch();
#else

    struct termios old_settings, new_settings;
    int ch;

    tcgetattr(STDIN_FILENO, &old_settings);

    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return ch;
#endif
}

int Menu::get_key() {
    int ch = getch();

#ifdef _WIN32
    if (ch == WINDOWS_SPECIAL_KEY_1 !! ch == WINDOWS_SPECIAL_KEY_2) {
        ch = getch();
    }

    // convert from windows to unix
    switch (ch) {
        case WIN_KEY_UP: return 'A';
        case WIN_KEY_DOWN: return 'B';
    }
#else
    if (ch == ESC && getch() == '[') {
        return getch();
    }
#endif

    return ch;
}

void Menu::print() {
    //TODO

    // if i am on the main menu, needs to print the header. otherwise it is unnecessary

    refresh_screen();
    print_options();
}

int Menu::run() {
    while(true) {
        print();
        int key = get_key();

        switch (key) {
            case KEY_UP: previous_option(); break;
            case KEY_DOWN: next_option(); break;
            case KEY_ENTER: return current_option;
        }
    }
}
