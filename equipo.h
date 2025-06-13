/*
 *
 * Proyecto Gestion de un equipo de fútbol
 * Pablo Torres Dávila Galindo
 * A01713204
 * 12/06/2025
 */
#ifndef EQUIPO_H
#define EQUIPO_H

#include <iostream>
#include <string>
#include "jugador.h" //Incluimos los objetos que usaremos 

class Equipo {
    private:
        Jugador**jugadores;//dinamico, polimorfismo con apuntadores
        int capacidad;
        int valor; //cuanto vale el equipo en pesos$$
        std::string entrenador;
        int contador;
    //se declara el constructor por default y los métodos públicos del equipo
    public:
    Equipo(int valor, std:: string entrenador, int capacidad);
    void agregarJugador(Jugador* jugador);//Cambiado a puntero. Metodos 
    void mostrarJugadores();
    int getContador();
};
//usamos new para crear un objeto al memoneto de ejecutar el codigo y cumplir con el polimorfismo, con ayuda de los apuntadores
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

void Equipo::mostrarJugadores() {//primero se muestran los atributos privados del equipo
    std::cout << "Entrenador: " << entrenador << std::endl;
    std::cout << "Valor del equipo: $" << valor << std::endl;
    std::cout << "Jugadores del equipo: " << std::endl;
// con esto imprimimos a cada jugador
    for (int i = 0; i < contador; i++) {
        jugadores[i]->muestra();  // Polimorfismo
        std::cout << " " << std::endl;
    }
}
int Equipo::getContador(){
    return contador;
}

#endif //Equipo_H
