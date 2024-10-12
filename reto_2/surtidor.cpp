#include "surtidor.h"
#include <iostream>

// Constructor de la clase Surtidor
surtidor::surtidor(const char* cod, const char* mod, bool act) {
    int i = 0;
    while (cod[i] != '\0' && i < 19) {
        codigo[i] = cod[i];
        i++;
    }
    codigo[i] = '\0';

    i = 0;
    while (mod[i] != '\0' && i < 49) {
        modelo[i] = mod[i];
        i++;
    }
    modelo[i] = '\0';

    activo = act;

    capacidadVentas = 2;
    numeroVentas = 0;
    ventas = new transaccion[capacidadVentas];
}

// Destructor de la clase Surtidor
surtidor::~surtidor() {
    delete[] ventas;
}

// Método privado para redimensionar el array de ventas si es necesario
void surtidor::redimensionarVentas() {
    capacidadVentas *= 2;
    transaccion* nuevoArray = new transaccion[capacidadVentas];
    for (int i = 0; i < numeroVentas; ++i) {
        nuevoArray[i] = ventas[i];
    }
    delete[] ventas;
    ventas = nuevoArray;
}

// Registrar una nueva venta si el surtidor está activo
void surtidor::registrarVenta(const transaccion& venta) {
    if (!activo) {
        std::cout << "El surtidor " << codigo << " está inactivo y no puede registrar ventas.\n";
        return;
    }
    if (numeroVentas == capacidadVentas) {
        redimensionarVentas();
    }
    ventas[numeroVentas++] = venta;
    std::cout << "Venta registrada en el surtidor " << codigo << ".\n";
}

// Consultar todas las transacciones realizadas por el surtidor
void surtidor::consultarTransacciones() const {
    std::cout << "Transacciones del surtidor " << codigo << " (" << modelo << "):\n";
    for (int i = 0; i < numeroVentas; ++i) {
        std::cout << "- Venta " << (i + 1) << ": "
                  << ventas[i].categoriaCombustible << ", "
                  << ventas[i].cantidadLitros << " litros, $"
                  << ventas[i].monto << "\n";
    }
}

// Reportar las ventas por categoría de combustible
void surtidor::reportarVentasPorCategoria() const {
    double totalRegular = 0.0, totalPremium = 0.0, totalEcoExtra = 0.0;

    for (int i = 0; i < numeroVentas; ++i) {
        if (strcmp(ventas[i].categoriaCombustible, "Regular") == 0) {
            totalRegular += ventas[i].cantidadLitros;
        } else if (strcmp(ventas[i].categoriaCombustible, "Premium") == 0) {
            totalPremium += ventas[i].cantidadLitros;
        } else if (strcmp(ventas[i].categoriaCombustible, "EcoExtra") == 0) {
            totalEcoExtra += ventas[i].cantidadLitros;
        }
    }

    std::cout << "Reporte de ventas por categoría en el surtidor " << codigo << " (" << modelo << "):\n";
    std::cout << "Regular: " << totalRegular << " litros\n";
    std::cout << "Premium: " << totalPremium << " litros\n";
    std::cout << "EcoExtra: " << totalEcoExtra << " litros\n";
}

// Método para activar el surtidor
void surtidor::activar() {
    activo = true;
    std::cout << "Surtidor " << codigo << " activado.\n";
}

// Método para desactivar el surtidor
void surtidor::desactivar() {
    activo = false;
    std::cout << "Surtidor " << codigo << " desactivado.\n";
}

// Método para verificar si el surtidor está activo
bool surtidor::estaActivo() const {
    return activo;
}
