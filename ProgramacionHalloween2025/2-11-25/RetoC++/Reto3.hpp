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

void mostrarMenu();

void reto3();

#endif // RETO3_HPP