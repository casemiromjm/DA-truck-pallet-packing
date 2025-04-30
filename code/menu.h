#ifndef MENU_H_
#define MENU_H

#include <string>
#include <vector>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

class Menu {
public:
    Menu();     // pode ser atualizado p receber um vetor de strings (opcoes) p conseguir criar submenus
    ~Menu();
    void print_options();
    void print_menu_header();
    void clear_screen();
    void run();
private:
    std::vector<std::string> options =
    {
        "0. What we have done",
        "1. Select a data set"
    };
};

#endif