[Fonte](https://www.uniba.it/it/docenti/mininni-michele/attivita-didattica/dispense-e-altro-materiale/algebra-lineare)
# Capitolo 1 - Calcolo Vettoriale e Matriciale
## Vettori e Calcolo Vettoriale
Si dice **vettore** o punto in $\mathbb{R}^3$ ogni $n$-pla ordinata di numeri reali. Un vettore viene rappresentato come una riga o, più spesso, come una colonna:
$$x=(x_{1},x_{2},\dots,x_{n}) \text{ vettore riga} \quad x=\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix} \text{ vettore colonna}$$
Se $n=2$ il vettore $x=(x_{1},x_{2})$, può essere identificato come il punto $P$ nel piano di coordinate $(x_{1},x_{2})$.
Il segmento $OP$ spiega la denominazione di "vettore", poiché determina una direzione nel piano o nello spazio $n$-dimensionale.
Si noti che dal teorema di Pitagora segue la lunghezza di $OP$:
$$\sqrt{ x_{1}^{2}+x_{2}^{2} }$$
In generale se $x=(x_{1},x_{2},\dots,x_{n})$ è un vettore in $\mathbb{R}^{n}$, dicesi **lunghezza** o **intensità** o **norma euclidea** del vettore $x$ il numero reale:
$$
|| x || = \sqrt{ x_{1}^{2}+x_{2}^{2}+\dots+x_{n}^{n}}\geq 0
$$
Nell'insieme $\mathbb{R}^{n}$ dei vettori si definiscono un'operazione di **addizione tra due vettori** e un'operazione di **moltiplicazione di un numero per un vettore**. Infatti, dati un numero $a$ e $x$ i vettori $x+y$ ed $ax$ le cui generiche coordinate $i$-esime sono rispettivamente la somma delle coordinate $i$-esime di $x$ e $y$ e il prodotto di $a$ con la coordinata $i$-esima di $x$:
$$
x+y=
\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix}
+
\begin{pmatrix}
y_{1} \\
y_{2} \\
\vdots \\
y_{n}
\end{pmatrix}
=
\begin{pmatrix}
x_{1}+y_{1} \\
x_{2}+y_{2} \\
\vdots \\
x_{n}+y_{n} \\
\end{pmatrix},
\quad
ax=a
\begin{pmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n}
\end{pmatrix}
=
\begin{pmatrix}
ax_{1} \\
ax_{2} \\
\vdots \\
ax_{n}
\end{pmatrix}
$$
#Esempio 
$$
\begin{pmatrix}
1 \\
2 \\
-3
\end{pmatrix}
+
\begin{pmatrix}
0 \\
-4 \\
2
\end{pmatrix}
=
\begin{pmatrix}
1 \\
-2 \\
-1
\end{pmatrix},
\quad
-2
\begin{pmatrix}
1 \\
-3 \\
\frac{5}{2}
\end{pmatrix}
=
\begin{pmatrix}
-2 \\
6 \\
-5
\end{pmatrix}
$$
Il vettore con coordinate nulle si dice **vettore nullo**, denotato con $0$. Per ogni $x=(x_{1},x_{2},\dots,x_{n})\in \mathbb{R}^{n}$, il vettore $(-1)\cdot x=(-x_{1},-x_{2},\dots,-x_{n})$, denotato $-x$, detto **vettore opposto** ad $x$. Si dice **vettore differenza** tra $y$ e $x$ il vettore $y-x=y+(-x)$.
Infine, dati due vettori $x$ e $y$, si dice **prodotto scalare** di $x$ e $y$:
$$(x|y)=x_{1}y_{1}+x_{2}y_{2}+\dots+x_{n}y_{n}$$
#Esempio se $x=\left( 1,2,-\frac{1}{2} \right)$ ed $y=\left(-2,\frac{1}{3}, -3\right)$:
$$(x|y)=1\cdot(-2)+\frac{1}{3} +\left( -\frac{1}{2} \right)\cdot(-3)=\frac{1}{6}$$
#Osservazione 1.1
Nel caso $n=2$, possiamo dare una interpretazione geometrica interessante del vettore $-x$, del vettore prodotto di uno scalare $a$ per un vettore $x$, del vettore somma $x+y$, del vettore differenza $y-x$ e del prodotto scalare dei vettori $x$ e $y$.
Infatti, detti $P$ e $Q$ i punti del piano in cui $x$ e $y$ sono i vettori delle coordinate rispetto ad un assegnato riferimento cartesiano ortogonale monometrico, allora si ha:
1. $-x$ è il vettore delle coordinate del punto $P'$ simmetrico di $P$ rispetto all'origina $O$; in altri termini $-x$ ha la stessa direzione e lunghezza, ma verso opposto al vettore $x$.
2. Se $\alpha>0$, allora il vettore $ax$ ha la stessa direzione e lo steso verso del vettore $x$ ed una lunghezza pari al prodotto di $a$ per la lunghezza di $x$.
3. Se $\alpha<0$, allora $\alpha x=- |\alpha|x$ è il vettore che ha la stessa direzione e verso opposto al vettore $x$ ed una lunghezza pari al prodotto di $|a|$ per la lunghezza di $x$.
4. $x+y$ rappresenta il vettore dele coordinate del punto $R$, quarto vertice del parallelogramma di cui lati sono $OP$ ed $OQ$
5. $y-x=y+(-x)$ è il vettore delle coordinate cartesiane del punto $R'$, quarto vertice del parallelogramma di cui i lati sono $OP'$ e $OQ$, il segmento orientato $OR'$ è parallelo ed ha la stessa lunghezza e lo stesso verso del segmento orientato $PQ$
In altre parole, nel parallelogramma $OPRQ$ costruito sui vettori $x$ e $y$, il vettore somma $x + y$ rappresenta la diagonale principale $OR$, mentre il vettore differenza $y − x$ rappresenta la diagonale secondaria $PQ$, nel verso da $P$ a $Q$, cioè dalla punta di $x$ alla punta di $y$.
Infine, per quanto riguarda il prodotto scalare di $x = (x1, x2)$ e $y = (y1, y2)$, dette $\alpha$ e $\beta$ le ampiezze degli angoli formati dal semiasse positivo delle ascisse rispettivamente con la semiretta $OP$ e con la semiretta $OQ$, risulta:
$$x_{1}= ||x||\cos a, \quad x_{2}=||x||\sin a, \quad y_{1}=||y||\cos \beta, \quad y_{2}=||y||\sin \beta$$
Quindi:
$$(x|y)=x_{1}y_{1}+x_{2}y_{2}=||x||\cdot||y||\cdot(\cos \alpha \cos \beta+\sin \alpha \sin \beta)=||x||\cdot||y||\cdot \cos(\alpha-\beta)$$
> [In altri termini si dice che]
Il prodotto scalare di due vettori piani è uguale al prodotto delle loro norme per il coseno dell’angolo $\theta=\alpha-\beta$ compreso tra di essi, cioè tra le semirette orientate $OP$ ed $OQ$.

#Osservazione 1.2
Per ogni $\alpha,\beta \in \mathbb{R}$ e per ogni $x,y,z\in\mathbb{R}^{n}$, esistono le proprietà:
$$\begin{align}
(A1) \quad\quad\quad & x+y=y+x\\
(A2) \quad\quad\quad & x+(y+z)=(x+y)+z\\
(A3) \quad\quad\quad & x+0=0+x=x \\
(A4) \quad\quad\quad & x+(-x)=(-x)+x=0 \\
(M1) \quad\quad\quad & \alpha(x+y)=\alpha x+\alpha y \\
(M2) \quad\quad\quad & (\alpha+\beta)x=\alpha x+\beta x \\
(M3) \quad\quad\quad & \alpha(\beta x)=(\alpha \beta)x \\
(M4) \quad\quad\quad &  1x=x\\
\end{align}$$
Le principali proprietà del prodotto scalare sono:
$$\begin{align}
(S1) \quad\quad\quad & (x|y)=(y|x)\\
(S2) \quad\quad\quad & (x'+x''|y)=(x'|y)+(x''|y), \quad (x|y'+y'')=(x|y')+(x|y'')\\
(S3) \quad\quad\quad & (\alpha x|y)=\alpha(x|y)=(x|\alpha y) \\
(S4) \quad\quad\quad & (x|x)=x_{1}^{2}+x_{2}^{2}+\dots+x_{n}^{2}=||x||^{2}\geq 0 \\
(S5) \quad\quad\quad & (x|x)=0 \quad \text{se e solo se } \ x=0 \\
\end{align}$$
#Osservazione 1.3
**Proprietà associativa**
$$v_{1}+v_{2}+v_{3}=(v_{1}+v_{2})+v_{3}=v_{1}+(v_{2}+v_{3}) \quad \forall v_{1},v_{2},v_{3}\in\mathbb{R}^{n}$$
**Combinazione lineare**
Siano $v_{1},v_{2},\dots,v_{k}$ $k$ vettori ed $\alpha_{1},\alpha_{2},\dots,\alpha_{k}$ $k$ numeri reali (coefficienti), allora:
$$\alpha_{1}v_{1}+\alpha_{2}v_{2}+\dots+\alpha_{k}v_{k}$$
#Osservazione 1.4
Tutto ciò può essere replicato con delle minime modifiche per i numeri complessi.
Ad esempio $(i,1+1,2-3i,-4)$ è un vettore complesso quadridimensionale. Si dice vettore complesso $n$-dimensionale una qualunque $n$-pla ordinata $x=(x_{1},x_{2},\dots,x_{n})$ di numeri complessi denotato con $\mathbb{C}^{n}$.
La norma di un vettore $x=x_{1},x_{2},\dots,x_{n}$ di numeri complessi è:
$$||x||=\sqrt{ |x_{2}|^{2}+|x_{2}|^{2}+\dots+|x_{n}|^{2} }\geq 0$$
dove $|\alpha|$ è il modulo di qualunque numero complesso $\alpha$.
Il prodotto scalare di due vettori $x$ e $y$ in $\mathbb{C}^{n}$ è:
$$(x|y)=x_{1}\overline{y_{1}}+x_{2}+\overline{y_{2}}+\dots+x_{n}\overline{y_{n}}$$
dove $\overline{a}$ è il numero complesso coniugato di $\alpha$, per ogni numero complesso $\alpha$.
Continuano a valere $(A1-A4),(M1-M4)$, le proprietà sono leggermente diverse:
$$\begin{align}
(S1)' \quad \quad &  (x|y)=\overline{(y|x)}\\
(S2)' \quad \quad &  (x'+x''|y)=(x'|y)+(x''|y), \quad (x|y'+y'')=(x|y')+(x|y'')\\
(S3)' \quad \quad & (\alpha x|y)=\alpha(x|y), \quad (x|\alpha y)=\overline{\alpha}(x|y) \\
(S4)' \quad \quad & (x|x)=|x_{1}|^{2} + x_{2}|^{2} + \dots + |x_{n}|^{2}=\|x_{n}\|^{2}\geq 0 \\
(S5)' \quad \quad & (x|x) = 0 \quad \text{ se e solo se } \ x=0
\end{align}$$
#Osservazione 1.5
Dicesi **spazio vettoriale reale** un qualunque insieme $V$ in cui si può definire una operazione di addizione tra due suoi elementi ed una operazione esterna di moltiplicazione di un numero reale per un elemento di $V$.
Dicesi **spazio euclideo** uno spazio vettoriale reale $V$ in cui è definito un **prodotto scalare**, cioè una funzione $V\times V\mapsto R$ soddisfacente di $(S1)-(S5)$ che associa ad ogni coppia di vettori $(v,w)$ associa uno scalare $\textlangle v,w\textrangle$ che soddisfa tre proprietà:
1. **Linearità**
	1. $\textlangle\alpha v_{1}+\beta v_{2},w\textrangle=\alpha \textlangle v_{1},2\textrangle+\beta\textlangle v_{2},w\textrangle$
2. **Simmetria**
	1. $\textlangle v_{1},v_{2}\textrangle=\textlangle v_{2},v_{1}\textrangle$
3. **Se uno dei due vettori è nullo di $V$, il prodotto scalare è zero**
	1. $\textlangle v_{1},0_{V}\textrangle=\textlangle 0_{V},v_{1}\textrangle=0$
Il prodotto scalare è **definito positivo** se:
$\forall v\in V$ con $v\neq 0$
$$\textlangle v,v\textrangle>0$$
## Matrici di tipo $k\times n$
Dicesi matrice del tipo $k\times n$ una matrice con $k$ righe e $n$ colonne.
$$A=\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
a_{21} & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots\\
a_{k1} & a_{k2} & \dots & a_{kn}
\end{pmatrix}$$
- $A_{i}$ rappresenta la riga $i$-esima, $\forall i=1,2,\dots,k$
- $A^{j}$ rappresenta la colonna $j$-esima, $\forall j=1,2,\dots,n$

Se $A$ è una matrice $k\times n$, scambiando righe e colonne otteniamo la **matrice trasposta** di $A$, $A^{T}$
La prima riga di $A^{T}$ coincide con la prima colonna di $A$ e così via:
#Esempio 
$$
\begin{pmatrix}
1 & 2 & 4 \\
-2 & 0 & -3
\end{pmatrix}^{T}
=
\begin{pmatrix}
1 & -2 \\
2 & 0 \\
4 & -3
\end{pmatrix}
$$
$((A)^{T})^{T}=A$ la trasposta della trasposta coincide con $A$.
In una matrice $A$ è utile distinguere una **sottomatrice** $B$ formata dalle prime $k_{1}$ righe di $A$ e la sottomatrice $C$ formata dalle restanti $k_{2}=k-k_{1}$ righe. Si dice decomposta in blocchi:
$$A=\begin{pmatrix}
B \\
C
\end{pmatrix}$$
Analogamente
$$A=\begin{pmatrix}
B & C
\end{pmatrix}$$
serve a rappresentare la decomposizione di $A$ nei due blocchi formati rispettivamente dalle prime $n1$ colonne e dalle restanti $n_{2} = n − n_{1}$ colonne.
## Matrici quadrate
Se il numero $k$ delle righe coincide con il numero $n$ delle colonne si dice che la matrice è **matrice quadrata di ordine $n$**.
Se $A$ è matrice quadrata, i numeri $a_{11},a_{22},\dots,a_{nn}$ si dice che formano la **diagonale** di $A$.
Si dice che $A$ è matrice quadrata **simmetrica** se coincide con al sua trasposta $A^{T}$, quindi se gli elementi simmetrici rispetto alla diagonale $a_{ij}$ ed $a_{ji}$ sono uguali:
$$
A=
\begin{pmatrix}
2 & -1 & 3 & 4 \\
-1 & 4 & 0 & 3 \\
3 & 0 & -1 & -2 \\
4 & 3 & -2 & 2
\end{pmatrix}
$$
- Si dice che $A$ è **triangolare superiore** se sono nulli tutti gli elementi di $A$ al di sotto della diagonale.
- Si dice che $A$ è **triangolare inferiore** se sono nulli tutti gli elementi di $A$ al di sopra della diagonale.
- Si dice che $A$ è **matrice diagonale** se sono nulli tutti gli elementi di $A$ tranne quelli della diagonale.
$$
A=\begin{pmatrix}
1 & 2 & 3 & 5 \\
0 & 2 & -1 & 4 \\
0 & 0 & 3 & 5 \\
0 & 0 & 0 & -3
\end{pmatrix},
\quad
B=\begin{pmatrix}
1 & 0 & 0 & 0 \\
2 & 0 & 0 & 0 &  \\
3 & 2 & 1 & 0 &  \\
1 & -1 & 0 & 2
\end{pmatrix},
\quad
C=\begin{pmatrix}
1 & 0 & 0 & 0 \\
0 & 2 & 0 & 0 \\
0 & 0 & -2 & 0 \\
0 & 0 & 0 & 3
\end{pmatrix}
$$
La matrice che ha uguali ad $1$ tutti gli elementi della diagonale prende il nome di **matrice identica** $I_{n}$.
## Operazioni tra matrici
Nell’ insieme delle matrici di tipo $k \times n$ si definiscono un’operazione di addizione tra due matrici e una operazione di moltiplicazione di un numero reale $\alpha$ per una matrice.
$$
\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
a_{21} & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots \\
a_{k1} & a_{k2} & \dots & a_{kn}
\end{pmatrix}
+
\begin{pmatrix}
b_{11} & b_{12} & \dots & b_{1n} \\
b_{21} & b_{22} & \dots & b_{2n} \\
\dots & \dots & \dots & \dots \\
b_{k1} & b_{k2} & \dots & b_{kn}
\end{pmatrix}
=
\begin{pmatrix}
a_{11}+b_{11} & \dots & a_{1n}+b_{1n} \\
a_{21}+b_{21} & \dots & a_{2n}+b_{2n} \\
\dots & \dots & \dots \\
a_{k1}+b_{k1} & \dots & a_{kn}+b_{kn}
\end{pmatrix}
$$
$$\alpha
\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
a_{21} & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots \\
a_{k1} & a_{k2} & \dots & a_{kn}
\end{pmatrix}
=
\begin{pmatrix}
\alpha a_{11} & \alpha a_{12} & \dots & \alpha a_{1n} \\
\alpha a_{21} & \alpha a_{22} & \dots & \alpha a_{2n} \\
\dots & \dots & \dots & \dots \\
\alpha a_{k1} & \alpha a_{k2} & \dots & \alpha a_{kn}
\end{pmatrix}
$$
#Esempio 
$$
\begin{pmatrix}
1 & 2 & 4 \\
-2 & 0 & -3
\end{pmatrix}
+
\begin{pmatrix}
0 & -1 & 3 \\
-4 & 1 & 2
\end{pmatrix}
=
\begin{pmatrix}
1 & 1 & 7 \\
-6 & 1 & -1
\end{pmatrix}
$$
$$-2
\begin{pmatrix}
1 & 2 & 0 \\
2 & -3 & \frac{5}{2}
\end{pmatrix}
=
\begin{pmatrix}
-2 & -4 & 0 \\
-4 & 6 & -5
\end{pmatrix}
$$
Proprietà:
$$
\begin{align}
(A1) \quad\quad &A+B=B+A \\
(A2) \quad\quad &A+(B+C)=(A+B)+C \\
(A3) \quad\quad &A+0=0+A=A \\
(A4) \quad\quad &A+(-A)=(-A)+A=0 \\
(M1) \quad\quad &\alpha(A+B)=\alpha A+\alpha B \\
(M2) \quad\quad &(\alpha+\beta)A=\alpha A+\beta A \\
(M3) \quad\quad &\alpha(\beta A)=(\alpha \beta)A \\
(M4) \quad\quad &1A=A
\end{align}
$$
## Prodotto matriciale
Sia $A$ una matrice di tipo $k\times n$ e $B$ $n\times p$, si dice **matrice prodotto** di $A$ e $B$ la matrice $C=AB$ con $k$ righe e $p$ colonne il cui elemento generico $c_{ij}$ è il prodotto scalare della riga $i$-esima di $A$ per la colonna $j$-esima di $B$:
$$c_{ij}=(A_{i}|B^{j})=\displaystyle\sum_{h=1}^{n}a_{ih}b_{hj}, \quad \text{per ogni }i=1,2,\dots,k \quad \text{e per ogni }j=1,2,\dots,p$$
#Esempio 
$$
\begin{pmatrix}
2 & 1 \\
1 & 0
\end{pmatrix}
\begin{pmatrix}
1 & -1 \\
0 & 2
\end{pmatrix}
=
\begin{pmatrix}
2 & 0 \\
1 & -1
\end{pmatrix}
$$
$$
\begin{pmatrix}
1 & -1 \\
0 & 2
\end{pmatrix}
\begin{pmatrix}
2 & 1 \\
0 & 2
\end{pmatrix}
=
\begin{pmatrix}
1 & 1 \\
2 & 0
\end{pmatrix}
$$
Dunque il prodotto matriciale **non gode** della proprietà commutativa $AB=BA$.
Proprietà:
$$
\begin{align}
(P1) \quad\quad &A(BC)=(AB)C \\
(P2) \quad\quad &I_{k}A=A, \quad AI_{n}=A \\
(P3) \quad\quad &A(B*C)=AB+AC, \quad (B+C)A=BA+CA \\
(P4) \quad\quad &(\alpha A)B=\alpha(AB)=A(\alpha B) \\
(P5) \quad\quad &(AB)^{T}=B^{T}A^{T}
\end{align}
$$
## Algoritmo di Gauss Jordan
Se $A$ è una matrice non nulla di tipo $k\times n$, le seguenti operazioni:
1. scambiare di posto due righe o due colonne
2. aggiungere ad una riga un multiplo di un'altra
3. moltiplicare o dividere una riga per una costante $\alpha \neq 0$
vengono dette **operazioni elementari** sulla matrice $A$.
Se $a_{hj}\neq 0$, usando in maniera sistematica 2. è possibile trasformare la matrice $A$ in una matrice in cui sono nulli tutti gli elementi della colonna $j$-esima ad eccezione di $a_{hj}$:
$$A=
\begin{pmatrix}
1 & 3 & -2 & 0 \\
-2 & 1 & 2 & -3 \\
3 & 1 & -4 & 2 \\
-3 & -1 & 3 & -2
\end{pmatrix}$$
considerato che $a_{11}=1\neq 0$, sostituendo la riga $A_{2}$ con $A_{2}+2A_{1}$, la riga $A_{3}$ con $A_{3}-3A_{1}$ e la riga $A_{4}$ con $A_{4}+3A_{1}$ si ottiene:
$$A'=
\begin{pmatrix}
1 & 3 & -2 & 0 \\
0 & 7 & -2 & -3 \\
0 & -8 & 2 & 2 \\
0 & 8 & -3 & -2
\end{pmatrix}
$$
analogamente sostituendo al riga $A_{1}$ con $A_{1}+A_{2}$, la riga $A_{3}+2A_{2}$ e la riga $A_{4}$ con $A_{4}-\left( \frac{3}{2} \right)A_{2}$ si ottiene:
$$A''=
\begin{pmatrix}
-1 & 4 & 0 & -3 \\
-2 & 1 & 2 & -3 \\
-1 & 3 & 0 & -4 \\
0 & -\frac{5}{2} & 0 & \frac{5}{2}
\end{pmatrix}
$$
La procedura di sostituzione delle righe di $A$ in modo da rendere nulli tutti gli elementi della colonna $j$-esima tranne $a_{hj}$ e rendere uguale ad 1 tale elemento dicesi **passo di pivot** su $a_{hj}$ e l'elemento non nullo di $a_{hj}$dicesi **pivot** o cardine del processo.
Se ci limitiamo ad eseguire l’operazione 2. solo sulle righe sotto il pivot, cioè solo per $i > h$, allora $A$ verrà trasformata in una matrice in cui sono nulli tutti gli elementi della colonna $j$-esima sotto il pivot $a_{hj}$ . Questa seconda procedura verrà detta passo di **pivot parziale** su $a_{hj}$.
#proposizione 6.1 (Algoritmo di Gauss Jordan)
Mediante passi di pivot parziali, scambi di riga e, (se necessario), scambi di colonna, è possibile trasformare una qualunque matrice non nulla $A$ di tipo $k \times n$ in una matrice $A'$ che può essere decomposta a blocchi in una delle forme
$$B,\quad \begin{pmatrix}B & C\end{pmatrix},\quad \begin{pmatrix}B\\O\end{pmatrix},\quad \begin{pmatrix}B & C\\O & O\end{pmatrix}$$
In primo luogo, scambiando la prima riga con una delle successive o, (se necessario), scambiando la prima colonna con una delle successive, possiamo fare in modo che $a_{11}\neq 0$. Eseguendo un passo di pivot parziale su $a_{11}$, la matrice $A$ viene trasformata in una matrice di tipo:
$$
\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
0 & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots \\
0 & a_{k2} & \dots & a_{kn}
\end{pmatrix}
\quad\text{cioè}\quad
\begin{pmatrix}
B & C \\
O & C'
\end{pmatrix}
\quad\text{dove}\quad
B=\begin{pmatrix}
a_{11}
\end{pmatrix}
$$
A questo punto se $C'$ è la matrice nulla, la tesi è stata dimostrata; in caso contrario scambiando eventualmente la attuale seconda riga con una delle successive, possiamo fare in modo che $a_{22}\neq 0$. Eseguendo un passo di pivot parziale su $a_{22}$, la matrice $A$ viene trasformata in:
$$
\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
0 & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots \\
0 & 0 & \dots & a_{kn}
\end{pmatrix}
\quad\text{cioè}\quad
\begin{pmatrix}
B & C \\
O & C'
\end{pmatrix}
\quad\text{dove}\quad
B=\begin{pmatrix}
a_{11} & a_{12} \\
0 & a_{22}
\end{pmatrix}
$$
A questo punto se $C'$ è la matrice nulla, la tesi è stata dimostrato, in caso contrario si ripete lo stesso procedimento finché possibile.
#Osservazione 6.2
Si noti che se modifichiamo l’algoritmo di Gauss Jordan, nel senso che effettuiamo passi di pivot completi anziché parziali, ed effettuiamo un passo di pivot completo anche sull’eventuale elemento diagonale non nullo della $k$-sima riga, allora $A$ verrà trasformata in una matrice $A'$ che si può decomporre a blocchi in una delle forme:
$$
i_{k},\quad \begin{pmatrix}I_{k} & C\end{pmatrix},\quad \begin{pmatrix}I_{n} \\O\end{pmatrix},\quad \begin{pmatrix}I_{r} & C \\O & O\end{pmatrix}
$$
Viene detto **algoritmo di Gauss Jordan completo**.
## Generalità sui sistemi lineari
Capita di dover cercare dei numeri $x_{1},x_{2},\dots,x_{n}$ che soddisfano contemporaneamente un numero finito di equazioni di primo grado nelle incognite $x_{1},x_{2},\dots,x_{n}$, ovvero, un **sistema di equazioni lineari**. Un sistema di $k$ equazioni lineari in $n$ incognite si rappresenta dunque la forma:
$$\begin{cases}
a_{11}x_{1}+a_{12}x_{2}+\dots+a_{1n}x_{n}=b_{1} \\
a_{21}x_{1}+a_{22}x_{2}+\dots+a_{2n}x_{n}=b_{2} \\
\dots \ \dots \ \dots \\
a_{k1}x_{1}+a_{k2}x_{2}+\dots+a_{kn}x_{n}=b_{k}
\end{cases}$$
A tale sistema resta associata la matrice con $k$ righe e $n$ colonne:
$$A=
\begin{pmatrix}
a_{11} & a_{12} & \dots & a_{1n} \\
a_{21} & a_{22} & \dots & a_{2n} \\
\dots & \dots & \dots & \dots \\
a_{k1} & a_{k2} & \dots & a_{kn}
\end{pmatrix}$$
viene detta la matrice dei **coefficienti** del sistema.
Invece il vettore colonna $b=(b_{1},b_{2},\dots,b_{k})^{T}$ dicesi il **vettore dei termini noti** del sistema.
Infine dicesi **soluzione** del sistema ogni vettore $x=(x_{1},x_{2},\dots,x_{n})^{T}$ le cui coordinate soddisfano simultaneamente tutte le equazioni del sistema.

Interpretando $x$ e $b$ rispettivamente come matrici di tipo $n \times 1$ e $k \times 1$, allora $x=(x_{1},x_{2},\dots,x_{n})^{T}$ è soluzione del sistema se e solo se risulta $Ax=b$. Pertanto il sistema può essere rappresentato sotto forma di equazione matriciale
$$Ax=b$$
#Definizione 7.1
Il sistema $Ax=b$ si dice **compatibile** se ha almeno una soluzione, **incompatibile** se non ha nessuna soluzione. Un sistema compatibile si dice **determinato** se ha una sola soluzione, **indeterminato** se ha almeno due soluzioni.
Si dice **omogeneo** se il vettore $b$ dei termini noti è il vettore nullo, si dice **non omogeneo** se $b\neq 0$.
#Osservazione 7.2
Se il sistema $Ax=b$ è indeterminato, allora esso ha infinite soluzioni.
Infatti, se $x'$ e $x''$ sono due distinte soluzioni del sistema $Ax=b$, allora $\forall \alpha\in R$ si ha che anche $\alpha x'+(1-\alpha)x''$ è soluzione dello stesso sistema poiché:
$$A(\alpha x'+(a-\alpha)x'')=\alpha Ax'+(a-\alpha)Ax''=ab+(a-\alpha)b=\alpha b+b-\alpha b=b$$
#Osservazione 7.3
È evidente inoltre che un sistema omogeneo è sempre compatibile perché il vettore nullo è sempre una soluzione; per i sistemi omogenei il problema significativo è dunque cercare le eventuali soluzioni non nulle.

I problemi che dobbiamo affrontare nello studio dei sistemi lineari sono:
1. sotto quali condizioni un sistema lineare omogeneo ha solo la soluzione banale $x=0$?
2. sotto quali condizioni un sistema non omogeneo è compatibile o incompatibile?
3. se il sistema è compatibile, sotto quali condizioni è determinato o indeterminato?
4. se il sistema è indeterminato, qual'è la struttura dell'insieme delle soluzioni?
5. come si fa a trovare la soluzione o le soluzioni del sistema?

#Osservazione 7.4
Per il momento ci limitiamo ad osservare che: il sistema $Ax=b$ viene trasformato in un sistema equivalente se:
- si scambiano di posto due equazioni
- si moltiplicano i coefficienti e il termine notto di un'equazione per una costante $\neq 0$
- si aggiunge ad una equazione il multiplo di un'altra equazione
Cioè se nella matrice $(A,b)$ dei coefficienti e termini noti del sistema:
- si scambiano di posto due righe
- si moltiplica o divide una riga per un numero costante $\neq 0$
- si aggiunge ad una riga il multiplo di un'altra







