#include <iostream>
#include "Musica.h"

Musica::Musica() {

}

Musica::Musica(std::string titulo, std::string nomeArtista) {
  this->titulo = titulo;
  this->nomeArtista = nomeArtista;
}

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

bool Musica::operator== (Musica &m1) {
  return (m1.getNomeArtista() == nomeArtista) && (m1.getTitulo() == titulo);
}

bool Musica::operator!= (Musica &m1) {
  return !(m1 == *this);
}
