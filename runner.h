#ifndef RUNNER_H
#define RUNNER_H

#include <iostream>
#include <vector>
#include "constants.h"

using namespace std;

/*
 * Verifica si los datos de un paquete son válidos
 * Parámetro: data Paquete a verificar
 * Retorna true si los datos son válidos, false en caso contrario
 */
bool check_correct_data(const package& data);

/*
 * Verifica si el tiempo de un paquete es válido (mayor que el último registrado)
 * Parámetro: seconds Tiempo en segundos a verificar
 * Retorna true si el tiempo es válido, false en caso contrario
 */
bool check_correct_time(const long& seconds);

/*
 * Calcula el total de pasos acumulados durante el día
 * Parámetro: steps Pasos
 * Retorna Suma total de pasos del día
 */
int get_step_day(const int& steps);

/*
 * Calcula la distancia recorrida en kilómetros
 * Parámetro: steps Cantidad total de pasos
 * Retorna Distancia en kilómetros
 */
double get_distance(const int& steps);

/*
 * Calcula las calorías quemadas durante la actividad
 * Parámetro dist Distancia recorrida en kilómetros
 * Parámetro current_time Tiempo transcurrido en formato estructurado
 * Retorna Calorías quemadas
 */
double get_calories_burned(const double& dist, const times& current_time);

/*
 * Genera un mensaje motivacional basado en la distancia recorrida
 * Parámetro: dist Distancia recorrida en kilómetros
 * Retorna Mensaje motivacional correspondiente
 */
string get_achievement(const double& dist);

/*
 * Muestra un resumen de la actividad con formato específico
 * Parámetro: t Tiempo del paquete
 * Parámetro: steps Pasos totales
 * Parámetro: dist Distancia recorrida
 * Parámetro: calories Calorías quemadas
 * Parámetro: achievement Mensaje motivacional
 */
void show_message(const times& t, const int& steps, const double& dist, const double& calories, const string& achievement);

/*
 * Convierte segundos a una estructura de tiempo (horas, minutos, segundos)
 * Parámetro: seconds Segundos transcurridos desde inicio del día
 * retorna Estructura times con tiempo desglosado
 */
times get_time_hms(const long& seconds);

/*
 * Formatea el tiempo a cadena HH:MM:SS con ceros iniciales
 * Parámetro: t Tiempo en estructura desglosada
 * Retorna Cadena con tiempo formateado
 */
string format_time(const times& t);

/*
 * Función principal que procesa un paquete de datos
 * Parámetro: data Paquete de datos a procesar
 * Retorna Vector global con todos los paquetes almacenados
 */
vector<package> accept_package(const package& data);

#endif