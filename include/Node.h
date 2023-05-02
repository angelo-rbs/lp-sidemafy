#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
  private:
    T *value;
    Node* nextNode;

  public:
    T *getValue();
    void setValue(T value);

    Node<T>* getNext();
    Node<T>* setNext(Node<T>* ptr);

    Node();
    Node(T value);
    Node(T *value);
    bool operator== (Node<T> &n);
    bool operator!= (Node<T> &n);
};

#endif