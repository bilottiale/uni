### Prof. Attilio Fiandrotti
attilio.fiandrotti@unito.it
[moodle](https://informatica.i-learn.unito.it/course/view.php?id=2802)
### Info esame
4 esercizi al PC:
- 2 esercizi di programmazione:
	- iterativa
	- ricorsiva
- 1 esercizio teorico:
	- Correttezza, tipi, puntatori
- 1 esercizio su stato della memoria:
	- Evoluzione della memoria dopo N steps di un programma

[[README]]
![[C Primer Plus 6th Edition.pdf]]
## *Indice*
[[Programmazione I#Primo Algoritmo|Primo Algoritmo]]
[[Programmazione I#*Tipi di variabile*|Tipi di variabile]]
[[Programmazione I#*Modello di memoria*|Modello di memoria]]
[[Programmazione I#Type casting - Conversione di tipo|Type casting]]
[[Programmazione I#Indirizzo di una variabile|Indirizzo di memoria di una variabile]]
[[Programmazione I#Pointers|Puntatori]]
[[Programmazione I#*Espressioni booleane*|Espressione booleane e tabelle]]
[[Programmazione I#*If - Else*|Costrutti If, If-Else, While, For]]
[[Programmazione I#*Funzioni*|Funzioni]]

# *Primo Algoritmo*
**Calcolatore**: Inizialmente la persona che eseguiva i calcoli, dopo gli anni '50, un dispositivo elettromeccanico.
**Algoritmo**: procedimento di calcoli, input -> output. Prende il nome dal matematico persiano Muhammad al-Khwarismi.
## *Programmazione imperativa*
Il programma è composto da una lista *ordinata* di istruzioni. Una riga = Istruzione. Terminata l'esecuzione della riga n si passa alla riga n+1, se non specificato diversamente.

Esempio di istruzioni per un calcolatore:
* Assegna un valore ad una variabile
* Somma due variabili e memorizza il risultato in una terza variabile
* Confronta due variabili
* Esegui una riga diversa dalla successiva (sotto una certa condizione
## *Algoritmo per la moltiplicazione fra interi*
Progettiamo un algoritmo per la moltiplicazione di due numeri interi $m, n \geq 0$  ipotizzando di disporre dell’operazione di addizione che è facilmente implementabile meccanicamente o elettronicamente.

![[Pasted image 20230920165218.png|450]]

Equivalente alla somma:
![[Pasted image 20230920165555.png|450]]

Es. per $m = 4$ e $n = 3$
Definisco la somma parziale $s = 0$
![[Pasted image 20230920171124.png|450]]
Per eseguire questo algoritmo meccanicamente abbiamo bisogno di:
* Un *accumulatore* $s$
* Un *contatore* $i$

1. Impostare *accumulatore* e *contatore* a $0$
2. Se $i=n$ il numero di somme richieste è stato effettuato ed il parziale $s$ corrisponde al totale e l’algoritmo termina, *altrimenti*:
3. Sommare $m$ e $s$ ed incrementare il contatore $i$ di $1$, ritorna al punto 2
## *Tipi di variabile*

![[Pasted image 20230926221051.png|450]]
```c
char c = 'a';
int integer = 24;
float f = 24.32;
double d = 24.3435;
```
*Dichiarazione di una variabile*:
Esempio con `int`:
```c
int x;
```
Viene riservata in memoria un'area di memoria *dipendente* da tipo
## *Modello di memoria*
- Al caricamento del programma dalla memoria secondaria, viene allocata un'area di memoria per codice e dati.
- La dimensione dell'area codice è fissa.
- L'area dati ha una dimensione massima prestabilita.
- Le variabili sono allocate nell'area riservata ai dati una dopo l'altra in ordine di dichiarazione.

## *Un primo modello di memoria*
- Il *Frame Pointer*(FP) è l'indirizzo base da cui iniziare ad allocare le variabili del programma.
- Lo *Stack Pointer*(SP) indica l'indirizzo a cui allocare la prossima variabile.
- Al caricamento FP e SP coincidono.

- Dopo la dichiarazione di x, SP è decrementato di 4 bytes (4 bytes perchè x è di tipo int)
	- "Lo *Stack* cresce verso il basso" come una stalattite.
![[Pasted image 20230926214828.png|450]]
- L’allocazione di una variabile di tipo int significa consumare 4 bytes dall’area dati disponibile.
- *Dichiarare* una variabile comporta l’allocazione di un certo numero di bytes in memoria, ma non sappiamo nulla sul contenuto.
- Ipotizzeremo che il contenuto di una variabile appena dichiarata sia una sequenza casuale di bit.
- Ne indicheremo il contenuto con *?*
![[Pasted image 20230926215144.png|450]]
- Per ogni variabile dichiarata, viene allocata una quantità di memoria corrispondente al tipo.
- L’allocazione avviene in ordine di dichiarzione.

```c
int main(void){
	int x;
	int y;
	int z;
}
```
![[Pasted image 20230926215310.png|450]]
## *Assegnamento di un valore*
- Dichiarata una variabile, è possibile scrivere un valore in tale area di memoria assegnando un valore ad x con l’operatore *=*

```c
int x;
x = 10;
```
- Dichiarazione e assegnamento possono essere eseguiti sulla sulla stessa linea per semplicità (definizione).

```c
int x = 10;
```
- L’assegnamento di valore deve riflettere il tipo della variabile.
- Alcuni valori danno overflow non rilevabili dal compilatore.
![[Pasted image 20230926215628.png|450]]
- Alcune espressioni potrebbero essere interpretate diversamente da come inteso dal programmatore a seconda del tipo.
```c
int x = 8.89;
```
![[Pasted image 20230926215717.png|450]]
## *Espressioni in C*
*\<variabile> = \<espressione E>*
- L’espressione E viene valutata (evaluated)
- Se la valutazione termina con successo, si ottiene un valore che viene scritto nell’area di memoria corrispondente alla variabile di nome simbolico *\<variabile>*
* Un *parametro* per ogni modificatore:
![[Pasted image 20230926220927.png|450]]
![[Pasted image 20230926220910.png|450]]
## *I tipi float e double*
- Nel calcolo scientifico è fondamentale poter lavorare con i numeri reali, ovvero con la virgola(*floating point*).
- • I tipi *float* e *double* in C permettono di rappresentare numeri reali con precisione a 32 e 64 bit rispettivamente.
- • stampabili via printf() con gli operatori *%f*, *%g* e *%e*
## *Type casting - Conversione di tipo*
```c
int x = 2;
float z = (float)x;
```
## *Indirizzo di una variabile*
```c
&x
printf("%p", &x)
```
## *Input con scanf*
#Esempio 
```c
int main(void){
	int x;
	printf("Inserisci un numero: ");
	scanf("%d", &x);
}
```
Le variabili a cui assegnare il valore vengono espresse con il proprio *indirizzo(&)*
## *Pointers*
I *puntatori* vengono espressi con *
```c
int main(void){
	int* pX;
	pX = &x;
}
```
Un puntatore indica un *indirizzo nella memoria*.
# *Operatori di uguaglianza o relazionali*
E’ spesso necessario verificare (dis)uguaglianze o relazioni fra due numeri.

* Il C supporta espressioni booleane o logiche del tipo int \<variabile> = \<espressione E> = \<E' operatore E">
* *operatori di confronto*
	* E’ == E’’ «E’ uguale ad E’’»
	* E’ != E’’ «E’ diverso da E’’»
* *operatori relazionali*
	* E’ > E’’ «E’ maggiore di E’’»
	* E’ >= E’’ «E’ uguale o uguale di E’’»
	* E’ < E’’ «E’ minore di E’’»
	* E’ <= E’’ «E’ minore o uguale di E’’»

* Il valore di espressioni con tali operatori può essere solo 0 oppure 1
	* 0 -> no, espressione falsa (es:uguaglianza fra E’ ed E’’ non verificata)
	* 1 -> si, espressione vera (es:uguaglianza verificata)
## *Espressioni booleane*
**AND -> &&**
```C
int superato = votoScritto >= 18 *AND* domandeOrale >= 1;
```
![[Pasted image 20231003162214.png|450]]
**OR -> ||**
```c
int superato = votoScritto >= 15 *OR* domandeOrale >= 2;
```
![[Pasted image 20231003162404.png|450]]
**XOR - ^^**
```c
int superato = votoScritto >= 18 XOR domandeOrale >= 2;
```
![[Pasted image 20231004130607.png|450]]
**NOT - !**
```c
int fallito = !superato;
```
![[Pasted image 20231004130630.png|450]]
## Tipi *bool*
L’header stdbool.h offre alcune utili funzionalità:
* Definisce il tipo non nativo bool, dimensionato da gcc a seconda delle necessità
* Definisce le costanti true e false utilizzabili al posto di 0 ed 1
```c
#include<stdbool.h>
```
#Esempio 
```c
#include<stdio.h>
#include<stdbool.h>

int main(void){
	int x = 1;
	bool B = false;
	int y = 2;
}
```
![[Pasted image 20231004161223.png|450]]
# *If - Else*
## Il costrutto *if*
* Il costrutto di selezione(branch)
```c
#include<stdio.h>

int main(void){
	if(<espressione E>){
		...
	}
}
```
* Se *E* è valutata vera, il blocco codice viene eseguito
* altrimenti si passa alla linea successiva al blocco
## Il costrutto *if - else*
```c
#include<stdio.h>

int main(void){
	if(<espressione E>){
		...
	} else {
		...
	}
}
```
* Se *E* è valutata vera, il blocco codice viene eseguito, altrimenti il secondo blocco viene eseguito
## Il costrutto *while*
```c
int main(void){
	while(<espressione E>) {
		...
	}
	...
}
```
#Esempio 
```c
int main(void){
	int i = 1, n = 3;
	while(i <= n) {
		printf("%d\n", i-1);
		i = i+1;
	}
}
```
## Il costrutto *for*
```c
int main(void){
	for(<inizializzazione>;<espressione E>;<aggiornameto>){
		...
	}
	...
}
```
# *Funzioni*
```c
#include<stdio.h>

void main(void){
	int x=2, x2=0;
	x2 = square(x);
	printf («%d al quadrato: %d\n», x, x2);
}

int square(int a){
	int ret = a * a;
	return ret;
}
```
Collocazione *`return`*:
* È buona regola (e requisito d'esame) avere un singolo `return` per funzione (collocato alla fine di essa)
* Rilevante sopratutto quando il codice di una funzione ha più branch e bisogna ritornare un valore diverso a seconda del branch
* Procedura per codificare il corpo della funzione
	* dichiarare variabile `ret` di tipo appropriato a inizio funzione
	* aggiungere `return ret` alla fine della funzione
	* scrivere corpo funzione impostando il valore di `ret`
# *Chiamata a funzione e ritorno*
## Funzionamento in una CPU
![[Pasted image 20231017195310.png|200]]
* Il *Program counter (PC)* contiene l'indirizzo nella memoria del programma della *prossima* istruzione da eseguire
* All'accensione vale 0
* Alla fine di ogni istruzione viene incrementato di una parola(es, 4bytes)
* Le istruzioni di salto JMP, JEQ, etc. impostano il PC all'indirizzo della linea a cui saltare
## *Chiamata a funzione*
* Ogni chiamata a funzione comporta l’allocazione di un nuovo *frame* nella memoria stack
* L’indirizzo della prima parola del frame è memorizzato nel registro *Frame Pointer (FP)*
* L’indirizzo dell’utima parola del frame è memorizzato nel registro *Stack Pointer (SP)*
* Lo stack cresce vero il basso, quindi l’indirizzo SP < indirizzo FP
![[Pasted image 20231017195746.png|450]]
*Cosa contiene il frame?*
- una parola per l’indice della prossima linea di codice da eseguire dopo il ritorno della funzione chiamata (`retl`)
- una parola per il valore restituito dalla funzione chiamata (`retv`)
- una parola per ogni parametro della funzione chiamata
- eventuali variabili locali della funzione chiamata comportano l’allocazione di una parola per variabile, come per `main()`
![[Pasted image 20231017200145.png|450]]
![[Pasted image 20231017200209.png|450]]
![[Pasted image 20231017200230.png|450]]
![[Pasted image 20231017200248.png|450]]
# *Dereferenziamento*
## *Passaggio parametri di riferimento*
### *Per valore*
Nel passaggio parametri per valore (*by value*), il valore della variabile passata come parametro alla funzione è copiato nello stack
```c
void main(void){
	int a = 10, asq = 0;
	asq = square(a);
	printf("%d squared: %d\n", a, asq);
}

int square(int x){
	int x2 = x * x;
	return x2;
}
```
Questo metodo è adatto al caso dove il valore del parametro debba essere letto, *ma non al caso dove debba essere scritto*

I valori vengono copiati all'interno della funzione, ma non vengono scritti, `return` ritorna un unico valore.
### *Per riferimento*
È possibile dichiarare (e definire) funzioni con parametri di tipo *puntatore*
```c
int leggiInput(int* a, int*b)
```
Nello stack verranno *copiato gli indirizzi* di `a` e `b` anziché i loro valori
```c
void main(void){
	int a = 0, b = 0;
	leggiInput(&a, &b);
	printf("%d+%d=%d\n", a, b, a+b);
}

int leggiInput(int* pA, int* pB){
	printf("Inserisci due interi: ");
	scanf("%d %d", a, b);
}
```
Il passaggio per riferimento è utilizzato in tutti quei casi dove la funzione chiamata debba restituire al chiamante due o più valori.
## *Dereferenziamento*
### *I puntatori*
- L’operatore `&` anteposto ad un nome di variabile è detto referenziamento (*referencing*) produce un *puntatore alla variabile*.
- L'operatore `*` anteposto ad un nome di puntatore è detto dereferenziazione (*dereferencing*) e produce il *valore della variabile puntatata dal puntatore*
- `*<nome puntatore a variabile>` è l'inverso di `&<nome variabile>`
	- `*pX` equivale a `x`
![[Pasted image 20231024135832.png|450]]
# *Arrays*
Gli array sono collezioni di elementi dello stesso tipo allocati in *aree contigue di memoria*
Un array di N elementi si alloca come `<tipo><noma array>[<numero elementi>]`
```c
int voti[5];
```
Indicizzazione da 0 a N-1
## *Assegnazione di valore all'elemento i-esimo*
`<nome array>[<indice>] = <valore>`
o tramite valori noti: 
```c
int voti[5] = {18, 19, 20, 21, 22};
int voti[] = {18, 19, 20, 21, 22};
```





