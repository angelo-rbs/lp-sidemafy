#include "Node.h"

template <typename T> Node<T>::Node() {

}

template <typename T> Node<T>::Node(T value) {
  this->value = value;
  this->nextNode = nullptr;
}

template <typename T> T Node<T>::getValue() {
  return this->value;
}

template <typename T> Node<T>* Node<T>::getNext() {
  return this->nextNode;
}

template <typename T> void Node<T>::setValue(T value) {
  this->value = value;
}

template <typename T> void Node<T>::setNext(Node<T>* ptr) {
  this->nextNode = ptr;
}


