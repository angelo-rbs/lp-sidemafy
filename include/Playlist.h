#ifndef PLAYLIST_H
#define PLAYLIST_H
#define NOT_FOUND -1

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

  Playlist(std::string name)
  {
    this->name = name;
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

  Playlist(Playlist &listToCopy)
  {
    this->name = listToCopy.getName();
    this->musics = new LinkedList<Music>(*(listToCopy.getMusics()));
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

  Node<Music> *add(Music *music)
  {
    return (this->musics->append(music));
  }

  Node<Music> *add(Music music)
  {
    return (this->musics->append(music));
  }

  void add(Playlist *list)
  {

    Node<Music> *it = list->getMusics()->getHead();

    while (it != nullptr)
    {

      Music songToBeAdd = it->getValue();
      int searchResult = getMusics()->find(songToBeAdd);

      if (searchResult == NOT_FOUND)
      {
        add(it->getValue());
      }

      it = it->getNext();
    }
  }

  bool remove(std::string title, std::string artistName)
  {

    Music *music = new Music(title, artistName);
    int position = musics->find(music);
    delete music;
    int found = (position != -1);

    if (found)
    {
      this->musics->remove(position);
      return true;
    }

    return false;
  }

  bool remove(Music *music)
  {
    return remove(music->getTitle(), music->getArtistName());
  }

  int remove(Playlist *list)
  {
    return this->getMusics()->remove(list->getMusics());
  }

  int find(Music *song)
  {
    return musics->find(song);
  }

  Playlist *operator+(Playlist &list)
  {

    Playlist *toReturn = new Playlist();

    toReturn->add(this);
    toReturn->add(&list);

    toReturn->setName("União de \"" + this->getName() + "\" e \"" + list.getName() + "\"");

    return toReturn;
  }

  Playlist *operator+(Music &music)
  {

    Playlist *toReturn = new Playlist(*this);
    toReturn->setName("");
    toReturn->add(music);

    return toReturn;
  }

  Playlist *operator-(Playlist &listToRemove)
  {

    Playlist *toReturn = new Playlist(*this);
    toReturn->setName("");

    toReturn->remove(&listToRemove);
    return toReturn;
  }

  Playlist *operator-(Music &music)
  {

    Playlist *toReturn = new Playlist(*this);
    toReturn->remove(music.getTitle(), music.getArtistName());
    toReturn->setName("");

    return toReturn;
  }

  bool operator==(Playlist &pl)
  {

    bool equals = true;
    Node<Music> *it = pl.getMusics()->getHead();

    while (it != nullptr)
    {
      Music song = it->getValue();
      if (musics->find(song) == NOT_FOUND)
        return false;
      it = it->getNext();
    }

    return true;
  }

  bool operator!=(Playlist &pl)
  {
    return !(*this == pl);
  }
};

std::ostream &operator<<(std::ostream &out, Playlist &pl)
{

  int size = pl.getMusics()->getSize();
  Music music;

  out << "========================================" << std::endl;

  if (pl.getName() == "")
    out << "[Playlist sem nome]" << std::endl;
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
  pl.add(music);
}

void operator>>(Playlist &pl, Music &music)
{
  if (pl.getMusics()->getSize() > 0)
  {
    music = pl.getMusics()->access(pl.getMusics()->getSize() - 1)->getValue();
    pl.remove(music.getTitle(), music.getArtistName());
  }
  else
  {
    music.setArtistName("");
    music.setTitle("");
    // &music = nullptr;
  }
}

#endif