#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
//Representa una estación de servicio que tiene varios surtidores y
//un tanque dividido en categorías de combustible (Regular, Premium, EcoExtra).
#include "surtidor.h"

class estacion
{    
private:
    // Atributos básicos de la estación
    char nombre[50];         // Nombre de la estación
    int codigo;              // Código de la estación
    char gerente[50];        // Nombre del gerente
    double coordenadas[2];   // Coordenadas GPS (latitud, longitud)
    char region[10];         // Región: Norte, Centro, Sur

    // Tanque de combustible (Regular, Premium, EcoExtra)
    double tanque[3];        // Capacidad del tanque para 3 tipos de combustible

public:
    // Constructor y destructor
    estacion(const char* nom = "", int cod = 0, const char* ger = "", const char* reg = "");
    ~estacion() {}

    // Métodos para establecer datos de la estación
    void establecerNombre(const char* nom);
    void establecerCodigo(int cod);
    void establecerGerente(const char* ger);
    void establecerRegion(const char* reg);
    void establecerCoordenadas(double latitud, double longitud);
    void establecerCapacidadTanque(double regular, double premium, double ecoExtra);

    // Método para mostrar los detalles de la estación
    void mostrarEstacion() const;
};

#endif // ESTACION_H
