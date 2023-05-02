#include "GerenciadorPlaylist.h"

GerenciadorPlaylist::GerenciadorPlaylist() {
  this->playlists = new LinkedList<Playlist>();
}

GerenciadorPlaylist::~GerenciadorPlaylist() {
  delete this->playlists;
}

Node<Playlist> *GerenciadorPlaylist::adicionarPlaylist(Playlist *playlist) {
  return this->playlists->anexar(playlist);
}

bool GerenciadorPlaylist::removerPlaylist(std::string nome) {
  int posicao = playlists->encontrar(Playlist(nome, nullptr));
  if (posicao == -1) {
    return false;
  } else {
    playlists->deletar(posicao);
    return true;
  }
}

Node<Playlist> *GerenciadorPlaylist::encontrarPlaylist(std::string nomePlaylist) {
  int tamanho = this->playlists->getTamanho();
  for (int i = 0; i < tamanho; i++) {
    Playlist *playlist = this->playlists->acessar(i)->getValue();
    if (playlist->getNome() == nomePlaylist) return this->playlists->acessar(i);
  }
  return nullptr;
}

bool GerenciadorPlaylist::adicionarMusica(std::string nomePlaylist, Musica *musica) {
  Node<Playlist> *playlist = this->encontrarPlaylist(nomePlaylist);
  if (playlist == nullptr) return false;
  playlist->getValue()->adicionarMusica(musica);
  return true;
}

bool GerenciadorPlaylist::removerMusica(std::string nomePlaylist, std::string titulo, std::string nomeArtista) {
  Node<Playlist> *playlist = this->encontrarPlaylist(nomePlaylist);
  if (playlist == nullptr) return false;
  return playlist->getValue()->removerMusica(titulo, nomeArtista);
}

void GerenciadorPlaylist::imprimirPlaylist(std::string nomePlaylist) {
  Node<Playlist> *playlist = this->encontrarPlaylist(nomePlaylist);
  if (playlist == nullptr) {
    std::cout << "Playlist não encontrada." << std::endl;
  } else {
    std::cout << *(playlist->getValue()) << std::endl;
  }
}

void GerenciadorPlaylist::imprimirTodasPlaylists() {
  int tamanho = this->playlists->getTamanho();
  for (int i = 0; i < tamanho; i++) {
    Node<Playlist> *playlist = this->playlists->acessar(i);
    std::cout << *(playlist->getValue()) << std::endl;
  }
}
