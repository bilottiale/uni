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
### Unione, intersezione e differenza
#### Leggi di De Morgan
Siano $A$ e $B$ due sottoinsiemi di un insieme $C$. Valgono le seguenti uguaglianze:
$$
\begin{align}
&(A\cap B)^{C}=A^{C}\cup B^{C} \\
&(A\cup B)^{C}=A^{C}\cap B^{C}
\end{align}
$$
Con $X^{C}$ complementare di $X$ in $C$, cioè $X^{C}=C\setminus X$.
### Prodotto cartesiano
Il prodotto cartesiano di due insiemi $A$ e $B$ è un nuovo insieme $A\times B$ i cui elementi sono tutte le coppie $(a,b)$ dove $a$ è un elemento di $A$ e $b$ un elemento di $B$:
$$A\times B=\{(a,b)|a\in A,b\in B\}$$
#Esempio $A=\{1,2\}, B=\{-1,3,4\}$
$$A\times B=\{(1,-1),(1,3),(1,4),(2,-1),(2,3),(2,4)\}$$
### Relazione di equivalenza
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
### Gruppi
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
### Anelli
Negli insiemi numerici $\mathbb{Z,Q,R}$ e $\mathbb{C}$ ci sono in realtà due operazioni $+$ e $\times$. Introduciamo una struttura che prevede la coesistenza di due operazioni binarie.
Un *anello* è un insieme $A$ dotato di due operazioni binarie $+$ e $\times$ che soddisfano:
1. $A$ è un gruppo commutativo con l'operazione $+$
2. $a\times(b\times c)=(a\times b)\times c \ \forall a,b,c\in A$ (associatività)
3. $a\times(b+c)=(a\times b)+(a\times c)\ \forall a,b,c \in A$ (distributività)
4. $\exists 1\in A: 1\times a=a\times 1=a \ \forall a\in A$ (elemento neutro)
### Campi
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
![[Pasted image 20231213184224.png|500]]
![[Pasted image 20231213184538.png|500]]
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
![[Pasted image 20231213204126.png|500]]
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
![[Pasted image 20231213215133.png|500]]
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






