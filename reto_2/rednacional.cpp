#include "rednacional.h"

// Constructor
rednacional::rednacional() {
    capacidadEstaciones = 2;
    numeroEstaciones = 0;
    estaciones = new estacion*[capacidadEstaciones];  // Array de punteros a estaciones
    precioRegular = 0.0;
    precioPremium = 0.0;
    precioEcoExtra = 0.0;
}

// Destructor
rednacional::~rednacional() {
    for (int i = 0; i < numeroEstaciones; ++i) {
        delete estaciones[i];  // Liberar cada estación
    }
    delete[] estaciones;  // Liberar el array dinámico
}

// Redimensionar el array dinámico de estaciones
void rednacional::redimensionar() {
    capacidadEstaciones *= 2;
    estacion** nuevoArray = new estacion*[capacidadEstaciones];  // Nuevo array de punteros
    for (int i = 0; i < numeroEstaciones; ++i) {
        nuevoArray[i] = estaciones[i];  // Copiar punteros
    }
    delete[] estaciones;  // Liberar el array antiguo
    estaciones = nuevoArray;
}

// Agregar una nueva estación a la red nacional
void rednacional::agregarEstacion(estacion* estacione) {
    if (numeroEstaciones == capacidadEstaciones) {
        redimensionar();  // Redimensionar si es necesario
    }
    estaciones[numeroEstaciones++] = estacione;  // Almacenar el puntero
}
void rednacional::eliminarEstacion(int indice) {
    if (indice < 0 || indice >= numeroEstaciones) {
        std::cout << "indice invalido.\n";
        return;
    }
    estacion* est = estaciones[indice];


    // Verificar si la estación tiene surtidores y si todos están desactivados
    if (est->getNumeroSurtidores() > 0) {
        for (int i = 0; i < est->getNumeroSurtidores(); ++i) {
            if (est->getSurtidor(i)->estaActivo()) {
                std::cout << "No se puede eliminar la estacion. Hay surtidores activos."<<std::endl;
                return;
            }
        }
    }
    // Proceder a eliminar si todos los surtidores están desactivados
    for (int i = indice; i < numeroEstaciones - 1; ++i) {
        estaciones[i] = estaciones[i + 1];
    }
    numeroEstaciones--;
    delete est;
    //delete estaciones[indice];  // Liberar la memoria de la estación
    std::cout << "Estacion eliminada exitosamente."<<std::endl;
}


// Mostrar todas las estaciones en la red
void rednacional::mostrarEstaciones() const {
    if (numeroEstaciones == 0) {
        std::cout << "No hay estaciones en la red.\n";
        return;
    }
    for (int i = 0; i < numeroEstaciones; ++i) {
        std::cout << "Estacion " << (i + 1) << ":\n";
        estaciones[i]->mostrarEstacion();  // Usar puntero
        std::cout << "-----------------------\n";
    }
}
void rednacional::fijarPrecios(double regular, double premium, double ecoExtra) {
    precioRegular = regular;
    precioPremium = premium;
    precioEcoExtra = ecoExtra;
    std::cout << "Precios actualizados en toda la red:"<<std::endl
              << "Regular: " << precioRegular <<std::endl
              << "Premium: " << precioPremium << std::endl
              << "EcoExtra: " << precioEcoExtra << std::endl;
}
double rednacional::getPrecioRegular() const {
    return precioRegular;
}
double rednacional::getPrecioPremium() const {
    return precioPremium;
}
double rednacional::getPrecioEcoExtra() const {
    return precioEcoExtra;
}

// Obtener estacion por índice
estacion* rednacional::getEstacion(int indice) const {
    if (indice >= 0 && indice < numeroEstaciones) {
        return estaciones[indice];
    }
    throw std::out_of_range("indice de estacion invalido.");
}

// Obtener el numero de estaciones actuales
int rednacional::getNumeroEstaciones() const {
    return numeroEstaciones;
}

void rednacional::simularVenta() {
    if (numeroEstaciones == 0) {
        std::cout << "No hay estaciones disponibles para simular ventas.\n";
        return;
    }

    // Seleccionar aleatoriamente una estación que tenga surtidores activos
    srand(time(0));
    estacion* est = nullptr;
    do {
        int indiceEstacion = rand() % numeroEstaciones;
        est = estaciones[indiceEstacion];
    } while (est->getNumeroSurtidores() == 0);

    // Verificar si la estación tiene surtidores activos
    bool surtidoresActivos = false;
    for (int i = 0; i < est->getNumeroSurtidores(); ++i) {
        if (est->getSurtidor(i)->estaActivo()) {
            surtidoresActivos = true;
            break;
        }
    }

    if (!surtidoresActivos) {
        std::cout << "No hay surtidores activos en la estación seleccionada.\n";
        return;
    }

    // Seleccionar aleatoriamente uno de los surtidores activos
    int indiceSurtidor;
    do {
        indiceSurtidor = rand() % est->getNumeroSurtidores();
    } while (!est->getSurtidor(indiceSurtidor)->estaActivo());

    surtidor* surt = est->getSurtidor(indiceSurtidor);

    // Generar aleatoriamente entre 3 y 20 litros de combustible
    int litrosVendidos = 3 + rand() % 18;

    // Determinar la categoría de combustible según la región de la estación
    std::string categoria;
    double precioPorLitro;
    if (est->getRegion() == "Norte") {
        categoria = "EcoExtra";
        precioPorLitro = getPrecioEcoExtra()*1.3;  // Usar el precio fijo de EcoExtra
    } else if (est->getRegion() == "Centro") {
        categoria = "Regular";
        precioPorLitro = getPrecioRegular()*1.2;  // Usar el precio fijo de Regular
    } else {
        categoria = "Premium";
        precioPorLitro = getPrecioPremium()*1.4;  // Usar el precio fijo de Premium
    }

    // Definir el precio por litro según la categoría de combustible
    int montoTotal = litrosVendidos * precioPorLitro;

    // Crear la transacción y registrarla
    transaccion nuevaVenta(categoria, litrosVendidos, montoTotal, "Efectivo", "123456789");
    surt->registrarVenta(nuevaVenta);

    // Mostrar los detalles de la transacción
    std::cout << "\n=== Transaccion registrada ===\n";
    nuevaVenta.mostrarDetalles();
}
