#include "runner.h"

/*
 * Punto de entrada principal del programa
 *
 * Contiene datos de prueba predefinidos para validar el funcionamiento
 * del sistema de seguimiento de actividad física.
 *
 * Los paquetes de prueba incluyen casos válidos e inválidos que
 * permiten verificar todas las funcionalidades del sistema.
 */
int main() {
    // Datos de prueba para validar diferentes escenarios

    // Paquete válido: tiempo positivo, pasos positivos
    package data_1 = {7201, 505};

    // Paquete inválido: tiempo cero
    package data_2 = {0, 505};

    // Paquete válido: tiempo válido, pasos suficientes para meta diaria
    package data_3 = {34562, 15000};

    // Paquete inválido: tiempo duplicado
    package data_4 = {34562, 9000};

    // Paquete inválido: tiempo menor que último registro
    package data_5 = {28862, 7600};

    // Procesamiento secuencial de todos los paquetes
    accept_package(data_1);
    accept_package(data_2);
    accept_package(data_3);
    accept_package(data_4);
    accept_package(data_5);

  return 0;
}
