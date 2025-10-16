#include <iostream>
#include "SongBank.cpp" //Esto es simplemente para indicar que, en caso de hacerse por módulos, debe importar SongBank de SongBank.cpp

class Playlist {
private:
    struct Node {
        Song data;
        Node* next;
        Node(const Song& _data) : data(_data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    Playlist() : head(nullptr), size(0) {}

    bool isEmpty() const {
        return head == nullptr;
    }

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

    int getSize() const {
        return size;
    }

    // Puedes agregar esto más adelante para simular reproducción
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

    ~Playlist() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

