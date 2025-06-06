#include "equipo.h"
#include "jugador.h"

int main() {
    int capacidad, valor;
    std::string entrenador;

    std::cout << "Ingresa la capacidad del equipo: ";
    std::cin >> capacidad;

    std::cout << "Ingresa el valor del equipo en pesos: ";
    std::cin >> valor;

    std::cout << "Nombre del entrenador (una sola palabra): ";
    std::cin >> entrenador;

    Equipo equipo(valor, entrenador, capacidad);

    for (int i = 0; i < capacidad; ++i) {
        int tipo, numero, edad, minutos, extra;
        std::string nombre, titular;

        std::cout << "\nJugador #" << i+1 << std::endl;
        std::cout << "Tipo (1=Delantero, 2=Medio, 3=Defensa, 4=Portero): ";
        std::cin >> tipo;

        std::cout << "Nombre (una sola palabra): ";
        std::cin >> nombre;

        std::cout << "Número: ";
        std::cin >> numero;

        std::cout << "Edad: ";
        std::cin >> edad;

        std::cout << "Minutos jugados: ";
        std::cin >> minutos;

        std::cout << "¿Titular? (sí/no) ";
        std::cin >> titular;

        Jugador* jugador;

        if (tipo == 1) {
            std::cout << "Goles anotados: ";
            std::cin >> extra;
            jugador = new Delantero(nombre, numero, edad, minutos, titular, extra);
        } else if (tipo == 2) {
            std::cout << "Asistencias: ";
            std::cin >> extra;
            jugador = new Medio(nombre, numero, edad, minutos, titular, extra);
        } else if (tipo == 3) {
            std::cout << "Recuperaciones: ";
            std::cin >> extra;
            jugador = new Defensa(nombre, numero, edad, minutos, titular, extra);
        } else if (tipo == 4) {
            std::cout << "Atajadas: ";
            std::cin >> extra;
            jugador = new Portero(nombre, numero, edad, minutos, titular, extra);
        } else {
            std::cout << "Tipo no válido. Jugador omitido.\n";
            continue;
        }

        equipo.agregarJugador(jugador);
    }

    std::cout << " INFORMACIÓN DEL EQUIPO"<< std::endl;
    equipo.mostrarJugadores();

    return 0;
}
