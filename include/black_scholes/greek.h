#ifndef greeks_h
#define greeks_h

#include <black_scholes.h>

double call_delta(double s, double k, double t, double r, double sigma);
double put_delta(double s, double k, double t, double r, double sigma);

#endif