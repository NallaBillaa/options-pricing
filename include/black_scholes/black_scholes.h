#ifndef black_scholes_h  
#define black_scholes_h

double calculate_d1(double s, double k, double t, double r, double sigma);
double calculate_d2(double d1, double t, double sigma);
double call_price(double s, double k, double t, double r, double sigma);
double put_price(double s, double k, double t, double r, double sigma); 
double normal_cdf(double x);

#endif 