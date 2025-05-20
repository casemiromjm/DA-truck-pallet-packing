#include "menu.h"

using namespace std;

/**
 * Constructor for Menu class
 * @param options Menu navigation options
 */
Menu::Menu(const std::vector<std::string> &options) {
    this->options = options;
    current_option = 0;
}

/**
 * Constructor for Menu class
 * @param options Menu navigation options
 * @param content Static content displayed in Menu instance
 */
Menu::Menu(const std::vector<std::string> &options, const std::string &content) {
    this->options = options;
    this->content = content;
    current_option = 0;
}

/**
 * Constructor for Menu class
 * @param options Menu navigation options
 * @param content Static content displayed in Menu instance
 * @param selection User selection to be displayed in Menu instance
 */
Menu::Menu(const std::vector<std::string> &options, const std::string &content, const std::string& selection) {
    this->options = options;
    this->content = content;
    this->selection = selection;
    current_option = 0;
}

/**
 * Menu destructor
 */
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

/**
 * Moves back Menu option selection
 */
void Menu::previous_option() {
    current_option--;

    if (current_option < 0) {
        current_option = options.size() - 1;
    }
}

/**
 * Moves forward Menu option selection
 */
void Menu::next_option() {
    current_option++;

    if (current_option > options.size() - 1) {
        current_option = 0;
    }
}

/**
 * Checks if an option is the selected one
 * @param i The checked option
 * @return True if "i" is the current selected option. False otherwise
 */
bool Menu::is_selected(const int& i) {
    if (current_option == i) {
        return true;
    }

    return false;
}

/**
 *
 */
void Menu::print_selected() {
    cout << "--> ";
}

/**
 * Print algorithm and dataset selections
 */
void Menu::print_selection() const {
    cout << selection << endl;
}

/**
 * Reads a single character from the console without echoing it.
 * Provides a platform-independent way to read a single
 * character from the console without echoing it to the screen. On Windows, it
 * uses the _getch() function, while on Unix-like systems it temporarily modifies
 * terminal settings to disable canonical mode and echoing.
 *
 * @return int The ASCII code of the character read.
 *
 * @note On Unix-like systems, this function modifies terminal settings temporarily
 * and restores them after reading the character. This ensures the terminal remains
 * in a usable state after the function call.
 */
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

/**
 * Reads and translates a key press into a standardized code.
 * Reads a key press and translates platform-specific key codes
 * into a standardized format. On Windows, it handles special keys (like arrows and Enter)
 * by converting them to Unix-style escape sequences. On Unix-like systems, it processes
 * escape sequences for special keys. It relies on the low-level getch() implemented before.
 *
 * @return The standardized key code:
 *             - For arrow keys: 'A' (up), 'B' (down) in Unix-style
 *             - For Enter key: 10 (Unix-style)
 *             - For regular keys: their ASCII code
 */
int Menu::get_key() {
    int ch = getch();

    #ifdef _WIN32
        if (ch == WINDOWS_SPECIAL_KEY_1 || ch == WINDOWS_SPECIAL_KEY_2) {
            ch = getch();
        }

        // convert from windows to unix
        switch (ch) {
            case WIN_KEY_UP: return 'A';
            case WIN_KEY_DOWN: return 'B';
            case WIN_KEY_ENTER: return 10;
        }
    #else
        if (ch == ESC && getch() == '[') {
            return getch();
        }
    #endif

    return ch;
}

/**
 * Menu generic print
 */
void Menu::print() {
    refresh_screen();

    if (!content.empty()) {
        print_content();
    }

    if (!selection.empty()) {
        print_selection();
    }

    print_options();
}

/**
 * Menu loop
 * @return Chosen option
 */
int Menu::run() {
    // loop for reading the terminal
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
