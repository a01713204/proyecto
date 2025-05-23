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
    string nombre;
    int numero;
    int edad;
    int minutos_jugados;
    string titular;  // sí o no
    
public: //Todos pueden acceder a esto
    Jugador(string nom, int num, int ed, int min, string tit)
        : nombre(nom), numero(num), edad(ed), minutos_jugados(min), titular(tit) {}

    virtual void atributos() = 0;//permite la sobreescritura. Que se pueda cambiar en clases hijas
    virtual int puntos() = 0;
    virtual ~Jugador() {}
    int getNumero()  { 
        return numero; 
    }
    string getNombre()  { 
        return nombre; 
    }

};

class Delantero : public Jugador { //Aqui se implementa la herencia
private: //Solo la clase delantero tiene acceso a estos atributos
    int goles_anotados;

public:
    Delantero(string nom, int num, int ed, int min, string tit, int goles)
        : Jugador(nom, num, ed, min, tit), goles_anotados(goles) {}


    void atributos() override {//override sobreescribe el metodo virtual
        cout << "Delantero: " << nombre<< "Numero: " <<numero <<"Minutos jugados: "<< minutos_jugados<< ", Goles: " << goles_anotados << endl;

    }

    void puntos() override {
        int pts = goles_anotados *4; // 4 puntos por gol
        cout << "Puntos del delantero " << nombre << " " << pts << endl;
    }
};

// Clase Medio
class Medio : public Jugador {
private:
    int asistencias;

public:
    Medio(string nom, int num, int ed, int min, string tit, int asist)
        : Jugador(nom, num, ed, min, tit), asistencias(asist) {

        }

    void atributos() override {
        cout << "Medio: " << nombre<< "Numero: " <<numero <<"Minutos jugados: "<< minutos_jugados<< ", Asistencias: " << asistencias << endl;

    }

    void puntos() override {
        int pts = asistencias * 3; //dos puntos por asist
        cout << "Puntos medio " << nombre << ": " << pts << endl;
    }
};


class Defensa : public Jugador {
private:
    int recuperaciones; //dentras de la media cancha

public:
    Defensa(string nom, int num, int ed, int min, string tit, int recup)
        : Jugador(nom, num, ed, min, tit), recuperaciones(recup) {}

    void atributos() override {
        cout << "Defensa: " << nombre<< "Numero: " <<numero <<"Minutos jugados: "<< minutos_jugados<< ", recuperaciones: " << recuperaciones << endl;

    }

    void puntos() override {
        int pts = recuperaciones ; //un punto por asist
        cout << "Puntos defensa " << nombre << ": " << pts << endl;
    }
};


class Portero : public Jugador {
private:
    int atajadas;

public:
    Portero(string nom, int num, int ed, int min, string tit, int ataj)
        : Jugador(nom, num, ed, min, tit), atajadas(ataj) {}

        void atributos() override {
            cout << "Portero: " << nombre<< "Numero: " <<numero <<"Minutos jugados: "<< minutos_jugados<< ", Atajadas: " << atajadas << endl;
    
        }
    
        void puntos() override {
            int pts = atajadas * 2; //dos puntos por asist
            cout << "Puntos portero: " << nombre << " " << pts << endl;
        }
};
