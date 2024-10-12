#ifndef REDNACIONAL_H
#define REDNACIONAL_H
//Gestiona todas las estaciones de servicio de la red nacional.
//Permite agregar/eliminar estaciones, calcular ventas totales y gestionar precios.
#include <iostream>
#include "estacion.h"

using namespace std;

class rednacional
{

private:
    estacion* estaciones;  // Puntero a un array dinámico de EstacionDeServicio
    int numeroEstaciones;            // Número de estaciones actuales en la red
    int capacidadEstaciones;         // Capacidad actual del array

    // Método privado para redimensionar el array cuando sea necesario
    void redimensionar();

public:
    // Constructor y destructor
    rednacional();
    ~rednacional();

    // Métodos para agregar y eliminar estaciones
    void agregarEstacion(const estacion& estacion);
    void eliminarEstacion(int indice);

    // Mostrar todas las estaciones
    void mostrarEstaciones() const;
};

#endif // REDNACIONAL_H
