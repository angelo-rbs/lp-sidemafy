/**
 * @file main.cpp
 * @brief Programa principal do sistema.
 */

#include <iostream>
#include "LinkedList.h"
#include "Menu.h"

/**
 * @brief Função principal do programa.
 * @details Cria uma lista encadeada e um objeto do menu, exibindo-o em seguida.
 * @return Retorna 0 se a execução foi bem sucedida.
 */
int main() {
  
  LinkedList<int> *lista = new LinkedList<int>();
  Menu menu;
  menu.showMenu();
  return 0;
}