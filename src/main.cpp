/* g++ -Iinclude/black_scholes src/main.cpp src/black_scholes/black_scholes.cpp src/black_scholes/greek.cpp -o option_pricing.exe

   .\option_pricing.exe */
   
#include <iostream>
#include <cmath>
#include <black_scholes.h>
#include <greek.h>

int main()
{
    double s,k,t,r,sigma;

    std::cout << "Enter Stock Price, Strike price, Time of expiration, Rate of Interest, Volatility" << "\n";
    std::cin >> s >> k >> t >> r >> sigma;

    double c, p,cd,pd,cpg;

    c = call_price(s,k,t,r,sigma);
    p = put_price(s,k,t,r,sigma);
    cd = call_delta(s,k,t,r,sigma);
    pd = put_delta(s,k,t,r,sigma);
    cpg = callput_gamma(s,k,t,r,sigma);

    std::cout << "\nOPTION PRICING\n" << "\n";
    std::cout << "Call Price = " << c << "\n";
    std::cout << "Put Price = " << p << "\n";

    std::cout << "\nGREEKS\n" << "\n";
    std::cout << "Call Delta (Δ) = " << cd << "\n";
    std::cout << "Put Delta (Δ) = " << pd << "\n";
    std::cout << "Call Gamma (Γ) = Put Gamma (Γ) = " << cpg << "\n";

    return 0;
}