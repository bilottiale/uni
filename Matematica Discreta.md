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
![](https://www.sosmatematica.it/wp-content/uploads/2022/07/Intersezione-di-Insiemi-1024x658.png)

$A$ e $B$ si dicono *disgiunti* se:
$$A \cap B = \varnothing$$

- Sia $I = \{ 1, \dots, n \}$
- $A_i$ un insieme per $i \in I$

L'intersezione di tutti $A_{i} = \{A_{1} \cap A_{2}\cap \dots \cap A_{n}\} = \{ x | x \in A  \forall i \in I \}$

2. L'*unione* di $A$ e $B$ è:
$$A \cup B = \{ x|x \in A \lor x \in B \}$$
![](https://www.sosmatematica.it/wp-content/uploads/2022/07/Unione-di-insiemi.png)

- Sia $I = \{ 1, \dots, n \}$
- $A_i$ un insieme per $i \in I$

L'unione di tutti $A_{i} = \{A_{1} \cup A_{2}\cup \dots \cup A_{n}\} = \{ x | \exists i \in I, x \in A_i \}$
$\exists \rightarrow \text{esiste}$

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
$$C_{x}(A \cup B) = C_{x}(A) \cap C_{x}(B)$$
![](https://www.youmath.it/images/stories/Insiemi/seconda-legge-di-de-morgan-1.png)

## Ricoprimento
Siano $A_{1}, A_{2}, \dots, A_{n}$ sottoinsiemi di $A$,
$$\{ A_{i}\}_{i=1}^{n} = \{ A_{1}, \dots, A_{n} \}$$
È un *ricoprimento* di $A$ se:
$$\cup_{i=1}^{n}A_{i}(A_{1} \cup A_{2} \cup \dots \cup A_{n}) = A$$
#Esempio $A = \mathbb{Z}$
$$A_{1} = \{\text{numeri interi pari}\}$$
$$A_{2} = \{\text{numeri interi dispari}\}$$
$$A = A_{1} \cup A_{2}, \{A_{1}, A_{2}\}$$

## Partizione
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

TODO: IMMAGINE $[0,1]\times[-1,0]$

#Esercizio 1.
$A = \{1,2,3\}$

$\varnothing \in A$ FALSO
$\{\varnothing\}\subseteq A$ FALSO
$\varnothing \subseteq A$ VERO

**?** Tra i numeri da $1,\dots,600$ quanti sono i numeri che non sono divisibili per $2$ e $3$?

$C_{x}(A \cap B) = 100$

# Funzioni
$def$: dati due insiemi $A$ e $B$, non vuoti, una relazione tra $A$ e $B$ è un sottoinsieme:
$$R\subseteq A \times B$$
#Esempio 
$$A = \{1,2,3,\} \quad B = \{3,4,5\}$$
$$R = \{ (1,3), (3,3), (2,4) \} \subseteq A \times B$$

$def$: siano $A$ e $B$ insiemi non vuoti, una funzione $f$ con dominio $A$ e codominio $B$, è dato un di sottoinsieme:
$\Gamma \subseteq A \times B$ tale che $\forall a \in A$ esiste un unico $b \in B$ tale che $(a, b) \in \Gamma$.

$R \subseteq A \times B$ è equivalente a $f: A \rightarrow B$ definita da $f(a) = b, \forall(a, b) \in \Gamma$

Per verificare la corrispondenza $f: A \rightarrow B$:

1. Ogni elemento di $A$ ha una "immagina" -> **Ovunque definita**
2. Ogni elemento di $A$ ha *una sola* "immagine" -> **Funzionale**

#### TODO!

## 