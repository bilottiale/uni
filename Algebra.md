### Prof. Reto Buzano
reto.buzano@unito.it
[testo](https://people.dm.unipi.it/martelli/Alg%20Lin.pdf)
[moodle]()

### Info esame
2 esami:
* 1 Matematica discreta
* 1 Algebra lineare
	* 10 scelta multipla (6/10 sufficienza)

[[README]]
[[Simbologia]]
[[Lettere]]
[[Matematica Discreta]]
# Indice
[[Algebra#Numeri reali|Numeri reali]]
# Numeri reali
[[Matematica Discreta#Insiemistica|Vedi insiemi]]
## Costruzione dei numeri reali
$Def:$ *Successione di Cauchy*: una successione $(a_{n})_{n}$ è di Cauchy se per ogni $\epsilon > 0$ esiste un intero positivo $N$ tale che ogni coppia di numeri interi positivi $n, m > N$ si ha che $|x_{n} - x_{m}| < \epsilon$.
## Criterio di convergenza di Cauchy
Il **criterio di convergenza di Cauchy** asserisce che una successione $\{a_{n}\}$di numeri reali ha limite finito se e solo se è [di Cauchy](https://it.wikipedia.org/wiki/Successione_di_Cauchy "Successione di Cauchy"). In altre parole, se e solo se per ogni $\epsilon > 0$ esiste $N$ tale che $|a_{n} - a_{m} | < \epsilon$ per ogni $n, m > N$.
#Esempio 1.5.5

$$a_{n} = (1 + \frac{1}{n})^{n} \space \text{con} \space n \geq 1$$
$$a_{1} = 2 \quad a_{2} = \left(\frac{3}{2}^{2}\right) = \frac{9}{4} = 2,25 \quad a_{3} = (\frac{4}{3})^{3} = \frac{64}{27} = 2,\overline{370}$$
È una [[Algebra#Costruzione dei numeri reali|successione di Cauchy]] che non converge a un numero razionale
Con questa interpretazione, un numero reale che abbia sviluppo decimale:
$$723, 1291851\dots$$
Corrisponde ad una [[Algebra#Costruzione dei numeri reali|successione di Cauchy]] $(a_{n})$ di numeri razionali.
$$a_{1} = 723,1$$
$$a_{2} = 723,12$$
$$a_{3} = 723,129$$
$$a_{4} = 723,1291$$
$$\dots$$
$Def:$ Siano $a, b$ due numeri reali rappresentati da due [[Algebra#Costruzione dei numeri reali|successioni di Cauchy]] $(a_{n})$ e $(b_{n})$ di numeri razionali
La *somma* $a + b$ ed il *prodotto* $a \cdot b$ sono le [[Algebra#Costruzione dei numeri reali|successioni di Cauchy]] $(a_{n} + b_{n})$ e $(a_{n}b_{n})$.
# Sistemi lineari
## Algoritmi di risoluzione
### Mosse di Gauss
Un sistema lineare è un insieme di $k$ equazioni lineari in $n$ variabili:
$$\begin{cases}
a_{11}x_{1}+\dots+a_{1n}x_{n}=b_{1} \\
\vdots \\
a_{k_{1}}x_{1}+\dots+a_{kn}x_{n}=b_{k}
\end{cases}$$
I numeri $a_{ij}$ sono i *coefficienti* e i $b_{i}$ sono i *termini noti* del sistema. Sono entrambi fissati in un campo $\mathbb{K}$.
$$A=\begin{bmatrix}
a_{11}&\dots&a_{1n} \\
\vdots & \ddots & \vdots \\
a_{k_{1}} & \dots & 1_{kn}
\end{bmatrix}, \quad b=\begin{bmatrix}
b_{1} \\
\vdots \\
b_{k}
\end{bmatrix}$$
Possiamo unire tutti in un'unica matrice $k\times(n+1):$
$$C=(A|b)$$
Il nostro scopo è determinare l'insieme $S\subset \mathbb{K}^n$ delle soluzioni del sistema.
Si può ottenere ciò tramite le *mosse di Gauss*:
1. Scambiare due righe
2. Moltiplicare una riga per un numero $\lambda \neq 0$
3. Aggiungere ad una riga un'altra riga moltiplicata per $\lambda$ qualsiasi.

### Algoritmo di Gauss
L’algoritmo trasforma una arbitraria matrice $C$ in una matrice particolare detta *a scalini*.
Ovvero una matrice nel quale il *pivot* di ogni riga è strettamente più a destra del pivot della riga precedente.
Si può ottenere ciò utilizzando le *mosse di Gauss*.
### Algoritmo di Gauss-Jordan
Dopo aver ridotto la matrice a scalini, è a volte utile fare delle ulteriori mosse di Gauss per fare in modo che tutti i numeri *sopra i pivot siano nulli*.
Si può ottenere ciò utilizzando le *mosse di Gauss*.
L'*algoritmo di Gauss-Jordan* consiste in due fasi:
1. Trasformare la matrice a scalini tramite l'algoritmo di Gauss.
2. Ottenere solo zeri sopra il pivot e i pivot uguali a 1.
## Risoluzione di un sistema lineare
Il sistema è descritto da una matrice $C = (A | b)$. Usando l’algoritmo di Gauss - Jordan, possiamo trasformare C in una matrice a scalini, in cui ogni pivot ha valore 1 e tutti i numeri sopra i pivot sono nulli.

Se fatto ciò troviamo un pivot nella colonna dei termini noti abbiamo $0=1$ che non può avere soluzione. In questo caso l'insieme delle soluzioni $S=\varnothing$.
Se invece abbiamo una matrice di questo tipo:
$$\left[\begin{array}{c c c c c c | c }
0&1&a_{13}&0&0&a_{16}&b_{1} \\
0&0&0&1&0&a_{26}&b_{2} \\
0&0&0&0&1&a_{36}&b_{3}
\end{array}\right]$$
Ricordiamo che ogni colonna corrisponde ad una variabile $x_{1},\dots,s_{n}$, eccetto l'ultima che contiene i termini noti.
Assegniamo un parametro $t_{1},t_{2},\dots$ a ciascuna variabile che corrisponde ad una colonna che non contiene pivot.
Il *pivot* coincide con il *rango*($rk$) del sistema.
$$\begin{cases}
x_{2}+a_{13}t_{2}+a_{16}t_{3} &=b_{1} \\
x_{4}+a_{26}t_{3}&=b_{2} \\
x_{5}+a_{26}t_{3}&=b_{3}
\end{cases}$$
Spostiamo a destra dell'uguale tutti i parametri:
$$\begin{cases}
x_{2}=-a_{13}t_{2}-a_{16}t_{3}+b_{1} \\
x_{4}=-a_{26}t_{3}+b_{2} \\
x_{5}=-a_{26}t_{3}+b_{3}
\end{cases}$$
Aggiungiamo i parametri liberi:
$$\begin{cases}
x_{1}=t_{1}\\
x_{2}=-a_{13}t_{2}-a_{16}t_{3}+b_{1} \\
x_{3}=t_{2} \\
x_{4}=-a_{26}t_{3}+b_{2} \\
x_{5}=-a_{26}t_{3}+b_{3} \\
x_{6}=t_{3}
\end{cases}$$
Il sistema è risolto.
#Esempio Risolviamo il sistema seguente:
$$\begin{cases}
x_{1}+3x_{2}+4x_{5}&=1 \\
x_{3}-2x_{4}&=3
\end{cases}$$
Le variabili corrispondenti ai pivot sono $x_{1}$ e $x_{3}$ Le variabili libere sono $x_{2},x_{4},x_{5}$ quindi scriviamo:
$$\begin{cases}
x_{1}=1-4t_{1}-4t_{3} \\
x_{2}=t_{1} \\
x_{3}=3+2t_{2} \\
x_{4}=t_{2} \\
x_{5}=t_{3}
\end{cases}$$
## Teorema di Rouché-Capelli
Se $rk(A)\neq rk(A|b)$ il sistema non ha soluzioni
Se $rk(A)=rk(A|b)$ il sistema ha almeno una soluzione
	- se $n$ = numero di incognite. $n-rk(A)=$ dimensione del sottospazio vettoriale generato dalle soluzioni.
Se $rk(A)=n$ la soluzione è unica.
# Applicazioni lineari
Un'*applicazione lineare* è una *funzione lineare* (o *omomorfismo*) che mette in relazione due spazi vettoriali $V$ e $W$ nel campo $K$
$$f:V\to W$$
e soddisfa due proprietà:
1. $f(v_{1}+v_{2})=f(v_{1})+f(v_{2})$
2. $f(a\cdot v)=a\cdot f(v)$
## Autovalori e Autovettori
#Definizione sia $T:V\to V$ un *endomorfismo* di uno spazio vettoriale $V$ definito su un campo $\mathbb{K}$.
Un *autovettore* di $T$ è un vettore $v\neq 0$ tale che:
$$T(v)=\lambda \cdot v$$
Per qualche $\lambda\in \mathbb{K}$. Questo $\lambda$ è l'*autovalore* associato all'autovettore $v$.
#Esempio 
Consideriamo $L_{A}:R^{2}\to R^{2}$ con $A=\begin{bmatrix}3&4\\0&2\end{bmatrix}$
- Poiché $\begin{pmatrix}3&4\\0&2\end{pmatrix}\dbinom{1}{0}=\dbinom{1}{0}=\dbinom{3}{0}=3\cdot\dbinom{1}{0}$
- Allora $e_{1}=\dbinom{1}{0}$ *è* l'autovettore con $\lambda=3$
#Esempio 
- $\begin{pmatrix}3&4\\0&2\end{pmatrix}\dbinom{0}{1}=\dbinom{4}{2}\neq \lambda\cdot\dbinom{0}{1}$ per qualsiasi $\lambda\in\mathbb{K}$
- Allora $e_{2}=\dbinom{0}{1}$ *non* è autovettore con autovalore $\lambda=3$
#Esempio 
- $\begin{pmatrix}3&4\\0&2\end{pmatrix}\dbinom{2}{3}=\dbinom{18}{6}\neq \lambda\cdot\dbinom{2}{3}$ per qualsiasi $\lambda\in\mathbb{K}$
- Allora $v=\dbinom{2}{3}$ *non* è un autovettore
#Esempio 
- $\begin{pmatrix}3&4\\0&2\end{pmatrix}\dbinom{-4}{1}=\dbinom{-8}{2}= 2\cdot\dbinom{-4}{1}$ allora
- $v=\dbinom{-4}{1}$ *è* un autovettore con autovalore $\lambda=2$
Se $v$ è un autovettore di $T$ con autovelore $\lambda,\mu\in\mathbb{K}\{0\}$ allora
$$T(\mu v)=\mu \cdot T(v)=\mu \cdot(\lambda \cdot v)=\lambda \cdot(\mu v)$$
$\mu v$ è autovettore con lo stesso autovalore $\lambda$.
## Endomorfismi (o matrici) diagonalizzabili
Un *endomorfismo* $T:V\to V$ è *diagonalizzabile* se $V$ ha una base $B=\{v_{1},\dots,v_{n}\}$ formato da autovettori di $T$.
La matrice $A=[T]_{B}^{B}$ è una matrice diagonale se e solo se $B$ è formato da autovettori di $T$.
Il vettore $v_{i}$ è autovettore di $T\iff T(v_{i})=\lambda_{i}v_{i}$ per qualche autovalore $\lambda_{i}\iff[T(v_{i})]_{B}$ è $\lambda_{i}e_{i}$.
Questo vale per ogni $i$ se e solo se
$$[T]_{B}^{B}=\begin{pmatrix}
\lambda_{1}&0&\cdots&0 \\
0&\lambda_{2}&\cdots&0 \\
\vdots&\vdots&\ddots&\vdots \\
0&0&\cdots&\lambda_{n}
\end{pmatrix}\text{\ è\ diagonale}$$
Dove ogni colonna è: $(\lambda_{1}e_{1},\lambda_{2}e_{2},\dots,\lambda_{n},e_{n})$
#Definizione 
Una matrice $A\in M(n,\mathbb{K})$ è *diagonalizzabile* se è simile ad una matrice diagonale $\Lambda$.

Le matrici diagonali sono utili, per #Esempio 
$$\begin{pmatrix}
\lambda_{1}&\cdots&0 \\
0&\ddots&0 \\
0&\cdots&\lambda_{n}
\end{pmatrix}
\begin{pmatrix}
\mu_{1}&\cdots&0 \\
0&\ddots&0 \\
0&\cdots&\mu_{n}
\end{pmatrix}
=
\begin{pmatrix}
\lambda_{1}\mu_{1}&\cdots&0 \\
0&\ddots&0 \\
0&\cdots&\lambda_{n}\mu_{n}
\end{pmatrix}$$
Se $A=\begin{pmatrix}\lambda_{1}&\cdots&0 \\0&\ddots&0 \\0&\cdots&\lambda_{n}\end{pmatrix}$ allora $A^{k}=\underbrace{A\cdot A\cdot \dots \cdot A}_{k \text{ volte}}=\begin{pmatrix}\lambda_{1}^{k}&\cdots&0 \\0&\ddots&0 \\0&\cdots&\lambda_{n}^{k}\end{pmatrix}$
#Esempio 
$A=\begin{pmatrix}3&4\\0&2\end{pmatrix}$ vogliamo calcolare $A^{22}$

--> Metodo 1: $A\cdot A\cdot A\cdot\dots$
$A\cdot A=\begin{pmatrix}3&4\\0&2\end{pmatrix}\begin{pmatrix}3&4\\0&2\end{pmatrix}=\begin{pmatrix}9&20\\0&4\end{pmatrix}$
$A^{3}=\begin{pmatrix}3&4\\0&2\end{pmatrix}\begin{pmatrix}9&20\\0&4\end{pmatrix}=\begin{pmatrix}27&76\\0&8\end{pmatrix}$
Ec...
--> Metodo 2: $\Lambda=V^{-1}AV$ è diagonale $\iff A=V\Lambda V^{-1}$
$$\begin{align}
A^{22}&=(V\Lambda V^{-1})\cdot(V\Lambda V^{-1})\cdot(V\Lambda V^{-1})\dots(V\Lambda V^{-1})\\
&=V\Lambda^{22}V^{-1} \\
&=
\begin{pmatrix}
1&-4 \\
0&1
\end{pmatrix}
\begin{pmatrix}
3^{22}&0 \\
0&2^{22}
\end{pmatrix}
\begin{pmatrix}
1&4 \\
0&1
\end{pmatrix} \\
&=\dots
\end{align}$$
## Polinomio Caratteristico
Sia $A\in M(n,\mathbb{K})$. Il *polinomio caratteristico* di $A$ è definiti da:
$$P_{A}(\lambda):=\det(A-\lambda \cdot I_{n})=\det \begin{pmatrix}
a_{11}-\lambda&a_{12}&\cdots&a_{1n} \\
a_{21}&a_{22}-\lambda&\cdots&a_{21} \\
\vdots&\vdots&\ddots&\vdots& \\
a_{n1}&a_{n2}&\cdots&a_{nm}-\lambda
\end{pmatrix}$$
$P_{A}(\lambda)=a_{n}\lambda^{n}+a_{n-1}\lambda^{n-1}+\dots+a_{1}\lambda+a_{0}$
con $a_{n}=(-1)^{n}$
# Sistemi lineari
## Algoritmi di risoluzione
### Mosse di Gauss
Un sistema lineare è un insieme di $k$ equazioni lineari in $n$ variabili:
$$\begin{cases}
a_{11}x_{1}+\dots+a_{1n}x_{n}=b_{1} \\
\vdots \\
a_{k_{1}}x_{1}+\dots+a_{kn}x_{n}=b_{k}
\end{cases}$$
I numeri $a_{ij}$ sono i *coefficienti* e i $b_{i}$ sono i *termini noti* del sistema. Sono entrambi fissati in un campo $\mathbb{K}$.
$$A=\begin{bmatrix}
a_{11}&\dots&a_{1n} \\
\vdots & \ddots & \vdots \\
a_{k_{1}} & \dots & 1_{kn}
\end{bmatrix}, \quad b=\begin{bmatrix}
b_{1} \\
\vdots \\
b_{k}
\end{bmatrix}$$
Possiamo unire tutti in un'unica matrice $k\times(n+1):$
$$C=(A|b)$$
Il nostro scopo è determinare l'insieme $S\subset \mathbb{K}^n$ delle soluzioni del sistema.
Si può ottenere ciò tramite le *mosse di Gauss*:
1. Scambiare due righe
2. Moltiplicare una riga per un numero $\lambda \neq 0$
3. Aggiungere ad una riga un'altra riga moltiplicata per $\lambda$ qualsiasi.

### Algoritmo di Gauss
L’algoritmo trasforma una arbitraria matrice $C$ in una matrice particolare detta *a scalini*.
Ovvero una matrice nel quale il *pivot* di ogni riga è strettamente più a destra del pivot della riga precedente.
Si può ottenere ciò utilizzando le *mosse di Gauss*.
### Algoritmo di Gauss-Jordan
Dopo aver ridotto la matrice a scalini, è a volte utile fare delle ulteriori mosse di Gauss per fare in modo che tutti i numeri *sopra i pivot siano nulli*.
Si può ottenere ciò utilizzando le *mosse di Gauss*.
L'*algoritmo di Gauss-Jordan* consiste in due fasi:
1. Trasformare la matrice a scalini tramite l'algoritmo di Gauss.
2. Ottenere solo zeri sopra il pivot e i pivot uguali a 1.
## Risoluzione di un sistema lineare
Il sistema è descritto da una matrice $C = (A | b)$. Usando l’algoritmo di Gauss - Jordan, possiamo trasformare C in una matrice a scalini, in cui ogni pivot ha valore 1 e tutti i numeri sopra i pivot sono nulli.

Se fatto ciò troviamo un pivot nella colonna dei termini noti abbiamo $0=1$ che non può avere soluzione. In questo caso l'insieme delle soluzioni $S=\varnothing$.
Se invece abbiamo una matrice di questo tipo:
$$\left[\begin{array}{c c c c c c | c }
0&1&a_{13}&0&0&a_{16}&b_{1} \\
0&0&0&1&0&a_{26}&b_{2} \\
0&0&0&0&1&a_{36}&b_{3}
\end{array}\right]$$
Ricordiamo che ogni colonna corrisponde ad una variabile $x_{1},\dots,s_{n}$, eccetto l'ultima che contiene i termini noti.
Assegniamo un parametro $t_{1},t_{2},\dots$ a ciascuna variabile che corrisponde ad una colonna che non contiene pivot.
Il *pivot* coincide con il *rango*($rk$) del sistema.
$$\begin{cases}
x_{2}+a_{13}t_{2}+a_{16}t_{3} &=b_{1} \\
x_{4}+a_{26}t_{3}&=b_{2} \\
x_{5}+a_{26}t_{3}&=b_{3}
\end{cases}$$
Spostiamo a destra dell'uguale tutti i parametri:
$$\begin{cases}
x_{2}=-a_{13}t_{2}-a_{16}t_{3}+b_{1} \\
x_{4}=-a_{26}t_{3}+b_{2} \\
x_{5}=-a_{26}t_{3}+b_{3}
\end{cases}$$
Aggiungiamo i parametri liberi:
$$\begin{cases}
x_{1}=t_{1}\\
x_{2}=-a_{13}t_{2}-a_{16}t_{3}+b_{1} \\
x_{3}=t_{2} \\
x_{4}=-a_{26}t_{3}+b_{2} \\
x_{5}=-a_{26}t_{3}+b_{3} \\
x_{6}=t_{3}
\end{cases}$$
Il sistema è risolto.
#Esempio Risolviamo il sistema seguente:
$$\begin{cases}
x_{1}+3x_{2}+4x_{5}&=1 \\
x_{3}-2x_{4}&=3
\end{cases}$$
Le variabili corrispondenti ai pivot sono $x_{1}$ e $x_{3}$ Le variabili libere sono $x_{2},x_{4},x_{5}$ quindi scriviamo:
$$\begin{cases}
x_{1}=1-4t_{1}-4t_{3} \\
x_{2}=t_{1} \\
x_{3}=3+2t_{2} \\
x_{4}=t_{2} \\
x_{5}=t_{3}
\end{cases}$$
## Teorema di Rouché-Capelli
Se $rk(A)\neq rk(A|b)$ il sistema non ha soluzioni
Se $rk(A)=rk(A|b)$ il sistema ha almeno una soluzione
	- se $n$ = numero di incognite. $n-rk(A)=$ dimensione del sottospazio vettoriale generato dalle soluzioni.
Se $rk(A)=n$ la soluzione è unica.
# Applicazioni lineari
Un'*applicazione lineare* è una *funzione lineare* (o *omomorfismo*) che mette in relazione due spazi vettoriali $V$ e $W$ nel campo $K$
$$f:V\to W$$
e soddisfa due proprietà:
1. $f(v_{1}+v_{2})=f(v_{1})+f(v_{2})$
2. $f(a\cdot v)=a\cdot f(v)$






