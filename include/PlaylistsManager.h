#ifndef PLAYLISTS_MANAGER_H
#define PLAYLISTS_MANAGER_H

#include "LinkedList.h"
#include "Playlist.h"
#include "Music.h"

class PlaylistsManager {

  private:

    LinkedList<Playlist> *playlists;

  public:

    // construtores

    PlaylistsManager() {
      this->playlists = new LinkedList<Playlist>();
    }

    PlaylistsManager(LinkedList<Playlist> &playlist) {
      this->playlists = new LinkedList(playlist);
    }

    // getter  

    LinkedList<Playlist>* getPlaylists() {
      return playlists;
    }

    // funcionalidades

    void create(Playlist &pl) {
      playlists->append(pl);
    }

    bool remove(Playlist &pl) {
      int pos = playlists->find(pl);

      if (pos != NOT_FOUND) return playlists->remove(pos);
      else return false;
    }

    bool update(Playlist &pl) {
      int pos = playlists->find(pl);

      if (pos != NOT_FOUND) return (playlists->insert(pos, pl) != nullptr);
    }

    void print() {
      int pos = 1;
      Node<Playlist>* node = playlists->getHead();

      std::cout << "================================================================================" << std::endl;
      std::cout << "Lista de playlists cadastradas" << std::endl;
      std::cout << "================================================================================" << std::endl;

      if (node != nullptr) {
        while (node != nullptr) {

          Playlist pl = node->getValue();

          std::cout << pos << " - " << pl.getName() << ", " << pl.getMusics()->getSize() << " músicas" <<std::endl;

          ++pos;
          node = node->getNext();
        }
      } else
        std::cout << "[lista vazia]" << std::endl;

      std::cout << "================================================================================" << std::endl;
    }

    void purge(Music *song) {

      Node<Playlist> *it = playlists->getHead();

      while (it != nullptr) {

        Playlist pl = it->getValue();
        
        if (pl.find(song) != -1)
          pl.remove(song);

        it = it->getNext();
      }

    }
};

#endif