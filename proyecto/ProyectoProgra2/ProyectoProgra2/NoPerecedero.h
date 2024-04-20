#pragma once
#include "Producto.h"
#include "Categoria.h"
#include "Fecha.h"
#include "Categoria.h"

class NoPerecedero : public Producto {
public:
	NoPerecedero(string cod, string nom,string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool env)
	 : Producto(cod, nom, descrip, prec, exis, cate, fechV), envasado{env}{}

	~NoPerecedero() {}

	void mostrarDetalles() override;

	float calcularPrecioVenta() override;


private:
	bool envasado;
	

};

