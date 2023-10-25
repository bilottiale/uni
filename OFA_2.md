# *Insiemi*
Gli insiemi sono denotati con le lettere maiuscole dell’alfabeto, gli elementi con le lettere minuscole.  
$\in$ : simbolo di appartenenza, che si usa solo tra un elemento e un insieme.  
$\notin$ : simbolo di non appartenenza, che si usa solo tra un elemento e un insieme.  

Per indicare che un elemento $x$ appartiene ad un insieme $A$ si scrive:
$$x \in A$$
Per indicare che un elemento $y$ non appartiene ad un insieme $A$ si scrive:
$$y \notin A$$
## *Rappresentare gli insiemi*
1) Con i diagrammi di Eulero–Venn:
![[Pasted image 20231016170340.png|350]]

2) Con l’elenco degli elementi, racchiusi tra parentesi graffe
Esempio: $A = \{1, 2, 3\}$
3) Con una proprietà caratteristica dell’insieme
Esempio: $B = \{\text{studenti iscritti a questo corso}\}$

## *Insiemi importanti*
Naturali
$$\mathbb{N} = \{0, 1, 2, 3,\dots\}$$
Relativi
$$\mathbb{Z} = \{\dots, -3, -2, -1, 0, 1, 2, 3,\dots\}$$
Razionali
$$\mathbb{Q} = \{\frac{a}{b}| a, b \in \mathbb{Z}, b \neq 0\}$$
Reali
$\mathbb{R}$ è l'insieme dei numeri reali (razionali e irrazionali)

## *Inclusione*
Si tratta di una relazione tra due insiemi, che si indica con il simbolo $\subseteq$ oppure $\subset$ .

$A \subseteq B$ : si legge $A$ è contenuto (o incluso) in $B$, vale a dire ogni elemento di $A$ è anche un elemento di $B$. Notare che la scrittura $A \subseteq B$non esclude che $A = B$.
Ordine inclusione tra insiemi:
$$\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R}$$
Preso un qualunque insieme $A$ vale $\varnothing \subseteq A$ e anche $A \subseteq A$
## *Insieme delle parti*
Sia $X$ un insieme; l’insieme delle parti di $X$, denotato con $\square(X)$, è l’insieme di tutti i sottoinsiemi di $X$:
$$\square(X) = \{A | A \subseteq X\}$$
Esempio:
$$X = \{1, 2, 3\} \quad \square(X)= \{\varnothing, \{1\}, \{2\}, \{3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, X\}$$
## *Intersezione*
![[Pasted image 20231017151644.png|350]]
## *Unione*
![[Pasted image 20231017151658.png|350]]
## *Differenza simmetrica*
![[Pasted image 20231017151711.png]]
## *Complementare*
![[Pasted image 20231017151724.png|350]]
## *Prodotto cartesiano*
Dati due insiemi $A$ e $B$, si definisce prodotto cartesiano di $A$ e $B$ l'insieme $A \times B$ di tutte le coppie ordinate $(a, b)$ per ogni $a \in A$ e per ogni $b \in B$.
Esempio:
$A = \{0, 1, 2\}$
$B = \{x,y\}$
$A \times B = \{(0,x),(0,y),(1,x),(1,y),(2,x),(2,y)\}$
# *Cenni elementari di logica*
*Proposizione logica*: un'affermazione per la quale si può stabilire con certezza, in modo oggettivo, se è vera o falsa.
*"5 è un numero primo"* proposizione logica vera
*"4 è un multiplo di 3"* proposizione logica falsa

*Predicato*: na proposizione il cui valore di verità dipende da una o più variabili.
*"$x$ è maggiore di zero, $x \in \mathbb{Z}$"* il predicato è vero per valori di $x$ positivi, falso per valori di $x$ negativi.

*Quantificatori*:
* Universale ($\forall$):
	* $n + 1 > n, \forall n \in \mathbb{N}$ --> tutti gli elementi di $\mathbb{N}$ sono validi
* Esistenziale ($\exists$):
	* $\exists x \in \mathbb{Z}|x^{2}-16=0$ --> esiste almeno un valore che soddisfa la proprietà
(esiste uno e uno solo ($\exists!$))
## *Connettivi logici*
*And*:
$$p \land q$$
*Or*:
$$p \lor q$$
*Implicazione*:
"Se... allora..."
$$p \implies q$$
*Doppia implicazione*:
"Se e solo se"
$$p \iff q$$
*Negazione*:
"non"
$$\neg p$$
## *Dimostrazione e controesempi*
Dimostrare un'implicazione:
* *Diretta*:
"Se $x$ è dispari allora $x^2$ è dispari"
Dimostrazione:
Suppongo $x$ dispari: $x = 2a + 1, a \in \mathbb{Z}$
$x^{2}=(2a+1)^{2}=4a^{2}+4a+1$
pongo --> $4a^{2}+4a=2b,b\in\mathbb{Z}$
quindi --> $x^{2}=2b+1,b\in\mathbb{Z}$
quindi --> $x^{2}$ è dispari
* *Dimostrazione indiretta: contronominale*
Nella tecnica di dimostrazione per contronominale, anziché dimostrare l’implicazione diretta $H \implies T$ se ne dimostra la contronominale, ossia $\neg T \implies \neg H$
Dimostrazione:
Siano $a,b,c$ numeri reali con $a>b$. Se $ac\leq bc$  allora $c\leq 0$:
Dimostriamo la contronominale, ovvero che se $c > 0$ allora $ac > bc$.
Questo è ovvio, basta moltiplicare ambo i membri di $a > b$ per $c$ (lo possiamo fare perché $c$ è positivo).
* *Dimostrazione indiretta: per assurdo*
La tecnica di dimostrazione indiretta per assurdo consiste nell’assumere l’ipotesi $H$ e la negazione della tesi $\neg T$. 
Dimostrazione:
Sia $n \in \mathbb{N}$. Dimostrare che se $n^{2}$ è un numero parti allora $n$ è pari.
Procediamo per assurdo assumendo come ipotesi che $n^{2}$ sia un numero naturale pari ce che esista almeno un numero $n$ non pari(negazione della tesi).
Allora un tale $n$ dispari si può scrivere come $n = 2p+1$ con $p \in \mathbb{N}$.
Quindi $n^{2}=4p^{2}+2p+1$ ossia $n^{2}$ è dispari, in contrasto con l'ipotesi.
* *Controesempio*
Per confutare una proposizione è sufficiente produrre un controesempio, ossia un solo esempio che, pur verificando le ipotesi, non verifica la tesi.
# *Numeri*
## *Numeri irrazionali*
Soffermiamoci sulla misura della diagonale di un quadrato di lato uno: applicando il teorema di Pitagora segue che la misura di quella diagonale è $\sqrt{2}$.
Si può dimostrare che $\sqrt{2}$ non è un numero razionale, cioè che non è rappresentabile nella forma $\frac{m}{n}$ con $m,n$ interi.
## *Polinomi e fattorizzazione*
Un polinomio si scrive nella forma:
$$a_{n}x^{n}+a_{n-1}x^{n-1}+\dots+a_{2}x^{2}+a_{1}x+a_{0} \quad n\in N$$
## *Somma di polinomi*
Si sommano i termini simili
$$(5x^{4}-3x^{3}-2x)+(7x^{4}+5x^{3}+3x^{2}+2) = $$
$$(5+7)x^{4}+(-3+5)x^{3}+(+3)x^{2}+(-2)x+2 = $$
$$12x^{4}+2x^{3}+3x^{2}-2x+2$$
## *Differenza di polinomi*
Tra termini simili
$$(5x^{4}-3x^{3}-2x)-(7x^{4}+5x^{3}+3x^{2}+2) = $$
$$(5-7)x^{4}+(-3-5)x^{3}+(-3)x^{2}+(-2)x-2 = $$
$$-2x^{4}-8x^{3}-3x^{2}-2x-2$$
## *Prodotto di polinomi*
Si moltiplica ciascun termine di uno per ciascun termine dell'altro e sommando alla fine i termini simili
$$(x^{3}+3x-2) \cdot (x^{2}-2x)=$$
$$x^{3} \cdot x^{2}+x^{3} \cdot (-2x) + 3x \cdot x^{2} + 3x \cdot (-2x) + (-2) \cdot x^{2} + (-2) \cdot (-2x) = $$
$$x^{5}+-2x^{4}+3x^{3}-6x^{2}-2x^{2}+4x =$$
$$x^{5}-2x^{4}+3x^{3}-8x^{2}+4x$$
## *Divisione di polinomi*
Esempio:
$$(2x^{3}-3x^{2}+x-6)/(x-2)$$
![[Pasted image 20231017163726.png|250]]
![[Pasted image 20231017163731.png|250]]
![[Pasted image 20231017163736.png|250]]
![[Pasted image 20231017163743.png|250]]
$$(2x^{3}-3x^{2}+x-6)/(x-2)=$$
$$2x^{2}+x+3$$
## *Raccoglimento a fattor comune*
Quando si osserva che in tutti i termini di un polinomio compare lo stesso fattore è possibile raccoglierlo a fattor comune.
Esempi:
* $7x^{2}+5x$
$x$ è comune --> $7x^{2}+5x = x(7x+5)$
* $15x^{3}+3x^{2}-6x$
$3x$ è comune --> $15x^{3}+3x^{2}-6x = 3x(5x^{3}+x^{2}-2)$
A volte non compare un fattore comune a tutti i termini di un polinomio, ma comune solo in alcuni suoi termini: in questi casi potrebbe essere possibile effettuare dei *raccoglimenti parziali* come nel seguente esempio.
$x^{2}+4x-6x-24$
$x(x+4)-6(x+4) = (x+4)(x-6)$
## *Prodotti notevoli*
*Quadrato di un binomio*:
$(A \pm B)^{2} = A^{2}\pm 2AB + B^{2}$
*Cubo di un binomio*:
$(A\pm B)^{3} = A^{3}\pm 3A^{2}B+3AB^{2}\pm B^{3}$
*Differenza di due quadrati*:
$A^{2}-B^{2}=(A+B)(A-B)$
*Somma o differenza di 2 cubi*:
$A^{3}+B^{3}=(A+B)(A^{2}-AB+B^{2})$
$A^{3}-B^{3}=(A-B)(A^{2}+AB+B^{2})$
#Esempio 
$x^{4}-49 = (x^{2}+7)(x^{2}-7)$
$36x^{2}-48x+16 = 4(9x^{2}-12x+4)$
## *Fattorizzazione applicando il teorema del resto*
Le radici razionali di un polinomio sono da ricercare tra i divisori del termine noto, presi sia con segno positivo che negativo, o tra i rapporti tra tali divisori e i divisori del termine di grado massimo.
#Esempio 
$$x^{2}-x-6$$
Il teorema del resto ci dice di cercare le radici razionali del polinomio tra i divisori del termine noto: $\pm1, \pm2, \pm3, \pm6$.
Sostituendo tali numeri alla variabile $x$ e svolgendo i calcoli si trova che solo $+2$ rende il polinomio nullo. L’unica radice razionale è quindi $+2$.
Possiamo scomporre il polinomio in fattori (un fattore sarà $x - 2$):
![[Pasted image 20231017181032.png|250]]
Conclusione: $x^{3}-x-6=(x-2)(x^2+2x+3)$
# *Equazioni e disequazioni algebriche di 1° grado con una incognita*
$$ax+b=0$$
$$a,b \in \mathbb{R}$$
Le soluzioni dell’equazione sono i valori che sostituiti ad x rendono vera l’uguaglianza.
Si possono presentare 3 casi:
* *determinata*, una sola soluzione data da $x = \frac{-b}{a}$
* *impossibile*, quando è priva di soluzioni, nessun valore di $x$ la soddisfa
* *indeterminata* o *identità*, quando le soluzioni sono infinite, l'equazione è verificata per ogni valore assunto da $x$
## *Esempi di risoluzione*
* $5(x-3)=2(x+6)$
	* $5x-15=2x+12$
	* $5x-2x-15-12=0$
	* $3x-27=0$
	* $ax-b=0$ --> $x=\frac{-b}{a}$ --> $\frac{-(-27)}{3}=9$
## *Disequazioni*
$$ax > b \quad ax<b \quad con \ a \neq 0$$
Possiamo anche vedere $\leq$ e $\geq$.
$$ax>b \rightarrow x>\frac{b}{a} \quad ax<b \rightarrow x<\frac{b}{a} \quad con \ a > 0$$
## *Esempi di risoluzione*
* $5x+3>2(x-1)$
	* $5x+3>2x-2$
	* si sottrae 2x da ambo i lati --> $3x+3>-2$
	* si sottrae 3 da ambo i lati --> $3x > -5$
	* $x>\frac{b}{a}$ --> $x>\frac{-5}{3}$
	* scritto anche come $(\frac{-5}{3},+\infty)$
# *Equazioni algebriche di 2° grado con una incognita*
Un’equazione algebrica di 2° grado con una incognita è sempre riconducibile alla seguente forma, in cui compare un polinomio di grado 2:
$$ax^{2}+bx+c = 0 \quad \text{con }a\neq 0$$
Essendo di 2° grado l’equazione può avere al massimo 2 soluzioni, indicate con $x_{1}$ e $x_{2}$.
$$x_{1,2}=\frac{-b\pm\sqrt{b^{2}-4ac}}{2a}$$
Le due soluzioni che otteniamo sono:
$$x_{1}=\frac{-b-\sqrt{b^{2}-4ac}}{2a}$$
$$x_{2}=\frac{-b+\sqrt{b^{2}-4ac}}{2a}$$
L’espressione sotto il simbolo di radice prende il nome di discriminante e si indica con $\Delta$. In base al segno del $\Delta$ si distinguono 3 casi:
- $\Delta > 0$ --> le soluzioni $x_{1}$ e $x_{2}$ sono reali e distinte
- $\Delta = 0$ --> le soluzioni $x_{1}$ e $x_{2}$ sono reali e coincidenti $(x_{1}=x_{2})$
- $\Delta < 0$ --> non si hanno soluzioni reali (sono complesse)
## *Giustifichiamo le formula risolutiva*
Si utilizza il metodo del *completamento dei quadrati*:
- si parte dall'equazioni $ax^{2}+bx+c=0$
- si dividono ambo i membri per a $x^{2}+\frac{bx}{a}+\frac{c}{a} = 0$
- si sottrae il termine $\frac{c}{a}$ da ambo i membri $x^{2}+\frac{bx}{a}=-\frac{c}{a}$
- si considera il coefficiente di $x$, ossia $\frac{b}{a}$, lo si dimezza e si fa il quadrato $\frac{b^{2}}{4a^{2}}$
- si somma questo termine a entrambi i membri dell'equazione $x^{2}+\frac{bx}{a}+\frac{b^{2}}{4a^{2}}=\frac{b^{2}}{4a^{2}}-\frac{c}{a}$
- si riconosce lo sviluppo di un binomio a primo membro e si svolgono i conti a secondo membro $(x+\frac{b}{2a})^{2}=\frac{b^{2}-4ac}{4a^{2}}$
- si considera la radice quadrata di ambo i membri $x+\frac{b}{2a}=\pm\frac{\sqrt{b^{2}-4ac}}{2a}$
- si ottiene la formula $x=\frac{-b\pm\sqrt{b^{2}-4ac}}{2a}$
#Esempio 
$$6x(x+3)-(2x+1)^{2}-15x-2=0$$
Per prima cosa si svolgono i conti per ricondursi alla forma $ax^{2}+bc+c=0$:
$$6x^{2}+18x-4x^{2}-4x-1-15x-2=0$$
$$2x^{2}-x-3=0$$
Si applica la formula risolutiva:
$$x_{1,2}=\frac{1\pm\sqrt{(-1)^{2}+4\cdot2\cdot(-3)}}{2*2} = \frac{1\pm\sqrt{25}}{4}$$
$$x_{1}=\frac{1-5}{4}=-1$$
$$x_{2}=\frac{1+5}{4}=\frac{3}{2}$$
## *Disequazioni algebriche di 2° grado con una incognita*
Una disequazione algebrica di 2° grado con una incognita può essere scritta in una delle seguenti forme:
$$ax^{2}+bx+c>0 \quad \quad ax^{2}+bx+c<0$$
Siano $x_{2}$ e $x_{2}$ le soluzioni dell’equazione associata, con $x_{1}<x_{2}$. Le soluzioni della corrispondente disequazione di 2° grado sono riassunte nel seguente schema:
- $\Delta > 0$
	- $ax^{2}+bx+c>0$ --> soluzione: $x<x_{1}$ o $x>x_{2}$
	- $ax^{2}+bx+c\geq0$ --> soluzione: $x\leq x_{1}$ o $x\geq x_{2}$
	- $ax^{2}+bx+c<0$ --> soluzione: $x_{1} < x < x_{2}$
	- $ax^{2}+bx+c\leq0$ --> soluzione: $x_{1}\leq x \geq x_{2}$
- $\Delta = 0$
	- $ax^{2}+bx+c>0$ --> soluzione: $\forall x \in R$ tranne $x\neq\frac{-b}{2a}$
	- $ax^{2}+bx+c\geq0$ --> soluzione: $\forall x \in R$
	- $ax^{2}+bx+c<0$ --> soluzione: $\not\exists x \in R$
	- $ax^{2}+bx+c\leq0$ --> soluzione: $\frac{-b}{2a}$
- $\Delta < 0$
	- $ax^{2}+bx+c>0$ --> soluzione: $\forall x \in R$
	- $ax^{2}+bx+c\geq0$ --> soluzione: $\forall x \in R$
	- $ax^{2}+bx+c<0$ --> soluzione: $\not\exists x \in R$
	- $ax^{2}+bx+c\leq0$ --> soluzione: $\not\exists x \in R$
#Esempio 
$$3x^{2} + 7x + 2 < 0$$
Calcolo $\Delta$:
$$x_{1}=\frac{-7-5}{6}=-2$$
$$x_{2}=\frac{-7+5}{6}=\frac{-1}{3}$$
> [!NOTA]
> Si osserva $a>0 \quad \Delta > 0$ verso della disequazione $<$
> Quindi la soluzione è rappresentata dall’intervallo interno: $-2 < x < \frac{-1}{3}$ oppure in altra forma $(-2;\frac{-1}{3})$
## *Sistemi di equazioni*
I **sistemi di equazioni** si introducono allo scopo di trovare le soluzioni comuni a più equazioni.
$$\begin{cases} x^{2}+3xy+5=0 \\ x+y=0 \end{cases}$$
## *Metodo di Gauss*
#Esempio 
$$\begin{cases} 18x-y=14 \\ 3x-3y=8 \end{cases}$$
Nell’esempio proposto possiamo risolvere la prima equazione rispetto ad $y$ e ricavare quindi $y$ in funzione di $x$:
$$\begin{cases} y=18x-14 \\ 3x-3y=8 \end{cases}$$
Sostituendo l'espressione trovata:
$$\begin{cases} y=18x-14 \\ 3x-3(18x-14)=8 \end{cases}$$
Ricaviamo $x$:
$$\begin{cases} y=18x-14 \\ x = \frac{2}{3} \end{cases}$$
Ricaviamo $y$ sostituendo $x$:
$$\begin{cases} y=-2 \\ x = \frac{2}{3} \end{cases}$$
Soluzione:
$$(\frac{2}{3};-2)$$
# *Equazioni e disequazioni algebriche fratte, irrazionali, con valore assoluto*
## *Equazioni e disequazioni fratte*
## *Equazioni*
Una equazione si dice fratta quando l’incognita $x$ compare a denominatore di qualche frazione.
Per questo motivo è necessario scartare dalle soluzioni i valori che annullerebbero anche solo uno dei denominatori.
Per risolvere un’equazione fratta si deve:
- Determinare il *campo di esistenza*
- Ridurre a forma intera
- Verificare che le soluzioni siano accettabili
#Esempio 
$$\frac{x}{x-2}+\frac{2}{x+1}=1$$
Determinare il *campo di esistenza*
$$x\neq 2 \quad \text{e} \quad x\neq-1$$
Ridurre a forma intera
Denominatore comune:
$$\frac{x^{2}+x+2x-4-x^{2}-x+2x+2}{(x-2)(x+1)}=0$$
$$\frac{4x-2}{(x-2)(x+1)}$$
Per eliminare il denominatore si possono moltiplicare ambo i membri per il denominatore comune, che abbiamo posto diverso da zero nelle condizioni di esistenza.  
Oppure si può vedere in altro modo: affinché la frazione sia nulla occorre che sia nullo il suo numeratore. Quindi si pone il numeratore uguale a zero:
$$4x-2=0$$
Risolvere l'equazione in forma intera
$$4x-2=0$$
$$x=\frac{2}{4}=\frac{1}{2}$$
Verificare che la soluzione sia accettabile
$$\frac{1}{2}\quad \text{è diverso da }2 \text{ e da }-1\text{ quindi la soluzione è accettabile}$$
## *Disequazioni*
Le disequazioni fratte si possono ricondurre tramite opportune semplificazione ad una delle seguenti forme:
$$\frac{N(x)}{D(x)}<0 \quad \frac{N(x)}{D(x)}>0$$
- Determinare il campo di esistenza.
- Ricondursi ad una delle forme sopra riportate.
- *Studiare il segno* di numeratore e denominatore, ponendo $N(x)>0 \ (o \ N(x)\geq 0 )$ a seconda della disequazione data, e $D(x)>0$ *(il denominatore deve essere diverso da zero quindi sempre strettamente maggiore di zero)*.
- Impostare un opportuno schema con i risultati trovati e applicare la regola dei segni allo schema per vedere dove la disequazione è positiva o negativa (segno concorde -> risultato positivo; segno discorde -> risultato negativo).
- Considerare il verso della disequazione e selezionare gli intervalli (positivi o negativi) che sono soluzioni, stando attenti a confrontarli con il campo di esistenza.
#Esempio 
$$1+\frac{2x^{2}-x+1}{4-x^{2}}\geq0$$
Determinare il campo di esistenza
$$x\neq\pm2$$
Ricondursi alla forma generale
$$\frac{x^{2}-x+5}{4-x^{2}}\geq0$$
Studiare il segno
Nominatore
$$x^{2}-x+5\geq0$$
$$\Delta = 1-4\cdot1\cdot5=-19$$
$$Sol: \forall x \in \mathbb{R}$$
Denominatore
$$4-x^{2}>0$$
$$x^{2}-4<0$$
$$x^{2}-4=0$$
$$x=\pm 2$$
$$Sol: -2<x<+2$$
Schema dei risultati
![[Pasted image 20231020163219.png|350]]
Selezionare gli intervalli
Il verso della disequazione è $\geq$ quindi si seleziona l’intervallo positivo.
Sol: $-2<x<+2$
## *Equazioni e disequazioni irrazionali*
## *Equazioni*
Una equazione si dice irrazionale quando l’incognita $x$ compare sotto il simbolo di radice.
Per risolvere equazioni di questo tipo si devono eliminare i radicali, elevando entrambi i membri a un'opportuna potenza $n$. Questo passaggio non è banale in quanto si possono introdurre soluzioni estranee all’equazione nel caso di $n$ pari, per cui è necessario imporre ulteriori condizioni come sarà precisato in seguito.
$$\sqrt[n]{f(x)}=g(x)$$
$$\text{Dove }f(x) \text{ e }g(x)\text{ sono polinomi in cui compare l'incognita }x \ .$$
Si possono presentare 2 casi:
1. $n$ dispari
2. $n$ pari

1. $n$ dispari:
Nel caso di $n$ dispari è sufficiente elevare a $n$ entrambi i membri dell’equazione, applicando la seguente proprietà e senza introdurre soluzioni estranee:
$$a=b\leftrightarrow a^{n}=b^{n}\quad\forall a,b\in \mathbb{R}$$
1. $n$ pari:
La situazione è più delicata
$$a=b\leftrightarrow a^{n}=b^{n}\text{ non vale }\forall a,b \in \mathbb{R}, \text{ ma solo per }a,b \text{ concordi.}$$
Di conseguenza oltre ad elevare a $n$ entrambi i membri, nel caso di $n$ pari si devono porre anche le seguenti condizioni per scartare eventualmente le soluzioni estranee:
- il radicando $f(x) \geq 0$ perché la radice di indice pari abbia significato
- $g(x)\geq0$, poiché una radice di indice pari è sicuramente maggiore o uguale a zero.
Le due condizioni devono essere contemporaneamente verificate, insieme con l’equazione.
In questi casi si imposta un sistema di equazioni e disequazioni.
$$\begin{cases} f(x)=g(x)^{n} \\ f(x)\geq0\\ g(x)\geq0 \end{cases}$$
In realtà possiamo risparmiare qualche conto notando che dalla prima riga del sistema, con $n$ pari, segue anche $f(x)\geq 0$.
In conclusione il sistema da impostare è il seguente:
$$\begin{cases} f(x)=g(x)^{n} \\ g(x)\geq0 \end{cases}$$
## *Disequazioni*
$$\sqrt[n]{f(x)}<g(x) \quad \sqrt[n]{f(x)}>g(x)$$
Si possono presentare 2 casi:
1. $n$ dispari
2. $n$ pari

1. $n$ dispari: Per $n$ dispari la soluzione della disequazione si trova semplicemente elevando ad $n$ entrambi i membri.
2. $n$ pari: si distinguono due diversi casi:
	1. quando $\sqrt[n]{f(x)}<g(x)$:
		1. $\begin{cases} f(x)>0 \\ g(x)>0 \\ f(x<[g(x)]^{n}\end{cases}$
	2. quando $\sqrt[n]{f(x)}>g(x)$:
		1. $\begin{cases} g(x)<0 \\ f(x)\geq0 \end{cases} \quad \lor \quad \begin{cases} g(x)\geq0 \\ f(x)>[g(x)]^{n} \end{cases}$
# *Geometria analitica*
## *Il piano cartesiano*
Il passaggio dalla geometria piana alla geometria analitica richiede l’introduzione di un riferimento cartesiano, costituito da due rette ortogonali e orientate. Il punto di incontro è l’origine, la retta orizzontale è l’asse delle ascisse o asse $x$, la retta verticale è l’asse delle ordinate o asse $y$. Si introduce l’orientamento verso destra sull’asse $x$ e verso l’alto sull’asse $y$, si rappresentano i numeri reali su entrambe le rette e si pone il numero 0 nel punto di intersezione delle rette.

Ogni punto $P$ ha coordinate $P=(x,y)$, dove $x$ è l’ascissa di $P$ e $y$ è l’ordinata di $P$.

Il piano viene così diviso in quattro quadranti, che, per convenzione, sono numerati in senso antiorario, a partire dal semiasse positivo delle $x$.
![[Pasted image 20231021144012.png|350]]
## *Distanza tra due punti*
Dati due punti $A=(x_{A},y_{A})$ e $B=(x_{B},y_{B})$ la loro distanza è:
$$d(A,B)=\sqrt{(x_{B}-x_{A})^{2}+(y_{B}-y_{A})^{2}}$$
## *Punto medio di un segmento*ù
Dati due punti $A=(x_{A},y_{A})$ e $B=(x_{B},y_{B})$ le coordinate del punto medio del segmento $AB$ è:
$$M=(\frac{x_{B}+x_{A}}{2};\frac{y_{B}+y_{A}}{2})$$
## *La retta nel piano cartesiano*
Ogni retta parallela all’asse $x$ ha equazione:
$$y=k \quad k\in\mathbb{R}$$
Ogni retta parallela all’asse $y$ ha equazione:
$$x=h \quad h\in\mathbb{R}$$
Una generica retta passante per l’origine degli assi ha equazione:
$$y=mx \quad m\in\mathbb{R}$$
$$m\text{ prende il nome di coefficiente angolare della retta.}$$
Presi due punti $A=(x_{A},y_{A})$ e $B=(x_{B},y_{B})=\tan(a)$ dove $a$ è l'angolo che la retta forma con l'asse $x$.
![[Pasted image 20231021145421.png|350]]
## *Retta in posizione generica scritta in forma esplicita*
$$y=mx+q \quad m,q\in\mathbb{R}$$
O anche:
$$ax+by+c=0 \quad a,b,c\neq0 \quad (a,b)\neq(0,0)$$
A seconda dei valori assunti dai coefficienti $a,b,c$ si ottengono tutti i casi di rette particolari presentate in precedenza.
*Coefficente angolare*:
$$m=\frac{-a}{b} \quad con \ b\neq0$$
## *Retta passante per uno o per due punti*
L’equazione di una generica retta passante per un punto $P=(x_{P},y_{P})$ e di coefficiente angolare $m$ è la seguente:
$$y-y_{P}=m(x-x_{P})$$
L'equazione generica di una retta passante per due punti $A=(x_{A},y_{A})$ e $B=(x_{B},y_{B})$ si ricava imponendo il passaggio sia per il punto $A$ che per il punto $B$:
$$\frac{x-x_{a}}{x_{b}-x_{a}}=\frac{y-y_{A}}{y_{B}-y_{A}}$$
## *Condizione di parallelismo e perpendicolarità tra rette*
Date due rette:
$$r:y=mx+q \quad \quad r':y=m'x+q'$$
O in forma esplicita:
$$r:ax+by+c=0 \quad \quad r':a'x+b'y+c'=0$$
Due rette sono *parallele* se e solo se i loro coefficienti coincidono:
$$m=m'$$
Due rette sono *perpendicolari* se e solo se il prodotto dei loro coefficienti è $-1$:
$$m\cdot m'=-1$$
si può scrivere anche:
$$aa'+bb'=0$$
## *Distanza di un punto da una retta*
Data una retta $r:ax+by+c=0$ e un punto $P_{0}=(x_{0},y_{0})$, la distanza di $P_{0}$ dalla retta $r$ è data da:
$$d(P_{0},r)=\frac{|ax_{0}+by_{0}+c|}{\sqrt{a^{2}+b^{2}}}$$
La formula si ottiene calcolando la distanza tra $P_{0}$ e $H,$ piede della perpendicolare condotta da $P_{0}$ a $r$.
![[Pasted image 20231021155043.png|350]]
## *Fasci di rette*
Si definiscono tre tipi
1. il fascio improprio di rette formato da tutte le rette parallele ad una retta assegnata;
	1. $y=mx+q$ con $m$ fissato e $q$ che assume ogni valore reale![[Pasted image 20231021155643.png|350]]
2. siano: $r:ax+by+c=0$ e $r':a'x+b'y+c'=0$ due rette incidenti nel punto $P_{0}(x_{0},y_{0})$. Il fascio proprio di rette per $P_{0}$ è dato da:
	1. $\lambda(ax+by+c)+\mu(a'x+b'y+c')=0$ per ogni valore reale di $\lambda$ e $\mu$
3. il fascio proprio di rette formato da tutte le rette passanti per un punto, detto centro del fascio.
#Esempio 
Retta passante per il punto $A=(\frac{3}{4},-2)$ e parallela all'asse $y$
$$x=\frac{3}{4}$$
#Esempio 
Retta passante per il punto $B=(\frac{2}{5},\frac{4}{3})$ e parallela all'asse $x$
$$y=\frac{4}{3}$$
#Esempio 
Retta passante per il punto $C=(2,-3)$ e perpendicolare alla retta di equazione $y=2x-1$

L'equazione di una generica retta passante per un punto $P_{0}=(x_{P},y_{P})$ e di coefficiente angolare $m$ è:
$$y-y_{P}=m(x-x_{P})$$
Nel nostro caso il punto è $C=(2,-3)$ quindi:
$$y+3=m(x-2)$$
Il coefficiente angolare $m$ si ottiene imponendo la condizione di perpendicolarità rispetto alla retta $y=2x-1$:
$$mm'=-1$$
$$2m=-1$$
$$m=-\frac{1}{2}$$
In conclusione:
$$y+3=-\frac{1}{2}(x-2)$$
$$y=-\frac{1}{2}x-2$$
# *Le coniche*
## *La circonferenza*
[YouMath - Circonferenza](https://www.youmath.it/formulari/formulari-di-geometria-analitica/440-circonferenza-e-cerchio-nel-piano-cartesiano.html)
Fissati un punto $C$ e una costante positiva $r$, la circonferenza del piano, di centro $C$ e raggio $r$, è l'insieme di tutti e soli i punti $P$ del piano tali che:
$$d(P,C)=r$$
Se $r=0$ la circonferenza si riduce ad un punto che coincide con il centro
![[Pasted image 20231021161511.png|250]]
Ricordando come si calcola la distanza tra due punti e considerando come punti $P=(x,y)$ appartiene alla circonferenza $C=(\alpha,\beta)$ centro della circonferenza si ha:
$$(x-\alpha)^{2}+(y-\beta)^{2}=r^{2}$$
Tale equazione può essere anche scritta come:
$$x^{2}+y^{2}+2ax+2\beta y+\gamma=0 \quad \quad \text{con } \gamma=a^{2}+b^{2}-r^{2}$$
che rappresenta l’equazione della circonferenza di centro $C=(a,\beta)$ e raggio $r$.

## *Posizione reciproca tra una retta e una circonferenza*
La posizione reciproca tra una retta $a$  e una circonferenza di centro $C$e raggio $r$ si determina calcolando la distanza dal centro della circonferenza alla retta e confrontandola con il raggio della circonferenza stessa.
Tre possibilità:
1. $d(C,a)>r$
	1. Retta esterna
	2. ![[Pasted image 20231021163231.png]]
2. $d(C,a)=r$
	1. Retta tangente
	2. ![[Pasted image 20231021163309.png]]
3. $d(C,a)<r$
	1. Retta incontra la circonferenza in 2 punti
	2. ![[Pasted image 20231021163335.png]]

## *La parabola*
La parabola è il luogo dei punti $P$ equidistanti da una retta $f$ fissata e da un punto $F$ fissato:
$$d(P,F)=d(P,f)$$
La retta $f$ prende il nome di direttrice e il punto $F$ è il fuoco della parabola.
![[Pasted image 20231021164432.png|250]]
Per ricavare l’equazione della parabola si sceglie un riferimento cartesiano opportuno. Si può procedere in due modi:
1. i sceglie il riferimento in modo tale che il fuoco abbia coordinate $F=(0,c)$ e la direttrice abbia equazione $y=-c$. L’origine quindi è un punto appartenente al luogo richiesto e rappresenta il vertice della parabola. Imponendo che:
	1. $d(P,F)=d(P,f)$
	2. si ha $\sqrt{x^{2}+(y-c)^{2}}= |y+c|$
	3. Elevando al quadrato si ha: $y=ax^{2}$ dove $a=\frac{1}{4c}$
	4. ![[Pasted image 20231021170229.png|250]]
2. Si sceglie il fuoco di coordinate $F=(c,0)$ e la direttrice di equazione $x=-c$:
	1. $x=ay^{2}$ che è un’altra equazione in forma canonica della parabola
	2. Analogamente usando valori negativi per il numero $c$ si ottengono le equazioni:
		1. $y=-ax^{2}$
		2. $x=-ay^{2}$
	3. ![[Pasted image 20231021170300.png|250]]

La parabola presentata con il vertice nell'origine degli assi e *simmetrica* rispetto all'asse $x$ (oppure $y$) è la più semplice e la si può considerare come punto di partenza per introdurre l’equazione generale di una parabola:
$$y=ax^{2}+bx+c$$
dove $a,b,c$ sono parametri reali
- $a$ agisce sulla concavità
- $b$ e $c$ hanno l'effetto di muovere la parabola rispetto all'origine

Consideriamo la generica parabola $y=ax^{2}+bx+c$:
- il vertice ha coordinate $V=(\frac{-b}{2a},\frac{-\Delta}{4a})$, dove $\Delta =b^{2}-4ac$
- il fuoco ha coordinate $F=(\frac{-b}{2a},\frac{1-\Delta}{4a})$
- l'asse di simmetria è la retta $x=(\frac{-b}{2a})$
- la direttrice ha equazione $y=\frac{-1-\Delta}{4a}$
#Esempio 
Determinare il vertice, il fuoco e la direttrice delle parabole:
$$P_{1}:3x-2y^{2}=0$$
$$P_{2}:2x^{2}+9y=0$$
![[Pasted image 20231021173000.png|250]]
$P_{1}$

![[Pasted image 20231021173015.png|250]]
$P_{2}$

Le due parabole date si possono riscrivere nella forma $x=ay^{2}$ oppure $y=ax^{2}$:
$$P_{1}:x=\frac{2}{3}y^{2}$$
$$P_{2}:y=-\frac{2}{9}x^{2}$$
Entrambe le parabole hanno vertice nell’origine.
# *Funzioni*
Una funzione $f$ da $A$ in $B$ è una legge che associa ad ogni elemento di $x$ di $A\subseteq \mathbb{R}$ uno e un solo elemento di $B\subseteq \mathbb{R}$.
$$f:A\rightarrow B$$
$$x \rightarrow f(x)$$
Comunemente $f(x)$ viene anche indicato con $y$.
#Esempio 
1. $f: \mathbb{R} \rightarrow \mathbb{R}, y=f(x)=2x+3$. Una retta è un esempio di funzione lineare.
2. $f: \mathbb{R} \rightarrow \mathbb{R}, y=f(x)=x^{2}+x-5$. Una parabola è un esempio di funzione polinomiale di 2° grado.
3. $f: \mathbb{N} \rightarrow \mathbb{N}, y=f(x)=x+1$. Questa funzione è definita nell'insieme dei numeri naturali e associa ad ogni numero naturale il suo successivo.
### *Nomenclatura*
L'insieme di partenza indicato con $A$ viene detto *dominio* della funzione, mentre l'insieme di arrivo indicato con $B$ viene detto *codominio*.
Il _dominio_ o _campo di esistenza_ di una funzione è l’insieme dei valori reali per i quali una funzione è definita: per esempio se nella funzione ci sono espressioni fratte è necessario escludere dall'insieme dei numeri reali i valori per cui non sono definite, ossia i valori che annullano i denominatori; oppure nel caso in cui la funzione presenti radici con indice pari è necessario porre la condizione che l’espressione sotto il simbolo di radice sia non negativa.
Con il termine *immagine* intendiamo l'insieme dei valori assunti dalla funzione al variare di $x$ nel dominio; l'immagine non sempre coincide con il codominio ma può essere anche un suo sottoinsieme. Si può pure parlare di immagine di un singolo elemento: in tale accezione, quella di un elemento fissato in $x$ in $A$ è semplicemente l'elemento $f(x)$ in $B$. Si parla di immagine di $x$ in $A$, ma anche, al contrario, di *controimmagine* di $y$ in $B$. La controimmagine di un elemento fissato $y$ in $B$ è l'insieme degli elementi di $x$ in $A$ tali per cui $f(x)=y$; non è detto che essa sia costituita da un solo elemento, ma può constare di più elementi, così come essere invece l'insieme vuoto.
$x$ e $y$ sono due variabili: in particolare la $x$ si dice *variabile indipendente* mentre la $y$ *variabile dipendente* in quanto il suo valore dipende dalla legge di associazione.
## *Grafico di una funzione*
Secondo la definizione data, una funzione $f$ opera ricevendo un valore $x$e fornendo un unico valore $y=f(x)$. La funzione stessa è quindi identificata da tutte le coppie $(x,f(x))$ con $x$ appartenente al dominio: questo insieme prende il nome di *grafico* della funzione $f(x)$.

> [!NOTA BENE]
> Attenzione: non tutti i grafici rappresentati nel piano cartesiano sono grafici di funzioni; alcuni rappresentano il grafico di una curva che però non è una funzione, come nell'esempio sotto riportato. La condizione per essere il grafico di una funzione è che nessuna retta parallela all'asse delle $y$ intersechi il grafico in più di un punto. Infatti se ciò accadesse significherebbe che ad un valore di $x$ corrispondono due valori di $y$, contro la definizione di funzione.

Ad esempio la Figura $A$ rappresenta il grafico di una funzione, mentre la Figura $B$ rappresenta il grafico di una curva, che non è una funzione.
![[Pasted image 20231024171050.png|250]] ![[Pasted image 20231024171054.png|250]]
Figura $A$                  Figura $B$

## *Funzioni iniettive, suriettive, biiettive o biunivoche*
***Funzioni iniettive***:
Una funzione è *iniettiva* quando ad elementi distinti del dominio corrispondono elementi distinti dell'immagine. In altri termini si tratta di una funzione che non assume mai due volte lo stesso valore.
Si dice iniettiva una funzione $f$ tale che ogni $x_{1}, x_{2}$ appartenenti al dominio si ha:
$$x_{1}\neq x_{2}\rightarrow f(x_{1})\neq f(x_{2})$$
$$\text{o in modo analogo } f(x_{1})=f(x_{2})\rightarrow x_{1}=x_{2}$$
#Esempio di funzione iniettiva:
![[Pasted image 20231024172050.png|250]]
La parabola, invece, è un esempio di funzione non iniettiva.
![[Pasted image 20231024172117.png|250]]
***Funzioni suriettive***:
Una funzione è suriettiva se ogni elemento del codominio è immagine di qualche elemento del dominio. In altri termini si tratta di una funzione che copre tutto lo spazio di arrivo, ossia $f(A)=B$ dove $A$ e $B$indicano rispettivamente dominio e codominio.
Una funzione $f$ si dice suriettiva se per ogni $y$ appartenente al codominio esiste un $x$ appartenente al dominio tale che $f(x)=y$
#Esempio di funzione suriettiva:
![[Pasted image 20231024172823.png|250]]
La funzione rappresentata dal seguente grafico, invece, non è suriettiva se come codominio si considera l'insieme dei numeri reali.
![[Pasted image 20231024172915.png|250]]
***Funzioni biiettive o biunivoche***
Una funzione è biiettiva o biunivoca quando è contemporaneamente iniettiva e suriettiva. Nel caso di funzione biunivoca vi è una corrispondenza uno a uno tra elementi del dominio e del codominio.
A livello grafico una funzione biunivoca interseca sempre una qualsiasi retta parallela all’asse delle $x$ in uno ed un solo punto.
#Esempio 
La funzione reale $f$ di variabile reale deinita come $y=f(x)=x^{3}$ è un esempio di funzione sia iniettiva che suriettiva e quindi biunivoca.
Dal suo grafico si osserva che una qualsiasi retta parallela all’asse delle $x$ interseca la funzione in uno ed un solo punto.
![[Pasted image 20231024173221.png|250]]
La funzione rappresentata dal seguente grafico, invece, non è biunivoca in quanto è suriettiva ma non iniettiva.
![[Pasted image 20231024173327.png|250]]
## *Restrizione di una funzione*
Si è detto che una funzione è definita da un insieme $A$, detto dominio, ad un insieme $B$, detto codominio. A volte però può essere utile o addirittura necessario considerare una funzione solo in una parte del suo dominio. In questi casi si parla di restrizione di una funzione.
La restrizione di una funzione $f$ all'insieme $D$, dove $D\subseteq A$ è definita nel seguente modo:
$$f|_{D}D \rightarrow B, \ con \ f|_{D}(x)=f(x)\forall x\in D$$
![[Pasted image 20231024173841.png|250]]
## *Funzione inversa*
Ricordiamo che una funzione associa ad un elemento $x$ di un insieme al più un elemento $y=f(x)$ di un altro insieme.
È possibile invertire il processo, cioè tornare a ritroso da $y$ e $x$?
Dipende dalle caratteristiche della funzione. Per poter invertire il processo e avere una funzione detta inversa è necessario che la funzione di partenza sia iniettiva e suriettiva, ossia biiettiva. Solo in questi casi esiste la funzione inversa, definita come segue:
si definisce inversa di una funzione $f:A\rightarrow B,y=f(x)$, esiste la funzione che associa ad ogni elemento $y=f(x)$ di $B$ la relativa controimmagine $x$ appartenente ad $A$. Essa si rappresenta come:
$$f^{-1}:B\rightarrow A,x=f^{-1}(y)$$
A livello grafico una funzione e la sua inversa sono simmetriche rispetto alla bisettrice del I e III quadrante.
![[Pasted image 20231024174351.png|250]]
#Esempio 
Si consideri la funzione $y=f(x)=2x+2$ definita da $\mathbb{R}$ in $\mathbb{R}$.
Essa è biiettiva quindi risulta invertibile.
La funzione inversa si trova scrivendo il valore di $x$ in funzione di quello di $y:f^{-1}(y)=\frac{y-2}{3}$ definita da $\mathbb{R}$ in $\mathbb{R}$.
Dopo aver effettuato l’inversione ci si riconduce alla notazione standard indicando con $x$ la variabile indipendente: in conclusione la funzione inversa è $f^{-1}(x)=y=\frac{x-2}{3}$
## *Composizioni di funzioni*
La composizione di due funzioni $f$ e $g$ si indica con $g \circ f$ è il risultato dell'applicazione:
1. della funzione $f$ dall'insieme $A$ all'insieme $B$
2. della funzione $g$ dall'insieme $B$ all'insieme $C$
![[Pasted image 20231024174926.png|350]]
Per poter effettuare $g\circ f$ occorre che sia verificata una condizione sui rispettivi insiemi immagine e dominio: l’immagine di $f$ deve essere contenuta nel dominio di $g$. Se questa condizione non è verificata occorre effettuare una restrizione per poter effettuare la composizione.
Date due funzioni $f:A\rightarrow B \ e \ g:B\rightarrow C$ si può effettuare la loro composizione ottenendo una nuova funzione $h$ definita nel seguente modo:
$$h=g\circ f:A\rightarrow C,z=h(x)=g(f(x))$$
Scambiando l'ordine di applicazione di $f$ e $g$ cambia l'effetto della composizione: in generale $g \circ f \neq f \circ g$.
#Esempio 
$$f(x)=x+5$$
$$g(x)=x^{2}$$
Determiniamo le composizioni:
$$g \circ f= g(f(x))=(x+5)^{2}$$
$$f\circ g=f(g(x))=x^{2}+5$$
## *Funzioni pari o dispari*
Una funzione è *pari se* $f(x)=f(-x)$ per ogni valore di $x$ appartenente al dominio.
Il grafico di una funzione pari è simmetrico rispetto all'asse delle ordinate.
Una funzione è *dispari se* $f(x)=-f(-x)$ per ogni valore di $x$ appartenente al dominio.
Il grafico di una funzione dispari è simmetrico rispetto all'origine degli assi cartesiani.
#Esempio 
$$f(x)=6x^{6}+4x^{4}+2x^{2}+1$$
$$g(x)=x^{5}-x^{3}-x$$
Osserviamo che $f$ è pari infatti:
$$f(-x)=6(-x)^{6}+4(-x)^{4}+2(-x)^{2}+1=6x^{6}+4x^{4}+2x^{2}+1=f(x)$$
![[Pasted image 20231024180952.png|250]]
Osserviamo che $g$ è dispari infatti:
$$f(-x)=(-x)^{5}-(-x)^{3}-(-x)=-x^{5}+x^{3}+x=-f(x)$$
![[Pasted image 20231024181120.png|250]]

> [!Attenzione]
> Tuttavia non tutte le funzioni rientrano nell’insieme delle funzioni pari o nell’insieme delle funzioni dispari: molte funzioni infatti non sono né pari né dispari. Citiamo ad esempio la funzione $f(x)=x^{3}-2x^{2}+3$, il cui grafico non presenta simmetrie.
> 
![[Pasted image 20231024181313.png|250]]
## *Funzioni periodiche*
Una funzione $f$ è *periodica* di periodo $T$ se $f(x+T)=f(x)$ per ogni valore di $x$ appartenente al dominio.
$T$ deve essere il più piccolo numero per cui vale la relazione.
La caratteristica di periodicità di una funzione permette di limitarne lo studio ad un intervallo di ampiezza $T$ e non all'intero dominio, sapendo che l’andamento della funzione si ripete.
Vedremo le [[OFA_2#Funzioni trigonometriche|funzioni trigonometriche]].
![[Pasted image 20231024182436.png|350]]
## *Funzioni crescenti, decrescenti, monotone*
Una funzione è *crescente* su $I$ se per ogni $x_{1},x_{2}$ appartenente ad $I, x_{1}<x_{2}\rightarrow f(x_{1})<f(x_{2})$
Una funzione è *decrescente* su $I$ se per ogni $x_{1},x_{2}$ appartenente ad $I, x_{1}<x_{2}\rightarrow f(x_{1})> f(x_{2})$

Se si considera la relazione d'ordine largo (ossia $\leq$ e $\geq$ al posto di < e >) invece si possono dare le definizioni seguenti:
Una funzione è *non crescente* su $I$ se per ogni $x_{1},x_{2}$ appartenente ad $I, x_{1}<x_{2}\rightarrow f(x_{1})<f(x_{2})$












