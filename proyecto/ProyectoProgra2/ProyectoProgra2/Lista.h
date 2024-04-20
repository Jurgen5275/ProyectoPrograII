#pragma once
template<typename T>
class Lista {
public:
    Lista();
    ~Lista();

    void agregar(const T& valor);
    void imprimir() const;
    void limpiar();
    bool estaVacia() const;
    int obtenerTamano() const;

private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
    int tamano;
};