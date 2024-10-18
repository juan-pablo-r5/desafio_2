#ifndef TRANSACCION_H
#define TRANSACCION_H
//Representa una transacción (venta) realizada por un surtidor,
//que incluye la cantidad de combustible vendido, el método de pago, y otros detalles.
#include <iostream>
#include <ctime>  // Para manejar la fecha y hora con time_t

class transaccion {
public:
    time_t fecha;               // Fecha y hora de la transacción
    std::string categoriaCombustible;  // Regular, Premium, EcoExtra
    int cantidadLitros;          // Cantidad de litros vendidos
    int montos;                   // Monto total pagado
    std::string metodoPago;      // Efectivo, TDebito, TCredito
    std::string documentoCliente; // Documento del cliente (ahora string)

    // Constructor
    transaccion(const std::string& categoria = "", int litros=0, int monto=0,
                const std::string& metodo = "", const std::string& documento = "");


    // Método para mostrar los detalles de la transacción
    void mostrarDetalles() const;
};
#endif // TRANSACCION_H
