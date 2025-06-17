#include "runner.h"

// variable global en donde debe guardarse los datos pasados
// Esto para el calculo correcto de los siguientes pasos, distancias, calorias, etc
vector<package> storage_data = {};

// TODO: Implente esta funcion.
// Verifique que la data en el paquete sea valida
bool check_correct_data(const package data) {
  if (data.steps <= 0 or data.segundos <= 0){
    return false;
  }
  return true;
}

// TODO: Implemente esta funcion.
// Verifique que el tiempo obtenido sea correcto.
bool check_correct_time(const long seconds) {
  if (storage_data.empty()){
    return true;
  }
  if (seconds <= storage_data.back().segundos){
    return false;
  }
  return true;
}

// TODO: Implemente esta funcion
// Devuelve la suma total de los pasos dados durante el dia
int get_step_day(const int steps) {
  int total_steps = 0;
  for (package i : storage_data){
    total_steps += i.steps;
  }
  return total_steps;
}

// TODO: Implemente esta funcion
// Devuelve la distancia recorrida segun los pasos dados durante el dia
double get_distance(const int steps) {
  double distance = (steps * STEP_M) / 1000.0;
  return distance;
}

// TODO: Implemente esta funcion
// Devuelve las calorias quemadas segun la distancia recurrida
double get_calories_burned(const double dist, const times current_time) {
  double hours = current_time.hour + current_time.min/60.0 + current_time.sec/3600.0;
  double mean_speed = dist / hours;
  double minutes = hours * 60;
  double cal_burned = (K_1 * WEIGHT + ((mean_speed * mean_speed)/HEIGHT) * K_2 * WEIGHT) * minutes;
  return cal_burned;
}

// TODO: Implemente esta funcion
// Devuelve una string con el mensaje de motivacion segun la distancia recorrida
string get_achievement(const double dist) {
  if (dist >= 6.5) {
    return "Gran entrenamiento! Objetivo cumplido.";
  } else if (dist >= 3.9) {
    return "Nada mal! Hoy ha sido un dia productivo.";
  } else if (dist >= 2.0) {
    return "Menos que el resultado deseado, pero intenta alcanzarlo manhana!";
  } else {
    return "Esta bien tomarse el dia de descanso. No siempre se puede ganar.";
  }
}

// TODO: Implemente las funciones restantes:
//       show_message
// Funcion que sirve para mostrar los datos sugeridos con el formato solicitado
void show_message(const times t, const int steps, const double dist, const double calories, const string& achievement){
  cout << "Tiempo: " << format_time(t) << "." << endl;
  cout << "Pasos dados hoy: " << steps << "." << endl;
  cout << "La distancia fue " << dist << "km." << endl;
  cout << "Has quemado " << calories << "cal." << endl;
  //printf("La distancia fue %.2f km.\n", dist);
  //printf("Has quemado %.2f cal.\n", calories);
  //NUEVA SALIDA AGREGADA PARA EL OBJETIVO PROPUESTO POR EL USUARIO
  if ((DAYLY_GOAL - steps) <= 0) {
    cout << "Objetivo diario superado!" << endl;
  } else {
    cout << "Faltan " << DAYLY_GOAL - steps << " pasos para tu meta." << endl;
  }
  cout << achievement << endl << endl;
}

//        get_time_hms
// Esta funcion convierte los segundos en horas, minutos y segundos, y los vuelve como miembros de la esctructura 'times'
times get_time_hms(const long seconds){
  times t{};
  t.hour = seconds / 3600;
  t.min = (seconds % 3600) / 60;
  t.sec = seconds % 60;
  return t;
}

//       format_time
// Transforma los miembros tipo 'times' en una secuencia de caracteres con el formato de hora solicitado
string format_time(const times t){
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
vector<package> accept_package(const package data) {
  if (!check_correct_data(data)){
    return storage_data;
  }
  if (!check_correct_time(data.segundos)){
    return storage_data;
  }
  storage_data.push_back(data);

  times t = get_time_hms(data.segundos);
  int total_steps = get_step_day(0);
  double dist = get_distance(total_steps);
  double calories = get_calories_burned(dist, t);
  string msg = get_achievement(dist);

  show_message(t, total_steps, dist, calories, msg);
  return storage_data;
}