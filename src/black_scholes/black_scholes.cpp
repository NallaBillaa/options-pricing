#include <black_scholes.h>
#include <cmath>

double normal_cdf(double x)
{
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

double calculate_d1(double S, double K, double T, double r, double sigma)
{
    return (std::log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * std::sqrt(T));
}

double calculate_d2(double d1, double T, double sigma)
{
    return d1 - sigma * std::sqrt(T);
}

double call_price(double S, double K, double T, double r, double sigma)
{
    double d1 = calculate_d1(S, K, T, r, sigma);
    double d2 = calculate_d2(d1, T, sigma);

    double n_d1 = normal_cdf(d1);
    double n_d2 = normal_cdf(d2);

    return S * n_d1 - K * std::exp(-r * T) * n_d2;
}

double put_price(double S, double K, double T, double r, double sigma)
{
    double d1 = calculate_d1(S, K, T, r, sigma);
    double d2 = calculate_d2(d1, T, sigma);

    double n_negative_d1 = normal_cdf(-d1);
    double n_negative_d2 = normal_cdf(-d2);

    return K * std::exp(-r * T) * n_negative_d2 - S * n_negative_d1;
}