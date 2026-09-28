#include <iostream>
#include <cmath>

double normalcdf(double x){
    return .5*(std::erfc(-x/std::sqrt(2)));;
}

int main()
{
    double s,k,t,r,sigma;
    std::cin >> s >> k >> t >> r >> sigma;
    double d1,d2,n_d1,n_d2,n_negative_d1,n_negative_d2,callprice,putprice;
    
    d1 = (std::log(s / k)+(r + sigma * sigma / 2) * t) / (sigma * std::sqrt(t));
    d2 = d1 - sigma * std::sqrt(t);

    n_d1 = normalcdf(d1);
    n_d2 = normalcdf(d2);
    n_negative_d1 = normalcdf(-d1);
    n_negative_d2 = normalcdf(-d2);

    callprice = s * n_d1 - k * std::exp(-r * t) * n_d2;
    putprice = k * std::exp(-r * t) * n_negative_d2 - s * n_negative_d1;

    std::cout << "INPUT VALUES\n";
    std::cout << "Stock Price = " << s << "\n";
    std::cout << "Strike Price = " << k << "\n";
    std::cout << "Time of Expiration = " << t << "\n";
    std::cout << "Risk Free Rate = " << r << "\n";
    std::cout << "Volatility = " << sigma << "\n";

    std::cout << "\nCALCULATED VALUES:\n";
    std::cout << "d1 = " << d1 << "\n";
    std::cout << "d2 = " << d2 << "\n";
    std::cout << "n(d1) = " << n_d1 << "\n";
    std::cout << "n(d2) = " << n_d2 << "\n";
    std::cout << "n(-d1) = " << n_negative_d1 << "\n";
    std::cout << "n(-d2) = " << n_negative_d2 << "\n";

    std::cout << "\nOPTION PRICES:\n";
    std::cout << "Call Price = " << callprice << "\n";
    std::cout << "Put Price = " << putprice << "\n";

    return 0;
}
