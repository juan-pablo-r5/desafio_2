#ifndef SURTIDOR_H
#define SURTIDOR_H
//Cada surtidor en la estación puede vender combustible de las tres categorías (Regular, Premium, EcoExtra),
// y debe registrar todas las transacciones que se realicen.
#include <iostream>
#include "transaccion.h"
#include <string>

class surtidor {
private:
    void redimensionarVentas();

public:
    std::string codigo;
    std::string modelo;
    bool activo;

    transaccion* ventas;   // Puntero a un array dinámico de transacciones
    int numeroVentas;
    int capacidadVentas;

    // Constructor y destructor
    surtidor(const std::string& cod = "", const std::string& mod = "", bool act = true);
    ~surtidor();

    // Métodos para gestionar las ventas
    void registrarVenta(const transaccion& nuevaVenta);
    void consultarTransacciones() const;
    void reportarVentasPorCategoria() const;

    // Métodos para manejar el estado del surtidor
    void activar();
    void desactivar();
    bool estaActivo() const;
};

#endif // SURTIDOR_H
