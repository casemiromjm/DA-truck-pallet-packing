#ifndef MENU_H_
#define MENU_H

#include <string>
#include <vector>
#include <iostream>

#define KEY_UP 'H'
#define KEY_DOWN 'K'
#define KEY_ENTER 13

class Menu {
public:
    Menu(const std::vector<std::string>& options);
    ~Menu();
    void print_options();
    void print_menu_header();
    void refresh_screen();
    void run();
    void previous_option();
    void next_option();
    bool is_selected(const int& i);
    void print_selected();
private:
    std::vector<std::string> options;
    int current_option = 0;
};

#endif