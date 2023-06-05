#include <iostream>
#include "include/LinkedList.h"
#include "include/Playlist.h"

int main()
{

  Playlist *listA = new Playlist("Playlist A");

  listA->add(new Music("Control", "Frusciante"));
  listA->add(new Music("Dark necessities", "RHCP"));
  listA->add(new Music("Muito romântico", "Roberto Carlos"));

  Playlist *listB = new Playlist("Playlist B");

  listB->add(new Music("Life of pablo", "KW"));
  listB->add(new Music("Brazil", "Mcleena"));
  listB->add(new Music("Muito romântico", "Roberto Carlos"));

  Playlist *result = *listA + *listB;
  result->print();


  std::cout << "\n\na primeira playlist é " << std::endl;
  listA->print();

  std::cout << "\n\na segunda playlist é " << std::endl;
  listB->print();

  return 0;
}