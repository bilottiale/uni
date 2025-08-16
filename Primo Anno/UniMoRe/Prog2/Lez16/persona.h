/*
 * persona.h
 * 
 * Definizione della struttura persona per inserisci_persone.c
 * 
 * Autore: Alessandro Bilotti
 * Data: 11 agosto 2025
 */

#ifndef PERSONA_H
#define PERSONA_H

#define MAX_NOME 30

// Struttura per rappresentare una persona
typedef struct {
    char cognome[MAX_NOME + 1];  // al più 30 caratteri + '\0'
    char nome[MAX_NOME + 1];     // al più 30 caratteri + '\0'
    char sesso;                  // 'M', 'F', 'N'
    int anno_nascita;            // anno di nascita
} Persona;

#endif /* PERSONA_H */