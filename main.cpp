#include <iostream>
#include "include/LinkedList.h"

int main() {
  
  LinkedList<int> *list = new LinkedList<int>();

  list->append(1);
  list->append(2);
  list->append(3);

  list->print();

  return 0;
}