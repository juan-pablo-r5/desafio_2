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
    surtidores = new surtidor*[capacidadSurtidores];  // Inicializar array dinámico de punteros a surtidores
}

// Constructor con parámetros
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
    surtidores = new surtidor*[capacidadSurtidores];  // Inicializar array dinámico de punteros a surtidores
}

// Destructor
estacion::~estacion() {
    for (int i = 0; i < numeroSurtidores; ++i) {
        delete surtidores[i];  // Liberar la memoria de cada surtidor
    }
    delete[] surtidores;  // Liberar el array dinámico de punteros a surtidores
}

// Redimensionar el array dinámico de surtidores
void estacion::redimensionarSurtidores() {
    capacidadSurtidores *= 2;
    surtidor** nuevoArray = new surtidor*[capacidadSurtidores];
    for (int i = 0; i < numeroSurtidores; ++i) {
        nuevoArray[i] = surtidores[i];
    }
    delete[] surtidores;
    surtidores = nuevoArray;
}

// Agregar un surtidor a la estación
void estacion::agregarSurtidor(surtidor* surtidor) {
    if (numeroSurtidores == capacidadSurtidores) {
        redimensionarSurtidores();
    }
    surtidores[numeroSurtidores++] = surtidor;
}

// Eliminar un surtidor de la estación por índice
void estacion::eliminarSurtidor(int indice) {
    if (indice < 0 || indice >= numeroSurtidores) {
        std::cout << "Índice inválido.\n";
        return;
    }
    delete surtidores[indice];  // Liberar la memoria del surtidor eliminado
    for (int i = indice; i < numeroSurtidores - 1; ++i) {
        surtidores[i] = surtidores[i + 1];
    }
    numeroSurtidores--;
}
void estacion::mostrarEstacion() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Cpdigo: " << codigo << "\n";
    std::cout << "Gerente: " << gerente << "\n";
    std::cout << "Regipn: " << region << "\n";
    std::cout << "Coordenadas: (" << coordenadas[0] << ", " << coordenadas[1] << ")\n";
    std::cout << "Capacidad del tanque - Regular: " << tanque[0] << " litros\n";
    std::cout << "Capacidad del tanque - Premium: " << tanque[1] << " litros\n";
    std::cout << "Capacidad del tanque - EcoExtra: " << tanque[2] << " litros\n";
    std::cout << "Numero de surtidores: " << numeroSurtidores << "\n";
}

// Mostrar todos los surtidores de la estación
void estacion::mostrarSurtidores() const {
    for (int i = 0; i < numeroSurtidores; ++i) {
        std::cout << "Surtidor " << (i + 1) << ": " << surtidores[i]->codigo << "\n";
    }
}

// Obtener un surtidor específico por índice
surtidor* estacion::getSurtidor(int indice) {
    if (indice >= 0 && indice < numeroSurtidores) {
        return surtidores[indice];
    }
    throw std::out_of_range("indice de surtidor invalido.");
}

