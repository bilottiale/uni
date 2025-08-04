/*
  Scrivere un programma in cui sia definita (a tempo di scrittura
  del programma stesso) una lista formata da due elementi,
  contenenti i valori 3 e 7, e si stampi il contenuto della lista
  mediante la funzione stampalista
  
  SOLUZIONE CORRETTA:
  - Inizializza correttamente i valori inf
  - Gestisce la memoria appropriatamente
  - Output atteso: "3 7"
*/

#include <iostream>

using namespace std;

struct elem
{
  int inf;
  elem *pun;
};

typedef elem *lista;

int head(lista p) { return p->inf; }

lista tail(lista p) { return (p->pun); }

void stampalista(lista p)
{
  cout << "Lista: ";
  while (p != NULL)
  {
    cout << head(p) << " "; // stampa valore
    p = tail(p);            // spostamento sul prossimo elemento
  }
  cout << endl;
}

// Funzione helper per creare un nuovo elemento
elem* crea_elemento(int valore, elem* successivo = NULL) {
  elem* nuovo = new elem;
  nuovo->inf = valore;
  nuovo->pun = successivo;
  return nuovo;
}

// Funzione helper per liberare una lista
void libera_lista(lista& testa) {
  while (testa != NULL) {
    elem* temp = testa;
    testa = testa->pun;
    delete temp;
  }
}

int main()
{
  cout << "=== APPROCCIO 1: Creazione manuale ===" << endl;
  
  // Creo il primo elemento con valore 3
  lista testa = new elem;
  testa->inf = 3;  // Assegno il valore 3
  
  // Creo il secondo elemento con valore 7
  elem *p = new elem;
  p->inf = 7;      // Assegno il valore 7
  p->pun = NULL;   // Ultimo elemento punta a NULL
  
  // Collego i due elementi
  testa->pun = p;  // Il primo elemento punta al secondo
  
  // Stampo la lista
  stampalista(testa);
  
  // Libero la memoria manualmente
  delete p;     // Libero il secondo elemento
  delete testa; // Libero il primo elemento
  
  cout << "\n=== APPROCCIO 2: Con funzioni helper ===" << endl;
  
  // Versione più elegante con funzioni helper
  lista testa2 = crea_elemento(3, crea_elemento(7, NULL));
  
  stampalista(testa2);
  
  // Libero la memoria con funzione helper
  libera_lista(testa2);
  
  cout << "\n=== APPROCCIO 3: Costruzione dal fondo ===" << endl;
  
  // Costruisco la lista dall'ultimo al primo elemento
  lista testa3 = NULL;
  testa3 = crea_elemento(7, testa3);  // [7] -> NULL
  testa3 = crea_elemento(3, testa3);  // [3] -> [7] -> NULL
  
  stampalista(testa3);
  libera_lista(testa3);
  
  cout << "\nTutti i test completati con successo!" << endl;
  return 0;
}
