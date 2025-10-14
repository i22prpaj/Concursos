#include <stdio.h> // For printf, scanf
#include <string.h> // For strlen
#include <stdlib.h> // For system("cls")
#include <unistd.h> // For sleep

#define SIZE 100

void contar_letras_cadena(char *cadena);
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

    int o = 0;
    char cadena[SIZE];

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
                printf("La longitud de la cadena es: %lu\n", strlen(cadena));
                //contar_letras_cadena(cadena);
                printf("Presiona Enter para continuar...");
                getchar(); // Limpiar buffer
                getchar(); // Espera a que el usuario presione Enter
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 0:
                printf("¡Hasta la próxima! 🎃👻\n");
                sleep(1);
                break;
            default:
                printf("Opción no válida. Por favor, elige de nuevo.\n");
                break;
        }
        
        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } while(o != 0);
    return 0;
}