#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>


//* Definimos la clase base de todo el simulador/  
class Song {
private:
    std::string name;
    std::string artist;
    int duration;
    std::string genre;

public:

//* Se definen los metodos de la clase song/
    Song(std::string _name, std::string _artist, int _duration, std::string _genre);

    std::string getName() const;
    std::string getArtist() const;
    int getDuration() const;
    std::string getGenre() const;

    void info() const;
};

#endif
