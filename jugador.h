#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// Clase madre de delantero, medio, defensa y portero
class Jugador {
protected: // modificador de acceso protected para que sus clases hijas puedan acceder a ellos
    std::string nombre;
    int numero;
    int edad;
    int minutos_jugados;
    std::string titular;  // sí o no
    
public: //Todos pueden acceder a esto
    
Jugador(); //constructor vacío
Jugador(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular);

    void setNombre(std::string);
    void setNumero(int);
    void setEdad(int);
    void setMinutos_jugados(int);
    void setTitular(std::string);

    //Metodo muestra que se aplicará a todas las clases hijas
    virtual void muestra();

};
Jugador::Jugador() : nombre(""), numero(0),edad(0), minutos_jugados(0), titular(""){}
Jugador:: Jugador(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular)
    : nombre(nombre), numero(numero), edad(edad), minutos_jugados(minutos_jugados), titular(titular){}

void Jugador::setNombre(std:: string name){
    nombre=name;
}
void Jugador::setNumero(int number){
    numero=number;
}
void Jugador::setEdad(int age){
    edad=age;
}
void Jugador::setMinutos_jugados(int minutes_played){
    minutos_jugados=minutes_played;
}
void Jugador::setTitular(std:: string tit){
    titular=tit;
}
void Jugador:: muestra(){
    std::cout << "nombre: "<< nombre << std::endl;
    std::cout << "numero: "<< numero << std::endl;
    std::cout << "edad: "<< edad << std::endl;
    std:: cout << "minutos jugados: "<< minutos_jugados<<std::endl;
    std::cout << "titular: "<< titular << std::endl;
}


class Delantero : public Jugador { //Aqui se implementa la herencia
    private: //Solo la clase delantero tiene acceso a estos atributos
        int goles_anotados;


    public:
        Delantero(std::string nombre, int numero, int edad, int minutos_jugados, std:: string titular, int goles_anotados);
        void setGoles_anotados(int scored_goals);
        void muestra();
};

Delantero::Delantero(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular, int goles_anotados)
    :Jugador(nombre, numero, edad, minutos_jugados, titular), goles_anotados(goles_anotados){}

void Delantero:: setGoles_anotados(int scored_goals){
    goles_anotados=scored_goals;
}

void Delantero::muestra(){
    std::cout<<"nombre: "<<nombre<<std::endl;
    std::cout<<"numero: "<<numero<<std::endl;
    std::cout<<"edad: "<<edad<<std::endl;
    std::cout<<"minutos jugados: "<<minutos_jugados<<std::endl;
    std::cout<<"golesanotados: "<<goles_anotados<<std::endl;
    std::cout<<"puntos: "<<goles_anotados*4<<std::endl;
}




// Clase Medio
class Medio : public Jugador {
private: //Solo la clase medio tiene acceso a estos atributos
    int asistencias;


public:
    Medio(std::string nombre, int numero, int edad, int minutos_jugados, std:: string titular, int asistencias);
    void setAsistencias(int asists);
    void muestra();
};

Medio::Medio(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular, int asistencias)
    :Jugador(nombre, numero, edad, minutos_jugados, titular), asistencias(asistencias){}

void Medio:: setAsistencias(int asists){
    asistencias=asists;
}

void Medio::muestra(){
std::cout<<"nombre: "<<nombre<<std::endl;
std::cout<<"numero: "<<numero<<std::endl;
std::cout<<"edad: "<<edad<<std::endl;
std::cout<<"minutos jugados: "<<minutos_jugados<<std::endl;
std::cout<<"asistencias: "<<asistencias<<std::endl;
std::cout<<"puntos: "<<asistencias*3<<std::endl;
}



class Defensa : public Jugador {
    private: //Solo la clase defensa tiene acceso a estos atributos
    int recuperaciones;


public:
    Defensa(std::string nombre, int numero, int edad, int minutos_jugados, std:: string titular, int recuperaciones);
    void setRecuperaciones(int recup);
    void muestra();
};

Defensa::Defensa(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular, int recuperaciones)
    :Jugador(nombre, numero, edad, minutos_jugados, titular), recuperaciones(recuperaciones){}

void Defensa:: setRecuperaciones(int recup){
    recuperaciones=recup;
}

void Defensa::muestra(){
std::cout<<"nombre: "<<nombre<<std::endl;
std::cout<<"numero: "<<numero<<std::endl;
std::cout<<"edad: "<<edad<<std::endl;
std::cout<<"minutos jugados: "<<minutos_jugados<<std::endl;
std::cout<<"recuperaciones: "<<recuperaciones<<std::endl;
std::cout<<"puntos: "<<recuperaciones*1<<std::endl;
}




class Portero : public Jugador {
    private: //Solo la clase defensa tiene acceso a estos atributos
    int atajadas;


public:
    Portero(std::string nombre, int numero, int edad, int minutos_jugados, std:: string titular, int atajadas);
    void setAtajadas(int saves);
    void muestra();
};

Portero::Portero(std::string nombre, int numero, int edad, int minutos_jugados, std::string titular, int atajadas)
    :Jugador(nombre, numero, edad, minutos_jugados, titular), atajadas(atajadas){}

void Portero:: setAtajadas(int saves){
    atajadas=saves;
}

void Portero::muestra(){
std::cout<<"nombre: "<<nombre<<std::endl;
std::cout<<"numero: "<<numero<<std::endl;
std::cout<<"edad: "<<edad<<std::endl;
std::cout<<"minutos jugados: "<<minutos_jugados<<std::endl;
std::cout<<"atajadas: "<<atajadas<<std::endl;
std::cout<<"puntos: "<<atajadas*2<<std::endl;
}
#endif
