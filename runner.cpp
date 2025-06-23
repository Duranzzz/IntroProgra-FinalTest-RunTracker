#include "runner.h"

// variable global en donde debe guardarse los datos pasados
// Esto para el calculo correcto de los siguientes pasos, distancias, calorias, etc
vector<package> storage_data = {};

/*
 * Verifica que los pasos y segundos sean valores positivos
 */
bool check_correct_data(const package& data) {
  // Paquetes con valores cero o negativos son inválidos
  if (data.steps <= 0 or data.segundos <= 0){
    return false;
  }
  return true;
}

/*
 * Verifica que el tiempo del nuevo paquete sea mayor que el último registrado
 */
bool check_correct_time(const long& seconds) {
  // El primer paquete siempre es válido
  if (storage_data.empty()){
    return true;
  }
  // Tiempo debe ser estrictamente creciente
  if (seconds <= storage_data.back().segundos){
    return false;
  }
  return true;
}

/*
 * Calcula el total de pasos sumando todos los paquetes almacenados
 */
int get_step_day(const int& steps) {
  int total_steps = 0;
  // Suma iterativa de pasos de todos los paquetes válidos
  for (package i : storage_data){
    total_steps += i.steps;
  }
  return total_steps;
}

/*
 * Convierte pasos a kilómetros usando la longitud promedio de paso
 */
double get_distance(const int& steps) {
  // Fórmula: (pasos * longitud_paso) / 1000 (metros a km)
  double distance = (steps * STEP_M) / 1000.0;
  return distance;
}

/*
 * Calcula calorías usando fórmula fisiológica basada en:
 * - Distancia recorrida
 * - Tiempo transcurrido
 * - Peso y altura del usuario
 */
double get_calories_burned(const double& dist, const times& current_time) {
  // Convertir tiempo a horas decimales
  double hours = current_time.hour + current_time.min/60.0 + current_time.sec/3600.0;
  // Calcular velocidad media (distancia/tiempo)
  double mean_speed = dist / hours;
  // Convertir tiempo a minutos
  double minutes = hours * 60;
  // Fórmula completa para cálculo de calorías
  double cal_burned = (K_1 * WEIGHT + ((mean_speed * mean_speed)/HEIGHT) * K_2 * WEIGHT) * minutes;
  return cal_burned;
}

/*
 * Selecciona mensaje motivacional basado en rangos de distancia
 */
string get_achievement(const double& dist) {
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

/*
 * Muestra el resumen completo de actividad con formato especificado
 */
void show_message(const times& t, const int& steps, const double& dist, const double& calories, const string& achievement){
  // Formatear y mostrar cada componente del resumen
  cout << "Tiempo: " << format_time(t) << "." << endl;
  cout << "Pasos dados hoy: " << steps << "." << endl;
  cout << "La distancia fue " << dist << " km." << endl;
  cout << "Has quemado " << calories << " cal." << endl;
  //printf("La distancia fue %.2f km.\n", dist);
  //printf("Has quemado %.2f cal.\n", calories);
  //NUEVA SALIDA AGREGADA PARA EL OBJETIVO PROPUESTO POR EL USUARIO
  // Mostrar progreso hacia la meta diaria
  if ((DAYLY_GOAL - steps) <= 0) {
    cout << "Objetivo diario superado!" << endl;
  } else {
    cout << "Faltan " << DAYLY_GOAL - steps << " pasos para tu meta." << endl;
  }
  cout << achievement << endl << endl;
}

/*
 Esta funcion convierte los segundos en horas, minutos y segundos, y los vuelve como miembros de la esctructura 'times'
 */
times get_time_hms(const long& seconds){
  times t{};
  t.hour = seconds / 3600;      // Horas completas
  t.min = (seconds % 3600) / 60;// Minutos restantes
  t.sec = seconds % 60;         // Segundos restantes
  return t;
}

/*
 Transforma los miembros tipo 'times' en una secuencia de caracteres con el formato de hora solicitado
 */
string format_time(const times& t){
  string hour, min, sec;
  // Formatea horas
  if (t.hour < 10) {
    hour = "0" + to_string(t.hour);
  } else {
    hour = to_string(t.hour);
  }
  // Formatea minutos
  if (t.min < 10) {
    min = "0" + to_string(t.min);
  } else {
    min = to_string(t.min);
  }
  // Formate segundos
  if (t.sec < 10) {
    sec = "0" + to_string(t.sec);
  } else {
    sec = to_string(t.sec);
  }
  return hour + ":" + min + ":" + sec;
}

/*
 * Función principal que orquesta el procesamiento completo de un paquete
 */
vector<package> accept_package(const package& data) {
  // Validación inicial del paquete
  if (!check_correct_data(data)){
    return storage_data;
  }
  if (!check_correct_time(data.segundos)){
    return storage_data;
  }

  // Almacenamiento del paqueta válido
  storage_data.push_back(data);

  // Procesamiento completo de los datos
  times t = get_time_hms(data.segundos);
  int total_steps = get_step_day(0);
  double dist = get_distance(total_steps);
  double calories = get_calories_burned(dist, t);
  string msg = get_achievement(dist);

  // Mostrar resumen
  show_message(t, total_steps, dist, calories, msg);
  return storage_data;
}