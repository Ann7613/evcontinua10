#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Nodo {
    char valor;
    unordered_map<char, Nodo*> hijos;
    bool esHoja;
    int posicion;

    Nodo(char v = '\0') : valor(v), esHoja(false), posicion(-1) {}
};

void bajarPorRamas(Nodo* nodo, vector<int>& posiciones) {
    if (!nodo) return;
    if (nodo->esHoja) {
        posiciones.push_back(nodo->posicion);
    }
    for (auto& par : nodo->hijos) {
        bajarPorRamas(par.second, posiciones);
    }
}

Nodo* construirArbol(const string& texto) {
    Nodo* raiz = new Nodo();
    int n = texto.size();
    for (int i = 0; i < n; i++) {
        Nodo* nodo = raiz;
        for (int j = i; j < n; j++) {
            char c = texto[j];
            if (nodo->hijos.find(c) == nodo->hijos.end()) {
                nodo->hijos[c] = new Nodo(c);
            }
            nodo = nodo->hijos[c];
        }
        nodo->esHoja = true;
        nodo->posicion = i;
    }
    return raiz;
}

vector<int> buscarPatron(Nodo* raiz, const string& patron) {
    Nodo* nodo = raiz;
    for (char c : patron) {
        if (nodo->hijos.find(c) == nodo->hijos.end())
            return {};
        nodo = nodo->hijos[c];
    }
    vector<int> posiciones;
    bajarPorRamas(nodo, posiciones);
    return posiciones;
}

