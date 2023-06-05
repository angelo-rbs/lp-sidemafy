#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "LinkedList.h"
#include "Node.h"
#include "Music.h"

class Playlist
{

private:
  LinkedList<Music> *musics;
  std::string name;

public:
  Playlist()
  {
    this->name = "";
    this->musics = new LinkedList<Music>();
  }

  Playlist(std::string name, LinkedList<Music> *lista)
  {
    this->name = name;
    this->musics = lista;
  }

  Playlist(std::string name, LinkedList<Music> list)
  {
    this->name = name;
    this->musics = new LinkedList<Music>();

    for (int i = 0; i < list.getSize(); i++)
    {

      Music it = list.access(i)->getValue();
      musics->append(new Music(it.getTitle(), it.getArtistName()));
    }
  }

  void print()
  {

    Node<Music> *head = this->getMusics()->getHead();

    std::cout << "========================================" << std::endl;
    std::cout << ((this->getName() == "") ? "[Playlist sem name]" : this->getName()) << std::endl;
    std::cout << "========================================" << std::endl;

    if (head != nullptr)
      printWrapped(head, 1);
    else
      std::cout << "[Playlist vazia]" << std::endl;

    std::cout << "========================================" << std::endl;

    delete head;
  }

  void printWrapped(Node<Music> *node, int pos)
  {

    Music Music = node->getValue();

    std::cout << pos << " - " << Music.getTitle() << ", " << Music.getArtistName() << std::endl;
    if (node->getNext() != nullptr)
      printWrapped(node->getNext(), pos + 1);
  }

  /*
  código grosso aqui
  */

  std::string getName()
  {
    return this->name;
  }

  LinkedList<Music> *getMusics()
  {
    return this->musics;
  }

  void setName(std::string name)
  {
    this->name = name;
  }

  Node<Music> *addMusic(Music *Music)
  {
    return (this->musics->append(Music));
  }

  bool removeMusic(std::string title, std::string artistName)
  {

    Music *music = new Music(title, artistName);
    int position = musics->find(music);
    int found = (position != -1);
    bool deleted = false;

    if (found)
      deleted = this->musics->deletePos(position);

    delete music;
    return deleted;
  }
};

std::ostream &operator<<(std::ostream &out, Playlist &pl)
{

  int size = pl.getMusics()->getSize();
  Music music;

  out << "========================================" << std::endl;

  if (pl.getName() == "")
    out << "[Playlist sem name]" << std::endl;
  else
    out << pl.getName() << std::endl;

  out << "========================================" << std::endl;

  for (int i = 0; i < size; i++)
  {
    music = pl.getMusics()->access(i)->getValue();
    out << (i + 1) << " - " << music.getArtistName() << ", " << music.getTitle() << std::endl;
  }

  out << "========================================" << std::endl;

  return out;
}

void operator<<(Playlist &pl, Music &music)
{
  pl.addMusic(&music);
}

void operator>>(Playlist &pl, Music &music)
{
  pl.removeMusic(music.getTitle(), music.getArtistName());
}

#endif