#include <iostream>
#include "include/LinkedList.h"
#include "include/Playlist.h"

int main()
{

  Playlist *list = new Playlist();

  list->add(new Music("Control", "Frusciante"));
  list->add(new Music("Dark necessities", "RHCP"));
  list->add(new Music("Muito romântico", "Roberto Carlos"));

  Playlist *toAdd = new Playlist();

  toAdd->add(new Music("Life of pablo", "KW"));
  toAdd->add(new Music("Brazil", "Mcleena"));


  list->add(toAdd);
  list->print();


  return 0;
}