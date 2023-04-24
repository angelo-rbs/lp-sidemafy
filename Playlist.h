#include <iostream>
#include <ostream>
#include "LinkedList.h"
#include "Musica.h"

class Playlist {

  private:
    std::string nome;
    LinkedList<Musica> *musicas;
    void printWrapped(Node<Musica> *node, int pos);

  public:
    Playlist();
    Playlist(std::string nome);
    Playlist(std::string nome, LinkedList<Musica> *lista);
    Playlist(std::string nome, LinkedList<Musica> lista);
    void print();

    std::string getNome();
    void setNome(std::string nome);

    LinkedList<Musica>* getMusicas();

    Node<Musica>* adicionarMusica(Musica* musica);
    bool removerMusica(std::string nomeMusica, std::string nomeArtista);
};

std::ostream& operator<<(std::ostream &out, Playlist &pl);