/*
 * tipo.h
 *
 * Header per la gestione del tipo di dato utilizzato nell'albero binario
 * 
 * Created on: 14 mag 2018
 * Author: federica
 * Updated: 14 agosto 2025
 */

#ifndef TIPO_H
#define TIPO_H

#include <iostream>
#include <cstring>

// ============================================================================
// DEFINIZIONE TIPO DI DATO
// ============================================================================

/**
 * Tipo di informazione memorizzata nei nodi dell'albero
 * Utilizza stringhe C-style per compatibilità
 */
typedef char* tipo_inf;

// ============================================================================
// PROTOTIPI FUNZIONI DI GESTIONE TIPO
// ============================================================================

/**
 * Confronta due elementi del tipo
 * 
 * @param a Primo elemento
 * @param b Secondo elemento
 * @return <0 se a<b, 0 se a==b, >0 se a>b
 */
int compare(tipo_inf a, tipo_inf b);

/**
 * Copia un elemento in un altro
 * 
 * @param dest Destinazione (modificata)
 * @param src Sorgente
 */
void copy(tipo_inf& dest, tipo_inf src);

/**
 * Stampa un elemento
 * 
 * @param elem Elemento da stampare
 */
void print(tipo_inf elem);

/**
 * Libera la memoria di un elemento (se necessario)
 * 
 * @param elem Elemento da liberare
 */
void destroy(tipo_inf elem);

/**
 * Crea una copia allocata dinamicamente di una stringa
 * 
 * @param str Stringa da copiare
 * @return Puntatore alla nuova stringa allocata
 */
tipo_inf create_string(const char* str);

#endif /* TIPO_H */
