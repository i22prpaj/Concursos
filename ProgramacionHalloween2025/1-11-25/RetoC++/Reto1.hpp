#ifndef RETO1_HPP
#define RETO1_HPP

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void contar_letras_cadena(const string &cadena) {
    int n_letras = 0, n_digitos = 0, n_otros = 0;
    for(auto c : cadena) {
        if(isdigit(c))
            n_digitos++;
        else if(isalpha(c))
            n_letras++;
        else
            n_otros++;
    }
    cout << "La cadena contiene: " 
              << n_letras << " letras, " 
              << n_digitos << " números, " 
              << n_otros << " caracteres especiales" << endl;
}

#endif // RETO1_HPP