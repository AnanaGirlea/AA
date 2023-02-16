// Algoritmul lui Miller-Rabin pentru identificarea numerelor prime

#include "algo2.h"
#include <iostream>
#include <fstream>
using namespace std;

// Functie iterativa care calculeaza (x^y) % p
long long powerMiller(long long x, unsigned long long y, long long p)
{
	long long res = 1;
	x = x % p;	// Daca 'a' >= p, a va face update

	while (y > 0)
	{
		// Daca n este impar, acesta se imnulteste cu res
		if (y % 2 == 1)
			res = (res*x) % p;
		y = y / 2;
		x = (x*x) % p;
	}
	return res % p;
}

/*
Daca n este prim functia va intoarce true.
Daca n nu este prim functia va intarce false.
Cu cat k este mai mare, cu atat este mai probabil ca 
	rasunsul este corect.
'd' este impar cu proprietatea ca d*2^r= n-1 
	pentru r >= 1
*/
bool millerTest(long long d, long long n)
{
	// Se alege un numar random din intervalul [2..n-2]
	long long a = 2 + rand() % (n - 4);

	long long x = powerMiller(a, d, n);		// Calculeaza a^d % n

	if (x == 1 || x == n-1)
	return true;

	/*
	Se continua inmultirea cu 'x' cat timp:
	1) d < (n-1)
	2) (x^2) % n != 1
	3) (x^2) % n != n-1
	*/
	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	return false;
}

/*
Daca n este prim functia va intoarce true.
Daca n nu este prim functia va intarce false.
Cu cat k este mai mare, cu atat este mai probabil ca 
	rasunsul este corect.
*/
bool isPrimeMiller(long long n, long long k)
{
	// Cazuri particulare 
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Calculam r astfel incat n = 2^d * r + 1 pentru r >= 1
	long long d = n - 1;

	// Cand n este mai mare decat 4 se continua cu while
	while (d % 2 == 0)
		d /= 2;

	// Iteram de k ori
	long long i;
	for (i = 0; i < k; i++)
		if (!millerTest(d, n))
			return false;

	return true;
}