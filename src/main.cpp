#include <iostream>
#include <cmath>
#include <black_scholes.h>
#include <greek.h>

int main()
{
    double s,k,t,r,sigma;

    std::cout << "Enter Stock Price, Strike price, Time of expiration, Rate of Interest, Volatility" << "\n";
    std::cin >> s >> k >> t >> r >> sigma;

    double c, p,cd,pd;

    c = call_price(s,k,t,r,sigma);
    p = put_price(s,k,t,r,sigma);

    cd = call_delta(s,k,t,r,sigma);
    pd = put_delta(s,k,t,r,sigma);

    std::cout << "OPTION PRICING" << "\n";
    std::cout << "Call Price = " << c << "\n";
    std::cout << "Put Price = " << p << "\n";

    std::cout << "GREEKS" << "\n";
    std::cout << "Call Delta (Δ) = " << cd << "\n";
    std::cout << "Put Price (Δ) = " << pd << "\n";

    return 0;
}