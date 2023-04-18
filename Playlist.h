#include <iostream>
#include "LinkedList.h"
#include "Musica.h"

class Playlist {

  private:
    std::string nome;
    LinkedList<Musica> musicas;

  public:
    std::string getNome();
    void setNome(std::string nome);

    LinkedList<Musica>* getMusicas();
    Node<Musica>* adicionarMusica(Musica* musica);
};