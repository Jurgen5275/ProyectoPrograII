#pragma once
#include "Fecha.h"
#include "Carne.h"
#include "Empaque.h"
#include "Categoria.h"

class Embutido : public Carne{
public: 
	Embutido(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string animalNom, string partAnimal, bool tri, string marc)
		: Carne(cod, nom, descrip, prec, exis, cate, fechV, nac, pes, animalNom, partAnimal) {}

	~Embutido(){}

private: 
	string marca;
	Empaque* empaque;
};
