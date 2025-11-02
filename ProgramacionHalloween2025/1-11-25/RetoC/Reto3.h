#ifndef RETO3_H
#define RETO3_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 100
#define MAX_TYPES 50

typedef struct {
    char name[MAX_NAME];
    int cant;
} TipoCalabaza;

int buscarTipo(TipoCalabaza inventario[], int total, char name[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(inventario[i].name, name) == 0) {
            return i;  // Retorna el índice si lo encuentra
        }
    }
    return -1;  // No encontrado
}

void consultarStock(TipoCalabaza inventario[], int total, char *name) {
    int indice = buscarTipo(inventario, total, name);
    if (indice == -1) {
        printf("'%s' no existe en el inventario\n", name);
    } else {
        printf("Stock de '%s': %d unidades\n", name, inventario[indice].cant);
    }
}

void mostrarInventario(TipoCalabaza inventario[], int total) {
    printf("\n╔════════════════════════════════════════════════╗\n");
    printf("║       INVENTARIO DE CALABAZAS 🎃              ║\n");
    printf("╚════════════════════════════════════════════════╝\n\n");
    printf("TIPO DE CALABAZA \t | CANTIDAD\n");
    printf("-----------------------------------------------\n");
    if (total == 0) {
        printf("El inventario está vacío\n");
    }
    else{
        for (int i = 0; i < total; i++) {
            if(strlen(inventario[i].name)<20 && strlen(inventario[i].name)>14)
                printf("%s \t | %d\n", inventario[i].name, inventario[i].cant);
            else if(strlen(inventario[i].name)<15)
                printf("%s  \t | %d\n", inventario[i].name, inventario[i].cant);
            else if(strlen(inventario[i].name)<25 && strlen(inventario[i].name)>20)
                printf("%s  | %d\n", inventario[i].name, inventario[i].cant);
            else
                printf("%s | %d\n", inventario[i].name, inventario[i].cant);
        }
    }
    printf("================================================\n");
    int suma = 0;
    for (int i = 0; i < total; i++) {
        suma += inventario[i].cant;
    }
    printf("Tipos diferentes: %d | Total de calabazas: %d\n", total, suma);  
}

bool agregarCalabaza(TipoCalabaza inventario[], int *total, char *name, int cantidad) {
    if (cantidad <= 0) {
        printf("Error: La cantidad debe ser mayor a 0\n");
        return false;
    }
    int indice = buscarTipo(inventario, *total, name);
    if (indice != -1) {
        inventario[indice].cant += cantidad;
        printf("Se han agregado %d unidades a '%s'. Nuevo stock: %d\n", cantidad, name, inventario[indice].cant);
    } else {
        strcpy(inventario[*total].name, name);
        inventario[*total].cant = cantidad;
        (*total)++;
        printf("Se ha agregado un nuevo tipo de calabaza: '%s' con %d unidades.\n", name, cantidad);
    }
    return true;
}

bool retirarCalabaza(TipoCalabaza inventario[], int *total, char *name, int cantidad) {
    int indice = buscarTipo(inventario, *total, name);
    if (indice == -1) {
        printf("Error: '%s' no existe en el inventario\n", name);
        return false;
    }
    if (cantidad <= 0 || cantidad > inventario[indice].cant) {
        printf("Error: Cantidad inválida para retirar de '%s'\n", name);
        return false;
    }
    inventario[indice].cant -= cantidad;
    printf("Se han retirado %d unidades de '%s'. Stock restante: %d\n", cantidad, name, inventario[indice].cant);
    if (inventario[indice].cant == 0) //Se podría eliminar, ya dependería de como quisieramos que fuese la BD
        printf("(Stock agotado de '%s')\n", name);

    return true;
}

void mostrarMenu() {
    printf("\n--- MENÚ DE OPCIONES ---\n");
    printf("1. Agregar calabazas\n");
    printf("2. Retirar calabazas\n");
    printf("3. Consultar stock\n");
    printf("4. Mostrar inventario completo\n");
    printf("0. Salir\n");
    printf("Opción: ");
}

void reto3(){
    TipoCalabaza inventario[MAX_TYPES];
    int total = 0, opcion, cantidad;
    char nombre[MAX_NAME];
    // Datos iniciales de ejemplo
    printf("=== INICIALIZANDO INVENTARIO ===\n");
    agregarCalabaza(inventario, &total, "Calabaza naranja pequeña", 5);
    agregarCalabaza(inventario, &total, "Calabaza blanca", 3);
    agregarCalabaza(inventario, &total, "Calabaza naranja grande", 2);
    agregarCalabaza(inventario, &total, "Calabaza verde", 4);
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (opcion) {
            case 1: // Agregar calabazas
                printf("Nombre del tipo de calabaza a agregar: ");
                scanf(" %[^\n]", nombre);
                getchar(); // Limpiar el salto de línea pendiente
                printf("Cantidad a agregar: ");
                scanf("%d", &cantidad);
                agregarCalabaza(inventario, &total, nombre, cantidad);
                break;
            case 2: // Retirar calabazas
                printf("Nombre del tipo de calabaza a retirar: ");
                scanf(" %[^\n]", nombre);
                getchar(); // Limpiar el salto de línea pendiente
                printf("Cantidad a retirar: ");
                scanf("%d", &cantidad);
                retirarCalabaza(inventario, &total, nombre, cantidad);
                break;
            case 3: // Consultar stock
                printf("Nombre del tipo de calabaza a consultar: ");
                scanf(" %[^\n]", nombre);
                getchar(); // Limpiar el salto de línea pendiente
                consultarStock(inventario, total, nombre);
                break;
            case 4: // Mostrar inventario completo
                mostrarInventario(inventario, total);
                break;
            case 0: // Salir
                break;
            default:
                printf("Opción no válida. Por favor, elige de nuevo.\n");
                break;
        }
    } while (opcion != 0);
}

#endif // RETO3_H