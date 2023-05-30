#include <iostream>
#include "include/LinkedList.h"

int main() {
  
  LinkedList<int> *list = new LinkedList<int>();

  list->append(1);
  list->append(2);
  list->append(3);
  list->append(4);
  list->append(5);
  list->append(6);

  list->print();
  list->remove(0);
  list->print();

  // std::cout << "ficou com tamanho " << list->getSize() << std::endl;

  // Node<int> *node;

  // node = list->drop();

  //list->print();
  
  //std::cout << node->getValue() << std::endl;

  

  return 0;
}