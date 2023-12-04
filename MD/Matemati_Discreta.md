[Fonte](https://matematicafinanza.campusnet.unito.it/didattica/att/4019.2102.file.pdf)
# Il linguaggio degli insiemi
## Insiemi ed elementi
Indicheremo gli insiemi come $A,B,\dots$ e gli elementi di un insieme con $a,b,\dots$.
#Esempio 1.1.1
$A=\{0,1\}$ è l'insieme costituito dai due numeri $0$ e $1$.

Un altro modo per assegnare un insieme è quello di indicare una sua **proprietà caratteristica**:
$$B=\{x\in X|x\text{ soddisfa la proprietà }P \}$$
In caso si usi la proprietà caratteristica:
- è necessario esplicitare l'insieme $X$ degli elementi da prendere in considerazione
- la proprietà $P$ usata non deve essere in alcun modo ambigua
#Esempio 1.1.2 Non hanno senso le espressioni:
$$\begin{align}
& X = \{\text{multipli di }2\}, \\
& Y = \{\text{numeri naturali grandi}\} \\
& Z = \{\text{soluzioni dell'equazione }x^{4}-1=0\}, \\
& \text{L'insieme }V = \{x\in \mathbb{R}|x^{2}+1=0\} \text{ è invece perfettamente definito}
\end{align}$$
Poiché nessun numero reale ha quadrato negativo, l'insieme $V$ ora considerato è privo di elementi:
$V$ si chiama **insieme vuoto** e si denota $\emptyset$.
L'insieme vuoto è unico: $\{x\in \mathbb{R}|x^{2}+1=0\}=\emptyset = \{n\in\mathbb{N}|n>n\}$

Per indicare che un elemento **non appartiene** ad un insieme $A$ scriviamo $a \not\in A$.
Preso un qualsiasi elemento $a, \ a$ non appartiene all'insieme vuoto, ovvero: $\forall a \ a\notin \emptyset$.
Ad eccezione dell’insieme vuoto, tutti gli altri insiemi contengono qualche elemento: $A\neq 0\iff \exists a \ t.c \ a\in A$.
## Sottoinsiemi
Si dice che l'insieme $A$ è un **sottoinsieme** dell'insieme $B$, oppure che $A$ è contenuto in $B$: $A\subseteq B\iff(a\in A\Longrightarrow a \in B)$.
#Esempio 1.2.1
L'implicazione $\forall n\in\mathbb{N}(n>3\Longrightarrow 2n \text{ è pari })$ è corretta.
Invece $\forall n\in\mathbb{N}(n>3\Longrightarrow n^{2}>20)$ è falsa perché esiste almeno un caso in cui la prima affermazione è vera e la seconda no: $4>3$, ma $4^{2}\leq 20$.
L'insieme vuoto è sottoinsieme di ogni insieme; ogni insieme è sottoinsieme di se stesso: se $A$ è un insieme, allora $\emptyset\subseteq A$ e $A\subseteq A$.
## Unione, intersezione, complementare
#Definizione 1.3.1
Siano $A,B,C$ insiemi.
Si dice **unione** di $A$ e $B$ e si denota $A\cup B$ l'insieme i cui elementi sono tutti gli elementi che stanno in almeno uno tra $A$ e $B$:
$$x\in A\cup B\iff(x\in A \text{ oppure }x\in B)$$
Si dice **intersezione** di $A$ e $B$ e si denota $A\cap B$ l'insieme i cui elementi sono tutti gli elementi che stanno sia in $A$ che in $B$:
$$x\in A\cap B\iff(x\in A\text{ e }x\in B)$$
Due insiemi si dicono **disgiunti** se $A\cap B=\emptyset$.

Unione e intersezione di insiemi soddisfano la **proprietà distributiva**:
$$(A\cup B)\cap C=(A\cap C)\cup(B\cap C)\quad\quad (A\cap B)\cup C=(A\cup C)\cap(B\cup C)$$
#Esempio 1.3.2
Siano $A=\{x\in\mathbb{R}|x^{2}-1=0\}$ e $B=\{x\in\mathbb{R}|x^{2}+3x+2=0\}$
Allora.
$$
A\cup B=\{x\in\mathbb{R}|(x^{2}-1)(x^{2}+3x+2)=0\}
$$
$$
A\cap B=\{x\in\mathbb{R}|\begin{cases}
x^{2}-1=0 \\
x^{2}+3x+2=0
\end{cases}\}
$$
#Definizione 1.3.6
Siano $X$ un insieme e $A$ un suo sottoinsieme. Si dice **complementare** di $A$ in $X$ e si indica con $C_{X}(A)$ l'insieme di tutti gli elementi di $X$ che non appartengono ad $A$:
$$C_{X}(A)=\{x\in X|x\notin A\}$$
L'insieme complementare di $C_{X}(A)$ è l'unico insieme che verifica le due condizioni:
$$A\cap C_{X}(A)=\emptyset \quad \text{ e } \quad A\cup C_{X}(A)=X$$
Valgono inoltre le **Leggi di De Morgan**: se $A$ e $B$ sono sottoinsiemi di $X$, allora:
$$C_{X}(A\cup B)=C_{X}(A)\cap C_{X}(B) \quad \text{ e }\quad C_{X}(A\cap B)=C_{X}(A)\cup C_{X}(B)$$
## Insieme delle parti e partizioni
Gli insiemi possono a loro volta essere considerati come elementi di altri insiemi.
#Esempio 1.4.1
L'insieme $A=\{1,\{3,2\}\}$ he due elementi: il numero $1$ e l'insieme formato dai numeri $2$ e $3$.
L'insieme $X=\{5,\{5\}\}$ ha due elementi: il numero $5$ e l'insieme che ha $5$ come unico elemento.
#Definizione 1.4.2
Si dice **insieme delle parti** di un insieme $X$, l'insieme $P(X)$ i cui elementi sono sottoinsiemi di $X$:
$$A\in P(X)\iff A\subseteq X$$
#Esempio 1.4.3
Sia $A=\{0,5,7\}$ Allora $P(A)=\{\emptyset , \{0\}, \{5\}, \{7\}, \{0, 5\}, \{0, 7\}, \{5, 7\}, A\}$.
#Definizione 1.4.4
Si dice **partizione** di $X$ una famiglia di suoi sottoinsiemi tali che:
- nessuno di essi è vuoto
- sono due a due disgiunti
- la loro unione è tutto $X$
## Prodotto cartesiano
#Definizione 1.5.1
Siano $A,B,A_{1},\dots,A_{n}$ insiemi.
Si dice **prodotto cartesiano** di $A$ e $B$ e si denota $A\times B$ l'insieme i cui elementi sono le **coppie ordinate** $(a,b)$ dove $a$ varia tra tutti gli elementi di $A$ e $b$ tra quelli di $B$:
$$A\times B=\{(a,b)|a\in A, b\in B\}$$
# Corrispondenze e relazioni
## Corrispondenze
#Definizione 2.1.1
Siano $A,B$ due insiemi. Si dice **corrispondenza** da $A$ a $B$ un qualsiasi sottoinsieme $R$ del prodotto cartesiano $A\times B$.
Se $A=B$, una corrispondenza in $A\times A$ si dice anche **relazione** in $A$.
#Esempio 
- Siano $A=\{1,4,-17\}$ e $B=\{0,1,2\}$. Il sottoinsieme $R=\{(1,1),(4,0),(4,1)\}$ di $A\times B$ è una corrispondenza da $A$ a $B$
- L'insieme $T=\{(n,m)\in\mathbb{N}\times \mathbb{Z}|n=m^{2}\}$ è una corrispondenza da $\mathbb{N}$ a $\mathbb{Z}$
- Il semipiano $S=\{(x,y)\in\mathbb{R}^{2}|x\leq y\}$ del piano cartesiano $\mathbb{R}^{2}$ è una relazione in $\mathbb{R}\times \mathbb{R}$
#Definizione 2.1.5
Sia $R$ una corrispondenza in $A\times B$. Si dice **corrispondenza inversa** di $R$ la corrispondenza in $B\times A$ data da
$$R^{-1}=\{(b,a)\in B\times A|(a,b)\in R\}$$
Di particolare interesse nello studio di una relazione è stabilire se verifica alcune particolari proprietà. Diremo che una relazione $R$ in $A$ soddisfa:
1. **Proprietà riflessiva** se $\forall a\in A$ si ha $(a,a)\in R$
2. **Proprietà simmetrica** se $\forall a,b\in A:(a,b)\in R\Longrightarrow (b,a)\in R$
3. **Proprietà antisimmetrica** se $\forall a,b\in A: (a,b)\in R$ e $(b,a)\in R \Longrightarrow a=b$
4. **Proprietà transitiva** se $\forall a,b,c\in A:(a,b)\in R$ e $(b,c)\in R \Longrightarrow (a,c)\in R$
## Relazioni d'ordine
#Definizione 2.2.1
Una relazione $R$ in $A$ si dice **relazione d'ordine** se soddisfa le proprietà riflessiva, antisimmetrica e transitiva.
Una relazione d'ordine $R$ in $A$ si dice **ordine totale** se due elementi qualsiasi $a,b\in A$ sono sempre **confrontabili**, ossia vale sempre uno tra $aRb$ e $bRa$. Una relazione d'ordine non totale si dice **ordine parziale**.
## Relazioni di equivalenza
#Definizione 2.3.1
Una relazione $R$ in un insieme $A$ si dice **relazione di equivalenza** se soddisfa le proprietà riflessiva, simmetrica e transitiva. Se $R$ è una relazione di equivalenza $a\sim b$ invece che $(a,b)\in R$ oppure $aRb$.
#Definizione 2.3.3
Sia $\sim$ una relazione di equivalenza in un insieme $X$ e sia $a$ un elemento di $X$. si dice **classe di equivalenza** di $a$, e si denota $[a]=\{b\in X|a\sim b\}$.
Un elemento $a$ che appartiene ad una classe di equivalenza si dice anche **un rappresentante** di quella classe.
#Teorema 2.3.4
Sia $Q=\{Y_{i}|i\in I\}$ una partizione di $X$. Allora la relazione in $X$ è definita da:
$$aRb\iff \exists Y_{i}\in Q \ t.c. \ a,b\in Y_{i}$$
è una relazione di equivalenza in $X$.
#Dimostrazione 
Dobbiamo verificare che sono soddisfare le proprietà: riflessiva, simmetrica e transitiva.
1. Poiché $\bigcup Y_{i}=X$, preso un qualsiasi $a\in X$ esiste sempre un sottoinsieme $Y_{i}$ tale che $a\in Y_{i}$ e quindi $aRa$
2. La validità della proprietà simmetrica è del tutto evidente: se $a,bin Y_{i}$ allora $b,a\in Y_{i}$
3. Siano $a,b,c$ elementi di $X$ e supponiamo che $aRb$ e che $bRc$, ossia che esistano $Y_{i}$ e $Y_{j}$ in $Q$ tali che $a,b\in Y_{i}$ e $b,c\in Y_{j}$. Allora $b\in Y_{i}\cap Y_{j}$; poiché due sottoinsiemi distinti in una partizione non possono avere elementi in comune, allora $Y_{i}=Y_{j}$ e $a,c\in Y_{i}$ ossia $aRc$.
#Teorema 2.3.5
Sia $\sim$ una relazione di equivalenza in $X$. Allora le classi di equivalenza soddisfano le condizioni:
1. $\forall a\in X \ [a]\neq\emptyset$
2. $\forall a,b\in X \text{ si ha }[a]=[b] \text{ oppure }[a]\cap[b]=\emptyset$
3. $\bigcup_{a\in X}[a]=X$
#Dimostrazione Verifichiamo le condizioni
1. $[a]\neq\emptyset$ poiché $a\in[a]$
2. 









