#include <iostream>

#ifdef _WIN32       // assim o sebastiao consegue rodar tb
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include "menu.h"

int getch() {
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

int main() {

    Menu main_menu({
        "0. What we have done",
        "1. Select a data set",
        "2. Select an algorithm",
        "3. Finish program"
    });

    while (true) {
        main_menu.print_menu_header();
        main_menu.print_options();

        int ch = getch();

        // Handle arrow keys (Windows returns 224 first, Linux/Unix uses ANSI escape (^[[A, ^[[B) )
        if (ch == WINDOWS_SPECIAL_KEY || ch == ESC) {
            // POSIX variant
            if (ch == ESC) { // Possible ANSI escape sequence
                ch = getch();
                if (ch == '[') {
                    ch = getch();
                }
            }
            // windows variant
            else {
                ch = getch();
            }

            switch (ch) {
                case 'A':
                case KEY_UP:
                    main_menu.previous_option();
                    break;
                case 'B':
                case KEY_DOWN:
                    main_menu.next_option();
                    break;
            }
        }

        main_menu.refresh_screen();
    }

    return 0;
}