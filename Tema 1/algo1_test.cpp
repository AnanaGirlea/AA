// Fisier pentru testarea algoritmul lui Fermat

#include "algo1.h"
#include "algo2.h"
#include <fstream>

using namespace std;

int main () {
    // Deschiem fisierle
    std::ifstream input_file;
    std::ofstream output_file;
    
    input_file.open("./test.in");
    output_file.open("./test.out");
    
    long long v[1000001],vect[1000001];
    int i, n, nr=0;
    long long k = 1000000;
    
    // Citim datele de intrare din test.in
    input_file>>n;      // Numarul de date din sir
    for(i=0;i<n;i++){
        input_file>>vect[i];  // Punem cele n elemente int-un vector
    }
    /*
    Apelam algoritmul lui Fermat pentru fiecare element din vector 
    si cream un alt vector care contine numai numerele prime din 
    sirul initial
    */
    for (i = 0; i < n; i++) {
        if (isPrimeFermat(vect[i], k)) {
            v[nr++]= vect[i];
        }       
    }

    // Varsam vectorul nou in test.out
    output_file<<nr<<endl;
    for(i=0;i<nr;i++){
        output_file<<v[i]<<" ";
    }

    // Inchidem fisierle
    input_file.close();
    output_file.close();

    return 0;
}
