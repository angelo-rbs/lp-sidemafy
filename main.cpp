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

  Music *musicaTeste = new Music("asndlaksd", "dba,sdaskl");

  std::cout << "antes de remover eh " << std::endl;
  listA->print();
  std::cout << std::endl;

  Playlist *listaTeste = *listA - *musicaTeste;
  listaTeste->print();

  Music *teste = new Music("Melhor Só", "Igor BZ");

  *listA << *teste;

  listA->print();

  *listA >> teste;

  listA->print();

  Playlist *listC = new Playlist("Playlist C");

  *listC >> teste;

  if (teste == nullptr)
  {
    std::cout << "teste eh nulo" << std::endl;
  }

  return 0;
}