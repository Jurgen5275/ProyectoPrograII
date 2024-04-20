#include "Lista.h"

template<typename T>
Lista<T>::Lista() : primero(nullptr), ultimo(nullptr), tamano(0) {}

template<typename T>
Lista<T>::~Lista() {
    limpiar();
}

template<typename T>
void Lista<T>::agregar(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if (estaVacia()) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
    else {
        ultimo->establecerSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    tamano++;
}

template<typename T>
void Lista<T>::imprimir() const {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        std::cout << actual->obtenerDato() << " ";
        actual = actual->obtenerSiguiente();
    }
    std::cout << std::endl;
}

template<typename T>
void Lista<T>::limpiar() {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->obtenerSiguiente();
        delete actual;
        actual = siguiente;
    }
    primero = nullptr;
    ultimo = nullptr;
    tamano = 0;
}

template<typename T>
bool Lista<T>::estaVacia() const {
    return tamano == 0;
}

template<typename T>
int Lista<T>::obtenerTamano() const {
    return tamano;
}