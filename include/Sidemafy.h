#ifndef SIDEMAFY_H
#define SIDEMAFY_H

#include "PlaylistsManager.h"
#include "SongsManager.h"

class Sidemafy {

private:
  SongsManager* sm;
  PlaylistsManager* pm;

public:

  // construtores

  Sidemafy() {
    this->sm = new SongsManager();
    this->pm = new PlaylistsManager();
  }

  Sidemafy(SongsManager &sm, PlaylistsManager &pm) {
    this->sm = new SongsManager(sm);
    this->pm = new PlaylistsManager(pm);
  }

  Sidemafy(SongsManager &sm) {
    this->sm = new SongsManager(sm);
    this->pm = new PlaylistsManager();
  }

  Sidemafy(PlaylistsManager &pm) {
    this->sm = new SongsManager();
    this->pm = new PlaylistsManager(pm);
  }

  Sidemafy(LinkedList<Music> &songs, LinkedList<Playlist> &pls) {
    this->sm = new SongsManager(songs);
    this->pm = new PlaylistsManager(pls);
  }

  Sidemafy(LinkedList<Music> &songs) {
    this->sm = new SongsManager(songs);
    this->pm = new PlaylistsManager();
  }

  Sidemafy(LinkedList<Playlist> &pls) {
    this->sm = new SongsManager();
    this->pm = new PlaylistsManager(pls);
  }

  // getters

  SongsManager* getSongsManager() {
    return this->sm;
  }

  PlaylistsManager* getPlaylistsManager() {
    return this->pm;
  }

  // funcionalidades

  void createSong(Music* song) {
    sm->add(song);
  }

  bool removeSong(Music* song) {

    if (sm->remove(song)) {
      pm->purge(song);
      return true;
    }

    return false;
  }

  bool updateSong(Music* song) {
    return sm->update(song);
  }

  void listSongs() {
    sm->print();
  }

  // bool addSongToPlaylist(Music *song, Playlist* pl) {
  //   return (pl->add(song) != nullptr);
  // }

  // bool removeSongOfPlaylist(Music *song, Playlist* pl) {
  //   return pl->remove(song);
  // }

};


#endif