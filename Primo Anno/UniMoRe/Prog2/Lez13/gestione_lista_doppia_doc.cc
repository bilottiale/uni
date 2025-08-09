/**
 * @file gestione_lista_doppia_doc.cc
 * @brief Sistema di gestione di liste doppie con interfaccia utente interattiva
 * @author Corso di Programmazione 2
 * @date 2025
 * 
 * Questo programma implementa un sistema completo per la gestione di liste doppie.
 * Il programma presenta un menù all'utente che permette di:
 * - Creare una lista di n valori
 * - Cancellare tutti gli elementi contenenti un valore dato dalla lista
 * - Stampare la lista con informazioni di debug
 * - Cercare valori nella lista e navigare bidirezionalmente
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @struct elem
 * @brief Struttura che rappresenta un elemento della lista doppia
 * 
 * Ogni elemento contiene:
 * - Un campo informativo (stringa di massimo 50 caratteri)
 * - Un puntatore al prossimo elemento
 * - Un puntatore all'elemento precedente
 */
struct elem
{
	char inf[51];    ///< Campo informativo dell'elemento (URL o stringa)
	elem *pun;       ///< Puntatore al prossimo elemento (successore)
	elem *prev;      ///< Puntatore all'elemento precedente (predecessore)
};

/**
 * @typedef lista
 * @brief Tipo di dato per rappresentare una lista doppia
 * 
 * Una lista è rappresentata dal puntatore al primo elemento (testa).
 * Se la lista è vuota, il puntatore vale NULL.
 */
typedef elem *lista;

/**
 * @defgroup primitive Primitive per la gestione degli elementi
 * @brief Funzioni base per accedere agli elementi della lista
 * @{
 */

/**
 * @brief Restituisce il contenuto informativo di un elemento
 * @param p Puntatore all'elemento
 * @return Puntatore al campo informativo dell'elemento
 * @pre p != NULL
 */
char *head(lista p) { return p->inf; }

/**
 * @brief Restituisce il puntatore al prossimo elemento
 * @param p Puntatore all'elemento corrente
 * @return Puntatore al successore di p
 * @post Il valore restituito può essere NULL se p è l'ultimo elemento
 */
lista tail(lista p) { return p->pun; }

/**
 * @brief Restituisce il puntatore all'elemento precedente
 * @param p Puntatore all'elemento corrente
 * @return Puntatore al predecessore di p
 * @post Il valore restituito può essere NULL se p è il primo elemento
 */
lista prev(lista p) { return p->prev; }

/** @} */ // end of primitive group

/**
 * @defgroup gestione Funzioni di gestione della lista
 * @brief Funzioni per inserimento, cancellazione e ricerca
 * @{
 */

/**
 * @brief Inserisce un nuovo elemento in testa alla lista
 * @param l Lista di destinazione
 * @param e Puntatore al nuovo elemento da inserire
 * @return Puntatore alla nuova testa della lista
 * 
 * @details La funzione inserisce l'elemento e in testa alla lista l.
 * I collegamenti vengono aggiornati correttamente per mantenere
 * la struttura della lista doppia.
 * 
 * @dot
 * digraph insert_example {
 *   rankdir=LR;
 *   node [shape=record];
 *   
 *   before [label="PRIMA|{lista|testa} -> {elem1|inf|pun|prev}"];
 *   after [label="DOPO|{lista|testa} -> {nuovo_elem|inf|pun|prev} -> {elem1|inf|pun|prev}"];
 *   
 *   before -> after [label="insert_elem()"];
 * }
 * @enddot
 */
lista insert_elem(lista l, elem *e)
{
	e->pun = l;
	if (l != NULL)
		l->prev = e;
	e->prev = NULL;
	return e;
}

/**
 * @brief Rimuove un elemento specifico dalla lista
 * @param l Lista di origine
 * @param e Puntatore all'elemento da rimuovere
 * @return Puntatore alla testa della lista aggiornata
 * 
 * @details La funzione rimuove l'elemento e dalla lista l,
 * aggiornando correttamente tutti i collegamenti tra gli elementi
 * rimasti. La memoria dell'elemento viene liberata.
 * 
 * @warning L'elemento e deve esistere nella lista l
 */
lista delete_elem(lista l, elem *e)
{
	if (l == e)
		l = e->pun; // e è la testa della lista
	else			// e non è la testa della lista
		(e->prev)->pun = e->pun;
	if (e->pun != NULL)
		(e->pun)->prev = e->prev;
	delete e;
	return l;
}

/**
 * @brief Cerca un elemento con un valore specifico nella lista
 * @param l Lista in cui cercare
 * @param v Valore da cercare
 * @return Puntatore all'elemento trovato, NULL se non trovato
 * 
 * @details La ricerca è sequenziale e restituisce il primo elemento
 * che contiene il valore specificato.
 */
elem *search(lista l, char *v)
{
	while (l != NULL)
		if (strcmp(head(l), v) == 0)
			return l;
		else
			l = tail(l);
	return NULL;
}

/** @} */ // end of gestione group

/**
 * @defgroup interfaccia Funzioni di interfaccia utente
 * @brief Funzioni per l'interazione con l'utente
 * @{
 */

/**
 * @brief Stampa tutti gli elementi della lista con informazioni di debug
 * @param p Lista da stampare
 * 
 * @details Per ogni elemento vengono mostrati:
 * - Il contenuto informativo
 * - L'indirizzo dell'elemento
 * - L'indirizzo del successore
 * - L'indirizzo del predecessore
 * 
 * Formato output: [valore (p: addr succ:addr prev:addr) ...]
 */
void stampalista(lista p)
{
	cout << "[";
	while (p != NULL)
	{
		cout << head(p) << " "; // stampa valore
		cout << "(p: " << p << " succ:" << p->pun << " prev:" << p->prev << ")";
		p = tail(p); // spostamento sul prossimo elemento
	}
	cout << "]" << endl;
}

/**
 * @brief Crea una nuova lista con n elementi inseriti dall'utente
 * @param n Numero di elementi da inserire
 * @return Puntatore alla testa della lista creata
 * 
 * @details La funzione richiede all'utente di inserire n valori
 * e costruisce una lista inserendo ogni nuovo elemento in testa.
 * L'ordine finale sarà inverso rispetto all'ordine di inserimento.
 * 
 * @dot
 * digraph crealista_flow {
 *   rankdir=TD;
 *   start [label="Inizio\ntesta=NULL"];
 *   loop [label="Per i=1 a n"];
 *   input [label="Leggi valore\ndall'utente"];
 *   create [label="Crea nuovo\nelemento"];
 *   insert [label="Inserisci in testa"];
 *   end [label="Ritorna testa"];
 *   
 *   start -> loop;
 *   loop -> input;
 *   input -> create;
 *   create -> insert;
 *   insert -> loop [label="i++"];
 *   loop -> end [label="i > n"];
 * }
 * @enddot
 */
lista crealista(int n)
{
	lista testa = NULL;
	for (int i = 1; i <= n; i++)
	{
		elem *p = new elem;
		cout << "URL " << i << ": ";
		cin >> p->inf;
		p->pun = p->prev = NULL;
		testa = insert_elem(testa, p);
	}
	return testa;
}

/**
 * @brief Cancella tutti gli elementi con un valore specifico dalla lista
 * @param l Lista da cui cancellare
 * @param v Valore degli elementi da cancellare
 * @return Puntatore alla testa della lista aggiornata
 * 
 * @details La funzione cerca ripetutamente elementi con il valore v
 * e li rimuove fino a quando non ce ne sono più nella lista.
 * Stampa un messaggio per ogni cancellazione effettuata.
 */
lista cancella(lista l, char *v)
{
	elem *e;
	while ((e = search(l, v)) != NULL)
	{
		cout << "Cancello un elemento con valore " << v << endl;
		l = delete_elem(l, e);
	}
	cout << "Fine cancellazione!!" << endl;
	return l;
}

/**
 * @brief Permette la navigazione bidirezionale a partire da un elemento
 * @param e Elemento di partenza per la navigazione
 * 
 * @details L'utente può spostarsi avanti (F), indietro (B) o fermarsi (S).
 * Per ogni movimento viene mostrato il contenuto dell'elemento raggiunto.
 * 
 * @dot
 * digraph naviga_states {
 *   rankdir=LR;
 *   node [shape=circle];
 *   
 *   current [label="Elemento\nCorrente"];
 *   forward [label="Elemento\nSuccessivo"];
 *   backward [label="Elemento\nPrecedente"];
 *   
 *   current -> forward [label="F (Forward)"];
 *   current -> backward [label="B (Backward)"];
 *   forward -> current [label="B"];
 *   backward -> current [label="F"];
 *   current -> current [label="S (Stop)"];
 * }
 * @enddot
 */
void naviga(elem *e)
{
	char scelta;
	cout << "Trovato!!";
	do
	{
		cout << "Cosa vuoi fare (B per backward,F per forward, S per stop)" << endl;
		cin >> scelta;
		if (scelta == 'F' && tail(e) != NULL)
		{
			cout << head(tail(e)) << endl;
			e = tail(e);
		}
		else if (scelta == 'B' && prev(e) != NULL)
		{
			cout << head(prev(e)) << endl;
			e = prev(e);
		}
		else
			cout << "Elemento non esistente!!" << endl;
	} while (scelta != 'S');
}

/** @} */ // end of interfaccia group

/**
 * @brief Funzione principale del programma
 * @return 0 se l'esecuzione è avvenuta con successo
 * 
 * @details Presenta un menu interattivo all'utente con le seguenti opzioni:
 * 1. Creare una lista di n elementi
 * 2. Cancellare elementi con un valore specifico
 * 3. Stampare la lista corrente
 * 4. Cercare e navigare nella lista
 * 5. Uscire dal programma
 * 
 * @dot
 * digraph main_menu {
 *   rankdir=TD;
 *   node [shape=box];
 *   
 *   start [label="Avvio Programma"];
 *   menu [label="Mostra Menu\n1-5"];
 *   
 *   create [label="1: Crea Lista"];
 *   delete [label="2: Cancella Elementi"];
 *   print [label="3: Stampa Lista"];
 *   search [label="4: Cerca e Naviga"];
 *   exit [label="5: Esci"];
 *   
 *   start -> menu;
 *   menu -> create;
 *   menu -> delete;
 *   menu -> print;
 *   menu -> search;
 *   menu -> exit;
 *   
 *   create -> menu;
 *   delete -> menu;
 *   print -> menu;
 *   search -> menu;
 * }
 * @enddot
 */
int main()
{
	int n;
	char v[51];
	int scelta;
	lista testa = NULL;
	elem *ris;

	do
	{
		cout << "Cosa vuoi fare?" << endl;
		cout << "1: creare una lista" << endl;
		cout << "2:cancellare valori dalla lista" << endl;
		cout << "3: stampare la lista" << endl;
		cout << "4:cercare valori nella lista" << endl;
		cout << "5:esci" << endl;
		cin >> scelta;
		switch (scelta)
		{
		case 1:
			cout << "Inserire il numero di elementi da inserire nella lista" << endl;
			cin >> n;
			testa = crealista(n);
			break;
		case 2:
			cout << "Inserire il valore da cancellare:" << endl;
			cin >> v;
			testa = cancella(testa, v);
			break;
		case 3:
			stampalista(testa);
			break;
		case 4:
			cout << "Valore da cercare" << endl;
			cin >> v;
			ris = search(testa, v);
			if (ris != NULL)
				naviga(ris);
			else
				cout << "Valore non presente" << endl;
			break;
		case 5:
			cout << "Ciao, ciao!!" << endl;
		}
	} while (scelta != 5);
	return 0;
}
