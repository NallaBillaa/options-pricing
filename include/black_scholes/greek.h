#ifndef greeks_h
#define greeks_h

#include <black_scholes.h>

double call_delta(double s, double k, double t, double r, double sigma);
double put_delta(double s, double k, double t, double r, double sigma);
double normal_pdf(double s, double k, double t, double r, double sigma);
double callput_gamma(double s, double k, double t, double r, double sigma);
double call_theta(double s, double k, double t, double r, double sigma);
double put_theta(double s, double k, double t, double r, double sigma);
double callput_vega(double s, double k, double t, double r, double sigma);
double call_rho(double s, double k, double t, double r, double sigma);
double put_rho(double s, double k, double t, double r, double sigma);

#endif