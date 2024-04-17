#include "Carne.h"
#include <sstream>
#include <iostream>
using namespace std;

Carne::Carne(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string animalNom, string partAnimal)
	: Perecedero(cod, nom, descrip, prec, exis, cate, fechV, nac, pes), nombreAnimal{ animalNom }, parteDelAnimal{ partAnimal } {}

Carne::~Carne() {}

void Carne::mostrarDetalles() {}

float Carne::calcularPrecioVenta() {}