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
    double n_dash_d1 = normal_pdf(s,k,t,r,sigma);
    return n_dash_d1 / (s * sigma * std::sqrt(t));
}   

double call_theta(double s, double k, double t, double r, double sigma){
    double n_dash_d1 = normal_pdf(s,k,t,r,sigma);
    double d1 = calculate_d1(s,k,t,r,sigma);
    double d2 = calculate_d2(d1,t,sigma);
    double n_d2 = normal_cdf(d2);
    return (-s * n_dash_d1 * sigma)/(2 * std::sqrt(t)) - r * std::exp(-r * t) * n_d2;
}

double put_theta(double s, double k, double t, double r, double sigma){
    double n_dash_d1 = normal_pdf(s,k,t,r,sigma);
    double d1 = calculate_d1(s,k,t,r,sigma);
    double d2 = calculate_d2(d1,t,sigma);
    double n_negative_d2 = normal_cdf(-d2);
    return (-s * n_dash_d1 * sigma)/(2 * std::sqrt(t)) + r * std::exp(-r * t) * n_negative_d2;
}

double callput_vega(double s, double k, double t, double r, double sigma){
    double n_dash_d1 = normal_pdf(s,k,t,r,sigma);
    return s * n_dash_d1 * std::sqrt(t);
}

double call_rho(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    double d2 = calculate_d2(d1,t,sigma);
    double n_d2 = normal_cdf(d2);
    return k * t * std::exp(-r * t) * n_d2;
}

double put_rho(double s, double k, double t, double r, double sigma){
    double d1 = calculate_d1(s,k,t,r,sigma);
    double d2 = calculate_d2(d1,t,sigma);
    double n_negative_d2 = normal_cdf(-d2);
    return -k * t * std::exp(-r * t) * n_negative_d2;
}