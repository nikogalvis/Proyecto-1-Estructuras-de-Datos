#include <iostream>
#include "Song.h"
#include "SongBank.h"
#include "Playlist.h"
#include "CircularPlaylist.h"


//! Este codigo es el que compila todo el programa (Se debe usar desde la carpeta raiz)/
/* g++ src/*.cpp -I include -o programa */
//* Luego solo usan programa.exe (como el Sonic) */


int main() {
    // --- Crear canciones ---
    Song song1("Song A", "Artist 1", 200, "Pop");
    Song song2("Song B", "Artist 2", 180, "Rock");
    Song song3("Song C", "Artist 3", 240, "Hip Hop");
    Song song4("Song D", "Adolf", 1945, "Concentration");

    // --- Crear SongBank ---
    SongBank bank;
    bank.addSong(song1);
    bank.addSong(song2);
    bank.addSong(song3);

    // --- Crear la CircularPlaylist ---
    CircularPlaylist pl;
    pl.addSong(song1, bank);
    pl.addSong(song2, bank);
    pl.addSong(song3, bank);
    pl.addSong(song4, bank);

    std::cout << "\nPlaylist inicial:\n";
    pl.showPlaylist();

    // --- Probar goBack y goForward antes de eliminar ---
    std::cout << "\nCancion siguiente a 'Song A':\n";
    pl.goForward("Song A"); // Debe mostrar Song B

    std::cout << "Cancion anterior a 'Song C':\n";
    pl.goBack("Song C"); // Debe mostrar Song B

    // --- Eliminar canción del medio ---
    std::cout << "\nEliminando 'Song B':\n";
    pl.deleteSong("Song B");

    std::cout << "\nPlaylist despues de eliminar 'Song B':\n";
    pl.showPlaylist();

    // --- Probar goBack y goForward después de eliminar ---
    std::cout << "\nCancion siguiente a 'Song A':\n";
    pl.goForward("Song A"); // Ahora debe ir directo a Song C

    std::cout << "Cancion anterior a 'Song C':\n";
    pl.goBack("Song C"); // Ahora debe ir directo a Song A

    std::cout << "Toda la wea: \n";
    pl.playAll();
    return 0;
}

