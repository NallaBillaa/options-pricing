/* g++ -Iinclude/black_scholes src/main.cpp src/black_scholes/black_scholes.cpp src/black_scholes/greek.cpp src/black_scholes/implied_volatility.cpp -o option_pricing.exe

   .\option_pricing.exe */
   
#include <iostream>
#include <cmath>
#include <black_scholes.h>
#include <greek.h>
#include <implied_volatility.h>

int main()
{
    double s,k,t,r,sigma;

    std::cout << "Enter Stock Price, Strike price, Time of expiration, Rate of Interest, Volatility" << "\n";
    std::cin >> s >> k >> t >> r >> sigma;

    double market_price_call, market_price_put;;
    std::cout << "\nEnter Call Market Price" << "\n";
    std::cin >> market_price_call;
    std::cout << "\nEnter Put Market Price" << "\n";
    std::cin >> market_price_put;

    double c, p,cd,pd,cpg,ct,pt,cpv,cr,pr,civ,piv;

    c = call_price(s,k,t,r,sigma);
    p = put_price(s,k,t,r,sigma);
    cd = call_delta(s,k,t,r,sigma);
    pd = put_delta(s,k,t,r,sigma);
    cpg = callput_gamma(s,k,t,r,sigma);
    ct = call_theta(s,k,t,r,sigma);
    pt = put_theta(s,k,t,r,sigma);
    cpv = callput_vega(s,k,t,r,sigma);
    cr = call_rho(s,k,t,r,sigma);
    pr = put_rho(s,k,t,r,sigma);
    civ = call_iv(s,k,t,r,market_price_call);
    piv = put_iv(s,k,t,r,market_price_put);

    std::cout << "\nOPTION PRICING\n" << "\n";
    std::cout << "Black Scholes Call Price = " << c << "\n";
    std::cout << "Black Scholes Put Price = " << p << "\n";

    std::cout << "\nGREEKS\n" << "\n";
    std::cout << "Call Delta (Δ) = " << cd << "\n";
    std::cout << "Put Delta (Δ) = " << pd << "\n";
    std::cout << "Call Gamma (Γ) = Put Gamma (Γ) = " << cpg << "\n";
    std::cout << "Call Theta (Θ) = " << ct << "\n";
    std::cout << "Put Theta (Θ) = " << pt << "\n";
    std::cout << "Call Vega (v) = Put Vega (v) = " << cpv << "\n";
    std::cout << "Call Rho (ρ) = " << cr << "\n";
    std::cout << "Put Rho (ρ) = " << pr << "\n";

    std::cout << "\nIMPLIED VOLATILITY\n" << "\n";
    std::cout << "Call Implied Volatility = " << civ << "\n";
    std::cout << "Put Implied Volatility = " << piv << "\n";

    return 0;
}