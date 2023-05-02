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

void Playlist::print() {

  Node<Musica> *head = this->getMusicas()->getCabeca();

  std::cout << "========================================" << std::endl;
  std::cout << ((this->getNome() == "") ? "[Playlist sem nome]" : this->getNome()) << std::endl;
  std::cout << "========================================" << std::endl;

  if (head != nullptr) printWrapped(head, 1);
  else std::cout << "[Playlist vazia]" << std::endl;

  std::cout << "========================================" << std::endl;

  delete head;
}

void Playlist::printWrapped(Node<Musica> *node, int pos) {

  Musica *musica = node->getValue(); 

   std::cout << pos << " - " << musica->getTitulo() << ", " << musica->getNomeArtista() << std::endl;
   if (node->getNext() != nullptr) printWrapped(node->getNext(), pos + 1);

   delete musica;
}

std::ostream& operator<<(std::ostream &out, Playlist &pl) {

  int size = pl.getMusicas()->getTamanho();
  Musica *musica;

  out << "========================================" << std::endl;

  if (pl.getNome() == "") out << "[Playlist sem nome]" << std::endl;
  else out << pl.getNome() << std::endl;

  out << "========================================" << std::endl;

  for (int i = 0; i < size; i++) {
    musica = pl.getMusicas()->acessar(i)->getValue();
    out << (i + 1) << " - " << (*musica).getNomeArtista() << ", " << (*musica).getTitulo() << std::endl;
  }

  out << "========================================" << std::endl;

  delete musica;
  return out;
}

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
