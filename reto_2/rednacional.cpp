#include "rednacional.h"
// Constructor
rednacional::rednacional() {
    capacidadEstaciones = 2;  // Capacidad inicial
    numeroEstaciones = 0;
    estaciones=nullptr;
    estaciones = new estacion[capacidadEstaciones];  // Crear array dinámico
}

// Destructor
rednacional::~rednacional() {
    delete[] estaciones;  // Liberar la memoria del array dinámico
}

// Redimensionar el array dinámico de estaciones
void rednacional::redimensionar() {
    capacidadEstaciones *= 2;
    estacion* nuevoArray = new estacion[capacidadEstaciones];
    for (int i = 0; i < numeroEstaciones; ++i) {
        nuevoArray[i] = estaciones[i];  // Copiar las estaciones existentes al nuevo array
    }
    delete[] estaciones;  // Liberar el array antiguo
    estaciones = nuevoArray;
}

// Agregar una nueva estación a la red nacional
void rednacional::agregarEstacion(const estacion& estacione) {
    if (numeroEstaciones == capacidadEstaciones) {
        redimensionar();  // Redimensionar si no hay espacio suficiente
    }
    estaciones[numeroEstaciones++] = estacione;
}

// Obtener una estación específica por su índice
estacion& rednacional::getEstacion(int indice) {
    if (indice >= 0 && indice < numeroEstaciones) {
        return estaciones[indice];
    }
    throw std::out_of_range("Índice de estación inválido.");
}

// Eliminar una estación de la red por su índice
void rednacional::eliminarEstacion(int indice) {
    if (indice < 0 || indice >= numeroEstaciones) {
        std::cout << "Índice inválido.\n";
        return;
    }
    for (int i = indice; i < numeroEstaciones - 1; ++i) {
        estaciones[i] = estaciones[i + 1];  // Desplazar las estaciones
    }
    numeroEstaciones--;
}

// Mostrar todas las estaciones en la red
void rednacional::mostrarEstaciones() const {
    if (numeroEstaciones == 0) {
        std::cout << "No hay estaciones en la red.\n";
        return;
    }

    for (int i = 0; i < numeroEstaciones; ++i) {
        std::cout << "Estacion " << (i + 1) << ":\n";
        estaciones[i].mostrarEstacion();
        std::cout << "-----------------------\n";
    }
}

// Retornar el número de estaciones actuales
int rednacional::getNumeroEstaciones() const {
    return numeroEstaciones;
}

