#pragma once
#ifndef NODO_H
#define NODO_H

#include "Producto.h"
template<typename T>
class Nodo {
public:
    Nodo() : dato(), siguiente(nullptr) {}
    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}

    T obtenerDato() const { return dato; }
    void establecerDato(const T& valor) { dato = valor; }

    Nodo* obtenerSiguiente() const { return siguiente; }
    void establecerSiguiente(Nodo* nodo) { siguiente = nodo; }

private:
    T dato;
    Nodo* siguiente;
};
#endif