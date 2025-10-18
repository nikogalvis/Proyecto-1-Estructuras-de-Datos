#include "Song.h"
#include "SongBank.h"

int main() {
    Song s1("From the Start", "Good Kid", 184, "Indie");
    Song s2("Bohemian Rhapsody", "Queen", 354, "Rock");
    Song s3("Clocks", "Coldplay", 307, "Alternative");
    Song s4("After Dark", "Mr.Kitty", 242, "Synthwave");

    SongBank bank({s1, s2, s3});
    bank.addSong(s4);

    std::cout << "\n--- Lista de canciones (sin ordenar) ---\n";
    bank.showSongs();

    std::cout << "\n--- Lista ordenada alfabeticamente ---\n";
    bank.sortByName();
    bank.showSongs();

    std::cout << "\n--- Eliminamos 'Clocks' ---\n";
    bank.deleteSong("Clocks");

    std::cout << "\n--- Lista final ---\n";
    bank.showSongs();

    return 0;
}
