#include <iostream>
#include "include/LinkedList.h"
#include "include/Playlist.h"

int main()
{

  Playlist *list = new Playlist("Playlist teste");

  list->add(new Music("Control", "Frusciante"));
  list->add(new Music("Dark necessities", "RHCP"));
  list->add(new Music("Muito romântico", "Roberto Carlos"));

  Playlist *toAdd = new Playlist();

  toAdd->add(new Music("Life of pablo", "KW"));
  toAdd->add(new Music("Brazil", "Mcleena"));

  Playlist *toRemove = new Playlist();

  toRemove->add(new Music("Life of pablo", "KW"));


  list->add(toAdd);
  list->print();

  std::cout << "\no resultado após remover eh " << std::endl;

  int removidas = list->remove(toRemove);
  list->print();
  std::cout << "e conseguiu remover " << removidas << " músicas" << std::endl;

  return 0;
}