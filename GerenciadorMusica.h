#ifndef GERENCIADOR_MUSICA_H
#define GERENCIADOR_MUSICA_H

#include <string>
#include "LinkedList.h"

class GerenciadorMusica {
public:
    GerenciadorMusica();
    ~GerenciadorMusica();

    void adicionarMusica(const std::string& nome);
    void removerMusica(const std::string& nome);
    void listarMusicas();

private:
    struct Musica {
        std::string nome;
        LinkedList<std::string>* playlists;
        Musica* prox;
    };

    Musica* cabeca;

    Musica* buscarMusica(const std::string& nome);
    void removerMusicaDePlaylists(const std::string& nome);
};

#endif
