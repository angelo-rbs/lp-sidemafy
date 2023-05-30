#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "Node.h"

template <typename T>
class LinkedList {

private:
  Node<T>* head;
  size_t size;

public:

  // construtores

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

  LinkedList(LinkedList<T>& toCopy) {

    Node<T>* it = toCopy.getHead();
    this->size = 0;

    while (it != nullptr) {
      this->append(it->getValue());
      it = it->getNext();
    }
  }

  // métodos de acesso 

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

  // funcionalidades

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

    if (quantPos > this->getSize() - 1)
      it = nullptr;

    while (quantPos-- > 0 && it != nullptr)
      it = it->getNext();

    return it;
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

  Node<T>* append(LinkedList<T>& toAppend) {

    Node<T>* it = toAppend.getHead();

    while (it != nullptr) {
      this->append(it->getValue());
      it = it->getNext();
    }

    return it;
  }

  void remove(size_t pos) {
    if (pos >= this->getSize())
      throw std::out_of_range("Posição de remoção fora do intervalo");


    if (this->getHead() == nullptr)
      return;
  
    
    Node<T> *it = this->getHead(); 
    
    if (pos == 0) {
      this->setHead(it->getNext());
      delete it;
      return;
    }


    for (int i = 0; it != nullptr && i < pos - 1; i++)
      it = it->getNext();

    if (it == nullptr || it->getNext() == nullptr)
      return;

    
    Node<T> *next = it->getNext()->getNext();

    delete it->getNext();
    it->setNext(next);

    this->decreaseSize();
  }

  bool remove(LinkedList<T>& toBeRemoved) {

    Node<T>* it = toBeRemoved.getHead();
    bool removedAll = true;

    while (it != nullptr) {

      int positionToRemove = this->find(it->getValue());

      if (positionToRemove != -1)
        this->remove(positionToRemove);
      else
        removedAll = false;

      it = it->getNext();
    }

    return removedAll;
  }

  Node<T>* drop() {

    if (this->getSize() == 0) return nullptr;

    Node<T> *dropped = new Node( *(this->access(this->getSize() - 1)) );
    
    this->remove(this->getSize() - 1);
    return dropped;
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

  // sobrescrita de operadores

  LinkedList<T>* operator+(const LinkedList<T> toAppend) {

    LinkedList<T>* list = new LinkedList();

    Node<T>* it = this->getHead();
    while (it != nullptr) {
      list->append(it->getValue());
      it = it->getNext();
    }

    it = toAppend.getHead();
    while (it != nullptr) {
      list->append(it->getValue());
      it = it->getNext();
    }

    delete it;
    return list;
  }

};

template <typename T>
void operator>>(const LinkedList<T>& list, const Node<T>& node) {
  node = list.drop();
}


#endif