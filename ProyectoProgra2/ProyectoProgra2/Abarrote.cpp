#include "Abarrote.h"
#include <sstream>
#include <iostream>
using namespace std;


//Abarrote::Abarrote(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string empresaNom)
	//: Perecedero(cod, nom, descrip, prec, exis, cate, fechV, nac, pes), empresaNombre{ empresaNom } {}


Abarrote::Abarrote(string cod, string nom, string descrip, float prec, int exis, Categoria cate, Fecha fechV, bool nac, double pes, string empresaNom)
	: Perecedero(cod, nom, descrip, prec, exis, cate, fechV, nac, pes), empresaNombre{ empresaNom } {}


//Fecha::Fecha(int d, int m, int an) : dia{ d }, mes{ m }, anio{an} {}

Abarrote::~Abarrote() {};

void Abarrote::mostrarDetalles(){};

float Abarrote::calcularPrecioVenta() {};