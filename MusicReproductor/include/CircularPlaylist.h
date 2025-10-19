#ifndef CIRCULARPLAYLIST_H
#define CIRCULARPLAYLIST_H

#include <iostream>
#include <string>
#include "Song.h"
#include "SongBank.h"

class CircularPlaylist {
private:
    struct Node {
        Song data;
        Node* next;
        Node* prev;
        Node(const Song& _data);
    };

    Node* head;
    int size;

public:
    CircularPlaylist();

    bool isEmpty() const;
    bool inSongBank(const std::string& song, const SongBank& sb) const;

    void addSong(const Song& song, const SongBank& sb);
    void deleteSong(const std::string& name);
    void showPlaylist() const;
    void goForward(const std::string& name) const;
    void goBack(const std::string& name) const;
    void playAll() const;

    int getSize() const;

    ~CircularPlaylist();
};

#endif
