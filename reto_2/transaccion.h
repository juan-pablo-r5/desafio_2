#ifndef TRANSACCION_H
#define TRANSACCION_H
//Representa una transacción (venta) realizada por un surtidor,
//que incluye la cantidad de combustible vendido, el método de pago, y otros detalles.
#include <iostream>
#include <ctime>  // Para manejar la fecha y hora con time_t

class transaccion
{
public:
    time_t fecha;               // Fecha y hora de la transacción
    char categoriaCombustible[10]; // Regular, Premium, EcoExtra
    double cantidadLitros;       // Cantidad de litros vendidos
    double monto;                // Monto total pagado
    char metodoPago[15];         // Efectivo, TDebito, TCredito
    char documentoCliente[20];   // Documento del cliente

    // Constructor
    transaccion(const char* categoria = "", double litros = 0.0, double monto = 0.0,
                const char* metodo = "", const char* documento = "");

    // Método para mostrar los detalles de la transacción
    void mostrarDetalles() const;
};

#endif // TRANSACCION_H
