#ifndef RETO4_HPP
#define RETO4_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Calcular la media
double calcularMedia(const vector<int>& edades) {
    if (edades.empty()) 
        return 0;
    int suma = 0;
    for (int edad : edades)
        suma += edad;
    return static_cast<double>(suma) / edades.size();
}

// Calcular la mediana
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
    cout << "\n=== DECISIÓN ===" << endl
         << "Media: " << media << " años" << endl
         << "Mediana: " << mediana << " años" << endl;

    if (media < 12 && mediana < 12) {
        cout << "\n🍬 ¡TRATO! (Dulces)" << endl
             << "Razón: Grupo de niños pequeños (media y mediana < 12)" << endl;
    } else if (media >= 15 && mediana >= 15) {
        cout << "\n🎃 ¡TRUCO! (Broma o actividad)" << endl
             << "Razón: Grupo de adolescentes/adultos (media y mediana >= 15)" << endl;
    } else if (media >= 12 && mediana >= 12) {
        cout << "\n🎭 ¡TRUCO Y TRATO!" << endl
             << "Razón: Grupo mixto de pre-adolescentes y mayores" << endl;
    } else {
        cout << "\n🍭 ¡TRATO! (Dulces)" << endl
             << "Razón: Predominan los niños en el grupo" << endl;
    }
}

#endif // RETO4_HPP