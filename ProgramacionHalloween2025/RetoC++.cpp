#include <iostream>
#include <string>
#include <cctype>    // Para isalpha, isdigit
using namespace std;

// Implementación de la función contar_letras_cadena
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
         << n_digitos << " nº, " 
         << n_otros << " caracteres especiales" << endl;
}

void limpiar_pantalla();
void normalizar_cadena(string &cadena);

int main() {
    cout << "¡Feliz Halloween 2025! 🎃👻" << endl
         << "·Realizado en C++" << endl
         << "·Autor: Juan Luis Prieto Panadero 👨‍💻" << endl
         << "·Contacto: i22prpaj@uco.es ✉" << endl
         << "·Estudiante de Ingeniería Informática en la EPSC" << endl
         << "·Mención: Computación" << endl
         << "Presiona Enter para continuar...";
    getchar();

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    int o = 0;
    string cadena;
    do{
        cout << "Menú de Halloween 2025 🎃👻" << endl
             << "1. Contar caramelos 🍬" << endl
             << "2. Limpiar el conjuro 🧙" << endl
             << "3. Inventario de calabazas 🎃" << endl
             << "4. Truco o Trato 🎭" << endl
             << "5. Ruta en el cementerio (BFS) 💀" << endl
             << "6. Compresor de aullidos (RLE) 🐺" << endl
             << "7. Agenda embrujada 📅 " << endl
             << "8. Censo de fantasmas 👻 " << endl
             << "9. Cifrado del vampiro (ROT-N) 🧛" << endl
             << "0. Salir 🚪" << endl
             << "Elige una opción: ";
        cin >> o;
        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch(o){
            case 1:
                cout << "Has elegido contar caramelos 🍬" << endl
                     << "Introduce una cadena: ";
                cin >> cadena;
                contar_letras_cadena(cadena);
                cout << "La longitud total de la cadena es: " << cadena.length() << endl;
                break;
            case 2:
                cout << "Has elegido limpiar el conjuro 🧙" << endl
                     << "Introduce una cadena: ";
                cin >> cadena;
                //normalizar_cadena(cadena);
                cout << "Cadena normalizada: " << cadena << endl;
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
                cout << "¡Hasta la próxima! 🎃👻" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elige de nuevo." << endl;
                break;
        }

        cout << "Presiona Enter para continuar...";
        while(getchar() != '\n'); // Limpiar buffer
            getchar(); // Esperar Enter
        
        // Limpiar pantalla después de la selección
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } while(o != 0);
    return 0;
}