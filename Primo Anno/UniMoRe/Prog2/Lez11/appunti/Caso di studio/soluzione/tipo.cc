#include "tipo.h"
#include <iostream>
using namespace std;

// Implementazione delle funzioni per il tipo

int compare(tipo_inf a, tipo_inf b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

void copy(tipo_inf& dest, tipo_inf src) {
    dest = src;
}

void print(tipo_inf value) {
    cout << value;
}
