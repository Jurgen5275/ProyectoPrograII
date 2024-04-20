#include "Embutido.h"
#include <sstream>
#include <iostream>
using namespace std;

Embutido::Embutido(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string animalNom, string partAnimal, bool tri, string marc)
	: Carne(cod, nom, descrip, prec, exis, cate, fechV, nac, pes, animalNom, partAnimal), Empaque{ tri }, marca{ marc } {}

Embutido::~Embutido() {}