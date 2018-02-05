/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 5
*/
#include"metit_utilidades.h"


resultado dicotomia(double (*funcion)(double), param parametros);
resultado newtonraphson(double (*funcion)(double), double(*dfuncion)(double),
                            param parametros);                        