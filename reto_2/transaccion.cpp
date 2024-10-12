#include "transaccion.h"


// Constructor de la clase Transaccion
transaccion::transaccion(const char* categoria, double litros, double monto,
                         const char* metodo, const char* documento) {
    // Copiar la categoría del combustible
    int i = 0;
    while (categoria[i] != '\0' && i < 9) {
        categoriaCombustible[i] = categoria[i];
        i++;
    }
    categoriaCombustible[i] = '\0';

    // Copiar el método de pago
    i = 0;
    while (metodo[i] != '\0' && i < 14) {
        metodoPago[i] = metodo[i];
        i++;
    }
    metodoPago[i] = '\0';

    // Copiar el documento del cliente
    i = 0;
    while (documento[i] != '\0' && i < 19) {
        documentoCliente[i] = documento[i];
        i++;
    }
    documentoCliente[i] = '\0';

    // Inicializar los litros vendidos y el monto pagado
    cantidadLitros = litros;
    this->monto = monto;

    // Establecer la fecha y hora actual
    fecha = time(0);
}

// Método para mostrar los detalles de la transacción
void transaccion::mostrarDetalles() const {
    char buffer[80];
    struct tm* timeinfo = localtime(&fecha);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    std::cout << "Fecha: " << buffer << "\n"
              << "Combustible: " << categoriaCombustible << "\n"
              << "Litros: " << cantidadLitros << "\n"
              << "Monto: $" << monto << "\n"
              << "Método de pago: " << metodoPago << "\n"
              << "Documento del cliente: " << documentoCliente << "\n";
}

