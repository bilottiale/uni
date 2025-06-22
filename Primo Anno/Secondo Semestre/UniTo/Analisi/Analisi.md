# Limiti
La distanza di un punto $x$ da $0$, è la lunghezza del segno di estremi $0$ e $x$:
$$
d(x,0)=
\begin{cases}
x &\text{se } x \geq 0 \\
-x &\text{se } x<0
\end{cases} = |x|
$$
La distanza di $x$ da $y$ è la lunghezza del segmento di estremi $x$ e $y$:
$$
d(x,y)=
\begin{cases}
y-x &\text{se } y \geq x \\
x-x &\text{se }yx<x
\end{cases} = |y-x|
$$
$d(x,y)=d(y,x)$.
## Intorni
È un insieme di punti che stanno "*intorno*" al punto $x_{0}$ che si sta considerando.
Indichiamo un intorno con $I(x_{0})$ ovveri:
$$(x_{0}-\delta_{1}, x_{0}+\delta_{2})$$
con $\delta_{1}$ e $\delta_{2}$ due numeri positivi, cioè un intervallo che ha come estremi un numero un po' più piccolo di $x_{0}, x_{0}-\delta_{1}$, e un numero un po' più grande, $x_{0}+\delta_{2}$.
![[Pasted image 20240417144330.png|300]]
L'intorno $(2,5)$ di $4$ si può scrivere come $(4-\delta_{1}, 4+\delta_{2})$ prendendo come $\delta_{1}=2$ e $\delta_{2}=1$.
**Intorno sinistro**:
$$I_{\delta}^-(x_{0})=(x_{0}-\delta, x_{0})$$
**Intorno destro**:
$$I_{\delta}^+=(x_{0},x_{0}+\delta)$$
## Pendenza
Funzione pendenza: $P_{f}:I \to \symbb{R}$:
dato $x$ restituisce la pendenza della retta tangente al grafico di $f$ in $x$.
- $f$ crescente $P_{f}\geq 0$
- $f$ decrescente $P_{f} \leq 0$
- $f$ convessa ($\cup$) $P_{f}$ crescente
- $f$ concava ($\cap$) $P_{f}$ decrescente
La funzione ha pendenza $=0$ nei punti a tangente orizzontale
## Derivata
$f:(a,b) \to \symbb{R} \quad x_{0} \in (a,b)$
$f$ è derivabile in $x_{0}$ se esiste finito:
$$
f'(x_{0}) = \lim_{ \Delta \to 0 } \frac{\Delta y}{\Delta x} = \lim_{ n \to 0 } \frac{f(x_{0}+n)-f(x_{0})}{n} \quad \text{rapporto incrementale}
$$
### Derivata della somma o differenza
$$
(f \pm g)'(x)=f'(x) \pm g'(x)
$$
### Derivata del prodotto
$$
(f\cdot g)'(x)=f'(x)g(x)+f(x)g'(x)
$$
### Derivata del rapporto
$$
\left( \frac{f}{g} \right)'(x)=\frac{f'(x)g(x)-f(x)g'(x)}{(g(x))^{2}}
$$
### Derivata della composta (regola della catena)
$$
(g \cdot f)'(x)=g'(f(x))\cdot f'(x)
$$
# Dinamica delle popolazioni
**Tasso di crescita**:
$$
\lim_{ \Delta t \to 0 } \frac{N(t+\Delta t)-N(t)}{\Delta t}
$$
- $N$ cresce se il tasso è $\geq 0$
- $N$ decresce se il tasso è $\leq 0$
- $N$ è convessa ($\cup$) se il tasso è crescente
- $N$ è concava ($\cap$) se il tasso è decrescente
### Limite finito al finito
$$\lim_{x\to c} f(x)=l$$
Si dice che $f$ tende a $l$ per $x$ che tende a $c$, se:
$$\forall \varepsilon > 0 \ \exists \ M > 0 : x < |x-c|< M \Rightarrow |f(x)-l|< \varepsilon$$
$$
\forall \varepsilon > 0 \exists I_{\delta}(x_{0}) : |f(x)-l| < \varepsilon \forall x \in I_{\delta}(x_{0}), x \neq x_{0}
$$
### Limite finito all'infinito
$$\lim_{ x \to \pm\infty } f(x)=l$$
Si dice che $f$ tende a $l$ per $x$ che tende a $\pm \infty$, se:
$$\forall \varepsilon > 0 \ \exists \ M > 0 : x>M \Rightarrow |f(x)-l|<\varepsilon$$
$$
\forall \varepsilon > 0 \exists I(\pm \infty):|f(x)-l|<\varepsilon \forall x \in I(\pm \infty)
$$
### Limite infinito al finito
$$\lim_{ x \to c } f(x)=\pm \infty$$
Si dice che $f:I_{r}(c)\backslash {c}\to \symbb{R}$, $f(x)$ tende a $+\infty$ per $x$ che tende a $c$ se:
$$\forall M>0\exists \varepsilon>0:0<|x-c|<\varepsilon \Rightarrow f(x)>M$$
$$
\forall M>0 \exists I(x_{0}) : f(x)>M \forall x \in I(x_{0}), x \neq x_{0}
$$
### Limite infinito all'infinito
$$\lim_{ x \to \pm\infty } f(x) = \pm \infty$$
Si dice che $f(x)$ tende a $\infty$ per $x \to \infty$ se:
$$\forall M>0\exists \varepsilon>0:x>\varepsilon \Rightarrow f(x)>M$$
$$
\forall M>0\exists I(\pm \infty): f(x)>M \forall x \in(\pm \infty)
$$
## Teorema di permanenza del segno
Sia:
- il limite per $x \to c$ di $f(x)$ deve esistere $\neq 0$.
Consideriamo $f(x)$ con dominio $dom(f)$ e sia $c \in \overline{\symbb{R}}$ un punto di accumulazione per il dominio. Se il limite per $x \to c$ di $f(x)$ è uguale a $l \in \overline{\symbb{R}}$, allora esiste un *intorno* di $c$ contenuto nel dominio di $f(x)$ in cui la funzione assume lo stesso segno del limite.
- se il limite $l$ è positivo allora esiste un intorno $I_{c}$ contenuto nel dominio di $f(x)$ in cui la funzione è positiva
$$\lim_{ x \to c } f(x)=l>0 \Longrightarrow f(x)>0 \quad \forall x \in I_{c}$$
- se il limite $l$ è negativo allora esiste un intorno $I_{c}$ contenuto nel dominio di $f(x)$ in cui la funzione è negativa
$$\lim_{ x \to c } f(x)=l<0 \Longrightarrow f(x)<0 \quad \forall x \in I_{c}$$
## Teorema del confronto
Sia $x_{0}\in \symbb{R}\cup \{\pm \infty\}$ un *punto di accumulazione* di $f, g, h$ definite in un intorno di $x_{0}$ detto $I$ diciamo che:
- $\forall x \in I, g(x)$ assume valori non inferiori a $f(x)$ e non superiori a $h(x)$:
$$
f(x)\leq g(x)\leq h(x) \quad \forall x \in I
$$
- I due limiti per $x$ tendente a $x_{0}$ di $f(x)$ e $h(x)$ esistano finiti e valgano entrambe $l$:
$$
\lim_{ x \to x_{0} } f(x) = \lim_{ x \to x_{0} } h(x)=l \quad \text{con } l \in \symbb{R}
$$
Allora, risulta che il limite per $x \to x_{0}$ di $g(x)$ vale $l$:
$$
\lim_{ x \to x_{0} } g(x) = l
$$
# Funzioni
Una funzione $f:I(c)\to \symbb{R}$ si dice **continua** in $c$ se $\displaystyle\lim_{ x \to c }f(x)=f(c)$, cioè se:
$$\forall \varepsilon > 0 \exists \delta>0:|x-c|<\delta \Rightarrow |f(x)-f(c)|<\varepsilon$$
Le funzioni elementari e le funzioni trigonometriche sono continue nel loro dominio.
## Teorema di Weierstrass
Sia $f:[a,b]\to \symbb{R}$ continua, in intervallo chiuso e limitato, allora $\exists x_{m}$ e $x_{M}$ in $[a,b]$ t.c:
$$f(x_{m})\leq f(x)\leq f(x_{M}) \quad \forall x \in [a,b]$$
- $x_{n}$ e $x_{M}$ si dicono punti di minimo e di massimo
- $f(x_{m})$ e $f(x_{M})$ si dicono minimo e massimo *assoluto*.
$x_{m}$ e $x_{M}$ non sono unici, il **massimo** e il **minimo** invece lo sono.
# Calcolo differenziale
Siano $c \in \symbb{R}$ e $I_{c}=(c-\delta, c+\delta)$ un suo intorno.
Una funzione $f:I_{c}\to \symbb{R}$ si dice **derivabile** se esiste finito:
$$f'(c)=\lim_{ h \to 0 } \frac{f(c+h)-f(c)}{h} = n$$
e si chiama **derivata**(*prima*) di $f$ in $c$.
$$\lim_{ h \to 0 } \frac{f(c+h)-f(c)}{h}=\lim_{ x \to c } \frac{f(x)-f(c)}{x-c}$$
Sia $I \subseteq \symbb{R}$ un intervallo e $f:I \to \symbb{R}$ si dice che $f$ è derivabile su $I$ se lo è ogni punto di $I$.
## Derivate delle funzioni elementari
| Funzione                         | Derivata                 |
| -------------------------------- | ------------------------ |
| $x^\alpha, \alpha \in \symbb{R}$ | $\alpha x^{\alpha -1}$   |
| $e^x$                            | $e^x$                    |
| $\log x$                         | $\frac{1}{x}$            |
| $\sin x$                         | $\cos x$                 |
| $\cos x$                         | $-\sin x$                |
| $\tan x$                         | $\frac{1}{\cos^2 x}$     |
| $\arctan x$                      | $\frac{1}{1+x^2}$        |
| $\arcsin x$                      | $\frac{1}{\sqrt{1-x^2}}$ |
## Teorema (Legame di continuità-derivabilità)
Sia $f:I(c) \to \symbb{R}$. Se $f$ è derivabile in $x=c$ allora $f$ è continua in $c$.
**Derivabilità** è condizione sufficiente per la **continuità**, **continuità** è condizione necessaria per **derivabilità**.
Se $f$ non è continua in $x=c$, non può essere derivabile in $c$.
**Derivabilità**:
$$
f'(a)=\lim_{ h \to 0 } \frac{f(a+h)-f(a)}{h}
$$
**Continuità**: la funzione $f$ è continua in $a$ se:
$$
\lim_{ h \to 0 } f(x)=f(a)
$$
**I punti spigolosi e i punti a tangente verticale, non sono derivabili**.
## Teorema di Lagrange
Sia $f:[a,b] \to \symbb{R}$ continua in $[a,b]$, e derivabile in $(a,b)$, allora $\exists  c \in(a,b)$ t.c:
$$f'(c)=\frac{f(b)-f(a)}{b-a}$$
Che rappresenta le pendenza.
![[Pasted image 20240417114121.png|200]]
## Test di monotonia
Sia $f:[a,b] \to \symbb{R}$ supponiamo $f$ continua e derivabile nell'intervallo:
1. $f$ è crescente su $(a,b)\iff f'(x)\geq 0 \quad \forall x \in (a,b)$
2. $f$ è decrescente su $(a,b)\iff f'(x) \leq 0 \quad \forall x \in (a,b)$
## Convessità/Concavità
Siano $I \subset \symbb{R}$ un intervallo e $f:I \to \symbb{R}$.
Si dice che $f$ è **convessa** su $I$ se:
$$\forall x_{1},x_{2}\in I\text{ con }x_{1}<x_{2} \text{ risulta:}$$
$$f(x)\leq f(x_{1})+\frac{f(x_{2})-f(x_{1})}{x_{2}-x_{1}}\cdot (x-x_{1}) \quad \forall x \in [x_{1},x_{2}]$$
![[Pasted image 20240417115142.png|200]]
Si dice che $f$ è **concava** su $I$ se:
$$\forall x_{1},x_{2} \in I\text{ con }x_{1}<x_{2} \text{ risulta:}$$
$$f(x)\geq f(x_{1})+\frac{f(x_{2})-f(x_{1})}{x_{2}-x_{1}}\cdot (x-x_{1})\quad \forall x \in[x_{1},x_{2}]$$
![[Pasted image 20240417115153.png|200]]
### Test di convessità/concavità
Sia $f:(a,b) \to \symbb{R}$ derivabile, allora:
1. $f$ è convessa su $(a,b)\iff f'$ è crescente su $(a,b)$
2. $f$ è concava su $(a,b)\iff f'$ è decrescente su $(a,b)$
Sia $f:(a,b)\to \symbb{R}$ derivabile 2 volte, allora:
1. $f$ è convessa su $(a,b) \iff f''(x) \geq 0 \quad \forall x \in (a,b)$
2. $f$ è concava su $(a,b) \iff f''(x) \leq 0 \quad \forall x \in (a,b)$
## Derivata prima nulla su un intervallo
$$
f'(x)=0 \ \forall x \in[a,b] \iff f(x) \text{ costante su }[a,b]
$$
## Derivata seconda nulla su un intervallo
$$
f''(x)=0 \iff f(x) \text{ non ha concavità o convessità su }[a,b], f' \text{ costante su } [a,b]
$$
# Approssimazioni lineari
Se $f$ è derivabile in $x=c$, la retta di equazione $y = f(c)+f'(c)(x-c)$ è la retta tangente a $f$ in $c$, la retta che meglio approssima $f$ vicino a $x = c$.
L'equazione della retta tangente a $f$ in $c$ è:
$$
y = f(c) + f'(c)(x-c)
$$
## Polinomio di Taylor
$f:I(c)\to \symbb{R}$ derivabile $n$ volte in $x=c$. Allora esiste un polinomio, chiamato **polinimio di Taylor** di ordine $n$, centrato in $x=c$, e indicato come $T_{n,c}(x)$, tale che:
$$
T^{(k)}_{n,c}(c)=f^{(k)}(c) \quad \forall k=0,..,n
$$
### Formula generale
$$
T_{n,c}(x)=\sum^{n}_{k=0 }\frac{f^{(k)}(c)}{k!}(x-c)^{k}=f(c)+f'(c)(x-c)+\frac{f''(c)}{2!}(x-c)^{2}+\dots+\frac{f^{(n)}(c)}{n!}(x-c)^{n}
$$
Scritto anche come:
$$
f(c)+f'(c)(x-c)+\frac{1}{2!}(x-c)^{2}+\frac{1}{3!}(x-c)^{3}+\dots+\frac{1}{n!}(x-c)^{n}
$$
$T_{n,c}(x)$ approssima la funzione $f$ vicino a $x=c$, per $n$ grande, il grafico di $T_{n,c}(x)$ e quello di $f$ sono "vicini" per $x = c$.
Se $x=c=0$, si parla di **sviluppo di McLaurin**:
## Sviluppo di McLaurin
$$T_{n,0}(x)=T_{n}(x)=f(0)+f'(0)x+\frac{f''(0)}{2}x^{2}+\dots+\frac{f^{(n)}(0)}{n!}n^{n}$$
Viene detto il *polinomio di MaLaurin* di $f$ di ordine $n$.
Ovvero la formula si riduce in:
$$f(x)=f(x_{0})+f'(c)(x-x_{0})$$
# Elenco sviluppi Taylor-McLaurin
**Funzione esponenziale** $e^{x}$
$$
e^{x}=1+x+\frac{x^{2}}{2}+\frac{x^{3}}{6}+\frac{x^{4}}{24}+\frac{x^{5}}{120}+\dots+\frac{x^{n}}{n!}+o(x^{n}) \quad \forall x
$$
**Funzione logaritmica** $\log(1+x)$
$$
\log(1+x)=x-\frac{x^{2}}{2}+\frac{x^{3}}{3}-\frac{x^{4}}{4}+\frac{x^{5}}{5}+\dots+\frac{(-1)^{n+1}}{n}x^{n}+o(x^{n}) \quad \text{per }|x|<1
$$
**Binomio** $(1+x)^{\alpha}$
$$
(1+x)^{\alpha}=1+\alpha x+\frac{\alpha(\alpha -1)}{2}x^{2}+\frac{\alpha(\alpha-1)(\alpha-2)}{6}x^{3}+\dots+\dbinom{a}{n}x^{n}+o(x^{n})
$$
$$
\sqrt{ 1+x }=(1+x)^{\frac{1}{2}}=1+\frac{x}{2}-\frac{x^{2}}{8}+\frac{x^{3}}{16}-\frac{5}{128}x^{4}+\frac{7}{256}x^{5}-\frac{21}{1024}x^{6}+o(x^{6})
$$
$$
\sqrt[3]{ 1+x }=(1+x)^{\frac{1}{3}}=1+\frac{x}{3}-\frac{x^{2}}{9}+\frac{5}{81}x^{3}-\frac{10}{243}x^{4}+\frac{22}{729}x^{5}-\frac{154}{6561}x^{6}+o(x^{6})
$$
**Funzioni razionali fondamentali**:
$$
\frac{1}{1-x}=\sum^{n}_{n=0}x^{n} \quad \text{per }|x|<1
$$
$$
\frac{1}{1+x^{2}}=\sum^{n}_{n=0}(-1)^{n}x^{2n} \quad \text{per }|x|<1
$$
$$
\frac{1}{1+x}=(1+x)^{-1}=1-x+x^{2}-x^{3}+\dots+(-1)^{n}x^{n}+o(x^{n})
$$
$$
\frac{1}{\sqrt{ 1+x }}=(1+x)^{-\frac{1}{2}}=1-\frac{1}{2}x+\frac{3}{8}x^{2}-\frac{5}{16}x^{3}+\dots+\dbinom{-\frac{1}{2}}{n}x^{n}+o(x^{n})
$$
**Seno**: $\sin(x)$
$$
\sin(x)=x-\frac{x^{3}}{3!}+\frac{x^{5}}{5!}-\frac{x^{7}}{7!}\dots \frac{x^{n}}{n!}+o(x^{2n+2})
$$
**Coseno** $\cos(x)$
$$
\cos(x)=1-\frac{x^{2}}{2!}+\frac{x^{4}}{4!}-\frac{x^{6}}{6!}\dots \frac{x^{2n}}{2n!}+o(x^{2n+1})
$$
**Logaritmo** $\log(1+ax)$
$$
\log(1+ax)=ax-\frac{(ax)^{2}}{2}+\frac{(ax)^{3}}{3}+o(x^{3})
$$
## Resto di Lagrange
$$
\begin{align}
R_{n}(x)&=\frac{f^{(n+1)}(\xi)}{(n+1)!}(x-c)^{n+1}, \quad \xi \in(c,x) \lor \xi \in (x,c) \\
&\Rightarrow f(x)=\underbrace{P_{n,c}}_{\textcolor{red}{\text{Taylor}}}+\underbrace{\frac{f^{(n+1)}(\xi)}{(n+1)!}(x-c)^{n+1}}_{\textcolor{red}{\text{Resto di Lagrange}}}
\end{align}
$$
In questo caso l'errore commesso è:
$$
E_{n}(x)=|f(x)-\frac{f^{n+1}(\xi)}{(n+1)!}(x-c)^{n+1}|
$$
L'errore si può stimare in questo modo:
**Formula per stimare l'errore** o **disuguaglianza di Taylor**:
$$
E_{n}(x)\leq \underbrace{\max\limits_{{\xi \in [c,x]}} |f^{n+1}(\xi)|}_{M_{n+1}(x)}(x-c)^{n+1}
$$
# Successioni numeriche
Una **successione** numerica è una funzione:
$$
\begin{align*}
  a:&\symbb{N} \to \symbb{R} \\
  &n \mapsto a_{n}=a(n)
\end{align*} \quad \symbb{N}=\{0,1,2,\dots\}$$
Una successione si denota con $\{a_{n}\}$ o $(a_{n})_{n}$ o $(a_{n})$.
Tipicamente ci sono 2 modi per assegnare una successione:
1. *Formula esplicita*
	1. $\begin{align}a_{n}:\{&n \in \symbb{N}:n \geq 1\}\to \symbb{R} \\ &n \mapsto \frac{1}{n}\end{align}$
2. *Formula ricorsiva*
	1. es: $a_{n} = \displaystyle\sum_{i=1}^{100}= (1)+(1+2)+(1+2+3)+(1+2+3+4+)+\dots$
Una successione $\{a_{n}\}$ si dice:
- *Monotona crescente* se $a_{n+1}\geq a_{n} \quad \forall n$
- *Monotona decrescente* se $a_{n+1}\leq a_{n} \quad \forall n$
- *Inferiormente limitata* se $\exists m \in \symbb{R}$ t.c:
	- $a_{n} \geq m \quad \forall n$
- *Superiormente limitata* se $\exists M \in \symbb{R}$ t.c:
	- $a_{n}\leq M \quad \forall n$
- *Limitata* se $\exp m,M \in \symbb{R}$ t.c:
	- $m \leq a_{n} \leq M \quad \forall n$
Si dice che $\{a_{n}\}$ tende a $l \in \symbb{R}$ per $n \to \infty$
$$\lim_{ n \to \infty } a_{n} = l$$
Se:
$$\forall \varepsilon \quad \exists N_{\varepsilon}\in \symbb{N} \text{ t.c } n>N_{\varepsilon}\Rightarrow |a_{n}-l|<\varepsilon$$
In questi casi si dice che $\{a_{n}\}$ è *convergente*.

Si dice che $\{a_{n}\}$ tende a $+\infty$ per $x \to \infty$
$$\lim_{ n \to \infty } a_{n} = +\infty$$
Rispettivo per $-\infty$.
Se:
$$\forall M > 0 \quad\exists N_{\varepsilon}\in \symbb{N} : n> N_{\varepsilon} \Rightarrow a_{n} > M$$
Rispettivo per $a_{n}<-M$.
In questi casi si dice che $\{a_{n}\}$ è *divergente*.
Si dice che $\{a_{n}\}$ è *indeterminata* se non è nè convergente, nè divergente.
## Confronti di crescita
Date 2 successioni $\{a_{n}\}$ e $\{b_{n}\}$ t.c:
$$\lim_{ n \to +\infty } a_{n}=\lim_{ n \to \infty } b_{n}=+\infty$$
Vogliamo capire quale sia la successione più grande:
Per procedere in modo rigoroso si deve considerare il rapporto:
$$\frac{a_{n}}{b_{n}}$$
Se $\displaystyle\lim_{ n \to \infty }\frac{a_{n}}{b_{n}}=0, \{a_{n}\}$ tende a $+\infty$ "più lentamente" di $\{b_{n}\}$.

Per parlare di informazioni sulla crescita di successioni è utile introdurre alcune definizioni.
Una proprietà vale *definitivamente* per $\{a_{n}\}$ se la proprietà è vera $\forall n \geq n_{0}$, cioè è vera da un certo indice in poi.
## Successioni definite per ricorrenza
È una successione in cui ciascun termine è ottenibile dal precedente (o dai precedenti) attraverso una formula che si ripete. Sistema dinamico:
$$
\begin{cases}
   a_{1} = \alpha &\text{assegnato } \\
   a_{n+1} = f(a_{n}) &\text{relazione ricorsiva}
\end{cases}
\quad \forall n
$$
$$
\begin{align}
&a_{1} = \alpha \\
&a_{2} = f(a_{1}) = f(\alpha) \\
&a_{3} = f(a_{2}) = f(f(\alpha)) \\
&a_{4} = f(a_{3}) = f(f(f(\alpha))) \\
&\vdots
\end{align}
$$
Il sistema si può vedere come modello per descrivere l'evoluzione di un sistema:
- assegnare $\alpha$ vuol dire assegnare la condizione iniziale
- $a_{n+1} = f(a_{n})$ è la "legge" che descrive l'evoluzione del sistema
Si dice che $\{a_{n}\}$ è la soluzione del sistema dinamico.
## Teorema
Sia $g:\symbb{R} \to \symbb{R}$ continua, e sia $\{x_{n}\}$ una soluzione del sistema dinamico, se esiste
$$\lim_{ n \to \infty } x_{n} = l \in \symbb{R}$$
allora $l$ è punto fisso di $g$.
Questo teorema dice che un sistema dinamico può convergere solo a un punto di equilibrio $x^{*}$.
- $x^{*}$ è un *punto di equilibrio stabile* se:
	- $\forall \varepsilon > 0 \ \exists \delta > 0 : |x_{0}-x^{*}|<\delta\Rightarrow |x_{n}-x^{*}|<\varepsilon\quad \forall n \in \symbb{N}$
	- cioè la soluzione $\{x_{n}\}$ rimane arbitrariamente vicina a $x^*$ purché sia sufficientemente vicina la condizione iniziale a $x_{0}$.
- $x^*$ è *punto di equilibrio asintoticamente stabile* se è stabile e:
	- $\displaystyle\exists \delta' > 0 : |x_{0}-x^{*}|<\delta' \Rightarrow \lim_{ n \to \infty }x_{n} = x^*$
	- se la condizione iniziale è abbastanza vicina ad $x^{*}$, allora la soluzione tende a $x^*$.
- $x^*$ è *punto di equilibrio instabile* se non è stabile.

Nel caso lineare $g(x)=ax+b$, con $a \neq 1$, abbiamo visto che il sistema dinamico ha un solo equilibrio dato da:
$$x^*=\frac{b}{1-a}$$
$x^*$ è:
- asintoticamente stabile se $|a|<1$
- instabile se $|a|>1$
Nel caso generale vale il seguente risultato di stabilità/instabilità per linearizzazione.
## Teorema
Sia $g:\symbb{R} \to \symbb{R}$ di classe $\zeta'$(derivata 1 volta), e sia $x^*$ un punto fisso di $g$ allora:
- $|g'(x^{*})|<1\Rightarrow x^*$ è un punto di equilibrio asintoticamnte stabile
- $|g'(x^*)|>1\Rightarrow x^*$ è un punto di equilibrio instabile
# Risoluzione approssimata di equazioni
La maggior parte delle equazioni non si risolve in forma esatta.
Es: $e^{x-3=0}\quad x \in \symbb{R}$
Non si riesce a risolvere esplicitamente. Servono:
- Risultati teorici che garantiscano l'esistenza di soluzioni.
- Metodi numerici per il calcolo approssimato di soluzioni.
## Teorema di esistenza degli zeri
Sia $f:[a,b] \to \symbb{R}$ continua.
Se:
$$f(a)\cdot f(b)<0 \Rightarrow \exists c \in (a,b) \quad \text{t.c: }f(c)=0$$
Se $f$ è continua e negli estremi $a$ e $b$ ha segno opposto(cambia segno), allora $f(x)=0$ ha almeno una soluzione in $(a,b)$.
$f(c)=0 \rightsquigarrow c$ si dice *zero* di $f$.
![[Pasted image 20240418103040.png|200]]
## Parità/Disparità
$f:\symbb{R} \to \symbb{R}$ è pari se $f(-x)=f(x) \quad \forall x \in \symbb{R}$.
$f:\symbb{R} \to \symbb{R}$ è dispari se $f(-x)=-f(x) \quad \forall x \in \symbb{R}$.
![[Pasted image 20240418103320.png|300]]
## Funzioni composte
$f(a,b) \to (c,d) \quad g(\alpha, \beta) \to \symbb{R} \quad \mathrm{Im}(f) \subset dom(g)$
$g \circ f:(a,b)\xrightarrow{f}(c,d)\xrightarrow{g}\symbb{R}$
1. $dom(g \circ f)$ è necessario che $\mathrm{Im}(f)\subset dom(g)$. Se questo non succede, a volte possiamo restringere $(a,b)$ in modo che la condizione valga.
2. *Monotonia* della composta:

|              | $g$ cresce           | $g$ decresce         |
|--------------|----------------------|----------------------|
| $f$ cresce   | $g \circ f$ cresce   | $g \circ f$ decresce |
| $f$ decresce | $g \circ f$ decresce | $g \circ f$ cresce   |
## Teorema dei valori intermedi
Combinando il teorema di esistenza degli zeri con Weierstrass, si dimostra il *teorema dei valori intermedi*.
Una funzione $f(x)$ continua in un intervallo $[a,b]$ chiuso e limitato, assume tutti i valori compresi tra $f(a)$ e $f(b)$.
Detti $m$ e $M$ il minimo e il massimo di $f$ su $[a,b]$:
$$\forall \lambda \in [m,M]\exists c_{\lambda}\in[a,b]\text{ t.c}$$
$$f(c_{\lambda})=\lambda$$
Ovvero $f$ assume tutti i valori intermedi tra il minimo e il massimo.
![[Pasted image 20240418104634.png|200]]
Lo zero potrebbe essere unico se $f$ è strettamente crescente/decrescente, ovvero in caso ci sia *unicità*.
Combinando il teorema di esistenza degli zeri e Weierstrass, si dimostra il *teorema dei valori intermedi*.
Sia $f[a,b]\to \symbb{R}$ continua, $[a,b]$ chiuso e limitato, $m$ il minimo e $M$ il massimo di $f$ su $[a,b]$:
$\forall \lambda \in[m,M] \exists c_{\lambda}\in[a,b]$ t.c:
$$f(c_{\lambda})=\lambda$$
($f$ assume tutti i valori intermedi tra il minimo e il massimo)
Per dimostrare il teorema di esistenza degli zeri abbiamo creato una successione di intervalli $[a_{n}, b_{n}]$ t.c:
1. in ciascun intervallo valgono le ipotesi del teorema, quindi contiene $c$
2. $b_{n}-a_{n}=\frac{b-a}{2^{n}}\quad \forall n \in \symbb{N}$
Questa procedura ci da un algoritmo per ottenere un valore approssimato di uno zero di $f$. Se approssimiamo $c$ con $a_{n}$(i con $b_{n}$, o qualsiasi altro punto di $[a_{n}, b_{n}]$), commettiamo al massimo un errore di $b_{n}-a_{n}=\frac{b-a}{2^n}$.
Per terminare l'algoritmo di approssimazione, fissiamo una "tolleranza" $\varepsilon$.
Se vogliamo approssimare $c$ con $a_{n}$, la tolleranza richiede che:
$$b_{n} - a_{n} = \frac{b-a}{2^n}<\varepsilon$$
dove $\frac{b-a}{2^n}$ è l'**errore massimo dopo $n$ interazioni**, e $\varepsilon$ la *tolleranza*.
$$\frac{b-a}{2^{n}}<\varepsilon\iff 2^n>\frac{b-a}{\varepsilon}\iff n>\log_{2}(\frac{b-a}{\varepsilon})$$
Es: per approssimare $c$ con tolleranza $ao^k=\varepsilon$, dovremo richiedere:
$$\displaystyle\begin{align}
n&>\log_{2}\left(\frac{b-a}{10^{-k}}\right) \\
&=\log_{2}((b-a)10^k)= \\
&=\log_{2}(b-a)+\log_{2}(10^k)= \\
&=\log_{2}(b-a)+k\log_{2}10
\end{align}$$
Data $f(x)=0, x \in I\subset \symbb{R}$ intervallo, come faccio a determinare $[a,b]$ in cui le ipotesi siano soddisfatte? Spesso è utile fare confronti grafici:
Es: $e^{x}+x-3=0 \quad x \in \symbb{R}$
La riscriviamo come:
$$e^{x}=3-x$$
dove $e^{x} = g(x)$ e $3-x = h(x)$. Quindi $f(x)=g-h$.
$$f(x)=0\iff g(x)=h(x)\iff (x,g(x)) \text{ è punto di intersezione tra }g \text{ e }h.$$
Possiamo usare $[0,3]$ come intervallo di partenza per la bisezione:
$$\begin{align}
&f(0)=e^{0}+0-3=-2<0 \\
&f(3)=e^{3}+3-3=e^{3}>0
\end{align}$$
Fissata una tolleranza di $\varepsilon=10^{-3}=0,001$, il **metodo di bisezione** in $[0,3]$ richiede:
$$\begin{align}
&n>\log_{2}3+3\log_{2}10\approxeq 11,6 \\
&\rightsquigarrow x \geq 12
\end{align}$$
Iterazioni per approssimare lo zero $c$ a meno di $\varepsilon$.
## Metodo delle tangenti di Newton
(detto anche Teorema di convergenza del metodo di Newton)
Possiamo anche usare il *metodo delle tangenti di Newton*:
$$\begin{align}
&f:[a:b]\to \symbb{R}, f \in C^{2}([a,b]) \text{ e } f',f'' \text{ non si annullano su }[a,b] \\
&\Rightarrow f \text{ è anche continua }\Rightarrow \text{ vale esistenza degli zeri}
\end{align}$$
- Preso un punto $x_{0}\in[a,b]$, considero la tangente a $f$ in $x_{0}$:
$$y=f(x_{0})+f'(x_{0})(x-x_{0})$$
- $x_{1}=$ zero della tangente $f(x_{0})+f'(x_{0})(x_{1}-x_{0})=0$
$$\Rightarrow x_{1}=x_{0}-\frac{f(x_{0})}{f'(x_{0})}$$
- Itero il procedimento: considero la tangente a $f$ in $x_{1}$, calcolo il suo zero
$$x_{n+1}=x_{n}-\frac{f(x_{n})}{f'(x_{n})}$$
Sotto opportune ipotesi $x_{n} \to c, c$ zero di $f$ non è detto che $x_{n}$ tenda a zero:
- Affinche $\{x_{n}\}$ sia ben definito si richiede $f'(x)\neq 0 \forall x \in[a,b]$  se $f \in \varphi'([a,b])$, questo implica $f$ strettamente monotona.
### Teorema
$f:[a,b]\to \symbb{R}$ di classe $\varphi'$. Supponiamo che:
1. $f(a)\cdot f(b)<0$
2. $f'$ e $f''$ non cambiano segno in $[a,b]$
3. $f(a)f''(a)>0$, oppure $f(b)f''(b)>0$
Allora $\exists! c \in (a,b)$ t.c. $f(c)=0$, e la succesisone $\{x_{n}\}$ definita da:
$$
\begin{cases}
x_{0}=a \\
x_{n+1}=x_{n}-\frac{f(x_{n})}{f'(x_{n})}
\end{cases}
\text{ se vale 3.}
$$
Oppure:
$$
\begin{cases}
x_{0}=b \\
x_{n+1}=x_{n}-\frac{f(x_{n})}{f'(x_{n})}
\end{cases}
\text{ se vale 3.}
$$
converge a $c$.
![[IMG_0990.jpeg|300]]
Es: $e^{x}+x-3=0$
Usando il metodo delle tangenti in $[0,3]$ si ottiene un valore approssimato con un errore più piccolo di $10^{-4}$ in sole 5 iterazioni($n \geq \frac{\log(\frac{10^{-4}}{|f(x_{0})|})}{\log(2)}$).
$f \in \zeta^{2}([0,3])$
$f'(x)=e^{x}+1 \quad\forall x$
con $e^{x} > 0 \quad \forall x$
$f''(x)=e^{x}>0 \quad \forall x$
$f(0)<0<f(3)$
In questo caso vale il punto *3.*, $f(3)f''(3)>0$:
$\begin{cases}x_{0}=3 \\x_{n+1}=x_{n}-\frac{f(x_{n})}{f'(x_{n})}\end{cases}$  converge a $c$.
# Serie numeriche
È possibile sommare infiniti numeri e ottenere un risultato finito?
### Paradosso di Achille-Tartaruga
![[Pasted image 20240505213138.png|250]]
La tartaruga parte prima di Achille.
Dopo $t_{0}+t_{1}+\dots+t_{n}+\dots$, Achille è ancora dietro a $T$.
Il punto è che "sommando" infiniti numeri positivi, si può ottenere un risultato finito.
Es:
1. $1+\frac{1}{2}+\frac{1}{4}+\dots+\frac{1}{2^{n}}+\dots$ risultato intuitivo: $2$
2. $1+1+1+\dots+1+\dots=+\infty$
3. $1+(-1)+1+(-1)+\dots$dots
Possiamo ragionare in 2 modi:
- $(1+(-1))+(1+(-1))+\dots=0$
- $1+(-1+1)+(-1+1)+\dots=1$
Quindi? Formalizziamo:
Sia $\{a_{n}\}_{n>n_{0}}$ successione. Si dice serie(numerica) di termine generale $a_{n}$ la somma formale:
$$\displaystyle\sum^{+\infty}_{n=n_{0}}a_{n}=a_{n_{0}}+a_{n_{0}+1}+a_{n_{0}+2}+\dots$$
Per dare senso introduciamo:
$$S_{n}=\sum^{n}_{k=n_{0}}a_{k} \quad \text{successione delle somme parziali (o delle ridotte)}$$
Questa serie si dice:
- **Convergente** se $\displaystyle\exists s \in \symbb{R}:\lim_{ n \to \infty }s_{n}=s$
- **Divergente** se $\displaystyle\lim_{ n \to \infty }s_{n}=\pm \infty$
- **Indeterminata** se $\displaystyle\not \exists \lim_{ n \to \infty }s_{n}$
Se $a_{n}\geq 0\quad \forall n$, si dice che la serie è *a termini non negativi* . In tal caso:
$$s_{n}=s_{n+1}+a_{n}\geq s_{n-1} \quad \forall n$$
Quindi $\{s_{n}\}$ è crescente e per il *teorema di esistenza del limite* la successine non può essere indeterminata.
Es:
2. $\displaystyle1+1+1+1+1+1+1+\dots=\sum^{+\infty}_{n=0}a_{n}$, dove $a_{n}=1 \quad \forall n$
$\displaystyle s_{n}=\sum^{n}_{k=0}a_{k}=\sum^{n}_{k=0}1=1+\underbrace{\dots}_{n+1 \text{ volte}}+1=n+1$
quindi
$\displaystyle\lim_{ n \to \infty }s_{n}=\lim_{ n \to \infty }(n+1)=+\infty$
Osservazione:
$$
\sum^{+\infty}_{n=0}c=
\begin{cases}
+\infty & \text{se } c>0\\
0 & \text{se } c=0 \\
-\infty & \text{se } c<0
\end{cases}
$$
3. $\displaystyle1+(-1)+1+(-1)+\dots=\sum^{+\infty}_{n=0}(-1)^{n}$
- $=+1$ se $n$ pari
- $=-1$ se $n$ dispari
$$
\begin{align}
&s_{0}=a_{0}=1 \\
&s_{1}=a_{0}+a_{1}=1+(-1)=0 \\
&s_{2}=a_{0}+a_{1}+a_{2}=1+(-1)+1=1 \\
&s_{3}=1+(-1)+1+(-1)=0 \\
&\vdots \\
&s_{n}=1+(-1)+\dots+(-1)=\begin{cases}
1 & \text{se }n \text{ pari}\\
0 & \text{se }n \text{ dispari}
\end{cases}
\end{align}
$$
La serie è *indeterminata*.
1. $a_{n}=\left( \frac{1}{2} \right)^{n}\quad \forall n$
Studiamo in generale $a_{n}=q^n$ (successione generica di base $Q\in\symbb{R}$).
$q=0 \lor q=1 \Rightarrow a_{n}=0 \quad \forall n \lor a_{n}=1$, già visto. $q=-1 \Rightarrow a_{n}=(-1)^{n}$
$q \neq_{0}, q \neq \pm 1$,
$\displaystyle\sum^{+\infty}_{n=0}q^{n}=? \quad s_{n}=\sum^{n}_{k=0}q^{k}=+1+q+q^{2}+q^{3}+\dots+q^{n}$
quindi
$$
\underbrace{\sum^{+\infty}_{n=0}q^{n}}_{\text{serie geometrica di base }q}=\lim_{ n \to \infty } s_{n}=
\begin{cases}
\frac{1}{1-q} & \text{se }|q|<1, q^{n+1}\to_{0} \\
\frac{-\inf}{(<0)}=\pm \infty & \text{se } Q \geq 1, \to q^{n+1} \to 0 \\
\not \exists & \text{se } q \leq -1, \to q^{n+1} \text{ non ha limite}
\end{cases}
$$
In particolare:
$\displaystyle\sum^{+\infty}_{n=0}\left( \frac{1}{2} \right)^{n}=\frac{1}{1-\frac{1}{2}}=\frac{1}{\frac{1}{2}}=2$ come ci aspettavamo.
La serie geometrica permette di scrivere come frazioni alcuni sviluppi decimali periodici:
- $1,\overline{5}=1,5555\dots$
$$
\begin{align}
&=1+\frac{5}{10}+\frac{5}{100}+\frac{5}{1000}+\dots+\frac{5}{10^n}+\dots \\
&=1+f\sum^{+\infty}_{n=1} \frac{1}{10^{n}} \\
&=1+5\cdot \left( \frac{1}{1-\frac{1}{10}}-1 \right)=1+5\cdot \left( \frac{10}{9}-1 \right)=1+\frac{5}{9}=\frac{14}{9}
\end{align}
$$
- $0,\overline{9}=1$
$$
0,999\dots=9\sum^{+\infty}_{n=1} \frac{1}{10^{n}}=9\left( \frac{1}{1-\frac{1}{10}}-1 \right)=9\left( \frac{10}{9}-1 \right)=9\cdot \frac{1}{9}=1
$$
- $1,4\overline{5}=1,4555\dots$
$$
\begin{align}
&= 1+\frac{4}{10}+\frac{5}{10^{2}}+\dots+\frac{5}{10^{n}}+\dots \\
&=5\left( \frac{\sum^{+\infty}_{n=0}1}{10^{n}}-1-\frac{1}{10} \right)=5\sum^{+\infty}_{n=2} \frac{1}{10^{n}} \\
&=1+\frac{4}{10}+5\left( \frac{1}{1-\frac{1}{10}}-1-\frac{1}{10} \right)=\dots=\frac{131}{90}
\end{align}
$$
**Problema fondamentale**: essere in grado di stabilire se una serie converga, diverga o sia indeterminata.
**Idea**: sviluppare dei criteri che consentano di ricondursi a casi noti.
## Criterio di convergenza
Consideriamo la successione $\{a_{n}\}=\frac{1}{n}$.
Verifichiamo la convergenza:
- consideriamo due termini $a_{n}$ e $a_{m}$ con $n,m>N$:
$$
|a_{n}-a_{m}|=|\frac{1}{n}-\frac{1}{m}|=|\frac{m-n}{nm}|
$$
**Condizione necessaria di convergenza**:
$\{a_{n}\}$ successione. Se la serie $\displaystyle\sum^{+\infty}_{n=0}a_{n}$ è convergente $\Rightarrow \lim_{ n \to \infty }a_{n}=0$.
Osservazione: $\displaystyle\sum^{+\infty}_{n=0}a_{n}$, con $a_{n} \not \to 0$ per $n \to \infty \Rightarrow$ la serie *non converge*.
Esempio *fondamentale*:
$$
\underbrace{\sum^{\infty}_{n=1}}_{\text{serie armonica generalizzata}} \frac{1}{n^\alpha}
\begin{cases}
\text{converge se } \alpha > 1 \\
\text{diverge a }+\infty \text{ se } \alpha \leq 1
\end{cases}
\quad
\text{notiamo che se }[0,1), \frac{1}{n^{\alpha}}\to 0 \text{ per }n \to \infty
$$
Il carattere di una serie non cambia se cambia l'indice di partenza, cambia eventualmente la somma della serie.
$n^{\alpha}<n^{\beta}\Rightarrow \frac{\frac{1}{n^{\alpha}}<1}{n^{\beta}}$
Più l'esponente è grande, più il termine $\frac{1}{n^{\beta}}$ è piccolo.
## Criterio del confronto
Siano $\{a_{n}\}$ e $\{b_{n}\}$ due successioni t.c.
Se $a_{n} \leq b_{n}$ vale definitivamente, possiamo dire che:
- se $a_{n}$ diverge (positivamente), allora $b_{n}$ diverge (positivamente)
- se $b_{n}$ converge, allora $a_{n}$ converge
## Criterio del confronto asintotico
Siano $\{a_{n}\}$ e $\{b_{n}\}$ successioni a termini $\geq 0$, supponiamo che $a_{n} \backsim b_{n}$ per $n \to \infty$, ovvero:
$$
\left( \lim_{ n \to \infty } \frac{a_{n}}{b_{n}} =1 \right)
$$
allora:
$$
\sum^{+\infty}_{n=0} a_{n} \text{ converge/diverge} \iff \sum^{+\infty}_{n=0}b_{n} \text{ converge/diverge}
$$
# Integrale definito
Sia $f:[a,b] \to \symbb{R}$ limitata ($\exists m,M \in \symbb{R}:m \leq f(x)\leq M \forall x$)
Con $[a,b]$ chiuso e limitato.
Fissato $n \in \symbb{N}$, si suddivide $[a,b]$ in $n$ sotto-intervalli di ampiezza $\frac{b-a}{n}$
Si scelgono in modo arbitrario $n$ punti detti "di campionamento":
$$
z_{i} \in [x_{i-1},x_{i}] \quad \forall i = 1,\dots,n
$$
Si considera la **somma di Riemann**:
$$
s_{n}(f;z_{1},\dots,z_{n}) = \sum^{n}_{i=1} \frac{b-a}{n} f(z_{i})
$$
Dove $\frac{b-a}{n}$ è la base di ciascun intervallo $[x_{i-1}, x_{i}]$.
$f(z_{i})$ altezza dell'$i$-esimo rettangolo in figura.
Ovvero rappresenta un valore approssimato dell'area.
L'**integrale definito di una funzione continua** $f(x)$ in un intervallo $[a,b]$ si calcola con:
$$
\int^{b}_{a}f(x)dx = \lim_{ n \to \infty } s_{n}(f;z_{1},\dots,z_{n})
$$
Una funzione è integrabile se:
- $f$ è continua su $[a,b]$
- $f$ monotona e limitata
- $f$ con un numero di $\infty$ di discontinuità a salto sono integrabili
**Proprietà**:
- *linearità*: se $f$ e $g$ sono integrabili in $[a,b]$ e $\alpha, \beta \in \symbb{R}$, allora:
$$
\begin{align}
\alpha f+\beta g \text{ è integrabile su }[a,b] \text{ e } \\
\int^{b}_{a}(\alpha f(x)+\beta g(x))dx = \alpha \int^{b}_{a}f(x)dx+\beta \int^{b}_{a}g(x)dx
\end{align}
$$
- *additività rispetto al dominio*: se $f$ integrabile su $[a,b]$ e $c \in (a,b)$, allora $f$ è integrabile su $[a,c]$ e su $[c,b]$, e:
$$
\int^{b}_{a}f=\int^{c}_{a}f+\int^{b}_{c}f
$$
![[IMG_0991.jpeg|200]]
- *l'integrale è un'area "consegno"*:
![[IMG_0992.jpeg|200]]
$$
\int^{b}_{a}f=\text{area}(A_{1})-\text{area}(A_{2})+\text{area}(A_{3})
$$
Se vogliamo l'area senza segno:
$$
\int^{b}_{a}|f|=\text{area}(A_{1})+\text{area}(A_{2})+\text{area}(A_{3})
$$
- *monotonia*: se $f$ e $g$ sono integrabili e $g(x) \leq f(x) \quad \forall x \in[a,b]$, allora:
$$
\int^{b}_{a}g \leq \int^{b}_{a}f
$$
In particolare, se $f(x) \geq 0 \quad \forall x \in[a,b]$, allora:
$$
\int^{b}_{a}f(x)dx \geq 0
$$
- *integrale di costante*:
$$
c \in \symbb{R}, \int^{b}_{a}cdx = (b-a)c
$$
![[IMG_0993.jpeg|200]]
## Teorema della media integrale
Sia $f:[a,b] \to \symbb{R}$ continua su $[a,b]$. Allora $\exists$ un punto $x_{0} \in [a,b]$ t.c:
$$
f(c)=\frac{1}{b-a}\int^{b}_{a}f(x)dx
$$
Ovvero $\exists$ un punto  $c \in [a,b]$ dove $f$ assume in suo valore medio.
![[IMG_0994.jpeg|250]]
$$
\int^{b}_{a}f(t)dt = f(x_{0}) \cdot (b-a)
$$
## Calcolo esatto di integrali
Sia basa sul:
## Teorema di valutazione (o Torricelli-Barrow)
Sia $f:[a,b] \to \symbb{R}$ continua e sia $F$ una primitiva di $f$ su $[a,b]$, allora:
$$
\int^{b}_{a}f(x)dx = F(b)-F(a)
$$
Es:
$$
f(x)=x^{4} \quad F(x)=\frac{x^{5}}{x}
$$
$$
\int^{2}_{-1}x^{4}dx = \frac{x^{5}}{5}|^{2}_{-1} = \frac{2^{5}}{5}-\frac{(-1)^{5}}{5}=\frac{32}{5}+\frac{1}{5}=\frac{33}{5}
$$
Il teorema mostra un primo collegamento tra calcolo differenziale e integrale
$$
\text{calcolo di primitiva (differenziale)} \longrightarrow \text{calcolo} \int^{b}_{a}f(x)dx
$$
Dimostrazione:
Dato $n \in \symbb{N}$, consideriamo la suddivisione di $[a,b]$ in $n$ sottoinsiemi di ampiezza $\frac{b-a}{n}$:
$$
a=x_{0}<x_{1}<x_{2}<\dots<x_{n}=b, \quad x_{i}-x_{i-1}=\frac{b-a}{n}
$$
Possiamo scrivere:
$$
\begin{align}
F(b)-F(a)&=F(x_{n})-F(x_{0}) \pm F(x_{1})\pm F(x_{2})\dots \pm F(x_{n-1}) \\
&= (F(x_{n})-F(x_{n-1}))+(F(x_{n-2})-F(x_{n-2}))+\dots+ (F(x_{2})-F(x_{1}))+(F(x_{1})-F(x_{0})) \\
&= \sum^{n}_{i=1}(F(x_{i})-F(x_{i-1}))
\end{align}
$$
$F$ è una primitiva su $[a,b]$ di $f$, quindi $F$ è derivabile in $[a,b] \Rightarrow$ vale il [[#Teorema di Lagrange]] in ogni intervallo $[x_{i-1}, x_{i}]: \exists z_{i} \in (x_{i-1},x_{i})$ t.c.
$$
F(x_{i})-F(x_{i-1})=\underbrace{F'(z_{i})}_{=f(z_{i})}(x_{i},x_{i-1})
$$
Quindi: **(\*)**
$$
\begin{align}
F(b)-F(a)&=\sum^{n}_{i=1}f(z_{i})(x_{i},x_{i-1})=\sum^{n}_{i=1}f(z_{i})\frac{b-a}{n} \\
&=S_{n}(f;z_{1},\dots,z_{n}), \quad \forall n \in \symbb{N} \text{ (somma di Riemann)}
\end{align}
$$
Passiamo ora al limite per $n \to \infty$:
$$
\begin{align}
&\lim_{ n \to \infty } (F(b)-F(a))=F(b)-F(a) \\
&\lim_{ n \to \infty } S_{n}(f;z_{1},\dots,z_{n})=\int^{b}_{a}f(x)dx
\end{align}
$$
$f$ è continua quindi integrabile, $S_{n}(f;z_{1},\dots,z_{n}) \to \int^{b}_{a}f$ indipendentemente da $z_{1},\dots,z_{n}$.
**(\*)** implica che:
$$
F(b)-F(a)=\int^{b}_{a}f(x)dx
$$
*Es*:
$$
\int^{\color{orange}2}_{\color{red}{-1}}x^{4}dx
 \overbrace{=}^{F(x)} \bigg[\frac{x^{5}}{5}\bigg]^{\color{orange}2}_{\color{red}{-1}}= \frac{\color{orange}2\color{black}^{5}}{5}-\frac{(\color{red}{-1} \color{black}{)^{5}}}{5}=\frac{32}{5}+\frac{1}{5}=\frac{33}{5}$$
 $F(x) = \frac{x^{5}}{5}$
## Stime errore nell'approssimazione integrale
La formula teorica per la stima dell'errore $E$ nell'approssimazione dell'integrale:
$$
\int^{b}_{a}f(x)dx
$$
vale:
$$
|E| \leq \frac{K}{24N^{2}}(b-a)^{3}
$$
dove $K$ vale:
$$
max_{[a,b]}|f''|
$$
## Funzioni integrali
$f:[a,b] \to \symbb{R}$ integrabile (o continua):
![[IMG_1011.jpeg|250]]
$\forall x \in [a,b]$, possiamo calcolare l'integrale definito di $f$ nell'intervallo di estremi $x_{0},x$:
$$
x \in [a,b] \mapsto \int^{x}_{x_{0}}f(t)dt=
\begin{cases}
\int^{x}_{x_{0}}f &\text{ se }x>x_{0} \\
0 &\text{ se }x=x_{0} \\
-\int^{x}_{x_{0}} &\text{ se }x<x_{0}
\end{cases}
$$
Questa si dice **funzione integrale** , o **di accumulazione**, di $f$, centrata in $x_{0}$.
## Teorema fondamentale del calcolo integrale
Sia $f:[a,b] \to \symbb{R}$ continua.
Fissato $x_{0} \in [a,b]$, consideriamo la funzione integrale:
$F(x)=\int^{x}_{x_{0}}f(t)dt \quad \forall x \in[a,b]$
allora $F$ è derivabile in $[a,b]$, e $F'(x)=f(x)$, cioè $F$ è primitiva di $f$.
- ogni $f$ continua amette primitiva, data dalla funzione integrale
- da [[#Teorema di valutazione (o Torricelli-Barrow)]] e [[#Teorema fondamentale del calcolo integrale]] si evince che integrazione $\int$ e derivazione $\frac{d}{dx}$ sono "inverse"
- $F(x)=\int^{x}_{x_{0}}f(t)dt$ è una primitiva di $f$, è la primitiva che si annulla in $x_{0}$, $F(x_{0})=0$
![[IMG_1012.jpeg|300]]
$F(x_{0})=0, f(t)>0 \quad \forall t \in[a,b]$
$\Rightarrow F'(x)>0 \forall x \Rightarrow F$ è crescente in $[a,b]$
$F \nearrow$ in $[a,x_{1}]$ e $[x_{2},b], f \searrow$ in $[x_{1},x_{2}]$
$\Rightarrow F$ è convessa in $[a,x_{1}]$ e $[x_{2},b]$
$\Rightarrow F$ è concava in $[x_{1},x_{2}]$
*Oss*: non sempre le primitive si possono determinare in forma esplicita, ad esempio le primitive di $e^{-x^{2}}$:
$$
\int^{x}_{0}e^{-t^{2}}dt = F(x) \text{ è primitiva di } e^{-x^{2}}
$$
![[Pasted image 20240507154148.png|200]]
Grafico, per il teorema fondamentale, sappiamo che:
$F'(x)=e^{-x^{2}}>0 \quad \forall x$
$\Rightarrow$ (monotonia) $F$ è sempre $\nearrow$
$F''(x)=(e^{-x^{2}})'=e^{-x^{2}}(-2x)=-2xe^{-x^{2}}$
$\textcolor{red}{(e^{t})'=e^{t}}$
$\textcolor{red}{-x^{2}=-2x}$
$$
F''(x)
\begin{cases}
>0 &\text{se }x<0 &F \text{ è convessa in }[-\infty,0] \\
<0 &\text{se }x>0 &F \text{ è concava in }[0,+\infty]
\end{cases}
$$
![[IMG_1013.jpeg|250]]
## Integrali generalizzati o impropri
Si tratta di integrali in cui (almeno) un estremo di integrazione è infinito:
$$
\int^{+\infty}_{a}f(x)dx, \quad \int^{b}_{-\infty}f(x)dx, \quad \int^{+\infty}_{-\infty}f(x)dx
$$
Consideriamo il primo tipo, il secondo è analogo, il terzo è una somma dei due precedenti.
Quale è il significato geometrico di $\displaystyle\int^{+\infty}_{a}f(x)dx$?
Se $f(x)\geq 0$, si vuole definire **l'area** della regione infinita tra grafico di $f$ e l'asse $x$.
$f$ continua in $a$ (dove $f \in \zeta([a,+\infty))$), allora $f \in \zeta([a,b]), \forall b > a$.
$\Rightarrow$ è ben definita $\displaystyle\int^{b}_{a}f(x)dx$ si definisce:
$$
\int^{+\infty}_{a}f(x)dx = \lim_{ \textcolor{blue}{b \to +\infty} } \int^{\textcolor{blue}{b}}_{a}f(x)dx
$$
Purché il limite esista.
Il valore di questo limite si dice **integrale generalizzato** (o *improprio*) di $f$ in $[a,+\infty)$.
- l'integrale è *convergente* se $\lim$ è finito
- l'integrale è *divergente* se $\lim = \pm \infty$ 
- l'integrale è *indeterminato* se $\not \exists \lim$
$f:[a,+\infty)\to \symbb{R}$ continua, definiamo $\displaystyle F(x)=\int^{+\infty}_{a}f(t)dt$
$$
\int^{+\infty}_{a}f(x)dx \overbrace{=}^{def}\lim_{ x \to +\infty } F(x)
$$
Se $f(x)\geq 0 \forall x \geq a$, allora $F(x)$ è definitivamente crescente per $x \to +\infty$
$$
F'(x)=f(x)\geq 0
$$
$\Rightarrow$ per monotonia, esiste $\lim_{ x \to +\infty }F(x)=\int^{+\infty}_{a}f(x)dx$, finito o infinito.
*Esempio fondamentale*:
Per $\alpha>0$, consideriamo $f(x)=\frac{1}{x^{\alpha}}$ su $[1,+\infty)$, e
$$
\frac{\int^{+\infty}_{1}1}{x^{\alpha}}=\lim_{ x \to +\infty } \int^{x}_{1} \frac{1}{t^{\alpha}}dt
$$
Primitive di $f(t)=\frac{1}{t^{\alpha}}=t^{-\alpha}$ sono:
- $\log t+c, c \in \symbb{R} \quad \text{ se }\alpha=1$
- $\frac{t^{1-\alpha}}{1-\alpha}+c, c \in \symbb{R} \quad \text{ se }\alpha \neq 1$
Quindi per il [[#Teorema di valutazione (o Torricelli-Barrow)]]:
$$
\int^{\alpha}_{1} \frac{1}{t^{\alpha}}dt =
\begin{cases}
\log t|^{x}_{1} = \log x- \overbrace{\log 1}^{=0} = \log x & \alpha=1\\
\\
\frac{t^{1-\alpha}}{1-\alpha} |^{\alpha}_{1} = \frac{x^{1-\alpha}}{1-\alpha}- \frac{1}{1-\alpha} &\alpha \neq 1
\end{cases}
$$
$\displaystyle\Rightarrow \int^{+\infty}_{1} \frac{1}{x^{\alpha}}dx = \lim_{ x \to +\infty }\int^{\alpha}_{1} \frac{1}{t^{\alpha}}dt$
$$
=
\begin{cases}
\lim_{ x \to +\infty }\log x = +\infty & \alpha = 1\\
\\
\lim_{ x \to +\infty } \frac{1}{1-\alpha}\cdot \frac{1}{x^{\alpha-1}}+\frac{1}{\alpha-1} = \frac{1}{\alpha-1} & \alpha > 1, 1-\alpha<0 \\
\\
\lim_{ x \to +\infty } \frac{x^{1-\alpha}}{1-\alpha}- \frac{1}{1-\alpha}=+\infty & \alpha < 1
\end{cases}
$$
Conclusione:
$\displaystyle\int^{+\infty}_{1} \frac{1}{x^\alpha}dx$ converge $\iff \alpha > 1$,
$\displaystyle\int^{+\infty}_{1} \frac{1}{x^\alpha}dx$ diverge a $+\infty \iff \alpha \leq 1$,
La convergenza/divergenza è legata alla velocità con cui $f(x)$ tende a $0$ per $x \to +\infty$.
**Analogie con le serie**:
- $\int^{+\infty}_{1} \frac{1}{x^{\alpha}}dx$ converge $\iff \alpha > 1$
- $\sum^{+\infty}_{n=1} \frac{1}{n^{\alpha}}$ converge $\iff x > 1$
Per saper stabilire se $\int^{+\infty}_{a}f$ converge come per le serie, usiamo criteri di convergenza:
1. **Criterio del confronto**: siano $f,g$ derivabili in $[a, +\infty)$, tale che $f(x),g(x)\geq 0$ definitivamente per $x \to +\infty$, supponiamo che $f(x) \leq g(x)$ definitivamente per $x \to +\infty$, allora:
	1. $\int^{+\infty}_{a}g(x)dx$ converge $\Rightarrow \int^{+\infty}_{a}f(x)dx$ converge
	2. $\int^{+\infty}_{a}f(x)dx$ divergen $\Rightarrow \int^{+\infty}_{a}g(x)dx$ diverge
2. **Criterio del confronto asintotico**: siano $f,g$ derivabili in $[a,+\infty)$, tale che $f(x),g(x) \geq 0$ definitivamente per $x \to +\inf$, supponiamo che:
	$f(x) \backsim g(x)$ per $x \to +\infty$, cioè che:
		$\lim_{ x \to +\infty }\frac{f(x)}{g(x)}=1$
	allora $\int^{+\infty}_{a}f=+\infty \iff \int^{+\infty}_{a}g=+\infty$
**Esempio**: studiare la convergenza di:
$$
\int^{+\infty}_{a}\frac{x^{2}}{\underbrace{x^{3}+x+1}_{f(x)}}dx
$$
$f$ derivabile in $[1,+\infty), f \geq 0$ in $[1,+\infty)$
$$
\frac{x^{2}}{x^{3}+x+1}=\frac{x^{2}}{x^{3}\left( 1+\underbrace{\frac{1}{x^{2}}}_{\to 0}+\underbrace{\frac{1}{x^{3}}}_{\to 0} \right)} \backsim \frac{x^{2}}{x^{3}}=\frac{1}{x} \text{ per } x \to +\infty
$$
Siccome $\int^{+\infty}_{1} \frac{1}{x}dx=+\infty \Rightarrow$ per confronto asintotico, diverge, anche $\int^{+\infty}_{1} \frac{x^{2}}{x^{3}+x+1}dx=+\infty$.
## Criterio del confronto integrale per la convergenza di una serie
Supponiamo di avere una serie:
$$
\sum^{\infty}_{n=1} a_{n}
$$
dove $a_{n} = f(n)$ e $f$ è una funzione *continua*, positiva e decrescente su $[1,\infty)$. Il criterio del confronto integrale si basa sulla relazione tra questa serie e l'integrale improprio:
$$
\int^{\infty}_{1} f(x)dx
$$
Si possono fare le seguenti osservazioni:
$$
\begin{align}
\int^{\infty}_{n_{0}}f(x)dx \text{ converge } \iff \sum^{\infty}_{n=n_{0}}a_{n} \text{ converge } \\
\int^{\infty}_{n_{0}}f(x)dx \text{ diverge } \iff \sum^{\infty}_{n=n_{0}}a_{n} \text{ diverge }
\end{align}
$$
