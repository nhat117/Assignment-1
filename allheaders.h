#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <chrono>

using namespace std;

// Function Declaration
long double mean(long double* arr, int size);
long double findMedian(long double* sortedArr, int size);
void mode(long double* arr, int size);
long double variance(long double* myarray, int size, long double meanNum);
long double stdev(long double variance);
long double mad(long double* ar, int size, long double meanNum);
long double firstQuartile(long double* sortedarr, int size);
long double skew(long double* arr, int size, long double var, long double meanNum);
long double kurt(long double *inputarray, int size, long double mean, long double deviation);
long double covariance(long double* arX, long double* arY, int arSize, long double meanX, long double meanY);
long double pcc(long double covXY, long double stdevX, long double stdevY);
void LinearRegression(long double mean_x, long double mean_y, long double stdev_x, long double stdev_y, long double r);
bool numberChk(string &inp);
void splitStr(string &line, string &x, string &y);
void merge(long double* &arr, int l, int m, int r);
void mergeSort(long double* &arr, int l, int r);