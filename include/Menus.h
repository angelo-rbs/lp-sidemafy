#ifndef MENUS_H
#define MENUS_H


#include <iostream>
#include <vector>
#include "Constants.h"
#include "Music.h"

// itens de menu

static const std::vector<std::string> pickAMenu = {
  "Menu de música",
  "Menu de playlist"
};

static const std::vector<std::string> menuMusica = {
  "Listar músicas",
  "Adicionar uma música",
  "Remover uma música",
  "Atualizar uma música",
};

static const std::vector<std::string> menuPlaylist = {
  "Listar playlists",
  "Adicionar playlist",
  "Apagar playlist",
  "Adicionar música a playlist",
  "Remover música de playlist"
};

// diálogos

Music* addSongDialog() {
  std::string artistName;
  std::string songTitle;

  std::cout << "Qual o nome da música?" << std::endl;
  getline(std::cin >> std::ws, songTitle);


  std::cout << "Qual o nome do artista?" << std::endl;
  getline(std::cin >> std::ws, artistName);

  return new Music(songTitle, artistName);
}

Music* updateSongDialog() {
  std::string artistName;
  std::string songTitle;

  std::cout << "Qual o novo nome da música?" << std::endl;
  getline(std::cin >> std::ws, songTitle);


  std::cout << "Qual o novo nome do artista?" << std::endl;
  getline(std::cin >> std::ws, artistName);

  return new Music(songTitle, artistName);
}

int pickSong() {
  int menuSongPosition, listSongPosition;

  std::cout << "Qual é a música escolhida?" << std::endl;
  std::cin >> menuSongPosition;
  listSongPosition = menuSongPosition - 1;

  return listSongPosition;
}

int pickPlaylist() {
  int menuPlaylistPosition, listPlaylistPosition;

  std::cout << "Qual é a playlist escolhida?" << std::endl;
  std::cin >> menuPlaylistPosition;
  listPlaylistPosition = menuPlaylistPosition - 1;

  return listPlaylistPosition;
}


Playlist* createPlaylistDialog() {
  std::string playlistTitle;

  std::cout << "Qual o nome da playlist?" << std::endl;
  getline(std::cin >> std::ws, playlistTitle);

  Playlist *pl = new Playlist();
  pl->setName(playlistTitle);

  return pl;
}

#endif