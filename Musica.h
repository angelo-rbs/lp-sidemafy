#ifndef MUSICA_H
#define MUSICA_H

class Musica
{

private:
  std::string titulo;
  std::string nomeArtista;

public:

  std::string getTitulo();
  void setTitulo(std::string titulo);

  std::string getNomeArtista();
  void setNomeArtista(std::string titulo);

  Musica();
  Musica(std::string titulo, std::string nomeArtista);
  bool operator== (Musica &m1);
  bool operator!= (Musica &m1);
};

#endif