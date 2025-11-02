#ifndef RETO2_H
#define RETO2_H

#include <ctype.h>
#include <string.h>

typedef struct {
    char original;
    char reemplazo;
} TildeMap;

char *normalizar_cadena(const char *entrada, char *salida) {
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
        for (int k = 0; k < tabla_size; k++) {
            if (c == tabla[k].original) {
                c = tabla[k].reemplazo;
                break;
            }
        }
        if (isalnum((unsigned char)c)) {
            salida[j++] = c;
        }
    }
    salida[j] = '\0';
    return salida;
}

#endif // RETO2_H