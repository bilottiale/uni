/*
 * test_simple.cc - Test semplificato per BST
 */

#include <iostream>
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

int main()
{
	bst t = NULL;
	
	cout << "🧪 TEST BST SEMPLIFICATO" << endl;
	cout << "========================" << endl;
	
	// Test con dati predefiniti
	cout << "Inserisco nodi: (10,'primo'), (5,'secondo'), (15,'terzo')" << endl;
	
	bnode *n1 = bst_newNode(10, (char*)"primo");
	cout << "Nodo 1: " << n1 << " chiave=" << get_key(n1) << " valore=" << get_value(n1) << endl;
	bst_insert(t, n1);
	
	bnode *n2 = bst_newNode(5, (char*)"secondo");
	cout << "Nodo 2: " << n2 << " chiave=" << get_key(n2) << " valore=" << get_value(n2) << endl;
	bst_insert(t, n2);
	
	bnode *n3 = bst_newNode(15, (char*)"terzo");
	cout << "Nodo 3: " << n3 << " chiave=" << get_key(n3) << " valore=" << get_value(n3) << endl;
	bst_insert(t, n3);
	
	cout << "\n🌳 STAMPA BST (in-order):" << endl;
	cout << "=========================" << endl;
	if (t != NULL) {
		print_BST(t);
	} else {
		cout << "Albero vuoto!" << endl;
	}
	
	return 0;
}
