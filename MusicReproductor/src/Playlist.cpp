#include "Playlist.h"
#include <iostream>

// --- Constructor del nodo ---
Playlist::Node::Node(const Song& _data)
    : data(_data), next(nullptr), prev(nullptr) {}

// --- Constructor de la playlist ---
Playlist::Playlist() : head(nullptr), size(0) {}

// --- Destructor ---
Playlist::~Playlist() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

//Verifica si la canción está en el banco
bool Playlist::inSongBank(const std::string& song, const SongBank& sb) {
    const auto& songs = sb.getSongs(); // obtener referencia para no copiar
    for (const auto& s : songs) {
        if (s.getName() == song) {
            return true;
        }
    }
    return false;
}


//Verifica si la playlist está vacía
bool Playlist::isEmpty() const {
    return head == nullptr;
}

//Añadir canción a la playlist
void Playlist::addSong(const Song& song, const SongBank& sb) {
    if (!inSongBank(song.getName(), sb)) {
        std::cout << "La cancion no se encuentra en el banco indicado.\n";
        return;
    }

    Node* newNode = new Node(song);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    size++;
    std::cout << "Se añadio '" << song.getName() << "' a la playlist.\n";
}

//Eliminar canción de la misma playlist (Redundante duh)
void Playlist::deleteSong(const std::string& name) {
    if (isEmpty()) {
        std::cout << "La playlist está vacia.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data.getName() != name) { //* El borrado se hace a traves del nombre/
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "No se encontro la canción '" << name << "'.\n";
        return;
    }

    // Se actualizan los punteros para que la lista siga unida
    if (prev == nullptr) {
        head = temp->next;
        if (head) head->prev = nullptr;
    } else {
        prev->next = temp->next;
        if (temp->next) temp->next->prev = prev;
    }

    delete temp;
    size--;
    std::cout << "Se elimino '" << name << "' de la playlist.\n";
}

// Este realiza una impresion de la playlist, mientras la recorre
void Playlist::showPlaylist() const {
    if (isEmpty()) {
        std::cout << "La playlist está vacia.\n";
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

// Obtenemos el tamaño de la playlist
int Playlist::getSize() const {
    return size;
}

// Metodo que permite regresar en la playlist, por esto es doblemente encadenada
void Playlist::goBack(const std::string& name) const {
    Node* temp = head;
    while (temp && temp->data.getName() != name) {
        temp = temp->next;
    }
    if (temp && temp->prev) {
        temp->prev->data.info();
    } else {
        std::cout << "No hay una cancion anterior.\n";
    }
}

// Metodo que accede a la siguiente Cancion
void Playlist::goForward(const std::string& name) const {
    Node* temp = head;
    while (temp && temp->data.getName() != name) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        temp->next->data.info();
    } else {
        std::cout << "No hay una cancion siguiente.\n";
    }
}

// Este metodo recorre toda la Playlist, y "Reproduce", las canciones
void Playlist::playAll() const {
    if (isEmpty()) {
        std::cout << "No hay canciones para reproducir.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "Reproduciendo la cancion: ";
        temp->data.info();
        temp = temp->next;
    }
}

