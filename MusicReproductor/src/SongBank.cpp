#include "SongBank.h"
#include <iostream>
#include <algorithm>


// Este es el constructor de SongBank*/
SongBank::SongBank(std::vector<Song> _songs) {
    songs = _songs;
}

//* Una manera de acceder a las canciones del banco de canciones/
std::vector<Song> SongBank::getSongs() const {
    return songs;
}

//* Con esto logramos añadir canciones al banco de canciones/
void SongBank::addSong(const Song& new_song) {
    songs.push_back(new_song);
}

//* Y con este borramos una cancion del banco de canciones, por medio del nombre/
void SongBank::deleteSong(std::string song) {
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i].getName() == song) {
            songs.erase(songs.begin() + i);
            std::cout << "Se elimino la cancion: " << song << std::endl;
            break;
        }
    }
}

//*Dado que los arreglos son ideales para organizar, se hace un metodo para ordenar alfabeticamente el SongBank/
void SongBank::sortByName() {
    std::sort(songs.begin(), songs.end(),
        [](const Song& a, const Song& b) {
            return a.getName() < b.getName();
        });
}

//* Este en lugar de retornar las canciones, las imprime en la terminal/
void SongBank::showSongs() const {
    if (songs.empty()) {
        std::cout << "No hay canciones." << std::endl;
        return;
    }

    for (int i = 0; i < songs.size(); i++) {
        std::cout << i + 1 << " // ";
        songs[i].info();
    }
}
