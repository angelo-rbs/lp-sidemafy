#include <iostream>
#include "LinkedList.h"
#include "Musica.h"

class Playlist {

  private:
    std::string nome;
    LinkedList<Musica> *musicas;

  public:
    Playlist();
    Playlist(std::string nome);
    Playlist(std::string nome, LinkedList<Musica> *lista);
    Playlist(std::string nome, LinkedList<Musica> lista);
    void print(); // reimplementar usando recursão

    std::string getNome();
    void setNome(std::string nome);

    LinkedList<Musica>* getMusicas();

    Node<Musica>* adicionarMusica(Musica* musica);
    bool removerMusica(std::string nomeMusica, std::string nomeArtista);
};