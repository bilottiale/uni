# Insiemi
$$\text{ Numeri interi }\mathbb{Z}=\{\dots,-5,-4,-3,-2,-1,0,1,2,3,4,5,\dots\}$$
$$\text{Numeri razionali }\mathbb{Q}=\left\{ \frac{a}{b}|a,b\in \mathbb{Z} \text{ e }b\neq 0 \right\}$$
## Prodotto cartesiano
$$A\times B=\{(a,b)|a\in A \text{ e }b\in B\}$$
Se $|A|=n$ e $|B|=n$, $|A\times B|=nm$.
# Funzioni
$f(a)$ è detta **immagine** di $a$ tramite $f$.
Una funzione si dice **suriettiva** se $Im(f)=B$, ovvero se per ogni $b\in B$ esiste sempre $a\in A$ tale che $f(a)=b$.
Una funzione si dice **iniettiva** se per ogni scelta di $a_{1},a_{2}\in A$ con $a_{1}\neq a_{2}$ si ha $f(a_{1})\neq f(a_{2})$.
Sia $f:A\to B$ una funzione e sia $b\in B$. Si dice **controimmagine** di $b$ tramite $f$ il sottoinsieme $f^{-1}(b)$ degli elementi del dominio $A$ che hanno $b$ come immagine, cioè: $f^{-1}(b)=\{a\in A!f(a)=b\}$.

Siano $f:A\to B$ e $g:B\to C$ due funzioni. La *composizione* di $f$ e $g$ è $g\circ f$: $g \circ f: A\to C, (g\circ f)(a)=g(f(a))$.
# Combinatoria
## Principio di Inclusione-Esclusione
$$|A\cup B|=|A|+|B|-|A\cap B|$$
$$|A\cup B\cup C|=|A|+|B|+|C|-|A\cap B|-|A\cap C|-|B\cap C|+|A\cap B\cap C|$$
## Ordinamenti
Un **ordinamento** di $A$ è una funzione biettiva $I_{n}\to A$.
$$
n!=
\begin{cases}
\begin{align}
&1 &\text{se }n=0 \\
&1\cdot 2\cdot 3\cdot\dots&\text{se }n\geq 1
\end{align}
\end{cases}
$$
## Disposizioni con ripetizioni
$$D_{n,k}=\underbrace{n\cdot n \cdot n\cdot\dots}_{{k\text{ volte}}}=n^{k}$$
## Disposizioni semplici
$$D_{n,k}=\frac{n!}{(n-k)!}=n(n-1)\cdot\ldots \cdot(n-k+1)$$
## Combinazioni semplici
$$C_{n,k}=\frac{n!}{k!\cdot(n-k)!}=\frac{n!}{k!}$$
## Coefficienti binomiali
Per $\frac{n!}{k!(n-k)!}$:
$$
C_{n,k}=
\dbinom{n}{k}
=\frac{n!}{k!(n-k)!}
$$
$$
\dbinom{n-1}{k-1}
+
\dbinom{n-1}{k}
=
\dbinom{n}{k}
$$
# Divisione euclidea
$$a=qb+r$$
$MCD(a,b)$:
$$
\begin{align}
a&=q_{1}b+r_{1} \\
b&=q_{2}r_{1}+r_{2} \\
r_{1}&=q_{3}r_{2}+r_{3} \\
r_{2}&=q_{4}r_{3}+r_{4} \\
&\vdots \quad \quad \quad \vdots
\end{align}
$$
## Identità di Bezout
Siano $a$ e $b$ due numeri interi e sia $d=MCD(a,b)$. Allora esistono numeri interi $A$ e $B$ tali che:
$$d=aA+bB$$
## Teorema fondamentale dell'aritmetica
Un numero $n$ è primo o prodotto di numeri primi.
# Permutazioni
Sia $X$ un insieme non vuoto. Si dice **permutazione di $X$** una funzione biettiva:
$$f:X\to X.$$
L'insieme di tutte le permutazioni di $X$ si denota $S_{X}$.
$$\pi:I_{n}\to I_{n}$$
$$
\begin{pmatrix}
1 & 2 & 3 & \dots & n \\
\pi(1) & \pi(2) & \pi(3) & \dots & \pi(n)
\end{pmatrix}
$$
$$
\begin{pmatrix}
1 & 2 & 3 & 4 & 5 & 6 & 7 \\
3 & 2 & 6 & 1 & 5 & 7 & 4
\end{pmatrix}
$$
## Cicli
Sia $2\leq l \leq n$ un intero e siano $t_{1},t_{2},\dots,t_{l}$ elementi a due a due distinti di $I_{n}$. Si dice **ciclo** di $S_{n}$ la permutazione $\pi\in S_{n}$ tale che
$$
\pi(k)=
\begin{cases}
\begin{align}
&t_{i+i} &&\text{se }k=t_{i}\text{ e }i=1,\dots,l-1 \\
&t_{1} &&\text{se }k=t_{l} \\
&k &&\text{se } k\not\in \{t_{1},\dots,t_{l}\}
\end{align}
\end{cases}
$$
$l$ è detto *lunghezza* del ciclo. Un ciclo di lunghezza $2$ è detto **trasposizione** o **scambio**.
I cicli possono essere **disgiunti**, $\pi\circ\sigma=\sigma\circ\pi$.
La lunghezza di un singolo ciclo disgiunto è detto **tipo**.
## Parità
Sia $\pi\in S_{n}$. Diremo che la permutazione $\pi$ è:
- **pari** se $\pi$ si scrive come composizione id un numero pari di *scambi*.
- **dispari** se $\pi$ si scrive come composizione di un numeri dispari di *scambi*.
Sia $c$ un ciclo di lunghezza $l$:
- $c$ è pari se $l$ è dispari;
- $c$ è dispari se $l$ è pari.
## Periodo
Si dice **periodo** di $\pi$ denotato $per(\pi)$, il più piccolo intero positivo nell'insieme $\{k\in \mathbb{Z}|\pi^{k}=id\}$.
Sia $\pi\in S_{n}$ una permutazione di tipo $(l_{1},l_{2},\dots,l_{r})$. Allora il periodo della permutazione è il massimo comune multiplo delle lunghezze nel tipo:
$$per(\pi)=mcm(l_{1},l_{2},\dots,l_{r})$$
# Gruppi
Sia $(A,*)$ una coppia formata da un insieme $A$ non vuoto e un'operazione binaria $*$ su $A$. Diremo:
- $(A.*)$ è un **semigruppo** se $*$ è *associativa*;
- $(A,*)$ è un **monoide** se $*$ è *associativa* e *esiste un elemento neutro* $e\in A$ per $*$;
- $(A,*)$ è un **gruppo** se $*$ è *associativa*, *esiste un elemento neutro* $e\in A$ per $*$ e se ogni elemento $a\in A$ è *invertibile*.
Se è soddisfatta la *proprietà commutativa*, parleremo di semigruppi, monoidi o gruppi **abeliani** o **commutativi**.
Sia $(G,*)$ un gruppo. Chiamiamo **ordine** di $(G,*)$ la cardinalità $|G|$.
Quando abbiamo $\mathbb{Q}^\times$ o $\mathbb{R}^\times$, escludiamo lo $0$.
## Sottogruppi
Sia $(G,*)$ un gruppo. Un **sottogruppo** $H$ di $G$ è un sottoinsieme di $G$ tale che $H$ è anch'esso un gruppo per l'operazione $*$. $H<G$.
Per controllare che un sottoinsieme $H\subset G$ sia un sottogruppo occorre verificare:
- $H$ è chiuso rispetto a $*$, cioè per ogni $h,h'\in H$ si ha $h*h'\in H$;
- $H$ contiene l'elemento neutro di $*$;
- $H$ contiene l'inverso di ogni suo elemento, cioè verificare che se $h\in H$, allora $h^{-1}\in H$.

I sottogruppi di $(\mathbb{Z},+)$ sono tutti e soli quelli della forma $n\mathbb{Z}$ per $n\in \mathbb{N}$.
Sia $G$ un gruppo e siano $H_{1}$ e $H_{2}$ sottogruppi di $G$. Allora $H_{1}\cap H_{2}$ è un sottogruppo di $G$.
## Omomorfismi
Vogliamo studiare le funzioni tra gruppi, cioè quelle dove dominio e codominio sono due gruppi.
Siano $(G,*)$ e $(H,*)$ due gruppi. Un **omomorfismo** da $G$ a $H$ è una funzione $\phi:G\to H$ tale che:
$$\phi(g_{1}*g_{2})=\phi(g_{1})*\phi(g_{2})$$
Sia $\phi:(G,*)\to (H,*)$ un omomorfismo di gruppi. Allora valgono:
- $\phi(e_{G})=e_{H}$
- Per ogni $g\in G,\phi(g^{-1})=\phi(g)^{-1}$
- Per ogni $g\in G$ e per ogni $n\in \mathbb{Z},\phi(g^{n})=\phi(g)^{n}$
- Se $G_{1}$ è un sottogruppo di $G$ allora l'immagine $\phi(G_{1})$ è un sottogruppo do $H$
- Se $H_{1}$ è un sottogruppo di $H$, allora la controimmagine $\phi^{-1}(H_{1})$ è un sottogruppo di $G$.
Sia $\phi:G\to H$ un omomorfismo, allora:
- se $\phi$ è *iniettivo* si dice **monomorfismo**
- se $\phi$ è *suriettivo* si dice **epimorfismo**
- se $\phi$ è *biettivo* si dice **isomorfismo**/**automorfismo**
Se $G$ e $H$ sono due gruppi e se esiste un isomorfismo $\phi:G\to H$ i due gruppi $G$ e $H$ si dicono essere **isomorfi** e sis scrive $G\simeq H$.
## Nucleo
Sia $\phi:G\to H$ un omomorfismo di gruppi. Si dice **nucleo** dell'omomorfismo $G$ il sottoinsieme:
$$ker(\phi)=\{g\in G|\phi(g)=e_{H}\}=\phi^{-1}(e_{H})$$
Il nucleo è un sottogruppo di $G$ in quanto controimmagine del sottogruppo banale $\{e_{H}\}<H$.
Sia $\phi:G\to H$ omomorfismo, allora vale l'equivalenza:
$$\phi \text{ è iniettivo (monomorfismo) se e soltanto se }ker(\phi)=\{e_{G}\}$$
## Gruppi e sottogruppi ciclici
Sia $(G,*)$ un gruppo. C'è un modo semplice per costruire sottogruppi di $G$. Fissato un elemento $g\in G$ denotiamo:
$$\braket{g}=\{g^{n}\in G|n\in \mathbb{Z}\}$$
ovvero il sottoinsieme di $G$ composto da tutte le potenze di $g$.
Il sottoinsieme $\braket{g}\subset G$ è un sottogruppo di $G$.

Il sottogruppo $\braket{g}$ di $G$ di dice **sottogruppo ciclico** di $G$ generato da $g$. Un sottogruppo $H<G$ per cui esiste un elemento $g\in G$ tale che $H=\braket{g}$ si dice **generato** da $g$ e l'elemento $g$ si dice **generatore** di $H$.
Si dice **periodo** di $g$ l'ordine $|\braket{g}|$ del sottogruppo ciclico generato da $G$:
- L'elemento neutro è l'unico elemento di un gruppo ad avere periodo $1$
- Tutti i gruppi ciclici infiniti sono isomorfi tra di loro, perché sono tutti isomorfi a $\mathbb{Z}$
- Un gruppo finito non può avere elementi di periodo infinito
- Se $g$ è un elemento di periodo infiniti, ogni potenza $g^k$ di $g$ ha periodo infinito
- Se $G$ è un gruppo di ordine $n$ il periodo di ogni elemento $g\in G$ deve essere un divisore di $n$ come conseguenza del teorema di Lagrange.

Sia $G=\braket{g}$ un gruppo ciclico generato dell'elemento $g$ e sia $H$ un gruppo qualunque. Allora un omomorfismo:
$$\phi:G\to H$$
è completamente determinato dal valore $\phi(g)$.
# Aritmetica modulare
## Classi resto e loro operazioni
Fissiamo un numero intero $N\geq 2$ che sarà detto **modulo**. Definiamo una relazione di **congruenza** in $\mathbb{Z}$ come:
Due interi $m,n\in\mathbb{Z}$ si dicono **congruenti** modulo $N$ e scriviamo:
$$m\equiv n\ mod\ N \quad \text{ se } N|x-y$$
$$17\equiv 5\  mod \ 6 \quad \text{ perché } 6 \text{ divide }12=17-5$$
La relazione di congruenza è una relazione di equivalenza.
Verifichiamo che sia riflessiva, simmetrica e transitiva:
- Si ha $m\equiv m\ mod \ N$ in quanto $N|0=m-m$
- Se $m\equiv n\ mod\ N$ si ha $Nk=m-n$ per un opportuno $k\in \mathbb{Z}$. Allora $n-m\equiv N(-k)$ e quindi $n \equiv m\ mod\ N$
- Se $m\equiv n\ mod\ N$ e $n\equiv p\ mod\ N$ possiamo scrivere $m-n=Nk$ e $n-p=Nl$ per opportuni $k,l\in\mathbb{Z}$. Allora $m-p=(m-n)+(n-p)=N(k+l)$ e quindi $m\equiv p\ mod\ N$
## Classi di congruenza modulo $N$
$$[n]_{N}=\{\dots,n-3N,n-2N,n-N,n,n+N,n+2N,n+3N,\dots\}$$
$$[1]_{3}=\{\dots,-5,-2,1,4,7,\dots\}$$
$$[-3]_{7}=\{\dots,-17,-10,-3,4,11,18,\dots\}$$
Fissiamo $n\geq 2$. Allora:
- per ogni $n\in\mathbb{Z}$, la classe di congruenza di $n$ è $[n]_{N}$
- si ha $[m]_{N}=[n]_{N}$ se e soltanto se $m\equiv n\ mod\ N$
- le $N$ classi $[0]_{N},[1]_{N},\dots,[N-1]_{N}$ sono distinte es esauriscono le classi di equivalenza modulo $N$
L'insieme delle classi resto modulo $N$ è l'insieme quoziente per la relazione di congruenza corrispondente alla scelta del modulo $N$. Lo denotiamo come $\mathbb{Z}_{N}$.

Per parlare di aritmetica modulare dobbiamo introdurre operazioni "naturali" in $\mathbb{Z}_{N}$. Introduciamo quindi addizione e moltiplicazione:
$$+:\mathbb{Z}_{N}\times\mathbb{Z}_{N}\to \mathbb{Z}_{N}\quad\quad\quad\quad\quad \cdot:\mathbb{Z}_{N}\times\mathbb{Z}_{N}\to\mathbb{Z}_{N}$$
Nell'insieme $\mathbb{Z}_{N}$ delle classi resto modulo $N$ definiamo le operazioni:
- di **addizione**: $\overline{a}+\overline{b}=\overline{a+b}$
- di **moltiplicazione**: $\overline{a}\cdot\overline{b}=\overline{a\cdot b}$
Queste due operazioni sono ben definite in $\mathbb{Z}_{N}$.

L'addizione in $\mathbb{Z}_{N}$ è associativa e:
- $0$ è l'elemento neutro
- ogni elemento $\overline{a}\in\mathbb{Z}_{N}$ ammette opposto e di fatto $-\overline{a}=\overline{-a}$
- vale la proprietà commutativa
Quindi $(\mathbb{Z}_{N},+)$ è abeliano e un gruppo ciclico.
Sia $G=\braket{g}$ un gruppo ciclico di ordine $|G|=N$. Allora $G\simeq(\mathbb{Z}_{N},+)$.

La moltiplicazione in $\mathbb{Z}_{N}$ è associativa e:
- $\overline{1}$ è un elemento neutro
- vale la proprietà commutativa
- vale la proprietà distributiva
## Gruppo moltiplicativo
Sia $\overline{0}\neq\overline{a}\in\mathbb{Z}_{N}$ una classe resto modulo $N$ non nulla. Diremo che $\overline{a}$ è un **divisore dello zero** se esiste una classe non nulla $b\in\mathbb{Z}_{N}$ tale che $\overline{a}\cdot\overline{b}=\overline{0}$.
Sia $\overline{0}\neq \overline{a}\in\mathbb{Z}_{N}$ una classe resto non nulla. Allora:
$$
\overline{a}
\begin{cases}
\begin{align}
&\text{è invertibile} &&\text{se }MCD(a,N)=1 \\
&\text{è uno }0{-divisore} &&\text{se }MCD(a,N)>1
\end{align}
\end{cases}
$$







