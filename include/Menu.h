/**
 * @file Menu.h
 * @brief Definição da classe Menu e seus métodos.
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

/**
 * @brief Classe que implementa o menu de um aplicativo de música.
 */
class Menu {
public:
    /**
     * @brief Exibe o menu principal do aplicativo.
     * @return Opção selecionada pelo usuário.
     */
    static int showMenu();

    /**
     * @brief Exibe o submenu do aplicativo.
     * @return Opção selecionada pelo usuário.
     */
    static int showSubMenu();

    /**
     * @brief Obtém o nome de uma música.
     * @return Nome da música.
     */
    static std::string getNome();

    /**
     * @brief Obtém o nome do artista de uma música.
     * @return Nome do artista.
     */
    static std::string getArtista();

    /**
     * @brief Obtém o gênero de uma música.
     * @return Gênero da música.
     */
    static std::string getGenero();

    /**
     * @brief Obtém o nome de uma playlist.
     * @return Nome da playlist.
     */
    static std::string getNomePlaylist();
};

#endif