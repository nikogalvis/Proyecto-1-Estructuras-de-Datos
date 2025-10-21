# Proyecto-1-Estructuras-de-Datos (Simulador reproductor de Musica)
Simulador de un reproductor de musica que use arreglos, colas, y colas circulares.

### Información Previa
Se opta el proyecto de un pseudoreproductor de musica, que imite la interfaz de un reproductor de musica, con funciones de almacenamiento de arreglo dinamico, mantener una playlist con una lista doblemente encandenada, y simular su recorrido en una Cola Circular, dado que en una playlist al llegar a la ultima canción, vuelve al inicio. 

### Características
El programa permite al usuario crear un banco con las canciones que prefiera especificando sus características. Luego puede crear una playlist, visualizarla y modificar su contenido, además de avanzar o retroceder entre canciones al reproducirse.

### Librerias Usadas (Rectifiquemos esto constantemente negros)
``` C++
#include <iostream> //*Permite las operaciones de [input/output] */
#include <vector> //* Es un arreglo dinamico que tiene c++ por default*/
#include <algorithm> //* Esta libreria tiene como funcionalidad organizar arreglos*/
#include <string> //* Funcionalidad de la clase string (std::string)*/

#include "imgui.h" //*Incluye los archivos referentes a IMGUI, la libreria que permite interfaces graficas*/
#include "backends/imgui_impl_glfw.h" //*Conecta con la librería de GLFW, la cual permite la interacción con los distintos
inputs de teclado y mouse, además de permitir crear ventanas/
#include "backends/imgui_impl_opengl3.h" //*Conecta Imgui con OpenGl, Este es el API de los graficos/

```
### Instalaciones previas
Hemos tenido varios problemas de compatibilidad, por lo tanto se dejara la lista de requisitos que nos han servido para que el programa corra

1. Compilador g++, version 15.2.0 (Usando MinGW-w64)
2. Definir el Path de Variables de Entorno en Windows 
3. Compiladores de GLFW, OPENGL y GLEW.

``` C++
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-glfw mingw-w64-x86_64-glew
```

4. Instalar el .zip de Imgui, el cual se encuentra en la web
5. Dentro de Visual Studio Code, asegurarse que se este compilando con la ruta del MingW64
6. Dentro de Visual Studio Code, usar el comando (Ctrl + Shft + Ñ) Para abrir la terminal.
7. Usar el comando para compilar los archivos (Verificar que no haya otro  .exe)
```
g++ src/*.cpp imgui/*.cpp imgui/backends/*.cpp -Iinclude -Iimgui -Iimgui/backends -lglfw3 -lopengl32 -lgdi32 -o music_gui.exe
```
Con esto queda Todo el programa instalado

### Uso del programa
Las instrucciones para el correcto manejo de este reproductor están indicadas en el Manual de Usuario correspondiente, disponible dentro de este mismo repositorio.

### Estructura
El proyecto ha sido desarrollado con la siguiente estructura:

#### MusicReproductor
* imgui
  * backends
    * imgui_impl_glfw.cpp
    * imgui_impl_glfw.h
    * imgui_impl_opengl3.cpp
    * imgui_impl_opengl3.h
  * imconfig.h
  * imgui.cpp
  * imgui.h
  * imgui_draw.cpp
  * imgui_impl_opengl3_loader.h
  * imgui_internal.h
  * imgui_tables.cpp
  * imgui_widgets.cpp
  * imstb_rectpack.h
  * imstb_textedit.h
  * imstb_truetype.h
* include
  * CircularPlaylist.h
  * Playlist.h
  * Song.h
  * SongBank.h
  * gui.h
* src
  * CircularPlaylist.cpp
  * Playlist.cpp
  * Song.cpp
  * SongBank.cpp
  * g++
  * gui.cpp
  * main_imgui.cpp
* imgui.ini
* music_gui.exe

#### Descripción
* imgui ayuda dando soporte a la interfaz del programa
* include contiene los headers necesarios, en dónde se encuentran cada uno de los "¿Qué?" de cada método
* src contiene los archivo de C++ que indican los "¿Cómo?" de dichos métodos
* imgui.ini se utiliza para guardar la configuración de las interfaz entre ejecuciones del programa
* music_gui.exe es el archivo ejecutable listo para ser utilizado por el usuario

### Créditos
* **Nicolás Steven Galvis Ordóñez**
* **Andrés Arturo Lozano Olivares**
* **Angel Santiago Flórez Rozo**
  
*Estudiantes de Ingeniería de Sistemas y Computación, Universidad Nacional de Colombia*
