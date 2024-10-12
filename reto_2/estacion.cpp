#include "estacion.h"

// Constructor
estacion::estacion(const char* nom, int cod, const char* ger, const char* reg) {
    // Copiar el nombre de la estación
    int i = 0;
    while (nom[i] != '\0' && i < 49) {
        nombre[i] = nom[i];
        i++;
    }
    nombre[i] = '\0';  // Asegurar el carácter nulo final

    // Asignar el código
    codigo = cod;

    // Copiar el nombre del gerente
    i = 0;
    while (ger[i] != '\0' && i < 49) {
        gerente[i] = ger[i];
        i++;
    }
    gerente[i] = '\0';  // Asegurar el carácter nulo final

    // Copiar la región
    i = 0;
    while (reg[i] != '\0' && i < 9) {
        region[i] = reg[i];
        i++;
    }
    region[i] = '\0';  // Asegurar el carácter nulo final

    // Inicialización de las coordenadas GPS
    coordenadas[0] = 0.0;
    coordenadas[1] = 0.0;

    // Inicialización del tanque de combustible con valores por defecto
    tanque[0] = 0;  // Regular
    tanque[1] = 0;  // Premium
    tanque[2] = 0;  // EcoExtra
}

// Establecer el nombre de la estación
void estacion::establecerNombre(const char* nom) {
    int i = 0;
    while (nom[i] != '\0' && i < 49) {
        nombre[i] = nom[i];
        i++;
    }
    nombre[i] = '\0';  // Asegurar el carácter nulo final
}

// Establecer el código de la estación
void estacion::establecerCodigo(int cod) {
    codigo = cod;
}

// Establecer el gerente de la estación
void estacion::establecerGerente(const char* ger) {
    int i = 0;
    while (ger[i] != '\0' && i < 49) {
        gerente[i] = ger[i];
        i++;
    }
    gerente[i] = '\0';  // Asegurar el carácter nulo final
}

// Establecer la región de la estación
void estacion::establecerRegion(const char* reg) {
    int i = 0;
    while (reg[i] != '\0' && i < 9) {
        region[i] = reg[i];
        i++;
    }
    region[i] = '\0';  // Asegurar el carácter nulo final
}

// Establecer las coordenadas GPS
void estacion::establecerCoordenadas(double latitud, double longitud) {
    coordenadas[0] = latitud;
    coordenadas[1] = longitud;
}

// Establecer la capacidad del tanque de combustible
void estacion::establecerCapacidadTanque(double regular, double premium, double ecoExtra) {
    tanque[0] = regular;
    tanque[1] = premium;
    tanque[2] = ecoExtra;
}

// Mostrar los detalles de la estación
void estacion::mostrarEstacion() const {
    std::cout << "Estacion: " << nombre << " (Codigo: " << codigo << ")\n";
    std::cout << "Gerente: " << gerente << "\nRegion: " << region << "\n";
    std::cout << "Coordenadas: (" << coordenadas[0] << ", " << coordenadas[1] << ")\n";
    std::cout << "Capacidad del tanque - Regular: " << tanque[0]
              << ", Premium: " << tanque[1] << ", EcoExtra: " << tanque[2] << "\n";
}






