# Proyecto-1-Estructuras-de-Datos (Simulador reproductor de Musica)
Simulador de un reproductor de musica que use arreglos, colas, y colas circulares.

### Información Previa
Se opta el proyecto de un pseudoreproductor de musica, que imite la interfaz de un reproductor de musica, con funciones de almacenamiento de arreglo dinamico, mantener una playlist con una lista encandenada, y simular su recorrido en una Cola Circular, dado que en una playlist al llegar a la ultima canción, vuelve al inicio. 

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
5. Dentro de Visual Studio Code, usar el comando (Ctrl + Shft + Ñ) Para abrir la terminal.
6. Usar el comando para compilar los archivos (Verificar que no haya otro  .exe)
```

```
7. Ejecutar el codigo .\music_gui.exe o music_gui.exe
