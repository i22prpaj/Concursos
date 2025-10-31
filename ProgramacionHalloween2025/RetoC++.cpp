#include <iostream>
#include <string>
#include <cctype> // Para isalpha, isdigit, tolower
#include <map>
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

string normalizar_cadena(string &cadena){
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
            cout << "╔════════════════════════════════════════════════╗" << endl;
            cout << "║       INVENTARIO DE CALABAZAS 🎃              ║" << endl;
            cout << "╚════════════════════════════════════════════════╝" << endl;
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

        bool agregarCalabaza(const string& nombre, int cantidad){
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

        bool retirarCalabaza(const string& nombre, int cantidad){
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
                //inventario_.erase(it); //Se podría eliminar, ya dependería de como quisieramos que fuese la BD
            }
            return true;
        }
};

void mostrarMenu() {
    cout << "\n--- MENÚ DE OPCIONES ---\n";
    cout << "1. Agregar calabazas\n";
    cout << "2. Retirar calabazas\n";
    cout << "3. Consultar stock\n";
    cout << "4. Mostrar inventario completo\n";
    cout << "0. Salir\n";
    cout << "Opción: ";
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
                cadena = normalizar_cadena(cadena);
                cout << "Cadena normalizada: " << cadena << endl;
                break;
            case 3:
                cout << "Has elegido el inventario de calabazas 🎃" << endl;
                reto3();
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