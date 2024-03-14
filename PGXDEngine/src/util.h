#ifndef UTIL_H
#define UTIL_H

#include "raylib.h"
Vector3 addVector3(Vector3 a, Vector3 b);

double clamp(double d, double min, double max);

double sigmoid(double x);

double smoothing_function(int i, int maxIn, double maxOut);

float ParametricBlend(float t);
#endif