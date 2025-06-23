#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>

using namespace std;

/*
 * Estructura para representar el tiempo en horas, minutos y segundos
 */
struct times {
  int hour; // < Horas (0-23)
  int min;  // < Minutos (0-59)
  int sec;  // < Segundos (0-59)
};

/*
 * Estructura para representar un paquete de datos recibido
 */
struct package {
  long segundos; // < Tiempo en segundos desde el inicio del día
  int steps;     // < Cantidad de pasos registrados
};

// Constantes para cálculos fisiológicos
const int WEIGHT = 75;       // < Peso del usuario en kilogramos
const int HEIGHT = 175;      // < Altura del usuario en centímetros
const double K_1 = 0.035;    // < Coeficiente metabólico para cálculo de calorías
const double K_2 = 0.029;    // < Coeficiente aeróbico para cálculo de calorías
const double STEP_M = 0.65;  // < Longitud promedio de un paso en metros
const int DAYLY_GOAL = 10000;// < Meta diaria de pasos a alcanzar

// Vector global para almacenar todos los paquetes válidos procesados
extern vector<package> storage_data;

#endif