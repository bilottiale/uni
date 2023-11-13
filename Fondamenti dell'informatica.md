[[README]]
## Indice
[[Fondamenti dell'informatica#Base 2, base 10...|Base 2, base 10...]]
# Base 2, base 10...
Se un oggetto può essere scelto in $n$ modi, e un secondo oggetto può essere scelto in $k$ modi, ci sono $n \cdot k$ modi per scegliere gli oggetti a coppie:
$$\overbrace{\overbrace{* \quad * \quad * \quad \dots}^{*\quad\textcolor{red}{\text{k modi}}} \quad \overbrace{* \quad * \quad * \quad \dots}^{*} \quad \overbrace{* \quad * \quad * \quad \dots}^{*} \quad * \quad \dots}^{\textcolor{red}{\text{n modi}}}$$

![tree](https://www.researchgate.net/profile/Do-Dong/publication/235903176/figure/fig1/AS:670050021290010@1536763782826/The-full-binary-tree-of-depth-m-the-root-is-at-level-0-leaves-are-at-level-m-Branches.png)
$2 \cdot \#$ sequenze di bit di lunghezza $n$
#Esempio
Riga 1 -> 0, 1 -> 1 bit -> 2 coppie/valori (0 e 1)
Riga 2 -> 00, 01, 10, 11 -> 2 bit -> 4 coppie/valori
Riga 3 -> 000, 001, 010, 011, 100, 101, 110, 111 -> 4 bit -> 8 coppie/valori
Ogni riga raddoppia il valore della riga precedente.

| Sequenza di bit | # sequenza di bit di quella lunghezza       |
|-----------------|---------------------------------------------|
| 0               | 1 = $2^{0}$                                 |
| 1               | 2 = $2^{1}$                                 |
| 2               | 4 = $2^{2}$                                 |
| 3               | 8 = $2^{3}$                                 |
| $\dots$         | $\dots$                                     |
| 10              | 1024 = $2^{10}\rightarrow K \rightarrow KB$ |

## Notazione posizionale
#Esempio 
$2023 = 3 \cdot 1 + 2 \cdot 10 + 0 \cdot 100 + 2 \cdot 2$
In base alla posizione il numero ha un "significato" diverso.

Da *base 10* a *base 2*:
$23_{10} : 2 = 11 \quad\text{con resto }1$
$11 : 2 = 5 \quad \text{con resto }1$
$5 : 2 = 2 \quad \text{con resto }1$
$2 : 2 = 1 \quad \text{con resto }0$
$1 : 2 = 0 \quad \text{con resto }1$

Prendi il resto, $last \quad to \quad first \quad \uparrow$
$1 \quad 0 \quad 1 \quad 1 \quad 1 \quad_{2}$

Da *base 2* a *base 10*:
$$1 \quad 0 \quad 1 \quad 1 \quad 1$$
$$16 \quad 8 \quad 4 \quad 2 \quad 1$$
$$16 \cdot 1 + 8 \cdot 0 + 4 \cdot 1 + 2 \cdot 1 + 1 \cdot 1 = 23_{10}$$

*Base 16* (Esadecimale)
* Cifre: $0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F$
*Base 8* (Ottale)
* Cifre: $0,1,2,3,4,5,6,7$
## Excess notation
Utilizzata in sequenze di bit di lunghezza fissata
$\overbrace{0}^{positivo} \quad \overbrace{111}^{eccesso di \ 4 \ (3 + 4 = 7)} \quad \overbrace{101.0}^{virgola \ data \ dall'esponente}$

![[Pasted image 20230928114024.png]]
#Esempio 
![[Pasted image 20230928114304.png]]
## Esercizi
#Esercizio 
$2\frac{3}{4} \rightarrow 10.01 \rightarrow 2,75_{10} \rightarrow 01101011$
$\overbrace{0}^{segno} \quad \overbrace{110}^{esponente} \quad \overbrace{1011}^{mantissa}$
$5\frac{1}{4} \rightarrow 101.01 \rightarrow 5,25 \rightarrow 01111010(1)$

$01001010 \rightarrow + \ 0.1010 \rightarrow \frac{1}{2} + \frac{1}{8} = \frac{5}{8}$
$01101101 \rightarrow + \ 11.01 \rightarrow 3\frac{1}{4}$
$11011100 \rightarrow - \ 1.100 \rightarrow - \ 1\frac{1}{2}$
# Logica
$(3 < 5) \land (5 \ dispari \lor 3 \ pari)$
Dove $3 < 5$, $5 \ dispari$ e $3 \ pari$ sono *proposizioni*,
e $\land$ (and) e $\lor$ (or) *connettivi proposizionali*.
L'insieme degli elementi è una *formula proposizionale*
## Tabelle di verità
*XOR*

| $p$ | $q$ | $(p \lor q) \land \neg \ (p \land q)$ |
| --- | --- | ------------------------------------- |
| T   | T   | F                                     |
| T   | F   | T                                     |
| T   | F   | T                                     |
| F   | F   | F                                     |
## Implicazione logica
$A \to B$
- $A$ è *condizione sufficiente* per $B$;
- $B$ è *condizione necessaria* per $A$;

| $A$ | $B$ | $A \to B$ | $B \to A$ | $A \leftrightarrow B$ |
|-----|-----|-----------|-----------|-----------------------|
| 0   | 0   | 1         | 1         | 1                     |
| 0   | 1   | 1         | 0         | 0                     |
| 1   | 0   | 0         | 1         | 0                     |
| 1   | 1   | 1         | 1         | 1                     |
## Tautologia
Una formula proposizionale $A$ è una *tautologia*, o *logicamente valida*, se *per ogni* assegnazioni di valori di verità alle variabili proposizionali che contiene, il suo valore è $T$ (True), e si scrive:
$$\models A$$
#Esempio 
* $\models A \lor \neg \ A = p \lor \neg \ p$ 
* $\models p \to (q \to p)$
* $\models (p \to q) \to (\neg \ q \to \neg \ p)$

$\underbrace{p}_{antecedente} \to \underbrace{q}_{conseguente}$ 
## Dimostrazioni
[Vari teoremi e tipi di dimostrazione](http://www.integr-abile.unito.it/Libri/Logica/1.1%20-%20Teoremi%20e%20Dimostrazioni.html#dimostrazione-diretta)
## Il metodo delle tavole
[Il metodo delle tavole, Moodle](https://informatica.i-learn.unito.it/pluginfile.php/386734/mod_resource/content/1/Il%20metodo%20delle%20tavole.pdf)
***!TODO***
$A \rightarrow B$
Come si dimostra ciò?
- *Diretta*:
	- Assumo $A$ e cerco di derivare $B$
$$
\begin{alignat}{1}
A \\
\vdots \\
C \\
\neg C \\
\text{-------} \\
\therefore \neg A \\
\end{alignat}
$$
- *Per assurdo*:
	- Assumo $A$ vera e che riusciamo a dimostrare $C$ e $\neg C$
$$
\begin{alignat}{1}
\neg A \\
\vdots \\
C \\
\neg C \\
\text{-------} \\
\therefore A \\
\end{alignat}
$$
## Da frase a funzione
Fissiamo un universo di discordo $U$ che contiene tutto quello di cui vorremmo poter parlare
- Numeri naturali, interi, reali, ...
- Individui come: Cesare, Cleopatra, Bruto, Topolino, Pippo, ...
#Esempio 
- Cesare ama Cleopatra
- Bruto uccise Cesare con un pugnale
- $\sqrt{2}<\Pi$
La prima frase si può anche scrivere:
- ___ ama Cleopatra --> ___ ama ___
Dove ___ sono gli *argomenti*
Usiamo variabili: $x$ ama $y$ --> $A(x,y)$
## Insieme di Russell
$R = \{ x|x \in x \} = R \in R$ non è ne vera ne falsa.
- Se fosse *vera*: $R \notin R$
- Se fosse *falsa*: $R \notin R$ (falsa) quindi $R \in R$ (vera) portando ad una *contraddizione*
# Quantificatori
$R(x,y)$
$\forall x, R(x,y)$ *Quantificatore universale* ($\forall$)
$\exists x, R(x,y)$ *Quantificatore esistenzaiale* ($\exists$)
#Esempio 
$R(x,y)$
$\exists y, R(x,y)$ --> $x$ ha la relazione $R$ con qualche $y$
$\forall x \exists y, R(x,y)$ --> ogni $x$ ha la relazione $R$ con qualche $y$
#Esempio 
Per ogni numero c'è un numero maggiore di esso
$\forall x \exists y | y>x$ --> Vero
$\neq$
$\exists y \forall x | y>x$ --> Falso
#Esempio 
$x \text{ ha ballato con } y = R(x,y)$
Tutti hanno ballato con qualcuno
$$\forall x \exists y | R(x,y)$$
Uno ha ballato con tutti
$$\exists y \forall x, R(x,y)$$
#Esempio 
*Tutti* gli svedesi sono protestanti
$S(x) = x$ è svedese
$P(x) = x$ è protestante
$\forall x (S(x)\rightarrow P(x))$
*Solo* gli svedesi sono protestanti
$\forall x (P(x) \rightarrow S(x))$
## Dimostrazione diretta
Per dimostrare una proposizione della forma
$\forall x (P(x) \rightarrow Q(x))$
Dove $P(x), Q(x)$ sono funzioni proposizionali
- Prendiamo un generico elemento $x$ di $U$
- Assumiamo che $P(x)$ e cerchiamo di dimostrare $Q(x)$, se ci riusciamo, concludiamo $\forall x (P(x)\rightarrow Q(x))$
#Esempio 
***Potrebbe essere in esame***
$$\text{Se } A \text{ allora } \overline{B} \subseteq \overline{A}$$
$$A\subseteq B \rightarrow \overline{B}\subseteq \overline{A}$$
$$\therefore A \subseteq B \rightarrow \overline{B} \subseteq \overline{A}$$
Bisogna dimostrare che $\forall x (x \in \overline{B} \rightarrow x \in \overline{A})$
Sia $x$ un elemento arbitrario di $U$
Dimostriamo che $x \in \overline{B} \rightarrow x \in \overline{A}$
Assumiamo $x \in \overline{B}$, bisogna concludere $x \in \overline{A}$
$$A\subseteq B = \forall x (\textcolor{red}{x\in A} \rightarrow \textcolor{yellow}{x \in B})$$
$$\overline{B} \subseteq \overline{A} = \forall x(\textcolor{yellow}{x\in \overline{B}} \rightarrow \textcolor{red}{x \in \overline{A}})$$
Assumiamo per assurdo che $\textcolor{red}{x \in A}$, quindi $\textcolor{yellow}{x \in B}$, ma assumiamo che $\textcolor{yellow}{x\in \overline{B}}$, quindi $x \notin B$ e $x\notin A$, cioè $\textcolor{red}{x \in \overline{A}}$ per assunzione.
$x \in \overline{B} \rightarrow x \in \overline{A}$ e $\overline{B}\subseteq \overline{A}$ perché $x$ è un elemento arbitrario.
Schematizziamo per semplificare
$$A\subseteq B \rightarrow \overline{B}\subseteq \overline{A}$$
### !TODO SCHEMA

---
$$A \subseteq B \leftrightarrow A \cup B=B$$
1. $A\subseteq B \rightarrow A \cup B=B$
2. $A\cup B=B\rightarrow A\subseteq B$
Implicazione: assumiamo che $A\subseteq B$, quindi $\forall x(x\in A \rightarrow x \in B)$
### !TODO SCHEMA

Per assurdo: $A\subseteq B \rightarrow A \cup B=B$
Assumo $A\subseteq B$, assumo anche $A\cup B \neq B$. Quindi c'è un elemento $a$ di $A$ che non è elemento di $B$, cioè $a\notin B$, ma per ipotesi $a\subseteq B$ quindi $a \in B$.

---
## Riepilogo
- Logica proposizionale
	- $A \lor B, A \land B, \dots$
	- Sintassi: variabili proposizionali, connettivi($\lor,\land,\neg,\rightarrow,\leftrightarrow$)
	- Semantica: tavole di verità, conseguenti logici($\vdash, \vDash$), tavole semantiche(alberi), inferenza logica
### !TODO SCHEMA
$C \rightarrow A, C \rightarrow B, C \vdash A \land B$

$\begin{rcases} 1. \ C \rightarrow A \\ 2. \ C \rightarrow B \\ 3. \ C \end{rcases}Premesse$
$4. \ A$ da 1,3 per *modus ponens*
$5. \ B$ da 2,3 per *modus ponens*
$6. \ A\land B$ da 4,5 per $\land$
***Modus ponens***
$\begin{rcases} p \\ p\rightarrow q \end{rcases} \ \text{Premesse}$
$\therefore q$ Conclusione
Da questo possiamo ricavare:
$C$
$C \rightarrow A$
$\therefore A$
---
$C$
$C \rightarrow B$
$\therefore B$
## Ripasso dimostrazioni
*Diretta*:
$A \rightarrow B$ o anche $\forall x(A\in B)$
*Assurdo*:
Per dimostrare formule della forma:
$\textcolor{red}{\neg A}$ Assumendo $\textcolor{lightgreen}{A}$ per ottenere una contraddizione
$\textcolor{lightgreen}{A}$ Assumendo $\textcolor{red}{\neg A}$ per ottenere una contraddizione
# Anatomia di una formula della logica dei predicati
$\underbrace{x}_{variabile} = \underbrace{5}_{proposizione}$
$x$ è pari
$x$ è rosso
$x$ ama $y=R(x,y)$
Maria ama $y=R(\text{Maria},y)=P(y)$
- $x$ è pari
	- $\exists y x = 2 \cdot y \quad \forall x \in \mathbb{Z}$
- Tutti gli uomini sono mortali
	- $\forall x (D(x)\to M(x))$
- Ogni donna ha ballato con qualche uomo
	- $\forall x(D(x)\to \exists y(U(x)\land B(x,y)))$
- C'è un uomo con il quale ogni donna ha ballato
	- $\exists x(U(x)\land \forall y(D(y)\to B(x,y)))$
- Tutti amano qualcuno
	- $\forall x\exists y A(x,y)$
- Tutti sono amati da qualcuno
	- $\forall x\exists y A(y,x)$
- C'è qualcuno che ama tutti
	- $\exists y\forall x A(y,x)$
Come rendere falsa una proposizione della forma:
$$\overbrace{\forall x \underbrace{P(x)}}_{x \text{  è libera, non è vincolata}}^{x\text{ è vincolata al quantificatore}(\forall, \exists)}$$ $\neg(\forall x P(x))\equiv \exists x\neg P(x)$
#Esempio 
Per ogni $m$ ed ogni $n$, se $m$ ed $n$ sono dispari, allora $m+n$ è pari.
$$\forall m\forall n((\exists k|m=2*k+1)\land(\exists u|n=2*u+1)\to(\exists v|m+n=2v))$$
$$\forall m\forall n(A\land B\to C)$$
*Dimostrazione diretta*:
Come dimostro che per ogni $m$ e ogni $n$ qualcosa è vero?
Prendiamo elementi generici, $a$ e $b$, dell'universo di discorso.
Assumiamo che:
- $\exists w|a=2*w+1$ --> $a$ dispari
- $\exists z|b=2*z+1$ --> $b$ dispari
Bisogna dimostrare che $a+b$ è pari facendo vedere che, per $a+b=2d$, $a+b$ è pari.
Allora: $a+b=(2*w+1)+(2*z+1)=2*(w+z+1)$
$$a+b \text{ è pari}$$
### Altre dimostrazioni
Dimostra che:
	Per ogni intero $n$, se $n^{2}$ è pari allora $n$ è pari
Dimostrazione: La proposizione ha la forma:
$$\forall n(n^{2}\text{ pari } \to n \text{ pari})$$
*Dimostrazione diretta*:
Sia $n$ un generico intero.
Assumiamo $n^{2}$ pari, dobbiamo concludere $n$ pari.
### !TODO SCHEMA
---
$$min(a,b)=\begin{cases}  a &\mbox{se }a\leq b\\  b &\mbox{se }a>b\end{cases}$$
Per ogni $a,b$ e $x$
$x \leq min(a,b)\to (x\leq a\land x\leq b)$
Dimostrazione:
Ci sono due casi:
- $a\leq b$: quindi $a=min(a,b)$
	- $x\leq a$ per ipotesi, inoltre $x\leq a<b$ per transitività
- $a>b$: quindi $min(a,b)=b$
	- Simmetrica alla precedente
---
Se due interi hanno opposta parità, la loro somma è dispari.
$$\forall x\forall y(\text{se }x,y\text{ hanno opposta parità, allora }x+y\text{ è dispari})$$
Ci sono due casi:
- $x$ dispari, $y$ pari:
	- $x=2a+1$, $y=2b$
	- $x+y=2(a+b)+1$ che ha forma $2c+1$ quindi $x+y$ è dispari
- $x$ pari, $y$ dispari:
	- Simmetrica alla precedente
---
#Esempio 
Per ciascuna delle seguenti proposizioni, indicare una forma equivalente alla sua *negazione*:
$$2<5 \to 2\geq 5$$
$$2<5\text{ e }3>1 \to 2\geq 5\text{ oppure } 3\leq 1$$
$$1<2\text{ oppure } 3\text{ è pari }\to 1\geq 2\text{ e }3\text{ è dispari}$$
## XOR
Come si definisce *xor* con $\neg,\land,\lor$
$A\oplus B\equiv(A\lor B)\land \neg(A\land B)$
La tavola di verità conclude: $F,T,T,F$
$\models (A\oplus B)\longleftrightarrow(A\lor B)\land\neg(A\land B)$
# Alcuni esempi relativi a formalizzazione, connettivi proposizionali e quantificatori
Spesso il significato di una proposizione $A$ può essere spiegato meglio dicendo che cosa la contraddice. Ecco una serie di esempi in cui si cerca di trovare una proposizione equivalente a $\neg A$.
Inizio con un esempio aritmetico, relativo a un qualsiasi insieme numerico. La negazione di $2<5$ è $2\geq 5$ e **non** $2>5$: bisogna considerare il caso in cui $2=5$, che pur non essendo equivalente alla negazione di $2<5$, è incompatibile con essa.
La negazione di $2<5$ e $3>1$ è $2\geq 5$ oppure $3\leq 1$. Questo segue da un. delle due *Leggi di de Morgan*:
$$\neg(A\land B)\equiv\neg A\lor\neg B$$
$$\neg(A\lor B)\equiv\neg A\land\neg B$$
#Esercizio Come esercizio si dimostri che queste equivalente sono vere, cioè che:
$$\models\neg(A\land B)\longleftrightarrow\neg A\lor\neg B$$
$$\models\neg(A\lor B)\longleftrightarrow\neg A\land\neg B$$
cosa che può essere dimostrata facendo vedere che:
$$\models\neg(A\land B)\longleftrightarrow\neg A\lor\neg B$$
$$\models\neg(A\lor B)\longleftrightarrow\neg A\land\neg B$$
$$\models\neg A\lor \neg B\longleftrightarrow\neg (A\land B)$$
$$\models\neg A\land \neg B\longleftrightarrow\neg (A\lor B)$$
o, in maniera equivalente che:
$$\neg(A\land B)\models\neg A\lor\neg B$$
$$\neg(A\lor B)\models\neg A\land\neg B$$
$$\neg A\lor \neg B\models\neg (A\land B)$$
$$\neg A\land \neg B\models\neg (A\lor B)$$
infatti $\models A\rightarrow B$ e $A \models B$ sono equivalenti.
#Esempio 
"*Qualche numero primo è pari*" può essere tradotta in formule usando funzioni proposizionali $Primo(x)$ e $Pari(x)$:
$$\exists x(Primo(x)\land Pari(x))$$
La negazione di questa proposizione ha allora forma:
$$\forall x(\neg Primo(x)\lor \neg Pari(x))$$
che è equivalente a:
$$\forall x(Primo(x)\rightarrow \neg Pari(x))$$
perché, in generale, $A\rightarrow B\equiv\neg A\lor B$ (dimostrare come in esercizio).
Usando ancora la funzione proposizionale $Primo(x)$, traduciamo in una formula la proposizione 'Ci sono numeri primi minori di $17$', che diventa:
$$\exists x(\neg Primo(x)\land x<17)$$
La sua negazione ha la forma:
$$\forall x(\neg Primo(x)\lor \neg (x<17))$$
che è equivalente a:
$$\forall x(Primo(x)\rightarrow x\geq17)$$
Consideriamo ora:
$$\text{Tutti i numeri}>5\text{ sono anche}>3$$
La sua traduzione è:
$$\forall x(x>5\rightarrow x>3)$$
e la sua negazione diventa:
$$\exists x\neg(x>5\rightarrow x>3)$$
che è equivalente a:
$$\exists x(x>5\land\neg(x>3))$$
perché, in generale, $\neg(A\rightarrow B)\equiv A\land \neg B$ (dimostrare come in esercizio).

# Induzione
$Q=3^{2}>2^{2}\longrightarrow Q(x)=x^{2}>x^{2}$
Ci aiuta a dimostrare che per tutti i numeri naturali esiste una proprietà:
![[Pasted image 20231108134622.png|250]]
Se un punto $n$ ha una proprietà $P$ allora $n+1$ ha la proprietà $P$.
$$\begin{align}
&P(0) \\
&\forall n\geq 0\quad (P(n)\rightarrow P(n+1)) \\
-&------------\\
\therefore&\forall n\geq 0\quad P(n)
\end{align}$$
Se siamo a un $k$ numero possiamo aumentare verso infinito, ma per tornare verso $0$ abbiamo un numero finito $k$ di passi da fare.
#Dimostrazione 
$$\forall n\geq 0\quad\underbrace{\displaystyle\sum_{i=0}^{n}i=\frac{n(n+1)}{2}}_{S(n)}$$
$\forall n\geq 0 \quad S(n)$
Usiamo il *principio di induzione*:
Dimostriamo la *base* $S(0)$:
$$S(0)=\displaystyle\sum_{i=0}^{0}i=\frac{0(0+1)}{2}\longrightarrow 0=0$$
$S(0)$ è vera.
Ora dimostro il *passo induttivo*:
$\forall k\geq 0\quad (S(k)\rightarrow S(k+1))$
Prendiamo un $k\geq 0$ generico e assumiamo $S(k)$, cioè:
$$\textcolor{yellow}{\displaystyle\sum_{i=0}^{k}i}=\textcolor{yellow}{\frac{k(k+1)}{2}}\longrightarrow \sum_{i=0}^{k+1}i=\frac{(k+1)(k+2)}{2}$$
Possiamo riscrivere come:
$$\displaystyle\sum_{i=0}^{k+1}i=\frac{(k+1)(k+2)}{2}\longrightarrow\textcolor{yellow}{\sum_{i=0}^{k}i}+k+1=\textcolor{yellow}{\frac{k(k+1)}{2}}+\frac{2(k+1)}{2}$$
Conclude la dimostrazione del passo induttivo.
Per *principio di induzione* possiamo concludere che:
$$\begin{align}
&\forall n\geq 0\quad S(n) \\
&\forall n\geq 0\quad \left( \displaystyle\sum_{i=0}^{n}i=\frac{n(n+1)}{2} \right)
\end{align}$$
#### Riepilogo
Quando vogliamo dimostrare che per ogni $n\geq 0 \quad P(n)$ (base dell'induzione)
$$\begin{align}
&P(0) \\
passo(2 \ alternative)
&\begin{cases}
&\forall k \geq 0(\textcolor{red}{P(k)}\to P(k+1)) \\
&\forall k >0(P(k-1)\to P(k))\\
\end{cases}\\
&\therefore\forall n\geq 0\quad P(n)
\end{align}$$
Con $\textcolor{red}{P(k)}$ ipotesi induttiva.
Per dimostrare con una dimostrazione diretta:
- Prendere un generico $K\geq 0$
- Assumere $P(k)$
- Dimostrare $P(k+1)$

*Invariante* (di ciclo): una proprietà che è vera dopo ogni iterazione del ciclo.
#Esempio dopo $n$ iterazioni
$n+Dq+r$
Dobbiamo dimostrare
$\forall n\geq 0\quad P(n)$
Per induzione su $n\geq 0$
***Base***: $P(0)$ che significa, dopo $0$ iterazioni $X=qD+r$, o, equivalentemente, prima di iniziare l'esecuzione del ciclo.
- $X=0D+r$
***Passo induttivo***: $\forall k\geq 0\quad (P(k)\to P(k+1))$
- Prendiamo generico $k\geq 0$, assumiamo $P(k)$, cioè, dopo $k$ iterazioni, $X=qD+r$. Bisogna dimostrare che dopo $k+1$ iterazioni, $X=qD+r$.









09-11-23