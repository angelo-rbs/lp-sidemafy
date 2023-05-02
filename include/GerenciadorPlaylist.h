#ifndef GERENCIADORPLAYLIST_H
#define GERENCIADORPLAYLIST_H

#include <iostream>
#include <string>
#include "Playlist.h"
#include "LinkedList.h"

class GerenciadorPlaylist {

private:
  LinkedList<Playlist> *playlists;

public:
  GerenciadorPlaylist();
  ~GerenciadorPlaylist();

  Node<Playlist> *adicionarPlaylist(Playlist *playlist);
  bool removerPlaylist(std::string nomePlaylist);
  Node<Playlist> *encontrarPlaylist(std::string nomePlaylist);
  bool adicionarMusica(std::string nomePlaylist, Musica *musica);
  bool removerMusica(std::string nomePlaylist, std::string titulo, std::string nomeArtista);
  void imprimirPlaylist(std::string nomePlaylist);
  void imprimirTodasPlaylists();
};

#endif
