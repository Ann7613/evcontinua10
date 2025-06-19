#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int OFFSET = 32;
const int E = 95;

struct Nodo {
    char valor;
    Nodo* hijos[E];
    bool esHoja;
    int posicion;

    Nodo(char v = '\0') : valor(v), esHoja(false), posicion(-1) {
        for (int i = 0; i < E; ++i)
            hijos[i] = nullptr;
    }
};

void bajarPorRamas(Nodo* nodo, vector<int>& posiciones) {
    if (nodo == nullptr) return;
    if (nodo->esHoja)
        posiciones.push_back(nodo->posicion);
    for (int i = 0; i < E; ++i) {
        if (nodo->hijos[i])
            bajarPorRamas(nodo->hijos[i], posiciones);
    }
}

Nodo* construirArbol(const string& texto) {
    Nodo* raiz = new Nodo();
    int n = texto.size();
    for (int i = 0; i < n; i++) {
        Nodo* nodo = raiz;
        for (int j = i; j < n; j++) {
            char c = texto[j];
            int index = c - OFFSET;
            if (index < 0 || index >= E) break;
            if (nodo->hijos[index] == nullptr)
                nodo->hijos[index] = new Nodo(c);
            nodo = nodo->hijos[index];
        }
        nodo->esHoja = true;
        nodo->posicion = i;
    }
    return raiz;
}

vector<int> buscarPatron(Nodo* raiz, const string& patron) {
    Nodo* nodo = raiz;
    for (char c : patron) {
        int index = c - OFFSET;
        if (index < 0 || index >= E || nodo->hijos[index] == nullptr)
            return {};
        nodo = nodo->hijos[index];
    }
    vector<int> posiciones;
    bajarPorRamas(nodo, posiciones);
    return posiciones;
}


