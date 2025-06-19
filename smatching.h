#include <vector>
#include <string>
using namespace std;

vector<int> execInocente(string Texto, string Patron){
    vector<int> posiciones;
    int n = Texto.size();
    int m = Patron.size();
    for (int j = 0; j <= n - m; j++) {
        int i = 0;
        while (i < m && Patron[i] == Texto[j + i]) {
            i++;
        }
        if (i == m) {
            posiciones.push_back(j);
        }
    }
    return posiciones;
}


int* buildPositions(const string& Patron) {
    int* pos = new int[256];
    for (int i = 0; i < 256; i++)
        pos[i] = -1;
    for (int i = 0; i < Patron.size(); i++)
        pos[(unsigned char)Patron[i]] = i;
    return pos;
}

vector<int> execBoyerMoore(string Texto, string Patron) {
    vector<int> posiciones;
    int n = Texto.size();
    int m = Patron.size();
    int* posicionesPatron = buildPositions(Patron);

    int j = 0;
    while (j <= n - m) {
        int i = m - 1;
        while (i >= 0 && Patron[i] == Texto[j + i])
            i--;
        if (i < 0) {
            posiciones.push_back(j);
            j += (j + m < n) ? m - posicionesPatron[(unsigned char)Texto[j + m]] : 1;
        } else {
            int salto = i - posicionesPatron[(unsigned char)Texto[j + i]];
            j += max(1, salto);
        }
    }
    delete[] posicionesPatron;
    return posiciones;
}

int* buildPositions(string Patron) {
    int* array = new int[256];
    for (int i = 0; i < 256; ++i) {
        array[i] = -1; // Inicializar todas las posiciones a -1
    }
    for (int i = 0; i < Patron.size(); ++i) {
        array[Patron[i]] = i; // Guardar la última posición del carácter
    }
    return nullptr;
}