#ifndef SONGS_MANAGER_H
#define SONGS_MANAGER_H

#include "Music.h"
#include "LinkedList.h"
#include "Playlist.h"

class SongsManager {

private:

  LinkedList<Music>* songs;

public:

  // construtores

  SongsManager() {
    songs = new LinkedList<Music>();
  }

  SongsManager(SongsManager& sm) {
    songs = new LinkedList(*sm.songs);
  }

  SongsManager(Playlist& pl) {
    songs = new LinkedList(*(pl.getMusics()));
  }

  SongsManager(LinkedList<Music>& list) {
    songs = new LinkedList(list);
  }

  // getters e setters

  LinkedList<Music>* getSongs() {
    return songs;
  }

  void setSongs(LinkedList<Music>* songs) {
    this->songs = songs;
  }

  size_t getSize() {
    return songs->getSize();
  }

  Music getByPosition(int pos) {
    return songs->access(pos)->getValue();
  }

  // funcionalidades

  
  bool add(Music* music) {
    if (songs->find(music) != NOT_FOUND) return false;

    return songs->append(music) != nullptr;
  }

  int add(LinkedList<Music>* list) {

    Node<Music>* it = list->getHead();
    int amountAdd = 0;

    while (it != nullptr) {
      Music song = it->getValue();

      int found = (songs->find(song) != -1);
      if (!found) {
        int sucessfullyAdd = (songs->append(song) != nullptr);
        amountAdd += sucessfullyAdd;
      }

      it = it->getNext();
    }

    return amountAdd;
  }

  bool remove(Music* music) {

    int pos = songs->find(music);
    if (pos == -1) throw std::invalid_argument("música não encontrada no gerenciador. tente novamente.");


    // a remoção da música das playlists existentes fica a encargo do purge chamado por Sidemafy.h

    return songs->remove(pos);
  }

  bool remove(int pos) {
    if (pos < 0 || pos >= songs->getSize()) return false;

    // a remoção da música das playlists existentes fica a encargo do purge chamado por Sidemafy.h

    return songs->remove(pos);
  }

  bool update(Music* music, int pos) {
    return songs->replace(music, pos);
  }

  void print() {

    int pos = 1;
    Node<Music>* node = songs->getHead();

    std::cout << "================================================================================" << std::endl;
    std::cout << "Lista de músicas cadastradas" << std::endl;
    std::cout << "================================================================================" << std::endl;

    if (node != nullptr) {
      while (node != nullptr) {

        Music music = node->getValue();

        std::cout << pos << " - " << music.getTitle() << ", " << music.getArtistName() << std::endl;

        ++pos;
        node = node->getNext();
      }
    }
    else
      std::cout << "[lista vazia]" << std::endl;

    std::cout << "================================================================================" << std::endl;
  }
};

#endif