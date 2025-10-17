# Proyecto-1-Estructuras-de-Datos (Simulador reproductor de Musica)
Simulador de un reproductor de musica que use arreglos, listas, pilas y colas.

### Información Previa
Se opta por recrear una aplicacion de reproduccion de canciones ya dadas por el sistema, es decir, canciones guardadas internamente en el dispositivo en el que se reproduce, siendo este programa una aproximación a Lark Player, más que a spotify u otras aplicaciones que funcionan por medio de internet.

### Librerias Usadas (Rectifiquemos esto constantemente negros)
``` C++
#include <iostream> 
#include <vector> //* Es un arreglo dinamico que tiene c++ por default*/
#include <algorithm>
```

## Clase Song
Se parte de una clase "Song", siendo esta la base del programa, añadimos los atributos que consideramos pertinentes para la aplicación, de forma privada, puesto que no queremos que el usuario cambie estos atributos. Se definen los getters para poder ver esta información de manera individual. Por ultimo, se le añade el metodo "info" para poder ver la información de la canción, de manera organizada. 

``` C++
class Song{

  private:
    std::string name;
    std::string artist;
    int duration; //? La duración la plantee para que sean segundos.
  
  public:

  //* Constructor, getters, no son necesarios los setters puesto que uno no cambia el contenido de la canción */
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
  //También puede ser útil para llevar el hilo de hasta donde funciona todo si ocurre algo inesperado
  void info() const{
    std::cout<<"Name: "<< name << ", Author(s): " << artist << ", Genre: "<< genre << std::endl;
  };

};

``` 

Una vez se define esta clase, se empieza a crear la clase "SongBank", un arreglo dinamico que contiene todas las canciones que la aplicación puede reproducir. Se inicia haciendo uso de la biblioteca <vector>, la cual actua como un arreglo dinamico, y hacemos uso de ella para dar el atributo "songs". De forma privada, creamos dos metodos que permitan, añadir una canción, y otro que permita borrar canciones por nombre., como es un arreglo dinamico, el espacio consumido se ajusta en la misma medida en la que se añaden/borran canciones (Aunque no estamos seguros si tiene la mejora del numero aureo)

Además, se le añade un metodo para que organice las canciones alfabeticamente, lo que facilita la busqueda de las mismas, por ultimo un metodo que permite observar todo el banco de canciones.

``` C++
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


```
