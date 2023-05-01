#include "Node.h"

template <typename T>
Node<T>::Node() {
  this->nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
  this->value = new T(value);
  this->nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T *value) {
  this->value = value;
  this->nextNode = nullptr;
}

template <typename T>
T* Node<T>::getValue() {
  return this->value;
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return this->nextNode;
}

template <typename T>
void Node<T>::setValue(T value) {
  this->value = value;
}

template <typename T>
Node<T>* Node<T>::setNext(Node<T>* ptr) {
  return this->nextNode = ptr;
}

template <typename T>
bool Node<T>::operator== (Node<T> &n) {
  return n.value == (*this).value; 
}

template <typename T>
bool Node<T>::operator!= (Node<T> &n) {
 return !(*this == n);
}

