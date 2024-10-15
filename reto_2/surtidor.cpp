#include "surtidor.h"
// Constructor del surtidor usando std::string
surtidor::surtidor(const std::string& cod, const std::string& mod, bool act) {
    codigo = cod;
    modelo = mod;
    activo = act;


    capacidadVentas = 4;  // Capacidad inicial mínima
    numeroVentas = 0;        // No hay ventas registradas al principio
    ventas = nullptr;
    ventas = new transaccion[capacidadVentas];  // Inicializar el array dinámico
}

// Destructor del surtidor
surtidor::~surtidor() {
    delete[] ventas;  // Liberar la memoria del array de ventas
}

// Método privado para redimensionar el array de ventas
void surtidor::redimensionarVentas() {
    capacidadVentas *= 2;  // Duplicar la capacidad del array dinámico de transacciones
    transaccion* nuevoArray = new transaccion[capacidadVentas];

    // Copiar las transacciones existentes al nuevo array
    for (int i = 0; i < numeroVentas; ++i) {
        nuevoArray[i] = ventas[i];
    }
    // Liberar la memoria del array antiguo
    delete[] ventas;
    // Asignar el nuevo array al puntero ventas
    ventas = nuevoArray;
}

// Registrar una nueva venta pasando un objeto `transaccion`
void surtidor::registrarVenta(const transaccion& nuevaVenta) {
    if (!activo) {
        std::cout << "El surtidor " << codigo << " esta inactivo y no puede registrar ventas.\n";
        return;
    }

    // Redimensionar el array de ventas si está lleno
    if (numeroVentas == capacidadVentas) {
        redimensionarVentas();  // Aumentar el tamaño del array si es necesario
    }

    // Agregar la venta al array, como en agregarSurtidor
    ventas[numeroVentas++] = nuevaVenta;

    std::cout << "Venta registrada en el surtidor " << codigo << ".\n";
}

// Consultar todas las transacciones realizadas por el surtidor
void surtidor::consultarTransacciones() const {
    if (numeroVentas == 0) {
        std::cout << "No hay transacciones registradas en el surtidor " << codigo << ".\n";
        return;
    }
    std::cout << "Transacciones del surtidor " << codigo << " (" << modelo << "):\n";
    for (int i = 0; i < numeroVentas; ++i) {
        ventas[i].mostrarDetalles();
        std::cout << "----------------------------\n";
    }
}

// Reportar las ventas por categoría de combustible
void surtidor::reportarVentasPorCategoria() const {
    double totalRegular = 0.0, totalPremium = 0.0, totalEcoExtra = 0.0;

    for (int i = 0; i < numeroVentas; ++i) {
        if (ventas[i].categoriaCombustible == "Regular") {
            totalRegular += ventas[i].cantidadLitros;
        } else if (ventas[i].categoriaCombustible == "Premium") {
            totalPremium += ventas[i].cantidadLitros;
        } else if (ventas[i].categoriaCombustible == "EcoExtra") {
            totalEcoExtra += ventas[i].cantidadLitros;
        }
    }

    std::cout << "Reporte de ventas por categoria en el surtidor " << codigo << " (" << modelo << "):\n";
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
