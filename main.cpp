#include <iostream>
#include "include/LinkedList.h"
#include "include/Playlist.h"
#include "include/SongsManager.h"

int main()
{

  Playlist *listA = new Playlist("Playlist A");

  Music *m1 = new Music("Control", "Frusciante");
  Music *m2 = new Music("Dark necessities", "RHCP");
  Music *m3 = new Music("Muito romântico", "Roberto Carlos");

  listA->add(m1);
  listA->add(m2);
  listA->add(m3);

  SongsManager *sm = new SongsManager(*listA);
  sm->remove(m1);

  sm->print();

  return 0;
}