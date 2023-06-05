#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>

class Music
{

private:
  std::string title;
  std::string artistName;

public:
  Music()
  {
  }

  Music(std::string title, std::string artistName)
  {
    this->title = title;
    this->artistName = artistName;
  }

  std::string getTitle()
  {
    return this->title;
  }

  void setTitle(std::string title)
  {
    this->title = title;
  }

  std::string getArtistName()
  {
    return this->artistName;
  }

  void setArtistName(std::string artistName)
  {
    this->artistName = artistName;
  }

  bool operator==(Music &m1)
  {
    return (m1.getArtistName() == artistName) && (m1.getTitle() == title);
  }

  bool operator!=(Music &m1)
  {
    return !(m1 == *this);
  }

  Music *operator=(Music *m)
  {
    this->artistName = m->getArtistName();
    this->title = m->getTitle();
    return this;
  }
};

#endif