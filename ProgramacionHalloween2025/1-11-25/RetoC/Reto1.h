#ifndef RETO1_H
#define RETO1_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void contar_letras_cadena(char *cadena) {
    int n_letras = 0, n_digitos = 0, n_otros = 0;
    for(int i = 0; cadena[i] != '\0'; i++){
        if(isdigit(cadena[i]))
            n_digitos++;
        else if(isalpha(cadena[i]))
            n_letras++;
        else
            n_otros++;
    }
    printf("La cadena contiene: ");
    printf("%d letras, %d nº, %d caracteres especiales\n", n_letras, n_digitos, n_otros);
}

#endif // RETO1_H