/**
 * @file Node.h
 * @brief Arquivo cabeçalho da classe Node
 */

#ifndef NODE_H
#define NODE_H

/**
 * @brief Classe template que representa um nó de uma lista encadeada
 * 
 * @tparam T Tipo de dado armazenado no nó
 */
template <typename T> class Node {
  private:
    T *value; /**< Ponteiro para o valor armazenado no nó */
    Node* nextNode; /**< Ponteiro para o próximo nó da lista */

  public:
    /**
     * @brief Retorna o valor armazenado no nó
     * 
     * @return T* Ponteiro para o valor armazenado no nó
     */
    T *getValue();

    /**
     * @brief Define o valor armazenado no nó
     * 
     * @param value Valor a ser armazenado no nó
     */
    void setValue(T value);

    /**
     * @brief Retorna o próximo nó da lista
     * 
     * @return Node<T>* Ponteiro para o próximo nó da lista
     */
    Node<T>* getNext();

    /**
     * @brief Define o próximo nó da lista
     * 
     * @param ptr Ponteiro para o próximo nó da lista
     * @return Node<T>* Ponteiro para o nó atual
     */
    Node<T>* setNext(Node<T>* ptr);

    /**
     * @brief Construtor padrão da classe Node
     */
    Node();

    /**
     * @brief Construtor da classe Node que recebe um valor a ser armazenado no nó
     * 
     * @param value Valor a ser armazenado no nó
     */
    Node(T value);

    /**
     * @brief Construtor da classe Node que recebe um ponteiro para um valor a ser armazenado no nó
     * 
     * @param value Ponteiro para o valor a ser armazenado no nó
     */
    Node(T *value);

    /**
     * @brief Sobrecarga do operador de igualdade (==) da classe Node
     * 
     * @param n Nó a ser comparado
     * @return true se o valor armazenado nos nós for igual, false caso contrário
     */
    bool operator== (Node<T> &n);

    /**
     * @brief Sobrecarga do operador de diferença (!=) da classe Node
     * 
     * @param n Nó a ser comparado
     * @return true se o valor armazenado nos nós for diferente, false caso contrário
     */
    bool operator!= (Node<T> &n);
};

#endif