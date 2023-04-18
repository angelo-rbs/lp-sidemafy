#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T>
class LinkedList {

private:
  Node<T> *cabeca;
  size_t tamanho;
  void incrementarTamanho(); // pode ser chamado no insert ? (deveria)
  void decrementarTamanho();

public:
  LinkedList();
  LinkedList(Node<T> *cabeca);

  void printar();
  Node<T> *inserir(size_t pos, T *value);
  bool deletar(size_t pos);
  Node<T> *encontrar(std::string nome);
  Node<T> *acessar(size_t pos);

  Node<T> getCabeca();
  void setCabeca(Node<T> *cabeca);

  size_t getTamanho();
};

#endif
