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
  "Criar playlist",
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

int removeSongDialog() {
  std::cout << "Qual música deseja remover?" << std::endl;

  int menuSongPosition, listSongPosition;

  std::cin >> menuSongPosition;
  listSongPosition = menuSongPosition - 1;
 

  return listSongPosition;
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

Playlist* createPlaylistDialog() {
  std::string playlistTitle;

  std::cout << "Qual o nome da nova playlist?" << std::endl;
  getline(std::cin >> std::ws, playlistTitle);

  return new Playlist(playlistTitle);
}

int pickSong() {
  int listSongPos, menuSongPos;

  std::cout << "Escolha a música desejada" << std::endl;
  std::cin >> menuSongPos;

  listSongPos = menuSongPos - 1;

  return listSongPos;
}

int pickPlaylist() {
  int listPlaylistPos, menuPlaylistPos;

  std::cout << "Escolha a playlist desejada" << std::endl;
  std::cin >> menuPlaylistPos;

  listPlaylistPos = menuPlaylistPos - 1;

  return listPlaylistPos;
}


int removePlaylistDialog() {
  int pos;

  std::cout << "Qual o número da playlist a ser removida?" << std::endl;
  std::cin >> pos;
 
  return pos;
} 

#endif