#include "rednacional.h"
#include <iostream>


int main() {
    // Crear una estación de servicio con coordenadas y capacidad del tanque
    estacion est("Estacion Central", 1001, "Juan Perez", "Centro", 45.2, -73.5, 300, 500, 400);

    // Crear surtidores dinámicamente (asegúrate de liberar esta memoria después)
    surtidor* surt1 = new surtidor("S001", "ModeloA", true);
    surtidor* surt2 = new surtidor("S002", "ModeloB", true);
    surtidor* surt3 = new surtidor("S003", "ModeloC", true);

    // Agregar surtidores a la estación
    est.agregarSurtidor(surt1);
    est.agregarSurtidor(surt2);
    est.agregarSurtidor(surt3);

    // Mostrar detalles de la estación
    est.mostrarEstacion();

    // Crear algunas transacciones para cada surtidor
    transaccion venta1("Regular", 50, 100, "Efectivo", "1234567890");
    transaccion venta2("Premium", 30, 150, "TDebito", "9876543210");

    transaccion venta3("EcoExtra", 40, 200, "TCredito", "2233445566");
    transaccion venta4("Regular", 60, 300, "Efectivo", "1122334455");

    transaccion venta5("Premium", 45, 225, "TDebito", "9988776655");
    transaccion venta6("Regular", 75, 375, "Efectivo", "5566778899");

    // Registrar ventas en los surtidores
    surt1->registrarVenta(venta1);
    surt1->registrarVenta(venta2);

    surt2->registrarVenta(venta3);
    surt2->registrarVenta(venta4);

    surt3->registrarVenta(venta5);
    surt3->registrarVenta(venta6);

    // Mostrar transacciones de cada surtidor
    std::cout << "\nTransacciones del surtidor S001:\n";
    surt1->consultarTransacciones();

    std::cout << "\nTransacciones del surtidor S002:\n";
    surt2->consultarTransacciones();

    std::cout << "\nTransacciones del surtidor S003:\n";
    surt3->consultarTransacciones();

    // Mostrar detalles completos de la estación después de registrar ventas
    std::cout << "\nDetalles de la Estación Central:\n";
    est.mostrarEstacion();

    // Eliminar un surtidor (el segundo surtidor, S002)
    std::cout << "\nEliminando surtidor S002...\n";
    est.eliminarSurtidor(1);  // Elimina el surtidor en la posición 1 (S002)

    // Mostrar detalles de la estación después de eliminar el surtidor
    std::cout << "\nDetalles de la estacion despues de eliminar S002:\n";
    est.mostrarEstacion();

    // Liberar la memoria de los surtidores restantes
    delete surt1;
    delete surt3;

    return 0;
}

