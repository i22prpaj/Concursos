#include <stdio.h> // For printf, scanf
#include <string.h> // For strlen
#include <stdlib.h> // For system("cls"), exit
#include <unistd.h> // For sleep
#include <ctype.h>  // For isalpha, isdigit, tolower

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

/*char eliminar_tilde(char c) {
    char *tildes = "áàäâéèëêíìïîóòöôúùüûñç";
    char *sin =    "aaaaeeeeiiiioooouuuunc";
    char *p = strchr(tildes, c); //compara caracter, devuelve la primera ocurrencia
    if (p) {
        return sin[p - tildes];
    } 
    else {
        return c;
    }
}*/

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

/*char *normalizar_cadena(const char *entrada, char *salida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = tolower((unsigned char)entrada[i]);
        c = eliminar_tilde(c);
        if (isalnum((unsigned char)c)) {
            salida[j++] = c; // Solo copiar si es alfanumérico
        }
    }
    salida[j] = '\0';
    return salida;
}*/

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