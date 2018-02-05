/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 5
*/
#include<cmath>
#include"metit.h"
#include"metit_utilidades.h"

#define ZERO_EPS 1e-6

/*
    Contiene metodos
    iterativos de resolucion
    de ecuaciones.
*/

resultado dicotomia(double (*funcion)(double), param parametros){
    double a = parametros.a0, b = parametros.b0;
    double error_max = parametros.error_max, iter_max = parametros.iter_max;

    if ((*funcion)(a) == 0) return resDI(NAN, NAN, 0,
                            "El extremo a del intervalo es raiz de la funcion");
    if ((*funcion)(b) == 0) return resDI(NAN, NAN, 0, 
                            "El extremo b del intervalo es raiz de la funcion");

    // f(a)x(fb) > 0
    if ((*funcion)(a)*(*funcion)(b) > 0)
        return resDI(NAN, NAN, 0, "Error en los datos, no cumplen f(a)xf(b)>=0.");
    
    double p;

    for(int i=0; i<iter_max; i++){
        p = (b + a)/2;

        if ((*funcion)(a)*(*funcion)(p) > 0) a = p; 
        else b = p;

        if (std::abs((*funcion)(p)) < error_max)
            return resC(p, std::abs((*funcion)(p)), i);
    }
    
    return resNIMA(p, std::abs((*funcion)(p)), iter_max);
}

resultado newtonraphson(double (*funcion)(double), double(*dfuncion)(double),
                            param parametros){
    double a = parametros.a0, b = parametros.b0, x0 = parametros.x0;
    double error_max = parametros.error_max, iter_max = parametros.iter_max;


    if ((*funcion)(a) == 0) return resDI(NAN, NAN, 0,
                            "El extremo a del intervalo es raiz de la funcion");
    if ((*funcion)(b) == 0) return resDI(NAN, NAN, 0, 
                            "El extremo b del intervalo es raiz de la funcion");
    // Condicion: f(a)x(fb) < 0
    if ((*funcion)(a)*(*funcion)(b) > 0) 
        return resDI(NAN, NAN, 0, "Error en los datos, no cumplen f(a)xf(b)>=0");
    
    // Condicion: x0 en (a,b)
    if (((b > a) && ((x0 < a) || (x0 > b))) || 
        ((a > b) && ((x0 < b) || (x0 > a))))
            return resDI(NAN, NAN, 0, "Error en los datos, x0 no esta en (a,b)");


    // Condicion |f(c)/f'(c)| <= b - a
    double c, fx, dfx;
    if ((*dfuncion)(b) < (*dfuncion)(a)) c = b;
    else c = a;

    fx = (*funcion)(c); 
    dfx = (*dfuncion)(c);
    c = std::abs(fx / dfx);
    if (c > (b - a))
        return resDI(NAN, NAN, 0,
                "Error en los datos, la funcion no cumple la hipotesis:"
                "c = max(f'(a), f'(b)) |f(c)/f'(c)| <= b - a");
    
    double x = x0, dfx2;

    for(int i=0; i < iter_max; i++){
        fx = (*funcion)(x);
        dfx = (*dfuncion)(x);
        if (std::abs(fx) < error_max)
            return resC(x, std::abs(fx), i);

        x = x - (fx/dfx);

        // Condicion: f'(x) != 0 en (a,b)
        if (i > 0 && dfx2*dfx <= 0)
            return resDI(NAN, NAN, i, "La derivada no cumple df != 0 en (a,b)");
        
        dfx2 = dfx;
    }
    
    return resNIMA(x, std::abs((*funcion)(x)), iter_max);
}