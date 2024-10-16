# Prestazioni dei Computer
## Tempo di risposta e produttività
- **Tempo di risposta**: latenza, quanto ci vuole per eseguire una operazione.
- **Produttività**: Lavoro totale svolto per unità di tempo.
In che modo sono influenzati?
- Sostituire il processore con una versione più veloce?
- Aggiungere più processori?
## Tempo di risposta
Cosa determina le prestazioni di un programma?
- **Algoritmi**
	- Determina il numero di **operazioni** eseguite.
- **Linguaggio di programmazione**, **compilatore**, **architettura**
	- Determina il numero di **istruzioni macchina** eseguite per operazione.
- **Processore e memoria di sistema**
	- Determinano quanto *veloce* le istruzioni vengono eseguite.
- **Sistemi di I/O** (OS incluso)
	- Determina quanto velocemente le operazioni di I/O sono eseguite.
### Misuriamo il tempo di risposta
**Tempo trascorso**:
- Tempo di risposta totale
	- Elaborazione, I/O, overhead del SO, tempo di inattività.
- **Tempo di CPU** (Clock):
	- Tempo speso elaborando un dato lavoro:
		- Sconti sul tempo di I/O, quote di altri lavori
	- Comprende il tempo CPU dell'utente + tempo  CPU del sistema
	- I programmi sono influenzati dalle prestazioni della CPU e del sistema
## CPU Clock
È la frequenza operativa di un processore, cioè la velocità con cui la CPU può eseguire le istruzioni.
$$
T=\frac{1}{f}
$$
Dove:
- $T$ è il **periodo di clock** (misurato in secondi)
- $f$ è la **frequenza del clock** (misurata in hertz, Hz)
![[Pasted image 20241014172619.png]]
**Esempio**:
Se la frequenza del clock della CPU è **2 GHz** (2 miliardi di cicli al secondo), il periodo di clock sarà:
$$
T = \frac{1}{2 \times 10^{9}} = 0,5 \times 10^{-9} = 0,5 \text{ nanosecondi}(ns)
$$
Ogni ciclo di clock dura **0,5 nanosecondi**.
$$
\text{Clock Rate} = \frac{\text{Clock Cycles}}{\text{CPU Time}}
$$
GHz:
$$
1GHz = 10^{9}Hz
$$
**ISA**: Instruction Set Architecture.
Il **conteggio delle istruzioni** per un programma sono determinati dal programma, ISA e compilatore.
Il numero medio di **cicli per istruzione** (CPI), sono determinati dall'hardware della CPU. Se istruzioni differenti hanno CPI differenti, il CPI medio è influenzato dal mix di istruzioni.

**Esempio**:
- Computer A: $\text{Cycle Time} = 250ps, CPI = 2.0$
- Computer B: $\text{Cycle Time}=500ps, CPI=1.2$
- ISA identico
Quale è più veloce? Di quanto?
$$
\begin{align}
\text{CPU Time}_{A} &= \text{Instruction Count}\times \text{CPI}_{A} \times \text{Cycle Time}_{A} \\
&=1 \times 2.0 \times 250ps = 1 \times 500ps \\
\text{CPU Time}_{B} &= \text{Instruction Count}\times \text{CPI}_{B} \times \text{Cycle Time}_{B} \\
&=1 \times 1.2 \times 500ps = 1 \times 600ps
\end{align}
$$
$A$ è più veloce, di quanto?
$$
\frac{\text{CPU Time}_{B}}{\text{CPU Time}_{A}} = \frac{1 \times 600ps}{1 \times 500ps} = 1.2
$$
$A$ è $1.2$ volte più veloce di $B$.

Se classi di istruzione diverse richiedono un numero diverso di cicli:
$$
\text{Clock Cycles} = \sum^{n}_{i=1}(\text{CPI}_{i} \times \text{Instruction Count}_{i})
$$
Media pesata dei CPI:
$$
\text{CPI} = \frac{\text{Clock Cycles}}{\text{Instruction Count}} = \sum^{n}_{i=1}\left( \text{CPI}_{i} \times \underbrace{\frac{\text{Instruction Count}_{i}}{\text{Instruction Count}}}_{\text{Relative frequency}} \right)
$$
![[Pasted image 20241014175013.png#invert]]
**IPC**: Istruzioni per ciclo:
$$
\text{IPC} = \frac{\text{Instruction Count}}{\text{Clock Cycle}} = \frac{1}{\text{CPI}}
$$
**RIASSUMENDO**:
$$
\text{CPU Time} = \frac{\text{Instructions}}{\text{Program}} \times \frac{\text{Clock Cycles}}{\text{Instruction}} \times \frac{\text{Seconds}}{\text{Clock Cycle}}
$$
## Power Trends
Nella tecnologia **CMOS IC**:
$$
\text{Power} =\text{Capacitive load} \times \text{Voltage}^{2} \times \text{Frequency}
$$
# Rappresentazione dell’informazione
## Rappresentazione binaria
Tutta l’informazione interna ad un computer è codificata con sequenze di due soli simboli: 0 e 1.
L’unità elementare di informazione si chiama *bit* (da *binary digit*).
**Byte**: 8 bit.
**Word**: sequenza di 32, 64, ... bits (4, 8, ... *Bytes*)
## Sistema decimale posizionale (1)
La rappresentazione di un numero intero in base 10 è una sequenza di cifre scelte fra l’insieme $\{0, 1, 2, 3, 4, 5, 6, 7, 8, 9\}$.
Il valore di una rappresentazione è dato da:
*Parte intera*:
$$
a_{N} \cdot 10^{N} + a_{N-1} \cdot 10^{N-1} + \ldots + a_{1} \cdot 10^{1} + a_{0} \cdot 10^{0} +
$$
*Parte frazionaria*:
$$
a_{-1} \cdot 10^{-1} + a_{-2} \cdot 10^{-2} + a_{-3} \cdot 10^{-3} + \dots
$$
## Sistema decimale posizionale (2)
$$
\begin{align}
253 &= 2 \times 100 + 5 \times 10 + 3 \times 1 \\
&= 2 \times 10^{2} + 5 \times 10^{1} + 3 \times 10^{0}
\end{align}
$$
## Notazione in base 2 (1)
La rappresentazione di un numero intero in base 2 è una sequenza di cifre scelte fra $\{0, 1\}$ :
*Parte intera*:
$$
a_{N} \cdot 2^{N} + a_{N-1} \cdot 2^{N-1} + \ldots + a_{1} \cdot 2^{1} + a_{0} \cdot 2^{0} +
$$
*Parte frazionaria*:
$$
a_{-1} \cdot 2^{-1} + a_{-2} \cdot 2^{-2} + a_{-3} \cdot 2^{-3} + \dots
$$
## Notazione in base 2 (2)
$$
\begin{align}
110 &= 1 \times 2^{2} + 1 \times 2^{1} + 0 \times 2^{0} = 4 + 2 + 0 = 6
\end{align}
$$
## Conversione di interi: Base 10 -> Base 2
![[Pasted image 20241015091736.png#invert]]
## La rappresentazione dei numeri all'interno di un computer
Gli interi positivi si rappresentano usando 4 o 8 byte.
![[Pasted image 20241015093230.png#invert]]
- Se uso 4 byte (32 bit) posso rappresentare tutti i numeri da $0$ a $2^{32}-1$.
### Numeri relativi
- **Modulo e segno**
	- Prima cifra $0$ -> $+$ 
	- Prima cifra $1$ -> $-$
$$
+2 \leftrightarrow 010 \ \text{ e } \ -2 \leftrightarrow 110
$$
### Complemento a due
Esempio con 4 bit:
Partiamo da $+5 = 0101 (4 + 1)$
1. si invertono gli $1$ con gli $0$: $1010$
2. si aggiunge $1$: $1011 = -5$
$$
\begin{align}
&1010 + 1 = 1011 = -5 \\
&-1 \times 2^{3} + 0 \times  2^{2} + 1 \times 2^{1} + 1 \times 2^{0} \\
&= -8 + 0 + 2 + 1 = \color{red}{-5}
\end{align}
$$
### Conversione in base 8 da base 2
$$
111000110101_{2}
$$
In base 8:
$$
\underbrace{111}_{} \ \underbrace{000}_{\text{}} \ \underbrace{110}_{\text{}} \ \underbrace{101}_{\text{}} = 7065_{8}
$$
In base 16:
$$
\underbrace{1110}_{\text{}}\  \underbrace{0011}_{\text{}} \ \underbrace{0101}_{\text{}} = E35_{16}
$$
### BCD (Binary-Coded Decimal)
Si codificano in binario (4 bit) le singole cifre decimali.
$254$:
$$
\underbrace{0010}_{2} \ \underbrace{0101}_{5} \ \underbrace{0100}_{4}
$$
## Rappresentazione in virgola fissa
Riservo $X$ bit per la parte frazionaria.
Es:
$$
\begin{align}
101.01 &= 1 \times 2^{2} + 0 \times 2^{1} + 1 \times 2^{0} + 0 \times 2^{-1} + 1 \times 2^{-2}  \\
&= 4 + 0 + 1 + 0 + 0.25 = 5,25
\end{align}
$$
**Problemi**:
- *Overflow*
	- quando si sale al di sopra del massimo numero rappresenrtabile.
- *Underflow*
	- quando si scende al di sotto del minimo numero rappresentabile.
## Rappresentazione in virgola mobile
Quando lavoro con *numeri molto piccoli* uso tutti i bit disponibili per rappresentare le cifre dopo la virgola.
Quando lavoro con *numeri molto grandi* le uso tutte per rappresentare le cifre in posizioni elevate.
- Ogni numero $N$ è rappresentato da una coppia (*mantissa* $M$, *esponente* $E$) con il seguente significato
$$
N = M \times 2^{E} 
$$
Esempio in base 10, con 3 cifre per la mantissa e 2 cifre per l'esponente:
$$
349 \ 000 \ 000 \ 000 = 3.49 \times 10^{11} 
$$
con la coppia $(3.49, 11)$ perché $M = 3,49$ e $E = 11$.
$$
0.000 \ 000 \ 002 = 2.0 \times 10^{-9} 
$$
con la coppia $(2.0, -9)$ perché $M = 2.0$ e $E = -9$.
## Standard IEEE 754
Si specificano 3 parametri:
- $P$: precisione o numero di bit che compongono la mantissa.
- $E_{max}$: esponente massimo.
- $E_{min}$: esponente minimo.
Per la **precisione singola** (32 bit):
- $P = 23, E_{max} = 127 \text{ e }E_{min} = -126$
- $1$ bit di *segno*; $8$ bit *esponente*
![[Pasted image 20241015102331.png#invert]]
- La mantissa viene normalizzata scegliendo l’esponente in modo che sia sempre nella forma $1,xxx\dots$
- L’esponente è *polarizzato*, ovvero ci si somma $E_{max}$
	- costante di polarizzazione o **bias**
Esempio:
$$
0.15625_{(10)} = \frac{1}{8} + \frac{1}{32} = 2^{-3} +2^{-5} = 0.00101_{(2)}
$$
**Normalizzazione** della manitssa:
$$
0.00101_{(2)} = 1.01_{(2)} \times 2^{-3} 
$$
- *Parte frazionaria della mantissa*: $.01_{(2)}$
- *Esponente*: $-3$
- *Esponente polarizzato*: $-3 + 127 = 124$

Per la **precisione doppia** (64 bit)
- $P = 52, E_{max} = 1023, E_{min} = -1022$
- $1$ bit *segno*; $11$ bit *esponente*

- *Parte frazionaria della mantissa*: $.01_{(2)}$
- *Esponente*: $-3$
- *Esponente polarizzato*: $-3 + 1023 = 1020$
...
...
...
# Introduzione alle Reti Logiche
## Reti logiche
Sistema digitale avente $n$ segnali binari di ingresso ed $m$ segnali binari di uscita.
I segnali sono rigorosamente binari $(0/1)$.
![[Pasted image 20241015104915.png#invert]]
I segnali sono grandezze funzioni del tempo
$$
X = \{ x_{n-1}(t), \dots, x_{0}(t) \}
$$
### Proprietà delle reti logiche
- **Interconnessione**: l’interconnessione di più reti logiche, aventi per ingresso segnali esterni o uscite di altre reti logiche e per uscite segnali di uscita esterne o ingressi di altre reti logiche, è ancora una rete logica.
![[Pasted image 20241015105327.png#invert]]
- **Decomposizione**: una rete logica complessa può essere decomposta in reti logiche più semplic.
- **Decomposizione in parallelo**: una rete logica a $m$ uscite può essere decomposta in $m$ reti logiche ad $1$ uscita, aventi ingressi condivisi.
![[Pasted image 20241015105436.png#invert]]
## Reti combinatorie
- ogni segnale di uscita dipende solo dai valori degli ingressi in quell’istante.
- senza memoria, *non ha stato*, non ricorda gli ingressi precedenti, *transitori* a parte, basta conoscere gli ingressi in un istante per sapere esattamente quali saranno tutte le uscite nel medesimo istante.
**Esempio**:
Conversione di valori BCD su display a sette segmenti:
- Progettare una rete logica che permette la visualizzazione su un display a sette segmenti di un valore in codice BCD.
- **Codifica BCD**: impiego di 4 cifre binarie per la rappresentazione di un numero decimale da 0 a 9.
$$
\begin{align}
15 &&& \text{decimale} \\
1111 &&& \text{binario} \\
0001 \ 0101 &&& BCD
\end{align}
$$
L'uscita $Z = \{ a, b, \dots, g \}$ dipende in ogni istante dalla configurazione degli ingressi $\{ x_{3}, x_{2}, x_{1}, x_{0} \}$.
![[Pasted image 20241015110713.png#invert|350]]
### Descrizione reti combinatorie
- **Tabelle di verità**: associa le possibili combinazioni degli ingressi alle corrispondenti configurazioni delle uscite e indica il comportamento della rete logica.
	- Se la rete combinatoria ha $n$ ingressi e $m$ uscite, allora la tabella di verità ha $(n+m)$ colonne e $2^{n}$ righe.
	- **COMPLETAMENTE SPECIFICATE**: se ogni valore della tabella assume il valore logico di vero o falso.
	- **NON COMPLETAMENTE SPECIFICATE**: se contengono condizioni di indifferenza. Si verifica in due casi:
		- se alcune configurazioni di ingressi sono vietate.
		- se le uscite sono indifferenti per alcune configurazioni di ingresso.
### Funzioni combinatorie e gate elementari
Le reti logiche combinatorie sintetizzano funzioni combinatorie.
Per ogni $n$, è finito il numero di funzioni combinatorie di $n$ variabili di ingresso. Alcune funzioni combinatorie elementari hanno una rappresentazione logica e grafica (*gate*).
![[Pasted image 20241015143152.png#invert|500]]
#### Funzioni di 2 variabili indipendenti
- **AND**
- **OR**
- **EXOR**
- **NOR**
- **EXNOR**
- **NAND**
Quante sono le possibili funzioni binarie di $n$ variabili?
$$
\text{N.conf} = 2^{2n}
$$
**Esempio** di rete logica con gate:
- **HALF ADDER**, un sommatore senza riporto in ingresso.
![[Half_Adder.svg#invert|250]]





## Reti sequenziali
- ogni segnale di uscita dipende dai valori degli ingressi in quell’istante $E$ dai valori che gli ingressi hanno assunto negli istanti precedenti.
- rete con memoria, *ha stato*, è una rete in cui l’uscita cambia in funzione del cambiamento dell’ingresso e della specifica configurazione interna in quell’istante (*STATO*). Lo stato riassume la sequenza degli ingressi precedenti.
- Per sapere l’uscita in un certo istante ho due possibilità:
	- Mi ricordo *TUTTI* gli ingressi che si sono presentati alla rete dalla sua accensione.
	- Memorizzo uno *STATO* del sistema, che riassume in qualche modo tutti gli ingressi precedenti al fine di valutare il valore delle uscite.
**Esempio**:
Progettare la rete logica di gestione di un ascensore:
- La rete ha tre uscite *UP*, *DW* e *O*. *UP*, *DW* indicano le direzioni su e giù mentre *O* vale $1$ se la porta deve essere aperta e $0$ altrimenti. La rete ha come ingresso due segnali che indicano il piano $\{ 0,1,2,3 \}$ corrispondente al tasto premuto. Per calcolare l’uscita è necessario conoscere il piano corrente che indica lo stato interno.
![[Pasted image 20241015110907.png#invert|400]]



