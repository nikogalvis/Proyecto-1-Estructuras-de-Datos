/* este archivo contiene todo el codigo para ser capazes de manipularlo
 * mientras se decide si se hace por modulos o no
*/ 

#include <iostream>
#include <vector> //* Es un arreglo dinamico que tiene c++ por default*/
#include <algorithm>
#include <chrono>

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
  //También puede ser útil para llevar el hilo de hasta donde funciona todo si ocurre algo inesperado
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

  std::vector<Song> getSongs() const{
    return songs;
  }

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



class Playlist {

// Todo esto es intocable para el usuario
private:

    /* Canciones a modo de lista simplemente encadenada por medio de nodos con valor propio (data) y apuntador al siguiente nodo (next)
    const es útil para indicar que el dato no cambia. Song& está referenciando a su parte _data. nullptr es una constante que sirve
    para representar un puntero nulo. */
    struct Node {
        Song data;
        Node* next;
        Node* prev;
        Node(const Song& _data) : data(_data), next(nullptr), prev(nullptr) {}
    };

    // Apuntador a la cabeza y tamaño de la playlist
    Node* head;
    int size;

// Y esto es aquello con lo que el usuario puede interactuar
public:
    // Se crea una playlist nueva (cabeza nula y tamaño 0)
    Playlist() : head(nullptr), size(0) {}

    bool inSongBank(std::string song, const SongBank& sb) {
        for(int i = 0; i < sb.getSongs().size(); i++){
            if(song == sb.getSongs()[i].getName()){
                return true;
            }
        return false;
        }
    };

    // ¿La cabeza tiene un valor nulo? Sí/No
    bool isEmpty() const {
        return head == nullptr;
    }

    /* Referencia al parámetro song como atributo de Song, crea un nuevo nodo para dicha canción y le asigna un apuntador.
    Si la cabeza es un apuntador nulo, la nueva canción se convierte en la cabeza.
    Si no, crea un apuntador temporal que apunta a la cabeza actual y, mientras el nodo siguiente no tenga un valor nulo,
    reasigna temp a dicho nodo siguiente. Cuando se rompa esa condición, le asigna al nodo actual en su apuntador siguiente
    el nuevo nodo. Por último, incrementa el tamaño e imprime el mensaje confirmando que se añadió la canción indicada. */
    void addSong(const Song& song, const SongBank& sb) {
        if(!inSongBank(song.getName(), sb)){
            std::cout << "La canción no se encuentra en el banco indicado";
            return;
        }
            Node* newNode = new Node(song);
            if (isEmpty()) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
            }
            size++;
            std::cout << "Se añadió '" << song.getName() << "' a la playlist.\n";
        }
    

    /* Referencia al parámetro name como dato de tipo string constante.
    Si la cabeza es nula, la playlist está vacía (¿Qué chucha piensas eliminar?).
    Si no, crea dos apuntadores: Uno temporal que apunta a la cabeza y uno previo que es nulo.
    Mientras el valor del temporal no sea nulo y el nombre obtenido de la parte data del mismo no sea el nombre buscado,
    reasigna a previo con el valor de temporal, y a temporal con el valor de su siguiente nodo.
    Al romperse la condición del ciclo verifica:
    1) Si temporal es nulo, la canción buscada no está en la playlist, de modo que no se puede eliminar
    2) Si no:
    2.1) Si previo es nulo, reasigna la cabeza con el valor del siguiente nodo
    2.2) Si no, reasigna el siguiente de previo con el valor del siguiente de temporal
    Después de 2), elimina el temporal, reduce el tamaño e imprime el mensaje confirmando que se eliminó la canción indicada. */
    void deleteSong(const std::string& name) {
        if (isEmpty()) {
            std::cout << "La playlist está vacía.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data.getName() != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "No se encontró la canción '" << name << "'.\n";
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        size--;
        std::cout << "Se eliminó '" << name << "' de la playlist.\n";
    }

    /* Verifica si la playlist está vacía (alias cabeza nula).
    Si no, crea un apuntador temporal y lo asigna a la cabeza; luego, crea un entero y lo inicializa en 1.
    Mientras temporal no sea nulo, imprime el índice de la canción en la lista, obtiene la información de
    la parte data del mismo nodo (imprimiéndola dada la definición de esta función), y reasigna a temporal
    con el valor de su siguiente nodo. */
    void showPlaylist() const {
        if (isEmpty()) {
            std::cout << "La playlist está vacía.\n";
            return;
        }

        Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            std::cout << i++ << ". ";
            temp->data.info();
            temp = temp->next;
        }
    }

    // ¿Debo explicar esto?
    int getSize() const {
        return size;
    }

    void goBack(const std::string& name) const{
        Node* temp = head;
        while (temp && temp->data.getName() != name) {
            temp = temp->next;
        if(temp->prev){
            temp->prev->data.info();
        } else {
            std::cout << "No hay una canción anterior.\n";
        }
        }
    }

    void goForward(const std::string& name) const{
        Node* temp = head;
        while (temp && temp->data.getName() != name) {
            temp = temp->next;
        if(temp->next){
            temp->next->data.info();
        } else {
            std::cout << "No hay una canción siguiente.\n";
        }
        }
    }
        
    /* Esto es prácticamente lo mismo que la función showPlaylist, con la única diferencia de que
    busca simular de forma muy básica a un "Reproducir" por medio de un mensaje que lo indica. */
    void playAll() const {
        if (isEmpty()) {
            std::cout << "No hay canciones para reproducir.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "Reproduciendo la canción: ";
            
            temp->data.info();
            temp = temp->next;
        }
    }

    /* Este son los aviones, y la playlist son las torres gemelas.
    De nuevo temporal nos ayuda a recorrer la lista, en este caso para
    que nos lo andemos macheteando cada que cambia de identidad. */
    ~Playlist() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
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

