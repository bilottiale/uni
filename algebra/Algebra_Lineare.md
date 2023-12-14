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
La matrice che ha uguali ad $1$ tutti gli elementi della diagonale prende il nome di **matrice identità** $I_{n}$.
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
# Capitolo 2 - Determinanti
#Definizione 1.1
Dicesi **determinante** di una matrice quadrata $A$ di ordine $n$, $\det(A)$, il numero reale ottenuto secondo la seguente procedura:
1. si prende una matrice quadrata $A'$ ottenuta da $A$ scambiando di posto le colonne, si calcola il prodotto degli elementi diagonali di $A'$ e si prende tale prodotto con il proprio segno o con il segno cambiato a seconda che $A'$ sia stata ottenuta da $A$ con un numero pari o dispari di scambi di colonne
2. si ripete il passo 1. per tutte le matrici quadrate $A'$ che è possibile ottenere da $A$ scambiando di posto le colonne
3. si calcola la somma di tutti i numeri ottenuti con il procedimento descritto dal passo 1.
In altri termini il determinante di $A$ è la somma degli $n!$ numeri reali del tipo:
$$(-1)^{k}a_{1,j_{1}}\cdot a_{2,j_{2}}\cdot\dots \cdot a_{n,j_{n}}$$
dove $(j_{1},j_{2},\dots,j_{n})$ è una permutazione dell'insieme ${1,2,\dots,n}$ e $k$ il numero degli scambi di indici necessari per ottenere la permutazione $(j_{1},j_{2},\dots,j_{n})$ dalla permutazione naturale $(1,2,\dots,n)$.
#Definizione 1.2
Si dice che $A$ è una matrice **singolare** o **non singolare** a seconda che i risulti $\det(A)=0$ o $\det(A)\neq 0$.
#Esempio 
Se $n=2$, le uniche due matrici che è possibile ottenere sono:
$$
\begin{pmatrix}
a_{11} & a_{12} \\
a_{21} & a_{22}
\end{pmatrix}
\quad
(\text{con 0 scambi})
\quad
\text{e}
\quad
\begin{pmatrix}
a_{12} & a_{11} \\
a_{22} & a_{21}
\end{pmatrix}
\quad
(\text{con 1 scambio})
$$
Ne segue che, per ogni matrice $A$ di ordine $2$:
$$\det A=\det \begin{pmatrix}
a_{11} & a_{12} \\
a_{21} & a_{22}
\end{pmatrix}
=a_{11}a_{22}-a_{12}a_{21}$$
#Esempio 
$$
\det
\begin{pmatrix}
3 & -5 \\
2 & -4
\end{pmatrix}
= 3(-4)-2(4)=-2
\quad\quad
\det \begin{pmatrix}
-2 & 4 \\
\frac{1}{2} & -3
\end{pmatrix}
= (-2)(-3)-4\left( \frac{1}{2} \right)=4
$$
#Esempio 
Se $n=3$, allora le $3! =6$ matrici che possibile ottenere da $A$ scambiando le colonne sono:
$$
\begin{pmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}
\quad (\text{con 0 scambi})
$$
$$
\begin{pmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix},
\begin{pmatrix}
a_{13} & a_{12} & a_{11} \\
a_{23} & a_{22} & a_{21} \\
a_{33} & a_{32} & a_{31}
\end{pmatrix},
\begin{pmatrix}
a_{13} & a_{11} & a_{12} \\
a_{23} & a_{21} & a_{22} \\
a_{33} & a_{31} & a_{32}
\end{pmatrix}, \quad (\text{con 1 scambio})
$$
$$
\begin{pmatrix}
a_{12} & a_{13} & a_{11} \\
a_{22} & a_{23} & a_{21} \\
a_{32} & a_{33} & a_{31}
\end{pmatrix},
\begin{pmatrix}
a_{13} & a_{11} & a_{12} \\
a_{23} & a_{21} & a_{22} \\
a_{33} & a_{31} & a_{32}
\end{pmatrix}, \quad (\text{con 2 scambi})
$$
Ne segue che:
$$
\det(A)=\det
\begin{pmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}=
$$
$$
=a_{11}a_{22}a_{33}+a_{12}a_{23}a_{31}+a_{13}a_{21}a_{32}-a_{12}a_{21}a_{33}-a_{13}a_{22}a_{31}-a_{11}a_{23}a_{32}
$$
#Teorema 1.3 Proprietà dei determinanti
![[Pasted image 20231203181224.png]]
## Algoritmo di Gauss Jordan per il calcolo del determinante di una matrice
#Osservazione 2.2
Utilizzando le mosse di Gauss su $A$ possiamo ottenere una matrice triangolare $A'$.
#Esempio 
$$
A=
\begin{pmatrix}
1 & 2 & -1 & 0 \\
2 & -1 & -2 & -1 \\
-1 & 8 & 0 & 3 \\
0 & 5 & 4 & 0 & 
\end{pmatrix}
$$
eseguiamo un passo di pivot parziale sull'elemento $a_{11}=1$, cioè sostituiamo la riga $A_{2}$ con $A_{2}-2A_{1}$ e la riga $A_{3}$ con $A_{3}+A_{1}$:
$$
\begin{pmatrix}
1 & 2 & -1 & 0 \\
0 & -5 & 0 & -1 \\
0 & 10 & -1 & 3 \\
0 & 5 & 4 & 0
\end{pmatrix}
$$
eseguiamo un secondo passo di pivot parziale su $a_{22}=-5$, cioè sostituiamo la riga $A_{3}$ con $A_{3}+2A_{2}$ e la riga $A_{4}$ con $A_{4}+A_{2}$:
$$
\begin{pmatrix}
1 & 2 & -1 & 0 \\
0 & -5 & 0 & -1 \\
0 & 0 & -1 & 1 \\
0 & 0 & 4 & -1
\end{pmatrix}
$$
eseguiamo infine un terzo passo di pivot parziale su $a_{33}=-1$, cioè sostituiamo la riga $A_{4}$ con $A_{4}+4A_{3}$ e otteniamo la matrice triangolare superiore:
$$
A'=
\begin{pmatrix}
1 & 2 & -1 & 0 \\
0 & -5 & 0 & -1 \\
0 & 0 & -1 & 1 \\
0 & 0 & 0 & 3
\end{pmatrix}
$$
#Teorema 2.3 **(di Binet)**
Se $A$ e $B$ sono matrici quadrate di ordine $n$, allora si ha:
$$\det(AB)=\det A\cdot \det B$$
## Regola di Laplace
In alternativa all'algoritmo di Gauss Jordan, il determinante di una matrice quadrata può essere calcolato in un altro modo.
#Definizione 
Sia $A$ una matrice quadrata di ordine $n>1$ e, $\forall i,j=1,2,\dots,n$, indichiamo con $A_{ij}$ la matrice quadrata di ordine $n-1$ ottenuta eliminando da $A$ la riga $i$-esima e la colonna $j$-esima.
$\det A_{ij}$ dicesi **minore complementare** dell'elemento $a_{ij}$ di $A$
$(-1)^{i+j}\det A_{ij}$ dicesi **complemento algebrico** di $a_{ij}$
#Teorema 2.3 **(di Laplace)**
Se $A$ è una matrice quadrata di ordine $n>1$, allora il determinante di $A$ è uguale alla somma dei prodotti degli elementi di una qualunque riga o colonna per i rispettivi complementi algebrici.
In altri termini $\forall h=1,2,\dots,n$ si ha:
$$\det A=\displaystyle\sum_{j=1}^{n}(-1)^{h+j}a_{hj}\cdot \det A_{hj}=\sum_{i=0}^{n}(-1)^{i+j}a_{ih}\cdot \det A_{ih}$$
#Dimostrazione 
Dimostriamo la tesi per $n=3$ prendendo come base di calcolo la prima riga.
Dette $E_{1},E_{2},E_{3}$ le righe della matrice identità, essendo $A_{1}=a_{11}E_{1}+a_{12}E_{2}+a_{13}E_{3}$, per le proprietà $(D6-D7)$ si ha:
$$
\det A=a_{11}\det
\begin{pmatrix}
1 & 0 & 0 \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}
+a_{12}\det
\begin{pmatrix}
0 & 1 & 0 \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}
+a_{13}\det
\begin{pmatrix}
0 & 0 & 1 \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{pmatrix}
$$
Effettuando un passo di pivot parziale sull'elemento non nullo della prima riga di ciascuna matrice si ha:
$$
\det A=a_{11}\det
\begin{pmatrix}
1 & 0 & 0 \\
0 & a_{22} & a_{23} \\
0 & a_{32} & a_{33}
\end{pmatrix}
+a_{12}\det
\begin{pmatrix}
0 & 1 & 0 \\
a_{21} & 0 & a_{23} \\
a_{31} & 0 & a_{33}
\end{pmatrix}
+a_{13}\det
\begin{pmatrix}
0 & 0 & 1 \\
a_{21} & a_{22} & 0 \\
a_{31} & a_{32} & 0
\end{pmatrix}
$$
Ora scambiamo la prima con la seconda colonna:
$$
\det
\begin{pmatrix}
0 & 1 & 0 \\
a_{21} & 0 & a_{23} \\
a_{31} & 0 & a_{33}
\end{pmatrix}
=-\det
\begin{pmatrix}
0 & 1 & 0 \\
0 & a_{22} & a_{23} \\
0 & a_{32} & a_{33}
\end{pmatrix}
$$
Invece, con due scambi di colonna si ha:
$$
\det
\begin{pmatrix}
0 & 0 & 1 \\
a_{21} & a_{22} & 0 \\
a_{31} & a_{32} & 0
\end{pmatrix}
=-\det
\begin{pmatrix}
0 & 1 & 0 \\
a_{21} & 0 & a_{23} \\
a_{31} & 0 & a_{33}
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 0 & 0 \\
0 & a_{22} & a_{23} \\
0 & a_{32} & a_{33}
\end{pmatrix}
$$
Infine, eseguire l'algoritmo di Gauss Jordan sulle matrici
$$
\begin{pmatrix}
1 & 0 & 0 \\
0 & a_{22} & a_{23} \\
0 & a_{32} & a_{33}
\end{pmatrix},
\quad\quad
\begin{pmatrix}
1 & 0 & 0 \\
0 & a_{21} & a_{23} \\
0 & a_{31} & a_{33}
\end{pmatrix},
\quad\quad
\begin{pmatrix}
1 & 0 & 0 \\
0 & a_{21} & a_{22} \\
0 & a_{31} & a_{32}
\end{pmatrix}
$$
## Sistemi lineari non omogenei - Teorema di Cramer
L’algoritmo di Gauss Jordan oltre a consentirci di calcolare facilmente il determinante di una matrice quadrata ci consente anche di risolvere un sistema lineare non omogeneo di $n$ equazioni in $n$ incognite.
#proposizione 4.1
Se $A$ è una matrice quadrata non singolare di ordine $n$, allora $\forall b\in R^{n}$ il sistema lineare non omogeneo $Ax=b$ ha una ed una sola soluzione; tale soluzione è il vettore $b'$ tale che l'algoritmo di Gauss Jordan completo trasforma la matrice $(A,b)$ nella matrice $(I_{n},b')$.
#Dimostrazione 
Per quanto visto nell'osservazione 7.4 del Capitolo 1, il sistema lineare non omogeneo $Ax=b$ è equivalente al sistema $A'x=b'$ dove $(A',b')$ è stata ottenuta da $(A,b)$ mediante l'algoritmo di Gauss Jordan l'algoritmo di Gauss Jordan completo.
D’altra parte, se il determinante di $A$ è $\neq 0$, allora per quanto visto nella Osservazione 2.2, l’algoritmo di Gauss Jordan completo trasforma la matrice $A$ nella matrice $I_{n}$ e quindi $(A,b)$ in $I_{n},b'$.
Pertanto il sistema $Ax=b$ è equivalente al sistema $I_{n}x=b'$, ha l'unica soluzione $x=b'$ e quindi $b'$ è l'unica soluzione del sistema $Ax=b$.
#Esempio 
$$
\left\{\begin{aligned}
&x_1+2 x_2-x_3 & =2 \\
&2 x_1-x_2-2 x_3-x_4 & =-1 \\
&-x_1+8 x_2+3 x_4 & =0 \\
&5 x_2+4 x_3 & =1
\end{aligned}\right.
$$
Cioè
![[Pasted image 20231204174421.png|324]]
![[Pasted image 20231204174441.png]]
Il sistema ha dunque l'unica soluzione $x=\left( -{\frac{44}{5}},\frac{17}{5},-4,-12 \right)^{T}$.

Il teorema di Cramer fornisce un metodo di risoluzione del sistema lineare $Ax=b$ alternativo all'algoritmo di Gauss Jordan.
#Teorema 4.2 **(Teorema di Cramer)**
Se $A$ è una matrice quadrata non singolare, allora $\forall b\in R^{n}$ l'unica soluzione del sistema $Ax=b$ è il vettore $x=(x_{1},x_{2},\dots,x_{n})^{T}$ tale che:
$$
d_{j}=\frac{\det(A^{1},A^{2},\dots,A^{j-1},b,A^{j+1},\dots,A^{n})}{\det A} \quad\quad \forall j=1,2,\dots,n
$$
#Dimostrazione 
Per la proposizione 4.1 sappiamo che il sistema $Ax=b$ ha un'unica soluzione $x$, può essere identificata osservando che $x=(x_{1},x_{2},\dots,x_{n})^{T}$ è soluzione del sistema se e solo se:
$$b=x_{1}A^{1}+x_{2}A^{2}+\dots+x_{n}A^{n}$$
Per le proprietà dei determinanti si ha:
$$
\begin{align}
\det(b,A^{2},\dots,A^{n})&=\det(x_{1}A^{1}+x_{2}A^{2}+\dots+x_{n}A^{n},A^{2},\dots,A^{n})= \\
&=x_{1}\det(A^{1},A^{2},\dots,A^{n})+x_{2}\det(A^{2},A^{2},\dots,A^{n})+\dots+x_{n}\det(A^{n},A^{2},\dots,A^{n})
\end{align}
$$
dal momento che il determinante di una matrice in cui due colonne coincidono è nullo, si deduce che:
$$\det(b,A^{2},\dots,A^{n})=x_{1}\det A\quad \text{ e quindi che }\quad x_{1}=\frac{\det(b,A^{2},\dots,A^{n})}{\det A}$$
Analogamente, $\forall j=2,3,\dots,n$:
$$
\det(A^{1},A^{2},\dots,A^{j-1},b,A^{j+1},\dots,A^{n})=x_{j}\det A
$$
quindi:
$$x_{j}=\frac{\det(A^{1},\dots,A^{j-1},b,A^{j+1},\dots,A^{n})}{\det A}$$
provando la tesi.
#Esempio 2
Risolvere il sistema
$$
\begin{cases}
x+y+z&=1 \\
x-y+z&=0 \\
-x-3y+z&=2
\end{cases}
$$
Calcolare i determinanti
$$
D=\det A=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 1 \\
-1 & -3 & 1
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -2 & 0 \\
0 & -2 & 2
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -2 & 0 \\
0 & 0 & 2
\end{pmatrix}
=-4
$$
$$
D_{x}=\det (b,A^{2},A^{3})=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 1 \\
2 & -3 & 1
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 1 \\
0 & -5 & -1
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 1 \\
0 & 0 & -6
\end{pmatrix}
=6
$$
$$
D_{y}=\det (A^{1}, b, A^{3})=\det
\begin{pmatrix}
1 & 1 & 1 \\
1 & 0 & 1 \\
-1 & 2 & 1
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 0 \\
0 & 3 & 2
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -1 & 0 \\
0 & 0 & 2
\end{pmatrix}
=-2
$$
$$
D_{z}=\det (A^{1},A^{2},b)=\det
\begin{pmatrix}
1 & 1 & 1 \\
1 & -1 & 0 \\
-1 & -3 & 2
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -2 & -1 \\
0 & -2 & 3
\end{pmatrix}
=\det
\begin{pmatrix}
1 & 1 & 1 \\
0 & -2 & -1 \\
0 & 0 & 4
\end{pmatrix}
=-8
$$
L'unica soluzione del sistema è dunque il vettore di coordinate:
$$x=\frac{D_{x}}{D}=-\frac{3}{2},\quad y=\frac{D_{y}}{D}=\frac{1}{2}, \quad z=\frac{D_{z}}{D}=2$$
## Matrici invertibili
Per le matrici quadrate di ordine $n$ è possibile introdurre la nozione di **invertibilità**.
#Definizione 5.1
Se $A$ è una matrice quadrata di ordine $n$, si dice che $A$ è invertibile se esiste una matrice quadrata $B$ di ordine $n$ tale che $BA=AB=I_{n}$.
La matrice inversa è unica e viene denotata anche come $A^{-1}$.
L'unicità è dovuta dal fatto che se $B',B''$ sono due matrici tali che $B'A=I_{n}$ ed $AB''=I_{n}$, allora si ha:
$$B'=B'I_{n}=B'(AB'')=(B'A)B''=I_{n}B''=B''$$
#proposizione 5.2
Se $A$ è una matrice quadrata di ordine $n$, allora le seguenti proprietà sono equivalenti:
1. $A$ è invertibile
2. $\det(A)\neq 0$
3. $\det(A^{T})\neq 0$
4. $A^{T}$ è invertibile

#Dimostrazione di $1. \Rightarrow 2.$, il teorema di Binet segue:
$$\det(A)\cdot \det(A^{-1})=\det(A\cdot A^{-1})=\det(I_{n})=1\neq 0\quad \text{ e quindi che }\quad \det(A)\neq 0$$
#Dimostrazione di $2. \Rightarrow 1.$ per l'osservazione 2.2 si ha $\det(A)\neq 0$ se e solo se l'algoritmo di Gauss Jordan trasforma $A$ in $I_{n}$.
$$A\cdot B=I_{n}\quad\text{ e }\quad B\cdot A=I_{n}$$
#Osservazione 5.3
Affianchiamo alla matrice $A$ la matrice identità $I_{n}$, quindi sulla matrice $(A|I_{n})$ si esegue l'algoritmo di Gauss Jordan:
#Esempio 
Dire se è invertibile e trovare l'eventuale inversa di:
$$
A=
\begin{pmatrix}
1 & 2 & -1 \\
-1 & 3 & -2 \\
4 & -1 & -3
\end{pmatrix}
$$
Consideriamo $(A|I_{n})$:
$$
(A|I_{n})=
\begin{pmatrix}
1 & 2 & -1  & | & 1 & 0 & 0\\
-1 & 3 & -2  & | & 0 & 1 & 0 \\
4 & -1 & -3 & | & 0 & 0 & 1
\end{pmatrix}
$$
effettuiamo le varie mosse di Gauss Jordan:
$A_{2}=A_{2}-A_{1}$ e $A_{3}-4A_{1}$:
$$
\begin{pmatrix}
1 & 2 & -1  & | & 1 & 0 & 0\\
0 & 5 & -3  & | & 1 & 1 & 0 \\
0 & 9 & 1 &   | & -4 & 0 & 1
\end{pmatrix}
$$
$A_{2}=\frac{A_{2}}{5}$ e $A_{1}=A_{1}-\left( \frac{2}{5} \right)A_{2}$ e $A_{3}=A_{3}+\left( \frac{9}{5} \right)A_{2}$:
$$
\begin{pmatrix}
1 & 0 & \frac{1}{5}  & | & \frac{3}{5} & -\frac{2}{5} & 0\\
0 & 1 & -\frac{3}{5}  & | & \frac{1}{5} & \frac{1}{5} & 0 \\
0 & 0 & -\frac{22}{5} &   | & -\frac{11}{5} & \frac{9}{5} & 1
\end{pmatrix}
$$
$A_{1}=A_{1}+\left( \frac{1}{22} \right)A_{3}$ e $A_{3}=A_{2}-\left( \frac{15}{22} \right)A_{3}$ e $A_{3}=\frac{A_{3}}{-\frac{22}{5}}$:
$$
\begin{pmatrix}
1 & 0 & 0  & | & \frac{1}{2} & -\frac{7}{22} & \frac{1}{22} \\
0 & 1 & 0  & | & \frac{1}{2} & -\frac{1}{22} & -\frac{3}{22} \\
0 & 0 & 1 &   | & \frac{1}{2} & -\frac{9}{22} & -\frac{5}{22}
\end{pmatrix}
$$
La matrice $A$ è quindi invertibile e la sua inversa è:
$$
B=
\begin{pmatrix}
\frac{1}{2} & -\frac{7}{22} & \frac{1}{22} \\
\frac{1}{2} & -\frac{1}{22} & -\frac{3}{22} \\
\frac{1}{2} & -\frac{9}{22} & -\frac{5}{22}
\end{pmatrix}
$$
Un metodo alternativo fornito dal teorema di Cramer è:
#proposizione 5.4
La matrice inversa di $A$ coincide con la matrice ottenuta dividendo per $\det(A)$ la matrice trasposta della matrice dei complementi algebrici degli elementi di $A$.
#Dimostrazione 
Sia $x_{ij}$ il generico elemento di $A^{-1}$ e siano $E^{1},E^{2},\dots,E^{n}$ le colonne della matrice identità. Allora la $j$-esima colonna di $A^{-1}$ è la soluzione del sistema $Ax=E^{j}$:
$$x_{ij}=\frac{\det(A^{1},A^{2},\dots,A^{i-1},E^{j},A^{i+1},\dots,A^{n})}{\det(A)}$$
#Esempio 
Nel caso di:
$$
A=
\begin{pmatrix}
1 & 2 & -1 \\
-1 & 3 & -2 \\
4 & -1 & -3
\end{pmatrix}
$$
si ha:
$$
\begin{align}
&\det(A_{11})\begin{pmatrix}
3 & -2 \\
-1 & -3
\end{pmatrix}=-11,
&\det(A_{12})\begin{pmatrix}
-1 & -2 \\
4 & -3
\end{pmatrix}=11,
&&\det(A_{13})\begin{pmatrix}
-1 & 3 \\
4 & -1
\end{pmatrix}=-11,

\\

&\det(A_{21})\begin{pmatrix}
2 & -1 \\
-1 & -3
\end{pmatrix}=-7,
&\det(A_{22})\begin{pmatrix}
1 & -1 \\
-4 & -3
\end{pmatrix}=1,
&&\det(A_{23})\begin{pmatrix}
1 & 2 \\
4 & -1
\end{pmatrix}=-9,

\\

&\det(A_{31})\begin{pmatrix}
2 & -1 \\
3 & -2
\end{pmatrix}=-1,
&\det(A_{32})\begin{pmatrix}
1 & -1 \\
-1 & -2
\end{pmatrix}=-3,
&&\det(A_{33})\begin{pmatrix}
1 & 2 \\
-1 & 3
\end{pmatrix}=5,
\end{align}
$$
La matrice dei complementi algebrici degli elementi di $A$ è la matrice:
$$
\begin{pmatrix}
-11 & -11 & -11 \\
7 & 1 & 9 \\
-1 & 3 & 5
\end{pmatrix}
$$
La trasposta:
$$
\begin{pmatrix}
-11 & 7 & -1 \\
-11 & 1 & 3 \\
-11 & 9 & 5
\end{pmatrix}
$$
Il determinante:
$$\det(A)=\displaystyle\sum_{j=1}^{3}(-1)^{1+j}a_{1j}=-11-2\cdot_{1}1-(-11)=-22$$
L'inversa di $A$ si ottiene dividendo per $-22$ la matrice trasposta coniugata di $A$:
$$
A^{-1}
\begin{pmatrix}
\frac{1}{2} & -\frac{7}{22} & \frac{1}{22} \\
\frac{1}{2} & -\frac{1}{22} & -\frac{3}{22} \\
\frac{1}{2} & -\frac{9}{22} & -\frac{5}{22}
\end{pmatrix}
$$
# Capitolo 3 - Sottospazi, Basi, Dimensioni
## Sottospazi vettoriali
#Definizione 1.1
Un **sottospazio vettoriale** di $R^{n}$ è ogni insieme non vuoto $H\subseteq R^{n}$ tale che:
1. $\forall u,v\in H$ risulta $u+v\in H$
2. $\forall \lambda\in R$ e $\forall v\in H$ risulta $a\cdot v\in H$
In altri termini, un sottospazio vettoriale è un sottoinsieme chiuso alle operazioni di addizione e di prodotto per uno scalare.
### Verificare se un sottoinsieme è uno spazio vettoriale
1. $\forall s_{1},s_{2} \in S, s_{1}+s_{2}\in S$
2. $\forall s\in S, \forall \lambda \in \mathbb{K}, \lambda s\in S$
3. Esiste elemento neutro
#Esempio 
$W$ è sottospazio?
$$W=\{\binom{x}{y}\in R^{2}, 2x-y=0\}$$
esiste elemento nullo?
$$\binom{0}{0}\in W\ ?$$
$$
\begin{align}
&2x-y=0 \\
&2(0)-(0)=0 \quad \text{ con }x=0, y=0\\
&0=0
\end{align}
$$
Si, ora devo verificare le altre due proprietà:
prendo due elementi del sottoinsieme $w_{1}=(x_{1},y_{1}), w_{2}=(x_{2},y_{2})$
li sommo e verifico che $w_{1}+w_{2}\in W$:
$$w_{1}+w_{2}=(x_{1},y_{1})+(x_{2}+y_{2})=(x_{1}+x_{2}),(y_{1},y_{2})$$
$$
\begin{align}
&2x-y=0 \\
&2(x_{1}+x_{2})-(y_{1}+y_{2})=0 \\
&2x_{1}+2x_{2}-y_{1}-y_{2}=0 \\
&(2x_{1}-y_{2})+(2x_{2}-y_{2})=0
\end{align}
$$
so che $(2x-y)=0$ e che $0+0=0$ quindi la somma appartiene a $W$.
Ora verifichiamo per il prodotto scalare:
prendo un elemento in $W$ e uno scalare in $R$:
$$w_{1}\in W, \quad \lambda\in R$$
$$w_{1}=(x_{1},y_{1})$$
li moltiplico:
$$
\begin{align}
\lambda \cdot w_{1} &=\lambda \cdot(x_{1},y_{1}) \\
&=(\lambda x_{1},\lambda y_{1})
\end{align}
$$
verifico se il risultato appartiene a $W$:
$$
\begin{align}
&2x-y=0 \\
&2\lambda x_{1}-\lambda y_{1}=0 \\
&\lambda(2x_{1}-y_{1})=0
\end{align}
$$
so che $(2x-y)=0$ e che $\lambda \cdot0=0$ quindi la moltiplicazione appartiene a $W$.
#Definizione 1.3
Sia $V$ uno spazio vettoriale definito su un campo $\mathbb{K}$ e ${v_{1},v_{2},\dots,v_{n}}\subseteq V$ un insieme di vettori di $V$.
Si dice $span$ o **sottospazio generato** dai vettori $v_{1},v_{2},\dots,v_{n}$ l'insieme di tutte le possibili combinazioni lineari:
$$
\begin{align}
&Span(v_{1},v_{2},\dots,v_{n}) \\
&L(v_{1},v_{2},\dots,v_{n}) \\
&<v_{1},v_{2},\dots,v_{n}>
\end{align}
$$
In simboli:
$$Span(v_{1},v_{2},\dots,v_{n}):=\{a_{1}v_{1}+a_{2}v_{2}+\dots+a_{n}v_{n}\}\quad a_{1},a_{2},\dots,a_{n}\in \mathbb{K}$$
## Sottospazio generato
Un qualsiasi insieme di vettori $\{v_{1},v_{2},\dots,v_{n}\}$ contenuto in uno spazio vettoriale $V$ su un campo $\mathbb{K}$ è un sistema di generatori $V$ se e solo se ogni $w\in V$ si può esprimere come combinazione lineare dei vettori $v_{1},v_{2},\dots,v_{n}$.
Ovvero se $\{v_{1},v_{2},\dots,v_{n}\}\subseteq V$ è un sistema di generatori di $V$ se e solo se per ogni $w\in V$ esistono gli scalari $a_{1},a_{2},\dots,a_{n}\in \mathbb{K}$ tali che:
$$a_{1}v_{1}+a_{2}v_{2}+\dots+a_{n}v_{n}=w$$
L'insieme di tutte le possibili combinazioni lineari dei vettori $v_{1},v_{2},\dots,v_{n}\in V$ è, per definizione, il sottospazio generato da questi vettori ossia:
$$V=Span(v_{1},v_{2},\dots,v_{n})$$
## Vettori linearmente dipendenti o indipendenti
Si dice che gli $n$ vettori $v_{1},v_{2},\dots,v_{n}$ sono **linearmente indipendenti** tra loro se, prendendo $n$ scalari $a_{1},a_{2},\dots,a_{n}\in \mathbb{K}$ e imponendo
$$a_{1}v_{1}+a_{2}v_{2}+\dots+a_{n}v_{n}=0$$
risulta che la precedente uguaglianza è soddisfatta se e solo se:
$$a_{1}=a_{2}=\ldots=a_{n}=0$$
cioè se e solo se l'unica $n$-upla di scalari che annulla la combinazione lineare $a_{1}v_{1}+a_{2}v_{2}+\ldots+a_{n}v_{n}$ è la $n$-upla di coefficienti nulli.
Diciamo invece che i vettori $v_{1},v_{2},\ldots,v_{n}$ sono **linearmente dipendenti** se oltre alla $n$-upla di scalari tutti nulli esiste almeno una $n$-upla di scalari non tutti nulli che annulla la combinazione lineare.
#Esempio 
I vettori $v_{1}=(1,0), v_{2}=(0,1)\in \mathbb{R}^{2}$ sono linearmente indipendenti.
Consideriamo due generici $a,b\in \mathbb{R}$ e imponiamo che sia nulla la generica combinazione lineare
$$
\begin{align}
&av_{1}+bv_{1} \\
&a(1,0)+b(0,1)=(0,0)
\end{align}
$$
svolgendo le operazioni otteniamo:
$$
\begin{align}
&(a,0)+(0,b)=(0,0) \\
&(a,b)=(0,0)
\end{align}
$$
quindi abbiamo che $a=b=0$
#Esempio 
I vettori $v_{1}=(1,1,0), v_{2}=(0,0,2), v_{3}=(0,0,-3)\in \mathbb{R}^{3}$ sono linearmente dipendenti.
Per vederlo basta considerare tre generici scalari $a,b,c\in \mathbb{R}$ e richiedere che:
$$av_{1}+bv_{2}+cv_{3}=0$$
ossia:
$$a(1,1,0)+b(0,0,2)+c(0,0,-3)=0$$
dopo i vari calcoli otteniamo:
$$(a,a,2b-3c)=(0,0,0)$$
soddisfatta per $a=b=c=0$ ma anche per $a=0,2b=3c$.
Ad esempio $a=0, b=\frac{3}{2}, c=1$ sono tre scalari non tutti nulli che annullano la generica combinazione lineare, dunque i tre vettori sono linearmente dipendenti.
## Sistemi di generatori
Un **sistema di generatori** di uno spazio o di un sottospazio vettoriale è un insieme di vettori che permette di ricostruire tutti i vettori dello spazio.
Sia $V$ uno spazio su un campo $\mathbb{K}$. Diciamo che un insieme di vettori $\{v_{1},v_{2},\dots,v_{n}\}\subseteq V$ è un **sistema di generatori** di $V$ se ogni elemento di $V$ si può esprimere mediante una combinazione lineare di tali vettori.
Ovvero, $\{v_{1},v_{2},\dots,v_{n}\}\subseteq V$ è un sistema di generatori di $V$ se e solo se $\forall w\in V$ esistono $n$ scalari $a_{1},a_{2},\dots,a_{n}\in \mathbb{K}$ tali che:
$$a_{1}v_{1}+a_{2}v_{2}+\ldots+a_{n}v_{n}=\displaystyle\sum_{i=1}^{n}a_{i}v_{i}=w$$
#Esempio 
Consideriamo lo spazio vettoriale $\mathbb{R}^{2}$ dei vettori a due componenti reali e consideriamo l'insieme:
$$\{(0,2),(1,0),(1,1)\}\subseteq \mathbb{R}^{2}$$
esso costituisce un sistema di generatori di $\mathbb{R}^{2}$, infatti $\forall w\in \mathbb{R}^{2}$, ossia per ogni $(w_{1},w_{2})\in \mathbb{R}^{2}$, possiamo trovare dei coefficienti $a_{1},a_{2},a_{3}\in\mathbb{R}$ tali che:
$$(w_{1},w_{2})=a_{1}(0,2)+a_{2}(1,0)+a_{3}(1,1)$$
per fissare le idee proviamo con il vettore:
$$w=(w_{1},w_{2})=(27,4)$$
Se consideriamo i coefficienti:
$$a_{1}=2,a_{2}=27,a_{3}=0$$
allora
$$
\begin{align}
&a_{1}(0,2)+a_{2}(1,0)+a_{3}(1,1)= \\
&=2\cdot(0,2)+27\cdot(1,0)+0\cdot(1,1)= \\
&=(0,4)+(27,0)+(0,0)=(27,4)
\end{align}
$$
In generale la scelta degli scalari $a_{1},a_{2},a_{3}\in \mathbb{R}$ non è unica. Anche considerando:
$$a_{1}=1,a_{2}=25,a_{3}=2$$
si può costruire una combinazione lineare che genera il vettore $w=(27,4)$.
### Come stabilire se un insieme di vettori è un sistema di generatori
Per capire il seguente metodo, utile per verificare se un insieme di vettori è un sistema di generatori di uno spazio vettoriale, è necessario conoscere il *teorema di Rouché Capelli* e come si calcola il *rango di una matrice*.
Sia $V$ uno spazio vettoriale qualsiasi su un campo $\mathbb{K}$ e immaginiamo di avere un insieme di $n$ vettori $\{v_{1},v_{2},\dots,v_{n}\}\in V$.
Secondo la definizione di sistema di generatori, per effettuare la verifica dobbiamo considerare un generico vettore $w\in V$ e stabilire se esistono $n$ scalari $a_{1},a_{2},\dots,a_{n}\in \mathbb{K}$ tali che:
$$a_{1}v_{2}+a_{2}v_{2}+\ldots+a_{n}v_{n}=w$$
Il trucco consiste nello svolgere i calcoli al primo membro dell'equazione, ricavando un'uguaglianza tra vettori, a cui associamo un sistema lineare nelle incognite $a_{1},a_{2},\dots,a_{n}$.
Quale che sia lo spazio vettoriale in esame, al sistema lineare nelle incognite $a_{1},a_{2},\dots,a_{n}$ associamo la forma matriciale:
$$Ax=b$$
dove $A$ è la matrice dei coefficienti, $x$ il vettore colonna delle incognite $a_{1},a_{2},\dots,a_{n}$ e $b$ il vettore colonna dei termini noti.
Affinché $\{v_{1},v_{2},\dots,v_{n}\}$ sia un sistema di generatori, $Ax=b$ deve ammettere soluzione, dunque il tutto si traduce nello studio della compatibilità del sistema lineare.
Per il *teorema di Rouché Capelli*, $Ax=b$ ammette soluzione se e solo se il rango della matrice incompleta $A$ è uguale al rango della matrice completa $(A|b)$ associata al sistema.
Quindi:
- se $rk(A)=rk(A|b)$ l'insieme dei vettori è un sistema di generatori
- se $rk(A)\neq rk(A|b)$ allora l'insieme di vettori non è un sistema di generatori
#Esempio 
Vogliamo capire se il seguente insieme di vettori è un sistema di generatori di $\mathbb{R}^{3}$:
$$\{(1,0,1),(0,0,3),(1,2,1),(1,-1,0)\}$$
tali vettori generano $\mathbb{R}^{3}$ se e solo se $\forall w\in\mathbb{R}^{3}$ esistono quattro scalari $a_{1},a_{2},a_{3},a_{4}\in\mathbb{R}$ tali che:
$$a_{1}(1,0,1)+a_{2}(0,0,3)+a_{3}(1,2,1)+a_{4}(1,-1,0)=w$$
scriviamo le coordinate del generico vettore $w$:
$$w=(w_{1},w_{2},w_{3})\in\mathbb{R}^{3}$$
sostituiamole nella precedente relazione e svolgiamo i calcoli:
$$
\begin{align}
&a_{1}(1,0,1)+a_{2}(0,0,3)+a_{3}(1,2,1)+a_{4}(1,-1,0)=(w_{1},w_{2},w_{3}) \\
&(a_{1},0,a_{1})+(0,0,3a_{2})+(a_{3},2a_{3},a_{3})+(a_{4},-a_{4},0)=(w_{1},w_{2},w_{3}) \\
&(a_{1}+a_{3}+a_{4},2a_{3}-a_{4},a_{1}+3a_{2}+a_{3})=(w_{1},w_{2},w_{3})
\end{align}
$$
uguagliando le componenti otteniamo il seguente sistema lineare nelle incognite $a_{1},a_{3},a_{3},a_{4}$:
$$
\begin{cases}
a_{1}+a_{3}+a_{4}=w_{1} \\
2a_{3}-a_{4}=w_{2} \\
a_{1}+3a_{2}+a_{3}=w_{3}
\end{cases}
$$
Scriviamo la matrice incompleta $A$ e la matrice completa $(A|b)$:
$$
\begin{align}
&A= \begin{pmatrix}
1 & 0 & 1 & 1 \\
0 & 0 & 2 & -1 \\
1 & 3 & 1 & 0
\end{pmatrix} \\ \\
&(A|b)=\begin{pmatrix}
1 & 0 & 1 & 1 & | & w_{1} \\
0 & 0 & 2 & -1 & | & w_{2} \\
1 & 3 & 1 & 0 & | & w_{3}
\end{pmatrix}
\end{align}
$$
Sostituiamo
$R_{3}=R_{3}-R_{1}$:
$$
(A|b)'=
\begin{pmatrix}
1 & 0 & 1 & 1 & | & w_{1} \\
0 & 0 & 2 & -1 & | & w_{2} \\
0 & 3 & 0 & -1 & | & w_{3}-w_{1}
\end{pmatrix}
$$
Scambiamo seconda e terza riga:
$$
(A|b)'=
\begin{pmatrix}
1 & 0 & 1 & 1 & | & w_{1} \\
0 & 3 & 0 & -1 & | & w_{3}-w_{1} \\
0 & 0 & 2 & -1 & | & w_{2}
\end{pmatrix}
$$
troviamo tre pivot: $a''_{11}=1,a''_{22}=3,a''_{33}=2$.
Possiamo concludere che:
$$rk(A)=rk(A|b)=3$$
per qualsiasi valore di $(w_{1},w_{2},w_{3})$, quindi i vettori assegnati costituiscono un sistema di generatori di $\mathbb{R}^{3}$.
## Base di uno spazio vettoriale
Una base di uno spazio vettoriale è un sistema di generatori linearmente indipendenti che generano l'intero spazio vettoriale.
Dato uno spazio vettoriale $V$ su un campo $\mathbb{K}$, diciamo che un insieme di vettori $\{v_{1},v_{2},\dots,v_{n}\}\subseteq V$ è una base di $V$ se:
1. $\{v_{1},v_{2},\dots,v_{n}\}$ è un sistema di generatori
2. i vettori $v_{1},v_{2},\dots,v_{n}$ sono vettori linearmente indipendenti
Ovvero
1. $\forall w\in V$ esistono $n$ scalari $a_{1},a_{2},\dots,a_{n}\in\mathbb{K}$ tali che:
	1. $w=a_{1}v_{1}+a_{2}v_{2}+\ldots+a_{n}v_{n}$
2. L'unica $n$-upla di scalari che soddisfa l'uguaglianza $b_{1}v_{1}+b_{2}v_{2}+\ldots+b_{n}v_{n}=0$ è la $n$-upla di scalari tutti nulli, cioè $b_{1}=b_{2}=\ldots=b_{n}=0$
## Dimensioni di uno spazio vettoriale
La **dimensione di uno spazio vettoriale** è la cardinalità di una sua base qualsiasi.
Se $V$ è uno spazio vettoriale e $B$ è una sua base, indichiamo con $dim(V)$ la dimensione di $V$ si ha che:
$$dim(V)=|B|$$
dove $|B|$ indica la cardinalità della base considerata.
#Esempio 
Supponiamo di voler calcolare la dimensione del seguente sottospazio generato:
$$
\begin{align}
&U=Span(u_{1},u_{2},u_{3}) \\
&u_{1}=(1,0,-3) \\
&u_{2}=(2,1,-5) \\
&u_{3}=(0,4,4)
\end{align}
$$
per determinare una base di $U$ e quindi calcolarne la dimensione è sufficiente estrarre una base dal sistema di generatori $\{u_{1},u_{2},u_{3}\}$. Procediamo, ad esempio, con il metodo di eliminazione di Gauss.
$$
M=
\begin{pmatrix}
1 & 2 & 0 \\
0 & 1 & 4 \\
-3 & -5 & 4
\end{pmatrix}
$$
$R_{3}=R_{3}+3R_{1}$:
$$
M'=
\begin{pmatrix}
1 & 2 & 0 \\
0 & 1 & 4 \\
0 & 1 & 4
\end{pmatrix}
$$
$R_{3}=R_{3}-R_{2}$:
$$
M'=
\begin{pmatrix}
1 & 2 & 0 \\
0 & 1 & 4 \\
0 & 0 & 0
\end{pmatrix}
$$
Il numero di pivot di $M'$ è il massimo numero di vettori linearmente indipendenti del sottospazio $U$. Una base di tale sottospazio è data dalle colonne della matrice non ridotta che corrispondono alle colonne della matrice ridotta contenenti i pivot:
$$B=\{u_{1},u_{2}\}=\{(1,0,-3),(2,1,-5)\}$$
la dimensione del sottospazio è quindi $2$.
# Capitolo 4 - Sistemi lineari
## Risoluzione di un sistema lineare
Trasformiamo la matrice $(A|b)$ in una matrice a scalini con Gauss-Jordan:
$$
C=(A|b)=
\begin{pmatrix}
0 & 1 & ? & 0 & 0 & ? & | & ? \\
0 & 0 & 0 & 1 & 0 & ? & | & ? \\
0 & 0 & 0 & 0 & 1 & ? & | & ?
\end{pmatrix}
$$
Adesso guardiamo le colonne che contengono i pivot, che in questo esempio sono la seconda, la quarta e la quinta.
Se la colonna dei termini noti b contiene un pivot, allora la matrice è indicativamente di questo tipo:
$$
\begin{pmatrix}
0 & 1 & ? & 0 & 0 & ? & | & ? \\
0 & 0 & 0 & 1 & 0 & ? & | & ? \\
0 & 0 & 0 & 0 & 0 & ? & | & 1
\end{pmatrix}
$$
La riga che contiene l’ultimo pivot rappresenta l’equazione $0 = 1$ che chiaramente non può avere soluzione, quindi l'insieme $S$ delle soluzioni è vuoti, $S=\emptyset$.
Consideriamo adesso il caso in cui l’ultima colonna non contenga pivot:
$$
\begin{pmatrix}
0 & 1 & a_{13} & 0 & 0 & a_{16} & | & b_{1} \\
0 & 0 & 0 & 1 & 0 & a_{26} & | & b_{2} \\
0 & 0 & 0 & 0 & 1 & a_{36} & | & b_{3}
\end{pmatrix}
$$
Ricordiamo che ciascuna colonna corrisponde ad una variabile $x_{1},\dots,x_{n}$, eccetto l'ultima che contiene i termini a noi noti.
Adesso assegniamo un parametro $t_{1},t_{2},\dots,t_{n}$ a ciascuna variabile che corrisponde ad una colonna che non contiene pivot. Quindi:
$$x_{1}=t_{1},x_{3}=t_{2}\text{ e }x_{6}=t_{3}$$
Il sistema è ora in questa forma:
$$\begin{cases}
x_{2}+a_{13}t_{2}+a_{16}t_{3}=b_{1} \\
x_{4}+a_{26}t_{3}=b_{2} \\
x_{5}+a_{36}t_{3}=b_{3}
\end{cases}$$
Spostiamo a destra dell’uguale tutti i nuovi parametri e otteniamo:
$$\begin{cases}
x_{2}=b_{1}-a_{13}t_{2}-a_{16}t_{3} \\
x_{4}=b_{2}-a_{26}t_{3} \\
x_{5}=b_{3}-a_{36}t_{3}
\end{cases}$$
Al sistema aggiungiamo anche le equazioni corrispondenti alle assegnazioni dei parametri liberi:
$$\begin{cases}
x_{1}=t_{1} \\
x_{2}=b_{1}-a_{13}t_{2}-1_{16}t_{3} \\
x_{3}=t_{2} \\
x_{4}=b_{2}-a_{26}t_{3} \\
x_{5}=b_{3}-a_{36}t_{3} \\
x_{6}=t_{3}
\end{cases}$$
Il sistema è risolto. I parametri $t_{1},t_{2},\dots$ sono liberi e possono assumere qualsiasi valore in $\mathbb{K}$, e le variabili $x_{1},x_{2},\dots,x_{n}$ dipendono da questi parametri liberi come indicato.
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
b_{3} \\
0
\end{pmatrix}+t_{1}
\begin{pmatrix}
1 \\
0 \\
0 \\
0 \\
0 \\
0
\end{pmatrix}+t_{2}
\begin{pmatrix}
0 \\
-a_{13} \\
1 \\
0 \\
0 \\
0
\end{pmatrix}+t_{3}
\begin{pmatrix}
0 \\
-a_{16} \\
0 \\
-a_{26} \\
-a_{36} \\
1
\end{pmatrix}
$$
Le soluzioni sono del tipo:
$$x=x_{0}+t_{1}v_{1}+\ldots+t_{h}v_{h}$$
dove $x_{0},v_{1},\dots,v_{h}\in \mathbb{K}^{n}$ sono vettori fissati, e i $v_{i}$ della forma:
$$v_{i}=\begin{pmatrix}
? \\
\vdots \\
? \\
1 \\
0 \\
\vdots \\
0
\end{pmatrix}$$
#Esempio Risolviamo il sistema già ridotto con Gauss-Jordan:
$$\begin{cases}
x_{1}+3x_{2}+4x_{5}=1 \\
x_{3}-2x_{4}=3
\end{cases}$$
Le variabili corrispondenti ai pivot sono $x_{1}$ e $x_{3}$. Le variabili libere sono $x_{2},x_{4}$ e $x_{5}$. Quindi:
$$\begin{cases}
x_{1}=1-3t_{2}+4t_{5} \\
x_{2}=t_{2} \\
x_{3}=3-t_{3}+2t_{2} \\
x_{4}=t_{2} \\
x_{5}=t_{3}
\end{cases}$$
## Teorema di Rouché - Capelli
### Sistema omogeneo asociato
Consideriamo un sistema di equazioni lineari
$$\begin{cases}
a_{11}x_{1}+\dots+a_{1n}x_{n}=b_{1} \\
\vdots \\
a_{k1}x_{1}+\dots+a_{kn}x_{n}=b_{k}
\end{cases}$$
Il sistema omogeneo associato è quello ottenuto semplicemente mettendo a zero tutti i termini noti $b_{i}$:
$$\begin{cases}
a_{11}x_{1}+\dots+a_{1n}x_{n}=0 \\
\vdots \\
a_{k1}x_{1}+\dots+a_{kn}x_{n}=0
\end{cases}$$
Scriviamo la matrice $A=(a_{ij})$ dei coefficienti ed il vettore$b=(b_{i})$ dei termini noti. $C=(A|b)$ rappresenta il sistema lineare iniziale, mentre $(A|0)$ o solo $A$, rappresenta il sistema lineare omogeneo associato.
#Esempio Consideriamo il sistema in $\mathbb{R}^{3}$
$$\begin{cases}
x-y+z=1 \\
y-z=2
\end{cases}$$
Risolvendo troviamo le soluzioni $S$ del tipo:
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
al variare di $t\in \mathbb{R}$. Le soluzioni $S_{0}$ del sistema omogeneo associato
$$\begin{cases}
x-y+z=0 \\
y-z=0
\end{cases}$$
sono i vettori del tipo:
$$\begin{pmatrix}
0 \\
t \\
t
\end{pmatrix}$$
Le soluzioni in $S$ sono tutte ottenute prendendo la soluzione particolare
$$\begin{pmatrix}
3 \\
0 \\
-2
\end{pmatrix}$$
ed aggiungendo a questa le soluzioni in $S_{0}$ del sistema omogeneo associato. Qualsiasi elemento di $S$ può fungere da soluzione particolare, per esempio:
$$\begin{pmatrix}
3 \\
2 \\
0
\end{pmatrix}$$
e quindi descrivere lo stesso insieme $S$ di soluzioni come:
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
Si ottiene lo stesso insieme $S$ di prima, sostituendo $t=u+2$.
## Sottospazio affine
Che tipo di luogo geometrico è $S$?
$S$ è sempre un **sottospazio affine**.
Sia $V$ uno spazio vettoriale. Un sottospazio affine di $V$ è qualsiasi sottoinsieme del tipo:
$$S=\{x+v|v\in W\}$$
dove $x$ è un punto fissato di $V$ e $W\subset V$ è un sottospazio vettoriale.
#proposizione 
Gli spazi affini $x+W$ e $x'+W'$ coincidono se e solo se $W=W'$ e $x-x'\in W$.
## Rango
#Definizione 
Il rango di $A$ è la dimensione dello spazio:
$$Span(A^{1},\dots,A^{n})\subset \mathbb{K}^{m}$$
È la dimensione dello spazio generato dalle colonne, indicato con $rk(A)$.
#proposizione 
Il rango di $A$ è il massimo numero di colonne linearmente indipendenti di $A$.
#Dimostrazione 
Poiché il rango non cambia con mosse di Gauss, possiamo supporre che $A$ sia già ridotta a scalini e inoltre usare la seconda parte dell’algoritmo di Gauss-Jordan per fare in modo che le $k$ colonne contenenti i pivot siano precisamente i primi $k$ vettori $e_{1},\dots,e_{k}$ della base canonica di $\mathbb{K}^{m}$









