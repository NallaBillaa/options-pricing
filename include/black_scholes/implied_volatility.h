#ifndef implied_volatility
#define implied_volatility

double call_iv(double s, double k, double t, double r, double market_price);
double put_iv(double s, double k, double t, double r, double market_price);

#endif