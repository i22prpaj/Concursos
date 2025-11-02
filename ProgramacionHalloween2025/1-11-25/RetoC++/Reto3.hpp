#ifndef RETO3_HPP
#define RETO3_HPP

#include <iostream>
#include <string>
#include <map>

using namespace std;

class InventarioCalabazas {
    private:
        map<string, int> inventario_;

    public:
        void consultarStock(const string& nombre) const {
            auto it = inventario_.find(nombre);
            if (it == inventario_.end()) {
                cout << "'" << nombre << "' no existe en el inventario" << endl;
            } else {
                cout << "Stock de '" << nombre << "': " << it->second << " unidades" << endl;
            }
        }

        void mostrarInventario() const {
            cout << "╔════════════════════════════════════════════════╗" << endl
                 << "║       INVENTARIO DE CALABAZAS 🎃              ║" << endl
                 << "╚════════════════════════════════════════════════╝" << endl;
            int totalCalabazas = 0;
            if (inventario_.empty())
                cout << "  El inventario está vacío" << endl;
            else{
                for(auto par_val : inventario_){
                    cout << par_val.first << ": "
                              << par_val.second << " unidades" << endl;
                    totalCalabazas += par_val.second;
                }
            }
            cout << "================================================" << endl
                 << "Tipos diferentes: " << inventario_.size()
                 << " | Total calabazas: " << totalCalabazas << endl;
        }

        bool agregarCalabaza(const string& nombre, int cantidad) {
            if (cantidad <= 0) {
                cout << "Error: La cantidad debe ser mayor a 0" << endl;
                return false;
            }
            if (inventario_.find(nombre) != inventario_.end()) {
                inventario_[nombre] += cantidad;
                cout << "+ " << cantidad << " '" << nombre 
                          << "' agregadas. Nuevo stock: " << inventario_[nombre] << "\n";
            } else {
                inventario_[nombre] = cantidad;
                cout << "+ Nuevo tipo '" << nombre
                     << "' agregado con " << cantidad << " unidades.\n";
            }
            return true;
        }

        bool retirarCalabaza(const string& nombre, int cantidad) {
            if (cantidad <= 0) {
                cout << "Error: La cantidad debe ser mayor a 0\n";
                return false;
            }

            auto it = inventario_.find(nombre);
            if (it == inventario_.end()) {
                cout << "Error: '" << nombre << "' no existe en el inventario\n";
                return false;
            }
            if(cantidad > it->second){
                cout << "Error: Stock insuficiente de '" << nombre 
                          << "'. Stock actual: " << it->second 
                          << ", Solicitado: " << cantidad << "\n";
                return false;
            }
            it->second -= cantidad;
            cout << "- " << cantidad << " '" << nombre 
                      << "' retiradas. Stock restante: " << it->second << "\n";
            if (it->second == 0) {
                cout << "  (Stock agotado de '" << nombre << "')\n";
            }
            return true;
        }
};

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

#endif // RETO3_HPP