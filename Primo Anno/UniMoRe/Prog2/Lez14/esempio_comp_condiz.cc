/*
 * Programma di esempio di compilazione condizionale.
 */
#include <iostream>

using namespace std;

#define X

int main()
{
#ifdef X
    cout << "Macro X definita" << endl;
#else
    cout << "Macro X non definita" << endl;
    cout << "Se X non � definita vi sar� un errore di sintassi perch� manca il ; " << endl cout << "Altrimenti nessun errore,perch� questa parte di codice non � "
         << "compilata affatto" << endl;
#endif

#ifdef Y
    cout << "Macro Y definita" << endl;
#else
    cout << "Macro Y non definita" << endl;
#endif
    return 0;
}
