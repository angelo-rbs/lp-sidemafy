#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "Node.h"

template <typename T>
class LinkedList {

private:
  Node<T> *head;
  size_t size;

public:

  LinkedList() {
    this->head = nullptr;
    this->size = 0;
  }

  LinkedList(Node<T>* head) {
    this->head = head;
    this->size = 1;
  }

  LinkedList(T valor) {
    this->head = new Node(valor);
    this->size = 1;
  }



  void print() {

    std::cout << "[ ";

    if (this->head != nullptr) {
      Node<T>* it = this->head;
      while (it != nullptr) {
        std::cout << it->getValue() << " ";
        it = it->getNext();
      }
    }

    std::cout << "]" << std::endl;
  }

  Node<T>* avancaPosicoes(Node<T>* ptr, int quantPos) {
    Node<T>* it = ptr;

    while (ptr != nullptr && quantPos-- > 0)
      it = it->getNext();

    return (it != nullptr) ? it : nullptr;
  }

  Node<T>* insert(size_t pos, T* valorPtr) {
    if (pos > this->getSize()) {
      throw std::out_of_range("Posição inválida");
    }

    Node<T>* node = wrappedInsert(pos, valorPtr);

    if (node) {
      this->increaseSize();
      return node;
    }
    else
      return nullptr;
  }

  Node<T>* insert(size_t pos, T valor) {
    if (pos > this->getSize()) {
      throw std::out_of_range("Posição inválida");
    }

    Node<T>* node = wrappedInsert(pos, valor);

    if (node) {
      this->increaseSize();
      return node;
    }
    else
      return nullptr;
  }

  Node<T>* wrappedInsert(size_t pos, T* valor) {

    if (pos > this->size)
      throw new std::out_of_range("Tentativa de inserção em posição inválida");
    Node<T>* it = this->head, * nodeAnterior, * newNode = new Node(valor);

    if (this->size == 0)
      this->head = newNode;

    else if (pos == size) {

      it = this->avancaPosicoes(it, pos - 1);
      it->setNext(newNode);
    }
    else {

      while (--pos)
        it = it->getNext();
      nodeAnterior = it;
      it = it->getNext();

      nodeAnterior->setNext(newNode);
      newNode->setNext(it);
    }

    return newNode;
  }

  Node<T>* wrappedInsert(size_t pos, T valor) {
    Node<T>* it = nullptr, * prev;

    if (this->head != nullptr) {
      it = this->head;
      it = this->avancaPosicoes(it, pos - 1);
    }
    else
      return this->head = new Node(valor);

    if (it->getNext() == nullptr) // se chegou na extremidade
      return it->setNext(new Node(valor));
    else {
      prev = it;
      it = this->avancaPosicoes(it, 1);

      prev->setNext(new Node(valor));
      prev->getNext()->setNext(it);

      return prev->getNext();
    }
  }

  Node<T>* append(T valor) {
    Node<T>* response = this->insert(this->getSize(), valor);

    return (response) ? response : nullptr;
  }

  Node<T>* append(T* valorPtr) {
    Node<T>* response = this->insert(this->getSize(), valorPtr);

    return (response) ? response : nullptr;
  }

  bool deletePos(size_t pos) {
    if (pos >= this->getSize())
      throw std::out_of_range("Posição fora do intervalo");

    try {
      Node<T>* prev = this->avancaPosicoes(this->gethead(), pos - 1);
      Node<T>* toBeDeleted = this->avancaPosicoes(prev, 1);
      Node<T>* next;

      if (toBeDeleted->getNext() != nullptr) {
        next = this->avancaPosicoes(toBeDeleted, 1);
        prev->setNext(next);
      }

      delete toBeDeleted;
    }
    catch (std::exception& e) {
      return false;
    }

    return true;
  }

  int find(T value) {

    int pos = 0;
    Node<T>* node = this->head;
    while (node != nullptr && node->getValue() != value) {
      node = node->getNext();
      ++pos;
    }

    return (node == nullptr) ? -1 : pos;
  }

  int find(T* valuePtr) {

    int pos = 0;
    Node<T>* node = this->head;
    while (node != nullptr && *(node->getValue()) != *valuePtr) {
      node = node->getNext();
      ++pos;
    }

    return (node == nullptr) ? -1 : pos;
  }

  Node<T>* access(size_t pos) {

    if (pos > this->size - 1)
      throw new std::out_of_range("Tentativa de acesso a posição inválida");

    Node<T>* node = this->head;
    node = this->avancaPosicoes(node, pos);

    return node;
  }



  Node<T>* getHead() {
    return this->head;
  }

  void setHead(Node<T>* head) {
    this->head = head;
  }

  size_t getSize() {
    return this->size;
  }

  void increaseSize() {
    ++(this->size);
  }

  void decreaseSize() {
    --(this->size);
  }
};


#endif