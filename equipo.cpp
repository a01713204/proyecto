#include "equipo.h"
#include "jugador.h"

int main() {
    // Crear un equipo con capacidad para 5 jugadores
    Equipo equipo(250000000, "Diego Simeone", 5);

    // Crear jugadores de diferentes posiciones
    Jugador* delantero1 = new Delantero("Luis Suárez", 9, 35, 480, "sí", 18);
    Jugador* medio1 = new Medio("Koke", 6, 30, 520, "sí", 9);
    Jugador* defensa1 = new Defensa("José Giménez", 2, 27, 500, "sí", 65);
    Jugador* portero1 = new Portero("Jan Oblak", 13, 29, 540, "sí", 42);
    Jugador* delantero2 = new Delantero("Antoine Griezmann", 7, 31, 490, "sí", 15);

    // Agregar jugadores al equipo
    equipo.agregarJugador(delantero1);
    equipo.agregarJugador(medio1);
    equipo.agregarJugador(defensa1);
    equipo.agregarJugador(portero1);
    equipo.agregarJugador(delantero2);

    // Mostrar información del equipo
    equipo.mostrarJugadores();

    return 0;
}
