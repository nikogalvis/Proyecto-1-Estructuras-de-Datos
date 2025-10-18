#include "SongBank.h"
#include <iostream>
#include <algorithm>

SongBank::SongBank(std::vector<Song> _songs) {
    songs = _songs;
}

void SongBank::addSong(const Song& new_song) {
    songs.push_back(new_song);
}

void SongBank::deleteSong(std::string song) {
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i].getName() == song) {
            songs.erase(songs.begin() + i);
            std::cout << "Se elimino la cancion: " << song << std::endl;
            break;
        }
    }
}

void SongBank::sortByName() {
    std::sort(songs.begin(), songs.end(),
        [](const Song& a, const Song& b) {
            return a.getName() < b.getName();
        });
}

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
