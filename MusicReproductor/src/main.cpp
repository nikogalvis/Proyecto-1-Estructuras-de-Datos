#include <iostream>
#include <vector>
#include "Song.h"
#include "SongBank.h"

int main() {
    // Creamos algunas canciones de ejemplo
    Song song1("Bohemian Rhapsody", "Queen", 354, "Rock");
    Song song2("Smells Like Teen Spirit", "Nirvana", 301, "Rock");
    Song song3("Billie Jean", "Michael Jackson", 294, "Pop");
    Song song4("Bohemian Rhapsody", "Queen", 354, "Rock");
    Song song5("Shape of You", "Ed Sheeran", 233, "Pop");
    Song song6("Lose Yourself", "Eminem", 326, "Hip Hop");
    Song song7("Hotel California", "Eagles", 391, "Rock");
    Song song8("Rolling in the Deep", "Adele", 228, "Pop");
    Song song9("Stairway to Heaven", "Led Zeppelin", 482, "Rock");
    Song song10("Bad Guy", "Billie Eilish", 194, "Pop");
    Song song11("Wonderwall", "Oasis", 258, "Rock");
    Song song12("Hey Jude", "The Beatles", 431, "Rock");

    // Creamos un vector inicial y el banco
    std::vector<Song> initialSongs = { song1, song2 };
    SongBank bank(initialSongs);

    std::cout << "Canciones que tienes disponibles:\n";
    bank.showSongs();
    std::cout << "\n----------------------------------\n";

    // Añadimos canciones
    std::cout << "Canciones Agregadas:\n";
    bank.addSong(song3);
    bank.addSong(song4);
    bank.addSong(song10);
    bank.addSong(song7);
    bank.addSong(song8);
    bank.showSongs();
    std::cout << "\n----------------------------------\n";

    // Ordenamos las canciones por nombre
    std::cout << "Organizando tu Banco de Canciones\n";
    bank.sortByName();
    bank.showSongs();
    std::cout << "\n----------------------------------\n";

    // Eliminamos una canción existente
    std::cout << "Eliminando 'Imagine'\n";
    bank.deleteSong("Imagine");
    bank.showSongs();
    std::cout << "\n----------------------------------\n";

    // Intentamos eliminar una que no existe
    std::cout << "Intentando eliminar 'Nothing Else Matters'...\n";
    bank.deleteSong("Nothing Else Matters");
    std::cout << "\n----------------------------------\n";

    // Mostramos el resultado final
    std::cout << "Banco final de canciones:\n";
    bank.showSongs();

    return 0;
}

