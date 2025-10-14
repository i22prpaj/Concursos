#include <iostream>
using namespace std;

int main() {
    cout << "¡Feliz Halloween 2025!" << endl
         << "Autor: Juan Luis Prieto Panadero" << endl
         << "Contacto: i22prpaj@uco.es" << endl
         << "Estudiante de Ingeniería Informática en la EPSC" << endl
         << "Mención: Computación" << endl;

    int o = 0;
    do{
        cout << "1.Contar caramelos 🍬" << endl
             << "2.Limpiar el conjuro 🧙" << endl
             << "3.Inventario de calabazas 🎃" << endl
             << "4.Truco o Trato 🎭" << endl
             << "5.Ruta en el cementerio (BFS)" << endl
             << "6.Compresor de aullidos (RLE) 🐺" << endl
             << "7.Agenda embrujada 📅 " << endl
             << "8.Censo de fantasmas 👻 " << endl
             << "9.Cifrado del vampiro (ROT-N)🧛" << endl
             << "0.Salir 🚪" << endl
             << "Elige una opción: ";
        cin >> o;
        switch(o){
            case 1:
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
                cout << "¡Hasta la próxima! 🎃👻" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elige de nuevo." << endl;
                break;
        }
    } while(o != 0);
    return 0;
}