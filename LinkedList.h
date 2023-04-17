#include <Node.h>

  template <typename T> class LinkedList {

    private: 
      Node<T>* cabeca;
      size_t tamanho;
      void incrementarTamanho(); // pode ser chamado no insert ? (deveria)

    public:
      LinkedList();
      LinkedList(Node<T>* cabeca);

      Node<T>* inserirNaPosicao(size_t pos);
      bool deletarPosicao();
      Node<T>* encontrarMusica(std::string nome);
      Node<T>* acessarPosicao(size_t pos);

      Node<T> getCabeca();
      void setCabeca(Node<T>* node);

      size_t getTamanho();
  };