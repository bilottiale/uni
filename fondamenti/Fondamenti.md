# Libro 1
## 1.1 Bits and Their Storage
1 -> True
0 -> False
Le tre operazioni Booleane basiche sono **AND**, **OR** e **XOR**.
![[Pasted image 20240117142953.png|500]]
Un **flip-flop** è una struttura fondamentale per la memoria dei computer. È un circuito che produce come input valori di $0$ e $1$, che rimangono costanti finché non ricevono un "impulso" da un altro circuito che gli permette di cambiare stato e quindi valore.

![[Pasted image 20240117143321.png|500]]
I flip-flop possono essere usati per memorizzare informazioni, ad esempio i **very large-scale integration (VLSI)** sono formati da *chip* dentro ai quali sono presenti milioni di flip-flops.

![[Pasted image 20240117143556.png|500]]

Una serie di **bit** viene chiamata **stringa** di bit, quindi sequenze di $1$ e $0$, per semplificare la rappresentazione usiamo la **notazione esadecimale**. Che comprende cifra da $0$ a $F$.
$$
15_{10}\quad = \quad F_{16}
$$
Spesso i numeri esadecimali usano il prefisso $0\text{x}$.
## 1.2 Main Memory
La memoria principale di un computer è organizzata in *celle*, di grandezza di $8$ bits($1$ byte). Per identificare le celle individuali ognuna di esse ha un "nome" detto **indirizzo**. Siccome la memoria principale è organizzata in celle individuali e "indirizzabili", viene chiamata **random access memory (RAM)**.
## 1.3 Mass Storage
Le memorie di massa sono: dischi magnetici, CD, DVD, nastri magnetici, flash drives, e SSD. Le memorie di massa sono meno volatili, più capaci e costano meno. Lo svantaggio è che richiedono movimenti meccanici e quindi più tempo per accedere alle informazioni. Possono quindi subire guasti meccanici.
Per valutare le prestazioni di un sistema disco vengono utilizzate diverse misurazioni:
1. *Tempo di ricerca*
2. *Ritardo rotazionale*
3. *Tempo di accesso*
4. *Velocità di trasferimento*
5. *Velocità della banda*
6. *Latenza*
Un'altra classe di sistemi di archiviazione come i **compact disk(CD)**. Inizialmente utilizzati per registrare tracce audio. Le informazioni sono archiviate lungo una singola traccia che ruota attorno al CD, divisa in settori da $2\text{KB}$. I CD tradizionali hanno una dimensione di $600-700\text{MB}$. Tuttavia i **DVD(Digital Versatile Disks)**, formati da più livelli semitrasparenti letti da un laser, offrono capacità di diversi $\text{GB}$. Infine i **DB(Blue-Ray Disks)** usano una laser nello spettro blue-viola invece del rosso. Come risultato abbiamo un singolo livello dalle capacità di diversi $\text{GB}$. Il movimento fisico come la rotazione del disco, il movimento del braccio di scrittura/lettura, puntare il laser, sono necessari e quindi lenti. Le **memorie Flash** alleviano questo problema, i bit sono archiviati mandando un segnale elettronico, per poi intrappolare gli elettroni in piccole gabbie di biossido di silicio, capaci di immagazzinare le informazioni per diversi anni senza alimentazione esterna, sono utili per memorie non volatili e portatili. I dispositivi di memoria flash sono chiamate *unità flash*. Le unità flash di grandi dimensioni prendo il nome di **SSD(Solid-state Drives)** sono progettate per sostituire i dischi magnetici data la loro silenziosità e velocità nell'accesso dei dati. 
## 1.4 Representing Information as Bit Patterns
*ASCII* per il testo.
*Unicode* $21$ bits
*UTF-8* $8$ bits
Per i numeri si usa la notazione binaria ($0,1$).
## 1.5 Storing Integers
*Complemento a due*:
- *Numeri positivi*: nel caso dei numeri binari positivi la rappresentazione in complemento a $2$ è uguale alla rappresentazione segno-grandezza.
- *Numeri negativi*: nel caso dei numeri binari negativi la rappresentazione in complemento a $2$ è uguale all'inversione di ogni cifra (bit) del numero binario in valore assoluto a cui viene addizionato il numero binario uno $(00000001)_{2}$.
$$
\begin{align}
&(-10)_{10} = 10001010 \\
&(+20)_{10} = 00010100 \\
\\
&|10|_{10} = 00001010 \\
\\
& \text{Inverto le cifre} \\
&|10|_{10} = 11110101 \\
\\
&\text{Aggiungo } 00000001 \\
&11110101+ \\
&00000001= \\
&11110110 \\
\end{align}
$$
Quindi il complemento in base $2$ di $(-10)_{10}=11110110$.
Per poi aggiungere il numero positivo:
$$
\begin{align}
&11110110+ \quad \text{-10 in complemento 2} \\
&00010100= \quad \text{+20} \\
&00001010
\end{align}
$$
*Notazione di eccesso*:
Eccesso-$3$:
- $1$ in eccesso-$3$: $1+3=4= (100)_{2}$
- $-1$ in eccesso-$8$: $-1+8=7=(111)_{2}$
## 1.7 Storing Fractions
*Virgola mobile* per frazioni:
![[Pasted image 20240119145615.png|500]]
$01101011$
$\underbrace{0}_{\text{Bit segno}}\ \underbrace{110}_{\text{Esponente}}\ \underbrace{1011}_{\text{Mantissa}}$

*0 = Bit di segno*:
- $0$: positivo
- $1$: negativo
Poi estraiamo la *mantissa*: $.1011$.
Poi estraiamo l'*esponente*: consideriamo $110$ in eccesso-$3$: $6-4=(2)_{10}$.
$2$ significa che dobbiamo spostare la virgola della mantissa di 2 posizioni verso destra:
$10.11$ ovvero $2\frac{3}{4}$. Quindi $01101011=10.11=2 \frac{3}{4}$.
#Esempio 
$00111100$
$0$ bit di segno.
$1100$ mantissa $.1100$
$011$ esponente.
$011 = 3 - 4 = -1$, 1 posizione verso sinistra.
$.01100= \frac{3}{8}= 00111100$.
*Troncamento*:
Si può perdere informazioni se la dimensione della mantissa non è grande abbastanza.
#Esempio 
![[Pasted image 20240119153529.png|500]]
## 1.9 Data Complession
possono essere con (*lossy*) o senza (*lossless*) perdita di informazione.
*Lempel-Ziv-Welsh* (*LZW*) *encoding*. Si codificano sequenze di simboli di lunghezza variabile con codici di lunghezza fissa.
#Esempio 
xyx xyx xyx xyx $=121343434$
$121 = 4$
   $3$ (spazio)
## 1.10 Communication Errors
Per sapere se ci sono stati errori di comunicazione viene utilizzato il *bit di parità*:
$10110110$
Parità *pari*: numero di $1$ è dispari quindi ne aggiungo uno: $10110110[1]$
Parità *dispari*: numeri di $1$ già dispari quindi aggiungo $0$: $10110110[0]$
Alcuni codici di correzione degli errori sono *Distanza di Hamming*:
$$
\begin{align}
&01{\color{red}1}100 \text{ codice}\\
&01{\color{red}0}100 \text{ ricevuto}\\
\end{align}
$$
cifre diverse $=1$.

---

# Libro 2
## 1 Sets and Logic
![[Pasted image 20240119160649.png|150]] ![[Pasted image 20240119160716.png|150]] ![[Pasted image 20240119160752.png|120]] ![[Pasted image 20240119160910.png|162]]
## 1.4 Arguments and Rules of Inference
**Modus Ponens**:
$$
\begin{align}
&A\to B \\
&A \\
&\_\_\_\_\_\_\\
&\therefore B
\end{align}
$$
$$[(A\to B)\land A]\to B$$
**Modus Tollens**:
$$
\begin{align}
&A\to B \\
&\overline{B} \\
&\_\_\_\_\_\_\\
&\therefore \overline{A}
\end{align}
$$
$$[(A\to B)\land \overline{B}]\to \overline{A}$$
## 1.5 Quantifiers
#Esempio 
$p:$ "Tutti gli animali hanno $2$ zampe."
$p: \forall x\in A, x$ ha $2$ zampe.
$\overline{p}: \exists x\in A, x$ non ha $2$ zampe.
#Esempio 
$p:$ "Esiste un giorno di $32$ ore."
$p: \exists g\in G, g$ ha $32$ ore.
$\overline{p}: \forall g\in G, g$ non ha $32$ ore.

Leggi di De Morgan per la logica generalizzate:
- $\neg(\forall xP(x)); \exists x\neg P(x)$ ovvero $\overline{A\land B}=\overline{A}\lor\overline{B}$
- $\neg(\exists xP(x)); \forall x\neg P(x)$ ovvero $\overline{A\lor B}=\overline{A}\land\overline{B}$

## 2 Proofs
## 2.1 Mathematica Systems, Direct Proofs, and Counterexamples
La ***dimostrazione diretta*** è la strategia più semplice e naturale per stabilire un teorema del tipo:
$$
P_{1},\dots,P_{n}\models Q
$$
La dimostrazione diretta assume di trovarsi in un qualunque contesto in cui siano verificate le ipotesi $P_{1},\dots,P_{n}$ e sulla base di semplici e rigorosi ragionamenti stabilisce che in tale contesto anche la tesi $Q$ è verificata.
#Esempio 
Se $n$ è un numero intero dispari e $m$ è un numero intero pari, allora $n+m$ è un numero intero dispari.
Siano $n$ ed $m$ interi qualsiasi, e assumiamo che $n$ sia dispari e $m$ sia pari, ovvero che $n=2l+1$ per qualche intero $l$, mentre $m=2k$ per qualche intero $k$. Bisogna dimostrare dimostrare che $n+m$ è dispari. Effettuando i calcoli:
$$
\begin{align}
n+m &=(2l+1)+2k \\
&=(2l+2k)+1 \\
&=2(l+k)+1
\end{align}
$$
Questo dimostra che $n+m$ è dispari perché ha la forma $2j+1$.

La ***dimostrazione per assurdo*** di una proposizione $Q$ a partire dalle ipotesi $P_{1},\dots,P_{n}$ è una dimostrazione in cui si assume che $Q$ sia falsa e da questa assunzione si deriva una *contraddizione*, ovvero una proposizione della forma
$$R \text{ e non }R$$
che asserisce che una qualche affermazione $R$ è al contempo sia vera che falsa. Poiché una contraddizione è necessariamente falsa, questo prova che assumere che $Q$ sia falsa porta a conclusioni assurde, e quindi $Q$ non può che essere vera. In altre parole: si dimostra che se le premesse $P_{1},\dots,P_{n}$ sono vere non è possibile che $Q$ sia falsa.
#Esempio 
Per tutti i numeri reali $x,y$, se $\underbrace{x+y\geq 2}_{P}$ allora $\underbrace{x\geq 1\text{ oppure }y\geq 1}_{Q}$.
Siano $x$ e $y$ numeri reali qualsiasi, e supponiamo per assurdo che $P$ sia vera ma $Q$ sia falsa, ovvero che valgano $x+y\geq 2$ e $x,y<1$.
Dalla negazione di $Q$ segue che $x+y<1+1$, ovvero $x+y<2$. Ma questo contraddice l'assunzione $P$, ovvero si avrebbe che
$$
x+y\geq 2\text{ e non }x+y\geq 2
$$
Questo dimostra che se vale $P$ allora $Q$ non può essere falsa. In altre parole, è vero che se vale $P$ allora deve valere anche $Q$, quindi il teorema è dimostrato.
#Esempio 
Dimostriamo che: per ogni numero intero $n$, se $\underbrace{n^{2} \text{ è pari}}_{P}$, allora $\underbrace{n \text{ è pari}}_{Q}$.
Supponiamo per assurdo che $P$ sia vera ma $Q$ sia falsa e facciamo vedere che queste assunzioni portano ad una contraddizione. Sia $n$ dispari, ovvero $n=2m+1$ per qualche intero $m$. Allora possiamo calcolare:
$$
\begin{align}
n^{2} &=(2m+1)^{2} \\
&=4m^{2}+4m+1 \\
&=2(2m^{2}+2m)+1
\end{align}
$$
per cui $n^{2}$ è dispari. Quindi abbiamo che:
"$n^{2} \text{ è pari}$" e non "$n^{2} \text{ è pari}$",
contraddizione! Quindi se vale $P$ deve valere anche $Q$.
## 2.4 Mathematical Induction
Supponiamo una serie di blocchi numerati $1,2,\dots$ siano su un tavolo e che alcuni blocchi siano marcato con una "$X$".
- Il primo blocco è marcato.
- Per ogni $n$, se il blocco $n$ è marcato, allora anche il blocco $n+1$ è marcato.
![[Pasted image 20240119175952.png|500]]
Ciò è chiamato *passo base* e la condizione è chiamata *passo induttivo*.
## 3 Functions, Sequences, and Relations
## 3.2 Sequences and Strings
Una *sequenza* $s$ è una funzione il quale dominio $D$ è un sottoinsieme di numeri interi. La notazione $s_{n}$ equivale a $s(n)$. $n$ indica l'indice della sequenza. Se $D$ è finito, chiamiamo la sequenza finita, oppure infinita.
Si possono creare nuove sequenze da una sequenza data, la quale prende il nome di *sottosequenza*.
La sottosequenza:
$$b,c$$
è ottenuta dalla sequenza:
$$a,a,b,c,q$$
Devono rispettare l'ordine in cui si trovano nella sequenza originaria.
## 3.3 Relations
$X=\{\text{Bill, Mary, Beth, Dave}\}$ e $Y=\{\text{CompSci, Math, Art, History}\}$ le relazioni $R$ sono:
$$
\begin{align}
R=&\{\text{(Bill, CompSci),(Mary, Math), (Bill, Art), (Beth, History)} \\
&\text{(Beth, CompSci), (Dave, Math)}\}
\end{align}
$$
Si può scrivere anche $\text{Beth }R \text{ History}$.
#Esempio 
Le relazioni $R$ in $X=\{a,b,c,d\}$ date dal seguente diagramma sono: $R=\{(a,a),(b,c),(c,b),(d,d)\}$.
![[Pasted image 20240120112359.png|250]]

Una relazione $R$ è *simmetrica* se per ogni $x,y\in X$, se $(x,y)\in R$, allora $(y,x)\in R$.
$$\forall x\forall y[(x,y)\in R]\to [(y,x)\in R]$$
Una relazione $R$ è *antisimmetrica* se per ogni $x,y\in X$, se $(x,y)\in R$ e $(y,x)\in R$, allora $x=y$.
$$\text{if }(x,y)\in R \text{ and }(y,x)\in R, \text{ then }x=y$$
Una relazione $R$ è *transitiva* se per ogni $x,y,z\in X$, se $(x,y)$ e $(y,z)\in R$, allora $(x,z)\in R$.
$$\text{if }(x,y)\text{ e }(y,z)\in R, \text{ allora }(x,z)\in R$$
Sia $R$ una relazione da $X$ a $Y$. La *inversa* di $R$ ($R^{-1}$), è la relazione da $Y$ a $X$ definita da:
$$R^{-1}=\{(y,x)|(x,y)\in R\}$$
#Esempio $R$ da $X=\{2,3,4\}$ a $Y=\{3,4,5,6,7\}$ definita da:
$$(x,y)\in R\quad \text{se }x \text{ divide }y$$
otteniamo:
$$R=\{(2,4),(2,6),(3,3),(3,6),(4,4)\}$$
La relazione inversa è:
$$R^{-1}=\{(4,2),(6,2),(3,3),(6,3),(4,4)\}$$

Sia $R_{1}$ una relazione da $X$ a $Y$ e $R_{2}$ una relazione da $Y$ a $Z$. La *composizione* di $R_{1}$ e $R_{2}$ scritta come $R_{2}\circ R_{1}$, è la relazione da $X$ a $Z$ definita come:
$$R_{2}\circ R_{1}=\{(x,z)|(x,y)\in R_{1}\text{ e }(y,z)\in R_{2}\text{ per alcuni }y\in Y\}$$
La composizione delle relazioni
$$R_{1}=\{(1,2),(1,6),(2,4),(3,4),(3,6),(3,8)\}$$
$$R_{2}=\{(2,u),(4,s),(4,t),(6,t),(8,u)\}$$
è:
$$
R_{2}\circ R_{1}=\{(1,u),(1,t),(2,s),(2,t),(3,s),(3,t),(3,u)\}
$$
## 11 Boolean Algebras and Combinatorial Circuits
## 11.1 Combinatorial Circuits
L'output di un *circuito combinatorio* è unicamente definito per ogni combinazione di input, non ha memoria, gli input precedenti non hanno effetto sul circuiti, a differenze dei *circuiti sequenziali*.
I circuiti combinatori sono formati da porte, dette *gates* logici.
***AND***
$$
\begin{align}
x_{1}\land x_{2}=\begin{cases}
1 &\text{if }x_{1}=1 \text{ e }x_{2}=1 \\
0 &\text{altrimenti}
\end{cases}
\end{align}
$$
![[Pasted image 20240120144802.png|250]]

***OR***
$$
\begin{align}
x_{1}\land x_{2}=
\begin{cases}
1 &\text{se }x_{1}=1  \text{ oppure }x_{2}=1\\
0 &\text{altrimenti}
\end{cases}
\end{align}
$$
![[Pasted image 20240120144926.png|250]]

***NOT***
$$
\begin{align}
\overline{x}=
\begin{cases}
1 &\text{se }x=0\\
0 &\text{se }x=1
\end{cases}
\end{align}
$$
![[Pasted image 20240120145050.png|500]]

#Esempio circuito combinatorio
![[Pasted image 20240120145203.png|500]]

Un circuito può essere scritto come espressione booleana:
![[Pasted image 20240120151345.png|500]]
$$
y=\overline{(x_{1}\land x_{2})\lor x_{3}}
$$
*Soluzione*:
assegnamo $1$ o $0$ ad ogni $x_{n}$:
$$
\begin{align}
X(1,0,0)&=\overline{(1\land 0)\lor 0} \\
&=\overline{0\lor 0} \\
&=\overline{0} \\
&=1
\end{align}
$$
## 11.2 Properties of Combinatorial Circuits
*Associativa*:
$$
\begin{align}
&(a\lor b)\lor c=a\lor(b\lor c)\\
&(a\land b)\land c=a\lor(b\lor c)
\end{align}
$$
*Commutativa*:
$$
\begin{align}
a\lor b=b\lor a\quad \quad a\land b=b\land a
\end{align}
$$
*Distributiva*:
$$
\begin{align}
a\land(b\lor c)=(a\land b)\lor(a\land c) \\
a\lor(b\land c)=(a\lor b)\land(a\lor c)
\end{align}
$$
*Identità*:
$$
a\lor 0=a, \quad\quad a\land 1=a
$$
*Complemento*:
$$
a\lor\overline{a}=1,\quad\quad a\land\overline{a}=0
$$
## 11.3 Boolean Algebras
L'*algebra Booleana* consiste in un insieme $S$ contenente gli elementi $1$ e $0$, le operazioni binarie $+$ e $\cdot$ su $S$.
*Legge associative*:
$$
\begin{align}
(x+y)+z&=x+(y+z) \\
(x\cdot y)\cdot z&=x\cdot(y\cdot z)
\end{align}
$$
*Legge commutativa*:
$$
x+y=y+x, \quad\quad x\cdot y=y\cdot x
$$
*Legge distributiva*:
$$
\begin{align}
x\cdot(y+z)&=(x\cdot y)+(x\cdot z) \\
x+(y\cdot z)&=(x+y)\cdot(x+z)
\end{align}
$$
*Identità*:
$$
x+0=x,\quad\quad x\cdot 1=x
$$
*Complemento*:
$$
x+x'=1,\quad\quad x\cdot x'=0
$$
## 11.5 Boolean Function and Applications
Un *gate* rappresenta una funzione:
$$
Z_{2}^{n}\to Z_{2}
$$
dove $Z_{2}=\{0,1\}$.
Il gate *AND* è la funzione $\land$ da $Z_{2}^{2}$ a $Z_{2}$.
Il gate *OR* è la funzione $\lor$ da $Z_{2}^{2}$ a $Z_{2}$.
Il gate *NOT* è la funzione $\overline{}$ da $Z_{2}^{2}$ a $Z_{2}$.
![[Pasted image 20240120160226.png|500]]

Il gate *NAND* riceve come input due bit $x_{1}$ e $x_{2}$, produce un output scritto come $x_{1}\uparrow x_{2}$, dove:
$$
\begin{align}
x_{1}\uparrow x_{2}=
\begin{cases}
0 &\text{se }x_{1}=1\text{ e }x_{2}=1\\
1 &\text{altrimenti}
\end{cases}
\end{align}
$$
![[Pasted image 20240120160622.png|250]]
$$x\uparrow y=\overline{xy}$$

***Half-Adder***: accetta come input due bits $x$ e $y$ e produce come output la somma binaria $cs$ di $x$ e $y$. Dove $s$ è la somma e $c$ il resto (carry bit).
![[Pasted image 20240120161556.png|500]]

***Full-Adder***: accetta come input 3 bits $x,y$ e $z$ e produce come output la somma binaria $cs$ di $x,y$ e $z$. Dove $s$ è la somma e $c$ il resto (carry bit).
![[Pasted image 20240120161809.png|500]]

#Esempio Un circuito che somma numeri binari è composto da:
![[Pasted image 20240120162012.png|500]]

## 12 Automata, Grammars, and Languages
## 12.1 Sequential Circuits and Finite-State Machines
Le operazioni all'interno di un computer digitale vengono eseguite a intervalli di tempo. L'output dipende dallo stato del sistema così come dall'input. Assumeremo che lo stato del sistema cambi solo al tempo $t=0,1,\dots$. Un modo semplice per introdurre la sequenza nei circuiti è introdurre una unità di *ritardo temporale* (delay).
L'unità di delay prende in input un bit $x_{t}$ ad un momento $t$ e restituisce $x_{t-1}$, il bit ricevuto come input al momento $t-1$.
![[Pasted image 20240120163621.png|250]]

Il delay viene utilizzato nel *serial adder*, il quale prende come input due numeri binari:
$$x=0x_{N}x_{N-1}\dots x_{0}\quad \text{ e }\quad y=0y_{N}y_{N-1}\dots y_{0}$$
e restituisce in output la somma $z_{N+1}z_{N}\dots z_{0}$ di $x$ e $y$.
I numeri $x$ e $y$ sono input sequenziali in paia, $x_{0}y_{0};x_{N}y_{N};0,0$. La somma è l'output $z_{0},z_{1},\dots ,z_{N+1}$.
![[Pasted image 20240120164114.png|250]]

Una ***macchina a stati finiti*** è un modello astratto di una macchina con una memoria primitiva. Una macchina a stati finiti $M$ consiste di:
- Un insieme finito $I$ di *simboli di input*
- Un insieme finito $O$ di *simboli di output*
- Un insieme finito $S$ di *stati*
- Una *funzione prossimo stato* $f$ da $S\times I$ a $S$
- Una *funzione di output* $g$ da $S\times I$ a $O$
- Uno *stato iniziale* $\sigma\in S$
Scriviamo $M=\{I,O,S,f,g,\sigma\}$.
## 12.2 Finite-State Automata
Un *automa a stati finiti* è una forma speciale di macchina a stati finiti, data la loro relazione con i linguaggi.
Sia $A=\{I,O,S,f,g,\sigma\}$ una macchina a stati finiti nel quale l'insieme degli output è $\{0,1\}$ e dove lo stato corrente determina l'ultimo output. Gli stati nel quale l'ultimo output era $1$ sono detti *stati accettanti*.
![[Pasted image 20240120165724.png|500]]
## 12.3 Languages and Grammars
La lingua è “le parole, la loro pronuncia e i metodi per combinarle, usate e comprese da una comunità”. Tali linguaggi sono spesso chiamati *linguaggi naturali* per distinguerli dai *linguaggi formali*, utilizzati per modellare i linguaggi naturali e per comunicare con i computer. Le regole di un linguaggio naturale sono molto complesse e difficili da comprendere completamente. D'altra parte, è possibile specificare completamente le regole con cui sono costruiti certi linguaggi formali.
Iniziamo con la definizione di linguaggio formale: sia $A$ un insieme finito. $A$ linguaggio (formale) $L$ di $A$, è un sottoinsieme di $A^{*}$.

Una *grammatica che struttura della frase* o semplicemente *grammatica* $G$ consiste di:
- un insieme finito $N$ di *simboli non terminali*
- un insieme finito $T$ di *simboli terminali* dove $N\cap T=\varnothing$
- un sottoinsieme finito $P$ di $[(N\cup T)^{*}-T^{*}]\times(N\cup T)^{*}$, chiamato insieme di *produzioni*
- un *simbolo iniziale* $\sigma\in N$
Scriviamo $G=\{N,T,P,\sigma\}$.
Una produzione $(A,B)\in P$ è scritta:
$$A\to B$$
#Esempio Sia
$$
\begin{align}
&N=\{\sigma,S\} \\
&T=\{a,b\} \\
&P=\{\sigma \to b\sigma, \sigma\to aS, S\to bS, S\to b\}
\end{align}
$$
allora $G=\{N,T,P,\sigma\}$ è una grammatica.
Data una grammatica $G$, possiamo costruire un linguaggio $L(G)$ da $G$ usando le produzioni per derivare le stringhe che compongono $L(G)$. L'idea è di iniziare con il simbolo iniziale e poi utilizzare ripetutamente le produzioni fino ad ottenere una stringa di simboli terminali. Il linguaggio L(G) è l'insieme di tutte queste stringhe ottenute.

Sia $G=(N,T,P,\sigma)$ una grammatica.
Se $\alpha\to \beta$ è una produzione e $x\alpha y\in (N\cup T)^{*}$, diciamo che $x\beta y$ è *direttamente derivabile* da $x\alpha y$ e quindi scrivere:
$$
x\alpha y\Rightarrow x\beta y
$$
se $\alpha_{i}\in (N\cup T)^{*}$ per $i=1,\dots,n$, e $a_{i+1}$ è direttamente derivabile da $a_{i}$ per $i=1,\dots,n-1$, diciamo che $\alpha_{n}$ è *derivabile da* $\alpha_{1}$ e scrivere:
$$\alpha_{1}\Rightarrow\alpha_{n}$$
ovvero:
$$
\alpha_{1}\Rightarrow\alpha_{2}\Rightarrow\dots\Rightarrow\alpha_{n}
$$
la derivazione di $\alpha_{n}$ (da $\alpha_{1}$). Per convenzione, ogni elemento di $(N\cup T)^{*}$ è derivabile da se stessa.
Il *linguaggio geerato* da $G$, scritto $L(G)$, consiste nelle stringhe di $T$ derivabili da $\sigma$.

Sia la grammatica:
$$
\begin{align}
&N=\{\sigma,S\} \\
&T=\{a,b\} \\
&P=\{\sigma \to b\sigma, \sigma\to aS, S\to bS, S\to b\}
\end{align}
$$
La stringa $abSbb$ è direttamente derivabile da $aSbb$:
$$aSbb\Rightarrow abSbb$$
usando la produzione $S\to bS$.
La stringa $bbab$ è derivabile da $\sigma$:
$$\sigma\Rightarrow bbab$$
la derivazione è:
$$
\sigma\Rightarrow b\sigma\Rightarrow bb\sigma\Rightarrow bbaS\Rightarrow bbab
$$
Sia $G$ una grammatica, denotiamo con $\lambda$ il carattere vuoto.
## 12.4 Nondeterministic Finite-State Automata
#Esempio 
Ho un automa non deterministico che lavora con un alfabeto binario $\{0,1\}$.
L'automa analizza una stringa composta da $0$ e $1$.
![[Pasted image 20240120182719.png|500]]

La funzione di transizione è:
$$\Delta=\{(a,0,a),(a,1,a),(a,1,b),(b,0,c),(c,0,c),(c,1,c)\}$$
Questo automa riconosce le stringhe con una sequenza interna composta almeno una volta dalla sottostringa "$01$".
Provo ad analizzare la stringa "$11$":
***Primo evento***:
Il primo evento è il simbolo $1$ ossia il primo carattere della stringa $11$.
L'automa non deterministico resta nello stato $A$ e contemporaneamente passa nello stato $B$.
È come se lanciasse due processi in esecuzione in background.
![[Pasted image 20240120183026.png|500]]

***Secondo evento***:
L'evento successivo è il simbolo $1$, secondo carattere della stringa "$11$".
Il nuovo evento è analizzato sia nel nodo $A$ che nel nodo $B$.
![[Pasted image 20240120183134.png|500]]

- Il processo nel nodo $A$ continua a girare, è previsto l'evento ($1$). In questo caso permane nello stesso nodo $A$.
- Il processo nel nodo $B$ viene eliminato, non è previsto l'evento ($1$) in uscita.


