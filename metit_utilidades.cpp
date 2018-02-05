/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 5
*/
#include<iostream>
#include<string>
#include<cmath>
#include"metit_utilidades.h"
using namespace std;


void printResultado(resultado r)
{
    cout << "Resultado: " << r.r << endl;
    cout << "Error: " << r.e << endl;
    cout << "Iteraciones: " << r.i << endl;
    cout << "Mensaje: " << r.m << endl;
    return;
};

void printParametros(param par, string nom, string met){
    cout << "Funcion: " << nom << endl;
    cout << "Metodo: " << met << endl;
    cout << "a = " << par.a0 << endl;
    cout << "b = " << par.b0 << endl;
    if (!isnan(par.x0)) cout << "x0 = " << par.x0 << endl;
    cout << "Error maximo = " << par.error_max << endl;
    cout << "Num. iteraciones maximo = " << par.iter_max << endl << endl;
};


resultado resC(double r, double e, int i, string m)
{
    resultado res; res.c = C; 
    res.r = r; res.e = e; 
    res.i = i; res.m = m;
    return res;
}

resultado resDI(double r, double e, int i, string m){
    resultado res; res.c = DI; 
    res.r = r; res.e = e; 
    res.i = i; res.m = m;
    return res;
}

resultado resNIMA(double r, double e, int i, string m){
    resultado res; res.c = NIMA; 
    res.r = r; res.e = e;
    res.i = i; res.m = m;
    return res;
}