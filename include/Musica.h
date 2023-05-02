/**
 * @file Musica.h
 * @brief Definição da classe Musica e seus métodos.
 */

#ifndef MUSICA_H
#define MUSICA_H

#include <string>

/**
 * @brief Classe que representa uma música.
 */
class Musica {

private:
  std::string titulo; /**< Título da música. */
  std::string nomeArtista; /**< Nome do artista da música. */

public:

  /**
   * @brief Obtém o título da música.
   * @return Título da música.
   */
  std::string getTitulo();

  /**
   * @brief Define o título da música.
   * @param titulo Título da música.
   */
  void setTitulo(std::string titulo);

  /**
   * @brief Obtém o nome do artista da música.
   * @return Nome do artista da música.
   */
  std::string getNomeArtista();

  /**
   * @brief Define o nome do artista da música.
   * @param nomeArtista Nome do artista da música.
   */
  void setNomeArtista(std::string nomeArtista);

  /**
   * @brief Construtor padrão da classe Musica.
   */
  Musica();

  /**
   * @brief Construtor da classe Musica.
   * @param titulo Título da música.
   * @param nomeArtista Nome do artista da música.
   */
  Musica(std::string titulo, std::string nomeArtista);

  /**
   * @brief Operador de igualdade para comparar duas músicas.
   * @param m1 Música a ser comparada.
   * @return true se as músicas forem iguais, false caso contrário.
   */
  bool operator== (Musica &m1);

  /**
   * @brief Operador de desigualdade para comparar duas músicas.
   * @param m1 Música a ser comparada.
   * @return true se as músicas forem diferentes, false caso contrário.
   */
  bool operator!= (Musica &m1);
};

#endif