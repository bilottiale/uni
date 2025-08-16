/*
 * btree.h
 *
 * Header per la gestione di alberi binari
 * Implementazione con puntatori a parent, left, right
 * 
 * Created on: 14 mag 2018
 * Author: federica
 * Updated: 14 agosto 2025
 */

#ifndef BTREE_H
#define BTREE_H

#include "tipo.h"

// ============================================================================
// STRUTTURE DATI
// ============================================================================

/**
 * Nodo dell'albero binario
 * 
 * Struttura che rappresenta un singolo nodo con:
 * - inf: informazione memorizzata nel nodo
 * - parent: puntatore al nodo genitore (NULL per la radice)
 * - left: puntatore al figlio sinistro
 * - right: puntatore al figlio destro
 */
struct bnode {
   tipo_inf inf;        // Informazione del nodo
   bnode* parent;       // Puntatore al genitore
   bnode* left;         // Figlio sinistro
   bnode* right;        // Figlio destro
};

/**
 * Tipo albero binario
 * Rappresentato come puntatore al nodo radice
 */
typedef bnode* btree;

// ============================================================================
// PROTOTIPI FUNZIONI - CREAZIONE E GESTIONE NODI
// ============================================================================

/**
 * Crea un nuovo nodo con l'informazione specificata
 * 
 * @param info Informazione da memorizzare nel nodo
 * @return Puntatore al nuovo nodo creato, NULL se errore
 */
bnode* new_node(tipo_inf info);

/**
 * Inserisce un sottoalbero come figlio sinistro
 * 
 * @param parent Nodo genitore
 * @param child Sottoalbero da inserire come figlio sinistro
 */
void insert_left(btree parent, btree child);

/**
 * Inserisce un sottoalbero come figlio destro
 * 
 * @param parent Nodo genitore  
 * @param child Sottoalbero da inserire come figlio destro
 */
void insert_right(btree parent, btree child);

// ============================================================================
// PROTOTIPI FUNZIONI - ACCESSO AI DATI
// ============================================================================

/**
 * Ottiene il genitore di un nodo
 * 
 * @param node Nodo di cui ottenere il genitore
 * @return Puntatore al nodo genitore, NULL se è la radice
 */
bnode* get_parent(bnode* node);

/**
 * Ottiene il figlio sinistro di un nodo
 * 
 * @param node Nodo di cui ottenere il figlio sinistro
 * @return Puntatore al figlio sinistro, NULL se non esiste
 */
bnode* get_left(bnode* node);

/**
 * Ottiene il figlio destro di un nodo
 * 
 * @param node Nodo di cui ottenere il figlio destro
 * @return Puntatore al figlio destro, NULL se non esiste
 */
bnode* get_right(bnode* node);

/**
 * Ottiene l'informazione memorizzata in un nodo
 * 
 * @param node Nodo di cui ottenere l'informazione
 * @return Informazione memorizzata nel nodo
 */
tipo_inf get_info(bnode* node);

// ============================================================================
// PROTOTIPI FUNZIONI - UTILITY E PREDICATI
// ============================================================================

/**
 * Verifica se un nodo è una foglia
 * 
 * @param node Nodo da verificare
 * @return true se è una foglia, false altrimenti
 */
bool is_leaf(bnode* node);

/**
 * Verifica se un nodo è la radice
 * 
 * @param node Nodo da verificare
 * @return true se è la radice, false altrimenti
 */
bool is_root(bnode* node);

/**
 * Verifica se un albero è vuoto
 * 
 * @param tree Albero da verificare
 * @return true se vuoto, false altrimenti
 */
bool is_empty(btree tree);

/**
 * Calcola l'altezza dell'albero
 * 
 * @param tree Radice dell'albero
 * @return Altezza dell'albero (0 per albero vuoto)
 */
int height(btree tree);

/**
 * Conta il numero di nodi nell'albero
 * 
 * @param tree Radice dell'albero
 * @return Numero di nodi
 */
int count_nodes(btree tree);

// ============================================================================
// PROTOTIPI FUNZIONI - VISITE E STAMPA
// ============================================================================

/**
 * Stampa l'albero in pre-order
 * 
 * @param tree Radice dell'albero da stampare
 */
void print_preorder(btree tree);

/**
 * Stampa l'albero in in-order
 * 
 * @param tree Radice dell'albero da stampare
 */
void print_inorder(btree tree);

/**
 * Stampa l'albero in post-order
 * 
 * @param tree Radice dell'albero da stampare
 */
void print_postorder(btree tree);

/**
 * Stampa la struttura dell'albero in forma visuale
 * 
 * @param tree Radice dell'albero da stampare
 * @param depth Profondità corrente (per indentazione)
 */
void print_tree_structure(btree tree, int depth = 0);

// ============================================================================
// PROTOTIPI FUNZIONI - GESTIONE MEMORIA
// ============================================================================

/**
 * Libera la memoria di tutto l'albero
 * 
 * @param tree Radice dell'albero da deallocare
 */
void destroy_tree(btree tree);

/**
 * Crea una copia completa dell'albero
 * 
 * @param tree Radice dell'albero da copiare
 * @return Puntatore alla radice dell'albero copiato
 */
btree copy_tree(btree tree);

#endif /* BTREE_H */
