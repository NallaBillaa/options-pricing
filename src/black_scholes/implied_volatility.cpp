#include <iostream>
#include <black_scholes.h>
#include <greek.h>
#include <cmath>

double call_iv(double s, double k, double t, double r, double market_price){
    double low = 0.01;
    double high = 1;
    double tolerance = 0.000001;

    for (int i=0;i<100;i++){
        double mid = (low + high) / 2;
        double price = call_price(s,k,t,r,mid);

        if(std::abs(price - market_price) < tolerance){
            return mid;
        }

        if(price < market_price){
            low = mid;
        }
        else{
            high = mid;
        }
    } 
    return (low + high) / 2;
}

double put_iv(double s, double k, double t, double r, double market_price){
    double low = 0.01;
    double high = 1;
    double tolerance = 0.000001;

    for (int i=0;i<100;i++){
        double mid = (low + high) / 2;
        double price = put_price(s,k,t,r,mid);

        if(std::abs(price - market_price) < tolerance){
            return mid;
        }

        if(price < market_price){
            low = mid;
        }
        else{
            high = mid;
        }
    } 
    return (low + high) / 2;
}