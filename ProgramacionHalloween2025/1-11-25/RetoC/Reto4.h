#ifndef RETO4_H
#define RETO4_H

#include <stdio.h>
#include <stdlib.h>

float calcularMedia(int edades[], int n) {
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma += edades[i];
    }
    return (float)suma / n;
}

// Función de comparación para qsort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calcularMediana(int edades[], int n){
    // Ordenar el array
    qsort(edades, n, sizeof(int), comparar);
    if(n % 2 == 0) //Promedio de los 2 valores centrales
        return (edades[n/2 - 1] + edades[n/2]) / 2.0;
    else //Valor central
        return edades[n/2];
}

void truco_trato(float media, float mediana) {
    printf("Media de edades: %f\n", media);
    printf("Mediana de edades: %f\n", mediana);

    if (media < 12 && mediana < 12) {
        printf("\n🍬 ¡TRATO! (Dulces)\n");
        printf("Razón: Grupo de niños pequeños (media y mediana < 12)\n");
    }
    else if (media >= 15 && mediana >= 15) {
        printf("\n🎃 ¡TRUCO! (Broma o actividad)\n");
        printf("Razón: Grupo de adolescentes/adultos (media y mediana >= 15)\n");
    }
    else if (media >= 12 && mediana >= 12) {
        printf("\n🎭 ¡TRUCO Y TRATO!\n");
        printf("Razón: Grupo mixto de pre-adolescentes y mayores\n");
    }
    else {
        printf("\n🍭 ¡TRATO! (Dulces)\n");
        printf("Razón: Predominan los niños en el grupo\n");
    }
}

#endif // RETO4_H