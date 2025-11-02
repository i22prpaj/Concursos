#include <iostream>
#include <string>
#include <vector>
#include "Reto1.hpp"
#include "Reto2.hpp"
#include "Reto3.hpp"
#include "Reto4.hpp"

using namespace std;

void limpiar_pantalla(); 

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

    int o = 0, n_personas, edad;
    string cadena;
    vector<int> edades;
    double media, mediana;
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
                cadena = normalizar_cadena(cadena);
                cout << "Cadena normalizada: " << cadena << endl;
                break;
            case 3:
                cout << "Has elegido el inventario de calabazas 🎃" << endl;
                reto3();
                break;
            case 4:
                cout << "Has elegido el truco o trato 🎭" << endl
                     << "¿Cuántas personas hay en el grupo? ";
                cin >> n_personas;
                if(n_personas <= 0){
                    cout << "Error: Debe haber al menos una persona." << endl;
                    break;
                }
                for (int i = 0; i < n_personas; i++) {
                    cout << "Edad de la persona " << (i + 1) << ": ";
                    cin >> edad;
                    if (edad < 0 || edad > 120) {
                        cout << "Error: Edad inválida." << endl;
                        break;
                    }
                    edades.push_back(edad);
                }
                //
                media = calcularMedia(edades);
                mediana = calcularMediana(edades);
                truco_trato(media, mediana);
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