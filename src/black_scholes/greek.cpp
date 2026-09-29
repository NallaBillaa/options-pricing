#include <black_scholes.h>
#include <cmath>
#include <numbers>

double call_delta(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    return normal_cdf(d1);
}

double put_delta(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    return normal_cdf(d1) - 1;
}

double normal_pdf(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    return 1 / std::sqrt(2 * std::numbers::pi) * std::exp(-d1 * d1 / 2);
}

double callput_gamma(double s, double k, double t, double r, double sigma){ 
    double n_d1 = normal_pdf(s,k,t,r,sigma);
    return n_d1 / (s * sigma * std::sqrt(t));
}   
