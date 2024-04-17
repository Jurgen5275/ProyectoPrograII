#pragma once
#include<iostream>
#include<sstream>
#include "Categoria.h"
#include "Fecha.h"

using namespace std;

class Producto{
public:
	Producto(){
		codigo = "";
		nombre = "";
		descripcion = "";
		precio = 0.00;
		//categoria = ""; 
		categoria = Categoria();
		existencias = 1;
		fechaV= Fecha(0,0,0); //limite o fecha vencimiento
	}

	//Producto(string cod, string nom, string descrip, float prec, int exis, string cate, Fecha fechV) 
	//	:codigo{ cod }, precio{ prec }, nombre{ nom }, descripcion{ descrip }, existencias{ exis }, categoria{ cate }, fechaV{fechV} {}

	Producto(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV)
		:codigo{ cod }, precio{ prec }, nombre{ nom }, descripcion{ descrip }, existencias{ exis }, categoria{ cate }, fechaV{fechV} {}


	virtual void mostrarDetalles() = 0;

	virtual float calcularPrecioVenta() = 0;

protected:
	string codigo;
	string nombre;
	string descripcion;
	float precio;
	//string categoria;
	Categoria categoria;
	int existencias;
	//limite o la fecha vencimiento
	Fecha fechaV;

};
