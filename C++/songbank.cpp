#include <iostream>
#include <vector> //* Es un arreglo dinamico que tiene c++ por default*/
#include <algorithm>

/* Clase base, para crear despues una lista de canciones
  *Los atributos es para organizarlos de distintas  maneras
  *Si lo vemos complejo, lo dejamos solo para Alfabeticamente
  */

class Song{

  private:
    std::string name;
    std::string artist;
    int duration; //? La duración la plantee para que sean segundos (Lo cambio?) */
    //Angel - Nah, creo que está bien, así no nos complicamos
    std::string genre;
  
  public:

  //* Constructor, y funciones para ver atributos */
  Song(std::string _name, std::string _artist, int _duration, std::string _genre){
    name = _name;
    artist = _artist;
    duration = _duration;
    genre = _genre;
  };

  std::string getName() const{
    return name;
  };

  std::string getArtist() const{
    return artist;
  };

  int getDuration() const{
    return duration;
  };

  std::string getGenre() const{
    return genre;
  };

  //* Este es el equivalente del __str__ creo, para que lo veamos en prints*/
  //También puede ser útil para llevar la cuerda de hasta donde funciona todo si ocurre algo inesperado
  void info() const{
    std::cout<<"Name: "<< name << ", Author(s): " << artist << ", Genre: "<< genre << std::endl;
  };

};

class SongBank{
  private:
    std::vector<Song> songs;

  public:
    
  SongBank(std::vector<Song> _songs){
    songs = _songs;
  };

  void addSong(const Song& new_song){
    songs.push_back(new_song);
  };

  void deleteSong(std::string song){
    for(int i = 0; i < songs.size(); i++)
      if(songs[i].getName() == song){
        songs.erase(songs.begin() + i);
        std::cout << "Se elimino la cancion" << song << std::endl;  
          break;
      }
  };

  void sortByName(){
    std::sort(songs.begin(), songs.end(),
        [](const Song& a, const Song& b) {
            return a.getName() < b.getName();
        });
  };

  void showSongs() const{
    if (songs.empty()) {
      std::cout << "There's no songs";
      return;
    }

    for (int i = 0; i < songs.size(); i++){
      std::cout << i + 1 << " // ";
      songs[i].info();
    };
    
  };
};

int main() {
    // Creamos algunas canciones
    Song s1("From the Start", "Good Kid", 184, "Indie");
    Song s2("Bohemian Rhapsody", "Queen", 354, "Rock");
    Song s3("Clocks", "Coldplay", 307, "Alternative");
    Song s4("After Dark", "Mr.Kitty", 242, "Synthwave");

    // Creamos el banco y agregamos las canciones
    SongBank bank({s1, s2, s3});
    bank.addSong(s4);

    std::cout << "\n--- Lista de canciones (sin ordenar) ---\n";
    bank.showSongs();

    // Ordenamos alfabéticamente
    std::cout << "\n--- Lista ordenada alfabeticamente ---\n";
    bank.sortByName();
    bank.showSongs();

    // Eliminamos una canción
    std::cout << "\n--- Eliminamos 'Clocks' ---\n";
    bank.deleteSong("Clocks");

    std::cout << "\n--- Lista final ---\n";
    bank.showSongs();

    return 0;
}

