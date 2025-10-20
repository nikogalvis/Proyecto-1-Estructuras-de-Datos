#include "CircularPlaylist.h"

CircularPlaylist::Node::Node(const Song& _data)
    : data(_data), next(nullptr), prev(nullptr) {}

CircularPlaylist::CircularPlaylist() : head(nullptr), size(0) {}

bool CircularPlaylist::isEmpty() const {
    return head == nullptr;
}

bool CircularPlaylist::inSongBank(const std::string& song, const SongBank& sb) const {
    for (int i = 0; i < sb.getSongs().size(); i++) {
        if (song == sb.getSongs()[i].getName())
            return true;
    }
    return false;
}

void CircularPlaylist::addSong(const Song& song, const SongBank& sb) {
    if (!inSongBank(song.getName(), sb)) {
        std::cout << "La cancion no se encuentra en el banco indicado.\n";
        return;
    }

    Node* newNode = new Node(song);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    size++;
    std::cout << "Se añadio '" << song.getName() << "' a la playlist.\n";
}

void CircularPlaylist::deleteSong(const std::string& name) {
    if (isEmpty()) {
        std::cout << "La playlist está vacia.\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->data.getName() == name) {
            if (temp->next == temp) {
                // Solo un nodo
                delete temp;
                head = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                delete temp;
            }
            size--;
            std::cout << "Se elimino '" << name << "' de la playlist.\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    std::cout << "No se encontro la canción '" << name << "'.\n";
}

void CircularPlaylist::showPlaylist() const {
    if (isEmpty()) {
        std::cout << "La playlist está vacia.\n";
        return;
    }

    Node* temp = head;
    int i = 1;
    do {
        std::cout << i++ << ". ";
        temp->data.info();
        temp = temp->next;
    } while (temp != head);
}

std::string CircularPlaylist::goForward(const std::string& name) const {
    if (isEmpty()) return "";

    Node* temp = head;
    do {
        if (temp->data.getName() == name) {
            return temp->next->data.getName();
        }
        temp = temp->next;
    } while (temp != head);

    return ""; // no encontrada
}

std::string CircularPlaylist::goBack(const std::string& name) const {
    if (isEmpty()) return "";

    Node* temp = head;
    do {
        if (temp->data.getName() == name) {
            return temp->prev->data.getName();
        }
        temp = temp->next;
    } while (temp != head);

    return "";
}

void CircularPlaylist::playAll() const {
    if (isEmpty()) {
        std::cout << "No hay canciones para reproducir.\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << "Reproduciendo: ";
        temp->data.info();
        temp = temp->next;
    } while (temp != head);
}

int CircularPlaylist::getSize() const {
    return size;
}

std::vector<Song> CircularPlaylist::getSongs() const {
    std::vector<Song> list;

    if (isEmpty()) return list;

    Node* temp = head;
    do {
        list.push_back(temp->data);
        temp = temp->next;
    } while (temp != head);

    return list;
}



CircularPlaylist::~CircularPlaylist() {
    if (isEmpty()) return;

    Node* temp = head->next;
    while (temp != head) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    delete head;
}
