#include <iostream>
#include <chrono>
#include "smatching.h"

using namespace std;

void testInocente(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
}

void testBoyerMoore(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
}

int main()
{    
    //generate text
    int N = 100;
    int m = 10;
    string Texto = generarTexto(N);
    string Patron = generarTexto(m);

    testInocente(Texto, Patron);
    testBoyerMoore(Texto, Patron);

    return 0;
}
