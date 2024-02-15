#include <stdio.h>
#include <stdbool.h>

bool esiste_carattere(char* pStr, char c) {
    if (*pStr == '\0') {
        return false;
    }
    if (*pStr == c) {
        return true;
    }
    return esiste_carattere(pStr + 1, c);
}

char e2R(char* pStr) {
    if (*pStr == '\0') {
        return '\0';
    }
    char c = *pStr;
    if (esiste_carattere(pStr + 1, c)) {
        e2R(pStr + 1);
    } else {
        *pStr = *(pStr + 1);
        e2R(pStr);
    }
    return c;
}

void e2(char* pStr) {
    e2R(pStr);
}