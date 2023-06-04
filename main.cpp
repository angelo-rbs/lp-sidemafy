#include <iostream>
#include "include/LinkedList.h"

int main()
{

  LinkedList<int> *list = new LinkedList<int>();

  list->append(1);
  list->append(2);
  list->append(3);
  list->append(4);
  list->append(5);
  list->append(6);

  list->drop();
  list->drop();
  list->drop();

  Node<int> *node = list->drop();

  list->print();
  std::cout << node->getValue() << std::endl;

  Node<int> *node2;

  *list >> *node2;

  list->print();

  *list << *node2;

  list->print();

  return 0;
}