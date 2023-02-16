// Algoritmul lui Fermat pentru identificarea numerelor prime

#include "algo1.h"
#include <iostream>
#include <fstream>
using namespace std;

// Functie iterativa care calculeaza (a^n)%p
long long powerFermat(long long a, unsigned long long n, long long p)
{
	long long res = 1;	 
	a = a % p; // Daca 'a' >= p, a va face update

	while (n > 0)
	{
		// Daca n este impar, acesta se imnulteste cu res
		if (n % 2 == 1)
			res = (res*a) % p;
		n = n / 2; 
		a = (a*a) % p;
	}
	return res %p;
}

/*
Daca n este prim functia va intoarce true.
Daca n nu este prim functia va intarce false.
Cu cat k este mai mare, cu atat este mai probabil ca 
	rasunsul este corect.
*/
bool isPrimeFermat(unsigned long long n, long long k)
{
// Cazuri particulare 
if (n <= 1 || n == 4) return false;
if (n <= 3) return true;

// Cand n este mai mare decat 4 se continua cu while
while (k>0)
{
	// Se alege un numar random din intervalul [2..n-2]
	long long a = 2 + rand()%(n-4);

	// Mica teorema a lui Fermat
	if (powerFermat(a, n-1, n) != 1)
		return false;

	k--;
	}

	return true;
}