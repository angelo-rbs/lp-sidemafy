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

  LinkedList<int> *copyOfList = new LinkedList<int>(*list);


  std::cout << "a lista original é ";
  list->print();
  std::cout << "de endereço " << list << std::endl;

  std::cout << std::endl;

  std::cout << "a lista copiada com 0 no final é ";
  copyOfList->append(0);
  copyOfList->print();
  std::cout << "de endereço " << copyOfList << std::endl;


  std::cout << "os endereços são diferentes: " << (copyOfList != list) << std::endl;

  return 0;
}