#include "rednacional.h"
#include <iostream>
#include<string>

void mostrarMenu();
void agregarEstacion(rednacional& red);
void agregarSurtidor(rednacional& red);
void eliminarEstacion(rednacional& red);
void eliminarSurtidor(rednacional& red);
void registrarVenta(rednacional& red);

int main() {
    rednacional red;  // Crear una red nacional de estaciones de servicio

    bool salir = false;
    while (!salir) {
        mostrarMenu();
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarEstacion(red);
            break;
        case 2:
            agregarSurtidor(red);
            break;
        case 3:
            eliminarEstacion(red);
            break;
        case 4:
            eliminarSurtidor(red);
            break;
        case 5:
            registrarVenta(red);
            break;
        case 6:
            red.mostrarEstaciones();  // Mostrar todas las estaciones
            break;
        case 7:
            salir = true;
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}

// Mostrar el menú principal
void mostrarMenu() {
    std::cout << "\n===== Menu Principal =====\n";
    std::cout << "1. Agregar estacion de servicio\n";
    std::cout << "2. Agregar surtidor a una estacion\n";
    std::cout << "3. Eliminar estacion de servicio\n";
    std::cout << "4. Eliminar surtidor de una estacion\n";
    std::cout << "5. Registrar venta en un surtidor\n";
    std::cout << "6. Mostrar todas las estaciones\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

// Función para agregar una estación a la red
void agregarEstacion(rednacional& red) {
    std::string nombre, gerente, region;
    int codigo;
    double latitud, longitud, regular, premium, ecoExtra;

    std::cout << "Ingrese el nombre de la estacion: ";
    std::cin >> nombre;
    std::cout << "Ingrese el código de la estacion: ";
    std::cin >> codigo;
    std::cout << "Ingrese el nombre del gerente: ";
    std::cin >> gerente;
    std::cout << "Ingrese la region (Norte/Centro/Sur): ";
    std::cin >> region;
    std::cout << "Ingrese las coordenadas GPS (latitud y longitud): ";
    std::cin >> latitud >> longitud;
    std::cout << "Ingrese la capacidad del tanque para combustible Regular: ";
    std::cin >> regular;
    std::cout << "Ingrese la capacidad del tanque para combustible Premium: ";
    std::cin >> premium;
    std::cout << "Ingrese la capacidad del tanque para combustible EcoExtra: ";
    std::cin >> ecoExtra;

    estacion nuevaEstacion(nombre, codigo, gerente, region, latitud, longitud, regular, premium, ecoExtra);
    red.agregarEstacion(nuevaEstacion);
    std::cout << "Estacion agregada exitosamente a la red nacional.\n";
}

// Función para agregar un surtidor a una estación
void agregarSurtidor(rednacional& red) {
    if (red.getNumeroEstaciones() == 0) {
        std::cout << "No hay estaciones disponibles.\n";
        return;
    }

    int indiceEstacion;
    std::cout << "Seleccione la estacion a la que desea agregar un surtidor:\n";
    red.mostrarEstaciones();
    std::cin >> indiceEstacion;

    if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
        std::cout << "indice de estación invalido.\n";
        return;
    }

    std::string codigo, modelo;
    std::cout << "Ingrese el codigo del surtidor: ";
    std::cin >> codigo;
    std::cout << "Ingrese el modelo del surtidor: ";
    std::cin >> modelo;

    surtidor nuevoSurtidor(codigo, modelo, true);
    red.getEstacion(indiceEstacion - 1).agregarSurtidor(&nuevoSurtidor);
    std::cout << "Surtidor agregado exitosamente a la estacion.\n";
}

// Función para eliminar una estación de la red
void eliminarEstacion(rednacional& red) {
    if (red.getNumeroEstaciones() == 0) {
        std::cout << "No hay estaciones disponibles para eliminar.\n";
        return;
    }

    int indiceEstacion;
    std::cout << "Seleccione la estacion que desea eliminar:\n";
    red.mostrarEstaciones();
    std::cin >> indiceEstacion;

    if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
        std::cout << "Índice de estacion invalido.\n";
        return;
    }

    red.eliminarEstacion(indiceEstacion - 1);
    std::cout << "Estacion eliminada exitosamente.\n";
}

// Función para eliminar un surtidor de una estación
void eliminarSurtidor(rednacional& red) {
    if (red.getNumeroEstaciones() == 0) {
        std::cout << "No hay estaciones disponibles.\n";
        return;
    }

    int indiceEstacion;
    std::cout << "Seleccione la estacion de la que desea eliminar un surtidor:\n";
    red.mostrarEstaciones();
    std::cin >> indiceEstacion;

    if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
        std::cout << "Índice de estacion invalido.\n";
        return;
    }

    estacion& est = red.getEstacion(indiceEstacion - 1);
    est.mostrarSurtidores();  // Asumimos que existe una función para mostrar los surtidores
    int indiceSurtidor;
    std::cout << "Seleccione el surtidor que desea eliminar: ";
    std::cin >> indiceSurtidor;

    est.eliminarSurtidor(indiceSurtidor - 1);
    std::cout << "Surtidor eliminado exitosamente.\n";
}

// Función para registrar una venta en un surtidor
void registrarVenta(rednacional& red) {
    if (red.getNumeroEstaciones() == 0) {
        std::cout << "No hay estaciones disponibles.\n";
        return;
    }

    int indiceEstacion;
    std::cout << "Seleccione la estacion donde desea registrar una venta:\n";
    red.mostrarEstaciones();
    std::cin >> indiceEstacion;

    if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
        std::cout << "indice de estacion invalido.\n";
        return;
    }

    estacion& est = red.getEstacion(indiceEstacion - 1);
    est.mostrarSurtidores();  // Asumimos que existe una función para mostrar los surtidores
    int indiceSurtidor;
    std::cout << "Seleccione el surtidor donde registrar la venta: ";
    std::cin >> indiceSurtidor;

    std::string categoria, metodo, documento;
    int litros, monto;
    std::cout << "Ingrese la categoria de combustible (Regular/Premium/EcoExtra): ";
    std::cin >> categoria;
    std::cout << "Ingrese la cantidad de litros vendidos: ";
    std::cin >> litros;
    std::cout << "Ingrese el monto total de la venta: ";
    std::cin >> monto;
    std::cout << "Ingrese el método de pago (Efectivo/TDebito/TCredito): ";
    std::cin >> metodo;
    std::cout << "Ingrese el documento del cliente: ";
    std::cin >> documento;

    transaccion nuevaVenta(categoria, litros, monto, metodo, documento);
    est.getSurtidor(indiceSurtidor - 1)->registrarVenta(nuevaVenta);
    std::cout << "Venta registrada exitosamente.\n";
}
/*
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
}*/

