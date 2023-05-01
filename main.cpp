#include <iostream>
#include "LinkedList.h"
#include "Menu.h"

int main() {
  
  LinkedList<int> *lista = new LinkedList<int>();
  Menu menu;
  menu.showMenu();
  return 0;
}