#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

double firstQuartile(int *&sortedarr, int &size);

double firstQuartile(int *&sortedarr, int &size) {
    if (size/2 % 2 != 0)
        return sortedarr[size / 4];
    return (sortedarr[(size - 1) / 4] + sortedarr[size / 4]) / 2;
}