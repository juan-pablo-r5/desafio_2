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

    surtidor** surtidores;  // Puntero a un array dinámico de punteros a surtidores
    int numeroSurtidores;
    int capacidadSurtidores;
    void redimensionarSurtidores();

public:
    estacion();
    estacion(const std::string& nom, int cod, const std::string& ger, const std::string& reg, double latitud, double longitud, double regular, double premium, double ecoExtra);
    ~estacion();

    void agregarSurtidor(surtidor* surtidor);
    void eliminarSurtidor(int indice);
    void mostrarEstacion() const;
    std::string getNombre() const;
    int getNumeroSurtidores() const;
    std::string getRegion() const;

    // Nuevos métodos necesarios
    void mostrarSurtidores() const;  // Mostrar todos los surtidores
    surtidor* getSurtidor(int indice);  // Obtener un surtidor específico
    void calcularTotalVentasPorCategoria() const;
    void calcularLitrosVendidosPorCategoria() const;


};

#endif // ESTACION_H
