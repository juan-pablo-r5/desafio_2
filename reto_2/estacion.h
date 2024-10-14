#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>
#include "surtidor.h"

class estacion {
private:
    std::string nombre;
    int codigo;
    std::string gerente;
    double coordenadas[2];
    std::string region;
    double tanque[3];

    // Almacenar punteros a surtidores en lugar de copias
    surtidor** surtidores;
    int numeroSurtidores;
    int capacidadSurtidores;

    void redimensionarSurtidores();

public:
    estacion();
    estacion(const std::string& nom, int cod, const std::string& ger, const std::string& reg, double latitud, double longitud, double regular, double premium, double ecoExtra);
    ~estacion();

    // Cambia para aceptar punteros
    void agregarSurtidor(surtidor* surtidor);
    void eliminarSurtidor(int indice);
    void mostrarEstacion() const;
};

#endif // ESTACION_H
