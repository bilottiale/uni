# Numeri reali
## Insiemi
### Insiemi numerici
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
## Lo spazio






LEZIONE 04: Polinomi (1.3.1-1.3.3, 1.4.7, 1.4.8)





