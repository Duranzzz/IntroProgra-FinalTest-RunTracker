#ifndef RUNNER_H
#define RUNNER_H

#include <iostream>
#include <vector>

#include "constants.h"

using namespace std;

bool check_correct_data(package data);
bool check_correct_time(long seconds);
int get_step_day(int steps);
double get_distance(int steps);
double get_calories_burned(double dist, times current_time);
string get_achievement(double dist);
vector<package> accept_package(package data);

// TODO: Implemente los protitopis de funciones restantes:
//       show_message
void show_message(times t, int steps, double dist, double calories, string achievement);
//       get_time_hms
times get_time_hms(long seconds);
//       format_time
string format_time(times t);

#endif