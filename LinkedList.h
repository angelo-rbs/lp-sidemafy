#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T>
class LinkedList {

private:
  Node<T> *cabeca;
  size_t tamanho;
  void incrementarTamanho(); 
  void decrementarTamanho();
  Node<T> *avancaPosicoes(Node<T> *ptr, int quantPos);
  Node<T> *wrapped_inserir(size_t pos, T *valor);
  Node<T> *wrapped_inserir(size_t pos, T valor);

public:
  LinkedList();
  LinkedList(Node<T> *cabeca);
  LinkedList(T valor);

  void printar();
  Node<T> *inserir(size_t pos, T *valor);
  Node<T> *inserir(size_t pos, T valorPtr);
  Node<T> *anexar(T valor);
  Node<T> *anexar(T *valorPtr);
  bool deletar(size_t pos);
  int encontrar(T valor);
  Node<T> *acessar(size_t pos);

  Node<T> *getCabeca();
  void setCabeca(Node<T> *cabeca);

  size_t getTamanho();

  bool contains(T valor);
  bool remove(T valor);


};

#endif