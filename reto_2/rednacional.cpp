#include "rednacional.h"

// Constructor de la red nacional
rednacional::rednacional() {
    capacidadEstaciones = 2;  // Capacidad inicial
    numeroEstaciones = 0;
    estaciones = nullptr;
    estaciones = new estacion[capacidadEstaciones];
}

// Destructor
rednacional::~rednacional() {
    delete[] estaciones;  // Liberar la memoria del array dinámico
}

// Método privado para redimensionar el array dinámico
void rednacional::redimensionar() {
    capacidadEstaciones *= 2;
    estacion* nuevoArray = new estacion[capacidadEstaciones];
    for (int i = 0; i < numeroEstaciones; ++i) {
        nuevoArray[i] = estaciones[i];  // Copiar los datos existentes al nuevo array
    }
    delete[] estaciones;  // Liberar el array antiguo
    estaciones = nuevoArray;
}

// Agregar una nueva estación a la red
void rednacional::agregarEstacion(const estacion& estacione) {
    if (numeroEstaciones == capacidadEstaciones) {
        redimensionar();  // Redimensionar si no hay espacio suficiente
    }
    estaciones[numeroEstaciones++] = estacione;
}

// Eliminar una estación de la red por índice
void rednacional::eliminarEstacion(int indice) {
    if (indice < 0 || indice >= numeroEstaciones) {
        std::cout << "Índice inválido.\n";
        return;
    }
    // Desplazar las estaciones para llenar el hueco dejado por la estación eliminada
    for (int i = indice; i < numeroEstaciones - 1; ++i) {
        estaciones[i] = estaciones[i + 1];
    }
    numeroEstaciones--;
}

// Mostrar la información de todas las estaciones
void rednacional::mostrarEstaciones() const {
    if (numeroEstaciones == 0) {
        std::cout << "No hay estaciones en la red.\n";
        return;
    }

    for (int i = 0; i < numeroEstaciones; ++i) {
        std::cout << "Estación " << (i + 1) << ":\n";
        estaciones[i].mostrarEstacion();
        std::cout << "-----------------------\n";
    }
}
