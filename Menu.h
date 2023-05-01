#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

class Menu {
public:
    static int showMenu();
    static int showSubMenu();
    static std::string getNome();
    static std::string getArtista();
    static std::string getGenero();
    static std::string getNomePlaylist();
};

#endif
