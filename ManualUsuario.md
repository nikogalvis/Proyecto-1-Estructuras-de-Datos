# Manual de Usuario Simulador Reproductor de Musica
A continuación se muestran las instrucciones de uso del programa diseñado.

## Requisitos
Aunque estos ya esten explicados en el README, se vuelven a aclarar aqui, puesto que son necesarios para el correcto funcionamiento de la aplicación

Hemos tenido varios problemas de compatibilidad, por lo tanto se dejara la lista de requisitos que nos han servido para que el programa corra:

1. Compilador g++, version 15.2.0 (Usando MinGW-w64)
2. Definir el Path _"C:\msys64\mingw64\bin"_ de Variables de Entorno en Windows 
3. Compiladores de GLFW, OPENGL y GLEW.

``` C++
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-glfw mingw-w64-x86_64-glew
```

4. Instalar el .zip de Imgui, el cual se encuentra en la web
5. Descargar esta carpeta, para un correcto funcionamiento posicionarse en la carpeta MusicReproductor
6. Dentro de Visual Studio Code, asegurarse que se este compilando con la ruta del MingW64
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

Con esto, deberia abrir la interfaz del programa, y podemos pasar a la funcionalidad del mismo


<img width="799" height="646" alt="Captura de pantalla 2025-10-20 213902" src="https://github.com/user-attachments/assets/b6825cc5-6135-4348-9113-69318e085faf" />

Se abrira la ventana que se muestra en la imagen, con un SongBank predeterminado, y dos botones de "Mostrar".

### Mostrar SongBank
<img width="801" height="642" alt="Captura de pantalla 2025-10-20 214353" src="https://github.com/user-attachments/assets/b3d69ce0-015b-46aa-962f-cd3bad2fa648" />

Una vez presionado este boton, se abriran dos campos, uno que muestra el Banco de Canciones con todas las canciones disponibles, y un apartado para agregar canciones que el usuario quiera.
Las canciones del SongBank se pueden agregar a la Playlist, o eliminar del banco de canciones, mientras que en el apartado de canciones, hay un unico boton para agregarla al Banco de Canciones **_[Para agregar una cancion se requiere de llenar los 4 campos, de lo contrario saltara un mensaje de error]_**


### Ejemplo de agregado de cancion

<img width="804" height="644" alt="Captura de pantalla 2025-10-20 214903" src="https://github.com/user-attachments/assets/41f097e1-3632-41ee-a8c1-43e17aa2b5e2" />

_Ejemplo de una cancion siendo añadida al SongBank_

Una vez se llenan los campos de la canción, se oprime el boton de agregar a la Playlist, lo cual permitira su paso por el reproductor de musica, para visualizar la playlist, se usa el boton de "Mostrar Playlist", lo que nos lleva






