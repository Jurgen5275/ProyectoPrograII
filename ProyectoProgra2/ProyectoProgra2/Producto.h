#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Producto
{
public:
	Producto() {
		codigo = "";
		precio = 0.00;
		nombre = "";
		existencias = 1;
	}
	Producto(string cod, string nom, float prec, int exis) :codigo{ cod }, precio{ prec }, nombre{ nom }, existencias{exis} {}
	virtual void mostrarDetalles() = 0;
	virtual float calcularPrecioVenta() = 0;

private:
	string codigo;
	float precio;
	string nombre;
	int existencias;
};
