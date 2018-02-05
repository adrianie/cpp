/*
    Adrian Anido Freire
    Programacion en C++ 2017-18
    Boletin 1, ejercicio 3 y 5
*/
#include<iostream>
#include<string>
using namespace std;

int menuGenerico(string* cabecera, string* opciones, int nopciones){
    if (nopciones < 1) return -1;

    int opcion;
    bool repetir = true;

    while(repetir){
        if (cabecera != nullptr) cout << *cabecera << endl << endl;
        for (int i=0; i < nopciones; i++)
            cout << i << ". " << *(opciones + i) << endl;
        
        cout << endl << "Opcion: ";
        cin >> opcion;
        cout << endl << endl;

        if (opcion < 0 || opcion > nopciones){
            cout << "Opcion elegida incorrecta!" << endl;
            continue;
        }

        repetir = false;
    }

    return opcion;
}