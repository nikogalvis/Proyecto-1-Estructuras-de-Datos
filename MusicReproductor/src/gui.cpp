#include "gui.h"

GUI::GUI(SongBank& sb, CircularPlaylist& pl)
    : songBank(sb), playlist(pl) {}

void GUI::render() {
    ImGui::Begin("Music Player. by: Unal");

    static bool showSongBank = false;
    static bool showPlaylist = false;
    static std::string popupMsg = "";

    // ----- SECCIÓN SONGBANK -----
    if (ImGui::Button("------Mostrar SongBank------------")) {
        showSongBank = !showSongBank;
    }

    if (showSongBank) {
        ImGui::Separator();
        ImGui::Text("Canciones disponibles:");
        ImGui::Spacing();

        if (ImGui::Button("Ordenar alfabéticamente")) {
            songBank.sortByName();
        }

        ImGui::Spacing();

        auto songs = songBank.getSongs();
        if (songs.empty()) {
            ImGui::Text("No hay canciones en el banco.");
        } else {
            int index = 0;
            for (const auto& s : songs) {
                ImGui::PushID(index++);
                ImGui::Text("%s - %s (%s)",
                    s.getName().c_str(),
                    s.getArtist().c_str(),
                    s.getGenre().c_str());
                ImGui::SameLine();

                // ➕ Añadir a playlist
                if (ImGui::Button("+ Añadir a Playlist")) {
                    if (playlist.inSongBank(s.getName(), songBank)) {
                        playlist.addSong(s, songBank);
                        popupMsg = "✅ Se añadió '" + s.getName() + "' a la playlist.";
                        ImGui::OpenPopup("Added");
                    } else {
                        ImGui::OpenPopup("ErrorAdd");
                    }
                }

                ImGui::SameLine();

                // ❌ Eliminar del SongBank
                if (ImGui::Button("❌ Eliminar")) {
                    songBank.deleteSong(s.getName());
                    popupMsg = "🗑️ Se eliminó '" + s.getName() + "' del SongBank.";
                    ImGui::OpenPopup("Added");
                }

                ImGui::PopID();
            }
        }

        if (ImGui::BeginPopup("Added")) {
            ImGui::Text("%s", popupMsg.c_str());
            if (ImGui::Button("Cerrar")) ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }

        if (ImGui::BeginPopup("ErrorAdd")) {
            ImGui::Text("⚠️ La canción no está en el SongBank.");
            if (ImGui::Button("Cerrar")) ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }

        ImGui::Separator();
        ImGui::Text("+ Agregar nueva canción:");
        ImGui::Spacing();

        static char name[64] = "";
        static char artist[64] = "";
        static int duration = 0;
        static char genre[64] = "";

        ImGui::InputText("Nombre", name, IM_ARRAYSIZE(name));
        ImGui::InputText("Artista", artist, IM_ARRAYSIZE(artist));
        ImGui::InputInt("Duración (segundos)", &duration);
        ImGui::InputText("Género", genre, IM_ARRAYSIZE(genre));

        if (ImGui::Button("Agregar al SongBank")) {
            if (strlen(name) > 0 && strlen(artist) > 0 && duration > 0 && strlen(genre) > 0) {
                Song nueva(name, artist, duration, genre);
                songBank.addSong(nueva);
                popupMsg = "🎵 Se añadió '" + std::string(name) + "' al SongBank.";
                ImGui::OpenPopup("Added");
                name[0] = artist[0] = genre[0] = '\0';
                duration = 0;
            } else {
                ImGui::OpenPopup("Error");
            }
        }

        if (ImGui::BeginPopup("Error")) {
            ImGui::Text("⚠️ Todos los campos son obligatorios.");
            if (ImGui::Button("Cerrar")) ImGui::CloseCurrentPopup();
            ImGui::EndPopup();
        }
    }

    ImGui::Separator();

    // ----- SECCIÓN DE REPRODUCCIÓN -----
    ImGui::Text("Reproducción (Circular Playlist)");
    static std::string currentSong = "Bohemian Rhapsody";

    ImGui::Text("Reproduciendo: %s", currentSong.c_str());

    if (ImGui::Button("⏮ Canción anterior")) {
        std::string prev = playlist.goBack(currentSong);
        if (!prev.empty()) {
            currentSong = prev;
            popupMsg = "Reproduciendo: " + currentSong;
            ImGui::OpenPopup("Info");
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("⏭ Siguiente canción")) {
        std::string next = playlist.goForward(currentSong);
        if (!next.empty()) {
            currentSong = next;
            popupMsg = "Reproduciendo: " + currentSong;
            ImGui::OpenPopup("Info");
        }
    }

    if (ImGui::BeginPopup("Info")) {
        ImGui::Text("%s", popupMsg.c_str());
        if (ImGui::Button("Cerrar")) ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }

    ImGui::Separator();

    // ----- SECCIÓN PARA VER PLAYLIST -----
    if (ImGui::Button("🎶 Mostrar Playlist Circular")) {
        showPlaylist = !showPlaylist;
    }

    if (showPlaylist) {
        ImGui::Separator();
        ImGui::Text("Playlist actual:");
        ImGui::Spacing();

        auto list = playlist.getSongs();

        if (list.empty()) {
            ImGui::Text("La playlist está vacía.");
        } else {
            int idx = 0;
            for (const auto& s : list) {
                ImGui::PushID(idx++);
                ImGui::Text("%d. %s - %s (%s)",
                    idx,
                    s.getName().c_str(),
                    s.getArtist().c_str(),
                    s.getGenre().c_str());
                ImGui::SameLine();
                if (ImGui::Button("❌ Quitar")) {
                    playlist.deleteSong(s.getName());
                    popupMsg = "🗑️ Se quitó '" + s.getName() + "' de la playlist.";
                    ImGui::OpenPopup("Added");
                }
                ImGui::PopID();
            }
        }
    }

    ImGui::End();
}
