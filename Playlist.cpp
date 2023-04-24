#include "Playlist.h"
#include "LinkedList.cpp"
#include "Node.cpp"

Playlist::Playlist() {
  this->nome = "";
  this->musicas = new LinkedList<Musica>();
}

Playlist::Playlist(std::string nome, LinkedList<Musica> *lista) {
  this->nome = nome;
  this->musicas = lista;
}

Playlist::Playlist(std::string nome, LinkedList<Musica> lista) {
  this->nome = nome;
  this->musicas = new LinkedList<Musica>();

  for (int i = 0; i < lista.getTamanho(); i++) {

    Musica *it = lista.acessar(i)->getValue();
    musicas->anexar(new Musica(it->getTitulo(), it->getNomeArtista()));
  }
}

// reimplementar usando recursão

void Playlist::print() {

  int size = musicas->getTamanho();
  Musica *musica;

  std::cout << "========================================" << std::endl;

  if (this->getNome() == "") std::cout << "[Playlist sem nome]" << std::endl;
  else std::cout << this->getNome() << std::endl;

  std::cout << "========================================" << std::endl;

  for (int i = 0; i < size; i++) {
    musica = musicas->acessar(i)->getValue();
    std::cout << (i + 1) << " - " << (*musica).getNomeArtista() << ", " << (*musica).getTitulo() << std::endl;
  }

  std::cout << "========================================" << std::endl;
}

/*
código grosso aqui
*/

std::string Playlist::getNome() {
  return this->nome;
}

LinkedList<Musica> *Playlist::getMusicas() {
  return this->musicas;
}


void Playlist::setNome(std::string nome) {
  this->nome = nome;
}

Node<Musica> *Playlist::adicionarMusica(Musica *musica) {
  return (this->musicas->anexar(musica));
}

bool Playlist::removerMusica(std::string titulo, std::string nomeArtista) {
  
  Musica musica = Musica(titulo, nomeArtista);
  int posicao = musicas->encontrar(musica);
  int encontrou = (posicao != -1);

  if (encontrou) return this->musicas->deletar(posicao);
  else return false;
  
}

