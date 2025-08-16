/*
 * tipo.cc
 *
 * Implementazione delle funzioni per la gestione del tipo di dato
 * utilizzato nell'albero binario
 * 
 * Created on: 14 mag 2018
 * Author: federica
 * Updated: 14 agosto 2025
 */

#include "tipo.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// ============================================================================
// IMPLEMENTAZIONE FUNZIONI TIPO
// ============================================================================

int compare(tipo_inf a, tipo_inf b) {
    if (a == nullptr && b == nullptr) return 0;
    if (a == nullptr) return -1;
    if (b == nullptr) return 1;
    
    return strcmp(a, b);
}

void copy(tipo_inf& dest, tipo_inf src) {
    if (src == nullptr) {
        dest = nullptr;
        return;
    }
    
    // Alloca memoria per la copia
    int len = strlen(src);
    dest = new char[len + 1];
    strcpy(dest, src);
}

void print(tipo_inf elem) {
    if (elem == nullptr) {
        cout << "NULL";
    } else {
        cout << elem;
    }
}

void destroy(tipo_inf elem) {
    if (elem != nullptr) {
        delete[] elem;
    }
}

tipo_inf create_string(const char* str) {
    if (str == nullptr) return nullptr;
    
    int len = strlen(str);
    char* new_str = new char[len + 1];
    strcpy(new_str, str);
    return new_str;
}
