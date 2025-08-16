/*
 * main_fixed.cc - Versione corretta con input robusto
 */

#include <iostream>
#include <limits>
using namespace std;

#include "tipo.h"
#include "bst.h"

void print_BST(bst b)
{
	if (b == NULL) {
		return;  // Protezione contro nodi nulli
	}
	
	if (get_left(b) != NULL)
		print_BST(get_left(b));
		
	print_key(get_key(b));
	cout << "  ";
	print(get_value(b));
	cout << endl;
	
	if (get_right(b) != NULL)
		print_BST(get_right(b));
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	bst t = NULL;
	int continua;
	int k;
	char i[100];  // Buffer più grande

	cout << "🌳 BST PRINT - Binary Search Tree" << endl;
	cout << "=================================" << endl;

	do
	{
		cout << "\nInserisci valore di chiave (intero): ";
		while (!(cin >> k)) {
			cout << "❌ Errore: inserisci un numero intero valido: ";
			clearInputBuffer();
		}
		
		cout << "Inserisci valore informativo (stringa): ";
		cin >> i;  // Leggiamo come una singola parola
		
		bnode *b = bst_newNode(k, i);
		cout << "✅ Nodo creato - Chiave: " << get_key(b) << ", Valore: '" << get_value(b) << "'" << endl;
		bst_insert(t, b);
		
		cout << "Per terminare digitare 0, per continuare altro valore: ";
		while (!(cin >> continua)) {
			cout << "❌ Errore: inserisci 0 per terminare o altro numero per continuare: ";
			clearInputBuffer();
		}
		
	} while (continua != 0);
	
	cout << "\n🌳 STAMPA BST (in-order):" << endl;
	cout << "=========================" << endl;
	if (t != NULL) {
		print_BST(t);
	} else {
		cout << "❌ Albero vuoto!" << endl;
	}
	
	cout << "\n✅ Programma terminato." << endl;
	return 0;
}
