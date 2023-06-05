#ifndef SIDEMAFY_H
#define SIDEMAFY_H
#define GET_ANSWEAR true

#include "PlaylistsManager.h"
#include "SongsManager.h"
#include "Menus.h"
#include "Constants.h"

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

  Sidemafy(SongsManager& sm, PlaylistsManager& pm) {
    this->sm = new SongsManager(sm);
    this->pm = new PlaylistsManager(pm);
  }

  Sidemafy(SongsManager& sm) {
    this->sm = new SongsManager(sm);
    this->pm = new PlaylistsManager();
  }

  Sidemafy(PlaylistsManager& pm) {
    this->sm = new SongsManager();
    this->pm = new PlaylistsManager(pm);
  }

  Sidemafy(LinkedList<Music>& songs, LinkedList<Playlist>& pls) {
    this->sm = new SongsManager(songs);
    this->pm = new PlaylistsManager(pls);
  }

  Sidemafy(LinkedList<Music>& songs) {
    this->sm = new SongsManager(songs);
    this->pm = new PlaylistsManager();
  }

  Sidemafy(LinkedList<Playlist>& pls) {
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

  // menus

  void start() {
    int answear = 0;
    Music song;
    Playlist pl;

    while (answear != -1) {

      system("clear");
      answear = printGenericMenu(pickAMenu, GET_ANSWEAR);
      int menuSongPosition = -1;
      int listSongPosition = -1;
      int songPos = -1;
      int playlistPos = -1;
      char trash;

      if (answear == MENU_MUSICA) {
        answear = printGenericMenu(menuMusica, GET_ANSWEAR);

        switch (answear) {


        case 1:
          listSongs();
          std::cout << "pressione [Enter] para continuar" << std::endl;

          std::cin.get(trash);

          break;

        case 2:
          addSong(addSongDialog());
          break;

        case 3:
          listSongs();

          if (removeSong(removeSongDialog()))
            std::cout << "Música removida com sucesso!" << std::endl;
          else
            std::cout << "Erro ao tentar remover música. Tente novamente." << std::endl;

          break;

        case 4:
          listSongs();
          std::cout << "De qual música deseja editar as informações?" << std::endl;

          std::cin >> menuSongPosition;

          if (menuSongPosition < 1 || menuSongPosition > sm->getSize()) {
            std::cout << "Posição inválida. Tente novamente." << std::endl;
            break;
          }

          listSongPosition = menuSongPosition - 1;

          Music music = sm->getByPosition(listSongPosition);

          std::cout << "Título: " << music.getTitle() << std::endl;
          std::cout << "Artista: " << music.getArtistName() << std::endl << std::endl;

          sm->update(updateSongDialog(), listSongPosition);
          break;

          // default:
          //   std::cout << "caiu no default" << std::endl;
          //   break;

        }

      }
      else if (answear == MENU_PLAYLIST) {
        answear = printGenericMenu(menuPlaylist, GET_ANSWEAR);

        switch (answear) {
        case 1:
          listPlaylists();
          std::cout << "pressione [Enter] para continuar" << std::endl;

          std::cin.get(trash);
          break;

        case 2:
          pm->create(*createPlaylistDialog());
          break;

        case 3:
          if (pm->remove(removePlaylistDialog()))
            std::cout << "Playlist removida com sucesso." << std::endl;
          else
            std::cout << "Erro ao tentar remover playlist>" << std::endl;

          break;

        case 4:
          listSongs();
          songPos = pickSong();

          if (songPos < 1 || songPos > sm->getSize()) {
            std::cout << "Posição de música inválida" << std::endl;
            break;
          }
          song = sm->getByPosition(songPos);
          system("clear");

          listPlaylists();
          playlistPos = pickPlaylist();
          system("clear");

          pm->addSongToPlaylist(song, playlistPos);
          break;

        case 5:
          listPlaylists();
          playlistPos = pickPlaylist();

          pl = pm->findByPosition(playlistPos);
          system("clear");

          pl.print();
          songPos = pickSong();

          if (songPos < 1 || songPos > pl.getMusics()->getSize()) {
            std::cout << "Posição de músca inválida" << std::endl;
            break;
          }

          pl.remove(pl.find(songPos));

          break;

        default:
          break;
        }
      }
      else break;
    }
  }

  int printGenericMenu(const std::vector<std::string> options, bool shouldGetAnswear) {
    int pos = 0;
    int answear = -1;
    int size = options.size();

    std::cout << "============================================================" << std::endl;

    while (pos < size) {
      std::cout << (pos + 1) << " - " << options[pos] << std::endl;
      ++pos;
    }

    std::cout << "============================================================" << std::endl << std::endl;

    if (shouldGetAnswear)
      std::cin >> answear;

    system("clear");
    return (answear < 1 || answear > size) ? -1 : answear;
  }

  // funcionalidades

  void listSongs() {
    sm->print();
  }

  void addSong(Music* song) {
    sm->add(song);
  }

  bool removeSong(Music* song) {

    if (sm->remove(song)) {
      pm->purge(song);
      return true;
    }

    return false;
  }

  bool removeSong(int pos) {
    return sm->remove(pos);
  }

  bool updateSong(Music* song) {
    int pos = sm->getSongs()->find(song);
    return sm->update(song, pos);
  }

  void listPlaylists() {
    pm->print();
  }

  void createPlaylist() {



  }

};


#endif