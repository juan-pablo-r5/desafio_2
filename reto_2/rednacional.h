#ifndef REDNACIONAL_H
#define REDNACIONAL_H
//Gestiona todas las estaciones de servicio de la red nacional.
//Permite agregar/eliminar estaciones, calcular ventas totales y gestionar precios.
#include <iostream>
#include "estacion.h"
#include <cstdlib>
#include <ctime>


class rednacional
{
private:
    estacion** estaciones;  // Puntero a un array dinámico de punteros a estaciones
    int numeroEstaciones;  // Número de estaciones actuales en la red
    int capacidadEstaciones; // Capacidad actual del array

    void redimensionar();  // Método para redimensionar el array
    double precioRegular;
    double precioPremium;
    double precioEcoExtra;


public:
    rednacional();
    ~rednacional();

    // Métodos para agregar y eliminar estaciones
    void agregarEstacion(estacion* estacione);  // Usar punteros
    void eliminarEstacion(int indice);

    // Mostrar todas las estaciones
    void mostrarEstaciones() const;

    // Obtener estación por índice
    estacion* getEstacion(int indice) const;
    int getNumeroEstaciones() const;
    void fijarPrecios(double regular, double premium, double ecoExtra);
    double getPrecioRegular() const;
    double getPrecioPremium() const;
    double getPrecioEcoExtra() const;
    void simularVenta();


};


#endif // REDNACIONAL_H
