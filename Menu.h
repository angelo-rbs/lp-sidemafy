
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "GerenciadorPlaylist.h"

class Menu {
public:
    Menu(GerenciadorPlaylist *gerenciador);
    ~Menu();

    void exibirMenu();

private:
    GerenciadorPlaylist *gerenciador;

    int mostrarOpcoes();
    void executarOpcao(int opcao);
    void listarMusicas();
    void adicionarMusica();
    void removerMusica();
    void procurarMusica();
};

#endif
