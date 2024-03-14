#include "util.h"
#include "raylib.h"
#include <math.h>

Vector3 addVector3(Vector3 a, Vector3 b) {
    return (Vector3) { a.x + b.x, a.y + b.y, a.z + b.z };
}

double clamp(double d, double min, double max) {
    const double t = d < min ? min : d;
    return t > max ? max : t;
}

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double smoothing_function(int i, int maxIn, double maxOut) {
    // Scale and translate i to fit the range [0, maxOut]
    double scaled_i = (double)i / maxIn * maxOut;

    // Apply the sigmoid function to get the smoothing effect
    double smoothed_value = sigmoid((scaled_i - maxOut / 2) * 2);

    return smoothed_value;
}
float ParametricBlend(float t)
{
    float sqr = t * t;
    return sqr / (2.0f * (sqr - t) + 1.0f);
}