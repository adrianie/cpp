/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 5
*/
#include<cmath>
#include<string>

/*
    En este archivo se definen las funciones empleadas en el programa. 

    Tambien estan sus derivadas, nombres para sacar por pantalla, una 
    estructura que representa a una funcion y un metodo que
    devuelve esa estructura para cada funcion.
    
    Las funciones estan ordenadas siendo la primera la nº 0 
    y la ultima la nº 5.
*/
std::string recta_expresion = "f(x)=3+3.2*(x-4)";
double recta(double x){ return (3 + 3.2*(x - 4)); }
double drecta(double x){ return 3.2; }

std::string polinomio3_expresion = "f(x)=x^3+2.3*x^2+x-3";
double polinomio3(double x){ return pow(x,3) + 2.3*pow(x,2) + x + 3; }
double dpolinomio3(double x){ return 3*pow(x,2) + 2*2.3*x + 1; }

std::string funcion1_expresion = "f(x)=x^2*sin(pi*x-3)-(x-7.5)cos(x-3/pi)";
double funcion1(double x){ return pow(x,2)*sin(M_PI*x-3)-(x-7.5)*cos(x - 3/M_PI); }

std::string funcion2_expresion = "f(x)=x^3-x-1";
double funcion2(double x){ return pow(x,3)-x-1; }
double dfuncion2(double x){ return 3*pow(x,2)-1; }

std::string funcion3_expresion = "f(x)=x^3-2x+3";
double funcion3(double x){ return pow(x,3)-2*x+3; }
double dfuncion3(double x){ return 3*pow(x,2)-2; }

std::string ejercicio5_expresion = "f(x)=e^(-x^2)-x";
double ejercicio5(double x){ return exp(-pow(x,2)) - x; }
double dejercicio5(double x){ return -2*x*exp(-pow(x,2)) - 1; }

int NumFnc = 6;

struct InfoFuncion{
    int num;
    std::string nombre;
    double (*funcion)(double);
    double (*dfuncion)(double);
};

// Contando desde 0
InfoFuncion getInfoFuncion(int num){
    InfoFuncion info;
    info.num = num; 
    switch(num){
        case 0: info.nombre = recta_expresion; info.funcion = recta; 
                info.dfuncion = drecta; return info;
        case 1: info.nombre = polinomio3_expresion; info.funcion = polinomio3; 
                info.dfuncion = dpolinomio3; return info;
        case 2: info.nombre = funcion1_expresion; info.funcion = funcion1; 
                info.dfuncion = nullptr; return info;
        case 3: info.nombre = funcion2_expresion; info.funcion = funcion2; 
                info.dfuncion = dfuncion2; return info;
        case 4: info.nombre = funcion3_expresion; info.funcion = funcion3; 
                info.dfuncion = dfuncion3; return info;
        case 5: info.nombre = ejercicio5_expresion; info.funcion = ejercicio5; 
                info.dfuncion = dejercicio5; return info;        
        default: info.num = 0; info.nombre = ""; info.funcion = nullptr;
                info.dfuncion = nullptr; return info;
    }
}

