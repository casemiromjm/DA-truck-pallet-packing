#ifndef MENU_H_
#define MENU_H

#include <string>
#include <vector>
#include <iostream>

#ifdef _WIN32       // assim o sebastiao consegue rodar tb
    #include <conio.h>
    #define WIN_KEY_UP 72
    #define WIN_KEY_DOWN 80
    #define WINDOWS_SPECIAL_KEY_2 224
    #define WINDOWS_SPECIAL_KEY_1 0
#else
    #include <termios.h>
    #include <unistd.h>
    #define KEY_UP 'A'
    #define KEY_DOWN 'B'
#endif


#define ESC 27
#define KEY_ENTER 13

class Menu {
public:
    Menu(const std::vector<std::string>& options);
    Menu(const std::vector<std::string>& options, const std::string content);  // tlvz add um param de content
    ~Menu();
    void print_options();
    void print_content() const;
    void refresh_screen();
    int run();
    void previous_option();
    void next_option();
    void print();
private:
    std::string content;
    std::vector<std::string> options;
    int current_option;

    bool is_selected(const int& i);
    void print_selected();
    int getch();    // Low-level implementation for input handling
    int get_key();     // High-level wrapper of getch()
};

#endif
