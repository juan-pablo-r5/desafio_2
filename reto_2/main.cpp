#include "rednacional.h"
#include <iostream>
#include<string>
#include <cstdlib>

int obtenerCapacidadAleatoria() {
    return 100 + rand() % 101;  // Genera un numero entre 100 y 200
}

int main() {
    rednacional red;  // Crear una red nacional de estaciones de servicio
    srand(time(0));
    bool salir = false;
    while (!salir) {
        std::cout << "\n===== Menu Principal ====="<<std::endl;
        std::cout << "1. Agregar estacion de servicio"<<std::endl;
        std::cout << "2. Agregar surtidor a una estacion"<<std::endl;
        std::cout << "3. Eliminar estacion de servicio"<<std::endl;
        std::cout << "4. Eliminar surtidor de una estacion"<<std::endl;
        std::cout << "5. Registrar venta en un surtidor"<<std::endl;
        std::cout << "6. Mostrar todas las estaciones"<<std::endl;
        std::cout << "7. Calcular monto total de ventas por categoria"<<std::endl;
        std::cout << "8. Reportar litros vendidos por categoria"<<std::endl;
        std::cout << "9. fijar precios"<<std::endl;
        std::cout << "10. Activar o Desactivar un surtidor "<<std::endl;
        std::cout << "11. Consultar historial de transacciones de surtidores dependiendo la estacion"<<std::endl;
        std::cout << "12. simular venta aleatoria"<<std::endl;
        std::cout << "13. salir del programa"<<std::endl;
        std::cout << "Seleccione una opcion: "<<std::endl;
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string nombre, gerente, region;
            int codigo;
            double latitud, longitud, regular, premium, ecoExtra;

            std::cout << "Ingrese el nombre de la estacion: "<< std::endl;
            std::cin >> nombre;
            std::cout << "Ingrese el codigo de la estacion: "<< std::endl;
            std::cin >> codigo;
            std::cout << "Ingrese el nombre del gerente: "<< std::endl;
            std::cin >> gerente;
            std::cout << "Ingrese la region (Norte/Centro/Sur): "<< std::endl;
            std::cin >> region;
            std::cout << "Ingrese las coordenadas GPS (latitud): "<< std::endl;
            std::cin >> latitud;
            std::cout << "Ingrese la longitud: "<< std::endl;
            std::cin >> longitud;

            // Opción para asignar capacidades de tanque aleatoriamente
            std::cout << "Desea asignar capacidades de tanque aleatorias (si/no)? ";
            std::string respuesta;
            std::cin >> respuesta;

            if (respuesta == "si") {
                regular = obtenerCapacidadAleatoria();
                premium = obtenerCapacidadAleatoria();
                ecoExtra = obtenerCapacidadAleatoria();
                std::cout << "Capacidades asignadas aleatoriamente.\n";
                std::cout << "Regular: " << regular << " litros\n";
                std::cout << "Premium: " << premium << " litros\n";
                std::cout << "EcoExtra: " << ecoExtra << " litros\n";
            } else {
                std::cout << "Ingrese la capacidad del tanque para combustible Regular: "<< std::endl;
                std::cin >> regular;
                std::cout << "Ingrese la capacidad del tanque para combustible Premium: "<< std::endl;
                std::cin >> premium;
                std::cout << "Ingrese la capacidad del tanque para combustible EcoExtra: "<< std::endl;
                std::cin >> ecoExtra;
            }

            estacion* nuevaEstacion = new estacion(nombre, codigo, gerente, region, latitud, longitud, regular, premium, ecoExtra);
            red.agregarEstacion(nuevaEstacion);  // Agregar puntero a la estación
            std::cout << "Estacion agregada exitosamente a la red nacional.\n";
            break;
        }
        case 2: {
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "escriba el numero de la estacion a la que desea agregar un surtidor:" << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "indice de estacion invalido." << std::endl;
                break;
            }

            std::string codigo, modelo;
            std::cout << "Ingrese el codigo del surtidor: " << std::endl;
            std::cin >> codigo;
            std::cout << "Ingrese el modelo del surtidor: " << std::endl;
            std::cin >> modelo;

            surtidor* nuevoSurtidor = new surtidor(codigo, modelo, true);  // Crear surtidor dinámicamente
            red.getEstacion(indiceEstacion - 1)->agregarSurtidor(nuevoSurtidor);  // Agregar a la estación
            std::cout << "Surtidor agregado exitosamente a la estacion." << std::endl;
            break;
        }
        case 3: {
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles para eliminar." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "Seleccione la estacion que desea eliminar:" << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "indice de estación invalido." << std::endl;
                break;
            }

            // Verificar si los surtidores están desactivados antes de eliminar
            estacion* est = red.getEstacion(indiceEstacion - 1);
            bool sePuedeEliminar = true;

            for (int i = 0; i < est->getNumeroSurtidores(); ++i) {
                if (est->getSurtidor(i)->estaActivo()) {
                    sePuedeEliminar = false;
                    break;
                }
            }

            if (!sePuedeEliminar) {
                std::cout << "No se puede eliminar la estacion. Hay surtidores activos." << std::endl;
                break;
            }

            red.eliminarEstacion(indiceEstacion - 1);
            break;
        }
        case 4: {
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "Seleccione la estacion de la que desea eliminar un surtidor:" << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "Índice de estacion invalido." << std::endl;
                break;
            }

            estacion* est = red.getEstacion(indiceEstacion - 1);
            est->mostrarSurtidores();  // Mostrar surtidores disponibles
            int indiceSurtidor;
            std::cout << "Seleccione el surtidor que desea eliminar: " << std::endl;
            std::cin >> indiceSurtidor;

            est->eliminarSurtidor(indiceSurtidor - 1);
            std::cout << "Surtidor eliminado exitosamente." << std::endl;
            break;
        }
        case 5: {
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "Escriba el numero de la estacion donde desea registrar una venta (ejemplo: estacion 1, entonces escriba 1): " << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "no existe esta estacion o no hay estaciones" << std::endl;
                break;
            }

            estacion* est = red.getEstacion(indiceEstacion - 1);

            // Verificar si la estación tiene surtidores
            if (est->getNumeroSurtidores() == 0) {
                std::cout << "No hay surtidores en esta estacion." << std::endl;
                break;
            }

            // Mostrar surtidores disponibles y verificar si están activos
            est->mostrarSurtidores();

            int indiceSurtidor;
            std::cout << "escriba el numero del surtidor donde registrar la venta(surtidor1 escribir 1): " << std::endl;
            std::cin >> indiceSurtidor;

            if (indiceSurtidor < 1 || indiceSurtidor > est->getNumeroSurtidores()) {
                std::cout << "no hay surtidores " << std::endl;
                break;
            }

            surtidor* surt = est->getSurtidor(indiceSurtidor - 1);

            // Verificar si el surtidor está activo
            if (!surt->estaActivo()) {
                std::cout << "El surtidor está inactivo. No se puede realizar la venta." << std::endl;
                break;
            }

            std::string categoria, metodo, documento;
            int litros;

            std::cout << "Ingrese la categoria de combustible (Regular/Premium/EcoExtra): " << std::endl;
            std::cin >> categoria;

            // Verificar si la categoría es válida
            if (categoria != "Regular" && categoria != "Premium" && categoria != "EcoExtra") {
                std::cout << "Categoria de combustible no existente" << std::endl;
                break;
            }

            std::cout << "Ingrese la cantidad de litros vendidos: " << std::endl;
            std::cin >> litros;

            // Obtener el precio del combustible basado en la categoría y región
            double precioPorLitro = 0.0;
            if (categoria == "Regular") {
                precioPorLitro = red.getPrecioRegular();
            } else if (categoria == "Premium") {
                precioPorLitro = red.getPrecioPremium();
            } else if (categoria == "EcoExtra") {
                precioPorLitro = red.getPrecioEcoExtra();
            }

            // Calcular el monto total de la venta
            double monto = litros * precioPorLitro;

            std::cout << "Ingrese el metodo de pago (Efectivo/TDebito/TCredito): " << std::endl;
            std::cin >> metodo;

            std::cout << "Ingrese el documento del cliente: " << std::endl;
            std::cin >> documento;

            // Registrar la venta
            transaccion nuevaVenta(categoria, litros, monto, metodo, documento);
            surt->registrarVenta(nuevaVenta);

            std::cout << "Venta registrada exitosamente. Monto total: $" << monto << std::endl;
            break;
        }
        case 6: {
            red.mostrarEstaciones();  // Mostrar todas las estaciones
            break;
        }
        case 7: {
            std::cout << "Calculando el monto total de ventas por categoria en cada estacion.\n";
            for (int i = 0; i < red.getNumeroEstaciones(); ++i) {
                estacion* est = red.getEstacion(i);
                est->calcularTotalVentasPorCategoria();
            }
            break;
        }
        case 8: {
            std::cout << "Reportando litros vendidos por categoria en cada estacion.\n";
            for (int i = 0; i < red.getNumeroEstaciones(); ++i) {
                estacion* est = red.getEstacion(i);
                est->calcularLitrosVendidosPorCategoria();
            }
            break;
        }
        case 9: {
            double precioRegular, precioPremium, precioEcoExtra;

            std::cout << "Ingrese el precio del combustible Regular: " << std::endl;
            std::cin >> precioRegular;

            std::cout << "Ingrese el precio del combustible Premium: " << std::endl;
            std::cin >> precioPremium;

            std::cout << "Ingrese el precio del combustible EcoExtra: " << std::endl;
            std::cin >> precioEcoExtra;

            // Llamar a la función para fijar precios en la red nacional
            red.fijarPrecios(precioRegular, precioPremium, precioEcoExtra);
            std::cout << "Precios de combustible actualizados exitosamente." << std::endl;
            break;
        }
        case 10:{
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "Seleccione el numero de la estacion donde desea activar/desactivar un surtidor:" << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "indice de estacion invalido." << std::endl;
                break;
            }

            estacion* est = red.getEstacion(indiceEstacion - 1);
            if (est->getNumeroSurtidores() == 0) {
                std::cout << "No hay surtidores en esta estacion." << std::endl;
                break;
            }

            est->mostrarSurtidores();  // Mostrar surtidores disponibles
            int indiceSurtidor;
            std::cout << "Seleccione el surtidor que desea activar/desactivar: " << std::endl;
            std::cin >> indiceSurtidor;

            if (indiceSurtidor < 1 || indiceSurtidor > est->getNumeroSurtidores()) {
                std::cout << "indice de surtidor invalido." << std::endl;
                break;
            }

            surtidor* surt = est->getSurtidor(indiceSurtidor - 1);
            std::cout << "El surtidor esta actualmente: " << (surt->estaActivo() ? "Activo" : "Inactivo") << std::endl;
            std::cout << "Desea: \n1. Activar\n2. Desactivar\nSeleccione una opcion: (ingresar 1 o 2)";
            int accion;
            std::cin >> accion;

            if (accion == 1) {
                surt->activar();
            } else if (accion == 2) {
                surt->desactivar();
            } else {
                std::cout << "Opcion invalida." << std::endl;
            }
            break;

        }
        case 11:{
            if (red.getNumeroEstaciones() == 0) {
                std::cout << "No hay estaciones disponibles para consultar." << std::endl;
                break;
            }

            int indiceEstacion;
            std::cout << "Seleccione la estacion para ver el historial de transacciones:" << std::endl;
            red.mostrarEstaciones();
            std::cin >> indiceEstacion;

            if (indiceEstacion < 1 || indiceEstacion > red.getNumeroEstaciones()) {
                std::cout << "indice de estacion invalido." << std::endl;
                break;
            }

            estacion* est = red.getEstacion(indiceEstacion - 1);
            if (est->getNumeroSurtidores() == 0) {
                std::cout << "No hay surtidores en esta estación." << std::endl;
                break;
            }

            std::cout << "\nMostrando el historial de transacciones de los surtidores de la estacion " << est->getNombre() << ":\n";

            // Mostrar transacciones de cada surtidor
            for (int i = 0; i < est->getNumeroSurtidores(); ++i) {
                surtidor* surt = est->getSurtidor(i);
                surt->consultarTransacciones();
            }

            break;
        }
        case 12:{
            red.simularVenta();
            break;
        }
        case 13:{
            salir=true;
            break;
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }
    return 0;
}

/*
int main() {
    rednacional red;

    // === ESTACION 1: Estacion Central ===
    estacion* est1 = new estacion("Estacion Central", 1001, "Juan Perez", "Centro", 45.2, -73.5, 300, 500, 400);
    red.agregarEstacion(est1);

    surtidor* surt1 = new surtidor("S001", "ModeloA", true);
    surtidor* surt2 = new surtidor("S002", "ModeloB", true);
    surtidor* surt3 = new surtidor("S003", "ModeloC", true);

    est1->agregarSurtidor(surt1);
    est1->agregarSurtidor(surt2);
    est1->agregarSurtidor(surt3);

    transaccion venta1("Regular", 50, 100, "Efectivo", "1234567890");
    transaccion venta2("Premium", 30, 150, "TDebito", "9876543210");
    transaccion venta3("EcoExtra", 40, 200, "TCredito", "2233445566");
    transaccion venta4("Regular", 60, 300, "Efectivo", "1122334455");

    surt1->registrarVenta(venta1);
    surt1->registrarVenta(venta2);
    surt2->registrarVenta(venta3);
    surt2->registrarVenta(venta4);

    std::cout << "\n=== Transacciones de Estacion Central ===\n";
    surt1->consultarTransacciones();
    surt2->consultarTransacciones();
    est1->mostrarEstacion();


    // === ESTACION 2: Estacion Sur ===
    estacion* est2 = new estacion("Estacion Sur", 2001, "Ana Lopez", "Sur", 40.0, -70.5, 200, 400, 300);
    red.agregarEstacion(est2);

    surtidor* surt4 = new surtidor("S004", "ModeloX", true);
    surtidor* surt5 = new surtidor("S005", "ModeloY", true);

    est2->agregarSurtidor(surt4);
    est2->agregarSurtidor(surt5);

    transaccion venta5("Premium", 70, 300, "Efectivo", "9988776655");
    transaccion venta6("Regular", 80, 350, "TDebito", "5566778899");

    surt4->registrarVenta(venta5);
    surt5->registrarVenta(venta6);

    std::cout << "\n=== Transacciones de Estacion Sur ===\n";
    surt4->consultarTransacciones();
    surt5->consultarTransacciones();
    est2->mostrarEstacion();


    // === ESTACION 3: Estacion Norte ===
    estacion* est3 = new estacion("Estacion Norte", 3001, "Carlos Ruiz", "Norte", 60.1, -72.4, 350, 600, 450);
    red.agregarEstacion(est3);

    surtidor* surt6 = new surtidor("S006", "ModeloZ", true);
    surtidor* surt7 = new surtidor("S007", "ModeloW", true);

    est3->agregarSurtidor(surt6);
    est3->agregarSurtidor(surt7);

    transaccion venta7("EcoExtra", 90, 400, "TCredito", "1111222233");
    transaccion venta8("Regular", 100, 500, "TDebito", "2222333344");

    surt6->registrarVenta(venta7);
    surt7->registrarVenta(venta8);

    std::cout << "\n=== Transacciones de Estacion Norte ===\n";
    surt6->consultarTransacciones();
    surt7->consultarTransacciones();
    est3->mostrarEstacion();


    // === MOSTRAR ESTACIONES Y TRANSACCIONES ===
    std::cout << "\n=== Mostrando todas las estaciones de la red ===\n";
    red.mostrarEstaciones();

    // === CALCULAR MONTO TOTAL DE VENTAS POR CATEGORÍA POR ESTACIÓN ===
    std::cout << "\n=== Monto total de ventas en Estacion Central por categoría ===\n";
    est1->calcularTotalVentasPorCategoria();

    std::cout << "\n=== Monto total de ventas en Estacion Sur por categoría ===\n";
    est2->calcularTotalVentasPorCategoria();

    std::cout << "\n=== Monto total de ventas en Estacion Norte por categoría ===\n";
    est3->calcularTotalVentasPorCategoria();

    // === REPORTAR LITROS VENDIDOS POR CATEGORÍA POR ESTACIÓN ===
    std::cout << "\n=== Reporte de litros vendidos en Estacion Central por categoría ===\n";
    est1->calcularLitrosVendidosPorCategoria();

    std::cout << "\n=== Reporte de litros vendidos en Estacion Sur por categoría ===\n";
    est2->calcularLitrosVendidosPorCategoria();

    std::cout << "\n=== Reporte de litros vendidos en Estacion Norte por categoría ===\n";
    est3->calcularLitrosVendidosPorCategoria();


    // === ELIMINAR UNA ESTACIÓN ===
    std::cout << "\n=== Eliminando Estacion Central (indice 0) ===\n";
    red.eliminarEstacion(0);
    red.mostrarEstaciones();

    // === LIBERAR MEMORIA ===
    delete surt1;
    delete surt2;
    delete surt3;
    delete surt4;
    delete surt5;
    delete surt6;
    delete surt7;
    delete est1;
    delete est2;
    delete est3;

    return 0;
}*/

