#include "runner.h"

// variable global en donde debe guardarse los datos pasados
// Esto para el calculo correcto de los siguientes pasos, distancias, calorias, etc
vector<package> storage_data = {};

// TODO: Implente esta funcion.
// Verifique que la data en el paquete sea valida
bool check_correct_data(package data) {
  return true;
}

// TODO: Implemente esta funcion.
// Verifique que el tiempo obtenido sea correcto.
bool check_correct_time(long seconds) {
  return true;
}

// TODO: Implemente esta funcion
// Devuelve la suma total de los pasos dados durante el dia
int get_step_day(int steps) {
  return 0;
}

// TODO: Implemente esta funcion
// Devuelve la distancia recorrida segun los pasos dados durante el dia
double get_distance(int steps) {
  return 0;
}

// TODO: Implemente esta funcion
// Devuelve las calorias quemadas segun la distancia recurrida
double get_calories_burned(double dist, times current_time) {
  return 0;
}

// TODO: Implemente esta funcion
// Devuelve una string con el mensaje de motivacion segun la distancia recorrida
string get_achievement(double dist) {
  return "";
}

// TODO: Implemente las funciones restantes:
//       show_message
// Funcion que sirve para mostrar los datos sugeridos con el formato solicitado
void show_message(times t, int steps, double dist, double calories, string achievement){

}

//        get_time_hms
// Esta funcion convierte los segundos en horas, minutos y segundos, y los vuelve como miembros de la esctructura 'times'
times get_time_hms(long seconds){

}

//       format_time
// Transforma los miembros tipo 'times' en una secuencia de caracteres con el formato de hora solicitado
string format_time(times t){

}

// TODO: Implemente la funcion madre
// Esta funcion debe llamar a las otras para realizar lo indicado en el pdf
vector<package> accept_package(package data) {
  return storage_data;
}