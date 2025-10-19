#ifndef SONGBANK_H
#define SONGBANK_H

#include <vector>
#include <string>
#include "Song.h"

class SongBank {
private:
    std::vector<Song> songs;

public:
    SongBank(std::vector<Song> _songs = {});

    std::vector<Song> getSongs() const;
    void addSong(const Song& new_song);
    void deleteSong(std::string song);
    void sortByName();
    void showSongs() const;
};

#endif
