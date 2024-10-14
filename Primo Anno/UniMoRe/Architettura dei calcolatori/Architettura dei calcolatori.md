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
![[Pasted image 20241014175013.png]]
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

