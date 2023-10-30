[[README]]
[[Simbologia]]
[[Lettere]]
[[Algebra]]
![[MatematicaDiscreta_AMori.pdf]]
## Indice
[[Matematica Discreta#Insiemistica|Insiemistica]]
# Insiemistica
Un insieme è una collezione *ben definita*(determinabile se un oggetto appartiene o meno all'insieme) di oggetti detti elementi dell'insieme.
[[Algebra#Numeri reali|Algebra - Numeri reali]]
$$\mathbb{N} = \{naturali\}$$
$$\mathbb{Z} = \{interi\}$$
$$\mathbb{Q} = \{razionali\}$$
$$\mathbb{R} = \{reali\}$$
$$\mathbb{C} = \{complessi\}$$
Sia $x$ un elemento di $A$ si scrive
Appartiene:
$$x \in A$$
Non appartiene
$$x \notin A$$
Cardinalità: numeri di elementi di $A$
$$|A|$$
Un insieme $B$ è un sottoinsieme di $A$, se ogni elemento di $B$ è anche un elemento di $A$:
$$B \subseteq A$$
$$B \not\subseteq A$$
#Esempio Sia $A$ un insieme allora:
$$x \in A \Leftrightarrow \{x\} \subseteq A$$
$\Leftrightarrow$ se e solo se
Due insiemi $A$ e $B$ sono uguali se e solo se
$$A \subseteq B $$
$$B \subseteq A$$
Sia $A$ un insieme, si dice insieme delle parti di $A$:
$$P(A)=\{B|B\subseteq A\}$$
#Esempio $A = \{a, b\}$
$$P(A)=\{ \varnothing, \{a\},\{b\},\{a,b\}\}$$
## Intersezione e unione
1. Siano $A$ e $B$ insiemi, l'*intersezione* è:
$$A \cap B = \{ x | x \in A \land x \in B \}$$
![[Pasted image 20231028185707.png|250]]
$A$ e $B$ si dicono *disgiunti* se:
$$A \cap B = \varnothing$$
- Sia $I = \{ 1, \dots, n \}$
- $A_i$ un insieme per $i \in I$
L'intersezione di tutti $A_{i} = \{A_{1} \cap A_{2}\cap \dots \cap A_{n}\} = \{ x | x \in A  \forall i \in I \}$
2. L'*unione* di $A$ e $B$ è:
$$A \cup B = \{ x|x \in A \lor x \in B \}$$
![[Pasted image 20231028185653.png|250]]
- Sia $I = \{ 1, \dots, n \}$
- $A_i$ un insieme per $i \in I$
L'unione di tutti $A_{i} = \{A_{1} \cup A_{2}\cup \dots \cup A_{n}\} = \{ x | \exists i \in I, x \in A_i \}$
$\exists \rightarrow \text{esiste}$
### Principio di inclusione-esclusione
$$\mid A\cup B\mid=\mid A\mid+\mid B\mid-\mid A\cap B\mid$$
![[Pasted image 20231028185606.png|250]]
#Esercizio 
- $A = 180$ studenti che seguono il corso quest'anno
- $B=40$ studenti che seguivano il corso l'anno scorso
- $A\cap B=7$ studenti che hanno seguito entrambi gli anni
Quanti studenti hanno seguito ALMENO un anno?
$$\mid A\cup B\mid=\mid A\mid+\mid B\mid-\mid A\cap B\mid=180+40-7=213$$
*Con tre insiemi*
![[Pasted image 20231028190042.png|250]]
$$\mid A\cup B\cup C\mid=\mid A\mid+\mid B\mid+\mid C\mid-\mid A\cap B\mid-A\cap C\mid-\mid B\cap C\mid+\mid A\cap B\cap C\mid$$
#Esercizio 
- $A=10$ amici vogliono la pizza
- $B=8$ amici vogliono un gelato
- $C=15$ amici vogliono la bagna cauda
- $A\cap B=2$ amici vogliono la pizza *e* il gelato
- $B\cap C=1$ amici vogliono bagna cauda *e* gelato
- $A\cap C=5$ amici vogliono pizza *e* bagna cauda
- $A\cap B\cap C=1$ amici voglio *tutti* e tre
Quanti sono gli amici?
$$\mid A\cup B\cup C\mid=10+8+15-2-1-5+1=26$$
## Proprietà degli insiemi
Dati $A, B, C$
- *Associativa*
	- $(A \cap B) \cap C = A \cap (B \cap C)$
	- $(A \cup B) \cup C = A \cup (B \cup C)$
- *Idempotente*
	- $A \cap A = A, A \cap \varnothing = \varnothing$
	- $A \cup A = A, A \cup \varnothing = A$
- *Distributiva*
	- $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
	- $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$

## Differenza
Dati $A$ e $X$ la differenza tra di loro è un sottoinsieme di $X$:
$$X \setminus A = \{ x \in X | x \not\in A \}$$
![](https://www.youmath.it/images/stories/Insiemi/Diagramma-di-Eulero-Venn-per-la-differenza-tra-insiemi.png)
## Insieme complementare
Sia $A$ un sottoinsieme di $X$ un *complementario* di $A$ in $X$ è:
$$C_{x}(A) := \{ x \in X | x \not\in A \} = X \setminus A$$
$$C_{x}(A) = \bar{A} \rightarrow \text{complementare}$$
## Legge di De Morgan
Siamo $A$ e $B$ sottoinsiemi di $X$:
$$C_{x}(A\cap B) = C_{x}(A) \cup C_{x}(B)$$
![](https://www.youmath.it/images/stories/Insiemi/prima-legge-di-de-morgan-1.png)
$C_{x}(A \cup B) = C_{x}(A) \cap C_{x}(B)$
![](https://www.youmath.it/images/stories/Insiemi/seconda-legge-di-de-morgan-1.png)
## Ricoprimento di un insieme
Siano $A_{1}, A_{2}, \dots, A_{n}$ sottoinsiemi di $A$,
$$\{ A_{i}\}_{i=1}^{n} = \{ A_{1}, \dots, A_{n} \}$$
È un *ricoprimento* di $A$ se:
$$\cup_{i=1}^{n}A_{i}(A_{1} \cup A_{2} \cup \dots \cup A_{n}) = A$$
#Esempio $A = \mathbb{Z}$
$$A_{1} = \{\text{numeri interi pari}\}$$
$$A_{2} = \{\text{numeri interi dispari}\}$$
$$A = A_{1} \cup A_{2}, \{A_{1}, A_{2}\}$$
## Partizione di un insieme
Una *partizione* di un insieme $A$ è un ricoprimento di $A$ tale che: $\{A_{i}\}_{i=1}^n$
1. $A_{i} \neq \varnothing$
2. $A_{i} \cap A_{j} = \varnothing, \forall i,j \in \{i, \dots, n \}$
#Esempio
$$\mathbb{Z} = \{ \text{numeri interi}\}$$
$$A_{1} = \{ \text{numeri interi pari} \}$$
$$A_{2} = \{ \text{numeri interi dispari} \}$$
$$A_{1} \cap A_{2} = \varnothing$$
$$\{A_{1}, A_{2} \} \text{è una partizione di } \mathbb{Z}$$
## Prodotto Cartesiano
Dati $A$ e $B$, il *prodotto cartesiano* è:
$$A\times B := \{ (a,b) | \forall a \in A, b \in B \}$$
#Esempio $A = \{ 1,2,3 \}, B = \{ 2,4 \}$
$$A \times B =
\begin{Bmatrix}
   (1,2), & (1,4) \\
   (2,2), & (2,4) \\ 
   (3,2), & (3,4) \\
\end{Bmatrix}$$
#Esempio Su piano cartesiano
$$[ 0,1 ] := \{ x \in \mathbb{R} | 0 \leq x \leq 1 \}$$
$$[ -1,0 ] := \{ y \in \mathbb{R} | -1 \leq y \leq 0 \}$$
### !TODO: IMMAGINE $[0,1]\times[-1,0]$
#Esercizio 
$A = \{1,2,3\}$

$\varnothing \in A$ FALSO
$\{\varnothing\}\subseteq A$ FALSO
$\varnothing \subseteq A$ VERO
**?** Tra i numeri da $1,\dots,600$ quanti sono i numeri che non sono divisibili per $2$ e $3$?
$C_{x}(A \cap B) = 100$
# Funzioni
Siano $A,B$ insiemi non vuoti, una *funzione* $f$ con *dominio* $A$ e *codominio* $B$, è il dato di un sottoinsieme $\Gamma \subseteq A\times B$ tale che:
$$\forall a\in A\quad \exists!b\in B \ t.c\ (a,b)\in\Gamma$$
$\Gamma$ è detto *grafico* della funzione.
Per indicare che $f$ è una funzione da $A$ a $B$, si usa
$$f:A\to B$$
Fissato un elemento $a\in A$, per indicare che $b$ è l'unico elemento di $B$ t.c. $(a,b)\in\Gamma$ si scrive $b=f(a)$ e si dice che $b$ è l'*immagine* di $a$.
## Immagine di una funzione
Si dice *immagine* di una funzione $f:A\to B$ e si denota con $f(A)$ il sottoinsieme di $B$ degli elementi che sono immagine di qualche elemento di $A$, ossia:
$$Im=\{b\in B\mid b=f(a), \text{ per qualche }a\in A\}$$
#Esempio 
Siano $A=\{0,1,2\}$ e $f,g:A\to \mathbb{R}$ le funzioni definite:
$$f(x)=x-7\quad g(x)=x^{3}-3x^{2}+3x-7$$
Sono evidentemente descritte da leggi diverse, ma sono la stessa funzione in quando hanno lo stesso dominio $A$, lo steso codominio $\mathbb{R}$ e lo stesso grafico $\Gamma_{f}=\Gamma_{g}=\{(0,-7),(1,-6),(2,-5)\}$

Possiamo quindi affermare che *due funzioni sono equivalenti se hanno stesso dominio, stesso codominio e stesso grafico*.
### Esempi importanti di funzioni
*Funzione costante*:
Siano $A,B$ due insiemi e $b\in B$ un elemento fissato
La funzione costante con valore $b$ è:
$$f_{b}:A\to B \quad f(a)=b \quad \forall a\in A$$
Il suo grafico è $\Gamma=A\times \{b\}\subseteq A\times B$
*Funzione identità*:
Dato un insieme $A$, la funzione identità su $A$ è:
$$id_{A}: A\to A\quad id_{A}(a)=a \quad \forall a\in A$$
Il suo grafico è $\Gamma=\{(a,a)\in A \times A\mid a\in A\}$
*Proiezione su un fattore*
Siano $A,B$ insiemi e $A \times B$ il loro prodotto cartesiano, la funzione proiezione sul primo fattore è:
$$p_{1}:A \times B\to A$$
definita da $p_{2}((a,b))=b$
*Successione*
Una successione è una funzione $f:\mathbb{N} \to B$
Il termine $n$-esimo $b_{n}$ della successione è l'immagine $f(n)$ del numero naturale $n$.
In altre parole: una successione $b_{0},b_{1},b_{2},\dots$ in un insieme $B$ è il dato di una funzione
$$
\begin{align}
s:\mathbb{N}, \quad &S(0)=b_{0} \\
&S(1)=b_{1} \\
&S(2)=b_{2} \\
&\vdots
\end{align}
$$
*Proiezione sul quoziente*
Sia $X$ un insieme e sia $X=\bigcup\limits_{i=1}A_{i}$ la sua partizione; indichiamo con $Q$ il relativo quoziente.
Si dice *proiezione* di $X$ sul quoziente la funzione
$$q:X\to Q$$
definita da $q(x)=A_{i}$
Con $A_{i}$ l'unico sottoinsieme della partizione t.c. $x\in A_{i}$
*Osservazione*: $\forall x\exists!A_{i}\in Q\text{ t.c. }x\in A_{i}$
## Immagine e Controimmagine
### Immagine
Sia $f:A\to B$ una funzione, si dice *immagine* di $f$ e si denota $Im(f)$:
$$Im(f)=f(A)$$
### Controimmagine
Sia $f:A\to B$ una funzione e sia $b\in B$, si dice *controimmagine* di $b$ il sottoinsieme di $A$:
$$f^{-1}(b)=\{a\in A\mid f(a)=b\}$$
## Funzione iniettiva
Una funzione si dice *iniettiva* se elementi distinti del dominio $A$ hanno immagini distinte in $B$:
$$\forall a_{1},a_{2}\in A:a_{1}\neq a_{2}\implies f(a_{1})\neq f(a_{2})$$
![[Pasted image 20231028140906.png|450]]
## Funzione suriettiva
Una funzione si dice *suriettiva* se ogni elemento del secondo ineieme è raggiunto da almeno una freccia che parte dal primo insieme:
$$Im(f)=B \text{ ossia se: }\forall b\in B \quad \exists a\in A \quad \text{ t.c. }f(a)=b$$
![[Pasted image 20231028140839.png|450]]
## Funzione biiettiva
Una funzione si dice *biiettiva* se è sia *iniettiva* che *suriettiva*.
#proposizione 
1. $f$ è inietiva $\iff \forall b\in B \quad f^{-1}(b)\neq \varnothing$
	1. $f^{-1}(b)$ contiene almeno un elemento
2. $f$ è suriettiva $\iff \forall b\in B\quad \mid f^{-1}(b)\mid \leq1$
	1. $f^{-1}(b)$ contiene max un elemento
3. $f$ è biiettiva $\iff \forall b\in B \quad \mid f^{-1}(b)\mid=1$
	1. $f^{-1}(b)$ contiene uno e un solo elemento
## Composizione di funzioni
Siano $f:A\to B$ e $g:B\to c$ funzioni. Si dice *funzione composta* di $f$ e $g$ la funzione:
$$g\circ f: A\to C$$
data da:
$$(g\circ f)(a)=g(f(a))$$
#proposizione 
*Proprietà associativa*:
Siano $f:A\to B$, $g:B\to C$ e $h:C\to D$ allora:
$$(h\circ g)\circ f=h \circ (g\circ f)$$
> [Attenzione]
> Se $f:A\to A$, $g:A\to A$ in genere $f\circ g \neq g \circ f$

#Esempio 
$$\begin{align}
&f:\mathbb{R}\to \mathbb{R}, \quad f(x)=2x \\
&g:\mathbb{R}\to \mathbb{R}, \quad g(x)=x+1 \\
 \\
&(f\circ g)(x)=f(g(x))=2(x+1)+1=2x+2 \\
&\neq \\
&(g\circ f)(x)=g(f(x))=(2x)+1=2x+1
\end{align}$$
#proposizione 
Siano $f:A\to B$ e $g:B\to C$ funzioni, allora:
1. se $g\circ f$ è iniettiva $\Rightarrow$ $f$ è iniettiva
2. se $g\circ f$ è suriettiva $\Rightarrow$ $g$ è suriettiva
3. se $f\circ g$ sono iniettive, allora $g\circ f$ è iniettiva
4. se $f$ e $g$ sono suriettive, allora $g\circ f$ è suriettiva

#Corollario
Siano $A\xrightarrow{f}B\xrightarrow{g}C$ se $g\circ f$ è biiettiva, allora $f$ è iniettiva e $g$ è suriettiva.
## Funzine inversa
Si dice *funzione inversa* di $f:A\rightarrow B$ una funzione $g:B\rightarrow A$ tale che:
$$\begin{align}
&g\circ f =id_{A} \\
&f\circ g=id_{B}
\end{align}$$
#Teorema
Sia $f:A\rightarrow B$ una funzione, le seguenti affermazioni sono equivalenti
1. $\exists$ una funzione $g$ inversa di $f$
2. $f$ è biiettiva
3. $\exists$ due funzioni $h_{1},h_{2}:B\rightarrow A$ tali che $h_{1}\circ f=id_{A}$ e $h_{2}\circ f=id_{B}$

Da qui possiamo dedurre che:
- $f:A\rightarrow B$ *è invertibile* $\iff$ *è biiettiva*
- l'*inversa* di $f:A\rightarrow B$, *se esiste, è unica* e si indica con $f^{-1}$
- siano $f:A\rightarrow B$ e $g:B\rightarrow C$ biiettive, allora $g\circ f$ è biiettiva e
	- $(g\circ f)^{-1}=f^{-1}\circ g^{-1}$
- sia $f:A\rightarrow B$ biiettiva e $g_{1},g_{2}:B\rightarrow C$ se $g_{1}\circ f=g_{2}\circ f \Rightarrow g_{1}=g_{2}$
- siano $h_{1},h_{2}:C\rightarrow A$ tali che $f\circ h_{1}=f\circ h_{2}$ allora $h_{1}=h_{2}$
## Operazioni tra funzioni
Sia $A$ un insieme non vuoto. Una operazione binaria è una funzione
$$*:A\times A\rightarrow A$$
L'immagine di un elemento $*((a_{1},a_{2}))$ si denota $a_{1}*a_{2}$
#Esempio 
Dati l'insieme $A$ e $P(A)$ (l'insieme delle parti), l'intersezione $\cap$ è un operazione su $P(A)$
$$\cup:P(A)\times P(A)\rightarrow P(A)$$
Presi i sottoinsiemi $x,y\subseteq A \quad \quad (x,y)\rightarrow x\cap y\in P(A)$
Vale lo stesso per l'unione $\cup$
#proposizione 
Un operazione $*$ su un insieme $A$ è:
1. *Associativa* se $\forall a_{1},a_{2},a_{3}\in A$
	1. $(a_{1}*a_{2})a_{3}=a_{1}*(a_{2}*a_{3})$
2. *Commutativa* se $\forall a_{2},a_{2}\in A$
	1. $a_{1}*a_{2}=a_{2}*a_{1}$
3. dotata di un *elemento neutro* se $\exists e\in A$ tale che $\forall a\in A$, $e*a=a*e=a$
	1. nel caso della somme $e=0$ e nel caso del prodotto $e=1$
# Combinatoria
Due insiemi $A$ e $B$ si dicono *equipotenti* se esiste una *funzione biiettiva* $f:A\rightarrow B$, ossia $A$ e $B$ hanno la *stessa cardinalità* $\mid A\mid=\mid B\mid$

Se esiste una *funzione* $f:A\rightarrow B$ *iniettiva*, allora $\mid A\mid \leq \mid B\mid$
$$f(A)\subseteq B\quad\text{ e }\quad \mid A\mid=\mid f(A)\mid$$
Se esiste una *funzione* $f:A\rightarrow B$ *suriettiva*, allora $\mid A\mid \geq \mid B\mid$
#proposizione 
Dati due insiemi $A$ e $B$
$$\mid A\mid=\mid B\mid \iff \mid A\mid \leq \mid B\mid \text{ e }\mid b\mid \leq \mid A\mid$$
$$(biiettiva \iff iniettiva \ e \ suriettiva)$$
#Esempio 
$f:\mathbb{N}\rightarrow2\mathbb{N}\quad |\quad \forall a\in\mathbb{N}, \quad a\mapsto 2a$
*è biiettiva* --> $\bigg(\begin{align}f^{-1}:&2\mathbb{N}\rightarrow \mathbb{N} \\&2a\mapsto a \quad \forall a\in\mathbb{N}\end{align}\bigg)$
dominio e codominio sono equipotenti
$$\mid \mathbb{N}\mid=\mid2\mathbb{N}\mid \quad (\text{ma }\mathbb{N}\not\equiv2\mathbb{N})$$
#Esempio 
Prendiamo il prodotto cartesiano $\mathbb{N}\times \mathbb{N}$
$$\mathbb{N}\times \mathbb{N}=\{\underbrace{(0,0)}_{a+b=0},\underbrace{(0,1),(1,0)}_{a+b=1},\underbrace{(0,2),(1,1),(2,0)}_{a+b=2},\dots \}$$
Abbiamo definito un ordine di grandezza tra le coppie $(a,b)$ tale che:
$$(a,b)\leq(a^{1},b^{1})\iff
\begin{cases}
a+b\leq a^{1}+b^{1} \\
a\leq a^{1} \text{ se }a=a^{1}, b\leq b^{1}
\end{cases}$$
Ovvero prima ordiniamo secondo la grandezza della somma $a+b$, poi secondo la $a$.
Se numeriamo le coppie, partendo da $0$, secondo l'ordine sopra, abbiamo definito una *biezione* $f:\mathbb{N}\times \mathbb{N}\rightarrow\mathbb{N}$ e $\mid \mathbb{N}\times \mathbb{N}\mid=\mid \mathbb{N}\mid$
Quindi: $f:\mathbb{N}\times \mathbb{N}\rightarrow\mathbb{N}$
$$
\begin{rcases}
\begin{align}
&(0,0)\rightarrow 0 \\
&(0,1)\rightarrow 1 \\
&(1,0)\rightarrow 2 \\
&\vdots
\end{align}
\end{rcases}\text{iniettiva e suriettiva} \Rightarrow\text{biiettiva}
$$
Un insieme $A$ è *infinito* se è *equipotente ad un suo sottoinsieme proprio*
Ossia: $\exists f:A\rightarrow A$ *iniettiva ma non suriettiva*, oppure, *suriettiva ma non iniettiva*.
Al contrario, $A$ si dice *finito* se per ogni funzione $f:A\rightarrow A$ si ha che se è iniettiva allora risulta anche suriettiva (e viceversa) e quindi anche biiettiva.
#Teorema 
Dato $n\in\mathbb{N}$, indichiamo con $In$ l'insieme dei numeri naturali: $In=\{1,2,3,\dots\}$
1. $\forall n\geq 1 \quad \quad In$ è finito
2. Per $m,n\in\mathbb{N}$ se $m\neq n$ allora $In$ e $Im$ *non sono equitenti*
3. Se $m\leq n$ allora $\mid Im\mid \leq \mid In\mid$
4. Ogni insieme non vuoto finito è equipotente ad un certo $In$
5. Per ogni insieme infinito $N$ si ha $\mid \mathbb{N}\mid \leq \mid \mathbb{X}\mid$
	1. #Esempio $\mid \mathbb{N}\mid \leq \mid \mathbb{R}\mid$

#Dimostrazione 5.
Sia $A$ un insieme finito non vuoto.
Devo stabilire una successione di sottoinsiemi $A\supset A_{1}\supset A_{2}\dots$
$\exists x_{1}\in A$ (perché $A\neq\varnothing$)
Poniamo $A_{1}=A\setminus\{x_{1}\}$ se $A_{1}=\varnothing$ la successione è terminata.
Se invece $A_{1}\neq 0$, $\exists x_{2}\in A_{1}$, t.c. $A_{2}=A_{1}\setminus\{x_{2}\}$ e così via si continua a iterare finché non trovo un $n\in\mathbb{N}$ tale che $A_{n}=\varnothing$
Se così non fosse, potrei costruire una funzione $f:A\rightarrow A$ iniettiva ma non suriettiva ponendo:
$$f(x_{1})=x_{2}, \quad f(x_{2})=x_{3}, \quad f(x_{3})=x_{4}, \quad etc\dots$$
Quindi $f$ risulta infinita, contraddicendo l'ipotesi che $A$ sia finito.
Se $A_{n}=\varnothing$ allora $A=\{x_{1},x_{2},\dots,x_{n}\}$ e
$$f:In\rightarrow A,\quad f(i)=x_{i}, \quad \forall i=1,2,\dots,n$$
è una biezione e quindi $A$ è equipotente ad $In$.

#proprietà
Siano $A,B$ insiemi finiti
$$\mid A\cup B\mid=\mid A\mid+\mid B\mid-\mid A\cap B\mid$$
Allo stesso modo, se ho $A,B,C$ finiti:
$$\mid A\cup B\cup C\mid=\mid A\mid+\mid B\mid+\mid C\mid-\mid A\cap B\mid-\mid A\cap C\mid-\mid B\cap C\mid+\mid A\cap B\cap C\mid$$

Ricordiamo che, dati due insiemi $A$ e $B$ finiti, con $\mid A\mid=m$ e $\mid B\mid=n$, allora
$$\mid A\times B\mid=\mid A\mid \cdot \mid B\mid=m\cdot n$$
#proposizione 
Siano $A_{1},A_{2},\dots,A_{k}$ insiemi finiti con $\mid A_{i}\mid=n_{i}$, $\forall i=1,2,\dots,k$ allora:
$$\mid A_{1}\times A_{2}\times\dots\times A_{k}\mid=n_{1}\cdot n_{2}\cdot\dots \cdot n_{K}$$
## Metodo delle scelte successive
Sia $A$ un insieme con $\mid A\mid=m$
Sia $n\in\mathbb{N}$ con $n\leq m$

Voglio fare $n$ scelte indipendenti dagli elementi di $A$.
Il mio scopo è selezionare $n$ elementi da $A$, uno alla volta, eventualmente facendo anche delle ripetizioni (posso prendere più volte lo stesso elemento).
Ad ogni selezione ho di fronte $m$ possibili opzioni di scelta, perciò in totale ci sono $\textcolor{yellow}{m^n}$ possibilità.
#proposizione 
Sia $A$ un insieme con $\mid A\mid=m$ e $In=\{1,2,\dots,n\}$ con $\mid In\mid=n$
$$F_{In,A}\text{ è l'insieme di tutte le funzioni }f:In\rightarrow A\text{ e si ha che }\mid F_{In,A}\mid=m^n$$
In generale, presi $A$ con $\mid A\mid=m$ e $B$ con $\mid B\mid=n$
$$F_{B,A}=\{\text{funzioni }f:B\rightarrow A\}$$
si ha $\mid F_{B,A}\mid=m^n$
### Ordinamenti
Sia $A$ un insieme con $\mid A\mid=n$
Un *ordinamento* di $A$ è una *funzione biiettiva* $f:In\rightarrow A$
Denotiamo con $O_{A}$ l'*insieme dei possibili ordinamenti* di $A$.
#proposizione 
Sia $\mid A\mid=n, \mid O_{A}\mid=n!$
Definiamo una *lista di lunghezza $n>0$* una *sequenza* o collezione *ordinata di $n$ elementi*.

#Definizione
Sia $A$ un insieme non vuoto di elementi e sia $f:In\rightarrow A$ una lista in $A$ di lunghtzza $n$.
Un *anagramma* di $f$ è una *lista* $h:In\rightarrow A$ ottenuta come composizione $h:f\circ g$ dove $g:In\rightarrow In$ è una biezione qualunque
![[Pasted image 20231029142800.png|250]]
#proposizione 
Sia $f:In\rightarrow A$ una lista di lunghezza $n$.
Supponiamo $Im(F)=\{a_{1},a_{2},\dots,a_{k}\}$ dove ogni $a_{i}\in A$ compare $r_{i}\geq 1$ volte tra $f(1),\dots,f(n)$
Allora il *numero di anagrammi di* $f$ è:
$$\frac{n!}{r_{1}!r_{2}!\dots r_{k}!}$$
### Disposizioni
È importante sia la *composizione* che la *posizione* degli elementi (*l'ordine consta*)
Esistono due casi diversi:
- disposizioni *con ripetizione*
- disposizioni *semplici*
#Definizione 
Sia $A$ un insieme finito e $k\geq 1$ un numero intero.
Una *disposizione con ripetizione* di ordine $k$ in $A$, è una sequenza di $k$ elementi di $A$ non necessariamente a due a due distinti.
#proposizione 
Se $1\leq k\leq \mid A\mid=n$ allora ci sono $n^k$ disposizioni con ripetizione di ordine $k$ in $A$.

#Definizione 
Sia $A$ un insieme finito e $k\geq 1$ un numero intero.
Una *disposizione semplice* di ordine $k$ in $A$ è una sequenza di $k$ elementi di $A$ a due a due distinti (non sono ammesse ripetizioni).
#proposizione 
Sia $\mid A\mid=n$ e $1\leq k\leq n$ allora il numero delle disposizioni semplici di ordine $k$ di $A$ è
$$D_{n,k}=n\cdot(n-1)\dots(n-k+1) = \frac{n!}{(n-k)!}$$
### Combinazioni
è impostante solo la *disposizione*
#Definizione 
Sia $A$ un insieme finito con $\mid A\mid=n$ e sia $k$ un intero tale che $0\leq k\leq n$.
Una *combinazione semplice* di ordine $k$ di $A$ è la scelta di un sottoinsieme $C$ di $A$ con $\mid C\mid=k$
#proposizione 
Il numero dei sottoinsiemi $C\subseteq A$, cioè il numero delle combinazioni di ordine $k$ in $A$, è:
$$C_{n,k}=\frac{D_{n,k}}{k!}=\frac{n!}{k!(n-k)!}$$
#Dimostrazione 
Per definizione $C_{n,k}=\mid\{\text{sottoinsiemi }B\subseteq A \text{ t.c. }\mid B\mid=k\}\mid$
$\forall B\subseteq A$, con $\mid B\mid=k$, si ha che il numero delle disposizioni semplici di ordine $k$ in $B$ è
$$D_{k,k}=k!$$
Allora il numero delle disposizioni semplici di ordine $k$ in $A$ è, combinando le precedenti affermazioni:
$$D_{n,k}=C_{n,k}\cdot D_{k,k}$$
$$C_{n,k}=\frac{D_{n,k}}{D_{k,k}}=\frac{n(n-1)\dots(n-k+1)}{k!}$$
#Esempio 
$C_{n,0}=C_{n,n}=1$
#proposizione 
Siano $n$ e $k$ due interi con $0\leq k\leq n$
Allora $C_{n,k}=C_{n,n-k}$
#Dimostrazione 
$C_{n,k}=\frac{n!}{k!(n-k)!}=\frac{n!}{(n-k)!k!}$
## COefficienti binomiali
#Definizione 
Siano $k,n\in\mathbb{N}$ e $0\leq k\leq n$
Definiamo *coefficiente binomiale* il numero
$$\tbinom{n}{k}=\frac{n!}{k!(n-k)!}$$
#proposizione 
1. $\tbinom{n}{0}=\tbinom{n}{n}=1$
2. $\tbinom{n}{k}=\tbinom{n}{n-k}$
3. *Formula di Stiefel* per $1\leq k\leq n$ --> $\tbinom{n-1}{k-1}+\tbinom{n-1}{k}=\tbinom{n}{k}$
#Teorema 
***Formula del Binomio di Newton***
$\forall n\geq 1$, con $n\in\mathbb{N}$
$$
\begin{align}
(x+y)^{n}&=\displaystyle\sum_{k=0}^{n} \tbinom{n}{k}x^{n-k}y^{k}= \\
&=x^{n}+\tbinom{n}{1}x^{n-1}y+\tbinom{n}{2}n^{n-2}y^{2}+\dots+y^{k}
\end{align}
$$
#Dimostrazione 
$$(x+y)^{n}=\underbrace{(x+y)(x+y)(x+y)\dots(x+y)}_{n \ fattori}$$
$$\gamma_{0}x^{n}+y_{1}n^{n-1}+\gamma_{2}n^{n-2}y+\dots+\gamma_{n-1}xy^{n-1}+\gamma_{n}y^{n}$$
$\gamma_{k}$ è il coefficiente del binomio $x^{n-k}y^{k}$ ed è pari al numero dlele volte che il monomio compare nell'espressione.
$\gamma_{k}=C_{n,k}=\tbinom{n}{k}$
#proposizione 
$\forall n\geq 0, n\in\mathbb{N}$
$$\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}=\tbinom{n}{0}+\tbinom{n}{1}+\dots+\tbinom{n}{n}=2^{n}$$
#Dimostrazione 
$\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}=\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}\cdot\underbrace{{1}^{n-k}\cdot1^{k}}_{\text{Binomio di Newton}}=(1+1)^{n}=2^{n}$
#Esempio 
Sia $A$ un insieme finito con $\mid A\mid=n$ e sia $P(A)=\{\text{sottoinsiemi di }A\}$ allora $\mid P(A)\mid=2^{n}$
Soluzione: per $0\leq k\leq n$
$$P_{k}(A)=\{B\subseteq A \text{ t.c } \mid B\mid=k\}\subseteq P(A)$$
so che $\mid P_{k}(A)=C_{n,k}$ e $P(A)=\bigcup\limits_{k=0}^{n}P_{k}(A)$
--> $\mid P(A)\mid=\displaystyle\sum_{k=0}^{n}\mid P_{k}(A)\mid=\displaystyle\sum_{k=0}^{n}C_{n,k}=\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}=2^{n}$
## Combinazioni con ripetizione
#Definizione 
Sia $A$ un insieme finito con $\mid A\mid=n$ e sia $k$ un intero non negativo $(k\in\mathbb{N}\setminus{\{0\}})$
Si dice *combinazione con ripetizione* di ordine $k$ in $A$, la scelta di $k$ elementi in $A$ in cui ciascun elemento può essere scelto più volte.

>[N.B]
>A differenza delle disposizioni con ripetizione, l'ordine degli elementi scelti non conta!
>$(b,b,a)=(b,a,b)$

#proposizione 
Il numero delle combinazioni con ripetizione di ordine $k$ in $A$ è:
$$C'_{n,k}=\tbinom{k+n-.1}{n-1}=\frac{(k+n-1)!}{(n+1)!k!}$$
### Riassunto: Combinazioni
#### Permutazioni
Scambio dell'ordine degli elementi di una sequenza
- Semplici $P_{n}=n!$
- Con ripetizione $P'_{n}=\frac{n!}{\underbrace{r_{1}!r_{2}1\dots r_{n}!}_{\text{n di volte che comprare ogni elemento}}}$
#### Disposizioni
Raggruppamento ordinato di $k$ elementi estratti da un insieme che ne contiene $n$
- Semplici $D_{n,k}=\frac{n!}{(n-k)!}$ con $0\leq k\leq n$
- Con ripetizione $D'_{n,k}=n^{k}$ con $k\gtreqless n$
#### Combinazioni
Raggruppamento di $k$ elementi, presi in qualsiasi ordine, formato a partire da $n$ elementi distinti
- Semplici $C_{n,k}=\frac{n!}{(n-k)!k!}$ con $0\leq k\leq n$
- Con ripetizione $C'_{n,k}=\frac{(n+k-1)!}{(n-1)!\cdot k!}$ con $k\gtreqless n$
#### Coefficiente binomiale
$$\tbinom{n}{k}=\frac{D_{n,k}}{P_{k}}=\frac{n!}{k!(n-k)!}$$
#### Binomio di Newton
$$
\begin{align}
(x+y)^{n}=&\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}\cdot x^{n-k}\cdot y^{k} = \\
&\displaystyle\sum_{k=0}^{n}\tbinom{n}{k}\cdot x^{k}\cdot y^{n-k}
\end{align}
$$
#### Come scegliere cosa usare
![[Pasted image 20231029152035.png|450]]





# Matrici
[Matrici](https://www.edutecnica.it/matematica/matrici/matrici.htm)
