#ifndef RETO2_HPP
#define RETO2_HPP

#include <string>
#include <map>
#include <cctype>

using namespace std;

string normalizar_cadena(string &cadena) {
    string resultado;
    map<char, char> tabla = {
        {'á','a'}, {'à','a'}, {'â','a'}, {'ã','a'}, {'ä','a'},
        {'é','e'}, {'è','e'}, {'ê','e'}, {'ë','e'},
        {'í','i'}, {'ì','i'}, {'î','i'}, {'ï','i'},
        {'ó','o'}, {'ò','o'}, {'ô','o'}, {'õ','o'}, {'ö','o'},
        {'ú','u'}, {'ù','u'}, {'û','u'}, {'ü','u'},
        {'ñ','n'}, {'ç','c'}
    };
    for(auto &c : cadena) {
        c = tolower(c);
        if (tabla.count(c)) 
            c = tabla[c];
        if (isalnum(static_cast<unsigned char>(c)))
            resultado += c;
    }
    return resultado;
}

#endif // RETO2_HPP