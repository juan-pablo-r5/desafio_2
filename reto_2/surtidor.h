#ifndef SURTIDOR_H
#define SURTIDOR_H
//Cada surtidor en la estación puede vender combustible de las tres categorías (Regular, Premium, EcoExtra),
// y debe registrar todas las transacciones que se realicen.
#include <iostream>
#include "transaccion.h"
#include <cstring>
class surtidor
{
public:
    surtidor();

private:
    void redimensionarVentas();

public:
    char codigo[20];
    char modelo[50];
    bool activo;
    transaccion* ventas;
    int numeroVentas;
    int capacidadVentas;
    surtidor(const char* cod = "", const char* mod = "", bool act = true);
    ~surtidor();

    // Métodos para gestionar las ventas
    void registrarVenta(const transaccion& venta);
    void consultarTransacciones() const;
    void reportarVentasPorCategoria() const;

    // Métodos para manejar el estado del surtidor
    void activar();
    void desactivar();
    bool estaActivo() const;
};

#endif // SURTIDOR_H
