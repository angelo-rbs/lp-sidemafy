#include "Menu.h"

int Menu::showMenu() {
    int opcao;
    std::cout << "Selecione uma opcao:" << std::endl;
    std::cout << "1. Gerenciar musicas" << std::endl;
    std::cout << "2. Gerenciar playlists" << std::endl;
    std::cout << "3. Sair" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> opcao;
    return opcao;
}

int Menu::showSubMenu() {
    int opcao;
    std::cout << "Selecione uma opcao:" << std::endl;
    std::cout << "1. Adicionar" << std::endl;
    std::cout << "2. Remover" << std::endl;
    std::cout << "3. Listar" << std::endl;
    std::cout << "4. Voltar" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> opcao;
    return opcao;
}

std::string Menu::getNome() {
    std::string nome;
    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    return nome;
}

std::string Menu::getArtista() {
    std::string artista;
    std::cout << "Artista: ";
    std::getline(std::cin, artista);
    return artista;
}

std::string Menu::getGenero() {
    std::string genero;
    std::cout << "Genero: ";
    std::getline(std::cin, genero);
    return genero;
}

std::string Menu::getNomePlaylist() {
    std::string nomePlaylist;
    std::cout << "Nome da Playlist: ";
    std::cin.ignore();
    std::getline(std::cin, nomePlaylist);
    return nomePlaylist;
}
