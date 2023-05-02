/**
 * @file Playlist.h
 * @brief Arquivo cabeçalho da classe Playlist
 */

#include <iostream>
#include <ostream>
#include "LinkedList.h"
#include "Musica.h"

/**
 * @brief Classe que representa uma playlist de músicas
 */
class Playlist {

  private:
    std::string nome; /**< Nome da playlist */
    LinkedList<Musica> *musicas; /**< Lista encadeada das músicas da playlist */
    /**
     * @brief Função auxiliar para impressão das músicas da playlist de forma quebrada em linhas
     * 
     * @param node Nó atual da lista de músicas
     * @param pos Posição atual da impressão
     */
    void printWrapped(Node<Musica> *node, int pos);

  public:
    /**
     * @brief Construtor padrão da classe Playlist
     */
    Playlist();

    /**
     * @brief Construtor da classe Playlist que recebe um nome
     * 
     * @param nome Nome da playlist
     */
    Playlist(std::string nome);

    /**
     * @brief Construtor da classe Playlist que recebe um nome e uma lista encadeada de músicas
     * 
     * @param nome Nome da playlist
     * @param lista Lista encadeada de músicas
     */
    Playlist(std::string nome, LinkedList<Musica> *lista);

    /**
     * @brief Construtor da classe Playlist que recebe um nome e uma lista de músicas
     * 
     * @param nome Nome da playlist
     * @param lista Lista de músicas
     */
    Playlist(std::string nome, LinkedList<Musica> lista);

    /**
     * @brief Função que imprime as músicas da playlist
     */
    void print();

    /**
     * @brief Retorna o nome da playlist
     * 
     * @return std::string Nome da playlist
     */
    std::string getNome();

    /**
     * @brief Define o nome da playlist
     * 
     * @param nome Novo nome da playlist
     */
    void setNome(std::string nome);

    /**
     * @brief Retorna a lista encadeada das músicas da playlist
     * 
     * @return LinkedList<Musica>* Ponteiro para a lista encadeada das músicas da playlist
     */
    LinkedList<Musica>* getMusicas();

    /**
     * @brief Adiciona uma música à playlist
     * 
     * @param musica Ponteiro para a música a ser adicionada
     * @return Node<Musica>* Ponteiro para o nó da lista que armazena a música adicionada
     */
    Node<Musica>* adicionarMusica(Musica* musica);

    /**
     * @brief Remove uma música da playlist
     * 
     * @param nomeMusica Nome da música a ser removida
     * @param nomeArtista Nome do artista da música a ser removida
     * @return true se a música foi removida, false caso contrário
     */
    bool removerMusica(std::string nomeMusica, std::string nomeArtista);
};

/**
 * @brief Sobrecarga do operador de impressão (<<) para a classe Playlist
 * 
 * @param out Stream de saída
 * @param pl Playlist a ser impressa
 * @return std::ostream& Stream de saída
 */
std::ostream& operator<<(std::ostream &out, Playlist &pl);