# Prog II Lab

# GDB (lldb on macOS)

**GDB** è un potente strumento di debugging per programmi in C e C++.

I bug si annidano inevitabilmente anche nel codice sviluppato da
ottimi programmatori. Buona parte del tempo di un programmatore è speso, ahimè, nel
trovare e risolvere i bug.

I bug possono produrre:

- Crash
- Cicli infiniti
- Risultati errati
- Altri casi di comportamento anomalo

Si differenziano in:

- Deterministici
- Dipendenti dall'input
- Random

Per un dato processo, GDB permette di osservare/manipolare:

- L'effetto di ciascuna linea di codice del file sorgente
- Variabili di tutti i tipi
- Lo stack delle varie chiamate a funzione in corso
- Posizioni arbitrarie della memoria
- I registri della CPU
- I diversi (eventuali) thread del processo

In pratica ficca il naso in ogni parte di un processo.

Per debuggare un programma efficacemente, occorre includere nel file
oggetto informazioni di debugging generate automaticamente in fase di
compilazione con l'opzione `-g`.

```bash
gcc -g main.c -o main
gdb main
```

Sebbene anche GDB possa debuggare anche codice ottimizzato (`-O<n>`), è meglio non produrre codice ottimizzato in fase di debug.

## Core Dump

Se un programma va in crash, tutte le informazioni del processo vengono salvate in un file.

GDB permette di ispezionare questo file come se fosse un processo in esecuzione.

Molto utile per analisi "post mortem".

## Flusso tipico di una "sessione di debug"

- Inizio sessione di debug:
  - `gbd eseguibile`
- Per passare parametri sulla linea di comando:
  - `gdb -args -eseguibile arg1 arg2 ...`
- Entro la sessione di debug:
  - `(gdb) comando1`
  - `(output comando1)`
  - `(gdb) comando2`
  - `(output comando2)`
  - ...
  - `(gdb) help comando`
- Fine sessione di debug:
  - `(gdb) quit`

## Comandi utili

- `b N_LINEA` (breakpoint): imposta un breakpoint ad una linea specifica del codice sorgente opppure ad una funzione, magari sotto condizione:
  - `(gdb) b 10`
  - `(gdb) b funzione`
  - `(gdb) b funzione if var == 0`
- `r` (run): inizia l'esecuzione del programma
- `c` (continue): continua l'esecuzione del programma fino al prossimo breakpoint
- `n` (next): esegue la prossima istruzione
- `s` (step): esegue la prossima istruzione, se è una chiamata a funzione entra nella funzione
- `f` (finish): esegue il resto della funzione corrente
- `<CTRL-C>`: interrompe l'esecuzione del programma
- `i b` (info breakpoints): mostra i breakpoint attivi
- `d N` (delete): elimina il breakpoint N
  - `(gdb) d 2`
- `watch var` (watchpoint): ferma l’esecuzione del programma quando il valore di una variabile (o di una espressione) nel contesto corrente cambia
- `watch addr` (watchpoint): ferma l’esecuzione del programma quando il valore all’indirizzo addr cambia
- `i watchpoints` (info watchpoints): mostra i watchpoints attivi
- `display var` (display): mostra il valore di una variabile ad ogni passo
- `list` (list): mostra il codice sorgente attorno alla posizione corrente
- `p var/addr` (print): mostra il valore di una variabile/indirizzo
  - `(gdb) p var`
  - `(gdb) p &var`
  - `(gdb) p argv[1]`
  - `(gdb) p A[10]@5` stampa 5 elementi dell'array A a partire dall'elemento 10
  - `(gdb) *(long *)0x614c20` stampa un long a partire dall'indirizzo 0x614c20
- `pt` (print type): mostra il tipo di una variabile

## Operazioni sullo stack

- `bt` (backtrace): mostra lo stack delle chiamate a funzione
- `f frameNumber` (frame): seleziona il frame di stack frameNumber
- `up` (up): seleziona il frame di stack precedente
- `down` (down): seleziona il frame di stack successivo
- `info locals` (info locals): mostra le variabili locali del frame corrente
- `info args` (info args): mostra gli argomenti del frame corrente

