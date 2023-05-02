/**
 * @file LinkedList.h
 * @brief Definição da classe LinkedList para implementação de uma lista encadeada.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

/**
 * @brief Classe que define uma lista encadeada.
 * 
 * @tparam T Tipo de dado armazenado na lista encadeada.
 */
template <typename T>
class LinkedList {

private:
  Node<T> *cabeca; /**< Nó cabeça da lista. */
  size_t tamanho; /**< Tamanho atual da lista. */

  /**
   * @brief Incrementa o tamanho da lista.
   */
  void incrementarTamanho(); 

  /**
   * @brief Decrementa o tamanho da lista.
   */
  void decrementarTamanho();

  /**
   * @brief Avança uma quantidade de posições na lista a partir de um nó dado.
   * 
   * @param ptr Nó a partir do qual a lista será percorrida.
   * @param quantPos Quantidade de posições a serem avançadas.
   * @return Ponteiro para o nó que se encontra na posição desejada.
   */
  Node<T> *avancaPosicoes(Node<T> *ptr, int quantPos);

  /**
   * @brief Insere um valor na lista encadeada em uma determinada posição.
   * 
   * @param pos Posição em que o valor será inserido.
   * @param valor Ponteiro para o valor que será inserido.
   * @return Ponteiro para o nó que contém o valor recém inserido.
   */
  Node<T> *wrapped_inserir(size_t pos, T *valor);

  /**
   * @brief Insere um valor na lista encadeada em uma determinada posição.
   * 
   * @param pos Posição em que o valor será inserido.
   * @param valor Valor que será inserido.
   * @return Ponteiro para o nó que contém o valor recém inserido.
   */
  Node<T> *wrapped_inserir(size_t pos, T valor);

public:

  /**
   * @brief Construtor padrão da classe LinkedList.
   */
  LinkedList();

  /**
   * @brief Construtor que inicializa a lista com um nó cabeça dado.
   * 
   * @param cabeca Nó cabeça da lista.
   */
  LinkedList(Node<T> *cabeca);

  /**
   * @brief Construtor que inicializa a lista com um valor dado.
   * 
   * @param valor Valor que será o primeiro elemento da lista.
   */
  LinkedList(T valor);

  /**
   * @brief Imprime a lista encadeada na saída padrão.
   */
  void printar();

  /**
   * @brief Insere um valor na lista encadeada em uma determinada posição.
   * 
   * @param pos Posição em que o valor será inserido.
   * @param valor Ponteiro para o valor que será inserido.
   * @return Ponteiro para o nó que contém o valor recém inserido.
   */

  Node<T> *inserir(size_t pos, T *valor);

  /**
   * @brief Insere um novo valor na posição especificada.
   * @param pos Posição onde o valor será inserido.
   * @param valorPtr Ponteiro para o valor que será inserido.
   * @return Ponteiro para o nó recém-inserido.
   */
  Node<T> *inserir(size_t pos, T valorPtr);

  /**
   * @brief Adiciona um novo valor no final da lista.
   * @param valor Valor que será adicionado.
   * @return Ponteiro para o nó recém-adicionado.
   */
  Node<T> *anexar(T valor);

  /**
   * @brief Adiciona um novo valor no final da lista.
   * @param valorPtr Ponteiro para o valor que será adicionado.
   * @return Ponteiro para o nó recém-adicionado.
   */
  Node<T> *anexar(T *valorPtr);

  /**
   * @brief Remove um valor da lista.
   * @param pos Posição do valor que será removido.
   * @return true se o valor foi removido com sucesso, false caso contrário.
   */
  bool deletar(size_t pos);

  /**
   * @brief Procura um valor na lista.
   * @param valor Valor que será procurado.
   * @return Posição do valor na lista ou -1 se não for encontrado.
   */
  int encontrar(T valor);

  /**
   * @brief Acessa o nó da lista na posição especificada.
   * @param pos Posição do nó que será acessado.
   * @return Ponteiro para o nó na posição especificada.
   */
  Node<T> *acessar(size_t pos);

  /**
   * @brief Retorna a cabeça da lista.
   * @return Ponteiro para o nó cabeça da lista.
   */
  Node<T> *getCabeca();

  /**
   * @brief Define o nó cabeça da lista.
   * @param cabeca Ponteiro para o nó cabeça da lista.
   */
  void setCabeca(Node<T> *cabeca);

  /**
   * @brief Retorna o tamanho da lista.
   * @return Tamanho da lista.
   */
  size_t getTamanho();

  /**
   * @brief Verifica se a lista contém um valor específico.
   * @param valor Valor que será procurado na lista.
   * @return true se a lista contém o valor, false caso contrário.
   */
  bool contains(T valor);

  /**
   * @brief Remove um valor da lista.
   * @param valor Valor que será removido.
   * @return true se o valor foi removido com sucesso, false caso contrário.
   */
  bool remove(T valor);
};

#endif