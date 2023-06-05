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