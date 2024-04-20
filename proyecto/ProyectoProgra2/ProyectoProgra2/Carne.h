#pragma once
#include "Perecedero.h"
#include "Fecha.h"
#include "Categoria.h"

class Carne : public Perecedero{
public:
	Carne(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string animalNom, string partAnimal)
		: Perecedero(cod, nom, descrip, prec, exis,cate, fechV, nac, pes), nombreAnimal{animalNom}, parteDelAnimal{partAnimal}{}

	~Carne() {}

	void mostrarDetalles() override;

	float calcularPrecioVenta() override;

private:
	string nombreAnimal;
	string parteDelAnimal;

};

