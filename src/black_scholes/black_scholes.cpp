#include <black_scholes.h>
#include <cmath>

double normal_cdf(double x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double calculate_d1(double s, double k, double t, double r, double sigma)
{
    return (std::log(s / k) + (r + sigma * sigma / 2) * t) / (sigma * std::sqrt(t));
}

double calculate_d2(double s, double k, double t, double r, double sigma)
{
    double d1 = calculate_d1(s,k,t,r,sigma);
    return d1 - sigma * std::sqrt(t);
}

double call_price(double s, double k, double t, double r, double sigma)
{
    double d1 = calculate_d1(s, k, t, r, sigma);
    double d2 = calculate_d2(d1, t, sigma);

    double n_d1 = normal_cdf(d1);
    double n_d2 = normal_cdf(d2);

    return s * n_d1 - k * std::exp(-r * t) * n_d2;
}

double put_price(double s, double k, double t, double r, double sigma)
{
    double d1 = calculate_d1(s, k, t, r, sigma);
    double d2 = calculate_d2(d1, t, sigma);

    double n_negative_d1 = normal_cdf(-d1);
    double n_negative_d2 = normal_cdf(-d2);

    return k * std::exp(-r * t) * n_negative_d2 - s * n_negative_d1;
}