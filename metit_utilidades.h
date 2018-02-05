/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 5
*/
#include<string>

/*
    Contiene utilidades para trabajar 
     con metodos iterativos.
*/

#ifndef __MIU
#define __MIU

/*
    Codigo del resultado.
    C:  Raiz calculada correctamente
    DI: Datos incorrectos
    NIMA: Numero de iteraciones máximo alcanzado.
*/
enum codigo_res{C, DI, NIMA};


/*
    Estructura empleada para 
    devolver los resultados
    de un metodo iterativo
*/
struct resultado{
    codigo_res c;      // Codigo
    double r;          // Resultado
    double e;          // Error
    double i;          // Iteraciones
    std::string m;     // Mensaje
};

// Parametros de resolucion
struct param {
    double a0 = -100;
    double b0 = 100;
    double x0 = 0;
    double error_max = 1e-4;
    double iter_max = 1e3;
};


/*
    Funciones que saca por
    pantalla el resultado y
    los parametros de resolucion
    de un metodo.
*/
void printResultado(resultado r);
void printParametros(param par, std::string nom, std::string met);


/*
    Funciones auxiliares 
    para generar los resultados
*/
resultado resC(double r, double e, int i, std::string m = "Raiz calculada correctamente");
resultado resDI(double r, double e, int i, std::string m = "Datos incorrectos");
resultado resNIMA(double r, double e, int i, std::string m = "Numero maximo de iteraciones alcanzado");

#endif