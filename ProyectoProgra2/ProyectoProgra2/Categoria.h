#pragma once
#include <string>

using namespace std;

class Categoria{
protected:
	string categoria;

public:
	Categoria(){}

	virtual ~Categoria(){}

	double porceGanancia(const string cate){}
};

