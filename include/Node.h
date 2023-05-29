#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {

private:
  Node<T>* nextNode;
  T value;

public:

  Node() {
    this->nextNode = nullptr;
  }

  Node(T value) {
    this->value = value;
    this->nextNode = nullptr;
  }

  Node(T* value) {
    this->value = *value;
    this->nextNode = nullptr;
  }


  bool operator== (Node<T>& n) {
    return n.value == (*this).value;
  }

  bool operator!= (Node<T>& n) {
    return !(*this == n);
  }


  T getValue() {
    return this->value;
  }

  Node<T>* getNext() {
    return this->nextNode;
  }

  void setValue(T value) {
    this->value = value;
  }

  Node<T>* setNext(Node<T>* ptr) {
    return this->nextNode = ptr;
  }

};


#endif