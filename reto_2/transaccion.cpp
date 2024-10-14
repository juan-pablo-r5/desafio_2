#include "transaccion.h"
// Constructor de la clase Transaccion usando std::string
transaccion::transaccion(const std::string& categoria, int litros, int monto,
                         const std::string& metodo, const std::string& documento) {
    categoriaCombustible = categoria;
    metodoPago = metodo;
    documentoCliente = documento;

    // Inicializar los litros vendidos y el monto pagado
    cantidadLitros = litros;
    montos = monto;

    // Establecer la fecha y hora actual
    fecha = time(0);
}
// Mostrar los detalles de la transacción
void transaccion::mostrarDetalles() const {
    // Formatear la fecha de la transacción
    char buffer[80];
    struct tm* timeinfo = localtime(&fecha);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    std::cout << "Fecha: " << buffer << "\n"
              << "Combustible: " << categoriaCombustible << "\n"
              << "Litros: " << cantidadLitros << "\n"
              << "Monto: $" << montos << "\n"
              << "Metodo de pago: " << metodoPago << "\n"
              << "Documento del cliente: " << documentoCliente << "\n";
}
