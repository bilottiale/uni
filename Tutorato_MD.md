#Esercizio 
Sia $V$ in $\mathbb{K}$ uno spazio vettoriale di matrici $3\times3$
$V=M(\underbrace{3}_{(m\times n)},\mathbb{K})$
Si trovi che $W=\{A\in M(3,\mathbb{K})|(A)^{\top}=A\}$
- Definire che sia uno spazio vettoriale
Deve rispettare 3 proprietà:
1. $0_{v}\in W$
2. $v_{1},v_{2}\in W$ allora $v_{1}+v_{2}\in W$
3. $v_{1}\in W, \lambda$ scalare in $\mathbb{K}$ allora $\lambda v\in W$

Come risolvere ciò?
1. $0_{v}=\begin{bmatrix}0&0&0\\0&0&0\\0&0&0\end{bmatrix}=0_{v}^{\top}$
	1. $0_{v}=0_{v}^{\top}$
2. Prendiamo $P,Q\in W\rightarrow P^{\top}=P, Q^{\top}=Q$
	1. $P+Q \in W$?
	2. Dimostro che $(P+Q)^{\top}=P^{\top}+Q^{\top}=P+Q\longrightarrow P+Q\in W$
	3. Grazie alla proprietà della trasposta
3. $P\in W, \lambda\in\mathbb{K}$
	1. $P=P^{\top}$
	2. $\lambda P\in W\longleftrightarrow(\lambda P)^{\top}=\lambda P$
	3. Perché $(\lambda P)^{\top}=\lambda\cdot P^{\top}=\lambda P$
	4. Grazie alla proprietà della trasposta
# Sistemi lineari di equazioni
#Esercizio 
$$\begin{cases}
   x+3y+z=3 \\
   2x+y+z=4 \\
   4x+7y+3z=9
\end{cases}
\quad
\begin{bmatrix}
x \\
y \\
z \\
\end{bmatrix}
\quad
\text{soluzioni di tutte e }3
$$
1. Matrice associata
$$A=\left[\begin{array}{c c c | c} 
1&3&1&3\\ 
2&1&1&4 \\
4&7&3&9 
\end{array}\right]=A(A|b)\text{ Matrice completa}$$
$A=$ matrice incompleta + $b=$ termini noti
2. Matrice a scalini (*Gauss-Jordan*)
Tramite 3 azioni:
- Scambio di righe
- Somma di righe
- Somma di un multiplo di righe
$$
\xrightarrow[R_{3}=R_{3}-2R_{2}]{R_{2}=R_{2}-2R_{1}}
\left[\begin{array}{c c c | c} 
1&3&1&3\\ 
0&-5&-1&-2 \\
0&5&1&1
\end{array}\right]
\xrightarrow{R_{3}=R_{3}+R_{2}}
\left[\begin{array}{c c c | c} 
\textcolor{yellow}{1}&3&1&3\\ 
0&\textcolor{yellow}{-5}&-1&-2 \\
0&0&0&\textcolor{yellow}{-1}
\end{array}\right]
$$
A scalini = con $\textcolor{yellow}{pivot}$ in colonne diverse.
$rk(A)=2 \quad rk(A|b)=3$
##### Teorema Ròuche-Capelli
se $rk(A)\neq rk(A|b) \rightarrow$ non ha soluzioni
se $rk(A)=rk(A|b)\rightarrow$ ha almeno una soluzione
	- se $n$ = numero di incognite, $n-rk(A)$ = dimensione del sottospazio vettoriale generato dalle soluzioni
se $rk(A)=n$ la soluzione è unica
#Esempio 
$$\begin{cases}
   x+3y+z=3 \\
   2x+y+z=4 \\
   4x+7y+3z=10
\end{cases}$$
$$\left[\begin{array}{c c c | c}
1&3&1&3 \\
2&1&1&4 \\
4&7&3&10
\end{array}\right]
\xrightarrow[R_{3}=R_{3}-2R_{2}]{R_{2}=R_{2}-2R_{1}}
\left[\begin{array}{c c c | c}
1&3&1&3 \\
0&-5&-1&-2 \\
0&5&1&2
\end{array}\right]
\xrightarrow{R_{3}=R_{3}+R_{2}}
\left[\begin{array}{c c c | c}
\textcolor{yellow}{1}&3&1&3 \\
0&\textcolor{yellow}{-5}&-1&-2 \\
0&0&0&0
\end{array}\right]
$$
$rk(A)=2=rk(A|b)\longrightarrow$ soluzioni infinite --> dipendono da $\underbrace{3}_{n.\ incognite}-\overbrace{2}^{rk}=1$ parametri.
Riscriviamo il sistema con $z=t$:
$$\begin{cases}
   x+3y+z=3 \\
   -5y-z=-2 \\
   -------
\end{cases}
\longrightarrow
\begin{cases}
   ------ \\
   -5y-t=-2 \\
\end{cases}
\longrightarrow
\begin{cases}
   x+3\cdot \frac{t-2}{5}+t=3 \\
   y=\frac{t-2}{-5} \\
\end{cases}
\longrightarrow
\begin{cases}
   x=3\cdot \frac{t-2}{5}+t+3 \\
   y=\frac{t-2}{-5} \\
\end{cases}
\longrightarrow
$$
$$\begin{cases}
   x=\frac{t-6-5t+15}{5} \\
   y=\frac{t-2}{-5} \\
\end{cases}
\longrightarrow
\begin{cases}
   x=\frac{-2t+9}{5} \\
   y=\frac{t-2}{-5} \\
\end{cases}
$$
$$\begin{bmatrix}
x \\
y \\
z
\end{bmatrix}
=
\begin{bmatrix}
\frac{-2t+9}{5} \\
\frac{t-2}{-5} \\
t
\end{bmatrix}
$$
# Dipendenza lineare
Da 3 vettori verificare che siano *linearmente indipendenti*, *generatori* e *basi*.
$$v_{1}=\begin{bmatrix}
1 \\
1 \\
2
\end{bmatrix}
\quad
v_{2}=
\begin{bmatrix}
0 \\
-1 \\
1
\end{bmatrix}
\quad
v_{3}=
\begin{bmatrix}
3 \\
1 \\
6
\end{bmatrix}
\in\mathbb{R^{3}}
$$
Sono linearmente indipendenti se:
$\lambda_{1}v_{1}+\lambda_{2}v_{2}+\lambda_{3}v_{3}=0$
$$\lambda_{1}
\begin{bmatrix}
1 \\
1 \\
2
\end{bmatrix}+
\lambda_{2}
\begin{bmatrix}
0 \\
-1 \\
1
\end{bmatrix}+
\lambda_{3}
\begin{bmatrix}
3 \\
1 \\
6
\end{bmatrix}=
\begin{bmatrix}
0 \\
0 \\
0 \\
\end{bmatrix}$$
$$\begin{cases}
\lambda_{1}+3\lambda_{3}=0 \\
\lambda_{1}-\lambda_{2}+\lambda_{3}=0 \\
2\lambda_{1}+\lambda_{2}+6\lambda_{3}=0
\end{cases}$$
Matrice completa:
$$\left[\begin{array}{c c c | c}
1&0&3&0 \\
1&-1&1&0 \\
2&1&6&0
\end{array}\right]
\xrightarrow[R_{3}=R_{3}-2R_{1}]{R_{2}=R_{2}-R_{1}}
\left[\begin{array}{c c c | c}
1&0&3&0 \\
1&-1&-2&0 \\
0&1&0&0
\end{array}\right]
\xrightarrow{R_{3}=R_{3}+R_{2}}
\left[\begin{array}{c c c | c}
1&0&3&0 \\
1&-1&-2&0 \\
0&0&-2&0
\end{array}\right]
$$
$$\begin{cases}
\lambda_{1}+3\lambda_{3}=0 \\
-\lambda_{2}-2\lambda_{3}=0 \\
-2\lambda_{3}=0
\end{cases}
=
\begin{cases}
\lambda_{1}=0 \\
\lambda_{2}=0 \\
\lambda_{3}=0
\end{cases}$$
$$(\lambda_{1},\lambda_{2},\lambda_{3})=(0,0,0)$$
$v_{1},v_{2},v_{3}$ *sono linearmente indipendenti*.
$rk(A)=3=rk(A|b)$ *sono generatori*.
Se sono linearmente indipendenti e generatori sono anche *basi*.
