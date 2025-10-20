#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include "Song.h"
#include "SongBank.h"


//* Se crea una lista doblemente encadenada, para representar una cola en la cual se puede retroceder/  
class Playlist {
private:
    struct Node {
        Song data;
        Node* next;
        Node* prev;
        Node(const Song& _data);
    };

    Node* head;
    int size;


//* Se definen los metodos que usara la clase/
public:
    Playlist();
    ~Playlist();

    bool inSongBank(const std::string& song, const SongBank& sb);
    bool isEmpty() const;
    void addSong(const Song& song, const SongBank& sb);
    void deleteSong(const std::string& name);
    void showPlaylist() const;
    int getSize() const;
    void goBack(const std::string& name) const;
    void goForward(const std::string& name) const;
    void playAll() const;
};

#endif
