#include <iostream>

using namespace std;

int NUM = 5;

#define _MAX(_x, _y) \
    ( (_x) > (_y) ? (_x) : (_y) )

#define _INC(_a) (_a)++


#ifndef _DEBUG_LEVEL
#define _MYDEBUG(_a)
#elif _DEBUG_LEVEL == 3
#define _MYDEBUG(_a) cout << __FILE__ << __LINE__ << " ; " << # _a << " is " << _a << endl;
#elif _DEBUG_LEVEL == 2
#define _MYDEBUG(_a) cout << # _a << " is " << _a << endl;
#elif _DEBUG_LEVEL == 1
int i = 0;
#define _MYDEBUG(_a) cout << "Punto di controllo " << (i++) << endl;
#endif

int main()
{
    int a = 1;
    int b = 10;

    int c = _MAX(a, b);
    int *p = &a;
    (*p)++;

    _MYDEBUG(a)
    _MYDEBUG(b)
    _MYDEBUG(c)

    _INC(*p);
}

#include "02-stampa.hpp"