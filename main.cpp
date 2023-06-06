#include <iostream>
#include <fstream>
#include "include/Sidemafy.h"
#include "include/Constants.h"
#include "include/LinkedList.h"
#include "include/Music.h"

LinkedList<Music>* list = new LinkedList<Music>();


Playlist* load(std::string s, std::string del = " ") {
  int start, end = -1 * del.size();
  std::string playlistTitle;
  std::string songTitle;
  std::string artistName;
  Playlist* pl = new Playlist();


  start = end + del.size();
  end = s.find(del, start);

  playlistTitle = s.substr(start, end - start);
  pl->setName(playlistTitle);

  while (end != -1) {

    del = ":";

    start = end + del.size();
    end = s.find(del, start);

    songTitle = s.substr(start, end - start);


    del = ",";

    start = end + del.size();
    end = s.find(del, start);

    if (end == -1) break;

    artistName = s.substr(start, end - start);

    pl->add(new Music(songTitle, artistName));
  }

  return pl;
}

int main(int argc, char* argv[]) {

  Sidemafy* sidemafy = new Sidemafy();

  // carrega as músicas e playlists do arquivo-banco

  if (argc == PASSOU_ARQUIVO_FONTE) {

    std::fstream fhandler = std::fstream(argv[1], std::ios::in);
    std::string line;

    while (fhandler && getline(fhandler, line)) {
      Playlist* pl = load(line, PLAYLISTNAME_DEL);

      sidemafy->getSongsManager()->add(pl->getMusics());
      sidemafy->getPlaylistsManager()->create(pl);
    }
  }

  sidemafy->start();

  // despacha as músicas e playlists para o arquivo-banco após encerrar



  return 0;
}

