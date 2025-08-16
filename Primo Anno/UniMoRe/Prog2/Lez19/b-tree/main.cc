/*
 * main.cc
 *
 * Programma di test per l'albero binario
 * Dimostra l'utilizzo delle funzioni implementate
 * 
 * Created on: 14 agosto 2025
 * Author: Alessandro Bilotti
 */

#include <iostream>
using namespace std;

#include "tipo.h"
#include "btree.h"

void test_creazione_albero() {
    cout << "\n🌳 TEST CREAZIONE ALBERO BINARIO" << endl;
    cout << "=================================" << endl;
    
    // Crea nodi
    btree root = new_node(create_string("A"));
    btree left = new_node(create_string("B"));
    btree right = new_node(create_string("C"));
    btree left_left = new_node(create_string("D"));
    btree left_right = new_node(create_string("E"));
    
    // Costruisci albero
    insert_left(root, left);
    insert_right(root, right);
    insert_left(left, left_left);
    insert_right(left, left_right);
    
    cout << "Albero creato:" << endl;
    cout << "       A" << endl;
    cout << "      / \\" << endl;
    cout << "     B   C" << endl;
    cout << "    / \\" << endl;
    cout << "   D   E" << endl;
    
    cout << "\nInformazioni nodi:" << endl;
    cout << "Root: "; print(get_info(root)); cout << endl;
    cout << "Left child of root: "; print(get_info(get_left(root))); cout << endl;
    cout << "Right child of root: "; print(get_info(get_right(root))); cout << endl;
    cout << "Left-left: "; print(get_info(get_left(get_left(root)))); cout << endl;
    cout << "Left-right: "; print(get_info(get_right(get_left(root)))); cout << endl;
}

void test_navigazione() {
    cout << "\n🧭 TEST NAVIGAZIONE ALBERO" << endl;
    cout << "===========================" << endl;
    
    // Crea un piccolo albero
    btree root = new_node(create_string("Root"));
    btree left = new_node(create_string("Left"));
    btree right = new_node(create_string("Right"));
    
    insert_left(root, left);
    insert_right(root, right);
    
    // Test navigazione
    cout << "Root: "; print(get_info(root)); cout << endl;
    
    bnode* left_node = get_left(root);
    cout << "Left child: "; print(get_info(left_node)); cout << endl;
    cout << "Parent of left: "; print(get_info(get_parent(left_node))); cout << endl;
    
    bnode* right_node = get_right(root);
    cout << "Right child: "; print(get_info(right_node)); cout << endl;
    cout << "Parent of right: "; print(get_info(get_parent(right_node))); cout << endl;
}

void test_tipo_dato() {
    cout << "\n📝 TEST GESTIONE TIPO DATO" << endl;
    cout << "===========================" << endl;
    
    // Test creazione stringhe
    tipo_inf str1 = create_string("Hello");
    tipo_inf str2 = create_string("World");
    tipo_inf str3;
    
    cout << "String 1: "; print(str1); cout << endl;
    cout << "String 2: "; print(str2); cout << endl;
    
    // Test copia
    copy(str3, str1);
    cout << "String 3 (copia di str1): "; print(str3); cout << endl;
    
    // Test confronto
    int cmp = compare(str1, str2);
    cout << "Confronto str1 vs str2: " << cmp << endl;
    
    cmp = compare(str1, str3);
    cout << "Confronto str1 vs str3: " << cmp << endl;
    
    // Cleanup
    destroy(str1);
    destroy(str2);
    destroy(str3);
}

int main() {
    cout << "🎯 PROGRAMMA DI TEST - ALBERO BINARIO" << endl;
    cout << "======================================" << endl;
    
    test_tipo_dato();
    test_creazione_albero();
    test_navigazione();
    
    cout << "\n✅ Tutti i test completati!" << endl;
    
    return 0;
}
