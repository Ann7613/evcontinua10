#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "smatching.h"

using namespace std;

const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789   ";

string generarTexto(int N){    
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() %  alfabeto.size()];
    return resultado;
}

void testInocente(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
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
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
}

void testSuffixTree(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    //TODO

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
}


int main()
{    
    srand(time(NULL));    
    size_t N = 100;
    int m = 10;
    string Texto = generarTexto(N);
    string Patron = generarTexto(m);    
    
    testInocente(Texto, Patron);
    testBoyerMoore(Texto, Patron);
    testSuffixTree(Texto, Patron);

    return 0;
}
