#ifndef GUI_H
#define GUI_H

//* Tomamos las librerias que se usaran para la vista usuario*/
#include "SongBank.h"
#include "CircularPlaylist.h"
#include "imgui.h"


//*Esta sección fue echa con ayuda de la IA*/

//* Esta es la "Promesa de valor" que hace el .h informando que cosas puede hacer el gui/
//* Le da los atributos songbank y playlist, y la funcion renderizar/
class GUI {
private:
    SongBank& songBank;
    CircularPlaylist& playlist;

public:
    GUI(SongBank& sb, CircularPlaylist& pl);
    void render();
};

#endif
