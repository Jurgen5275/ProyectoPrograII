#pragma once
#include <sstream>
#include <iostream>
#include "Perecedero.h"
#include "Producto.h"
#include "Fecha.h"
#include "Categoria.h"

class Abarrote : public Perecedero{
public:
	Abarrote(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string empresaNom)
		: Perecedero(cod, nom, descrip, prec, exis, cate, fechV, nac, pes), empresaNombre{ empresaNom } {}

	~Abarrote();

	void mostrarDetalles() override;

	float calcularPrecioVenta() override;

private:
	string empresaNombre;
};

