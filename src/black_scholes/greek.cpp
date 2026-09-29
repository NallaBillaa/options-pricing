#include <black_scholes.h>
#include <cmath>

double call_delta(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    return normal_cdf(d1);
}

double put_delta(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    return normal_cdf(d1) - 1;
}


