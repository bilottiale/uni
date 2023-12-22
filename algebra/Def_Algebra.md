# Numeri reali
## Insiemi

**Naturali**:
$$\mathbb{N}=\{0,1,2,3,\dots\}$$
**Interi**:
$$\mathbb{Z}=\{\dots,-2,-1,0,1,2,\dots\}$$
**Razionali**:
$$\mathbb{Q}=\{\dots,-\frac{2}{5},\dots,\frac{1}{8},\dots,\frac{9}{4},\dots\}$$
**Reali**:
$$\mathbb{R}=\{\dots,-5,\dots,-\sqrt{ 2 },\dots,0,1,\dots,\pi,10\}$$
**Complessi**:
$$\mathbb{C}=\{\sqrt{ 7 },23i,-1+\pi i\}$$
## Unione, intersezione e differenza
## Leggi di De Morgan
Siano $A$ e $B$ due sottoinsiemi di un insieme $C$. Valgono le seguenti uguaglianze:
$$
\begin{align}
&(A\cap B)^{C}=A^{C}\cup B^{C} \\
&(A\cup B)^{C}=A^{C}\cap B^{C}
\end{align}
$$
Con $X^{C}$ complementare di $X$ in $C$, cioè $X^{C}=C\setminus X$.
## Prodotto cartesiano
Il prodotto cartesiano di due insiemi $A$ e $B$ è un nuovo insieme $A\times B$ i cui elementi sono tutte le coppie $(a,b)$ dove $a$ è un elemento di $A$ e $b$ un elemento di $B$:
$$A\times B=\{(a,b)|a\in A,b\in B\}$$
#Esempio $A=\{1,2\}, B=\{-1,3,4\}$
$$A\times B=\{(1,-1),(1,3),(1,4),(2,-1),(2,3),(2,4)\}$$
## Relazione di equivalenza
Una relazione di equivalenza su $X$ è una relazione $\sim$ che occorre fra alcune coppie di elementi di $X$ e che soddisfa:
1. **riflessività**: $x\sim x\ \forall x\in X$
2. **simmetria**: se $x\sim y$ allora $y\sim x, \forall x,y\in X$
3. **transitività**: se $x \sim y$ e $y\sim z$, allora $x\sim z, \forall x,y,z\in X$
## Funzioni
Siano $A$ e $B$ due insiemi. Una funzione da $A$ in $B$ è una legge $f$ che trasforma qualsiasi elemento $x$ di $A$ in qualche elemento $y$ di $B$:
$$y=f(x)$$
L'insieme di partenza $A$ è detto dominio, quello di arrivo, $B$, è detto codominio:
$$f:A\longrightarrow B$$
Due funzioni sono considerate uguali se hanno lo stesso dominio e lo stesso codominio:
$$f:\mathbb{N}\longrightarrow \mathbb{N}, f(x)=1, \quad g:\mathbb{N}\longrightarrow \mathbb{N}, g(x)=(x-1)^{2}-x^{2}+2x$$
## Strutture algebriche
## Gruppi
Un *gruppo* è un insieme $G$ dotato di una operazione binaria, cioè di una funzione che associa ad ogni coppia $a,b$ di elementi in $G$ un nuovo elemento di $G$ che indichiamo con $a*b$. Il simbolo $*$ indica l'operazione binaria che deve soddisfare tre assiomi:
1. $\exists e\in G: e*a=a*e=a\forall a\in G$ (esistenza elemento neutro)
2. $a*(b*c)=(a*b)*c\forall a,b,c\in G$ (proprietà associativa)
3. $\forall a\in G, \exists a'\in G: a*a'=a'*a=e$ (esistenza dell'inverso)
#Esempio $(\mathbb{Z}, +)$ è un gruppo:
1. esiste l'elemento neutro $0$, per cui $0+a=a+0=a \ \forall a\in \mathbb{Z}$
2. vale la proprietà associativa $a+(b+c)=(a+b)+c \ \forall a,b,c\in \mathbb{Z}$
3. ogni numero intero $a\in \mathbb{Z}$ ha un inverso $a'=-a$, per cui $a+(-a)=(-a)+a=0$

Mentre invece
- $(\mathbb{Z}, \cdot)$ non soddisfa 3.
- $(\mathbb{N},+)$ non soddisfa 3.
Il gruppo $G$ è commutativo se vale anche la proprietà commutativa:
$$a*b=b*a \ \forall a,b \in G$$
I numeri interi $\mathbb{Z}$ formano un gruppo commutativo. Anche $\mathbb{Q,R}$ e $\mathbb{C}$ con la somma. Un altro esempio di gruppo è l'insieme
$$S_{n}$$
formato da tutte le $n!$ permutazioni dell'insieme $X=\{1,\dots,n\}$, con l'operazione di composizione $\circ$.
## Anelli
Negli insiemi numerici $\mathbb{Z,Q,R}$ e $\mathbb{C}$ ci sono in realtà due operazioni $+$ e $\times$. Introduciamo una struttura che prevede la coesistenza di due operazioni binarie.
Un *anello* è un insieme $A$ dotato di due operazioni binarie $+$ e $\times$ che soddisfano:
1. $A$ è un gruppo commutativo con l'operazione $+$
2. $a\times(b\times c)=(a\times b)\times c \ \forall a,b,c\in A$ (associatività)
3. $a\times(b+c)=(a\times b)+(a\times c)\ \forall a,b,c \in A$ (distributività)
4. $\exists 1\in A: 1\times a=a\times 1=a \ \forall a\in A$ (elemento neutro)
## Campi
Un *campo* è un anello commutativo $K$ in cui vale anche il seguente assioma:
$$\forall a\in K, a\neq 0 \Longrightarrow\exists a'\in K:a\times a'=a'\times a=1$$
(esiste inverso per il prodotto)
Chiediamo quindi che ogni elemento $a$ diverso da $0$ abbia anche un inverso rispetto al prodotto. Esempi di campi sono $\mathbb{Q,R,C}$.
## Numeri complessi
Un numero complesso è un oggetto algebrico che si scrive nel modo:
$$a+bi$$
dove $a$ e $b$ sono numeri reali arbitrari e $i$ è un simbolo chiamato unità immaginaria. Ad esempio:
$$\sqrt{ 7 },\quad_{2}+i,\quad 23i,\quad 4-i, \quad -1+\pi i$$
I numeri complessi si sommano e si moltiplicano nel modo usuale, tenendo a mente un'unica relazione:
$$i^{2}=-1$$
La somma e la moltiplicazione di $a+bi$ e $c+di$ si svolge nel modo:
$$\begin{align}
(a+bi)+(c+di)&=a+c+(b+d)i \\
(a+bi)\cdot(c+di)&=ac+bci+adi+bdi^{2}=ac-bd+(ad+bc)i
\end{align}$$
Nel prodotto abbiamo usa che $i^{2}=-1$:
$$(7+i)\cdot(4-i)=29-3i$$
La sequenze di insiemi numerici è quindi:
$$\mathbb{N}\subset \mathbb{Z}\subset \mathbb{Q}\subset \mathbb{R}\subset \mathbb{C}$$
## Coniugio, norma e inverso
Sia $z=a+bi$ un numero complesso. I numeri $a$ e $b$ sono detti rispettivamente la parte reale e la parte immaginaria di $z$. Il numero $z$ è reale, quindi $z\in \mathbb{R}\subset \mathbb{C}$, se e solo se la sua parte immaginaria è nulla.
Il **coniugio** di $z=a+bi$ è il numero complesso:
$$\overline{z}=a-bi$$
ottenuto da $z$ cambiando il segno della sua parte immaginaria. Notiamo che $z=\overline{z}$ precisamente quando $b=0$, cioè quando $z$ è reale. Quindi:
$$z\in \mathbb{R}\iff z=\overline{z}$$
Il modulo di $z=a+bi$ è il numero reale:
$$|z|=\sqrt{ a^{2}+b^{2} }$$
Il modulo $|z|$ è nullo quando $z=0$, cioè quando $a=b=0$, ed è strettamente positivo se $z\neq 0$. Notiamo anche che:
$$z\cdot\overline{z}=(a+bi)\cdot(a-bi)=a^{2}+b^{2}=|z|^{2}$$
## Il piano complesso
Mentre i numeri reali $\mathbb{R}$ formano una retta, i numeri complessi $\mathbb{C}$ formano un piano detto *piano complesso*. Ogni numero complesso $a+bi$ può essere identificato con il punto di coordinate $(a,b)$ nel piano cartesiano o equivalentemente come un vettore applicato nell'origine $0$ e diretto verso $(a,b)$, come illustrato:
![[Pasted image 20231213184224.png|350]]

![[Pasted image 20231213184538.png|350]]
## Coordinate polari
Un punto $(x,y)$ diverso dall'origine del piano cartesiano può essere identificato usando la lunghezza $r$ del vettore corrispondente e l'angolo $\theta$ formato dal vettore con l'asse reale. Le *coordinate polari* del punto sono la coppia $(r,\theta)$. Per passare dalle coordinate polari $(r,\theta)$ a quelle cartesiane $(x,y)$ basta usare le formule:
$$x=r\cos \theta, \quad y=rsen\theta$$
Viceversa:
$$r=\sqrt{ x^{2}+y^{2} }, \quad \theta=arcos \frac{x}{\sqrt{ x^{2}+y^{2} }}$$
Un numero complesso $z=x+yi$ può essere scritto in coordinate polari come:
$$z=x+yi=r\cos \theta+(rsen\theta)i=r(\cos \theta+isen\theta)$$
Notiamo che:
$$|z|=\sqrt{ x^{2}+y^{2} }=r$$
Il modulo di $z$ è quindi la lunghezza del vettore che descrive $z$. Il coniugio $\overline{z}=a-ib$ è il punto ottenuto cambiando il segno della coordinata immaginaria: geometricamente questo corrisponde a riflettere il punto rispetto all'asse reale. In coordinate polari, questo corrisponde a cambiare $\theta$ in $-\theta$ lasciando fisso $r$.
In coordinate polari è quindi comodo scrivere:
$$e^{i\theta}=\cos \theta+isen\theta$$
In questo modo ogni numero complesso $z\neq 0$ si scrive come:
$$z=re^{i\theta}$$
Il numero $r=|z|$ è il modulo di $z$, mentre l'angolo $\theta$ è detto argomento di $z$.

## Proprietà dei numeri complessi
I numeri complessi hanno numerose proprietà. Queste si dimostrano facilmente: in presenza di un prodotto, è spesso utile usare la rappresentazione polare. Lasciamo la dimostrazione di queste proprietà per esercizio:
#Esempio Valgono i fatti seguenti per ogni $z,w\in \mathbb{C}$
$$|z+w|\leq|z|+|w|, \quad |zw|=|z||w|, \quad |z|^{-1}=\frac{1}{|z|}$$
$$|z|=|\overline{z}|, \quad \overline{z+w}=\overline{z}+\overline{w}, \quad \overline{zw}=\overline{z}\ \overline{w}$$
Il numero costante $e$ di *Nepero* è dovuto alle rappresentazioni delle funzioni $e^{x},\sin x, \cos x$ come serie di potenze. Questo numero $e^{i\theta}$ vuole dire semplicemente $\cos \theta+i\sin \theta$.
Vale la relazione:
$$e^{i(\theta+\varphi)}=e^{i\theta}\cdot e^{i\varphi}$$
Adesso capiamo perché le coordinate polari sono particolarmente utili quando moltiplichiamo due numeri complessi. Se:
$$z_{1}=r_{1}e^{i\theta_{1}}, \quad z_{2}=r_{2}e^{i\theta_{2}}$$
Ovvero:
$$z_{1}z_{2}=r_{1}r_{2}e^{i(\theta_{1}+\theta_{2})}$$
Quindi possiamo concludere che: quando si fa il prodotto di due numeri complessi, i moduli si moltiplicano e gli argomenti si sommano.
Se $z=re^{i\theta}\neq 0$, il suo inverso è $z^{-1}=r^{-1}e^{-i\theta}$.
L'inverso $z^{-1}$ ha argomento $-\theta$ opposto a quello $\theta$ di $z$ e ha modulo $|z^{-1}|=r^{-1}$ inverso rispetto a $|z|=r$.
Per $\theta=\pi$ otteniamo l'identità di Eulero:
$$e^{i\pi}=-1$$
## Radici $n$-esime di un numero complesso
Sia $z_{0}=r_{0}e^{i\theta_{0}}$ un numero complesso fissato diverso da zero. Risolviamo l'equazione:
$$z^{n}=z_{0}$$
determiniamo tutte le radici $n$-esime di $z_{0}$. Scriviamo la variabile $z$ in forma polare come $z=re^{i\theta}$:
$$r^{n}e^{in\theta}=r_{0}e^{i\theta_{0}}$$
L'equazione è soddisfatta se valgono questi fatti:
- $r=\sqrt[n]{ r_{0} }$
- $n\theta=\theta_{0}+2k\pi$ per qualche $k\in \mathbb{Z}$
La seconda può essere scritta richiedendo che:
$$\theta=\frac{\theta_{0}}{n}+\frac{2k\pi}{n}$$
Otteniamo quindi $n$ soluzioni diverse: per valor i$k=0,1,\dots,n-1$:
$$\theta=\frac{\theta_{0}}{n},\frac{\theta_{0}}{n}+\frac{2\pi}{n},\dots,\frac{\theta_{0}}{n}+\frac{2(n-1)\pi}{n}$$
#Esempio L'equazione $z^{n}=1$ ha come soluzioni:
$$z=e^{i\frac{2k\pi}{n}}$$
dove $k=0,1,\dots,n-1$. Queste $n$ soluzioni sono i vertici di un poligono regolare di raggio $1$ con $n$ lati, avente $1$ come vertice. Questi numeri complessi sono le radici $n$-esime dell'unità.
![[Pasted image 20231213204126.png|350]]
# Polinomi
Un monomio è una espressione algebrica che ha una espressione algebrica che ha una parte numerica (il coefficiente) e duna parte letterale:
$$4x, \quad -2xy, \quad \sqrt{ 5 }x^{3}$$
Ci interessano particolarmente i polinomi in cui compare una sola variabile $x$, indicato con $p(x)$, oppure con $p$. $p(x)$ con una sola variabile può essere descritto ordinando i suoi monomi da quello di grado più alto a quello di grado più basso:
$$p(x)=a_{n}x^{n}+\ldots+a_{1}x+a_{0}$$
dove $n$ è il grado di $p(x)$ e $a_{n}\neq 0$:
$$x^{3}-2x+5,\quad 4x^{2}-7$$
## Divisione con resto fra polinomi
Dati due polinomi $p(x)$ (dividendo) e $d(x)$ (divisore), esistono due polinomi $q(x)$ (quoziente) e $r(x)$ (resto):
$$p(x)=q(x)d(x)+r(x)$$
il resto $r(x)$ ha sempre grado minore del divisore $d(x)$.
#Esempio 
$$
\begin{align}
&p(x)=x^{3}+1 \\
&d(x)=x^{2}-1
\end{align}$$
$$x^{3}+1=x(x^{2}-1)+(x+1)$$
## Radici di un polinomio
Se $p(x)$ è un polinomio e $a$ un numero, indichiamo con $p(a)$ il numero che otteniamo sostituendo $a$ al posto di $x$.
#Esempio 
$p(x)=x^{2}-3$, allora $p(-2)=4-3=1$
#Definizione 
Un numero $a$ è radice di un polinomio $p(x)$ se:
$$p(a)=0$$
## Teorema fondamentale dell'algebra
Ogni polinomio a coefficienti complessi ha almeno una radice complessa.
#Corollario 
Un polinomio $p(x)$ a coefficienti complessi di grado $n$ ha esattamente $n$ radici, contate con molteplicità.
#Dimostrazione 
Per induzione su $n$. Possiamo supporre $p(x)$ abbia $n=1$, allora $p(x)=x-a_{0}$ ha una sola radice $x=a_{0}$.
## Polinomi a coefficienti reali
Sappiamo che un polinomio $p(x)$ di grado $n$ ha esattamente $n$ soluzioni complesse contate con molteplicità. Se $p(x)$ ha coefficienti reali, possiamo dire qualcosa di più sulle sue radici complesse.
Sia $p(x)$ un polinomio a coefficienti reali, Se $z$ è una radice complessa di $p(x)$, allora $\overline{z}$ è anch'essa radice di $p(x)$.
#Dimostrazione Il polinomio è:
$$p(x)=a_{n}n^{n}+\ldots+a_{1}x+a_{0}$$
per ipotesi i coefficienti $a_{n},\dots,a_{0}$ sono tutti reali. Se $z$ è radice, allora:
$$p(z)=a_{n}z^{n}+\ldots+a_{1}z+a_{0}=0$$
Applicando il coniugio ad entrambi i membri troviamo:
$$\overline{a_{n}}\overline{z}^{n}+\ldots+\overline{a_{1}}\overline{z}+\overline{a_{0}}=\overline{0}=0$$
Siccome i coefficienti sono reali, il coniugio di $a_{i}$ è sempre $a_{i}$ e quindi:
$$a_{n}\overline{z}^{n}+\ldots+a_{1}\overline{z}+a_{0}=0$$
In altre parole, anche $\overline{z}$ è radice di $p(x)$.
# Spazi vettoriali
## Lo spazio euclideo
Partendo da $\mathbb{R}$ e usando l'operazione di prodotto cartesiano fra insiemi, definiamo subito la nozione di spazio euclideo in dimensione arbitraria. Sia $n\geq 1$ un numero naturale.
Lo spazio euclideo $n$-dimensionale è l'insieme $\mathbb{R}^{n}$.
Ricordiamo che $\mathbb{R}^{n}$ è il prodotto cartesiano $\mathbb{R}\times\dots \times \mathbb{R}$ di $n$ copie di $\mathbb{R}$. Un elemento dell'insieme $\mathbb{R}^{2}$ è il piano cartesiano, in cui ogni punto è determinato da una coppia $(x,y)$. Analogamente in $\mathbb{R}^{3}$ è una terna $(x,y,z)$.
![[Pasted image 20231213215133.png|350]]
## Spazi vettoriali
Nella sezione precedente abbiamo iniziato a studiare lo spazio euclideo $\mathbb{R}^{n}$, che generalizza il piano cartesiano $\mathbb{R}^{2}$ in ogni dimensione.
#Definizione 
Fissiamo un campo $\mathbb{K}$. Questo è generalmente il campo $\mathbb{K=\mathbb{R}}$ dei numeri reali, ma può anche essere il campo dei complessi o quello dei razionali.
Gli elementi del campo sono detti *scalari*.
Uno spazio vettoriale su $\mathbb{K}$ è un insieme $V$ di elementi, detti vettori, dotato di due operazioni binarie:
- *somma* che associa a due vettori $v,w \in V$, un terzo vettore $v+w\in V$
- *prodotto per scalare* che associa ad un vettore $v\in V$ e ad uno scalare $\lambda\in \mathbb{K}$ un vettore $\lambda v\in V$
Queste due operazioni devono soddisfare gli assiomi per lo spazio euclideo:
1. L'insieme $V$ è un gruppo commutativo con la somma $+$
2. $\lambda(v+w)=\lambda v+\lambda w$
3. $(\lambda+\mu)=\lambda v+\lambda \mu$
4. $(\lambda \mu)v=\lambda(\mu v)$
5. $1v=v$
## Lo spazio $\mathbb{K}^{n}$
L’esempio principale di spazio vettoriale su $\mathbb{R}$ è ovviamente lo spazio euclideo $\mathbb{R}^{n}$ già incontrato precedentemente. Più in generale, è possibile definire per qualsiasi campo $\mathbb{K}$ uno spazio $\mathbb{K}^{n}$.
Sia $n\geq 1$ un numero naturale. Lo spazio $\mathbb{K}^{n}$ è l'insieme delle sequenze $(x_{1},\dots,x_{n})$ di numeri in $\mathbb{K}$. Gli elementi $v\in \mathbb{K}^{n}$ sono descritti come vettori colonna:
$$v=
\begin{pmatrix}
x_{1} \\
\vdots \\
x_{n}
\end{pmatrix}
\in \mathbb{K}^{n}
$$
La somma e la moltiplicazione per scalare sono definiti termine a termine:
$$
\begin{pmatrix}
x_{1} \\
\vdots \\
x_{n}
\end{pmatrix}
+
\begin{pmatrix}
y_{1} \\
\vdots \\
y_{n}
\end{pmatrix}
=
\begin{pmatrix}
x_{1} + y_{1}\\
\vdots \\
x_{n} + y_{n}
\end{pmatrix},
\quad \quad
\lambda
\begin{pmatrix}
x_{1} \\
\vdots \\
x_{n}
\end{pmatrix}
=
\begin{pmatrix}
\lambda x_{1} \\
\vdots \\
\lambda x_{n}
\end{pmatrix}
$$
#Esempio con vettori di $\mathbb{C}^{2}$
$$
\begin{pmatrix}
1+i \\
-2
\end{pmatrix}
+
\begin{pmatrix}
3i \\
1-i
\end{pmatrix}
=
\begin{pmatrix}
1+4i \\
-1-i
\end{pmatrix},
\quad \quad
\begin{pmatrix}
2+1
\end{pmatrix}
\begin{pmatrix}
3 \\
1-i
\end{pmatrix}
=
\begin{pmatrix}
6+3i \\
3-i
\end{pmatrix}
$$
## Lo spazio $\mathbb{K}[x]$ dei polinomi
Indichiamo con $\mathbb{K}[x]$ l'insieme di tutti i polinomi con coefficienti in un certo campo $\mathbb{K}$. Due polinomi possono essere sommati, e moltiplicando un polinomio per uno scalare otteniamo un polinomio:
$$(x^{3}-2x+1)+(4x^{4}+x-3)=4x^{4}+x^{3}-x-2, \quad\quad 3(x^{3}-2x)=3x^{3}-6x$$
$\mathbb{K}[x]$ è uno spazio vettoriale su $\mathbb{K}$.
# Matrici
## Le matrici
Introduciamo un terzo oggetto matematico importante che rientra negli spazi vettoriali: le *matrici*.
Sia sempre $\mathbb{K}$ un campo fissato. Una matrice con $m$ righe e $n$ colonne a coefficienti in $\mathbb{K}$ è tipo:
$$
A=
\begin{pmatrix}
a_{11} & \cdots & a_{1n} \\
\vdots & \ddots & \vdots \\
a_{m1} & \cdots & a_{mn}
\end{pmatrix}
$$
in cui tutti gli $mn$ numeri $a_{11},\dots,a_{mn}$ sono elementi del campo $\mathbb{K}$. Diciamo che $A$ è una matrice $m\times n$.
Righe:
$$
A_{i}=
\begin{pmatrix}
a_{i1} & \cdots & a_{in}
\end{pmatrix}
$$
Colonne:
$$
A^{j}=
\begin{pmatrix}
a_{1j} \\
\vdots \\
a_{mj}
\end{pmatrix}
$$
Due matrici $A$ e $B$ possono essere sommate creando:
$$
C=
\begin{pmatrix}
a_{11}+b_{11} & \cdots & a_{1n}+b_{1n} \\
\vdots & \ddots & \vdots \\
a_{m1}+b_{m1} & \cdots & a_{mn}+b_{mn}
\end{pmatrix}
$$
Analogamente è possibile moltiplicare $A$ per uno scalare $\lambda\in \mathbb{K}$:
$$
\lambda A=
\begin{pmatrix}
\lambda a_{11} & \cdots & \lambda a_{1n} \\
\vdots & \ddots & \vdots \\
\lambda a_{m1} & \cdots & \lambda a_{mn}
\end{pmatrix}
$$
## Sottospazio vettoriale
Definiamo adesso in che senso uno spazio vettoriale può contenerne un altro.
Sia $V$ uno spazio vettoriale su un campo $\mathbb{K}$. Un *sottospazio vettoriale* di $V$ è un sottoinsieme $W\subset V$ che soddisfa tre assiomi:
1. $0\in W$
2. se $v,v'\in W$, allora anche $v+v'\in W$
3. se $v\in W$ e $\lambda\in\mathbb{K}$, allora $\lambda v\in W$
Ovvero:
1. $W$ deve contenere l'origine
2. $W$ deve essere chiuso rispetto alla somma
3. $W$ deve essere chiuso rispetto al prodotto per scalare
## Sottospazio banale e totale
- Il sottospazio *banale* $W=\{0\}$, formato da solo punto, l'origine
- Il sottospazio *totale* $W=V$, formato da tutti i vettori di $V$
$$\{0\}\subset W\subset V$$
## Combinazioni lineari
Sia $V$ uno spazio vettoriale qualsiasi e siano $v_{1},\dots,v_{k}\in V$ vettori arbitrari. Una *combinazione lineare* dei vettori è un qualsiasi vettore $v$ che si ottiene come:
$$v=\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}$$
dove $\lambda_{1},\dots,\lambda_{k}$ sono scalari arbitrari.
#Esempio se $V=\mathbb{R}^{3}$ e
$$
v_{1}=
\begin{pmatrix}
1 \\
0 \\
0
\end{pmatrix},
\quad\quad
v_{2}=
\begin{pmatrix}
0 \\
1 \\
0
\end{pmatrix}
$$
allora una combinazione lineare arbitraria di questi due vettori è:
$$
\lambda_{1}v_{1}+\lambda_{2}v_{2}=
\lambda_{1}
\begin{pmatrix}
1 \\
0 \\
0
\end{pmatrix}
+\lambda_{2}
\begin{pmatrix}
0 \\
1 \\
0
\end{pmatrix}
=
\begin{pmatrix}
\lambda_{1} \\
0 \\
0
\end{pmatrix}
+
\begin{pmatrix}
0 \\
\lambda_{2} \\
0
\end{pmatrix}
=
\begin{pmatrix}
\lambda_{1} \\
\lambda_{2} \\
0
\end{pmatrix}
$$
Questo vettore sta nel piano orizzontale $z=0$. Al variare di $\lambda_{1}$ e $\lambda_{2}$, facendo le combinazioni lineari di $v_{1}$ e $v_{2}$ otteniamo tutti i punti del piano orizzontale $z=0$.
## Sottospazio generato
Sia $V$ uno spazio vettoriale e siano $v_{1},\dots,v_{k}\in V$ vettori arbitrari. Il *sottospazio generato* dai vettori è il sottoinsieme di $V$ formato da tutte le combinazioni lineari dei vettori.
$$Span(v_{1},\dots,v_{k})$$
$$Span(v_{1},\dots,v_{k})=\{\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}|\lambda_{1},\dots,\lambda_{k}\in\mathbb{K}\}$$
Il sottoinsieme $Span(v_{1},\dots,v_{k})$ è un sottospazio vettoriale di $V$. Dimostriamo che $W=Span(v_{1},\dots,v_{k})$ soddisfa i 3 assiomi di sottospazio:
1. $0\in W$, infatti usando $\lambda_{1}=\dots=\lambda_{k}=0$ troviamo$$0v_{1}+\ldots+0v_{k}=0+\ldots+0=0\in W$$
2. Se $v,w\in W$, allora $v+w\in W$. Infatti per ipotesi:
$$\begin{align}v&=\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k} \\w&=\mu_{1}v_{1}+\ldots+\mu_{k}v_{k}\end{align}$$
Quindi:$$v+w=(\lambda_{1}+\mu_{1})v_{1}+\ldots+(\lambda_{k}\mu_{k})v_{k}$$
3. Se $v\in W$ e $\lambda\in \mathbb{K}$, allora $\lambda v\in W$:
$$v=\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}$$
allora:
$$\lambda v=(\lambda \lambda_{1})v_{1}+\ldots+(\lambda \lambda_{k})v_{k}$$
#Esempio se $v$ è un singolo vettore di $V$:
$$W=Span(v)=\{\lambda v|\lambda\in\mathbb{K}\}$$
#Esempio se $V=\mathbb{R}^{2}$ e $v=\dbinom{1}{2}$:
$$W=Span(v)=\{t\dbinom{1}{2}|t\in \mathbb{R}\}=\{\dbinom{t}{2t}|t\in\mathbb{R}\}$$
## Matrici diagonali, triangolari, simmetriche e antisimmetriche
Possiamo definire dei sottospazi di $M(m,n,\mathbb{K})$ imponendo restrizioni. Data una matrice $A$, indichiamo con $A_{ij}$ o $a_{ij}$ i coefficienti.
Una matrice $n\times n$ è detta quadrata.
Una matrice $A$ quadrata è:
- diagonale se $a_{ij}=0 \ \forall i\neq j$
- triangolare superiore se $a_{ij}=0 \ \forall i>j$
- triangolare inferiore se $a_{ij}=0 \ \forall i <j$
- triangolare se è triangolare inferiore o superiore;
- simmatrica se $a_{ij}=a_{ji} \ \forall i,j$
- antisimmetrica se $a_{ij}=-a_{ji} \ \forall i,j$
## Dimensione
## (In)dipendenza lineare
Sia $V$ uno spazio vettoriale su $\mathbb{K}$ e siano $v_{1},..,v_{k}\in V$ dei vettori. Diciamo che questi vettori sono *linearmente dipendenti*  se esistono coefficienti $\lambda_{1},\dots,\lambda_{k}\in\mathbb{K}$, non tutti nulli tali che:
$$\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}=0$$
se i vettori sono linearmente dipendenti, allora è possibile esprimere uno di loro in funzione degli altri. Per ipotesi esiste almeno un $\lambda_{i}\neq 0$ e dopo aver diviso tutto per $\lambda_{i}$ e spostato gli addendi otteniamo:
$$v_{i}=-\frac{\lambda_{1}}{\lambda_{i}}v_{1}-\ldots-\frac{\lambda_{k}}{\lambda_{i}}v_{k}$$
dove tra i vettori di destra ovviamente non compare $v_{i}$, quindi i vettori sono dipendenti se e solo se uno di loro è esprimibile come combinazione lineare degli altri.
#Esempio i vettori $\dbinom{1}{2},\dbinom{1}{1}$ e $\dbinom{2}{0}$ in $\mathbb{R}^{2}$ sono dipendenti perché:
$$-2\dbinom{1}{2}+4\dbinom{1}{1}-\dbinom{2}{2}=\dbinom{0}{0}$$
In questo caso ogni vettore è esprimibile come combinazione lineare degli altri due:
$$\dbinom{1}{2}=2\dbinom{1}{1}-\frac{1}{2}\dbinom{2}{0}, \quad \dbinom{1}{1}=\frac{1}{4}\dbinom{2}{0}+\frac{1}{2}\dbinom{1}{2},\quad \dbinom{2}{0}=-2\dbinom{1}{2}+4\dbinom{1}{1}$$
I vettori sono *linearmente indipendenti* se sono sono dipendenti, ovvero:
$$\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}=0\Longrightarrow \lambda_{1}=\ldots=\lambda_{k}=0$$
Quindi l'unica combinazione lineare che può dare il vettore nullo è quella banale in cui tutti i coefficienti sono nulli.
I casi $k=1$ e $k=2$ sono:
- un vettore $v_{1}$ è dipendente $\iff v_{1}=0$
- due vettori $v_{1},v_{2}$ sono dipendenti $\iff$ sono multipli, cioè se esiste un $k\in\mathbb{K}$ tale che $v_{1}=kv_{2}$ oppure $v_{2}=kv_{1}$

I vettori $v_{1}=\dbinom{1}{1}, v_{2}=\dbinom{-2}{-2}$ di $\mathbb{R}^{2}$ sono dipendenti; $w_{1}=\dbinom{1}{2}, w_{2}=\dbinom{2}{1}$ sono indipendenti perché non sono multipli.
In caso con tre o più vettori è più complesso:
$$
v_{1}=
\begin{pmatrix}
1 \\
1 \\
0
\end{pmatrix},
\quad\quad
v_{2}=
\begin{pmatrix}
0 \\
1 \\
1
\end{pmatrix},
\quad\quad
v_{3}=
\begin{pmatrix}
1 \\
0 \\
-1
\end{pmatrix}
$$
in $\mathbb{R}^{3}$ sono dipendenti perché $v_{1}-v_{2}-v_{3}=0$. A coppie i vettori sono indipendenti, ma tutti e tre non lo sono. Non è certamente un fatto che si vede immediatamente come nel caso k = 2. D’altra parte, i vettori:
$$
e_{1}=
\begin{pmatrix}
1 \\
0 \\
0
\end{pmatrix},
\quad\quad
e_{2}=
\begin{pmatrix}
0 \\
1 \\
0
\end{pmatrix},
\quad\quad
e_{3}=
\begin{pmatrix}
0 \\
0 \\
1
\end{pmatrix}
$$
sono indipendenti: se una combinazione lineare produce il vettore nullo:
$$\lambda_{1}e_{1}+\lambda_{2}e_{2}+\lambda_{3}e_{3}=0$$
riscriviamo i membri come vettori:
$$
\begin{pmatrix}
\lambda_{1} \\
\lambda_{2} \\
\lambda_{3}
\end{pmatrix}
=\lambda_{1}
\begin{pmatrix}
1 \\
0 \\
0 \\
\end{pmatrix}
+\lambda_{2}
\begin{pmatrix}
0 \\
1 \\
0 \\
\end{pmatrix}
+\lambda_{3}
\begin{pmatrix}
0 \\
0 \\
1
\end{pmatrix}
=
\begin{pmatrix}
0 \\
0 \\
0
\end{pmatrix}
$$
Deduciamo quindi che $\lambda_{1}=\lambda_{2}=\lambda_{3}=0$. L'unica combinazione di $e_{1},e_{2},e_{3}$ che dà il vettore nullo è quella banale.
Se $v_{1},\dots,v_{k}$ sono indipendenti, allora qualsiasi sottoinsieme di ${v_{1},\dots,v_{k}}$ è anch'esso formato da vettori indipendenti.
## Basi
Sia $V$ uno spazio vettoriale. Una sequenza $v_{1},\dots,v_{n}\in V$ di vettori è una *base* se:
- i vettori $v_{1},\dots,v_{n}$ sono indipendenti
- i vettori $v_{1},\dots,v_{n}$ generano $V$
	- quindi $V=Span(v_{1},\dots,v_{n})$, qualsiasi vettore di $V$ è esprimibile come combinazione lineare dei vettori
#proposizione Gli elementi
$$
e_{1}=
\begin{pmatrix}
1 \\
0 \\
\vdots \\
0
\end{pmatrix},
\quad\quad
e_{2}=
\begin{pmatrix}
0 \\
1 \\
\vdots \\
0
\end{pmatrix},
\quad\quad
\dots
\quad\quad
e_{n}=
\begin{pmatrix}
0 \\
0 \\
\vdots \\
1
\end{pmatrix}
$$
formano una base in $\mathbb{K}^{n}$ detta *base canonica*.
#Dimostrazione 
Mostriamo che i vettori sono indipendenti. Supponiamo di avere una combinazione lineare nulla:
$$\lambda_{1}e_{1}+\ldots+\lambda_{n}e_{n}=0$$
tradotta in vettori
$$
\begin{pmatrix}
\lambda_{1} \\
\lambda_{2} \\
\vdots \\
\lambda_{n}
\end{pmatrix}
=
\begin{pmatrix}
0 \\
0 \\
\vdots \\
0
\end{pmatrix}
$$
ne deduciamo che $\lambda_{1}=\ldots=\lambda_{n}=0$ quindi $e_{1},\dots,e_{n}$ sono indipendenti.
Mostriamo che i vettori generano $\mathbb{K}^{n}$. Un generico vettore $x\in \mathbb{K}^{n}$ si può scrivere come combinazione lineare:
$$
x=
\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix}
=x_{1}
\begin{pmatrix}
1 \\
0 \\
\vdots \\
0
\end{pmatrix}
+x_{2}
\begin{pmatrix}
0 \\
1 \\
\vdots \\
0
\end{pmatrix}
+\ldots+x_{n}
\begin{pmatrix}
0 \\
0 \\
\vdots \\
1
\end{pmatrix}
=x_{1}e_{1}+x_{2}e_{2}+\ldots+x_{n}e_{n}
$$
Dimostrazione conclusa.
## Coordinate di un vettore rispetto ad una base
Le basi servono per dare un nome a tutti i vettori dello spazio.
#proposizione 
Sia $V$ uno spazio vettoriale e sia $v_{1},\dots,v_{n}$ una base di $V$. Ogni vettore $x\in V$ si scrive:
$$v=\lambda_{1}v_{1}+\ldots+\lambda_{n}v_{n}$$
#Dimostrazione 
Sappiamo che i vettori generano, quindi $v$ si può scrivere come combinazione lineare dei vettori. Supponiamo che lo si possa fare in due modi diversi:
$$v=\lambda_{1}v_{1}+\ldots+\lambda_{n}v_{n}=\mu_{1}v_{1}+\ldots+\mu_{n}v_{n}$$
Spostando tutto a sinistra:
$$(\lambda_{1}-\mu_{1})v_{1}+\ldots+(\lambda_{n}-\mu_{n})v_{n}=0$$
Siccome sono indipendenti: $\mu_{i}=\lambda_{i} \ \forall i$.
I coefficienti $\lambda_{1},\dots,\lambda_{n}$ sono coordinate di $v$ rispetto alla base.
## Dimensione
#Teorema 
Due basi dello stesso spazio vettoriale $V$ contengono lo stesso numero $n$ di elementi.

#Definizione 
Se uno spazio vettoriale $V$ ha base $v_{1},\dots,v_{n}$, diciamo che $V$ ha dimensione $n$. Se $V$ non ha una base allora diciamo che ha dimensione $\infty$.

Supponiamo di avere:
- dei vettori $v_{1},\dots,v_{n}\in V$ che generano $V$
- dei vettori $w_{1},\dots,w_{n}\in V$ indipendenti
allora anche i vettori $w_{1},\dots,w_{n}$ generano $V$.
Sappiamo che $V=Span(v_{1},\dots,v_{n})$, vogliamo dimostrare che $V=Span(w_{1},\dots,w_{n})$. Otteniamo ciò posizionando ciascun $w_{i}$ al posto di un $v_{j}$, iterativamente per $i=1,\dots,_{n}$.
$$w_{1}=\lambda_{1}v_{1}+\ldots+\lambda_{n}v_{n}$$
Poiché $w_{1}\neq 0$, almeno un $\lambda_{i}$ è non nullo: a meno di riordinare i vettori $v_{1},\dots,v_{n}$, supponiamo che $\lambda_{1}\neq 0$. Allora dividendo per $\lambda_{1}$:
$$v_{1}=\frac{1}{\lambda_{1}}w_{1}-\frac{\lambda_{2}}{\lambda_{1}}v_{2}-\dots-\frac{\lambda_{n}}{\lambda_{1}}v_{n}$$
quindi $v_{1}$ è combinazione lineare dei $w_{1},v_{2},\dots,v_{n}$. Questo implica che i vettori generino $V$, cioè possiamo sostituire $v_{1}$ con $w_{1}$ e:
$$V=Span(w_{1},v_{2},\dots,v_{n})$$
Iteriamo il processo $n$ volte. Al passo numero $s$, supponiamo di aver già dimostrato che $V=Span(w_{1},\dots,w_{s-1},v_{s},\dots,v_{n})$. Allora:
$$w_{s}=\lambda_{1}w_{1}+\ldots+\lambda_{s-1}w_{s-1}+\lambda_{s}v_{s}+\ldots+\lambda_{n}v_{n}$$
Esiste almeno un $i\geq s$ con $\lambda_{i}\neq 0$. Se così non fosse, questa sarebbe una relazione di dipendenza fra i soli $w_{1},\dots,w_{s}$, ma questo è escluso perché sono indipendenti.

Ora dimostriamo il teorema.
Supponiamo per assurdo che uno spazio vettoriale $V$ contenga due basi:
$$v_{1},\dots,v_{n}, \quad\quad w_{1},\dots,w_{m}$$
con $n\neq m$. Sia ad esempio $n<m$.
Per ipotesi i vettori $v_{i}$ generano $V$ e i vettori $w_{j}$ sono indipendenti. Deduciamo che $w_{j}$ generano $V$. Quindi $w_{n+1}$ può essere espresso come combinazione lineare dei $w_{1},\dots,w_{n}$, e allora i vettori $w_{1},\dots,w_{m}$ non sono indipendenti: assurdo.

Indichiamo la dimensione di uno spazio $V$ come $dim \ V$.
Possiamo calcolare la dimensione di tutti gli spazi vettoriali dei quali abbiamo esibito una base:
$$
\begin{align}
dim \ \mathbb{K}^{n}&=n \\
dim \ \mathbb{K}_{n}[x]&=n+1 \\
dim \ M(m,n,\mathbb{K})&=mn
\end{align}
$$
ricordiamo che $dim \ V=\infty$ se $V$ non ha una base.
## Trasposta di una matrice
La trasposta di una matrice $A\in M(m,n,\mathbb{K})$ è:
$$^{t}A\in M(n,n,\mathbb{K})$$
definita scambiando right e colonne:
$$(^{t}A)_{ij}=A_{ji}$$
#Esempio 
$$
A=
\begin{pmatrix}
2 & 1 \\
-1 & 0 \\
5 & 7
\end{pmatrix}
\Longrightarrow
\quad \quad
\prescript{t}{}{A}=
\begin{pmatrix}
2 & -1 & 5 \\
1 & 0 & 7
\end{pmatrix}
$$
Valgono le proprietà:
$$\prescript{t}{}{(A+B)}=\prescript{t}{}{A}+\prescript{t}{}{B},\quad\quad \prescript{t}{}{(\lambda A)}=\lambda\prescript{t}{}{A}$$
## Rango
Sappiamo come risolvere un sistema lineare e che l’insieme $S$ delle soluzioni può essere vuoto o un sottospazio affine di una certa dimensione. Cerchiamo adesso delle tecniche per capire rapidamente se un sistema lineare abbia soluzioni, e in caso affermativo la loro dimensione.
Sia $A$ una matrice $m\times n$ a coefficienti in $\mathbb{K}$. Ricordiamo che indichiamo con $A^{1},\dots,A^{n}$ le colonne di $A$. Ciascun $A^{i}$ è un vettore in $\mathbb{K}^{m}$.
#Definizione 
Il *rango* di $A$ è la dimensione dello spazio:
$$Span(A^{1},\dots,A^{n})\subset \mathbb{K}^{m}$$
Il rango di $A$ è la dimensione dello spazio generato dalle colonne.
Viene indicato con $rk(A)$.
#proposizione 
Se modifichiamo $A$ per mosse di Gauss sulle righe, il rango non cambia.
#proposizione 
Il rango di $A$ è il numero di pivot in una sua qualsiasi riduzione a scalini.
## Prodotto fra matrici
Se $A$ è una matrice $m\times n$ e $B$ una matrice $n\times p$ il prodotto $AB$ è una nuova matrice $m\times p$ definita come:
$$(AB)_{ij}=\displaystyle\sum_{k=1}^{n}A_{ik}B_{kj}=A_{i1}B_{1j}+\ldots+A_{in}B_{nj}$$
Questo tipo di prodotto fra matrici si chiama *prodotto* riga per colonna perché l'elemento $(AB)_{ij}$ si ottiene facendo un opportuno prodotto fra la riga $i$-esima $A_{i}$ di $A$ e la colonna $j$-esima $B^{j}$ di $B$.
#Esempio 
$$
\begin{pmatrix}
1 & 2 \\
-1 & 1 \\
0 & 3
\end{pmatrix}
\cdot
\begin{pmatrix}
-1 & 2 & 0 & 1 \\
3 & 0 & 3 & 0
\end{pmatrix}
=
\begin{pmatrix}
5 & 2 & 6 & 1 \\
4 & -2 & 3 & -1 \\
9 & 0 & 9 & 0
\end{pmatrix}
$$
### Proprietà
Ricordiamo che il prodotto AB ha senso solo se il numero di colonne di $A$ coincide con il numero di righe di $B$.
Valgono le proprietà seguenti, per ogni $A, B, C$ matrici per cui i prodotti e le somme abbiano senso e per ogni $\lambda\in\mathbb{K}$:
1. $A(B+C)=AB+AC$ e $(A+B)C=AC+BC$ distributività
2. $A(BC)=(AB)C$ associatività
3. $\lambda(AB)=(\lambda A)B=A(\lambda B)$
## Traccia di una matrice
La *traccia* di una matrice quadrata $A\in M(n)$ è il numero:
$$tr(A)=A_{11}+\ldots+A_{nn}$$
la traccia di $A$ è la somma dei valori sulla diagonale principale di $A$.
Due matrici *simili* hanno la stessa traccia.
#Dimostrazione 
Se $A=M^{-1}BM$, troviamo:
$$tr(A)=tr(M^{-1}BM)=tr((M^{-1}B)M)=tr(M(M^{-1}B))=tr(B)$$
#Esempio 
$$
tr
\begin{pmatrix}
1 & 0 \\
2 & 5
\end{pmatrix}
= 1+5=6
$$
#Esempio 
$$
tr
\begin{pmatrix}
1 & 2 & 4 \\
-1 & 3 & 7 \\
0 & 5 & -4
\end{pmatrix}
=1+3+(-4)=0
$$
## Determinante
#Definizione 
Sia $A$ una matrice quadrata $n\times n$. Il *determinante* di $A$ è il numero:
$$\det A=\displaystyle\sum_{\sigma\in S_{n}}sgn(\sigma)a_{1\sigma(1)}\ldots a_{n\sigma(n)}$$
#Esempio 
$$
A=
\begin{pmatrix}
2 & -1 & 4 \\
1 & 2 & 0 \\
3 & 5 & 1
\end{pmatrix}
$$
$$
\begin{matrix}
2 & -1 & 4 & 2 & -1 & 4 \\
1 & 2 & 0 & 1 & 2 & 0 \\
3 & 5 & 1 & 3 & 5 & 1
\end{matrix}
$$
Sommiamo i prodotti lungo le tre diagonali principali:
$$(2\cdot 2\cdot 1)+(-1 \cdot 0 \cdot 3)+(4 \cdot 1 codt 5)=4+0+20=24$$
Quelli lungo le ultime tre diagonali:
$$(4 \cdot 2 \cdot 3)+(-1 \cdot 1 \cdot 1)+(2 \cdot 0 \cdot 5)=24-1+0=23$$
Sottraendo, nell'ordine, i due risultati otteniamo:
$$\det(A)=24-23=1$$
## Matrici triangolari
Il calcolo del determinante di una matrice triangolare è particolarmente semplice: è il prodotto dei valori sulla diagonale principale.
Sia $A\in M(n)$ una matrice superiore:
$$
A=
\begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
0 & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots  & a_{nn}
\end{pmatrix}
$$
vale:
$$\det(A)=a_{11}a_{22}\cdots a_{nn}$$
## Matrice identità
La *matrice identità* di taglia $n\times n$ è:
$$
I_{n}=
\begin{pmatrix}
1 & 0 & \cdots & 0 \\
0 & 1 & \cdots & 0 \\
\vdots  & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & 1
\end{pmatrix}
$$
i cui coefficienti sono $1$ sulla diagonale principale e $0$ altrove.
## Sviluppo di Laplace
Ci sono vari algoritmi che permettono di calcolare il determinante di una matrice più agevolmente che con la cruda definizione. Uno di questi è noto come lo *sviluppo di Laplace* e funziona nel modo seguente.
Sia $A$ una matrice $n\times n$ con $n\geq 2$. Indichiamo con $C_{ij}$ la sottomatrice $(n-1)\times(n-1)$ ottenuta da $A$ rimuovendo la $i$-esima riga e la $j$-esima colonna.
#Teorema per ogni $i$ fissato vale:
$$
\det (A)=\displaystyle\sum_{j=1}^{n}(-1)^{i+j}a_{ij}\det (C_{ij})
$$
#Dimostrazione 
In caso $n=3$ e $i=1$ e
$$\det(A)=a_{11}\det(C_{11})-a_{12}\det(C_{12})+a_{13}\det(C_{13})$$
![[Screenshot 2023-12-16 alle 12.43.30.png|350]]
Per ogni $j=1,\dots,n$, le colorazioni della sottomatrice $C_{ij}$, che sommate danno $\det(C_{ij})$, contribuiscono alle colorazioni della matrice $A$ con un peso che va moltiplicato. per $a_{ij}$ e per un segno $(-1)^{i+j}$.
#Esempio 
$$
\det
\begin{pmatrix}
1 & -1 & 0 \\
2 & -2 & 5 \\
1 & 1 & -1
\end{pmatrix}
=1\cdot \det
\begin{pmatrix}
-1 & 5 \\
1 & -1
\end{pmatrix}
-(5
1)\cdot \det
\begin{pmatrix}
2 & 5 \\
1 & -1
\end{pmatrix}
$$
$$
+o\cdot \det
\begin{pmatrix}
2 & -1 \\
1 & 1
\end{pmatrix}
=-4-7+0=-11
$$
è conveniente sviluppare lungo una riga che contiene degli zeri.
Grazie al fatto che $\prescript{t}{}{A}=\det A$, è anche possibile usare lo svilupppo di Laplace sulle colonne. Ad esempio sviluppando la matrice seguente sulla seconda colonna otteniamo:
$$
\det
\begin{pmatrix}
1 & 0 & 1 \\
2 & 0 & 1 \\
\pi & 3 & \sqrt{ 7 }
\end{pmatrix}
=(-1)\cdot 3\cdot \det
\begin{pmatrix}
1 & 1 \\
2 & 1
\end{pmatrix}
=3
$$
## Mosse di Gauss
Il determinante è compatibile con le *mosse di Gauss*.
Sia $A$ una matrice $n\times n$ e sia $A'$ ottenuta aggiunta da $A$ tramite una *mossa di Gauss*. Il determinante cambia:
1. Se $A'$ è ottenuta da $A$ scambiando due righe, $\det(A')=.-\det(A)$
2. Se $A'$ è ottenuta da $A$ moltiplicando una riga di $A$ per uno scalare $\lambda$, allora $\det(A')=\lambda \det(A)$
3. Se $A'$ è ottenuta da $A$ aggiungendo ad una riga il multiplo di un'altra, allora $\det(A')=\det(A)$
#Dimostrazione 
Per induzione su $n\geq 2$. se $n=2$, tutte le proprietà discendono dalla formula $\det \begin{pmatrix}a&b\\c&d\end{pmatrix}=ad-bd$.
Dimostriamo per $n\geq 3$ supponendo sia vero per $n-1$.
Siccome $n\geq 3$, esiste sempre una riga di $A_{i}$ che non è implicata nella mossa di Gauss. Con lo sviluppo di Laplace lungo la riga $i$-esima troviamo:
$$\det (A)=\displaystyle\sum_{j=1}^{n}(-1)^{i+j}a_{ij}\det(C_{ij})$$
$$\det (A')=\displaystyle\sum_{j=1}^{n}(-1)^{i+j}a_{ij}\det(C'_{ij})$$
La matrice $C'_{ij}$ è di taglia $(n-1)\times(n-1)$ ed è ottenuta da $C_{ij}$ tramite lo stesso tipo di mossa di Gauss che trasforma $A$ in $A'$. Quindi per l'ipotesi induttiva:
$$\det(C'_{ij})=-\det(C_{ij}),\lambda \det(C_{ij})\text{ oppure }\det(C_{ij})$$
a seconda della mossa di Gauss.
#Esempio 
Nel calcolo del determinante è spesso utile combinare mosse di Gauss e sviluppo di Laplace:
$$
\det
\begin{pmatrix}
5 & 1 & 1 & 2 & 1 \\
1 & 4 & 1 & 1 & 1 \\
1 & 3 & 3 & 1 & 1 \\
1 & 1 & 1 & 6 & 1 \\
1 & 1 & 1 & 1 & 1
\end{pmatrix}
=\det
\begin{pmatrix}
4 & 0 & 0 & 1 & 0 \\
0 & 3 & 0 & 0 & 0 \\
0 & 2 & 2 & 0 & 0 \\
0 & 0 & 0 & 5 & 0 \\
1 & 1 & 1 & 1 & 1
\end{pmatrix}
=\det
\begin{pmatrix}
4 & 0 & 0 & 1 \\
0 & 3 & 0 & 0 \\
0 & 2 & 2 & 0 \\
0 & 0 & 0 & 5
\end{pmatrix}
$$
$$
=5\det
\begin{pmatrix}
4 & 0 & 0 \\
0 & 3 & 0 \\
0 & 2 & 2
\end{pmatrix}
=5 \cdot 4 \cdot 3 \cdot 2 = 120
$$
Nella prima uguaglianza abbiamo tolto l’ultima riga da tutte le altre, quindi abbiamo sviluppato lungo alcune righe o colonne e infine abbiamo usato la formula per le matrici triangolari.
## Calcolo del rango
Il determinante può essere usato per calcolare il rango di una matrice qualsiasi. Ricordiamo che il determinante è definito solo per le matrici quadrate, mentre il rango è definito per tutte.
Sia $A$ una matrice $m\times n$. Un minore di $A$ di ordine $k$ è una sottomatrice quadrata $k\times k$ ottenuta cancellando $m-k$ righe e $n-k$ colonne.
#Esempio 
Usiamo il determinante per capire per quali $k\in \mathbb{R}$ il seguente sistema abbia soluzioni reali:
$$
\begin{cases}
\begin{align}
y+kz&=-k \\
2x+(k-3)y+4z&=k-1 \\
x+ky-kz&=k+1
\end{align}
\end{cases}
$$
La matrice dei coefficienti è
$$
A=
\begin{pmatrix}
0 & 1 & k \\
2 & k-3 & 4 \\
1 & k & -k
\end{pmatrix}
$$
con determinante $(k+4)(k+1)$. Quindi per $k\neq-1,-4$ sia $A$ che $C=(A|b)$ hanno rango massimo e il sistema ha una sola soluzione.
Per $k=-1$ la matrice $C$ diventa:
$$
C=
\begin{pmatrix}
0 & 1 & -1 & | & 1 \\
2 & -4 & 4 & | & -2 \\
1 & -1 & 1 & | & 0
\end{pmatrix}
$$
Troviamo $rkA=rkC=2$ perché è facile trovare una relazione tra le righe di $C$, oppure perché tutti e $4$ i minori $3\times3$ di $C$ hanno determinante nullo, mentre il minore $\begin{pmatrix}0&1\\2&-4\end{pmatrix}$ ha $\det \neq 0$. Quindi il sistema ha soluzione, e le soluzioni formano un sottospazio affine di dimensione $3-2=1$.
Per $k=-1$:
$$
C=
\begin{pmatrix}
0 & 1 & -4 & | & 4 \\
2 & -7 & 4 & | & -5 \\
1 & -4 & 4 & | & -3
\end{pmatrix}
$$
Troviamo $rkA=2$ perché $A$ contiene il minore $\begin{pmatrix}0&1\\2&-7\end{pmatrix}$ che ha $\det \neq 0$. D'altra parte $rkC=3$ perché $C$ contiene un minore $3\times3$ con $\det$ non nullo:
$$
\det
\begin{pmatrix}
0 & -4 & 4 \\
2 & 4 & -5 \\
1 & 4 & -3
\end{pmatrix}
=4\det
\begin{pmatrix}
0 & -1 & 4 \\
2 & 1 & -5 \\
1 & 1 & -3
\end{pmatrix}
=4\det
\begin{pmatrix}
0 & -1 & 4 \\
0 & -1 & 1 \\
1 & 1 & -3
\end{pmatrix}
$$
$$
4\det
\begin{pmatrix}
-1 & 4 \\
-1 & 1
\end{pmatrix}
=4\cdot 3=12
$$
## Base di $\mathbb{K}^{n}$
Per capire se $n$ vettori $v_{1},\dots,v_{n}\in\mathbb{K}^{n}$ sono una base, si affiancano e si costruisce una matrice quadrata $A=(v_{1},\dots,v_{n})$.
#proposizione 
I vettori $v_{1},\dots,v_{n}$ sono una base $\iff \det(A)\neq 0$.
#Dimostrazione 
I vettori $v_{1},\dots,v_{n}$ sono una base $\iff$ generano $\mathbb{K}^{n}$$\iff rk(A)=n\iff \det(A)\neq 0$
#Corollario 
I vettori $\dbinom{a}{b},\dbinom{c}{d}\in\mathbb{K}^{2}$ sono una base $\iff ad-bc\neq 0$.
## Algebra delle matrici
## Prodotto fra matrici
Se $A$ è una matrice $m\times n$ e $B$ una matrice $n\times p$ il prodotto $AB$ è una nuova matrice $m\times p$ definita:
$$(AB)_{ij}=\displaystyle\sum_{k=1}^n A_{ij}B_{kj}=A_{i1}B_{1j}+\ldots+A_{in}B_{nj}$$
Questo prodotto si chiama *prodotto riga per colonna* perché l'elemento $(AB)_{ij}$ si ottiene facendo il prodotto fra la riga $i$-esima $A_{i}$ di $A$ e la colonna $j$-esima $B^{j}$ di $B$.
#Esempio 
$$
\begin{pmatrix}
1 & 2 \\
-1 & 1 \\
0 & 3
\end{pmatrix}
\cdot
\begin{pmatrix}
-1 & 2 & 0 & 1 \\
3 & 0 & 3 & 0
\end{pmatrix}
=
\begin{pmatrix}
5 & 2 & 6 & 1 \\
4 & -2 & 3 & -1 \\
9 & 0 & 9 & 0
\end{pmatrix}
$$
Il prodotto $AB$ si può fare solo se il numero di colonne di $A$ è lari al numero di righe di $B$.
#Esempio 
$$
\begin{pmatrix}
1 & 2 \\
-1 & 1 \\
0 & 3
\end{pmatrix}
\cdot
\begin{pmatrix}
1 \\
-1
\end{pmatrix}
=
\begin{pmatrix}
-1 \\
-2 \\
-3
\end{pmatrix}
$$
## Proprietà
Per ogni $A,B,C$ matrici per cui prodotto e le somme abbiano senso e per ogni $\lambda\in\mathbb{K}$.
1. $A(B+C)=AB+AC$ e $(A+B)C=AC+BC$ *distributiva*
2. $A(BC)=(AB)C$ *associativa*
3. $labda(AB)=(\lambda A)B=A(\lambda B)$
## Traccia di una matrice quadrata
LA *traccia* di una matrice quadrata $A\in M(n)$ è il numero:
$$trA=A_{11}+\ldots+A_{nn}$$
La traccia di $A$ è la somma dei valori sulla diagonale principale di $A$.
Se $A,B\in M(n)$, allora $tr(AB)=tr(BA)$.
#Dimostrazione 
$$tr(AB)=\displaystyle\sum_{i=1}^n (AB)_{ii}=\sum_{i=1}^n \sum_{j=1}^n A_{ij}B_{ji}$$
$$tr(BA)=\displaystyle\sum_{j=1}^n (BA)_{jj}=\sum_{j=1}^n \sum_{i=1}^n B_{ij}A_{ij}$$
## Teorema di Binet
#Teorema 
Date $A,B\in M(n)$, vale:
$$\det(AB)=\det A\cdot \det B$$
#Dimostrazione 
Sia $B_{i}$ la riga $i$-esima di $B$:
$$
\det(AB)=\det
\begin{pmatrix}
a_{11}B_{1}+\ldots+a_{1n}B_{n} \\
\vdots \\
a_{n1}B_{1}+\ldots+a_{nn}B_{n}
\end{pmatrix}
$$
vale $\det(A)=\lambda_{1}\det(B_{1})+\ldots+\lambda_{h}\det(B_{h})$.
Usando numerose volte ciò sulle righe possiamo scrivere questa quantità come somma di $n^{n}$ addendi del tipo:
$$
a_{1\sigma(1)}\dots a_{n\sigma(n)}\det
\begin{pmatrix}
B_{\sigma(1)} \\
\vdots \\
B_{\sigma(n)}
\end{pmatrix}$$
al variare di $\sigma(1),\dots,\sigma(n)\in \{1,\dots,n\}$. Se due righe sono uguali allora il determinante si annulla: quindi ci possiamo limitare a considerare solo i casi in cui $\sigma(1),\dots,\sigma(n)$ sono tutti distinti, in altre parole $σ$ è una permutazione.
$$
\det(AB)=\displaystyle\sum_{\sigma \in S_{n}}a_{1\sigma(1)}\dots a_{n\sigma(n)}\det
\begin{pmatrix}
B_{\sigma(1)} \\
\vdots \\
B_{\sigma(n)}
\end{pmatrix}
$$
## Calcolo dell'inversa di una matrice
Introduciamo un algoritmo che permette di calcolare l’inversa di una matrice $A$, quando esiste. Si basa sulle mosse di Gauss.
Si prende \lambdamatrice $n\times(2n)$
$$C=(A|I_{n})$$
ottenuta affiancando $A$ e la matrice identità $I_{n}$. Trasformiamo $C$ con l'algoritmo di Gauss - Jordan. Se $rkA=n$, tutti i pivot stanno nelle prime $n$ colonne e abbiamo ottenuto una nuova matrice:
$$C'=(I|B)$$
dove $B$ è una matrice $n\times n$. $B=A^{-1}$.
### TODO
# Sistemi lineari
## Mosse di Gauss
Un *sistema lineare* è un insieme di $k$ equazioni lineari in $n$ variabili
$$
\begin{cases}
\begin{align}
a_{11}x_{1}+\dots+a_{1n}x_{n}&=b_{1} \\
\vdots \\
a_{k1}x_{1}+\dots+a_{kn}x_{n}&=b_{k}
\end{align}
\end{cases}
$$
I numeri $a_{ij}$ sono i *coefficienti* e i $b_{i}$ i *termini noti* del sistema.
Possiamo raggruppare i coefficienti e i termini noti in una matrice $k\times n$ e un vettore colonna:
$$
A=
\begin{pmatrix}
a_{11} & \dots & a_{1n} \\
\vdots & \ddots & \vdots \\
a_{k1} & \dots & a_{kn}
\end{pmatrix},
\quad\quad
b=
\begin{pmatrix}
b_{1} \\
\vdots \\
b_{k}
\end{pmatrix}
$$
uniamo tutti in una unica matrice $k\times(n+1)$:
$$C=(A|b)$$
Dobbiamo determinare l'insieme $S\subset \mathbb{K}^{n}$ delle soluzioni del sistema.
Notiamo che esistono alcune mosse che cambiano la matrice $C$ senza modificare l’insieme $S$ delle soluzioni del sistema. Queste sono le seguenti e sono note come mosse di Gauss:
1. Scambiare due righe
2. Moltiplicare una riga per un numero $\lambda \neq 0$
3. Aggiungere ad una riga un'altra riga moltiplicata per $\lambda$ qualsiasi
#Esempio 
$$
\begin{pmatrix}
1 & 2 \\
3 & 0 \\
4 & -2
\end{pmatrix}\
\xrightarrow{1.}
\begin{pmatrix}
4 & -2 \\
3 & 0 \\
1 & 2
\end{pmatrix}\
\xrightarrow{2.}
\begin{pmatrix}
2 & -1 \\
3 & 0 \\
1 & 2
\end{pmatrix}
\xrightarrow{3.}
\begin{pmatrix}
2 & -1 \\
5 & 4 \\
1 & 2
\end{pmatrix}
$$
## Algoritmo di Gauss
Introduciamo un algoritmo che può essere usato per risolvere qualsiasi sistema lineare. L’algoritmo trasforma una arbitraria matrice $C$ in una matrice particolare detta *a scalini*.
Sia $C$ una matrice qualsiasi. Per ogni riga $C_{i}$ di $C$, chiamiamo pivot il primo elemento non nullo della riga $C_{i}$. Una *matrice a scalini* è una matrice avente la proprietà:
il pivot di ogni riga è sempre strettamente più a destra del pivot della riga precedente.
#Esempio 
$$
\begin{pmatrix}
1 & 0 & 5 \\
0 & -1 & -1
\end{pmatrix},
\quad\quad
\begin{pmatrix}
7 & -2 & 9 \\
0 & 0 & 1 \\
0 & 0 & 0
\end{pmatrix}
$$
L’algoritmo di Gauss è un algoritmo che trasforma qualsiasi matrice $C$ in una matrice a scalini usando le 3 mosse di Gauss:
1. Se $C_{11}=0$, scambia se puoi la prima riga con un'altra riga in modo da ottenere $C_{11}\neq 0$. Se $C_{i1}=0$ per ogni $i$, passa al punto 3.
2. Per ogni riga $C_{i}$ con $i\geq 2$ e con $C_{i1}\neq 0$ sostituisci $C_{i}$ con la riga
$$C_{i}-\frac{C_{i1}}{C_{11}}C_{1}$$
3. Ottenuto $C_{i1}=0$ per ogni $i\geq 2$. Continua dal punto 1. lavorando sulla sottomatrice ottenuta togliendo la prima riga e la prima colonna
#Esempio 
$$
C=
\begin{pmatrix}
0 & 1 & 1 & 0 \\
1 & 1 & 2 & -3 \\
-1 & 2 & 1 & 1
\end{pmatrix}
$$
$C_{11}=0$ quindi scambiamo $C_{1}$ e $C_{2}$ per ottenere $C_{11}\neq 0$:
$$
C=
\begin{pmatrix}
1 & 1 & 2 & -3 \\
0 & 1 & 1 & 0 \\
-1 & 2 & 1 & 1
\end{pmatrix}
$$
ora $C_{31}\neq0$, scambiamo $C_{3}$ con $C_{3}+C_{1}$:
$$
C=
\begin{pmatrix}
1 & 2 & 2 & -3 \\
0 & 1 & 1 & 0 \\
0 & 3 & 3 & -2
\end{pmatrix}
$$
$C_{32}\neq 0\rightarrow C_{3}=C_{3}-3C_{2}$:
$$
C=
\begin{pmatrix}
1 & 1 & 2 & -3 \\
0 & 1 & 1 & 0 \\
0 & 0 & 0 & -2
\end{pmatrix}
$$
## Risoluzione di un sistema lineare
Il sistema è descritto da una matrice $C = (A | b)$. Usando l’algoritmo di Gauss - Jordan, possiamo trasformare $C$ in una matrice a scalini, in cui ogni pivot ha valore $1$ e tutti i numeri sopra i pivot sono nulli. La matrice $C$ sarà indicativamente di questo tipo:
$$
\begin{pmatrix}
0 & 1 & ? & 0 & 0 & ? & | & ? \\
0 & 0 & 0 & 1 & 0 & ? & | & ? \\
0 & 0 & 0 & 0 & 1 & ? & | & ?
\end{pmatrix}
$$
Adesso guardiamo le colonne che contengono i pivot, in questo esempio la seconda, la quarta e la quinta. Ciascuna di queste colonne contiene un 1 al posto del pivot e 0 in tutte le altre caselle.
Ci sono due casi da considerare. Se la colonna dei termini noti $b$ contiene un pivot, allora la matrice è indicativamente di questo tipo:
$$
\begin{pmatrix}
0 & 1 & ? & 0 & 0 & ? & | & ? \\
0 & 0 & 0 & 1 & 0 & ? & | & ? \\
0 & 0 & 0 & 0 & 0 & 0 & | & 1
\end{pmatrix}
$$
La riga che contiene l’ultimo pivot rappresenta l’equazione $0 = 1$ che chiaramente non può avere soluzione. In questo caso l’insieme $S$ delle soluzioni è vuoto, cioè $S = ∅$.
Consideriamo adesso il caso in cui l’ultima colonna non contenga pivot. La matrice $C$ è indicativamente di questo tipo:
$$
\begin{pmatrix}
0 & 1 & a_{13} & 0 & 0 & a_{16} & | & b_{1} \\
0 & 0 & 0 & 1 & 0 & a_{26} & | & b_{2} \\
0 & 0 & 0 & 0 & 1 & a_{36} & | & b_{3}
\end{pmatrix}
$$
ciascuna colonna corrisponde ad una variabile $x_{1},...,x_{n}$, eccetto l’ultima che contiene i *termini noti*. Adesso assegniamo un parametro $t_{1},t_{2},...$ a ciascuna variabile che corrisponde ad una colonna che non contiene un pivot. Nel nostro caso, scriviamo $x_{1} = t_{1}, x_{3} = t_{2}$ e $x_{6} = t_{3}$. Conseguentemente il sistema lineare è di questa forma:
$$
\begin{cases}
x_{2}+a_{13}t_{2}+a_{16}t_{3}=b_{1} \\
x_{4}+a_{26}t_{3}=b_{2} \\
x_{5}+a_{35}t_{3}=b_{3}
\end{cases}
$$
Spostiamo a destra dell’uguale tutti i parametri:
$$
\begin{cases}
x_{2}=b_{1}-a_{13}t_{2}-a_{16}t_{3} \\
x_{4}=b_{2}-a_{26}t_{3} \\
x_{5}=b_{3}-a_{36}t_{3}
\end{cases}
$$
Al sistema aggiungiamo anche le equazioni corrispondenti alle assegnazioni dei parametri liberi:
$$
\begin{cases}
x_{1}=t_{1} \\
x_{2}=b_{1}-a_{13}t_{2}-a_{16}t_{3} \\
x_{3}=t_{2} \\
x_{4}=b_{2} \\
x_{5}=b_{3}-a_{35}t_{3} \\
x_{6}=t_{3}
\end{cases}
$$
Il sistema è risolto.
Notiamo che è sempre possibile usare una notazione parametrica vettoriale per esprimere le soluzioni, del tipo:
$$
\begin{pmatrix}
x_{1} \\
x_{2} \\
x_{3} \\
x_{4} \\
x_{5} \\
x_{6}
\end{pmatrix}
=
\begin{pmatrix}
t_{1} \\
b_{1}-a_{13}t_{2}-a_{16}t_{3} \\
t_{2} \\
b_{2}-a_{26}t_{3} \\
b_{3}-a_{36}t_{3} \\
t_{3}
\end{pmatrix}
=
\begin{pmatrix}
0 \\
b_{1} \\
0 \\
b_{2} \\
b_{2} \\
0
\end{pmatrix}
+t_{1}
\begin{pmatrix}
1 \\
0 \\
0 \\
0 \\
0 \\
0
\end{pmatrix}
+t_{2}
\begin{pmatrix}
0 \\
-a_{13} \\
1 \\
0 \\
0 \\
0
\end{pmatrix}
+t_{3}
\begin{pmatrix}
0 \\
-a_{16} \\
0 \\
-a_{26} \\
-a_{36} \\
1
\end{pmatrix}
$$
In generale, le soluzioni sono sempre del tipo
$$x=x_{0}+t_{1}v_{1}+\ldots+t_{h}v_{h}$$
dove $x_{0},v_{1},\dots,v_{h}\in\mathbb{K^{n}}$ sono vettori fissati e i $v_{i}$ sono della forma:
$$
v_{i}=
\begin{pmatrix}
? \\
\vdots \\
? \\
1 \\
0 \\
\vdots \\
0
\end{pmatrix}
$$
con la posizione della cifra $1$ che scende al crescere di $i$. I vettori $v_{1},\dots, v_{h}$ sono sempre indipendenti.
#Esempio 
$$
\begin{cases}
\begin{align}
x_{1}+3x_{2}+4x_{5}&=1 \\
x_{3}-2x_{4}&=3
\end{align}
\end{cases}
$$
Le variabili corrispondenti ai pivot sono $x_{1}$ e $x_{3}$. Le variabili libere sono $x_{2}, x_{4}$ e $x_{5}$. Quindi scriviamo:
$$
\begin{cases}
x_{1}=1-t_{1}-4t_{3} \\
x_{2}=t_{1} \\
x_{3}=3+2t_{2} \\
x_{4}=t_{2} \\
x_{5}=t_{3}
\end{cases}
$$
## Teorema di Rouché - Capelli
## Il sistema omogeneo associato
Consideriamo un sistema di equazioni lineari
$$
\begin{cases}
\begin{align}
a_{11}x_{1}+\ldots+&a_{1n}x_{n}=b_{1} \\
\vdots \\
a_{k1}x_{1}+\ldots+&a_{kn}x_{n}=b_{1}
\end{align}
\end{cases}
$$
Il *sistema omogeneo associato* è quello ottenuto semplicemente mettendo a zero tutti i termini noti $b_{i}$
$$
\begin{cases}
\begin{align}
a_{11}x_{1}+\ldots+&a_{1n}x_{n}=0 \\
\vdots \\
a_{k1}x_{1}+\ldots+&a_{kn}x_{n}=0
\end{align}
\end{cases}
$$
scriviamo la matrice $A=(a_{ij})$ dei coefficienti e il vettore $b=(b_{i})$ dei termini noti. La matrice $C=(A|b)$ rappresenta il sistema lineare iniziale, mentre $(A|0)$ rappresenta il sistema omogeneo associato.
Sia $S\subset \mathbb{K}^{n}$ l'insieme delle soluzioni del sistema lineare iniziale e $S_{0}\subset \mathbb{K}^{n}$ l'insieme delle soluzioni del sistema omogeneo associato.
$S$ e $S_{0}$ sono correlati: se $S\neq \emptyset$, allora $S$ è ottenuto prendendo una soluzione $x\in S$ e aggiungendo a questa tutti i vettori $S_{0}$.
#Dimostrazione 
Sia $x\in S$ soluzione del sistema e $x'\in S_{0}$ soluzione del sistema omogeneo associato. $x+x'$ è anch'essa soluzione dei sistema:
$$a_{i_{1}}(x_{1}+x'_{1})+\ldots+a_{in}(x_{n}+x'_{n})=b_{i}+0=b_{i}$$
#Esempio 
$$
\begin{cases}
\begin{align}
x-y+z&=1 \\
y-z&=2
\end{align}
\end{cases}
$$
troviamo che le soluzioni $S$ sono
$$
\begin{pmatrix}
3 \\
t \\
t-2
\end{pmatrix}
=
\begin{pmatrix}
3 \\
0 \\
-2
\end{pmatrix}
+
\begin{pmatrix}
0 \\
t \\
t
\end{pmatrix}
$$
al variare di $t\in\mathbb{R}$. Le soluzioni $S_{0}$ del sistema omogeneo associato
$$
\begin{cases}
\begin{align}
x-y+z&=0 \\
y-z&=0
\end{align}
\end{cases}
$$
sono vettori
$$
\begin{pmatrix}
0 \\
t \\
t
\end{pmatrix}
$$
Le soluzioni in $S$ sono tutte ottenute prendendo la soluzione particolare
$$
\begin{pmatrix}
3 \\
0 \\
-2
\end{pmatrix}
$$
ed aggiungendo a questa tutte le soluzioni in $S_{0}$ del sistema omogeneo associato. Qualsiasi elemento di $S$ può fungere da soluzione particolare:
$$
\begin{pmatrix}
3 \\
2 \\
0
\end{pmatrix}
$$
e quindi descrivere lo stesso insieme $S$ di soluzioni in questo modo:
$$
\begin{pmatrix}
3 \\
2 \\
0
\end{pmatrix}
+
\begin{pmatrix}
0 \\
u \\
u
\end{pmatrix}
=
\begin{pmatrix}
3 \\
2+u \\
u
\end{pmatrix}
$$
Si ottiene effettivamente lo stesso insieme $S$, sostituendo $t =u+2$.
## Teorema di Rouché - Capelli
Consideriamo un sistema lineare
$$
\begin{cases}
\begin{align}
a_{11}x_{1}+\ldots+&a_{1n}x_{n}=b_{1} \\
\vdots \\
a_{k1}x_{1}+\ldots+&a_{kn}x_{n}=b_{1}
\end{align}
\end{cases}
$$
$A=(a_{ij})$ matrice dei coefficienti, $b=(b_{i})$ vettore dei termini noti e $C=(A|b)$ matrice completa.
Il sistema ha soluzioni se e solo se
$$b\in Span(A^1,\dots,A^n)$$
#Dimostrazione il sistema può essere riscritto
$$x_{1}A^1+\ldots+x_{n}A^n=b$$
Esistono soluzioni se e solo se b è combinazione lineare delle colonne $A^1,\dots,A^n$ con coefficienti $x_{1},\dots,x_{n}$.
#Teorema 
Il sistema ha soluzioni se e solo se
$$rk(A|b)=rk(A)$$
Lo spazio delle soluzioni $S\subset \mathbb{K}^n$ è un sottospazio affine di dimensione $n-rk(A)$.
Se ci sono soluzioni, sappiamo che la dimensione di $S$ è pari alla dimensione dello spazio $S_{0}$.
Il sistema ha $0,1$ oppure $\infty$ soluzioni:
- $0$ se $rk(A|b)>rkA$
- $1$ se $rk(A|b)=rkA=n$
- $\infty$ se $rk(A|b)=rkA<n$
#Esempio 
$$
\begin{cases}
\begin{align}
x+ky&=4-k \\
kx+4y&=4
\end{align}
\end{cases}
$$
Vogliamo sapere al variare di $k ∈ R$ se ci siano soluzioni e, in caso affermativo, la dimensione, applichiamo Gauss:
$$
\begin{pmatrix}
1 & k & ! & 4-k \\
k & 4 & | & 4
\end{pmatrix}
\longrightarrow
\begin{pmatrix}
1 & k & | & 4-k \\
0 & 4-k^2 & | & 4-4k+k^2
\end{pmatrix}
$$
Notiamo che $4-4k+k^{2}=(k-2)^{2}$. La matrice è ridotta a scalini per tutti i possibili valori di $k ∈ R$ e ci sono sempre due pivot, tranne per $k = 2$ in cui ce n'è solo uno. $rk(A|B)=1$ per $k=2$ e $2$ per $k\neq 2$.
La matrice dei coefficienti con le mosse di Gauss è diventata
$$
\begin{pmatrix}
1 & k \\
0 & 4-k^2
\end{pmatrix}
$$
il rango è $1$ per $k=\pm 2$ e rango $2$ per $k\neq\pm 2$.
- Se $k=-2$, $rk(A|b)\neq rk(A)$, non ci sono soluzioni
- Se$k=2$, $rk(A|b)=rk(A)=1$, le soluzioni formano un sottospazio di $\mathbb{R}^{2}$ di dimensione $2-1=1$, una retta affine, infinite soluzioni
- Se $k\neq \pm_{2}$, $rk(A|b)=rk(A)=2$, le soluzioni formano un sottosapzio di $\mathbb{R}^{2}$ di dimensione $2-2=0$, un punto, una sola soluzione
## Sistema lineare omogeneo
$$
\begin{cases}
\begin{align}
a_{11}x_{1}+\ldots+&a_{1n}x_{n}=0 \\
\vdots \\
a_{k1}x_{1}+\ldots+&a_{kn}x_{n}=0
\end{align}
\end{cases}
$$
Un sistema lineare omogeneo ha sempre soluzione. Il sottospazio vettoriale $S\subset \mathbb{K}^{n}$ delle solluzioni ha dimensione $n-rk(A)$.
Le due differenze principali fra i sistemi lineari omogenei e non omogenei: nei primi le soluzioni ci sono sempre e formano un sottospazio vettoriale, mentre nei secondi le soluzioni possono non esserci, se ci sono formano un sottospazio affine.
## Sistema lineare con $A$ invertibile
Sia
$$Ax=b$$
sistema lineare con $A$ quadrata. Se $A$ è invertibile possiamo moltiplicare entrambe i membri per $A^{-1}$:
$$x=A^-1 b$$
il sistema ha quindi una unica soluzione.
## Lo spazio $\mathbb{K}[x]$ dei polinomi
Indichiamo con $\mathbb{K}[x]$ l'insieme di tutti i polinomi con coefficienti in un campo $\mathbb{K}$. Due polinomi possono essere sommati, e moltiplicando un polinomio per uno scalare otteniamo un polinomio.
$$(x^3 -2x+1)+(4x^4 +x-3)=3x^4+x^3-x-2, \quad\quad 3(x^3-2x)=3x^3-6x$$
# Applicazioni lineari
## Definizione
Siano $V$ e $W$ due spazi vettoriali sullo stesso campo $\mathbb{K}$
$$f:v\to W$$
è lineare se:
1. $f(0)=0$
2. $f(v+w)=f(v)+f(w)\ \forall v,w\in V$ 
3. $f(\lambda v)=\lambda f(v) \ \forall v\in V, \forall \lambda\in \mathbb{K}$
## Combinazioni lineari
Se $f:V \to W$ è lineare ed un vettore $v\in V$ è espresso come combinazione lineare di alcuni vettori di $V$:
$$v=\lambda_{1}v_{1}+\ldots+\lambda_{k}v_{k}$$
poiché $f$ è lineare, troviamo che la sua immagine è
$$
\begin{align}
f(v)&= f(\lambda_{1}v_{1}+\dots+\lambda_{k}v_{k})=f(\lambda_{1}v_{1})+\dots+f(\lambda_{k}v_{k}) \\
&=\lambda_{1}f(v_{1})+\dots+\lambda_{k}f(v_{k})
\end{align}$$
#Esempio Dati due spazi vettoriali $V, W$ su $\mathbb{K}$, la funzione nulla è la funzione $f:V\to W$ che è costantemente nulla, cioè $f(v)=0, \ \forall v$. La funzione nulla è lineare.
Dato uno spazio vettoriale $V$ su $\mathbb{K}$, la funzione identità è la funzione $id_{v}:V\to V$ che manda ogni vettore in se stesso, $id_{v}(v)=v$.
#Esempio La funzione $f:\mathbb{R}\to \mathbb{R}$ data da $f(x)=3x$ è lineare. Verifichiamo i 3 punti
1. $f(0)=0$
2. $f(x+x')=3(x+x')=3x+3x'=f(x)+f(x')$
3. $f(\lambda x)=3\lambda x=\lambda_{3}x=\lambda f(x)$
Per $k=0$ otteniamo la funzione nulla, per $k=1$ la funzione identità. Non sono lineari le funzioni da $\mathbb{R}$ in $\mathbb{R}$:
$$f(x)=2x+1,\quad\quad f(x)=x^2$$
#Esempio Generalizziamo lo scorso esempio prendendo un campo $\mathbb{K}$ qualsiasi e variando la dimensione del dominio. Siano $a_{1},\dots,a_{n}\in\mathbb{K}$ costanti:
$$f:\mathbb{K^n}\to\mathbb{K},\quad\quad f(x)=a_{1}x_{1}+\dots+a_{n}x_{n}$$
è lineare:
1. $f(0)=a_{1}0+\dots+a_{n}0=0$
2. $f(x+x')=a_{1}(x_{1}+x'_{1})+\dots+a_{n}(x_{n}+x'_{n})=a_{1}x_{1}+\dots+a_{n}x_{n}+a_{1}x'_{1}+\dots+a_{n}x'_{n}=f(x)+f(x')$
3. $f(\lambda x)=a_{1}\lambda x_{1}+\dots+a_{n}\lambda x_{n}=\lambda(a_{1}x_{1}+\dots+a_{n}x_{n})=\lambda f(x)$
#Esempio Generalizziamo ulteriormente. Prendiamo una matrice $A=(a_{ij})$ di taglia $m\times n$:
$$L_{A}:\mathbb{K}^n\to\mathbb{K}^m$$
prodotto fra matrici e vettori:
$$L_{A}(x)=Ax$$
ovvero:
$$
L_{A}(x)=Ax=
\begin{pmatrix}
a_{11} & \dots & a_{1n} \\
\vdots & \ddots & \vdots \\
a_{m1} & \dots & a_{mn}
\end{pmatrix}
\cdot
\begin{pmatrix}
x_{1} \\
\vdots \\
x_{n}
\end{pmatrix}
=
\begin{pmatrix}
a_{11}x_{1}+\dots+a_{1n}+x_{n} \\
\vdots \\
a_{m1}+x_{1}+\dots+a_{mn}+x_{n}
\end{pmatrix}
$$
La linearità di $L_{A}$ discende dalle proprietà delle matrici:
1. $L_{A}(0)=A0=0$
2. $L_{A}(x+x')=A(x+x')=Ax+Ax'=L_{A}(x)+L_{A}(x')$
3. $L_{A}(\lambda x)=A(\lambda x)=\lambda Ax=\lambda L_{A}(x)$
Quindi se $A=\begin{pmatrix}3&-1\\1&2\end{pmatrix}$ otteniamo la funzione $L_{A}:\mathbb{R}^{2}\to\mathbb{R}^2$ data da:
$$L_{A}\dbinom{x}{y}=\dbinom{3x-y}{x+2y}$$
Esaminando le colonne della matrice $A$ si vede subito dove va la base canonica. Ad esempio, se
$$
A=
\begin{pmatrix}
0 & 1 \\
1 & 0
\end{pmatrix}
$$
guardando le colonne capiamo subito che l’applicazione $L_{A}$ scambia i due vettori $e_{1}$ ed $e_{2}$ della base canonica. Effettivamente, scrivendo esplicitamente
$$
L_{A}\dbinom{x}{y}=
\begin{pmatrix}
0 & 1 \\
1 & 0
\end{pmatrix}
\dbinom{x}{y}
=
\dbinom{y}{x}
$$
- Se $A=0$ è matrice nulla, $L_{A}:\mathbb{K}^n\to\mathbb{K}^n$ è applicazione nulla
- Se $A=I_{n}$ è la matrice identità, $L_{A}:\mathbb{K}^n\to\mathbb{K}^n$ è l'identità
## Esempi più elaborati
### TODO
## Nucleo
Sia $f:V\to W$ un'applicazione lineare. Il *nucleo* di $f$ è il sottoinsieme di $V$ definito come:
$$kerf=\{v\in V|f(v)=0\}$$
Il *nucleo* è l'insieme dei vettori che vengono mandati in zero da $f$. È un sottospazio vettoriale di $V$.
Dobbiamo verificare i 3 assiomi di sottospazio:
1. $0\in kerf$, infatti $f(0)=0$
2. $v,w\in ker f\Rightarrow v+w\in kerf$, infetti $f(v+w)=f(v)+f(w)=0+0=0$
3. $v\in kerf,\lambda\in \mathbb{K}\Rightarrow \lambda v\in ker f$, infatti $f(\lambda v)=\lambda f(v)=\lambda0=0$
Ricordiamo che una funzione $f:V \to W$ è iniettiva se $v\neq v'\Rightarrow f(v)\neq f(v')$. Capire se un'applicazione lineare è iniettiva è facile: basta eliminare il nucleo.
## Immagine
Sia $f:V\to W$ un'applicazione lineare. $f$ ha una immagine che indichiamo con $I_{m}f\subset W$, è sottospazio vettoriale di $W$.
Dimostriamo i soliti assiomi
1. $0\in I_{m}f$ perché $f(0)=0$
2. $f(v),f(v')\in I_{m}f\Rightarrow f(v)+f(v')\in I_{m}f$ perché $f(v)+f(v')=f(v+v')$
3. $f(v)\in I_{m}f,\lambda\in \mathbb{K}\Rightarrow \lambda f(v)\in I_{m}f$ perché $\lambda f(v)=f(\lambda v)$
## Teorema della dimensione
#Teorema 
Sia $f:V\to W$ una funzione lineare. Se $V$ ha dimensione finita $n$:
$$dim\ ker\ f+dim\ I_{m}f=n$$
### TODO
## Isomorfismi
Un'applicazione lineare $f:V\to W$ è un *isomorfismo* se è bietiva. Quindi se è suriettiva e iniettiva.
Se $f:V\to W$ è biettiva esiste inversa $f^{-1}:W\to V$.
Valgono i 3 assiomi.
#proposizione Una applicaizone lineare $L_{A}:\mathbb{K}^n\to \mathbb{K}^n$ è un isomorfismo $\iff A$ è invertibile.
- Se $f$ è iniettiva, allora $dim \ V\leq dim\ W$
- Se $f$ è suriettiva, allora $dim\ V\geq dim\ W$
- Se $f$ è biettiva, allora $dim\ V=dim\ W$
Per il teorema della dimensione:
$$f \text{ iniettiva }\iff dim\ ker\ f=0\iff dim\ I_{m}\ f=n\iff f\text{ suriettiva}$$
dove $n=dim\ V=dim\ W$.
## Spazi vettoriali isomorfi
Due spazi $V,W$ sullo stesso campo $\mathbb{K}$ sono isomorfi se $f:V\to W$ è isomorfo.
Per capire ciò basta calcolare le dimensioni. I due spazi sono isomorfi $\iff dim\ V=dim\ W$.
Tutti gli spazi vettoriali su $\mathbb{K}$ di dimensione $n$ sono isomorfi $\mathbb{K}^{n}$.
#Esempio $\mathbb{K}_{n}[k]$ è isomorfo a $\mathbb{K}^{n+1}$ e $M(m,n,\mathbb{K})$ è isomorfo a $\mathbb{K}^{mn}$.
## Matrice associata
Fissiamo una base $B=\{v_{1},\dots,v_{n}\}$ di uno spazio $V$, possiamo rappresentare qualsiasi vettore $v\in V$ come un vettore numerico di coordinate $[v]_{B}\in \mathbb{K}^{n}$. Facciamo lo stesso con le applicazioni lineari.
Sia $f:V\to W$ un'applicazione lineare fra spazi vettoriali definiti su $\mathbb{K}$. Sia inoltre
$$B=\{v_{1},\dots,v_{n}\}, \quad\quad C=\{w_{1},\dots,w_{n}\}$$
due basi di $V$ e di $W$, sappiamo che:
$$
\begin{align}
f(v_{1})&=a_{11}w_{1}+\ldots+a_{m1}w_{m} \\
\vdots \\
f(v_{n})&=a_{1n}w_{1}+\ldots+a_{mn}w_{m}
\end{align}
$$
per qualche insieme di coefficienti $a_{ij}\in \mathbb{K}$. Definiamo la matrice associata a $f$ nelle basi $B$ e $C$ come la matrice $m\times n$:
$$A=(a_{ij})$$
che raggruppa questi coefficienti:
$$A=[f]^B_{C}$$
ci ricorda che $A$ dipende da $f$, da $B$ e da $C$. La $j$-esima colonna di $A$ contiene le coordinate di $f(v_{j})$ rispetto a $C$:
$$
A^j=
\begin{pmatrix}
a_{1j} \\
\vdots \\
a_{mj}
\end{pmatrix}
=[f(v_{j})]_{C}
$$
Valutiamo $L_{A}$.
La matrice associata a $L_{A}$ rispetto alle basi canoniche di $\mathbb{K}^{n}$ e $\mathbb{K}^{m}$ è $A$.
#Esempio 
Consideriamo l'applicazione lineare
$$
f:\mathbb{R}_{2}[x]\longrightarrow \mathbb{R}^2, \quad\quad f(p)=\dbinom{p(2)}{p(-2)}$$
assegna ad ogni polinomio i suoi valori n $2$ e in$-2$. Scriviamo la matrice associata a $f$ nelle basi canoniche $C'=\{1,x,x^{2}\}$ di $\mathbb{R}_{2}[x]$ e $C=\{e_{1},e_{2}\}$ di $\mathbb{R}^{2}$.
$$
f(1)=\dbinom{1}{1},
\quad\quad
f(x)=\dbinom{2}{-2},
\quad\quad
f(x^2)=\dbinom{4}{4}
$$
la matrice associata è:
$$
[f]^{C'}_{C}=
\begin{pmatrix}
1 & 2 & 4 \\
1 & -2 & 4
\end{pmatrix}
$$
Se in arrivo prendiamo la base $B=\{\dbinom{1}{-1},\dbinom{0}{1}\}$ invece della canonica $C$, dobbiamo anche calcolare le coordinate di ciascun vettore immagine rispetto a $B$. Risolvendo i sistemi lineari troviamo:
$$
\begin{align}
&f(1)=\dbinom{1}{1}=\dbinom{1}{-1}+2\dbinom{0}{1}, \\
&f(x)=\dbinom{2}{-2}=2\dbinom{1}{-1}+0\dbinom{0}{1}, \\
&f(x^2)=\dbinom{4}{4}=4\dbinom{1}{-1}+8\dbinom{0}{1}
\end{align}
$$
la matrice associata diventa:
$$
[f]^{C'}_{2}=
\begin{pmatrix}
1 & 2 & 4 \\
2 & 0 & 8
\end{pmatrix}
$$
#Esempio Consideriamo l'applicazione lineare
$$
f:\mathbb{C}^2 \longrightarrow \mathbb{C}^3,
\quad\quad
f(\dbinom{x}{y})=
\begin{pmatrix}
x-y \\
2x \\
y
\end{pmatrix}
$$
la matrice associata a $f$ rispetto alle basi canoniche è quella dei coefficienti:
$$
\begin{pmatrix}
1 & -1 \\
2 & 0 \\
0 & 1
\end{pmatrix}
$$
Se come basi di partenza prendiamo
$$
v_{1}=\dbinom{1}{1},
\quad\quad
v_{2}=\dbinom{1}{-1}
$$
e in arrivo
$$
w_{1}=
\begin{pmatrix}
1 \\
1 \\
0
\end{pmatrix},
\quad\quad
w_{2}=
\begin{pmatrix}
0 \\
1 \\
1
\end{pmatrix},
\quad\quad
w_{3}=
\begin{pmatrix}
1 \\
0 \\
1
\end{pmatrix}
$$
Dobbiamo determinare le coordinate di $f(v_{1})$ e $f(v_{2})$ rispetto alla base $w_{1},w_{2},w_{3}$. Risolvendo i sistemi lineari:
$$
\begin{align}
&f(v_{1})=\begin{pmatrix}
0 \\
2 \\
1
\end{pmatrix}
=\frac{1}{2}\begin{pmatrix}
1 \\
1 \\
0
\end{pmatrix}
+\frac{3}{2}\begin{pmatrix}
0 \\
1 \\
1
\end{pmatrix}
-\frac{1}{2}\begin{pmatrix}
1 \\
0 \\
1
\end{pmatrix}, \\
&f(v_{2})=\begin{pmatrix}
2 \\
2 \\
-1
\end{pmatrix}
=\frac{5}{2}\begin{pmatrix}
1 \\
1 \\
0
\end{pmatrix}
-\frac{1}{2}\begin{pmatrix}
0 \\
1 \\
1
\end{pmatrix}
-\frac{1}{2}\begin{pmatrix}
1 \\
0 \\
1
\end{pmatrix}
\end{align}
$$
quindi la matrice associata a $f$ rispetto alle basi $v_{1},v_{2}$ e $w_{1},w_{2},w_{3}$ è
$$
[f]^{v_{2},v_{2}}_{w_{1},w_{2},w_{3}}=
\begin{pmatrix}
\frac{1}{2} & \frac{5}{2} \\
\frac{3}{2} & -\frac{1}{2} \\
-\frac{1}{2} & -\frac{1}{2}
\end{pmatrix}
=\frac{1}{2}
\begin{pmatrix}
1 & 5 \\
3 & -1 \\
-1 & -1
\end{pmatrix}
$$
## Proprietà
### TODO?
## Matrice di cambiamento di base
Sia $V$ uno spazio vettoriale e $B=\{v_{1},\dots,v_{n}\}$ e $C=\{w_{1},\dots,w_{n}\}$ basi di $V$. La matrice *cambiamento di base* da $B$ a $C$ è:
$$A=[id_{V}]^B_{C}$$
La matrice $A$ rappresenta la funzione identità nelle basi $B$ e $C$:
$$v_{j}=a_{1j}w_{1}+\dots+a_{nj}w_{n} \quad \forall j=1,\dots,n$$
La colonna $j$-esima di $A$ contiene le coordinate di $v_{j}$ rispetto a $C$:
$$A^j=[v_{j}]_{C}$$
La matrice di cambiamento di base $A$ ha nelle sue colonne le coordinate di ciascun elemento di $B$ rispetto a $C$. L’inversa
$$A^-1=[id_{V}]^C_{B}$$
è la matrice di cambiamento di base da $C$ rispetto a $B$.
#proposizione Per ogni $v\in V$ vale
$$[v]_{C}=A[v]_{B}$$
Possiamo usare la matrice di cambiamento di base $A$ per passare agevolmente dalle coordinate dei vettori in $B$ a quelle in $C$.
Sia $f:V\to W$ una applicazione lineare. Siano $B_{1},B_{2}$ basi di $V$ e $\mathbb{C}1,C_{2}$ basi di $W$:
$$
[f]^{b_{2}}_{C_{2}}=[id_{W}]^{C_{1}}_{C_{2}}\cdot[f]^{B_{1}}_{C_{2}}\cdot[id_{V}]^{B_{2}}_{B_{1}}
$$
per passare da $[f]^{B_{1}}_{C_{1}}$ a $[f]^{B_{2}}_{C_{2}}$ basta moltiplicare a destra e sinistra per le matrici di cambiamento di base.
#Esempio Nello scorso esempio abbiamo analizzato un'applicazione lineare $f:\mathbb{R}_{2}[x]\longrightarrow \mathbb{R}^{2}$ e calcolato la matrice associata rispetto alle basi $C'=\{1,x,2^2\}$ e $C=\{e_{1},e_{2}\}$ ottenendo:
$$
[f]^{C'}_{C}=
\begin{pmatrix}
1 & 2 & 4 \\
1 & -2 & 4
\end{pmatrix}
$$
Successivamente abbiamo cambiato $C$ con $B=\{\dbinom{1}{-1},\dbinom{0}{1}\}$. Per ottenere la matrice di cambiamento di base da $B$ a $C$ basta affiancare i vettori di $B$:
$$
[id]^B_{C}=
\begin{pmatrix}
1 & 0 \\
-1 & 1
\end{pmatrix}
$$
calcoliamo l'inversa:
$$
[id]^C_{B}=
\begin{pmatrix}
1 & 0 \\
1 & 1
\end{pmatrix}
$$
quindi la matrice associata a $f$ nelle basi $C'$ e $B$ è:
$$
[f]^{C'}_{B}=[id]^C_{B}[f]^{C'}_{0}=
\begin{pmatrix}
1 & 0 \\
1 & 1
\end{pmatrix}
\begin{pmatrix}
1 & 2 & 4 \\
1 & -2 & 4
\end{pmatrix}
=
\begin{pmatrix}
1 & 2 & 4 \\
2 & 0 & 8
\end{pmatrix}
$$
#Esempio Nell'esempio successivo avevamo considerato un'applicazione lineare $f:\mathbb{C}^{2}\longrightarrow \mathbb{C}^{3}$, calcolato la matrice associata rispetto alle basi canoniche $C$ e $C'$ di $\mathbb{R}^2$ e $\mathbb{R}^3$:
$$
[f]^C_{C'}=
\begin{pmatrix}
1 & -1 \\
2 & 0 \\
0 & 1
\end{pmatrix}
$$
Successivamente abbiamo cambiate entrambe le basi con
$$
B=\{
\begin{pmatrix}
1 \\
1
\end{pmatrix},
\begin{pmatrix}
1 \\
-1
\end{pmatrix}
\},
\quad\quad
B'=\{
\begin{pmatrix}
1 \\
1 \\
0
\end{pmatrix},
\begin{pmatrix}
0 \\
1 \\
1
\end{pmatrix},
\begin{pmatrix}
1 \\
0 \\
1
\end{pmatrix}
\}
$$
calcoliamo le matrici di cambiamento di base:
$$
[id_{\mathbb{C}^2}]^B_{C}=
\begin{pmatrix}
1 & 1 \\
1 & -1
\end{pmatrix},
\quad\quad
[id_{\mathbb{C}^3}]^{B'}_{C'}=
\begin{pmatrix}
1 & 0 & 1 \\
1 & 1 & 0 \\
0 & 1 & 1
\end{pmatrix}
$$
l'inversa della seconda è:
$$
[id_{\mathbb{C}^3}]^{C'}_{B'}=\frac{1}{2}
\begin{pmatrix}
1 & 1 & -1 \\
-1 & 1 & 1 \\
1 & -1 &  1
\end{pmatrix}
$$
infine troviamo
$$
\begin{align}
&[f]^B_{B'}=[id_{\mathbb{C}^3}]^{C'}_{B'}\cdot[id_{\mathbb{C^2}}]^B_{C} \\
&=\frac{1}{1}\begin{pmatrix}
1 & 1 & -1 \\
-1 & 1 & 1 \\
1 & -1 & 1
\end{pmatrix}
\begin{pmatrix}
1 & -1 \\
2 & 0 \\
0 & 1
\end{pmatrix}
\begin{pmatrix}
1 & 1 \\
1 & -1
\end{pmatrix}
=\frac{1}{2}
\begin{pmatrix}
1 & 5 \\
3 & -1 \\
-1 & -1
\end{pmatrix}
\end{align}
$$
## Composizione di applicazioni lineari
Se $f:V\to W$ e $g:W\to Z$ sono funzioni lineari, allora anche la *composizione* $g\circ f:V\to Z$ lo è perché valgono i tre assiomi di linearità.
Per le applicazioni di tipo $L_{A}$ la composizione corrisponde al prodotto fra matrici.
Siano $A\in M(k,m,\mathbb{K})$ e $B\in M(m,n,\mathbb{K})$. Consideriamo $L_{A}:\mathbb{K}^{m}\to\mathbb{K^k}$ e $L_{B}:\mathbb{K}^{n}\to \mathbb{K}^m$ vale la relazione:
$$L_{A}\circ L_{B}=L_{AB}$$
Segue l'associatività del prodotto fra matrici:
$$L_{A}(L_{B}(x))=A(Bx)=(AB)x=L_{AB(x)}$$
## Endomorfismi
Sia $V$ uno spazio vettoriale.
Un *endomorfismo* di $V$ è un'applicazione lineare $f:V\to V$.
In ciascuno spazio vettoriale $V$, la moltiplicazione per un $\lambda\in \mathbb{K}$ fissato $f(v)=\lambda v$ è un endomorfismo.
## Matrice associata
Quando rappresentiamo un endomorfismo $f:V\to V$ come matrice è raginevole prendere la stessa base $B$ per $V$ in partenza e in arrivo. Otteniamo $A=[f]^B_{B}$. Questa rappresentazione trasforma la composizione fra endomorfismi in prodotto di matrici:
$$
[f\circ g]^B_{B}=[f]^B_{B}\cdot[f]^B_{B}
$$
Abbiamo anche visto che se $C$ è un'altra base per $V$ e $M=[id_{V}]^B_{C}$ è la matrice di cambiamento di base da $B$ a $C$:
$$
[f]^B_{B}=M^{-1}[f]^C_{C}M
$$
Ricapitoliamo, se $A$ e $B$ sono matrici associate a $f$ rispetto alle basi $B$ e $C$ e $M$ è la matrice di cambiamento di base, allora:
$$A=M^{-1}BM$$
Il prodotto tra matrici non è commutativo. Le matrici $A$ e $B$ sono ben differenti tra loro.
## Similitudine tra matrici
Lavoriamo con l'anello $M(n)$ delle matrici quadrate $n\times n$. Diciamo che due matrici $A,B\in M(n)$ sono *simili* o *coniugate* se esiste una matrice invertibile $M\in M(n)$ tale che:
$$A=M^{-1}BM$$
Se $A$ e $B$ sono simili scriviamo $A\sim B$.
La *similitudine* è una relazione di equivalenza, dobbiamo dimostrare tre proprietà:
1. $A\sim A$, infatti prendendo $M=I_{n}$ otteniamo $A=I^{-1}_{n}AI_{n}$
2. $A\sim B\Rightarrow B\sim A$, infatti se $A=M^{-1}BM$, allora moltiplicando entrambi i membri a sinistra per $M$ e a destra per $M^{-1}$ troviamo $B=MAM^{-1}$, e definendo $N=M^{-1}$ otteniamo $B=N^{-1}AN$
3. $A\sim B,B\sim C\Rightarrow A\sim C$, infatti:
	$A=M^{-1}BM,B=N^{-1}CN\Rightarrow A=M^{-1}N^{-1}CNM=(NM)^{-1}C(NM)$
# Autovalori e Autovettori
Sia $T:V\to V$ un endomorfismo di uno spazio vettoriale $V$ definito su un campo $\mathbb{K}$. Un *autovettore* di $T$ è un vettore $v\neq 0$ in $V$ per cui
$$T(v)=\lambda v$$
per qualche scalare $\lambda\in\mathbb{K}$ che chiameremo *autovalore* di $T$ relativo a $v$. $\lambda$ può essere qualsiasi scalare, anche $0$. Un *autovettore* è un vettore $\neq 0$ che viene mandato da $T$ in un multiplo di se stesso.
#Esempio Consideriamo l'endomorfismo $L_{A}:\mathbb{R}^{2\to}\mathbb{R}^2$ con
$$
A=
\begin{pmatrix}
3 & 4 \\
0 & 2
\end{pmatrix}
$$
Poiché $L_{A}(e_{1})=3e_{1}$, il vettore $e_{1}$ è l'autovettore di $L_{A}$ con autovalore $3$. Notiamo che $L_{A}\dbinom{-1}{1}=\dbinom{-8}{2}=2\dbinom{-4}{1}$ e quindi il vettore $dbinom{-4}{1}$ è autovettore con autovalore $2$.
#Esempio 
Sia $V$ uno spazio vettoriale su $\mathbb{K}$. Fissiamo $\lambda\in \mathbb{K}$ e definiamo l'endomorfismo $f:V\to V,f(v)=\lambda v$. Tutti i vettori non nulli di $V$ sono autovettori con lo $\lambda$.
#Esempio 
Sia $L_{A}:\mathbb{R}^{2}\to \mathbb{R}^{2}$ con $A=Rot_{\theta}$ una rotazione di angono $\theta \neq 0, \pi$. Ciascun vettore $v\in \mathbb{R}^{2}$ diverso da zero viene ruotato di $\theta \neq 0,\pi$ e quindi chiaramente la sua immagina $L_{A}(v)$ non può essere multiplo di $v$. L'endomorfismo $L_{A}$ non ha autovettori.
## Endomorfismi diagonalizzabili
#Definizione 
Un endomorfismo $T:V\to V$ è diagonalizzabile se $V$ ha una base $B=\{v_{1},\dots,v_{n}\}$ composta da autovettori per $T$. Il termine “diagonalizzabile” è dovuto al fatto seguente, che è cruciale. Sia $B=\{v_{1},\dots,v_{n}\}$ una base qualsiasi di $V$.
La matrice associata $A=[T]^B_{B}$ è diagonale se e solo se i vettori $v_{1},\dots,v_{n}$ sono tutti autovettori per $T$.
#Dimostrazione 
Il vettore $v_{i}$ è un autovettore $\iff f(v_{i})=\lambda_{i}v_{i}$ per qualche $\lambda_{i}\in\mathbb{K}\iff[f(v_{i})]_{B}=\lambda_{i}e_{i}$. Capita per ogni $i=1,\dots,n\iff A$ è diagonale, con gli autovalori sulla diagonale principale:
$$
A=
\begin{pmatrix}
\lambda_{1} & 0 & \cdots & 0 \\
0 & \lambda_{2} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \dots & \lambda_{n}
\end{pmatrix}
$$
Quindi un endomorfismo $T$ è diagonalizzabile se e solo se esiste una base $B$ tale che $A=[T]^B_{B}$ sia una matrice diagonale. Quindi quando $B$ è una base di autovettori e gli elementi sulla diagonale principale di $A$ sono precisamente i loro autovalori.
## Matrici diagonali
Un endomorfismo $T:V\to V$ è diagonalizzabile precisamente quando esiste una base $B$ rispetto alla quale la matrice associata $A=[T]^B_{B}$ è diagonale. Preferiamo le matrici diagonali perché sono facili da maneggiare.
Il prodotto $Ax$ tra una matrice quadrata $A$ e un vettore $x$ si semplifica se $A$ è diagonale:
$$
\begin{pmatrix}
\lambda_{1} & 0 & \cdots & 0 \\
0 & \lambda_{2} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \lambda_{n}
\end{pmatrix}
\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix}
=
\begin{pmatrix}
\lambda_{1}x_{1} \\
\lambda_{2}x_{2} \\
\vdots \\
\lambda_{n}x_{n}
\end{pmatrix}
$$
Quindi se $[T]^B_{B}$ è diagonale è facile calcolare le immagini dei vettori. Inoltre il determinante è il prodotto degli elementi sulla diagonale principale:
$$\det(A)=\lambda_{1}\dots \lambda_{n}$$
Anche il prodotto fra matrici è semplica
$$
\begin{pmatrix}
\lambda_{1} & 0 & \cdots & 0 \\
0 & \lambda_{2} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \lambda_{n}
\end{pmatrix}
\begin{pmatrix}
\mu_{1} & 0 & \cdots & 0 \\
0 & \mu_{2} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \mu{n}
\end{pmatrix}
=
\begin{pmatrix}
\lambda_{1}\mu_{1} & 0 & \cdots & 0 \\
0 & \lambda_{2}\mu_{2} & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \lambda_{n}\mu_{n}
\end{pmatrix}
$$
## Matrici diagonalizzabili
Una matrice $A\in M(n,\mathbb{K})$ è *diagonalizzabile* se è simile ad una matrice diagonale $D$.
Quindi $A$ è diagonalizzabile $\iff$ esiste $M$ invertibile tale che
$$D=M^{-1}AM$$
sia diagonale.
#proposizione 
Sia $B$ una base di $V$. Un endomorfismo $T:V\to V$ è diagonalizzabile $\iff$ la matrice associata $A?[T]^B_{B}$ è diagonalizzabile.
#Corollario $A$ è diagonalizzabile $\iff L_{A}$ è diagonalizzabile.
## Polinomio caratteristico
Come facciamo a capire se un dato endomorfismo $T$ sia diagonalizzabile? Come possiamo trovare una base $B$ che diagonalizzi $T$, se esiste? In generale, come troviamo gli autovettori di un endomorfismo $T$?
Uno strumento cruciale a questo scopo è il *polinomio caratteristico*.
#Definizione 
Sia $A\in M(n,\mathbb{K})$. Il *polinomio caratteristico* di $A=a_{ij}$ è definito nel modo:
$$
p_{A}(\lambda)=\det(A-\lambda I_{n})=\det
\begin{pmatrix}
a_{11}-\lambda & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22}-\lambda & \cdots & a_{2n} \\
\cdots & \cdots & \ddots & \vdots \\
a_{n1} & a_{n2} & \cdots & a_{nn}-\lambda
\end{pmatrix}
$$
normalmente un polinomio viene indicato con il simbolo $p(x)$, in cui $x$ rappresenta la variabile. Il pedice $A$ in $p_{A}$ indica che il polinomio dipende dalla matrice A e a volte può essere omesso.
#proposizione Il polinomio caratteristico $p_{A}(\lambda)$ è effettivamente un polinomio. Ha grado $n$ e quindi è nella forma:
$$
p_{A}(\lambda)=a_{n}\lambda^n+a_{n-1}\lambda^{n-1}+\dots+a_{0}
$$
alcuni suoi coefficienti:
- $a_{n}=(-1)^{n}$
- $a_{n-1}=(-1)^{n.-1}trA$
- $a_{0}=\det(A)$
#Dimostrazione In caso $n=1$ \lambdamatrice $A=(a)$ è
$$p_{A}(\lambda)=\det(A-\lambda I)=\det(a-\lambda)=a-\lambda=-\lambda+a$$
Otteniamo un polinomio di grado $1$ con coefficienti giusti. Il caso $n=2$ è istruttivo: qui $A=\begin{pmatrix}a&b\\c&d\end{pmatrix}$ e quindi:
$$
\begin{align}
p_{A}(\lambda)&=\det
\begin{pmatrix}
a-\lambda & b \\
c & d-\lambda
\end{pmatrix}
=(a-\lambda)(d-\lambda)-bc\\
&=\lambda^2-(a+d)\lambda+ad-bc=\lambda^2-trA\lambda+\det(A)
\end{align}
$$
## Le radici del polinomio caratteristico
Sia $V$ uno spazio di dimensione $n$ e $T:V\to V$ un endomorfismo.
Gli autovalori di $T$ sono precisamente le radici del polinomio caratteristico $p_{T}(\lambda)$.
#Dimostrazione Scegliamo una base $B$ e scriviamo $A=[T]^B_{B}$. Uno scalare $\lambda\in\mathbb{K}$ è autovalore per $T$ se e solo se esiste $x\in \mathbb{K}^{n}$ non nullo tale che $Ax=\lambda x$. I fatti sono equivalenti:
$$
\begin{align}
&\exists x\neq 0\text{ tale che }Ax-=\lambda x \iff \\
&\exists x\neq 0\text{ tale che }Ax-\lambda x=0 \iff \\
&\exists x\neq 0\text{ tale che } (A-\lambda I_{n})x=0 \iff \\
&\exists x\neq 0\text{ tale che }x\in ker(A-\lambda I_{n})\iff \\
&\det(A-\lambda I_{n})=0\iff p_{A}(\lambda)=0
\end{align}
$$
#Esempio Consideriamo l'endomorfismo $L_{A}:\mathbb{R}^2\to \mathbb{R}^2$ con
$$
A=
\begin{pmatrix}
-1 & 2 \\
-4 & 5
\end{pmatrix}
$$
il polinomi caratteristico è
$$p_{A}(\lambda)=\lambda^2-trA\lambda+\det(A)=\lambda^2-4\lambda+3$$
le radici sono $\lambda=1$ e $\lambda=3$. Quindi gli autovalori di $A$ sono $1$ e $3$. Per ciascun autovalore $\lambda=1$ e $\lambda=3$, gli autovettori relativi sono precisamente le soluzioni non banali dei sistemi $A\dbinom{x}{y}=\dbinom{x}{y}$ e $A\dbinom{x}{y}=3\dbinom{x}{y}$.
Ovvero:
$$
\begin{cases}
\begin{align}
-x+2y&=x \\
-4x+5y&=y
\end{align}
\end{cases}
$$
$$
\begin{cases}
\begin{align}
-x_{2}y&=3x \\
-4x+5y&=3y
\end{align}
\end{cases}
$$
sono due sistemi omogenei e le soluzioni rispettive sono due rette
$$
Span\dbinom{1}{1}, \quad\quad Span\dbinom{1}{2}
$$
Due generatori qualsiasi di queste rette ($v_{1}=\dbinom{1}{1}$ e $v_{2}=\dbinom{1}{2}$) formano una base di autovettori per $L_{A}$. La matrice $A$ è quindi diagonalizzabile, ed è simile alla matrice $D=\begin{pmatrix}1&0\\0&3\end{pmatrix}$. Con $M=\begin{pmatrix}1&1\\1&2\end{pmatrix}$ otteniamo $D=M^{-1}AM$.
## Autospazio
Sia $T:V\to V$ un endomorfismo. Per ogni autovalore $\lambda$ di $T$ definiamo l'*autospazio* $V_{\lambda}\subset V$ nel modo:
$$V_{\lambda}=\{v\in V|T(v)=\lambda v\}$$
L'*autospazio* $V_{\lambda}$ consiste precisamente di tutti gli autovettori $v$ con autovalore $\lambda$, più l'origine $0\in V$ ($0\in V$ non è autovalore per definizione).
Per ogni autovalore $\lambda$ di $T$ abbiamo
$$V_{\lambda}=ker(T-\lambda id)$$
#Dimostrazione 
$$
\begin{align}
V_{\lambda}&=\{v\in V|T(v)=\lambda v\}=\{v\in V|T(v)-\lambda v=0\} \\
&=\{v\in V|(T-\lambda id)v=0\}=ker(T-\lambda id)
\end{align}
$$
L'autospazio $V_{\lambda}$ è un sottospazio vettoriale di $V$.
## Molteplicità algebrica e geometrica
Per enunciare il teorema di diagonalizzabilità abbiamo bisogno di introdurre due ultime definizioni.
In tutta questa sezione $V$ è uno spazio vettoriale di dimensione $n$.
Sia $T:V\to V$ un endomorfismo e sia $\lambda$ un autovalore per $T$. La *molteplicità algebrica* $m_{a}(\lambda)$ è la molteplicità di $\lambda$ come radice del polinomio caratteristico $p_{T}$. La *molteplicità geometrica* $m_{g}(\lambda)$ è la dimensione dell'autospazio associato a $\lambda$, ovvero:
$$m_{g}(\lambda)=dimV_{k}$$
#Esempio Sia $L_{A}:\mathbb{R}^{2}\to \mathbb{R}^{2}$ l'endomorfismo dato da
$$
A=
\begin{pmatrix}
1 & 1 \\
0 & 1
\end{pmatrix}
$$
Il polinomio caratteristico è $p_{A}(\lambda)=\lambda^2-2\lambda+1=(\lambda-1)^2$. Troviamo un solo autovalore $\lambda_{1}=1$, con molteplicità algebrica $m_{a}(1)=2$. Inoltre
$$m_{g}(1)=dimV_{1}=dim\ ker(A-I_{2})=dim\ ker\begin{pmatrix}0&1\\0&0\end{pmatrix}=1$$
Abbiamo quindi trovato
$$m_{a}(1)=2,\quad\quad m_{g}(1)=1$$
#proposizione 
Sia $T:V\to V$ un endomorfismo. Per ogni autovalore $\lambda_{0}$ di $T$ valgono le disuguaglianze:
$$1\leq m_{g}(\lambda_{0})\leq m_{a}(\lambda_{0})$$
## Teorema di diagonalizzabilità
#Teorema 
Un endomorfismo $T:V\to V$ è *diagonalizzabile* se e solo se valgono entrambi i fatti:
1. $p_{T}(\lambda)$ ha $n$ radici in$\mathbb{K}$, contate con molteplicità
2. $m_{a}(\lambda)=m_{g}(\lambda)$ per ogni autovalore $\lambda$ di $T$
#Dimostrazione 
Sappiamo che gli autospazi sono in somma diretta e definiamo il sottospazio $W\subset V$ come la loro somma
$$W=V_{\lambda_{1}}\oplus\dots \oplus V_{\lambda_{k}}$$
Sappiamo che $T$ è diagonalizzabile $\iff W=V\iff dim\ W=n$. Inoltre
$$
\begin{align}
dim\ W&=dim\ V_{\lambda_{1}}+\dots +dim\ V_{\lambda_{k}}=m_{g}(\lambda_{1})+\dots+m_{g}(\lambda_{k}) \\
&\leq m_{a}(\lambda_{1})+\dots+m_{a}(\lambda_{k})\leq n
\end{align}
$$
#Esempio Studiamo la diagonalizzabilità su $\mathbb{R}$ della matrice
$$
A=
\begin{pmatrix}
3 & 0 & 0 \\
-4 & -1 & -8 \\
0 & 0 & 3
\end{pmatrix}
$$
il polinomio caratteristico è
$$
p_{A}(\lambda)=(3-\lambda)(-1-\lambda)(3-\lambda)
$$
ha radici $\lambda_{1}=3$ con $m_{a}(\lambda_{1})=2$ e $\lambda_{2}=-1$ con $m_{a}(\lambda_{2})=1$. Le radici di $p_{A}(\lambda)$ sono reali, quindi $A$ è diagonalizzabile se e solo se le molteplicità algebriche e geometriche di ciascun autovalore coincidono.
Concentriamoci sull'autovalore $\lambda_{1}$ che ha $m_{a}(\lambda_{1})=2$. $m_{g}(\lambda_{1})$ può essere $1$ oppure $2$: nel primo caso $A$ noin è diagonalizzabile, nel secondo si:
$$
\begin{align}
m_{g}(3)&=3-rk
\begin{pmatrix}
3-3 & 0 & 0 \\
-4 & -1-3 & -8 \\
0 & 0 & 3-3
\end{pmatrix} \\
&=3-rk
\begin{pmatrix}
0 & 0 & 0 \\
-4 & -4 & -8 \\
0 & 0 & 0
\end{pmatrix}
=3-1=2
\end{align}
$$
$m_{a}(\lambda_{1})=m_{g}(\lambda_{1})=2$ e quindi $A$ è diagonalizzabile.
# Prodotti scalari
Sia $V$ uno spazio vettoriale reale.
#Definizione 
Un *prodotto scalare* su $V$ è una applicazione
$$
\begin{align}
V\times V&\longrightarrow\mathbb{R} \\
(v,w)&\longmapsto \langle v,w\rangle
\end{align}
$$
che soddisfa i seguenti assiomi:
1. $\langle v+v',w\rangle=\langle v,w\rangle+\langle v',w \rangle$
2. $\langle \lambda v,w\rangle=\lambda\langle v,w\rangle$
3. $\langle v,w+w'\rangle=\langle v,w\rangle+\langle v+w'\rangle$
4. $\langle v,\lambda w\rangle=\lambda\langle v,w\rangle$
5. $\langle v,w\rangle=\langle w,v\rangle$
per ogni $v,v',w,w'\in V$ e ogni $\lambda\in\mathbb{R}$.
Il prodotto scalare è una applicazione che prende come input due vettori $v, w \in V$ e restituisce come output uno scalare, che indichiamo con $\langle v,w\rangle$.
## Prodotto scalare degenere e definito positivo
Un prodotto scalare su $V$ è:
- *degenere* se esiste $v\neq 0$ tale che $\langle v,w\rangle=0$ per ogni $w\in V$
- *definito positivo* se $\langle v,w\rangle>0$ per ogni $v\in V$ non nullo
Se un prodotto scalare è definito positivo, allora non è degenere.
## Prodotto scalare euclideo
#Definizione Il prodotto scalare euclideo su $\mathbb{R}^{n}$ è definito come
$$\langle x,y\rangle=\prescript{t}{}{x}\cdot y$$
Nell'espressione $\prescript{t}{}{x}\cdot y$ il vettore $\prescript{t}{}{x}$ è un vettore riga e $\cdot$ indica il prodotto fra matrici, ovvero:
$$
x=
\begin{pmatrix}
x_{1} \\
\vdots \\
x_{n}
\end{pmatrix},
\quad\quad
y=
\begin{pmatrix}
y_{1} \\
\vdots \\
y_{n}
\end{pmatrix}
$$
allora
$$
\langle x,y\rangle=(x_{1},\dots,x_{n})\cdot \begin{pmatrix}
y_{1} \\
\vdots \\
y_{n}
\end{pmatrix}
=x_{1}y_{1}+\dots+x_{n}y_{n}
$$
#Esempio il prodotto scalare fra i vettori $\dbinom{1}{3}$ e $\dbinom{-2}{1}$ di $\mathbb{R}^{2}$ è
$$
\begin{pmatrix}
1 & 3
\end{pmatrix}
\begin{pmatrix}
-2 \\
1
\end{pmatrix}
=1\cdot(-2)+3\cdot 1=1
$$
## Matrici simmetriche
La matrice quadrata $A\in M(n,\mathbb{R})$ determina l'endomorfismo $L_{A}:\mathbb{R}^{n}\to \mathbb{R}^{n}$, e che tutti gli endomorfismi di $\mathbb{R}^{n}$ sono di questo tipo. . Analogamente, vediamo che una matrice simmetrica $S\in M(n,\mathbb{R})$ determina un prodotto scalare $g_{S}$ su $\mathbb{R}^{n}$. Una matrice $S\in M(n)$ è simmetrica se $\prescript{t}{}{S}=S$.
$$
\prescript{t}{}{(AB)}=\prescript{t}{}{B}\ \prescript{t}{}{A}
$$
Una matrice simmetrica $S$ definisce un prodotto scalare $g_{S}$ su $\mathbb{R}^{n}$:
$$g_{S}(x,y)=\prescript{t}{}{x}\cdot S \cdot y$$
le tre matrici hanno taglia $1\times n,n\times n$ e $n\times 1$, quindi $\prescript{t}{}{x}Sy$ ha come risultato una matrice $1\times 1$, un numero.
Ogni matrice simmetrica $S$ determina quindi un prodotto scalare $g_{S}$ su $\mathbb{R}^{n}$.
## Matrice associata
Sia $V$ uno spazio vettoriale reale e
$$g:V\times V\longrightarrow \mathbb{R}$$
un prodotto scalare. Sia $B=\{v_{1},\dots,v_{n}\}$ una base per $V$.






