# Proyecto Equipo de Fútbol
Este proyecto está desarrollado como referencia para los alumnos de TC1030. Modela la estructura de un equipo de fútbol profesional, permitiendo registrar jugadores de distintas posiciones (delantero, medio, defensa y portero), cada uno con sus propios atributos y lógica de cálculo de puntos.
El programa implementa una jerarquía de clases con una clase abstracta Jugador y clases derivadas que representan los diferentes tipos de jugadores. También se cuenta con una clase Equipo que gestiona la composición del equipo y la información de su entrenador.

### Funcionalidad
El programa permite realizar las siguientes acciones desde un menú en consola:
Agregar nuevos jugadores al equipo (si no se ha alcanzado la capacidad máxima)
Mostrar la información completa del equipo y los puntos obtenidos por cada jugador
Salir del programa
Cada jugador tiene atributos como nombre, número, edad, minutos jugados y si es titular. Además, cada posición tiene atributos adicionales como:
Delantero: goles anotados
Medio: asistencias
Defensa: recuperaciones
Portero: atajadas
El puntaje de cada jugador se calcula según su posición y desempeño.

El programa deja de funcionar si no se usan comandos para incluir la clase madre, si se le ingresa una variable que no sea del tipo que pide, si los métodos no se implementan de forma correcta, si no se incluyen ciertas librerías, si se intenta agregar un jugador y el equipo está lleno, etc.

### Consideraciones
El programa corre en consola y está hecho en C++ estándar, por lo que puede ejecutarse en cualquier sistema operativo.
Utiliza programación orientada a objetos con herencia, clases abstractas y polimorfismo.
La capacidad del equipo y los datos del entrenador se ingresan al inicio del programa.
Se cargan automáticamente 4 jugadores iniciales al arrancar el programa, uno por cada posición.
### Compilacion
g++ equipo.cpp -o ./equipo.exe

./equipo.exe

