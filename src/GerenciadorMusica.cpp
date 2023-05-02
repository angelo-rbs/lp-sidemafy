#include <iostream>
#include <exception>
#include "LinkedList.h"
#include "Node.h"

template <typename T>
class GerenciadorMusica
{
private:
    LinkedList<T> *listaMusica;
    LinkedList<T> **playlists;
    int numPlaylists;
    int maxNumPlaylists;

public:
    GerenciadorMusica() {
        listaMusica = new LinkedList<T>();
        maxNumPlaylists = 10;
        numPlaylists = 0;
        playlists = new LinkedList<T>*[maxNumPlaylists];
    }

    ~GerenciadorMusica() {
        delete listaMusica;
        for (int i = 0; i < numPlaylists; i++) {
            delete playlists[i];
        }
        delete[] playlists;
    }

    void adicionarMusica(T valor) {
        listaMusica->anexar(valor);
    }

    void removerMusica(int posicao) {
        listaMusica->deletar(posicao);
    }

    void moverMusica(int posicaoOrigem, int posicaoDestino) {
        T musica = listaMusica->obter(posicaoOrigem);
        listaMusica->deletar(posicaoOrigem);
        listaMusica->inserir(posicaoDestino, musica);
    }

    void adicionarMusicaPlaylist(int playlist, T valor) {
        if (playlist >= numPlaylists) {
            std::cout << "Playlist inválida." << std::endl;
            return;
        }
        playlists[playlist]->anexar(valor);
    }

    void removerMusicaPlaylist(int playlist, int posicao) {
        if (playlist >= numPlaylists) {
            std::cout << "Playlist inválida." << std::endl;
            return;
        }
        playlists[playlist]->deletar(posicao);
    }

    void moverMusicaPlaylist(int playlist, int posicaoOrigem, int posicaoDestino) {
        if (playlist >= numPlaylists) {
            std::cout << "Playlist inválida." << std::endl;
            return;
        }
        T musica = playlists[playlist]->obter(posicaoOrigem);
        playlists[playlist]->deletar(posicaoOrigem);
        playlists[playlist]->inserir(posicaoDestino, musica);
    }

    void imprimirListaMusica() {
        std::cout << "Lista de Músicas:" << std::endl;
        listaMusica->printar();
    }

};
