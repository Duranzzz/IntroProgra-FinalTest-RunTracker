#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>

using namespace std;

/*
  NO debe modificar nada en este documento
  Asegurese de entender que ocurre aqui y cuales son las constantes que utilzara en las funciones
*/
struct times {
  int hour;
  int min;
  int sec;
};

struct package {
  long segundos;
  int steps;
};

const int WEIGHT = 75;
const int HEIGHT = 175;
const double K_1 = 0.035;
const double K_2 = 0.029;
const double STEP_M = 0.65;
//Nueva variable para fucionalidad: cantidad de pasos para cumplir una determinada meta
const int DAYLY_GOAL = 10000;

extern vector<package> storage_data;

#endif