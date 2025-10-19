#include "Playlist.h"

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

// --- Verifica si la canción está en el banco ---
bool Playlist::inSongBank(std::string song, const SongBank& sb) {
    for (int i = 0; i < sb.getSongs().size(); i++) {
        if (song == sb.getSongs()[i].getName()) {
            return true;
        }
    }
    return false;
}

// --- Verifica si la playlist está vacía ---
bool Playlist::isEmpty() const {
    return head == nullptr;
}

// --- Añadir canción ---
void Playlist::addSong(const Song& song, const SongBank& sb) {
    if (!inSongBank(song.getName(), sb)) {
        std::cout << "La canción no se encuentra en el banco indicado\n";
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
    std::cout << "Se añadió '" << song.getName() << "' a la playlist.\n";
}

// --- Eliminar canción ---
void Playlist::deleteSong(const std::string& name) {
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

// --- Mostrar playlist ---
void Playlist::showPlaylist() const {
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

// --- Obtener tamaño ---
int Playlist::getSize() const {
    return size;
}

// --- Canción anterior ---
void Playlist::goBack(const std::string& name) const {
    Node* temp = head;
    while (temp && temp->data.getName() != name) {
        temp = temp->next;
    }
    if (temp && temp->prev) {
        temp->prev->data.info();
    } else {
        std::cout << "No hay una canción anterior.\n";
    }
}

// --- Canción siguiente ---
void Playlist::goForward(const std::string& name) const {
    Node* temp = head;
    while (temp && temp->data.getName() != name) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        temp->next->data.info();
    } else {
        std::cout << "No hay una canción siguiente.\n";
    }
}

// --- Reproducir todas ---
void Playlist::playAll() const {
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
