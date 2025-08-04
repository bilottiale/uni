#include "liste.h"
#include "tipo.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== TEST LISTE DOPPIE - FUNZIONI CORRETTE ===" << endl;
    
    // Test 1: Creazione lista vuota
    lista l = NULL;
    cout << "\n1. Lista vuota:" << endl;
    print_list(l);
    cout << "Lunghezza: " << list_length(l) << endl;
    cout << "Integrità: " << (verify_list_integrity(l) ? "OK" : "ERRORE") << endl;
    
    // Test 2: Inserimento elementi in testa
    cout << "\n2. Inserimento in testa (10, 20, 30):" << endl;
    elem* e1 = new_elem(10);
    elem* e2 = new_elem(20);
    elem* e3 = new_elem(30);
    
    l = insert_elem(l, e1);
    print_list(l);
    
    l = insert_elem(l, e2);
    print_list(l);
    
    l = insert_elem(l, e3);
    print_list(l);
    
    cout << "Lunghezza: " << list_length(l) << endl;
    cout << "Integrità: " << (verify_list_integrity(l) ? "OK" : "ERRORE") << endl;
    
    // Test 3: Stampa al contrario
    cout << "\n3. Stampa bidirezionale:" << endl;
    print_list(l);
    print_list_reverse(l);
    
    // Test 4: Ricerca elementi
    cout << "\n4. Test ricerca:" << endl;
    elem* trovato = search(l, 20);
    if (trovato != NULL) {
        cout << "Elemento 20 trovato!" << endl;
    } else {
        cout << "Elemento 20 non trovato" << endl;
    }
    
    trovato = search(l, 99);
    if (trovato != NULL) {
        cout << "Elemento 99 trovato!" << endl;
    } else {
        cout << "Elemento 99 non trovato" << endl;
    }
    
    // Test 5: Inserimento in coda
    cout << "\n5. Inserimento in coda (5):" << endl;
    elem* e4 = new_elem(5);
    l = insert_elem_tail(l, e4);
    print_list(l);
    print_list_reverse(l);
    
    // Test 6: Rimozione elemento
    cout << "\n6. Rimozione elemento 20:" << endl;
    elem* da_rimuovere = search(l, 20);
    if (da_rimuovere != NULL) {
        l = delete_elem(l, da_rimuovere);
        print_list(l);
        cout << "Integrità dopo rimozione: " << (verify_list_integrity(l) ? "OK" : "ERRORE") << endl;
    }
    
    // Test 7: Navigazione con tail e prev
    cout << "\n7. Test navigazione:" << endl;
    cout << "Primo elemento (head): " << head(l) << endl;
    lista secondo = tail(l);
    if (secondo != NULL) {
        cout << "Secondo elemento: " << head(secondo) << endl;
        
        lista primo_di_nuovo = prev(secondo);
        if (primo_di_nuovo != NULL) {
            cout << "Tornando al primo: " << head(primo_di_nuovo) << endl;
        }
    }
    
    // Pulizia finale
    cout << "\n8. Pulizia memoria:" << endl;
    cout << "Lunghezza finale: " << list_length(l) << endl;
    delete_list(l);
    cout << "Memoria liberata" << endl;
    
    cout << "\n=== TUTTI I TEST COMPLETATI ===" << endl;
    return 0;
}
