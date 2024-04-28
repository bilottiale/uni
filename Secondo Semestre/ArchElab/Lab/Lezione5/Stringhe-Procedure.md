# Stringhe - Procedure

## Esecuzione di una procedura

1. Inserire i parametri in un luogo accessibile alla procedura
2. Trasferire il controllo alla procedura
3. Accedere alle risorse necessarie per l’esecuzione della procedura
4. Eseguire il compito richiesto
5. Salvare il risultato in un luogo accessibile al programma chiamante
6.  Restituire il controllo al punto di origine, dato che la stessa procedura può
essere chiamata in diversi punti di un programma

## Parametri e Indirizzo di Ritorno

`a0-a7 (x10-x17)` sono regustri utilizzati dai parametri, utilizzati
quindi per passare valori alle funzioni o restituire valori al chiamante.

`rx(x2)` contiene l'indirizzo di ritorno.

## `jal` e `jalr`: Passaggi di controllo

L’istruzione `jal` (jump and link) serve per la chiamata di funzioni:
produce un salto a un indirizzo e salva l’indirizzo dell’istruzione
successiva a quella del salto nel registro `ra`.

Il ritorno da una procedura utilizza un salto indiretto, jump and link
register (`jalr`)

- la funzione chiamante mette i parametri in `a0-a7` e usa `jal x` per saltare alla funzione `x`
- la funzione chiamata svolge le proprie operazioni, inserisce i risultati
negli stessi registri e restituisce il controllo al chiamante con
l’istruzione `jr ra`.

## Codific ASCII

load byte unsigned (`lbu`) prende un byte dalla memoria mettendolo
negli 8 bit di un registro, collocati più a destra.

store byte (`sb`) prende il byte corrispondente agli 8 bit di un registro,
collocati più a destra, e lo salva in memoria

```
lbu x12, 0(x10) // Leggi un byte dall’indirizzo sorgente
sb x12, 0(x11) // Scrivi il byte all’indirizzo di destinazione
```
