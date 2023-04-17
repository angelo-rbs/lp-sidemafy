#include <iostream>
#include "Musica.h"


Musica::Musica(std::string titulo, std::string nomeArtista) {
  this->titulo = titulo;
  this->nomeArtista = nomeArtista;
}

Musica::Musica() {};


std::string Musica::getTitulo() {
  return this->titulo;
}

void Musica::setTitulo(std::string titulo) {
  this->titulo = titulo;
}

std::string Musica::getNomeArtista() {
  return this->nomeArtista;
}

void Musica::setNomeArtista(std::string nomeArtista) {
  this->nomeArtista = nomeArtista;
}

