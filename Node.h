#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
  private:
    T* value;
    Node* nextNode;

  public:
    T getValue();
    void setValue(T value);

    Node<T>* getNext();
    void setNext(Node<T>* ptr);

    Node();
    Node(T value);
};

#endif
