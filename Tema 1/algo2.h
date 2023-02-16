// Fisier header pentru algoritmul lui Miller-Rabin

#ifndef ALGO2_H
#define ALGO2_H

#include <iostream>
#include <fstream>
using namespace std;

long long powerMiller(long long x, unsigned long long y, long long p);
bool millerTest(long long d, long long n);
bool isPrimeMiller(long long n, long long k);

#endif