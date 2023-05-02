/**
 * @file GerenciadorPlaylist.h
 * @brief Definição da classe GerenciadorPlaylist, responsável por gerenciar as playlists.
 */

#ifndef GERENCIADORPLAYLIST_H
#define GERENCIADORPLAYLIST_H

#include <iostream>
#include <string>
#include "Playlist.h"
#include "LinkedList.h"

/**
 * @class GerenciadorPlaylist
 * @brief Classe responsável por gerenciar as playlists.
 */
class GerenciadorPlaylist {

private:
  LinkedList<Playlist> *playlists; /**< Ponteiro para lista de playlists. */

public:
  /**
   * @brief Construtor padrão da classe GerenciadorPlaylist.
   */
  GerenciadorPlaylist();

  /**
   * @brief Destrutor da classe GerenciadorPlaylist.
   */
  ~GerenciadorPlaylist();

  /**
   * @brief Adiciona uma nova playlist.
   * @param playlist Ponteiro para a playlist a ser adicionada.
   * @return Ponteiro para o nó da lista de playlists que contém a playlist adicionada.
   */
  Node<Playlist> *adicionarPlaylist(Playlist *playlist);

  /**
   * @brief Remove uma playlist.
   * @param nomePlaylist Nome da playlist a ser removida.
   * @return Verdadeiro se a playlist foi removida com sucesso, falso caso contrário.
   */
  bool removerPlaylist(std::string nomePlaylist);

  /**
   * @brief Encontra uma playlist.
   * @param nomePlaylist Nome da playlist a ser encontrada.
   * @return Ponteiro para o nó da lista de playlists que contém a playlist encontrada, ou nullptr se a playlist não foi encontrada.
   */
  Node<Playlist> *encontrarPlaylist(std::string nomePlaylist);

  /**
   * @brief Adiciona uma música a uma playlist.
   * @param nomePlaylist Nome da playlist onde a música será adicionada.
   * @param musica Ponteiro para a música a ser adicionada.
   * @return Verdadeiro se a música foi adicionada com sucesso, falso caso contrário.
   */
  bool adicionarMusica(std::string nomePlaylist, Musica *musica);

  /**
   * @brief Remove uma música de uma playlist.
   * @param nomePlaylist Nome da playlist onde a música será removida.
   * @param titulo Título da música a ser removida.
   * @param nomeArtista Nome do artista da música a ser removida.
   * @return Verdadeiro se a música foi removida com sucesso, falso caso contrário.
   */
  bool removerMusica(std::string nomePlaylist, std::string titulo, std::string nomeArtista);

  /**
   * @brief Imprime os dados de uma playlist.
   * @param nomePlaylist Nome da playlist a ser impressa.
   */
  void imprimirPlaylist(std::string nomePlaylist);

  /**
   * @brief Imprime os dados de todas as playlists.
   */
  void imprimirTodasPlaylists();
};

#endif