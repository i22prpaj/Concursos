# 🎯 Algoritmos y Soluciones Detalladas

Este documento contiene explicaciones detalladas de cada algoritmo implementado en el concurso de Halloween 2025.

## 🍬 1. Contar Caramelos
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(1)

```cpp
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
         << n_digitos << " números, " 
         << n_otros << " caracteres especiales" << endl;
}
```

## 🧙 2. Limpiar el Conjuro
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(1)

Normaliza una cadena eliminando tildes, convirtiendo a minúsculas y quitando caracteres especiales.

```cpp
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
```

## 🎃 3. Inventario de Calabazas
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(k) donde k es el número de tipos únicos

Utiliza estructuras de datos para contar elementos por categoría.

```cpp
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
};
```

## 🎭 4. Truco o Trato
**Algoritmo:** Cálculo de media y mediana  
**Decisión:** Si media > mediana → "Trato", sino → "Truco"

```cpp
double calcularMedia(const vector<int>& edades) {
    if (edades.empty()) 
        return 0;
    int suma = 0;
    for (int edad : edades)
        suma += edad;
    return static_cast<double>(suma) / edades.size();
}

double calcularMediana(const vector<int>& edades) {
    if (edades.empty())
        return 0;
    vector<int> copia = edades;
    sort(copia.begin(), copia.end());
    size_t n = copia.size();
    if (n % 2 == 0)
        return (copia[n / 2 - 1] + copia[n / 2]) / 2.0;
    else
        return copia[n / 2];
}

void truco_trato(double media, double mediana) {
    cout << "\n=== DECISIÓN ===" << endl;
    cout << "Media: " << media << " años" << endl;
    cout << "Mediana: " << mediana << " años" << endl;

    if (media < 12 && mediana < 12) {
        cout << "\n🍬 ¡TRATO! (Dulces)" << endl;
        cout << "Razón: Grupo de niños pequeños (media y mediana < 12)" << endl;
    } else if (media >= 15 && mediana >= 15) {
        cout << "\n🎃 ¡TRUCO! (Broma o actividad)" << endl;
        cout << "Razón: Grupo de adolescentes/adultos (media y mediana >= 15)" << endl;
    } else if (media >= 12 && mediana >= 12) {
        cout << "\n🎭 ¡TRUCO Y TRATO!" << endl;
        cout << "Razón: Grupo mixto de pre-adolescentes y mayores" << endl;
    } else {
        cout << "\n🍭 ¡TRATO! (Dulces)" << endl;
        cout << "Razón: Predominan los niños en el grupo" << endl;
    }
}
```

## 💀 5. Ruta en el Cementerio (BFS)
**Complejidad temporal:** O(V + E)  
**Complejidad espacial:** O(V)

Implementación del algoritmo BFS para encontrar el camino más corto en un grafo no ponderado.

## 🐺 6. Compresor de Aullidos (RLE)
**Ejemplo:** "AAABBBCC" → "3A3B2C"

## 📅 7. Agenda Embrujada
**Algoritmo:** Detección de overlapping intervals
**Técnica:** Ordenamiento por tiempo de inicio

## 👻 8. Censo de Fantasmas
**Análisis estadístico:** Media, mediana, moda, desviación estándar

## 🧛 9. Cifrado del Vampiro (ROT-N)
**Algoritmo:** Cifrado César modificable
**Fórmula:** `nuevo_char = (char_original + n) % 26`

## 🧪 10. Lista de Pociones
**Estructura de datos:** Array o lista enlazada
**Operaciones:** CRUD (Create, Read, Update, Delete)

---

*Cada algoritmo está optimizado para el contexto del problema y mantiene la temática de Halloween.* 🎃