[Appunti](http://www.integr-abile.unito.it/Libri/Logica/1.1%20-%20Teoremi%20e%20Dimostrazioni.html#dimostrazione-diretta)
## Introduzione
Le conoscenze alle quali pervengono le scienze esatte si esprimono generalmente in forma di *proposizioni*, frasi dichiarative con il verbo all'indicativo:
- l'equazione $x^{2}=2$ non ha soluzioni razionali.
Analogamente, in informatica possiamo esprimere la correttezza di un algoritmo $a$ di ordinamento di vettori mediante la proposizione:
- Per ogni vettore $v$, l'algoritmo $a$ produce una permutazione degli elementi di $v$ ordinata in ordine crescente.
La logica analizza queste proposizioni scomponendole in elementi che appartengono ad un numero ristretto di categorie grammaticali, mettendone in evidenza la struttura mediante una traduzione in *formule* di un opportuno linguaggio formale.
## Tecniche di dimostrazione
#Esempio [Dimostrazione diretta]
In questo esempio dimostriamo un enunciato della forma:
$$A\to B$$
Una strategia generica che si può applicare in questo caso consiste nel dimostrare $B$ avendo assunto $A$. Da un punto di vista operativo, cioè relativo all'utilizzo di un'assunzione nell'ambito di una dimostrazione, assumere $A$ significa poter usare $A$ nella dimostrazione di $B$. Da un punto di vista semantico, assumere $A$ significa supporre che $A$ sia vera. Questo tipo di dimostrazione di $A\to B$ viene chiamata anche *Dimostrazione diretta*. Graficamente, una dimostrazione diretta può essere rappresentata così:
$$
\begin{aligned}
& \begin{array}{l}
A \text { (assunzione) } \\
\vdots \\
B
\end{array} \\
& A \rightarrow B \text { (conclusione) } \\
&
\end{aligned}
$$
In questa rappresentazione, $A \dots B$ delimitano il campo di azione di una assunzione. In questo caso, l'assunzione $A$ si estende per tutte le right della derivazione tranne l'ultima, in cui l'assunzione viene *scaricata*: mentre l'enunciato $B$ dipende ancora da $A$, l'enunciato $A \to B$ non ne dipende più, quindi si trova all'esterno.
Si ricordi che un numero intero $n$ è pari se $b=2k$ per qualche intero $k$. Analogamente, $n$ è dispari se $n=2l+1$ per qualche $l$. Vediamo una dimostrazione diretta dell'enunciato seguente:
	Per tutti i numeri interi $n$ ed $m$, se $n$ è dispari e $m$ è pari, allora $n+m$ è dispari.
Per la dimostrazione: siano $n$ ed $m$ interi qualsiasi, ed assumiamo
	$n$ è dispari e $m$ è pari
Bisogna dimostrare che $n+m$ è dispari. Per definizione $n=2l+1$ per qualche intero $l$, mentre $m=2k$ per qualche intero $k$. Perciò:
$$
\begin{align}
n+m=&(2l+1)+2k \\
=&(2l+2k)+1 \\
=&2(l+k)+1
\end{align}
$$
che dimostra che $n+m$ è dispari perché ha la forma $2j+1$ $(j=l+k)$
#Esercizio 1
Si dia una dimostrazione diretta del fatto che, se $n$ è pari, allora $n^{2}$ è divisibile per $4$.
#Esercizio 2
Dimostrare i seguenti utilizzando la tecnica appropriata:
1. Per tutti i numeri interi $n,m$, se $n$ ed $m$ sono pari allora $n+m$ è pari.
2. Per tutti i numeri interi $n,m$ se $n$ ed $m$ sono dispari allora $n+m$ è pari.
3. Per tutti i numeri interi $n,m$ se $n$ ed $m$ sono pari allora $nm$ è pari.
4. Per tutti i numeri interi $n,m$ se $n$ ed $m$ sono dispari allora $nm$ è dispari.
5. Per tutti i numeri interi $n,m$ se $n$ è pari ed $m$ è dispari, allora $nm$ è pari.
#Esercizio 3
Siano $a$ e $b$ due numeri reali. Si definisce il *minimo* $min(a,b)$ tra $a$ e $b$ nel modo seguente:
$$min(a,b)=
\begin{cases}
a &\mbox{se }a< b \\
b &\mbox{se }a>b \\
a &\mbox{se }a=b
\end{cases}$$
Si dia una dimostrazione diretta dell'enunciato:
$$\text{Se }x\leq min(a,b),\text{ allora }x\leq a \text{ e }x\leq b$$
#Esempio [Dimostrazione per assurdo]
Una *dimostrazione per assurdo* è una dimostrazione di un enunciato della forma (1) che assume che $A$ sia vera e che $B$ sia falsa, e da queste assunzioni deriva una *contraddizione*, una proposizione della forma $C\land \neg C$ (dove $C$ è una proposizione qualsiasi.) Una dimostrazione di questo tipo di (1) viene anche chiamata una *dimostrazione indiretta*.
Vediamo una dimostrazione per assurdo dell'enunciato:
$$\text{Per tutti i numeri reali }x,y, \text{ se }x+y\geq 2\text{ allora }x\geq 1\text{ oppure }y\geq 1$$
Si osservi che assumere che $x\geq 1$ oppure $y\geq 1$ sia falsa è equivalente ad assumere che $x<1$ e $y<1$. Siano $x$ e $y$ numeri reali qualsiasi, e supponiamo che:
$$
\begin{align}
x+y&\geq 2 \\
x&<1 \\
y&<1
\end{align}
$$
Allora $x+1<1+1=2$, quindi $x+1<2$, ma questo contraddice la nostra prima assunzione, e questo dimostra (per assurdo) che se $x+1\geq 2$ allora $x\geq 1$ oppure $y\geq 1$.
## Dimostrazione diretta
La *dimostrazione diretta* è la strategia più semplice e naturale per stabilire un teorema del tipo
$$P_{1},\dots,P_{n}\vDash Q$$
La dimostrazione diretta assume di trovarsi in un qualunque contesto in cui siano verificate le ipotesi $P_{1},\dots,P_{n}$ e sulla base di semplici e rigorosi ragionamenti stabilisce che in tale contesto anche la tesi $Q$è verificata.
#Esempio 
Se $n$ è un *numero intero dispari* e $m$ un *numero intero pari*, allora $n+m$è un *numero intero dispari*.

Siano $n$ ed $m$ interi qualsiasi, e assumiamo che $n$ sia *dispari* ed $m$ *pari*, ovvero che $n=2l+1$ per qualche intero $l$, mentre $m=2k$ per qualche intero $k$.
Bisogna dimostrare che $n+m$ è dispari. Effettuando i calcoli si ha:
$$
\begin{align}
n+m\quad &= (2l+1)+2k \\
&=(2l+2k)+1 \\
&=2(l+k)+1
\end{align}
$$
Questo dimostra che $n+m$ *è dispari* perché ha forma $2j+1$.
## Dimostrazione per assurdo
Una *dimostrazione per assurdo* di una proposizione $Q$ a partire dalle ipotesi $P_{1},\dots,P_{n}$ è una dimostrazione in cui si assume $Q$ sia falsa e da questa assunzione si deriva una *contraddizione*, ovvero una proposizione della forma:
$$R \text{ e } \neg R$$
che asserisce che una qualche affermazione $R$ è al contempo sia vera che falsa.
Poiché una contraddizione è necessariamente falsa questo prova che assumere che $Q$ sia falsa porta a conclusioni assurde, e quindi $Q$ non può essere vera. In altre parole: si dimostra che se le premesse $P_{1},\dots,P_{n}$ sono vere non è possibile che $Q$ sia falsa.
Concretamente, in una dimostrazione per assurdo di un teorema del tipo:
$$P_{1},\dots,P_{n}\vDash Q$$
si assume che le ipotesi $P_{1},\dots,P_{n}$ siano vere ma che, per assurdo la tesi $Q$ sia falsa, e da questa assunzione si deriva una contraddizione.

Quando invece il teorema è del tipo:
$$\vDash Q$$
ovvero quando si deve dimostrare $Q$ senza partire da alcuna ipotesi, allora una dimostrazione per assurdo consiste semplicemente nell’assumere per assurdo che $Q$ sia falsa, e poi dimostrare che da quest'assunzione deriva una contraddizione.
#Esempio 
Per tutti i numeri reali $x,y$ se $\underbrace{x+y\geq 2}_{P}$ allora $\underbrace{x\geq1\text{ oppure }y\geq 1}_{Q}$.
Siano $x$ e $y$ numeri reali qualsiasi, e supponiamo per assurdo che $P$ sia vera ma $Q$ sia falsa, ovvero che valgano $x+y\geq 2$ e $x,y<1$.

Dalla negazione di $Q$ segue che $x+1<1+1$, ovvero $x+y<2$. Ma questo contraddice l'assunzione $P$, ovvero si avrebbe che:
$$x+y\geq 2\text{ e }\neg(x+y\geq 2)$$
Questo dimostra che se vale $P$, allora $Q$ non può essere falsa. In altre parole, è vero che se vale $P$ allora deve valere anche $Q$, quindi il teorema è dimostrato.
## Dimostrazione per contrapposizione
