#include <iostream>
#include <exception>
#include "LinkedList.h"
#include "Node.h"

template <typename T>
LinkedList<T>::LinkedList() {
  this->tamanho = 0;
}
     
template <typename T>
LinkedList<T>::LinkedList(Node<T>* cabeca) {
  this->cabeca = cabeca;
  this->tamanho = 1;
}

template <typename T>
void LinkedList<T>::printar() {

  std::cout << "[ ";

  Node<T> it = this->cabeca;
  while(it != nullptr) {
    std::cout << it.value << " ";
    it = it.nextNode();
  }
  std::cout << "]" << std::endl;

}

/*
  a ser testada
*/

template <typename T>
Node<T>* LinkedList<T>::inserir(size_t pos, T* valorPtr) {

  if (pos > this->tamanho || pos < 0) throw new std::out_of_range("Tentativa de inserção em posição inválida");
  Node<T>* it = this->cabeca, *nodeAnterior, *newNode = new Node(*valorPtr);;

  if (pos == tamanho) {

    while(pos-- - 1 > 0) it = it->getNext();
    it->setNext(newNode);

  } else {

    while(--pos) it = it->getNext();
    nodeAnterior = it;
    it = it->getNext();

    nodeAnterior->setNext(newNode);
    newNode->setNext(it);
  }

  return newNode;
}


template <typename T>
bool LinkedList<T>::deletar(size_t pos) {
  // TODO
}

template <typename T>
Node<T>* LinkedList<T>::encontrar(std::string nome) {

  Node<T>* node = this->cabeca;
  while (node != nullptr && node->value != nome) 
    para testarnode = node->nextNode();

  return node;
}

template <typename T>
Node<T>* LinkedList<T>::acessar(size_t pos) {

  if (pos > this->tamanho - 1) throw new std::out_of_range("Tentativa de acesso a posição inválida");
  Node<T>* node = this->cabeca;

  while (pos--) node = node->nextNode();

  return node->value;
  
}

template <typename T>
Node<T> LinkedList<T>::getCabeca() {
  return this->cabeca;
}

template <typename T>
void LinkedList<T>::setCabeca(Node<T> *cabeca) {
  this->cabeca = cabeca;
}

template <typename T>
size_t LinkedList<T>::getTamanho() {
  this->tamanho;
}

template <typename T>
void LinkedList<T>::incrementarTamanho() {
  ++(this->tamanho);
}

template <typename T>
void LinkedList<T>::decrementarTamanho() {
  --(this->tamanho);
}