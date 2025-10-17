#include <iostream>
#include "SongBank.cpp" // Esto es simplemente para indicar que, en caso de hacerse por módulos, debe importar SongBank de SongBank.cpp

class Playlist {

// Todo esto es intocable para el usuario
private:

    /* Canciones a modo de lista simplemente encadenada por medio de nodos con valor propio (data) y apuntador al siguiente nodo (next)
    const es útil para indicar que el dato no cambia. Song& está referenciando a su parte _data. nullptr es una constante que sirve
    para representar un puntero nulo. */
    struct Node {
        Song data;
        Node* next;
        Node(const Song& _data) : data(_data), next(nullptr) {}
    };

    // Apuntador a la cabeza y tamaño de la playlist
    Node* head;
    int size;

// Y esto es aquello con lo que el usuario puede interactuar
public:
    // Se crea una playlist nueva (cabeza nula y tamaño 0)
    Playlist() : head(nullptr), size(0) {}

    bool inSongBank(std::string song, Songbank& sb) {
        s = False;
        for(i = 0; i < sb.songs.size(); i++){
            if(song == sb.songs[i].getName()){
                s = True;
            }
        return s;
        }
    }

    // ¿La cabeza tiene un valor nulo? Sí/No
    bool isEmpty() const {
        return head == nullptr;
    }

    /* Referencia al parámetro song como atributo de Song, crea un nuevo nodo para dicha canción y le asigna un apuntador.
    Si la cabeza es un apuntador nulo, la nueva canción se convierte en la cabeza.
    Si no, crea un apuntador temporal que apunta a la cabeza actual y, mientras el nodo siguiente no tenga un valor nulo,
    reasigna temp a dicho nodo siguiente. Cuando se rompa esa condición, le asigna al nodo actual en su apuntador siguiente
    el nuevo nodo. Por último, incrementa el tamaño e imprime el mensaje confirmando que se añadió la canción indicada. */
    void addSong(const Song& song) {
        Node* newNode = new Node(song);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
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

    /* Esto es prácticamente lo mismo que la función showPlaylist, con la única diferencia de que
    busca simular de forma muy básica a un "Reproducir" por medio de un mensaje que lo indica. */
    void playAll() const {
        if (isEmpty()) {
            std::cout << "No hay canciones para reproducir.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "🎧 Reproduciendo: ";
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




