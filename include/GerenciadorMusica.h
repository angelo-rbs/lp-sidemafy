/**
 * @file GerenciadorMusica.h
 * @brief Definição da classe GerenciadorMusica.
 */

#ifndef GERENCIADOR_MUSICA_H
#define GERENCIADOR_MUSICA_H

#include <string>
#include "LinkedList.h"
#include "Musica.h"

/**
 * @brief Classe responsável por gerenciar músicas e suas playlists.
 */
class GerenciadorMusica {
public:
    /**
     * @brief Construtor padrão da classe GerenciadorMusica.
     */
    GerenciadorMusica();

    /**
     * @brief Destrutor da classe GerenciadorMusica.
     */
    ~GerenciadorMusica();

    /**
     * @brief Adiciona uma nova música ao gerenciador.
     *
     * @param nome O nome da nova música.
     */
    void adicionarMusica(const std::string& nome);

    /**
     * @brief Remove uma música do gerenciador.
     *
     * @param nome O nome da música a ser removida.
     */
    void removerMusica(const std::string& nome);

    /**
     * @brief Lista todas as músicas do gerenciador.
     */
    void listarMusicas();

private:
    /**
     * @brief Estrutura interna para armazenar informações sobre as músicas.
     */
    struct Musica {
        std::string nome; /**< Nome da música. */
        LinkedList<std::string>* playlists; /**< Ponteiro para a lista de playlists em que a música está presente. */
        Musica* prox; /**< Ponteiro para a próxima música na lista encadeada. */
    };

    /**
     * @brief Busca uma música pelo nome.
     *
     * @param nome O nome da música a ser buscada.
     * @return Um ponteiro para a estrutura da música, ou nullptr se a música não for encontrada.
     */
    Musica* buscarMusica(const std::string& nome);

    /**
     * @brief Remove a música de todas as playlists em que ela está presente.
     *
     * @param nome O nome da música a ser removida.
     */
    void removerMusicaDePlaylists(const std::string& nome);

    Musica* cabeca; /**< Ponteiro para a cabeça da lista encadeada de músicas. */
};

#endif
