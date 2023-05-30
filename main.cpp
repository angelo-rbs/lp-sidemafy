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

  LinkedList<int> *toRemove = new LinkedList<int>();

  toRemove->append(2);
  toRemove->append(5);
  toRemove->append(0);

  bool removeuTodos = list->remove(*toRemove);

  std::cout << "removeu todos: " << removeuTodos << std::endl;
  list->print();

  return 0;
}