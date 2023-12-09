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
#Osservazione 2.1
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
Dette $E_{1},E_{2},E_{3}$ le righe della matrice identica, essendo $A_{1}=a_{11}E_{1}+a_{12}E_{2}+a_{13}E_{3}$, per le proprietà $(D6-D7)$ si ha:
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










