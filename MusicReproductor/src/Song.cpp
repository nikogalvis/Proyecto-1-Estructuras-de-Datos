#include "Song.h"

/* Clase base, para crear despues una lista de canciones
  *Los atributos es para organizarlos de distintas  maneras
  *Si lo vemos complejo, lo dejamos solo para Alfabeticamente
  */

Song::Song(std::string _name, std::string _artist, int _duration, std::string _genre)
    : name(_name), artist(_artist), duration(_duration), genre(_genre) {}

std::string Song::getName() const { return name; }
std::string Song::getArtist() const { return artist; }
int Song::getDuration() const { return duration; }
std::string Song::getGenre() const { return genre; }

void Song::info() const {
    std::cout << "Name: " << name << ", By: " << artist
              << ", Genre: " << genre << std::endl;
}