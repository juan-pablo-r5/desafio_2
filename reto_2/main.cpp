#include "rednacional.h"
#include "estacion.h"

int main()
{
    cout<<"menu del desafio";
    // Crear una red nacional de estaciones de servicio
    rednacional red;

    // Crear algunas estaciones de servicio
    estacion est1("Estacion A", 101, "Gerente A", "Norte");
    estacion est2("Estacion B", 102, "Gerente B", "Sur");
    estacion est3("Estacion C", 103, "Gerente C", "Centro");

    // Agregar estaciones a la red
    red.agregarEstacion(est1);
    red.agregarEstacion(est2);
    red.agregarEstacion(est3);

    // Mostrar todas las estaciones
    red.mostrarEstaciones();

    // Eliminar una estación y mostrar las estaciones restantes
    red.eliminarEstacion(1);  // Elimina la estación B
    std::cout << "Despues de eliminar la estacion B:\n";
    red.mostrarEstaciones();

    return 0;

}
