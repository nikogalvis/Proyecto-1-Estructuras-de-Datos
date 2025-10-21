# Manual de Usuario Simulador Reproductor de Música
A continuación se muestran las instrucciones de uso del programa diseñado.

## Requisitos
Aunque estos ya esten explicados en el README, se vuelven a aclarar aqui, puesto que son necesarios para el correcto funcionamiento de la aplicación

Hemos tenido varios problemas de compatibilidad, por lo tanto se dejará la lista de requisitos que nos han servido para que el programa corra:

1. Compilador g++, versión 15.2.0 (Usando MinGW-w64)
2. Definir el Path _"C:\msys64\mingw64\bin"_ de Variables de Entorno en Windows 
3. Compiladores de GLFW, OPENGL y GLEW. (En la terminal Mingw64)

_(El compilador OPENGL viene dentro de el propio Windows)_

``` C++
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-glfw mingw-w64-x86_64-glew
```

4. Instalar el .zip de Imgui, el cual se encuentra en la web
-"_https://github.com/ocornut/imgui_"

5. Descargar esta carpeta, para un correcto funcionamiento posicionarse en la carpeta MusicReproductor
6. Dentro de Visual Studio Code, asegurarse que se esté compilando con la ruta del MingW64
7. Dentro de Visual Studio Code, usar el comando (Ctrl + Shft + Ñ) Para abrir la terminal.
8. Usar el comando para compilar los archivos (Verificar que no haya otro  .exe)
   
``` C++
g++ src/*.cpp imgui/*.cpp imgui/backends/*.cpp -Iinclude -Iimgui -Iimgui/backends -lglfw3 -lopengl32 -lgdi32 -o music_gui.exe
```
Luego de seguir estos pasos, queda listo el programa, para abrirlo, se debe ejecutar uno de los siguientes comandos:
```C++
.\music_gui.exe
```
En caso de que este comando no funcione, se debe usar:
```C++
music_gui.exe
```

Con esto, debería abrir la interfaz del programa, y podemos pasar a la funcionalidad del mismo


<img width="799" height="646" alt="Captura de pantalla 2025-10-20 213902" src="https://github.com/user-attachments/assets/b6825cc5-6135-4348-9113-69318e085faf" />

Se abrirá la ventana que se muestra en la imagen, con un SongBank predeterminado, y dos botones de "Mostrar".

### Mostrar SongBank
<img width="801" height="642" alt="Captura de pantalla 2025-10-20 214353" src="https://github.com/user-attachments/assets/b3d69ce0-015b-46aa-962f-cd3bad2fa648" />

Una vez presionado este botón, se abrirán dos campos, uno que muestra el Banco de Canciones con todas las canciones disponibles, y un apartado para agregar canciones que el usuario quiera.
Las canciones del SongBank se pueden agregar a la Playlist, o eliminar del banco de canciones, mientras que en el apartado de canciones, hay un único botón para agregarla al Banco de Canciones **_[Para agregar una canción se requiere de llenar los 4 campos, de lo contrario saltará un mensaje de error]_**


### Ejemplo de agregado de canción

<img width="804" height="644" alt="Captura de pantalla 2025-10-20 214903" src="https://github.com/user-attachments/assets/41f097e1-3632-41ee-a8c1-43e17aa2b5e2" />

_Ejemplo de una canción siendo añadida al SongBank_

Una vez se llenan los campos de la canción, se oprime el botón de agregar al SongBank, lo cual permitirá} agregarlo a la Playlist, para visualizar la playlist, se usa el botón de "Mostrar Playlist", lo que nos deja ver que canciones hemos añadido a la misma.


<img width="797" height="639" alt="Captura de pantalla 2025-10-20 221737" src="https://github.com/user-attachments/assets/2d425778-394b-4874-8376-27491c02573a" />

De esta manera se ve la playlist, sabiendo que canciones se pueden reproducir en la CircularPlaylist, la Playlist se implemento como lista por la facilidad que tiene para eliminar y agregar canciones, de forma rápida.

Por  último, los botones de canción siguiente y canción anterior, para funcionar, se debe hallar en la Playlist la canción que se esta reproduciendo actualmente, a partir de ahi, cualquier  canción que agregues será recorrible, y  cuando llegues a la última, volverás a la primera canción de la Playlist




