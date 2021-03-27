#include <iostream>

using namespace std;

long double correlationCoefficient(long double cov, long double stdevX, long double stdevY) { 
    return (cov / (stdevX * stdevY));
} 
