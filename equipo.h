#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
#include "jugador.h"

class Equipo {
    private:
        Jugador**jugadores;
        int capacidad;
        int valor; //cuanto vale el equipo en pesos$$
        std::string entrenador;
        int contador;
    
    public:
    Equipo(int valor, std:: string entrenador, int capacidad);
    void agregarJugador(Jugador* jugador);//Cambiado a puntero
    void mostrarJugadores();
};

Equipo::Equipo(int valor, std::string entrenador, int capacidad): valor(valor), entrenador(entrenador), capacidad(capacidad), contador(0){
    jugadores = new Jugador*[capacidad]; //Inicializa el arreglo de punteros
}

void Equipo::agregarJugador(Jugador* jugador) {
    if (contador < capacidad) {
        jugadores[contador++] = jugador;
    } else {
        std::cout << "Equipo lleno, no se puede agregar más jugadores" << std::endl;
    }
}

void Equipo::mostrarJugadores() {
    std::cout << "Entrenador: " << entrenador << std::endl;
    std::cout << "Valor del equipo: $" << valor << std::endl;
    std::cout << "Jugadores del equipo: " << std::endl;

    for (int i = 0; i < contador; i++) {
        jugadores[i]->muestra();  // Polimorfismo
        std::cout << " " << std::endl;
    }
}

#endif //Equipo_H
