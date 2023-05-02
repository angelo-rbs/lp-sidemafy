#include <iostream>
#include <exception>
#include "LinkedList.h"
#include "Node.h"

template <typename T>
LinkedList<T>::LinkedList()
{
  this->cabeca = nullptr;
  this->tamanho = 0;
}

template <typename T>
LinkedList<T>::LinkedList(Node<T> *cabeca)
{
  this->cabeca = cabeca;
  this->tamanho = 1;
}

template <typename T>
LinkedList<T>::LinkedList(T valor)
{
  this->cabeca = new Node(valor);
  this->tamanho = 1;
}

template <typename T>
void LinkedList<T>::printar()
{

  std::cout << "[ ";

  if (this->cabeca != nullptr)
  {
    Node<T> *it = this->cabeca;
    while (it != nullptr)
    {
      std::cout << (*it).getValue() << " ";
      it = it->getNext();
    }
  }

  std::cout << "]" << std::endl;
}

template <typename T>
Node<T> *LinkedList<T>::avancaPosicoes(Node<T> *ptr, int quantPos) {
  Node<T> *it = ptr;

  while (ptr != nullptr && quantPos-- > 0)
    it = it->getNext();

  return (it != nullptr) ? it : nullptr; 
}

template <typename T>
Node<T> *LinkedList<T>::inserir(size_t pos, T *valorPtr)
{
  if (pos > this->getTamanho())
  {
    throw std::out_of_range("Posição inválida");
  }

  Node<T> *node = wrapped_inserir(pos, valorPtr);

  if (node)
  {
    this->incrementarTamanho();
    return node;
  }
  else
    return nullptr;
}

template <typename T>
Node<T> *LinkedList<T>::inserir(size_t pos, T valor)
{
  if (pos > this->getTamanho())
  {
    throw std::out_of_range("Posição inválida");
  }

  Node<T> *node = wrapped_inserir(pos, valor);

  if (node)
  {
    this->incrementarTamanho();
    return node;
  }
  else
    return nullptr;
}

template <typename T>
Node<T> *LinkedList<T>::wrapped_inserir(size_t pos, T *valor)
{

  if (pos > this->tamanho)
    throw new std::out_of_range("Tentativa de inserção em posição inválida");
  Node<T> *it = this->cabeca, *nodeAnterior, *newNode = new Node(valor);

  if (this->tamanho == 0)
    this->cabeca = newNode;

  else if (pos == tamanho)
  {

    it = this->avancaPosicoes(it, pos - 1);
    it->setNext(newNode);
  }
  else
  {

    while (--pos)
      it = it->getNext();
    nodeAnterior = it;
    it = it->getNext();

    nodeAnterior->setNext(newNode);
    newNode->setNext(it);
  }

  return newNode;
}

template <typename T>
Node<T> *LinkedList<T>::wrapped_inserir(size_t pos, T valor)
{
  Node<T> *it = nullptr, *prev;

  if (this->cabeca != nullptr)
  {
    it = this->cabeca;
    it = this->avancaPosicoes(it, pos - 1);
  }
  else
    return this->cabeca = new Node(valor);

  if (it->getNext() == nullptr) // se chegou na extremidade
    return it->setNext(new Node(valor));
  else
  {
    prev = it;
    it = this->avancaPosicoes(it, 1);

    prev->setNext(new Node(valor));
    prev->getNext()->setNext(it);

    return prev->getNext();
  }
}

template <typename T>
Node<T> *LinkedList<T>::anexar(T valor) {
  Node<T> *response = this->inserir(this->getTamanho(), valor);

  return (response) ? response : nullptr;
}


template <typename T>
Node<T> *LinkedList<T>::anexar(T *valorPtr) {
  Node<T> *response = this->inserir(this->getTamanho(), valorPtr);

  return (response) ? response : nullptr;
}

template <typename T>
bool LinkedList<T>::deletar(size_t pos)
{
  if (pos >= this->getTamanho()) throw std::out_of_range("Posição fora do intervalo");

  try {
    Node<T> *prev = this->avancaPosicoes(this->getCabeca(), pos - 1);
    Node<T> *toBeDeleted = this->avancaPosicoes(prev, 1);
    Node<T> *next;

    if (toBeDeleted->getNext() != nullptr) { 
      next = this->avancaPosicoes(toBeDeleted, 1);
      prev->setNext(next);
    } 

    delete toBeDeleted;

  } catch (std::exception &e) {
    return false;
  }

  

  return true;
}

template <typename T>
int LinkedList<T>::encontrar(T valor)
{

  int pos = 0;
  Node<T> *node = this->cabeca;
  while (node != nullptr && *(node->getValue()) != valor) {
    node = node->getNext();
    ++pos;
  }

  return (node == nullptr) ? -1 : pos;
}


template <typename T>
Node<T> *LinkedList<T>::acessar(size_t pos)
{

  if (pos > this->tamanho - 1)
    throw new std::out_of_range("Tentativa de acesso a posição inválida");

  Node<T> *node = this->cabeca;
  node = this->avancaPosicoes(node, pos);

  return node;
}

template <typename T>
Node<T> *LinkedList<T>::getCabeca()
{
  return this->cabeca;
}

template <typename T>
void LinkedList<T>::setCabeca(Node<T> *cabeca)
{
  this->cabeca = cabeca;
}

template <typename T>
size_t LinkedList<T>::getTamanho()
{
  return this->tamanho;
}

template <typename T>
void LinkedList<T>::incrementarTamanho()
{
  ++(this->tamanho);
}

template <typename T>
void LinkedList<T>::decrementarTamanho()
{
  --(this->tamanho);
}

template <typename T>
bool LinkedList<T>::contains(T valor) {
  Node<T> *it = this->cabeca;

  while (it != nullptr) {
    if (it->getValue() == valor) {
      return true;
    }
    it = it->getNext();
  }

  return false;
}

template <typename T>
bool LinkedList<T>::remove(T valor) {
  Node<T> *it = this->cabeca, *nodeAnterior = nullptr;

  while (it != nullptr) {
    if (it->getValue() == valor) {
      if (nodeAnterior == nullptr) {
        // Caso estejamos na primeira posição
        this->cabeca = it->getNext();
      } else {
        nodeAnterior->setNext(it->getNext());
      }

      delete it;
      this->decrementarTamanho();
      return true;
    }
    nodeAnterior = it;
    it = it->getNext();
  }

  return false;
}

