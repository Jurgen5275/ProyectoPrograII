#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/*#include ".h" (contenedores)*/

//prueba menu.h
class Menu {
private:
    struct Nodo {
        int opcion;
        string nombre;
        Menu* submenu;
        Nodo* siguiente;
    };

    Nodo* ppio; //puntero al principio
    string titulo;
    bool dynamicallyAllocated;

    //CONTENEDORES
    /*StudentContainer student;
    ContenedorVentas venta; */

    void ingresarOpcion(const int& op, const string& nombre, Menu* submenu);

    void clear();

public:
    struct Opcion { //una lista anidada con otra lista
        int numero;
        string nombre;
        Menu* submenu;
    };

    Menu(const string& titulo, const vector<Opcion>& opciones);
    //el vec Option es xq Option es un tipo (se creó el struct)
    //y se usa un vector para pasar de manera dinamica las opciones
    //al constructor y el convierte ese vector en una lista

    Menu();

    //destructor
    ~Menu();

    //metodos
    void mostrarMenu() const;

    void manejarEntradaUsuario() const;

    void manejarOpcion(Nodo* nod) const;

    bool isDynamicallyAllocated() const; //bool asignadoDinamicamente const;

    void setDynamicallyAllocated(bool dynamicallyAllocated);
    //void setAsignadoDinamicamente(bool dynamically Allocated);
};