#include "GerenciadorMusica.h"
#include <iostream>

GerenciadorMusica::GerenciadorMusica() {
    this->cabeca = nullptr;
}

GerenciadorMusica::~GerenciadorMusica() {
    Musica* atual = this->cabeca;
    while (atual != nullptr) {
        Musica* prox = atual->prox;
        delete atual->playlists;
        delete atual;
        atual = prox;
    }
}

void GerenciadorMusica::adicionarMusica(const std::string& nome) {
    Musica* musica = buscarMusica(nome);

    if (musica != nullptr) {
        std::cout << "A música \"" << nome << "\" já foi cadastrada." << std::endl;
        return;
    }

    Musica* novaMusica = new Musica;
    novaMusica->nome = nome;
    novaMusica->playlists = new LinkedList<std::string>;

    novaMusica->prox = this->cabeca;
    this->cabeca = novaMusica;

    std::cout << "A música \"" << nome << "\" foi cadastrada com sucesso." << std::endl;
}

void GerenciadorMusica::removerMusica(const std::string& nome) {
    Musica* musica = buscarMusica(nome);

    if (musica == nullptr) {
        std::cout << "A música \"" << nome << "\" não foi encontrada." << std::endl;
        return;
    }

    removerMusicaDePlaylists(nome);

    if (musica == this->cabeca) {
        this->cabeca = musica->prox;
    } else {
        Musica* atual = this->cabeca;
        while (atual->prox != musica) {
            atual = atual->prox;
        }
        atual->prox = musica->prox;
    }

    delete musica->playlists;
    delete musica;

    std::cout << "A música \"" << nome << "\" foi removida com sucesso." << std::endl;
}

void GerenciadorMusica::listarMusicas() {
    Musica* atual = this->cabeca;
    if (atual == nullptr) {
        std::cout << "Não há músicas cadastradas." << std::endl;
    } else {
        std::cout << "Lista de músicas cadastradas:" << std::endl;
        while (atual != nullptr) {
            std::cout << "- " << atual->nome << std::endl;
            atual = atual->prox;
        }
    }
}

GerenciadorMusica::Musica* GerenciadorMusica::buscarMusica(const std::string& nome) {
    Musica* atual = this->cabeca;
    while (atual != nullptr) {
        if (atual->nome == nome) {
            return atual;
        }
        atual = atual->prox;
    }
    return nullptr;
}

void GerenciadorMusica::removerMusicaDePlaylists(const std::string& nome) {
    Musica* atual = this->cabeca;
    while (atual != nullptr) {
        LinkedList<std::string>* playlists = atual->playlists;
        if (playlists->contains(nome)) {
            playlists->remove(nome);
        }
        atual = atual->prox;
    }
}
