#pragma once
#include"Producto.h"
class Perecedero:public Producto
{
public:
	Perecedero(string cod, string nom, float prec, int exis, string fechV) :Producto(cod, nom, prec, exis), fechaV{fechV} {}
	~Perecedero();

private:
	string fechaV;
};


