# 🎯 Algoritmos y Soluciones Detalladas

Este documento contiene explicaciones detalladas de cada algoritmo implementado en el concurso de Halloween 2025.

## 🍬 1. Contar Caramelos
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(1)

```c
// Ejemplo de implementación
void contar_letras_cadena(char *cadena) {
    int longitud = strlen(cadena);
    int letras = 0, numeros = 0, especiales = 0;
    
    for(int i = 0; i < longitud; i++) {
        if(isalpha(cadena[i])) letras++;
        else if(isdigit(cadena[i])) numeros++;
        else especiales++;
    }
    
    printf("Letras: %d, Números: %d, Especiales: %d\n", 
           letras, numeros, especiales);
}
```

## 🧙 2. Limpiar el Conjuro
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(1)

Normaliza una cadena eliminando tildes, convirtiendo a minúsculas y quitando caracteres especiales.

## 🎃 3. Inventario de Calabazas
**Complejidad temporal:** O(n)  
**Complejidad espacial:** O(k) donde k es el número de tipos únicos

Utiliza estructuras de datos para contar elementos por categoría.

## 🎭 4. Truco o Trato
**Algoritmo:** Cálculo de media y mediana
**Decisión:** Si media > mediana → "Trato", sino → "Truco"

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