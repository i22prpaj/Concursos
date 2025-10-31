#include <stdio.h> // For printf, scanf
#include <string.h> // For strlen
#include <stdlib.h> // For system("cls"), exit
#include <unistd.h> // For sleep
#include <ctype.h>  // For isalpha, isdigit, tolower
#include <stdbool.h>

#define SIZE 100

void contar_letras_cadena(char *cadena){
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

void limpiar_pantalla();

// Estructura para mapeo de tildes
typedef struct {
    char original;
    char reemplazo;
} TildeMap;

char *normalizar_cadena(const char *entrada, char *salida){
    // Tabla de mapeo de tildes
    TildeMap tabla[] = {
        {'á','a'}, {'à','a'}, {'ä','a'}, {'â','a'},
        {'é','e'}, {'è','e'}, {'ë','e'}, {'ê','e'},
        {'í','i'}, {'ì','i'}, {'ï','i'}, {'î','i'},
        {'ó','o'}, {'ò','o'}, {'ö','o'}, {'ô','o'},
        {'ú','u'}, {'ù','u'}, {'ü','u'}, {'û','u'},
        {'ñ','n'}, {'ç','c'}
    };
    int tabla_size = sizeof(tabla) / sizeof(tabla[0]);
    int j = 0;
    for(int i = 0; entrada[i] != '\0'; i++){
        char c = tolower((unsigned char)entrada[i]);
        //c = eliminar_tilde(c);
        for (int k = 0; k < tabla_size; k++) {
            if (c == tabla[k].original) {
                c = tabla[k].reemplazo;
                break;
            }
        }
        /*if(!isalnum(c)){
            // Desplazar caracteres hacia la izquierda, dejando los no-alfanuméricos fuera (derecha)
            for(int j = i; cadena[j] != '\0'; j++){
                cadena[j] = cadena[j + 1];
            }
            i--; // Stay at the same index to check the new character
        }*/
        if (isalnum((unsigned char)c)) {
            salida[j++] = c;
        }
    }
    salida[j] = '\0';
    return salida;
}

#define MAX_NAME 100
#define MAX_TYPES 50
// Estructura para almacenar tipo de calabaza y su cantidad
typedef struct {
    char name[MAX_NAME];
    int cant;
} TipoCalabaza;

// Función para buscar si un tipo ya existe en el inventario
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
                void reto3();
                break;
            case 4:
                printf("Has elegido el truco o trato 🎭\n");
                printf("Esta opción aún no está implementada.\n");
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