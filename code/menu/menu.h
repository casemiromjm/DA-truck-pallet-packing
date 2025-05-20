#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <iostream>

#include "state.h"

#ifdef _WIN32       // assim o sebastiao consegue rodar tb
    #include <conio.h>
    #define WIN_KEY_UP 72
    #define WIN_KEY_DOWN 80
    #define WINDOWS_SPECIAL_KEY_2 224
    #define WINDOWS_SPECIAL_KEY_1 0
    #define WIN_KEY_ENTER 13
#else
    #include <termios.h>
    #include <unistd.h>
    #define KEY_UP 'A'
    #define KEY_DOWN 'B'
    #define KEY_ENTER 10
#endif

#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_ENTER 10
#define ESC 27


class Menu {
public:
    Menu(const std::vector<std::string>& options);
    Menu(const std::vector<std::string>& options, const std::string &content);  // tlvz add um param de content
    Menu(const std::vector<std::string>& options, const std::string &content, const std::string& selection);
    ~Menu();

    void print_options();
    void print_content() const;
    void refresh_screen();
    void print_selection() const;
    void print();

    void previous_option();
    void next_option();

    int run();

private:
    std::string content;    // content to be displayed
    std::string selection;      // selected algorithm and dataset
    std::vector<std::string> options;   // menu options
    int current_option;

    bool is_selected(const int& i);
    void print_selected();
    int getch();    // Low-level implementation for input handling
    int get_key();     // High-level wrapper of getch()
};

#endif
