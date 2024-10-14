#include "estacion.h"
#include "estacion.h"

// Constructor por defecto
estacion::estacion() {
    nombre = "Sin nombre";
    codigo = 0;
    gerente = "Sin gerente";
    region = "Sin region";
    coordenadas[0] = 0.0;
    coordenadas[1] = 0.0;
    tanque[0] = tanque[1] = tanque[2] = 0.0;
    numeroSurtidores = 0;
    capacidadSurtidores = 2;
    surtidores = new surtidor*[capacidadSurtidores];  // Punteros a surtidores
}

// Constructor parametrizado
estacion::estacion(const std::string& nom, int cod, const std::string& ger, const std::string& reg, double latitud, double longitud, double regular, double premium, double ecoExtra) {
    nombre = nom;
    codigo = cod;
    gerente = ger;
    region = reg;

    coordenadas[0] = latitud;
    coordenadas[1] = longitud;

    tanque[0] = regular;
    tanque[1] = premium;
    tanque[2] = ecoExtra;

    capacidadSurtidores = 2;
    numeroSurtidores = 0;
    surtidores = new surtidor*[capacidadSurtidores];  // Punteros a surtidores
}

// Destructor para liberar memoria
estacion::~estacion() {
    for (int i = 0; i < numeroSurtidores; ++i) {
        delete surtidores[i];  // Liberar los surtidores apuntados
    }
    delete[] surtidores;  // Liberar el array de punteros
}

// Método privado para redimensionar el array de punteros a surtidores
void estacion::redimensionarSurtidores() {
    capacidadSurtidores *= 2;
    surtidor** nuevoArray = new surtidor*[capacidadSurtidores];
    for (int i = 0; i < numeroSurtidores; ++i) {
        nuevoArray[i] = surtidores[i];
    }
    delete[] surtidores;
    surtidores = nuevoArray;
}

// Agregar un nuevo surtidor a la estación
void estacion::agregarSurtidor(surtidor* surtidors) {
    if (numeroSurtidores == capacidadSurtidores) {
        redimensionarSurtidores();
    }
    surtidores[numeroSurtidores++] = surtidors;  // Solo almacenar el puntero
}

// Eliminar un surtidor de la estación por su índice
void estacion::eliminarSurtidor(int indice) {
    if (indice < 0 || indice >= numeroSurtidores) {
        std::cout << "Índice inválido.\n";
        return;
    }

    delete surtidores[indice];  // Liberar la memoria del surtidor eliminado

    // Desplazar los punteros para llenar el hueco dejado por el surtidor eliminado
    for (int i = indice; i < numeroSurtidores - 1; ++i) {
        surtidores[i] = surtidores[i + 1];
    }
    numeroSurtidores--;
}

// Mostrar los detalles de la estación
void estacion::mostrarEstacion() const {
    std::cout << "Estacion: " << nombre << " (Codigo: " << codigo << ")\n";
    std::cout << "Gerente: " << gerente << "\nRegion: " << region << "\n";
    std::cout << "Coordenadas: (" << coordenadas[0] << ", " << coordenadas[1] << ")\n";
    std::cout << "Capacidad del tanque - Regular: " << tanque[0]
              << ", Premium: " << tanque[1] << ", EcoExtra: " << tanque[2] << "\n";
    std::cout << "Numero de surtidores: " << numeroSurtidores << "\n";

    for (int i = 0; i < numeroSurtidores; ++i) {
        std::cout << "- Surtidor " << (i + 1) << ": " << surtidores[i]->codigo << "\n";
    }
}
