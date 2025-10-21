#ifndef CIRCULARPLAYLIST_H
#define CIRCULARPLAYLIST_H


#include <iostream>
#include <string>
#include "Song.h"
#include "SongBank.h"


//*Se implementa la clase CircularPlaylist*/
// Tiene el proposito de simular una lista que en lugar de terminar abruptamente, se repite/
class CircularPlaylist {



//*Se crea una lista, doblemente encadenada, con un dato del tipo "Song"*/
//*Se añade tambien la cabeza y el tamaño de la playlist/
private:
    struct Node {
        Song data;
        Node* next;
        Node* prev;
        Node(const Song& _data);
    };

    Node* head;
    int size;


//* Se añaden los metodos que se usaran (Sin logica  pues esta va en los .cpp)/
public:
    CircularPlaylist();

    bool isEmpty() const;
    bool inSongBank(const std::string& song, const SongBank& sb) const;

    void addSong(const Song& song, const SongBank& sb);
    void deleteSong(const std::string& name);
    void showPlaylist() const;
    std::string goForward(const std::string& name) const;
    std::string goBack(const std::string& name) const;
    void playAll() const;
    int getSize() const;
    std::vector<Song> getSongs() const;


    ~CircularPlaylist();
};

#endif
