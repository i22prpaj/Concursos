#include "Reto3.hpp"

void mostrarMenu() {
    cout << "--- MENÚ DE OPCIONES ---" << endl
        << "1. Agregar calabazas" << endl
        << "2. Retirar calabazas" << endl
        << "3. Consultar stock" << endl
        << "4. Mostrar inventario completo" << endl
        << "0. Salir" << endl
        << "Opción: ";
}

void reto3(){
    InventarioCalabazas inventario;
    int opcion, cant;
    string nombre;
    // Datos iniciales de ejemplo
    cout << "=== INICIALIZANDO INVENTARIO ===\n\n";
    inventario.agregarCalabaza("Calabaza naranja pequeña", 5);
    inventario.agregarCalabaza("Calabaza blanca", 3);
    inventario.agregarCalabaza("Calabaza naranja grande", 2);
    inventario.agregarCalabaza("Calabaza verde", 4);
    do{
        mostrarMenu();
        cin >> opcion;

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch(opcion){
            case 1: // Agregar calabazas
                cout << "Introduce el nombre de la calabaza a agregar: ";
                //cin.ignore();
                getline(cin, nombre);
                cout << "Introduce la cantidad: ";
                cin >> cant;
                inventario.agregarCalabaza(nombre, cant);
                break;
            case 2: // Retirar calabazas
                cout << "Introduce el nombre de la calabaza a retirar: ";
                //cin.ignore();
                getline(cin, nombre);
                cout << "Introduce la cantidad: ";
                cin >> cant;
                inventario.retirarCalabaza(nombre, cant);
                break;
            case 3: // Consultar stock
                cout << "Introduce el nombre de la calabaza a consultar: ";
                cin.ignore();
                getline(cin, nombre);
                inventario.consultarStock(nombre);
                break;
            case 4: // Mostrar inventario
                inventario.mostrarInventario();
                break;
            case 0:
                cout << "Saliendo del menú...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elige de nuevo.\n";
                break;
        }
    }while(opcion != 0);
}