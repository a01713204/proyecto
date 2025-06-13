/*
 *
 * Proyecto Gestion de un equipo de fútbol
 * Pablo Torres Dávila Galindo
 * A01713204
 * 12/06/2025
 */
#include <iostream>
#include "equipo.h"
#include "jugador.h"

int main() {
    int capacidad, valor;
    std::string entrenador;

    std::cout << "Ingresa la capacidad del equipo, toma en cuenta que el equipo ya tiene 4 jugadores, por lo que debería ser 4 o mas: ";
    std::cin >> capacidad;

    std::cout << "Ingresa el valor del equipo en pesos: ";
    std::cin >> valor;

    std::cout << "Nombre del entrenador (una sola palabra): ";
    std::cin >> entrenador;

    Equipo equipo(valor, entrenador, capacidad);

    Jugador* d = new Delantero("Leo", 10, 35, 90, "sí", 2);
    Jugador* m = new Medio("Andres", 8, 32, 85, "sí", 1);
    Jugador* def = new Defensa("Carlos", 4, 30, 90, "no", 5);
    Jugador* p = new Portero("Memo", 1, 36, 90, "sí", 7);

    equipo.agregarJugador(d);
    equipo.agregarJugador(m);
    equipo.agregarJugador(def);
    equipo.agregarJugador(p);

    std::string opcion;

    while (true) {
        std::cout << "\n Menu -\n";
        std::cout << "1. Agregar jugador\n";
        std::cout << "2. Mostrar información del equipo y los puntos por jugador\n";
        std::cout << "3. Salir\n";
        std::cout << "Cual quieres realizar? (1, 2 o 3) ";
        std::cin >> opcion;

        if (opcion == "1") {
            if (capacidad == equipo.getContador()) {
                std::cout << "El equipo ya está lleno. No se pueden agregar más jugadores.\n";
                continue;
            }

            int tipo, numero, edad, minutos, extra;
            std::string nombre, titular;

            std::cout << "\nTipo de jugador (1=Delantero, 2=Medio, 3=Defensa, 4=Portero): ";
            std::cin >> tipo;

            std::cout << "Nombre (una sola palabra): ";
            std::cin >> nombre;

            std::cout << "Número: ";
            std::cin >> numero;

            std::cout << "Edad: ";
            std::cin >> edad;

            std::cout << "Minutos jugados: ";
            std::cin >> minutos;

            std::cout << "¿Titular? (sí/no): ";
            std::cin >> titular;

            Jugador* jugador = 0;

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
                std::cout << "Tipo no válido.\n";
                continue;
            }

            equipo.agregarJugador(jugador);

        } else if (opcion == "2") {
            equipo.mostrarJugadores();
        } else if (opcion == "3") {
            std::cout << "Nos vemos \n";
            break;
        } else {
            std::cout << "Opcion no válida, intenta de nuevo.\n";
        }
    }

    return 0;
}

