#pragma once
#include"Producto.h"
#include"Fecha.h"
#include "Fecha.h"
#include "Categoria.h"

class Perecedero:public Producto{
public:
	Perecedero(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes)
	 : Producto(cod, nom, descrip, prec, exis, cate, fechV), nacional{nac}, peso{pes}{}

	~Perecedero();

	virtual void mostrarDetalles() = 0;

	virtual float calcularPrecioVenta() = 0;

private:
	bool nacional;
	double peso;
	Fecha* fecha;
};


