#include "runner.h"

// variable global en donde debe guardarse los datos pasados
// Esto para el calculo correcto de los siguientes pasos, distancias, calorias, etc
vector<package> storage_data = {};

// TODO: Implente esta funcion.
// Verifique que la data en el paquete sea valida
bool check_correct_data(package data) {
  if (data.steps <= 0 or data.segundos <= 0){
    return false;
  }
  if (storage_data.size() == 0){
    return true;
  }
  return true;
}

// TODO: Implemente esta funcion.
// Verifique que el tiempo obtenido sea correcto.
bool check_correct_time(long seconds) {
  if (storage_data.size() == 0 and seconds > 0){
    return true;
  }
  if (seconds <= storage_data[storage_data.size() - 1].segundos){
    return false;
  }
  return true;
}

// TODO: Implemente esta funcion
// Devuelve la suma total de los pasos dados durante el dia
int get_step_day(int steps) {   //Parámetro no usado
  int total_steps = 0;
  for (int i = 0; i < storage_data.size(); i++){
    total_steps += storage_data[i].steps;
  }
  return total_steps;
}
/*
 * Suma todos los pasos almacenados en storage_data.
 * El parámetro 'steps' no se utiliza porque:
 *   - storage_data ya contiene todos los paquetes válidos
 *   - El problema pide "pasos dados hoy" (total diario)
 */

// TODO: Implemente esta funcion
// Devuelve la distancia recorrida segun los pasos dados durante el dia
double get_distance(int steps) {
  double distance = (steps * STEP_M) / 1000.0;
  return distance;
}

// TODO: Implemente esta funcion
// Devuelve las calorias quemadas segun la distancia recurrida
double get_calories_burned(double dist, times current_time) {
  double hours = current_time.hour + current_time.min/60.0 + current_time.sec/3600.0;
  double mean_speed = dist / hours;
  double minutes = hours * 60;
  double cal_burned = (K_1 * WEIGHT + ((mean_speed * mean_speed)/HEIGHT) * K_2 * WEIGHT) * minutes;
  return cal_burned;
}

// TODO: Implemente esta funcion
// Devuelve una string con el mensaje de motivacion segun la distancia recorrida
string get_achievement(double dist) {
  if (dist >= 6.5) {
    return "¡Gran entrenamiento! Objetivo cumplido.";
  } else if (dist >= 3.9) {
    return "¡Nada mal! Hoy ha sido un día productivo.";
  } else if (dist >= 2.0) {
    return "Menos que el resultado deseado, ¡pero intenta alcanzarlo mañana!";
  } else {
    return "Está bien tomarse el día de descanso. No siempre se puede ganar.";
  }
}

// TODO: Implemente las funciones restantes:
//       show_message
// Funcion que sirve para mostrar los datos sugeridos con el formato solicitado
void show_message(times t, int steps, double dist, double calories, string achievement){

}

//        get_time_hms
// Esta funcion convierte los segundos en horas, minutos y segundos, y los vuelve como miembros de la esctructura 'times'
times get_time_hms(long seconds){
  times t;
  t.hour = seconds / 3600;
  t.min = (seconds % 3600) / 60;
  t.sec = seconds % 60;
  return t;
}

//       format_time
// Transforma los miembros tipo 'times' en una secuencia de caracteres con el formato de hora solicitado
string format_time(times t){
  string hour, min, sec;
  if (t.hour < 10) {
    hour = "0" + to_string(t.hour);
  } else {
    hour = to_string(t.hour);
  }
  if (t.min < 10) {
    min = "0" + to_string(t.min);
  } else {
    min = to_string(t.min);
  }
  if (t.sec < 10) {
    sec = "0" + to_string(t.sec);
  } else {
    sec = to_string(t.sec);
  }
  return hour + ":" + min + ":" + sec;
}

// TODO: Implemente la funcion madre
// Esta funcion debe llamar a las otras para realizar lo indicado en el pdf
vector<package> accept_package(package data) {
  return storage_data;
}