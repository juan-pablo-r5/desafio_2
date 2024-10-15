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
    estacion* estaciones;  // Puntero a un array dinámico de estaciones
    int numeroEstaciones;  // Número de estaciones actuales en la red
    int capacidadEstaciones; // Capacidad actual del array de estaciones

    void redimensionar();  // Método para redimensionar el array dinámico

public:
    rednacional();  // Constructor
    ~rednacional();  // Destructor

    void agregarEstacion(const estacion& estacion);
    void eliminarEstacion(int indice);
    bool puedeEliminarEstacion(int indice) const;

    // Nuevos métodos necesarios
    estacion& getEstacion(int indice);  // Obtener una estación específica
    int getNumeroEstaciones() const;  // Obtener el número de estaciones
    void mostrarEstaciones() const;  // Mostrar todas las estaciones
};

#endif // REDNACIONAL_H
