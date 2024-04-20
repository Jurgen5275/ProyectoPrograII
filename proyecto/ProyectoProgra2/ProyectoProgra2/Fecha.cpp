#include "Fecha.h"
#include <sstream>
#include <iostream>
using namespace std;

Fecha::Fecha(){}

Fecha::Fecha(int d, int m, int an) : dia{ d }, mes{ m }, anio{an} {}

Fecha::~Fecha(){}
