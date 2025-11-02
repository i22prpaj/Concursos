#include <stdio.h> // For printf, scanf
#include <stdlib.h> // For system("cls"), exit
#include <stdbool.h>
#include "Reto1.h"
#include "Reto2.h"
#include "Reto3.h"
#include "Reto4.h"

#define SIZE 100

void limpiar_pantalla();

int main() {
    printf("¡Feliz Halloween 2025! 🎃👻\n");
    printf("Realizado en C\n");
    printf("Autor: Juan Luis Prieto Panadero 👨‍💻\n");
    printf("Contacto: i22prpaj@uco.es ✉\n");
    printf("Estudiante de Ingeniería Informática en la EPSC\n");
    printf("Mención: Computación\n");
    printf("Presiona Enter para continuar...");
    getchar(); // Esperar Enter

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    int o = 0, n;
    char cadena[SIZE];
    char cadena_normalizada[SIZE];

    do{
        printf("Menú de Halloween 2025 🎃👻\n");
        printf("1. Contar caramelos 🍬\n");
        printf("2. Limpiar el conjuro 🧙\n");
        printf("3. Inventario de calabazas 🎃\n");
        printf("4. Truco o Trato 🎭\n");
        printf("5. Ruta en el cementerio (BFS) 💀\n");
        printf("6. Compresor de aullidos (RLE) 🐺\n");
        printf("7. Agenda embrujada 📅 \n");
        printf("8. Censo de fantasmas 👻 \n");
        printf("9. Cifrado del vampiro (ROT-N) 🧛\n");
        printf("0. Salir 🚪\n");
        printf("Elige una opción: ");
        scanf("%d", &o);
        
        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        switch(o){
            case 1:
                printf("Has elegido contar caramelos 🍬\n");
                printf("Introduce una cadena: ");
                scanf("%s", cadena);
                contar_letras_cadena(cadena);
                printf("La longitud total de la cadena es: %lu\n", strlen(cadena));
                break;
            case 2:
                printf("Has elegido limpiar el conjuro 🧙\n");
                printf("Introduce una cadena: ");
                scanf("%s", cadena);
                //strcpy(cadena, normalizar_cadena(cadena));
                normalizar_cadena(cadena, cadena_normalizada);
                printf("Cadena normalizada: %s\n", cadena_normalizada);
                break;
            case 3:
                printf("Has elegido el inventario de calabazas 🎃\n");
                reto3();
                break;
            case 4:
                printf("Has elegido el truco o trato 🎭\n");
                printf("¿Cuántas personas hay en el grupo? ");
                scanf("%d", &n);
                if (n <= 0) {
                    printf("Error: Debe haber al menos una persona.\n");
                    break;
                }
                int *edades = (int*)malloc(n * sizeof(int));
                for (int i = 0; i < n; i++) {
                    printf("Edad de la persona %d: ", i + 1);
                    scanf("%d", &edades[i]);
        
                    if (edades[i] < 0 || edades[i] > 120) {
                        printf("Error: Edad inválida.\n");
                        free(edades);
                        break;
                    }
                }
                // Calcular estadísticas
                float media = calcularMedia(edades, n);
                float mediana = calcularMediana(edades, n);

                truco_trato(media, mediana);
                free(edades);
                break;
            case 5:
                printf("Has elegido la ruta en el cementerio (BFS) 💀\n");
                printf("Funcionalidad en desarrollo...\n");
                break;
            case 6:
                printf("Has elegido el compresor de aullidos (RLE) 🐺\n");
                printf("Funcionalidad en desarrollo...\n");
                break;
            case 7:
                printf("Has elegido la agenda embrujada 📅\n");
                printf("Funcionalidad en desarrollo...\n");
                break;
            case 8:
                printf("Has elegido el censo de fantasmas 👻\n");
                printf("Funcionalidad en desarrollo...\n");
                break;
            case 9:
                printf("Has elegido el cifrado del vampiro (ROT-N) 🧛\n");
                printf("Funcionalidad en desarrollo...\n");
                break;
            case 0:
                printf("¡Hasta la próxima! 🎃👻\n");
                sleep(1);
                exit(EXIT_SUCCESS);
            default:
                printf("Opción no válida. Por favor, elige de nuevo.\n");
                break;
        }

        printf("Presiona Enter para continuar...");
        getchar(); // Limpiar buffer
        getchar(); // Espera a que el usuario presione Enter
        
        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } while(o != 0);
    exit(EXIT_SUCCESS);
}