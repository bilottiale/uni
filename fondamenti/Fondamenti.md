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





