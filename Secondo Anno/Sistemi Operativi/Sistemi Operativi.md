# T3 - Chiamate di sistema
## SO in un sistema di calcolo
![[Pasted image 20241014110743.png]]
## Sistema Operativo
- *Kernel*: software mediatore fra applicazioni e hw.
- *Sistema di base*: permette ad un SO di avviarsi e di presentare una interfaccia testuale all'utente.
## Programmi applicativi
Tutto ciò che non è kernel o sistema di base.
![[Pasted image 20241014110921.png|250]]
# Kernel
- Driver dispositivi
- Gestore I/O
- Gestore dei processi
- Gestore del file system
- Gestore della memoria
- IPC
# Sistema base
- Librerie di sistema
- Caricatore dinamico
- Sistema di init
- Comandi di sistema
- Shell
- Terminale
# Programmi applicativi
- Compilatori
- Interpreti
- Ambiente grafico
- Suite di ufficio
- Browser
- Client e-mail
## Modello Client-Server
Una applicazione (di base e non) richiede un servizio al kernel. Il kernel elabora la risposta e la fornisce alla applicazione.
# User Mode e Kernel mode
**User Mode**:
- L'applicazione esegue i calcoli senza accesso diretto alle risorse critiche del sistema, con privilegi ridotti.
- Non può alterare la memoria di altre applicazioni o del kernel.
- Non può eseguire istruzioni assembly legate all'I/O.
**Kernel Mode**:
- **Elevazione dei privilegi**:
	- Quando un'applicazione richiede un servizio del kernel, i privilegi aumentano al massimo livello.
	- Terminato il servizio torna in **User Mode**.
# User Space e Kernel Space
**User Space**:
- Insieme di indirizzi di memoria accessibili ad una applicazione.
**Kernel Space**:
- Insieme di indirizzi di memoria accessibili al kernel.
### Livelli di privilegio nelle CPU Intel
![[Pasted image 20241014113049.png|350]]
**Ring 0**: kernel mode.
**Ring 3**: user mode.
# Chiamata di sistema
È l'unico meccanismo con cui una applicazione può richiedere un servizio al kernel.
1. Salvataggio registri.
2. Commutazione user -> kernel.
3. Esegue una funzione di servizio.
4. Copia opzionalmente dati in memoria utente.
5. Commuta kernel -> user.
6. Ripristino registri ed esecuzione programma.
## Passaggio di parametri
Una chiamata di sistema accetta al più sei parametri.
Se ne servono di più, occorre usare un parametro come puntatore ad una struttura dati.
Il passaggio dei parametri avviene tramite registri.
Il registro **eax** contiene sempre un identificatore numerico della chiamata di sistema.
### Ingresso in Kernel Mode
- **Fino a Pentium**: Si è usata una interruzione software (*trap*), precisamente la 128 (*int 0x80*).
- **Da Pentium 2**: Si usa l'istruzione assembly `sysenter`, ben più performante della eccezione.
Ora si esegue la una funzione di servizio kernel `system_call()`. Per invocare la vera e propria funzione di servizio, che ha solitamente il prefisso `sys_`.
Se ad esempio si invoca la chiamata di sistema `getpid()`, da qualche parte nel kernel esiste una funzione `sys_getpid()`.
### Ritorno in User Space
Il valore di ritorno della funzione di lavoro è memorizzato nel registro **eax**, **rax** a 64bit.
Se si è usata l'istruzione `sysenter` per entrare in kernel mode, si usa ora l'istruzione `sysexit`.
## La libreria del C
Linux usa una libreria wrapper per facilitare l'accesso ai servizi del kernel: la libreria del C (**GNU C Library**).
![[Pasted image 20241014114543.png]]
***
# T4 - Struttura di un SO
# Stratificazione
Un SO moderno è concepito per *strati* software successivi impilati uno sopra l'altro.
L'insieme degli strati forma uno *stack software*.

Uno strato contiene l'implementazione delle funzione e delle strutture dati atte a fornire la funzionalità necessaria allo strato superiore.
Implementazione in due possibili modi:
- *Software*: libreria (statica o dinamica)
- *Hardware*: chip (ROM, EEPROM)
![[Pasted image 20241014144936.png]]
## Vantaggi
### Modularità
- **Nello sviluppo**: Il primo strato può essere progettato senza alcuna considerazione per il resto del sistema. Il secondo strato si appoggia sulle funzioni del primo.
- **Nel debugging**: In un sistema ad $m$ strati, se i primi $m-1$ sono corretti ciò implica che l'eventuale errore stia nell'$m-m_{n}$ strato.
## Svantaggi
- Divisione degli strati, dove inizia e finisce uno strato?
- Riduzione dell'efficienza: ritardo nella fruizione del servizio. La funzione a strato $m$ ci mette di meno ad essere "servita" rispetto ad una funzione nello strato $m-m_{n}$.
# Macro, Micro, Hybrid Kernel
## Macro Kernel (o monolitico)
I servizi vengono eseguiti in kernel mode. Le funzionalità essenziali del kernel sono contenute in una singola immagine eseguita al boot della macchina.
L'insieme delle applicazioni viene eseguito in user mode.
- Kernel Unix-Like (Linux, BSD, AIX, System V)
**Vantaggi**:
- Esecuzione dei servizi rapida (user -> kernel / kernel -> user)
**Svantaggi**:
- Forte fragilità: un crash del kernel pianta la CPU.
- Dimensione kernel enorme, possibile riduzione di prestazioni.
![[Pasted image 20241014151511.png|500]]
### Dimensione della code base di UNIX
Con l'aumentare dei servizi, il kernel dei sistemi UNIX è cresciuto notevolmente.
- Problemi funzionali
- Problemi di sicurezza
- Problemi prestazionali
Hanno portato all'uso di **moduli caricabili**, adozione dell'architettura basata su **Micro kernel**.
**Moduli caricabili**: file oggetto contenente funzionalità del kernel (file system, driver di dispositivi, algoritmi di schedulazione, ...). (Dis)attivabile a tempo di esecuzione (a mano oppure automaticamente).
- Linux, FreeBSD, Mac OS X
#### Vantaggi
- Modularità: I vari componenti del sistema operativo, come i driver di dispositivi o le funzionalità di rete, sono separati in moduli che possono essere aggiunti o rimossi in fase di esecuzione.
- Flessibilità: I moduli possono essere caricati solo quando necessari.
- Migliore gestione delle risorse: kernel più leggero.
- Se un modulo crasha non compromette l'intero sistema.
#### Svantaggi
- Sicurezza: può introdurre rischi di sicurezza, poiché caricare moduli non sicuri potrebbe compromettere il sistema operativo.
- Lieve perdita di prestazione dovuta alla attivazione e disattivazione dei moduli durante l'esecuzione.
## Micro Kernel
Il kernel esegue solo i servizi essenziali. Il resto è eseguito sotto forma di server applicativo.
Il kernel diventa un *sistema di messaggistica* per i server, scheduler CPU e allocatore di memoria.
- Tru64 UNIX, Mach, Minix
### Vantaggi
- Estendibili: nuovo servizio -> nuovo server, il kernel non è toccato.
- Kernel minimale, CPU cache friendly.
- SO robusto rispetto ai crash (muore il server, si ripara, se ne lancia una nuova istanza; nel frattempo, il SO continua ad eseguire).
### Svantaggi
- Meno performante.
- Presenza di commutazioni user -> kernel e kernel -> user per ogni chiamata di sistema e messaggio scambiato fra server.
![[Pasted image 20241014153028.png|500]]
## Hybrid Kernel
Micro Kernel, ma i driver dei dispositivi eseguono in kernel mode.
Tentativo di combinare il meglio dei Macro e dei Micro kernel. Funzionalità, prestazioni e sicurezza si collocano come intermedie fra Macro e Micro kernel.
- Windows, Plan 9, OS X
![[Pasted image 20241014153157.png|500]]
![[Pasted image 20241014153231.png]]
***
# T5 - Processi
Il kernel di un SO deve saper gestire processi:
**Multiprogrammati**: Più applicazioni in esecuzione contemporaneamente.
**Multiutente**: Più utenti possono usare la macchina contemporaneamente.
**Time sharing**: “Piccole” porzioni di applicazione eseguite sequenzialmente.
**Astrazione** = _processo_
## Processo vs programma eseguibile
**Programma eseguibile**: file memorizzato su supporto secondario, contiene codice macchina da eseguire, alcune aree dati, una tabella di simboli utile per il debugging. Non va in esecuzione da solo.
**Processo**: la rappresentazione del kernel (in termini di strutture dati e funzioni di gestione) di un programma eseguibile *in esecuzione*.
### Rappresentazione
**Strutture dati**: Rappresentazione di uno *“stato interno”* (Bloccato? In esecuzione? Terminato?). Puntatori alle risorse in uso.
**Funzioni di gestione**: Creazione e terminazione. Esecuzione di un eseguibile. Comunicazione, sincronizzazione.
### PID
L'**identificatore di processo** è un numero *univoco* assegnato dal kernel a ciascun processo creato.

In quali stati si può trovare un processo?
**In esecuzione**: codice in esecuzione dal processore.
**Bloccato**: in attesa di un evento.
**Pronto**: si è verificato un evento ed il processo è pronto a proseguire/iniziare la sua esecuzione.
**Terminato**: terminato il codice da eseguire, `free()` della memoria e distruzione del processo.
# Automa
### Automa a stati finiti (DFA)
L'evoluzione fra stati si rappresenta mediante un automa a stati finiti deterministico (Deterministic Finite Automaton).
![[Pasted image 20241017150639.png]]
## Differenze in Linux
- *Esecuzione*: non vi è differenziazione fra processo “pronto” ed “in esecuzione”. Entrambi sono catturati da un unico stato, `TASK_RUNNING`.
- *Comunicazione*: un processo può comunicare con altri tramite la ricezione e l'invio  di segnali.
	- `ctrl-C` segnale di interruzione. Se il processo sta ricevendo dati da una periferica ed esce così, può lasciare il kernel in uno stato inconsistente. L'attesa è gestita da due stati: interrompibile mediante un segnale (`TASK_INTERRUPTIBLE`) e non interrompibile (`TASK_UNINTERRUPTIBLE`).
- *Sincronizzazione*: Un processo può crearne un altro ed aspettare (wait) che esso termini. Quando il processo creato termina, salva il suo stato di uscita in una struttura dati, in modo tale che il processo creante possa leggerlo.
	- `EXIT_ZOMBIE`: il processo creato è morto ma le sue risorse non sono ancora deallocate.
	- `EXIT_DEAD`: il processo creato è morto e il creante ha letto il suo stato di uscita. Le sue risorse possono essere deallocate.
- *Debugging*:
	- `TASK_STOPPED`: il processo è stato stoppatoil processo è stato stoppato.
	- `TASK_TRACED`: il processo è tracciato da un debugger.
![[Pasted image 20241017151210.png]]
## Descrittore di processo
Al momento della creazione di un processo, il kernel del SO crea una struttura dati detta **Process Control Block** (**PCB**) che contiene:
- Informazioni di stato.
- Puntatori alle risorse prenotate.
In Linux, il descrittore dei processi è definito nella struttura dati `struct task_struct`.
## Funzionalità di base
### Creazione di processi
Un processo può creare altri processi. Il meccanismo di creazione è una vera e propria *clonazione* (**forking**).
Processo *clonante* -> processo *padre*.
Processo *clonato* -> processo *figlio*.
Il processo figlio è una copia identica del processo padre. Entrambi i processi ripartono dall'istruzione successiva alla clonazione.
Nei sistemi UNIX si usa la chiamata di sistema `fork()` per creare una copia esatta di un processo. In Linux, è implementata dalla funzione di servizio `do_fork()`.

> [!NOTE] Come si distingue padre e figlio?
> `fork()`ritorna un valore mutevole.
> Nel processo padre: il PID del processo figlio.
> Nel processo figlio: 0.
> Errore: -1.

Nei SO UNIX l'organizzazione dei processi è ad *albero*. Un processo iniziale (*init*) è creato “a mano” dal kernel. Esso ha sempre PID = 1. Tale processo fa partire i servizi forniti dal computer tramite fork and exec. Fra i servizi vi è `getty` (gestore login su console).
Al termine del login, `getty` fa partire una shell (`bash`). La shell esegue un comando impartito dall'utente (`ls`).
![[Pasted image 20241017153559.png]]
## Esecuzione di programmi eseguibili
`fork()`non carica altri programmi. Il caricamento è gestito dalla chiamata di sistema `execve()`. Essa “sostituisce” in maniera efficiente le aree di codice e dati di un processo.
### Usi buoni del forking
Comandi composti in pipeline.
```bash
find . -name \*.c | wc -l
```
Server multiprocesso (Web, FTP, SSH, ...).
![[Screenshot 2024-10-17 alle 15.39.33.png|300]]
### Usi cattivi del forking
**Fork bomb**: tipo di processo che non fa altro che riprodurre processi figli, i quali a loro volta si riproducono. Meccanismo rozzo ma efficace di negazione del servizio (**Denial of Service**, **DoS**). Ogni processo consuma risorse e contribuisce al rallentamento della macchina.
Bash:
```bash
:(){ :|:& };:
```
C:
```c
while(1)
	fork();
```
La chiamata di sistema `exit()` termina un processo in maniera pulita.
Mette il processo in stato `EXIT_ZOMBIE`.
Attende la lettura del codice di uscita da parte del padre.
Mette il processo in stato `EXIT_DEAD`.
Rilascia le risorse.
Distrugge il PCB.
Schedula l'esecuzione di un altro processo.

Se un processo genitore termina, tutti i suoi figli diventano *orfani*.
**Reparenting**: processo orfano diventa figlio del processo `init`.
## Gruppi di processi e sessioni
Ogni comando dato all'interprete della shell crea un **gruppo** di processi, individuato da un *identificatore di gruppo* (*Process Group IDentifier* **PGID**) pari al PID del primo processo nella pipeline (detto *process group leader*).
In questo modo è possibile inviare un segnale (e anche uccidere) a tutti i processi coinvolti in un comando.
```bash
ls -al | grep .bash | less -Mr
```
Una **sessione** è un insieme di gruppi di processi che condividono un terminale.
Una sessione è individuata da un *ID di sessione* (*session ID*, **SID**). Il SID è il PID del processo *session leader* che crea la sessione tramite `setsid()`.
### Gruppo in foreground e background
Un solo gruppo di processi può leggere dal terminale. Tale gruppo prende il nome di **foreground process group**. Gli altri gruppi di processi sono lanciati come **background process group**.
Lancio in *Background*:
```bash
ls -lR / > out.txt 2>err.txt &
```
Lancio in *Foreground*:
```bash
ls -lR / > out.txt 2>err.txt
```
**Esempio sessione**:
![[Pasted image 20241017155510.png]]
## Rappresentazione PID, PGID, SID
![[Pasted image 20241017155550.png]]
***
# T6 - Scheduling e dispatching
## Caratterizzazione dei processi
Durante la sua esecuzione, un processo si alterna in due fasi:
- **CPU Burst**: elaborazione user o kernel.
- **Wait**: attesa di I/O o evento.
Un processo si dice *vincolato* (**bound**) ad una *risorsa* (**resource**) o ad un *evento* (**event**) se la sua prestazione è correlata alla disponibilità della risorsa o al verificarsi dell'evento.
### Alcuni esempi di programmi
**CPU**: `factor` che fattorizza un numero intero è vincolato alla CPU.
**Disco**: `dd` che trasferisce dati a blocchi da/verso periferiche è vincolato al disco.
**Rete**: `wget` che scarica documenti dal web è vincolato dal collegamento alla rete.
## Vincoli di interesse: CPU-bound e I/O-bound
Il comportamento di un processo si posiziona tra:
- **Processo CPU-bound**:
	- Tende a produrre poche sequenze di CPU burst lunghe.
	- Tende a fare poche richieste di I/O.
- **Processo I/O-bound**:
	- Tende a produrre tante sequenze di CPU burst brevi.
	- Tende a fare molte richieste di I/O.
![[Pasted image 20241021155310.png]]
### Quali processi sono più importanti?
**Sistema desktop**: caratterizzato da *elevata interattività* con l'utente. Tale interattività si estrinseca in richieste di I/O a periferiche (terminale, disco, rete).
Si dovrebbero favorire i processi I/O-bound rispetto a quelli CPU-bound.
**Sistema di calcolo batch**: Duale del sistema desktop: interattività pressoché inesistente, necessità di completare quanti più processi di calcolo possibile. Si preferiscono i processi CPU-bound.
Il **grado di multiprogrammazione** è la somma di:
- $n$ processi in esecuzione.
- $n$ di processi pronti per l'esecuzione.
$n$ dipende da:
- frequenza con cui un utente fa partire processi.
- frequenza con cui i processi escono.
### Obiettivi del gestore dei processi
Reggere il grado di multiprogrammazione imposto dall'utente senza degradare le prestazioni proprie e dei processi.
Favorire i processi “giusti” per il tipo di SO considerato:
- Desktop $\rightarrow$ I/O-bound.
- Server $\rightarrow$ CPU-bound.
Come si raggiungono questi obiettivi?
**Schedulatore dei processi**: sceglie il prossimo processo da eseguire in maniera consona al tipo di SO in esecuzione.
**Dispatcher**: sostituisce in maniera efficiente il PCB del processo attuale con il PCB del processo scelto dallo schedulatore.
# Schedulatore
### Scenario
Un processo in kernel mode ha appena programmato il DMA controller per eseguire una operazione di I/O (lettura). La lettura è bloccante ed il processo non può più proseguire l'esecuzione fino all'ottenimento del dato.
Per non lasciare il processore inattivo, deve essere scelto e ripristinato un nuovo processo. Qui entra in gioco lo schedulatore, invocato dalla `sys_read()` (o chi per lei).
Lo schedulatore dei processi sceglie un processo ritenuto idoneo per l'esecuzione. Possibili criteri:
- È importante (priorità alta).
- Non esegue da tanto tempo.
- Scelto a caso.
- Scelto circolarmente.
Lo schedulatore invoca il dispatcher per sostituire il PCB del processo in esecuzione con il PCB del nuovo processo. A questo punto, il processo B è pronto per continuare l'esecuzione.
**Quando schedulare?**
1. Un processo si blocca in attesa di un evento.
2. Un processo termina l'esecuzione.
Altrimenti il processo rimane *inattivo*.
## Prelazione
*Il kernel strappa con forza la CPU ad un processo*, l'atto di interrompere momentaneamente un processo troppo avido di CPU a favore di un altro che sta aspettando l'esecuzione.
Lo schema precedentemente visto non ha prelazione. Un processo CPU-bound può provocare starvation di altri processi.
![[Pasted image 20241021164840.png|500]]
### Scheduling con prelazione
Quando?
1. Un processo si blocca in attesa di un evento.
2. Un processo termina l'esecuzione.
3. È stato creato un nuovo processo.
4. Un processo è interrotto.
5. Un processo passa dallo stato bloccato allo stato pronto.
### Scheduling in Linux
È con prelazione. Implementato dalla funzione `schedule()`, definita in `$LINUX/kernel/sched/core.c`:
- Sceglie le `task_struct()` di un nuovo processo.
- Salva lo stato del processo attuale nella sua `task_struct`.
- Ripristina nei registri lo stato del nuovo processo.
- Salta alla prossima istruzione utile del nuovo processo.

La funzione `schedule()` è invocata nelle seguenti occasioni:
- Blocco dovuto da I/O.
- Blocco dovuto ad evento di sincronizzazione.
- Al termine di una chiamata di sistema.
- Al termine di un gestore delle interruzioni.

Lo scheduler non rischedula per forza, solamente se forzato dagli eventi (ad esempio, se un processo a priorità più elevata è pronto).
Il kernel usa un flag (`TIF_NEED_RESCHED`) della `task_struct` del processo in esecuzione per segnalare la necessità di rischedulare.
Il kernel controlla se è il flag è impostato mediante la funzione `need_resched()`definita in `$LINUX/include/linux/sched.h`. Se la funzione ritorna 1 (TRUE) allora viene invocata la `schedule()`, altrimenti no.
## Funzioni rientranti
**Dati di fatto**:
- Le macchine moderne sono multiprocessore.
- I SO moderni sono multiutente e time sharing.
- Le operazioni di I/O sono gestite in maniera asincrona tramite DMA e interruzioni.
**Conseguenza inevitabile**:
- **Funzione rientrante**: funzione del kernel può essere invocata di nuovo prima del termine di una sua precedente invocazione.
## Rientranza di `schedule()`
In questo istante, la funzione schedule() non è ancora terminata. La sostituzione dei processi provoca un salto diretto al processo B.
![[Pasted image 20241021164942.png|500]]
$$
\text{A}\  \xrightarrow{\text{sys\_read()}} \text{I/O DMA} \ \xrightarrow{\text{schedule()}} \text{Schedulatore} \longrightarrow \text{B}
$$
All'arrivo della richiesta di interruzioni da parte del disco, parte il gestore delle interruzioni. Al termine della sua esecuzione, lo schedulatore dei processi rischedula, nel caso, il processo A.
![[Pasted image 20241021165610.png|500]]
Notare come `schedule()` sia stata nuovamente invocata prima che la precedente istanza di `schedule()` sia terminata.
Al termine della `schedule()`, il controllo è ritornato alle funzioni invocate dalla chiamata di sistema `sys_read()`.
### Vantaggi della rientranza
Il kernel esegue in maniera più efficiente su architetture [SMP](https://it.wikipedia.org/wiki/Sistema_multiprocessore_simmetrico). 
### Svantaggi della rientranza
Le funzioni devono essere progettate in modo tale da essere eseguibili contemporaneamente:
- L'accesso a variabili globali va evitato come la peste, se possibile.
- Se proprio non si riesce ad evitare l'accesso a variabili globali, tale accesso deve essere serializzato.
La sua esecuzione su più CPU va impedita per evitare corruzione sui dati.
### Idle task
Se nessun processo è in grado di eseguire, il kernel esegue un processo speciale detto *swapper* o *idle task*.
- PID = 0
- Mette in idle il processore.
## Cambio di contesto
Lo scambio di due processi prende il nome di *cambio di contesto* (**context switch**).
*Contesto*: contenuto del PCB.
Operazioni svolte:
- Salvataggio del contesto del processo attuale.
- Ripristino del contesto del nuovo processo.
Il cambio di contesto impiega 1μs – 1ms (in base all'architettura hardware).
### Hop al nuovo processo
Uno dei campi contenuti nel contesto è il registro **Instruction Pointer**. Se tale registro fosse ripristinato per ultimo, la CPU salterebbe automaticamente alla prossima istruzione della nuova traccia. Nella sostanza, il salto avviene proprio così.
**Problema**: un processo appena creato (`fork()`) deve essere inizializzato prima di poter eseguire la prima volta.
Si usa un piccolo trucco:
- `push` sullo stack l'indirizzo della prossima istruzione da eseguire.
- `jump`(`JMP`) ad una funzione in cui vengono effettuati gli ultimi preparativi.
- La funzione invocata esegue un `return` (`RET`).
- L'*Instruction Pointer* è caricato con l'ultimo valore presente sullo stack (l'indirizzo desiderato).
La macro `switch_to()`, definita in `$LINUX/arch/x86/include/asm/switch_to.h` implementa questa variante.
La funzione inizializzatrice è: `ret_from_fork()`.
***
# T7 - Algoritmi di scheduling
Il kernel deve assegnare una risorsa ad $n$ entità che la vogliono accedere.
Come vengono assegnate le richieste alle risorse?
## Lo scheduler
Gestisce l'accesso alle risorse:
**Accodamento**: le richieste sono ricevute e "parcheggiate".
**Algoritmo**: una richiesta è scelta dalla coda.
**Dispatching**: la richiesta è assegnata alla risorsa.
![[Pasted image 20241024163636.png]]
**CPU scheduling**: scelta del prossimo processo da eseguire.
- *Entità*: processi
- *Risorsa*: CPU
**Job scheduling**: scelta del prossimo job da eseguire.
- *Entità*: job
- *Risorsa*: CPU
**I/O scheduling**: scelta della prossima richiesta di disco (lettura/scrittura) da soddisfare.
- *Entità*: richieste di I/O
- *Risorsa*: disco
**Memory scheduling**: scelta di una pagina di memoria da spostare in swap.
- *Entità*: pagine di memoria
- *Risorsa*: memoria
## Scheduling con e senza prelazione
**Con prelazione**: lo scheduler interrompe la fruizione della risorsa da parte di un utente per favorirne un altro.
**Senza prelazione**: lo scheduler non interrompe la fruizione della risorsa. L'utente continua ad usufruire della risorsa fino a quand:
- non termina la sua funzione
- non necessita di un'altra risorsa
### Scheduling senza prelazione
**Scheduling cooperativo**: l'utente può decidere di assegnare la risorsa direttamente ad un altro utente, tramite lo **yielding**.
**Scheduling non cooperativo**: l'utente non influisce sulle scelte decisionali dello scheduler.
## Modello senza prelazione
I processi non effettuano richieste ad altre risorse. Non esiste prelazione.
![[Pasted image 20241024164530.png|500]]
Un **indice di prestazione** indica il livello di prestazione di un componente hw/sw. Nel caso di uno scheduler di CPU si considerano:
- *Attesa di un processo*
- *Produttività dello scheduler*
- *Utilizzo del processore*
### Processi in coda
Il *numero di processi accodati* in un'istante $t=t_{1}$, misura il numero di processi precedenti al nostro processo accodato.
Il *tempo di attesa in coda* indica l'intervallo temporale tra l'ingresso in coda e l'associazione al processore(tempo in coda è tempo di "congestione" del processore).
*Tempo di completamento*: somma dei tempi di attesa in coda e. di servizio $T_{C} = T_{w} + T_{S}$, misura l'attesa complessiva di un processo.
![[Pasted image 20241024170513.png|500]]
**Latenza**: intervallo temporale fra l'ingresso di un processo in coda ed il calcolo del primo byte della risposta utile all'applicazione: $T_{R} = T_{2}-T_{1}$, misura l'attesa di un processo ad iniziale la sua elaborazione e lo stato di congestione del processore. L'attesa percepita dall'utente.
![[Pasted image 20241024170723.png|500]]
**Throughput**: numero di processi portati a termine da uno scheduler nell'unità di tempo $X = \frac{N}{t_{2}-t_{1}}$, misura la produttività dello scheduler.
![[Pasted image 20241024170911.png|500]]
**Utilizzatore**: frazione di tempo in cui il processore è occupato ($T_{occ}$) in un dato intervallo $(T_{mis}): p=\frac{T_{occ}}{T_{mis}}$, misura l'utilizzo del processore.
## Modello con prelazione
Si deve prevedere il rientro di un processo nella coda di attesa, un processo può subire più attese in coda e ricevere più volte servizio dal processore.
![[Pasted image 20241024171233.png|500]]
### Throughput vs. Latenza
Sono *obiettivi contrastanti*:
- Uno scheduler ad alto throughput serve tutto ciò che si presenta in coda $\rightarrow$ Non si fa distinzione fra processi $\rightarrow$ interattivi e non La latenza di tali processi aumenta.
- Uno scheduler a bassa latenza tende a scegliere i processi interattivi $\rightarrow$ Gli altri processi non avanzano $\rightarrow$ Il throughput dello scheduler cala.
# Algoritmi di base
## First come, first served
Opera *senza prelazione*, un processo esegue fino all'I/O o alla fine.
![[Pasted image 20241024171956.png|500]]
![[Pasted image 20241024172024.png|500]]
**Vantaggi**:
- semplice
- eseguibile su piattaforme non dotate di clock hardware
- non implementa prelazione
	- i processi non devono essere interrotti bruscamente
	- non serve un timer per avviare periodicamente il meccanismo di interruzione
**Svantaggi**:
- Attesa non minima, varia al variare della composizione dei processi
- senza prelazione, monopolizza il processore e stalla l'esecuzione degli altri processi(starvation)
## Shortest job first
Opera *senza prelazione*, un processo esegue fino all'I/O o alla fine.
![[Pasted image 20241024172501.png|500]]
![[Pasted image 20241024172600.png|500]]
**Vantaggi**:
- In assenza di prelazione, si può dimostrare che SJF è l'algoritmo di scheduling che fornisce tempo di attesa medio minimo.
	- Dati $n$ processi $P_{1},P_{2},\dots,P_{n};$
	- $R_{W}(P_{j})$ tempo di attesa del processo $P_{j}$;
	- $T_{W}=\left( \frac{1}{n} \right) \times [T_{W}(P_{1})èT_{W}(P_{2})+\dots+T_{W}(P_{n})]$ tempo medio di attesa dei processi al termine della schedulazione.
	- $T_{W}$ minimo fra tutti gli scheduler senza prelazione.
**Svantaggi**:
- Richiede la conoscenza della durata del prossimo CPU burst di ciascun processo, va stimata.
- Lo scheduler eseguito non è SJF, bensì un “simil-SJF” con stima dei CPU burst.
- SJF considera l'intera durata del processo. Tuttavia, in uno scheduler con prelazione, i processi sono eseguiti “per piccoli pezzi” e le durate residue divergono rapidamente dalla durata iniziale.
	- L'informazione su cui fa conto SJF diventa molto rapidamente obsoleta.
### Stima durata prossimo CPU burst
**Media esponenziale** $\tau_{n}$ dei CPU burst passati e presente.
$$
\tau_{n+1} = a \times \tau_{n} + (1-a) \times \tau_{n}, a \in [0,1]
$$
$a$ "tara" il quantitativo di storia passata da prendere in codiserazione.
$$
\begin{align}
&a=0 \text{ valore recente non ha effetto} \\
&a=1 \text{ assenza di storia} \\
&a=\frac{1}{2} \text{ stesso peso per valore recente e storia passata}
\end{align}
$$
![[Pasted image 20241024173413.png|400]]
## Shortest remaining time first
Opera *con prelazione*, un processo può essere interrotto dallo scheduler.
![[Pasted image 20241024173953.png|500]]
$P_{1}$ viene eseguito, a $t_{2}$ arriva $P_{2}$ che, avendo un tempo residuo minore di $P_{1}$, $P_{1}$ torna in coda($P_{1} = 7 < P_{2} = 4$).
![[Pasted image 20241024174200.png|500]]
$P_{3}$ e $P_{4}$ si accodano, al termine di $P_{2}$ viene eseguito $P_{4}$, quello con il tempo residuo minore ($5_{P_{4}} < 7_{P_{1}} < 9_{P_{3}}$).
![[Pasted image 20241024174542.png|500]]
Ora vengono eseguiti $P_{1}$ e $P_{3}$ che termina l'esecuzione.
**Vantaggi**:
- Diminuisce il tempo di attesa medio rispetto a SJF.
**Svantaggi**:
- Richiede la conoscenza della durata del CPU burst residuo di ciascun processo, va stimata.
- Lo scheduler eseguito non è SRTF, bensì un “simil-SRTF” con stima dei CPU burst.
## Priority
Opera *con o senza prelazione*.
![[Pasted image 20241024174845.png|500]]
Vengono eseguiti in base al valore della *priorità*: $1 \to 5$.
![[Pasted image 20241024174945.png|500]]
**Vantaggi**:
- Favorisce i processi ritenuti più importanti. Tale modo di operare è fondamentale nei sistemi interattivi.
	- **Processo importante**: processo che interagisce “spesso” e direttamente con l'utente.
**Svantaggi**:
- È soggetto a starvation dei processi. Nella simulazione ora vista, $P_{4}$ ha tempo di attesa pari a 18 $\rightarrow$ starvation. Se $P_{4}$ fosse un terminale, stallerebbe per lungo tempo e l'utente non riuscirebbe ad interagire con il SO.
Gli scheduler con priorità necessitano di un ulteriore meccanismo per combattere l'attesa indefinita.
**Aging**: aumento graduale della priorità dei processi in attesa da lungo tempo.
Il valore della priorità può essere definito in due modi:
- **Internamente**: dal SO in vase a grandezze misurabili.
	- Limiti di tempo, memoria, CPU burst.
	- Rapporto (avg I/O burst) / (avg CPU burst).
- **Esternamente**: in base a criteri esterni al SO.
	- Si associa ad ogni processo una priorità.
	- Sistemi UNIX: valore intero in $[-20, 19]$ (più è basso, più è alta la priorità).
## Round Robin
Opera *con prelazione*, un processo può essere interrotto dallo scheduler.
Ogni esecuzione è quantificata in un tempo detto *quanto*, al termine del quanto, si passa al processo successivo, rimettendo in coda il processo se non completato.
![[Pasted image 20241024175652.png|500]]
![[Pasted image 20241024175715.png|500]]
**Vantaggi**:
- Fornisce generalmente attese molto basse.
- Con $n$ processi ed un quanto di tempo pari a $q$, l'attesa di un processo è limitata superiormente a:
$$
(n-1) \cdot q
$$
**Svantaggi**:
- Fornisce tempi di completamento di processi CPU-bound più lunghi rispetto a FCFS.
	- FCFS esegue i CPU burst “in toto”, fino alla fine, mentre RR si alterna fra processi.
### Quanti di tempo fissi e variabili
**Quanto fisso**: scelto una volta per tutte e non cambia mai. È molto semplice da gestire, ma un quanto fisso non va mai bene per tutte le categorie di processi.
**Time slice variabile**: il kernel calcola dinamicamente l'intervallo massimo di esecuzione, in funzione della tipologia di processo e della sua priorità di esecuzione.
### Impatto del quanto sulle schedulazioni
Il tempo di completamento medio tende a diminuire se la maggior parte dei processi finisce il CPU burst entro lo scadere del quanto.
**Regoletta empirica**: l'80% dei processi dovrebbe avere CPU burst minori del quanto.
# Scheduling multilivello
## Categorizzazione dei processi nei SO moderni
**Processi interattivi** (*foreground*): devono andare in esecuzione il più presto possibile.
**Processi non interattivi brevi** (*background*): devono andare in esecuzione meno spesso degli interattivi.
**Processi non interattivi lunghi** (*batch*): vanno in esecuzione solo se non ne esistono di interattivi e non interattivi brevi.
È necessario saper schedulare prima i processi appartenenti alle classi più importanti.
## Scheduler multilivello
Si usano più code, una per ogni categoria di processi.
![[Pasted image 20241024180659.png|500]]
1. sceglie la code da cui pescare un processo.
2. sceglie un processo dalla coda, associando diversi livelli di priorità(fissi) alle code. Si sceglie la coda a priorità più alta in cui è presente un processo.
![[Pasted image 20241024180942.png|500]]
Dopo l'esecuzione, il processo è inserito di nuovo nella stessa coda da cui proviene.
**Esempio**:
Si suddivide la coda di pronto in cinque code distinte, con priorità decrescente in termini di importanza.
1. Processi di sistema (RR).
2. Processi interattivi (RR).
3. Processi interattivi di editing (RR).
4. Processi in background (FCFS).
5. Processi batch degli studenti di laboratorio (FCFS).
![[Pasted image 20241024181136.png|500]]
**Vantaggi**:
- I processi importanti sono serviti per prima, essendo incanalati nelle code a priorità più alta.
	- Per tali processi, la latenza è molto bassa.
**Svantaggi**:
- I processi non importanti soffrono di starvation.
	- Per tali processi, non vi è garanzia sulla latenza.
	- È necessario integrare lo scheduler con un meccanismo di aging.
- Se la natura del processo(CPU-bound, I/O-bound) è variabile nel tempo, lo scheduler multilivello non è efficace.
## Scheduler multilivello con retroazione
È una variante dello scheduler multilivello in cui il processo può rientrare in una coda diversa da quella in cui si trovava precedentemente.
La retroazione tende a raggruppare i processi con caratteristiche di CPU burstiness simili simili nelle stesse code.
- Processi con CPU burst lunghi si muovono verso le code a priorità più bassa.
- Processi con CPU burst brevi si muovono verso le code a priorità più alta.
La retroazione è tanto più efficace quanto meno frequente è il cambio di natura dei processi.
**Esempio**:
Si usano tre code di scheduling di priorità 0, 1, 2.
0. Round Robin con quanto 8
1. Round Robin con quanto 16
2. FCFS
Se un processo non finisce entro il suo quanto assegnato, viene spostato nella coda successiva. Se per 10 volte il processo non esaurisce il suo quanto di tempo, viene spostato nella coda precedente.
Quindi:
- I processi con CPU burst brevi (I/O bound, interattivi con il terminale) sono serviti molto rapidamente.
- I processi con CPU burst un po' più lunghi sono serviti rapidamente.
- I processi con CPU burst lunghi (batch) sono serviti solo se il sistema non è altrimenti impegnato.
Un sistema con CPU burst variabile si adatta lentamente alla sua coda ottimale.
![[Pasted image 20241024181743.png|500]]
# Scheduling in sistemi SMP
## Coda di pronto globali
**Coda globale**: unica coda di pronto condivisa da tutti i processori.
**Coda di pronto distribuita per CPU**: ne esiste una per ogni processore della macchina.
- Lo scheduler può operare su più code allo stesso istante.
- Non esistono ritardi dovuti a uso non corretto delle cache del processore.
- Soluzione preferita dai SO moderni su architetture SMP.
Come bilanciare i processi sulle diverse code?
## Predilezione
**Predilezione** (*CPU affinity*): lo scheduler dei processi cerca di eseguire il processo sempre sullo stesso processore.
**Predilezione debole** (*soft affinity*): lo scheduler rischedula il processo sempre sulla stessa CPU, a meno di un bilanciamento delle code di scheduling.
- scheduler di Linux
**Predilezione forte** (*hard affinity*): l'utente impone che il processo esegua sempre su una data CPU.
### Bilanciamento del carico
Per bilanciare il carico della predilezione i processi vengono spostati (*migrati*) da un processore all'altro, in modo che il carico sui processori sia simile.
Attenzione a bilanciare troppo spesso, *il bilanciamento annulla i benefici della predilezione*.
**Migrazione guidata**(*push migration*): un processo dedicato controlla periodicamente la lunghezza delle code. In caso di sbilanciamento, sposta i processi in modo da bilanciare il carico.
**Migrazione spontanea**(*pull migration*): o scheduler sottrae un PCB ad una coda sovraccarica.
***
# T8 - File System
## File: Rappresentazione e accesso
Nei SO moderni le informazioni possono essere memorizzate in maniera strutturata e permanente su supporto secondario
Un **file system** è una gerarchia di *directory* e *file*, ospitata su un dispositivo di memorizzazione secondaria.
- **File**: sequenza di byte memorizzata su supporto secondario.
	- struttura di controllo che memorizza le proprietà durevoli.
	- insieme di blocchi di dati.
Il **File Control Block** è la struttura che memorizza le proprietà durevoli di un file. Memorizza su disco:
- Proprietario.
- Date notevoli (creazione, ultimo accesso, modifica).
- Dimensione.
- Permessi di accesso.
- Puntatori a blocchi di dati.
Per recuperare questi metadati si usa:
```c
int stat(const char *path, struct sttat &buf);
```
In GNU/Linus, la chiamata `stat()` ritorna una struttura dati contenente i metadati di un file.
### Estensioni
I file possono essere classificati in *tipi*, in modo da assegnare ad essi una applicazione di default che li possa gestire. Il SO li riconosce attraverso una *estensione* e una analisi del contenuto del file.
`<nome_file><separatore><estensione>`
Il meccanismo più semplice di riconoscimento del tipo del file è la **associazione diretta**. Il SO legge l'estensione del file e gli associa automaticamente una applicazione adatta.
Ciascuna applicazione gestisce una lista di estensioni gradite.
- LibreOffice -> `.doc`, `.odt`, `.docx`
Ciascun file è riconoscibile da una o più sequenze di byte (dette **magic number**) in offset strategici.
- `.elf` contiene i caratteri 'E', 'L', 'F' nel secondo, terzo e quarto byte.
I magic number sono salvati su un file locale detto **magic file**: `/usr/share/file/misc/magic`.
Il comando `file` (UNIX, linea di comando) scandisce un file alla ricerca dei magic number, fino a quando non ne trova uno corretto.
```bash
file file.txt
file.txt: ASCII text, with very long lines.
```
In GNU/Linux gli eseguibili sono associati ad un programma detto **caricatore**(**loader**).
- carica in memoria le librerie necessarie all'esecuzione.
- carica il programma.
- controlla se il file inizia con una riga simile (detta **she-bang**):
	- `#!/bin/bash` specifica l'interprete dello script.
	- carica l'interprete.
	- esegue l'interprete con argomento pari al nome dello script.
## File: Organizzazione interna
- Organizzazione **logica**: file acceduto per unità logiche (singoli byte, righe o record, indici).
- Organizzazione **fisica**: impacchettamento delle unità logiche nei blocchi fissi del disco.
### Impacchettamenot del file su disco
L'unità **logica** del file è mappata sulla rappresentazione **fisica** del disco(**settore**). Nel caso degli hard disk, un settore è spesso lungo 512 byte.
In un file, l'unità logica è quasi sempre di dimensione diversa rispetto al settore.
## Organizzazione logica
- Per **flussi di byte**: il file è visto come una sequenza di record logici di lunghezza pari ad 1(sequenza di byte). Non esiste una strutturazione; l'applicazione legge flussi di byte. È compito della applicazione dare un significato al flusso di byte.
- Per **record logici**: in file è visto come una sequenza di record logici di lunghezza maggiore di 1. L'applicazione legge e scrive un certo numero di record logici.
- Per **indice**: in file contiene una sequenza di record logici di lunghezza fissa. Ciascun record contiene un campo indice in una posizione fissa. L'albero è ordinato in base all'indice. Con una ricerca binaria sull'indice, si trova l'elemento $i$-mo in $O(\log n)$ passi ($n$=numero di record logici).
	- **indice doppio**: In caso di cancellazioni ed inserimenti frequenti dei record logici, diventa molto costoso mantenere ordinato il file. Si usano due file:
		- *indice*.
		- file con *record logici*.
	- **indice gerarchico**: Se il file indice cresce a dismisura, si adotta un indice multilivello.
		- *file indice primario*: punta ad un file indice seocndario.
		- *file indice secondario*: punta al record.
## Accesso ai file
- **sequenziale**: L'informazione contenuta nel file viene acceduta sequenzialmente, ossia un record dopo l'altro. Il modello considerato è quello di un *nastro*.
- **diretto**: L'informazione contenuta nel file viene acceduta per singoli blocchi fisici, direttamente (casualmente). Modello di un *disco*.
- **per indice**: L'informazione contenuta nel file viene acceduta per indice, casualmente. Modello di una **base di dati**.
Solitamente
- *accesso sequenziale* -> *organizzazione per flussi di byte*.
- *accesso diretto* -> *organizzazione per record logici*.
- *accesso per indice* -> *organizzazione per indice*.
## I/O low-level e bufferizzato
- **I/O diretto**(basso livello): le operazioni sono inviate direttamente al kernel.
- **I/O bufferizzato**: le operazioni di I/O sono gestite da un buffer intermedio. Letture e scritture sono "ritardate" fino al riempirsi del buffer.
## Buffering in GNU/Linux
- **buffering applicativo**:
	- usato dalle funzioni di libreria del C.
	- Permette operazioni di I/O con blocchi di dati,
	- Riduce chiamate di sistema → meno carico per il kernel.
	- **nessun buffer**: ha dimensione nulla.
	- **singola riga**: il buffer è considerato riempito quando raggiunge la sua massima dimensione o quando si incontra un carattere newline.
	- **buffering completo**: il buffer è considerato riempito quando raggiunge la sua massima dimensione.
- **buffer del kernel**:
	- **Caching Letture**: memorizza dati già letti in RAM → risponde a richieste successive più velocemente.
	- **Raggruppamento Scritture**: unisce più scritture in un'unica operazione (scrittura su disco più lenta) → riduce scritture frequenti e usura del disco.
**Flushing** del buffer: svuotamento del buffer, trasferiemento dei dati temporaneamente memorizzati nel buffer applicativo verso il kernel o il dispositivo di destinazione.
- **flush** svuotamento del buffer applicativo.
- **sync** svuotamento del buffer dal kernel.
## Directory
È un file contenente coppie del tipo(nome, puntatore).
Una directory può essere rappresentata mediante diversi modelli:
- **A singolo livello**: estremamente scomodo nei sistemi multiutente.
- **A due livelli**: esiste un completo isolamento fra utenti.
- **Ad albero**: è scomodo condividere file fra utenti senza copiarli; è impossibile creare “collegamenti a file”.
- **A grafo**: quello attualmente più utilizzato, il file system è modellato con un **grafo aciclico**:
	- **vertici**: directory o file.
	- **archi**: relazioni fra directory e file contenuti.
	- **vertice radice**: rappresenta la directory radice del file system (UNIX: `/`, Windows: `C:\`).
Il contenuto di un file può essere referenziato da due elementi di directory (**hard link**) distinti.
![[Pasted image 20241105161621.png|250]]
![[Pasted image 20241105162458.png|500]]
Non è possibile introdurre un ciclo nel grafo.
- Niente link a directory superiori (si creerebbe un ciclo infinito).
- `cd directory` in una directory con ciclo stallo.
Non è possibile creare un hard link ad un file in un altro file system.
- File system diversi implementazioni diverse delle → directory.
![[Pasted image 20241105162554.png|500]]
**Grafo ciclico**: simile al precedente, in questo è possibile creare link in grado di chiudere cicli (noti con il nome di **soft link**).
## Soft Link vs Hard Link
**Soft Link (o Link Simbolico)**:
- **Cross-File System**: può essere creato tra file system diversi.
- **Riferimento Diretto**: punta al percorso del file di destinazione.
- **File Mancante**: se il file di destinazione è assente (ad esempio su un supporto non inserito come un CD-ROM), il link appare rotto (colorato di rosso).
- **Supporto Directory Superiori**: può puntare anche a directory superiori o ad altre directory e file.
**Hard Link**:
- **Stesso File System**: deve risiedere nello stesso file system del file di destinazione.
- **Riferimento Indiretto**: punta direttamente all'inode del file, quindi rappresenta una copia “fisica” del file (condividendo lo stesso inode).
- **Persistenza del File**: se l’originale viene eliminato, il file rimane accessibile tramite l'hard link.
- **Non Supporta Directory**: non può essere creato per le directory, solo per file.
### Gestione cicli infiniti
**Scenario:** il comando `find` scandisce un sottoalbero di directory con un soft link alla directory di partenza. → Ciclo infinito. La gestione dei cicli infiniti è delegata alle applicazioni.
```bash
find /home/andreoli -name andreoli -follow
```
![[Pasted image 20241105163014.png|200]]
### Cancellazione di file
L'hard link di un file è un **conteggio di riferimento**. Il conteggio serve ad impedire la distruzione del contenuto di un file in presenza di utenti che ne usufruiscono. Quando si cancella un file, si decrementa di uno il conteggio degli hard link. Se il conteggio è zero, si stacca il contenuto del file dal suo FCB.
## Implementazione delle directory
1. **Hash Table + Simple List** (Usata nelle prime versioni di EXT3, EXT4):
   - **Lista Semplice**: Contiene coppie `<nome file, puntatore FCB>` (File Control Block).
   - **Tabella Hash**:
     - **Chiave**: Un hash del nome del file.
     - **Valore**: Un puntatore all’elemento corrispondente della lista.
   - **Vantaggio**: Ricerca più veloce rispetto a una lista semplice, ma meno efficiente per directory di grandi dimensioni.
2. **Binary Tree** (Usato nelle versioni attuali di EXT4):
   - **Struttura ad Albero Binario**: Organizza i nomi dei file come hash, ordinati alfanumericamente.
   - **Nodi Foglia**: Ogni nodo foglia contiene un puntatore al FCB, il quale gestisce i metadati e l’accesso al file.
   - **Vantaggio**: Migliora l’efficienza della ricerca in directory molto grandi, riducendo i tempi di accesso grazie alla struttura ad albero.
### Accesso alle directory
Mediante un **descrittore di directory** simile al puntatore allo stream usato nell'I/O bufferizzato.
È rappresentato dalla struttura `struct __dirstream` rinominata in `DIR` nella libreria del C.
Si ottiene un puntatore a tale descrittore mediante la funzione di libreria `opendir()` che, analogamente a `fopen()`, apre una directory.
## Montaggio e Smontaggio
Un file system, prima di essere utilizzato deve essere associato ad un dispositivo di memorizzazione secondaria. deve essere agganciato ad un file system esistente, usando una directory come punto di attacco.
- **File system mount** o **mount**.
- La directory di aggancio prende il nome di **mount point**.
### Opzioni di mount
- **read-only**: solo lettura.
- **sync**: le scritture sono sincrone.
- **async**: le scritture sono asincrone.
- **exec**: si permette l'esecuzione dei programmi.
Il file system può essere staccato dal suo mount point tramite l'operazione di **unmount** (umount nel gergo UNIX), sostanzialmente l'inversa di mount.
L'unmount è preceduto da un *flush* dei buffer del kernel.
### Root file system
Almeno un file system deve essere presente all'avvio del SO, affinché il mount degli altri file system sia sempre possibile. Tale file system prende il nome di **root file system** e contiene almeno il comando `init` per avviare i servizi della macchina.
***
# T9 -  Implementazione File System
# Preparazione di un dispositivo
La **formattazione a basso livello** è una procedura mediante la quale il dispositivo è preparato al primo uso (creazione di un *file system*).
La superficie del dispositivo è marcata in **settori**, la più piccola porzione indirizzabile dalla testina del dispositivo (in un HDD 512byte).
- **Preambolo**: marcatura indicante l'inizio di un settore(usato dalla testina per sincronizzarsi).
- **Error Correcting Code (ECC)**: codice per la correzione automatica di errori.
- **Intersector gap**: separazione fra settori.
## Partizionamento
Il disco può essere diviso in zone dette **partizioni**, ciascuna delle quali può ospitare:
- *file system*: ospita dati strutturati secondo un formato specifico.
- *swap partition*: spazio dedicato alla memoria virtuale per il SO.
- *raw partition*: area non formattata utilizzata da applicazioni per accesso ai dati.
![[Pasted image 20241116161718.png|350]]
**Pro**:
- **Limitazione dello spazio** a disposizione: si può impedire che i file di log riempiano il file system di root, confinandoli in una partizione separata.
- **Memoria virtuale**: implementazione di un'area di swap.
**Contro**:
- Le partizioni non posso essere modificate facilmente.
- Sono in chiaro, sempre.
## Volumi
Un **volume fisico** è una partizione di un disco rigido usabile per i volumi, il contenuto è organizzato come una sequenza di *blocchi fisici*.
![[Pasted image 20241116161953.png|350]]
Un **grupo di volumi** è la totalità dei blocchi fisici offerti dai volumi fisici.
Un **volume logico** è un insieme di *blocchi logici* del gruppo di appartenenza.
![[Pasted image 20241116162115.png|350]]
Il **superblocco** è il primo blocco di un *file system*, contiene metadati fondamentali del *file system*.
La **formattazione ad alto livello** è la procedura con la quale si inizializza un *file system* su una partizione o volume logico.
# Allocazione dei blocchi
**Scenario**:
- **Problema**: diversi processi vogliono scrivere sul disco contemporaneamente.
- SO:
	- Alloca i blocchi del *file system* per le operazioni di scrittura.
	- **Obiettivi**:
		1. Usare lo spazio libero in modo efficiente.
		2. Garantire un accesso veloce ai file:
			- Blocchi logicamente vicini dovrebbero essere fisicamente vicini sul disco.
Se il blocco è di dimensione piccola, un processo che scrive file grandi rischia di richiedere tanti blocchi, potenzialmente sparpagliati sul disco. In seguito a creazioni e cancellazioni di file, i blocchi liberi risultano disposti “a gruviera”. Si ha una **frammentazione esterna**.
Come vengono assegnati quindi i blocchi?
- **Assegnazione contigua**:
	- In blocchi *fisicamente contigui* sul disco.
	- Quando un file deve essere salvato, il SO cerca uno spazio libero sufficiente.
	- L'intero file viene scritto in un'unica area contigua di blocchi.
	- **Pro**:
		- Accesso rapido, ideale per file che devono essere letti e/o scritti in sequenza.
	- **Contro**:
		- *Frammentazione esterna*: con il tempo, blocchi contigui sufficientemente grandi possono non essere disponibili.
			- Si può risolvere tramite *estensioni* del volume, ma rimane il problema dello spazio.
		- *Rigidità*: file di dimensioni variabile possono richiedere spostamenti costosi.
- **Assegnazione concatenata**:
	- Ogni blocco memorizza un *puntatore* al successivo.
	- I blocchi non devono essere fisicamente contigui.
	- **Pro**:
		- *Niente frammentazione esterna*: qualsiasi blocco libero può essere usato.
		- *Adattabilità*: ideale per file di dimensione dinamica.
	- **Contro**:
		- *Prestazioni inferiori*: ci vuole tempo per "collegare" i vari blocchi.
		- *Fragilità*: un errore in un puntatore può interrompere l'intera catena.
		- *Overhead dei puntatori*: parte dello spazio è riservato per memorizzare i puntatori.
	- **Varianti**:
		- **Cluster**: gruppo di blocchi contigui, il *file system* alloca un **cluster**, in modo da diminuire il numero di puntatori richiesto per collegare il file (rischio frammentazione interna).
		- **FAT**: variante dell'assegnazione concatenata. All'inizio di ciascuna partizione viene riservato uno spazio per contenere una tabella di allocazione dei file (**File Allocation Table, FAT**). Ciascun blocco del disco è rappresentato da un numero intero univoco, detto indice. La FAT è acceduta attraverso gli indici e contiene indici.
			- **Contro**:
				- Richiede un accesso alla FAT per ogni blocco letto/scritto.
**Blocchi indice multipli**:
- **Schema concatenato**:
	- Il blocco indice ha una piccola intestazione nella quale sono riportati:
		- nome del file.
		- i primi 100 blocchi del disco.
	- L'ultimo elemento è `NULL` o il puntatore ad un altro blocco indice.
- **Indice a più livelli**:
	- Si usa un blocco indice di primo livello.
	- Gli elementi del blocco indice di primo livello puntano a blocchi indice di secondo livello.
	- Gli elementi del blocco indice di secondo livello puntano ai blocchi dei file.
- **Schema concatenato**:
	- A ciascun file è assegnato un blocco descrittore, noto con il nome di **inode**.
		- FCB del file.
		- **Puntatori 1-12**: puntatori diretti (**blocchi diretti**).
		- **Puntatore 13**: puntatore a puntatore di blocchi (**blocco indiretto singolo**).
		- **Puntatore 14**: puntatore a puntatore a puntatore di blocchi (**blocco indiretto doppio**).
		- **Puntatore 15**: puntatore a puntatore a puntatore a puntatore di blocchi (**blocco indiretto triplo**).
	- Per file piccoli, l'accesso è $O(1)$ tramite i blocchi diretti.
	- Per file più grandi, l'accesso è $O(\log(n))$ nel numero di blocchi del file.
	- Dimensione massima decisamente più grande.
- **Assegnazione indicizzata**:
	- Ogni file ha un **blocco indice** che memorizza gli indirizzi di tutti i blocchi dati.
	- Accesso diretto tramite il blocco indice.
	- **Pro**:
		- *Efficienza*: accesso diretto ai blocchi senza seguire puntatori.
		- *Flessibilità*: blocchi non contigui e supporto per file di dimensioni variabili.
		- *Robustezza*: la perdita di un blocco non compromette l'intero file.
	- **Contro**:
		- *Limite dimensioni file*:
			- Limitato dal numero di puntatori che un blocco indice può contenere.
		- *Dimensione del blocco indice critica*.
			- Troppo piccolo: non sufficiente per file grandi.
			- Troppo grande frammentazione interna.
# Gestione dello spazio libero
**Problema**: Lo spazio di memorizzazione secondario, è limitato. È necessario tenere traccia dei blocchi liberi per garantire un'allocazione efficiente e prevenire lo spreco di spazio.
Rappresentazione dei Blocchi Liberi:
- **Bitmap**
- **Liste concatenate**
- **Raggruppamenti**
- **Conteggi**
## Bitmap
Ciascun blocco del disco viene rappresentato tramite un bit:
- `0` $\to$ blocco allocato.
- `1` $\to$ blocco libero.
**Costante `BIT_PER_PAROLA`**: dimensione di una parole (32 o 64 bit).
**Indice `i`**: identifica il blocco.
**Vettore\[n\]**: vettore di $n$ parole di lunghezza `BIT_PER_PAROLA`.
**Bit**: valore effettivo del bit `i`-esimo.
**Operazioni**:
- `offset_parola` = `i/BIT_PER_PAROLA`;
- `offset_bit` = `i%BIT_PER_PAROLA`;
- `bit_i` = `parola_con_bit&(2^{offset_bit})`;
I processori moderni hanno istruzioni per individuare in un colpo di clock il primo bit imposto ad 1 in una parola di 16, 32, 64 bit:
- ISA x86_64: istruzioni `bsf`, `bsr`.
## Lista concatenata
I blocchi liberi sono collegati fra loro ogni blocco libero contiene un **puntatore** al blocco successivo libero.
**Pro**:
- Struttura semplice, non c'è bisogno di memorizzare una struttura complessa per tutti i blocchi, solo quelli liberi.
**Contro**:
- Accesso sequenziale, meno efficiente.
## Raggruppamento
I blocchi liberi sono raggruppati in **blocchi contigui**, ogni blocco punta al successivo.
## Conteggio
I blocchi liberi sono **contigui**. Ogni gruppo memorizza:
- **Numero** di blocchi liberi consecutivi.
- **Puntatore** al prossimo gruppo.
# Efficienza
Il termine "efficienza" indica la capacità di svolgere compiti con il minimo sforzo.
Nel *file system* si intende:
- Uso "compatto" dello spazio del disco.
- Rappresentazione di file grandi con il minimo dispendio di metadati.
Gli **inode** sono impacchettati all'inizio del disco, vicino al superblocco. Facilitando il caricamento in memoria di molti inode.
## Metadati dei file
**Timestamp**: accesso al file, critici per alcune applicazioni.
Ad ogni accesso cambia, vanno aggiornati:
- Lettura blocco FCB da disco.
- Modifica metadati.
- Scrittura blocco FCB aggiornato.
Se un file è acceduto frequentemente, si ha una palese inefficienza di uso del disco.
**Soluzione**: si mantiene una copia del FCB in memoria centrale e si aggiorna il FCB su disco periodicamente.
# Prestazioni
La capacità di svolgere compiti al massimo della propria capacità.
Nel contesto dei *file system* si intende:
- Aumento della velocità delle operazioni di I/O.
- Applicazione del concetto di gerarchia di memoria.
## Scritture sincrone e asincrone
- **Scritture sincrone**:
	- Eseguite *immediatamente*, nell'ordine in cui sono ricevute.
	- Non utilizzano buffer intermedi.
	- **Pro**: garantiscono consistenza immediata.
	- **Contro**: lente, ogni operazione aspetta il completamento fisico sul disco.
- **Scritture asincrone**:
	- Utilizzano un **buffer intermedio** pr memorizzare temporaneamente i dati.
	- Il controllo ritorna subito al processo chiamante, senza attendere che i dati siano scritti sul disco.
	- **Pro**:
		- Aumento delle prestazioni: il SO può ottimizzare la scrittura scegliendo momenti più efficienti (riduzione dei movimenti della testina).
		- `write()` diventa veloce.
	- **Contro**:
		- Rischio di *perdita di dati* in caso di crash.
		- Se i metadati sono stati aggiornati, ma non i dati, posso verificarsi gravi inconsistenze.
# Sicurezza
- Mantenere un sistema in uno stato *consistente*.
- Impedire agli utenti un *uso malizioso* del sistema.
**Controllo di consistenza**:  applicazione progettata per verificare e mantenere la coerenza di metadati e blocchi:
- In Linux: `fsck.nome_fs`, `fsck.ext4, `fsck.vfat`, ...
Operazioni di `fsck`:
- **Controllo consistenza**: verifica l'integrità dei metadati e blocchi.
- **Riparazione**: corregge eventuali problemi riscontrati. 
# Journal
Il file system è arricchito con un file speciale(detto **journal**), gestito come un **buffer circolare**.
1. **Annotazioni**:
	- Ogni inizio di transazione.
	- Ogni operazione di ogni transazione.
2. **Sincronizzazione**:
	- Periodicamente il SO applica le modifiche annotate dal file system.
	- Operazioni completate e inizio transazione vengono rimosse.
3. **Crash-case**:
	- Le operazioni non marcate come completate vengono applicate al disco seguendo l'ordine del journal(**controllo di consistenza**).
	- Garantisce la consistenza del file system.
***
# T10 - VFS
# Virtual File System
Il **Virtual File System** è un sottosistema del kernel Linux, offre una rappresentazione uniforme e gerarchica dei file e delle periferiche, indipendentemente dalla loro posizione.
- In Linux sono i file di primo livello in :`$LINUX/fs`.
Separa la logica del file system dall'hardware, offrendo agli utenti un unico modello di accesso.
Si supponga di avere mount point con nomi direttamente associabili alle periferiche.
Windows:
- Primo disco SATA: "`C:\`".
- Secondo disco SATA: "`D:\`".
- Terzo disco SATA: "`E:\`".
Si scriva un'applicazione che fa riferimento a file contenuti in "`D:`". Si scambino di posto il secondo e terzo disco.
- L'applicazione non accede più ai file.
![[Pasted image 20241118154943.png|500]]
- **Path lookup**: scompone il percorso di un file per individuare i dispositivi sottostanti.
- **Gestione descrittori di file**: mappa i file aperti dalle applicazioni su strutture di dati kernel.
## Struct inode
Nei sistemi UNIX rappresenta il FCB, una struttura detta **inode**.
In `EXT4` l'*inode* è definito come: `struct ext4_inode` in `$LINUX/fs/ext4/ext4.h`.
File system diversi possono avere *inode* in formato diverso. Per tale motivo il VFS definisce un unico formato di *inode*, valido per tutti i file system: `struct inode`, definita nel file: `$LINUX/include/fs.h` creata al primo uso di un file e mantenuta in RAM perché l'analisi di un percorso è frequente e dispendiosa.
### Struct file
`struct file` rappresenta il file aperto `$LINUX/include/fs.h` contenente:
- Puntatore all'*inode* del VFS.
- Posizione nel file.
- Modalità di apertura.
- File Path
- Puntatori alle operazioni possibili sul file.
### Struct dentry
`struct dentry` rappresenta un elemento del percorso di un file: `$LINUX/include/dcache.h`:
- Il file `/bin/vi` è composto da due *dentry*:
	- `/bin`(directory)
	- `vi`(file)
La prima volta che xil kernel scandisce tale percorso, costruisce le due dentry e le inserisce in un albero in memoria centrale (**dentry cache**).
Con la cache il path lookup si riduce ad una navigazione di un albero binario in RAM. (`vfs_path_lookup(`).
### Struct file_operations
`struct file_operations` è un array di puntatori a funzione rappresentante le operazioni possibili su un file(`$LINUX/include/fs.h`). Occupa una intera linea di cache hardware per un accesso fulmineo.
# Directory Tree
## Filesystem Hierarchy Standard
Le directory del file system di root sono organizzate secondo uno standard: **Filesystem Hierarchy Standard**(FHS).
![[Pasted image 20241118161813.png|500]]
Definisce la struttura delle directory nei sistemi, specificando la funzione di ciascuna di esse.

| **Directory**    | **Descrizione**                                                                                 |
| ---------------- | ----------------------------------------------------------------------------------------------- |
| **`/bin`**       | Comandi base per il sistema operativo in modalità testuale (es. `ls`, `cp`, `mv`).              |
| **`/sbin`**      | Comandi di amministrazione (es. `fsck`, `reboot`) e il programma `init`, che avvia i servizi.   |
| **`/boot`**      | File per l'avvio del sistema (kernel, configurazioni del bootloader).                           |
| **`/dev`**       | File speciali per dispositivi hardware (comunicazione con periferiche).                         |
| **`/etc`**       | Configurazioni di sistema e software (es. `passwd`, `fstab`).                                   |
| **`/home`**      | Directory personali degli utenti, con i loro file e configurazioni locali.                      |
| **`/lib`**       | Librerie condivise necessarie per l'avvio del sistema (es. `libc.so`).                          |
| **`/mnt`**       | Mount point obsoleto (sostituito da `/media` per dispositivi rimovibili).                       |
| **`/opt`**       | Software di terze parti, non open-source o distribuito in formato binario.                      |
| **`/proc`**      | Informazioni sul sistema generate dal kernel in tempo reale (processi, memoria, ecc.).          |
| **`/root`**      | Spazio personale dell'utente `root` (amministratore di sistema).                                |
| **`/run`**       | File temporanei in RAM, utili per la gestione dei processi (es. PID di servizi come `apache2`). |
| **`/tmp`**       | File temporanei in RAM, eliminati al riavvio.                                                   |
| **`/usr`**       | File di sistema, librerie e applicazioni installate dall'utente.                                |
| **`/usr/local`** | Software personalizzato, compilato o installato manualmente dall'amministratore.                |
| **`/var`**       | File di registro e directory che crescono nel tempo (log, spool, cache).                        |
### Usi comuni del Virtual File System (VFS)
1. **Clonazione dischi**: 
   ```bash
   dd if=/dev/sda of=/dev/sdb
   ```
   - Copia blocco per blocco il contenuto di `/dev/sda` su `/dev/sdb`.
2. **Masterizzazione CD**: 
   ```bash
   dd if=img.iso of=/dev/cdrw
   ```
   - Scrive l'immagine `img.iso` su un CD nell'unità `/dev/cdrw`.
3. **Analisi partizioni**:
   ```bash
   strings /dev/sda2
   ```
   - Estrae le sequenze di caratteri leggibili dalla partizione `/dev/sda2`.
4. **Visione terminale**: 
   ```bash
   watch -n 1 fold -w 80 /dev/vcs2
   ```
   - Mostra ogni secondo la schermata del terminale (`tty2`).
5. **Statistiche di un processo**:
   - Per ogni processo attivo, il kernel crea una directory `/proc/[PID]`, dove:
     - `[PID]`: identificativo del processo.
     - Contenuto: informazioni su memoria, CPU, I/O e altri parametri statistici.
# T-11
# Sistemi monoprogrammati
**Scenario**: i processi hanno bisogno di memoria che venga fornita in modo:
- *Efficiente*: sprecando meno risorse possibile.
- *Performante*: nel modo più veloce possibile.
- *Sicura*: processi diversi sono isolati fra loro.
da SO.
Lo sviluppatore può gestire la **memoria**: un gigantesco vettore di byte, ciascuno dotato di un indirizzo. La memoria contiene:
- *Istruzioni*.
- *Dati*.
Nei **sistemi monoprogrammati** solo un processo può risiedere in memoria e prende il controllo dell'intera macchina.
- **contro**:
	- Un solo processo può essere in esecuzione in ogni istante.
	- Il programma deve contenere i device driver delle periferiche per la macchina.
# Sistemi multiprogrammati
La memoria principale è suddivisa in **partizioni** di grandezza fissa.
Ogni partizione ha una coda di ingresso per i programmi.
I programmi vengono assegnati alla partizione più piccola disponibile.
![[Pasted image 20241121160625.png|350]]
**Contro**:
- **Frammentazione interna**: Ogni programma occupa una intera partizione a prescindere dalla sua dimensione. Se le code piccole sono intasate, un programma piccolo può occupare una partizione grande.
- **Frammentazione esterna**: La dimensione di un programma può essere più grande di una qualunque partizione esistente, anche se la memoria libera disponibile nel complesso lo permetterebbe.
- **Limitazione grado di multiprogrammazione**: Nessuna partizione disponibile $\to$ niente esecuzione.
## Partizionamento dinamico
Numero e dimensione delle partizioni sono dinamici. Ogni programma riceve solo la memoria necessaria.
**Pro**:
- Frammentazione interna limitata.
**Contro**:
- Problema di spazio contiguo insufficiente per grandi programmi.
## Swap
Si usa un disco di appoggio(**backing store** o **swap**) per riversare su disco(**swap out**) la memoria di un programma:
- che intralcia il caricamento di uno più importante.
- che deve bloccarsi per un I/O.
Quando è riattivato, il programma è riportato in memoria centrale (**swap in**) previo eventuale swap out di un altro programma.
![[Pasted image 20241121161307.png]]
**Pro**:
- La frammentazione esterna non impedisce più l'avvio di un programma.
**Contro**:
- Operazioni lente (copia e lettura da disco).
# Allocazione di memoria
## Allocazione statica
La memoria è dichiarata e allocata interamente a tempo di caricamento.
Non permette espansioni dinamiche.
## Allocazione dinamica
Un programma può richiedere memoria aggiuntiva a runtime.
### Problema
Che cosa succede se l'allocazione invade la zona di un altro programma?
### Soluzioni
- $P_{1}$ è bloccato e spostato in una partizione abbastanza grande per contenerlo. Se tale partizione non esiste, $P_{1}$ è ucciso.
![[Pasted image 20241121162352.png|350]]
- $P_{2}$ è bloccato e spostato in area di swap per favorire l'espansione dinamica della memoria di $P_{1}$.
![[Pasted image 20241121162512.png|350]]
# Organizzazione interna
La memoria è suddivisa in:
- *Codice*
- *Dati*
	1. variabili(statiche) dichiarate a livello di compilazione
	2. memoria dinamnica(**heap**)
- *Stack*: per record di attivazione e variabili locali.
Tali parti devono trovare posto nella partizione del processo.
![[Pasted image 20241121162847.png|305]]
## Problemi di collisione heap $\iff$ stack
**Stack $\to$ Heap**: corruzione dei dati nell'heap.
**Heap $\to$ Stack**: gli ultimi record di attivazione sono sovrascritti con valori provenienti dall'heap $\to$ Sovrascrittura di record di attivazione (_buffer overflow_), che può portare all'esecuzione di codice arbitrario.
***
# T-12 Supporto alla memoria
## Problemi nella gestione della memoria

1. **Memoria contigua**: Necessità di collocare un processo in una porzione di memoria fisica continua.
2. **Swap mirato**: Possibilità di spostare solo porzioni specifiche della memoria di un processo.
3. **Distanza tra heap e stack**: Necessità di mantenerli separati per evitare conflitti.
4. **Protezione della memoria**: Impedire a un programma di accedere alla memoria di un altro programma.
5. **Buffer overflow**: Limitare gli effetti di problemi di sovrascrittura di memoria.
## Soluzioni proposte
1. **Illusione di esclusività**:
    - Far credere a ogni processo di essere l'unico nella memoria centrale.
    - Elimina problemi di sovrapposizione e gestione delle partizioni.
2. **Blocchi di memoria piccoli**:
    - Riduce la frammentazione esterna.
3. **Schemi di indirizzamento multipli**:
    - **Indirizzi virtuali**: Simulano zone di memoria contigue, eliminando la frammentazione esterna.
    - **Indirizzi fisici**: Utilizzati per accedere effettivamente al chip RAM.
    - Mappatura efficiente tra indirizzi virtuali e fisici, con supporto allo swap su disco.
### Supporto hardware
1. **Segmentazione** (dall'8086):
    - La memoria di un processo è suddivisa in segmenti per **codice**, **dati** e **stack**.
    - Ogni segmento ha il proprio intervallo di indirizzi e permessi di accesso.
2. **Paginazione** (dall'80386):
    - La memoria è vista come una collezione di piccoli blocchi (tipicamente da 4 KB).
    - Ogni blocco ha il proprio intervallo di indirizzi e permessi.
Questi meccanismi costituiscono la base del sottosistema di memoria virtuale nei sistemi operativi moderni.
### Schema degli indirizzi
1. **Indirizzo logico**:
    - Generato dalla CPU e processato dall'unità di segmentazione.
2. **Indirizzo lineare**:
    - Prodotto dell'unità di segmentazione e processato dall'unità di paginazione.
3. **Indirizzo fisico**:
    - Prodotto dell'unità di paginazione e usato per accedere ai dati nella RAM.
Esempio:
- Salto a `jmp 0058:FFEC` genera:
    - **Indirizzo logico**: `0058:FFEC`
    - **Indirizzo lineare**: `0x9121C`
    - **Indirizzo fisico**: `0x4000021C`
### Modalità operative
1. **Real Mode**:
    - Pre-80286: Sempre attiva.
    - 80286 e superiori: Utilizzata nella fase iniziale di avvio.
2. **Protected Mode**:
    - Attivata sui processori 80286 e successivi impostando il bit *PE* del registro di controllo `CR0` a 1.
# Segmentazione
La **segmentazione** è una tecnica di gestione della memoria usata nei sistemi operativi per organizzare lo spazio di memoria in segmenti logici di dimensioni variabili. È progettata per riflettere meglio la struttura logica di un programma(ad esempio, separando il codice, i dati e lo stack). A differenza della **paginazione**, che divide la memoria in blocchi di dimensioni fisse, la segmentazione permette segmenti di dimensioni diverse, legati alla logica del programma.
Un indirizzo logico assume la forma: **SELECTOR:OFFSET**
- **Selector**: indice nella tabella dei segmenti.
- **Offset**: posizione relativa all'interno del segmento.
## Registri di segmento
Il *selector* è salvato in un *registro di segmento*(segment register). Esempio: 8086:
- **CS**(Code Segment): contiene il selettore del segmento per il segmento di codice.
- **DS**(Data Segment): contiene il selettore del segmento per il segmento dati.
- **SS**(Stack Segment): contiene il selettore del segmento per il segmento dello stack.
- **ES**(Extra Segment): contiene il selettore di un segmento “extra”, impostabile dall'utente.
## Registri puntatore
L'*offset* di alcuni indirizzi notevoli è salvato in un *registro puntatore* o *indice*(pointer o index register). Esempio: 8086:
- **SP**(Stack Pointer): contiene l'offset dell'indirizzo cima dello stack.
- **BP**(Base Pointer): contiene l'offset dell'indirizzo del record di attivazione corrente.
- **IP**(Instruction Pointer): contiene l'offset dell'indirizzo della prossima istruzione da eseguire.
- **SI, DI**(Source, Destination Index): contengono offset variabili per l'implementazione di cicli.
![[Pasted image 20241129173855.png|500]]
## Limitazioni real mode
1. **Bus degli indirizzi a 20 bit**:
    - L'8086 può gestire al massimo **2²⁰ byte = 1 MB di memoria**.
2. **Dimensione massima di un segmento**:
    - Ogni segmento è limitato a **64 KB**.
3. **Assenza di privilegi**:
    - Non ci sono livelli di protezione per isolare processi o segmenti di memoria.
4. **Necessità di un'estensione**:
    - Per superare queste limitazioni, si è sviluppata la **Protected Mode**, retrocompatibile con il Real Mode.
## Descrittore di segmento(80286)
- Struttura dati di **8 byte** nella modalità protetta, descrive un segmento.
- Contiene:
    1. **Base**: indirizzo lineare a **32 bit**, indica l'inizio del segmento.
    2. **Limite**: offset a **20 bit**, specifica la lunghezza del segmento.
    3. **DPL** (Descriptor Privilege Level): livello di privilegio minimo richiesto per accedere al segmento:
        - **0**: kernel mode (massimo privilegio).
        - **3**: user mode (minimo privilegio).
Il formato è una **estensione retrocompatibile** con il vecchio schema a 20 bit (Real Mode).
### Tabelle dei descrittori
1. **Global Descriptor Table (GDT)**:
    - Contiene descrittori di segmenti di interesse globale.
    - Può includere descrittori delle Local Descriptor Table (LDT).
2. **Local Descriptor Table (LDT)**:
    - Contiene i descrittori specifici di un processo (es. codice, dati, stack).
### Registri associati alle tabelle
1. **GDTR** (Global Descriptor Table Register):
    - Memorizza l’indirizzo iniziale della GDT.
2. **LDTR** (Local Descriptor Table Register):
    - Memorizza l’indirizzo iniziale della LDT del processo corrente.
### Istruzioni per gestire i registri
- **`lgdt` / `sgdt`**:
    - `lgdt`: carica un indirizzo nel GDTR.
    - `sgdt`: salva il contenuto di GDTR in un altro registro.
- **`lldt` / `sldt`**:
    - `lldt`: carica un indirizzo nel LDTR.
    - `sldt`: salva il contenuto di LDTR in un altro registro.
- Queste istruzioni sono eseguibili solo in **ring 0** (kernel mode).
## Inizializzazione delle GDT
- All'avvio del kernel durante il boot:
    ```
    go_to_protected_mode()
    ```
    - File di riferimento:
        ```
        $LINUX/arch/x86/boot/pm.c
        ```
    - Cosa fa?
        - Attiva la **modalità protetta**.
        - Inizializza il **vettore delle interruzioni**.
### Inizializzazione della LDT (Local Descriptor Table)
- Quando avviene?:
    1. Alla **creazione di un processo** (`fork()`):
        - Attraverso la funzione `dup_mm()`.
    2. Al **caricamento di un'immagine** (`execve()`):
        - Attraverso la funzione `bprm_mm_init()`.
- Si usa una **funzione architettura-dipendente**:
    ```
    init_new_context()
    ```
    - File di riferimento:
        ```
        $LINUX/arch/x86/kernel/ldt.c
        ```
### Il selettore di segmento (80286)
Punta a un descrittore di segmento nella **GDT** o **LDT**.
- **Organizzazione**: Struttura di 2 byte.
    - Campi del selettore:
        - **Indice** (13 bit):
            - Identificatore del segmento (fino a **8192 segmenti**).
        - **TI** (Table Indicator, 1 bit):
            - Indica la tabella in cui si trova il segmento:
                - `0`: **GDT**.
                - `1`: **LDT**.
        - **RPL** (Requestor Privilege Level, 2 bit):
            - Privilegio richiesto per accedere al segmento (**0-3**).
        - **CPL** (Current Privilege Level):
            - Privilegio con cui il codice sta eseguendo.
## Traduzione degli indirizzi in protected mode
1. **Lettura del Segment Selector**:
    - Il processore legge il **segment selector** da una costante o da un registro di segmento (es. **CS**, **DS**).
2. **Controllo dei privilegi**:
    - Si verificano i privilegi di accesso, confrontando il **CPL** (Current Privilege Level) con il **DPL** (Descriptor Privilege Level) del descrittore di segmento.
3. **Identificazione della tabella**:
    - Tramite il bit **TI** (Table Indicator) si determina se il descrittore si trova nella **GDT** o nella **LDT**.
4. **Individuazione dell'indirizzo del descrittore**:
    - Si calcola l'indirizzo del descrittore di segmento usando l'indirizzo base del registro **GDTR** e l'indice del segmento:
        ```
        Indirizzo descrittore = GDTR + indice * 8
        ```
5. **Estrazione dell'indirizzo base**:
    - Una volta individuato il descrittore, si estrae l'**indirizzo base** (che è parte del descrittore di segmento).
6. **Calcolo dell'indirizzo lineare**:
    - Si somma l'**offset** (fornito dal codice o dal registro puntatore) all'indirizzo base per ottenere l'**indirizzo lineare**:
        ```
        Indirizzo lineare = Indirizzo base + offset
        ```
7. **Fine del processo**:
    - Nell'**80286**, l'indirizzo lineare coincide con l'indirizzo **fisico** (poiché non è presente la paginazione).
![[Pasted image 20241129175803.png|500]]
## Livelli di privilegio
I privilegi di esecuzione sono un meccanismo di difesa da istruzioni/accessi alla memoria illegali causati da: malfunzionamenti hardware. comportamenti maliziosi.
La CPU è dotata di 4 modi di utilizzo, disposti “ad anello”:
- **Ring 3**: applicazioni utente.
- **Ring 2**: device driver.
- **Ring 1**: device driver, hypervisor.
- **Ring 0**: device driver e basso livello SO (kernel)
![[Pasted image 20241129175947.png|500]]
## Algoritmo di controllo dei privilegi
1. Si estrae il *CPL* dal selettore di segmento in *CS*.
2. Si estrae il *RPL* dal selettore del segmento dati nel registro di segmento opportuno (DS, ES, …).
3. Si identifica il descrittore di segmento usando il campo index del selettore di segmento.
4. Si estrae il *DPL* dal descrittore di segmento.
5. Si calcola il privilegio più debole fra codice in esecuzione e privilegio di richiesta:
	1. `max(CPL, RPL)`.
6. Se DPL $\geq$ `max(CPL, RPL)`, l'accesso viene garantito.
7. Altrimenti, viene generata una eccezione del tipo **General Protection Fault**.
![[Pasted image 20241129180202.png|500]]
### Estensioni introdotte nell'80386
1. **Registri a 32 bit**
2. **Descrittore di segmento**:
    - Il **descrittore di segmento** viene modificato per supportare segmenti di **dimensione massima maggiore** (da 1MB a **4GB**).
    - Introduzione del **registro base a 32 bit** per indirizzare segmenti più grandi.
    - Il **flag G** (Granularity) indica che se impostato a **1**, il limite del segmento è moltiplicato per 4096 (la dimensione di una pagina), estendendo la dimensione massima del segmento da 1MB a 4GB.
3. **Due nuovi segmenti FS e GS**:
	- Programmabili dall'utente.
4. **Paginazione**:
    - L'indirizzo lineare non coincide più con l'indirizzo fisico, ma viene passato all'**unità di paginazione** per la mappatura in memoria.
### Schema del descrittore di segmento (80386, 32 bit):
![[Pasted image 20241129181041.png|500]]
### Modifiche introdotte nell'architettura x86_64
1. **Registri a 64 bit**:
    - Registri **tutti a 64 bit**, ampliando significativamente la capacità di memoria e la potenza di elaborazione.
2. **No segmentazione**:
    - Nella modalità di indirizzamento **default** (long mode), **la segmentazione viene disabilitata**. I registri di segmento (**CS, DS, ES, SS**) hanno:
        - **Base = 0** e **Limite = 2⁶⁴**, che consente di indirizzare tutta la memoria.
3. **Modalità di compatibilità(legacy mode)**:
    - Quando il processore è in modalità compatibilità(per supportare software a 32 bit), si comporta come un **x86_32**, mantenendo il modello di segmentazione tradizionale.
4. **Vantaggi**:
    - L'architettura **x86_64** elimina le complessità della segmentazione, riducendo la necessità di descrittori di segmento e migliorando l'efficienza nell'accesso alla memoria.
## Flat memory model(Linux, x86_32)
Il **modello piatto di memoria**(flat memory model) è una tecnica che riduce l'uso della segmentazione, mappando l'intero spazio di memoria in un singolo segmento continuo.
In Linux (x86, 32 bit) viene fatto definendo quattro segmenti sovrapposti che coprono l'intero spazio di indirizzamento a 4GB(0-4GB), evitando la segmentazione complessa.
### Segmenti nel Flat Memory Model:

| **Nome**      | **Tipo**            | **Base** | **Limite** | **DPL** |
| ------------- | ------------------- | -------- | ---------- | ------- |
| `__KERNEL_CS` | Kernel code segment | 0        | 4GB        | 0       |
| `__KERNEL_DS` | Kernel data segment | 0        | 4GB        | 0       |
| `__USER_CS`   | User code segment   | 0        | 4GB        | 3       |
| `__USER_DS`   | User data segment   | 0        | 4GB        | 3       |
### Impostazione del Flat Memory Model in Linux:
1. **Definizione delle macro**: Le macro per la configurazione dei segmenti sono definite in:
    ```
    $LINUX/include/asm/segment.h
    ```
2. **Fasi dell'impostazione**:
    - **Avvio del kernel**: In questa fase, vengono inizializzati i registri di segmento per il kernel.
    - **Chiamata di sistema**: Durante l'esecuzione di chiamate di sistema, vengono gestiti i segmenti per il kernel e per l'utente.
    - **Copia dati tra kernel e applicazione**: Quando un'applicazione passa dati al kernel o viceversa, i segmenti vengono aggiornati di conseguenza.
    - **Clonazione di un processo**: Quando un processo viene duplicato (ad esempio, con `fork()`), la configurazione dei segmenti viene adattata per il nuovo processo.
I dettagli sui segmenti nel sistema Linux (x86, x86_64) possono essere trovati tramite il comando:
```
cd $LINUX/arch/x86
grep -nrHE “__KERNEL_(C|D)S” *
```
# Paginazione: Supporto Hardware
La **paginazione** è un meccanismo di gestione della memoria introdotto con l'architettura 80386, che consente di trattare la memoria come una serie di piccoli blocchi contigui e di dimensione fissa, migliorando l'efficienza nell'allocazione e gestione della memoria.
### Obiettivo della Paginazione:
Lo scopo principale della paginazione è mappare gli **indirizzi logici** (o lineari) in **indirizzi fisici**, creando una relazione tra lo spazio di memoria virtuale e quello fisico.
- **Indirizzi lineari (logici)**: Rappresentano lo spazio di memoria che il processore vede come un blocco contiguo.
- **Indirizzi fisici**: Rappresentano la memoria reale, che potrebbe non essere contigua a causa di limitazioni fisiche o gestione dinamica della memoria.
**Problema**:
**Mappare ogni singolo indirizzo lineare in un indirizzo fisico** è molto dispendioso in termini di tempo e risorse, soprattutto per grandi spazi di memoria.
### Frame e Pagine:
- **Pagine**: Lo spazio di indirizzamento **lineare** (virtuale) è suddiviso in blocchi di dimensione fissa chiamati **pagine**.
	- Non troppo piccola e non troppo grande, è di **4KB**.
- **Frame**: Lo spazio di indirizzamento **fisico** è suddiviso in blocchi di uguale dimensione chiamati **frame**.
Il **problema della paginazione** si riduce a mappare una **pagina** in un **frame**. Essendo le dimensioni di pagine e frame uguali, la mappatura diventa più semplice e meno costosa rispetto a una mappatura puntuale di ogni singolo indirizzo.
**Benefici**:
- **Semplificazione**: Poiché avviene tra blocchi di memoria di dimensione fissa (pagine e frame), la complessità e il costo computazionale della gestione della memoria si riducono.
- **Flessibilità**: Permette una gestione dinamica della memoria, supportando la **memoria virtuale**, in cui i processi possono utilizzare più memoria di quella effettivamente disponibile, tramite la paginazione e l'uso di dispositivi di memoria secondaria (come il disco).
![[Pasted image 20241129182809.png|500]]
## Memory Management Unit
La mappatura fra pagine e frame è ottenuta attraverso un circuito integrato nel processore, la **Memory Management Unit (MMU)**.
La *Memory Management Unit* gestisce la **tabella delle pagine(page table)**. Indicizzata tramite una porzione dell'indirizzo logico. L'elemento i contiene una struttura dati descrivente il frame associato alla pagina $i$.
![[Pasted image 20241129183215.png|350]]
### Schema ideale di base
![[Pasted image 20241129183312.png|500]]
### Problema della Dimensione della Tabella delle Pagine
Nel sistema di paginazione, la **tabella delle pagine** è un elemento cruciale per la mappatura tra gli indirizzi logici e fisici. Tuttavia, la sua dimensione può essere un problema, soprattutto in architetture con grandi spazi di indirizzamento.
- La tabella delle pagine contiene una voce per ogni **pagina** di memoria. Se si considera una memoria indirizzabile di 4GB con pagine di 4KB, il numero di voci nella tabella delle pagine sarebbe $2^{20}$ (1 milione di voci).
- Ogni voce della tabella può occupare almeno 4 byte (in un sistema a 32 bit), portando la **dimensione totale della tabella** a **4MB** (4 byte × $2^{20}$ voci).
Nel **1985**, quando è stato introdotto l'80386, una tabella delle pagine di 4MB era **troppo grande** per essere gestita direttamente dal processore, sia in termini di **memoria hardware** che di **prestazioni**.
### Soluzione: Memorizzare la Tabella delle Pagine in RAM
Per risolvere il problema della dimensione della tabella delle pagine, si è deciso di **memorizzare la tabella in RAM** anziché cercare di cablarla direttamente nell'hardware del processore. In questo modo, la tabella non deve occupare spazio fisico nel chip, ma viene comunque utilizzata dal processore per la traduzione degli indirizzi.
- La tabella delle pagine viene **caricata in memoria RAM** e il **processore utilizza un registro di controllo** per accedere ad essa.
- **Registro CR3**: Nei processori Intel, l'indirizzo fisico iniziale della tabella delle pagine viene **salvato nel registro di controllo CR3**. Il **registro CR3** punta all'indirizzo base della tabella delle pagine in memoria, permettendo al processore di accedervi per ottenere la mappatura tra gli indirizzi logici e fisici.
Con questa soluzione, la tabella delle pagine può essere gestita in modo dinamico senza doverla integrare direttamente nell'hardware del processore, riducendo il costo in termini di spazio e di complessità.
![[Pasted image 20241130105406.png|500]]
## Rappresentazione della Pagina in Linux
In Linux, la rappresentazione di un elemento della **tabella delle pagine** (mappatura tra pagina logica e frame fisico) utilizza un **tipo di dato opaco** chiamato `pte_t`.
- **Tipo opaco `pte_t`**: È una rappresentazione astratta e dipende dall'architettura della CPU.
- Per l'architettura **x86_64**, è spesso un `unsigned long`, incapsulato in una struttura `pteval_t`.
- **Definizioni specifiche**: Variano a seconda dell'architettura. Per x86_64, la definizione si trova in:
    - `$LINUX/arch/x86/include/pgtable_64_types.h`.
## Gestione dei Frame Fisici (Allocazione e Deallocazione)
Linux fornisce strumenti per gestire i **frame fisici** (blocchi di memoria fisica corrispondenti alle pagine logiche).
- **`get_page()`**: Ottiene un frame fisico libero.
- **`free_page()`**: Restituisce un frame fisico al sistema.
- **`alloc_pages()` e `free_pages()`**: Permettono di allocare/deallocare **blocchi di $2^{n}$ frame**.
Queste funzioni sono definite in:
- `$LINUX/include/linux/gfp.h`.
## Problema: Accesso Inefficiente alla Memoria
Con la **tabella delle pagine** in RAM, ogni accesso alla memoria logica richiede due operazioni:
1. **Accesso alla tabella delle pagine**: Per ottenere l'indirizzo fisico corrispondente a quello logico.
2. **Accesso alla memoria fisica**: Per leggere/scrivere i dati.
Questo introduce un **overhead significativo**, raddoppiando il numero di accessi alla memoria.
## Soluzione: Translation Lookaside Buffer (TLB)
Per migliorare le prestazioni, si utilizza una **cache hardware** chiamata **Translation Lookaside Buffer (TLB)**.
- Il TLB è una **memoria associativa hardware** progettata per memorizzare le traduzioni di indirizzi più utilizzate (le porzioni "calde" della tabella delle pagine).
- **Velocità**: Il TLB opera a velocità comparabili a quelle dei registri della CPU (pochi nanosecondi).
#### **Processo**:
1. Quando si traduce un indirizzo lineare in fisico, si effettua un **lookup** nel TLB.
2. **Se la traduzione è presente**:
    - Si ottiene l'indirizzo fisico direttamente.
3. **Se la traduzione non è presente**:
    - Si accede alla tabella delle pagine in RAM.
    - Si aggiorna il TLB con la nuova traduzione per utilizzi futuri.
Questo approccio riduce drasticamente il numero di accessi alla RAM, migliorando le prestazioni della memoria virtuale.
### TLB hit e TBL miss
- **TLB Hit**: L'indirizzo logico richiesto è presente nel **TLB** → Traduzione immediata, **accesso veloce** (pochi nanosecondi).
- **TLB Miss**: L'indirizzo non è nel **TLB** → Si accede alla **tabella delle pagine** in RAM per la traduzione, poi si aggiorna il TLB → **Accesso più lento**.
- **TLB Hit Ratio**: Percentuale di accessi alla memoria con **TLB Hit** rispetto al totale degli accessi.
    - Valore alto = **prestazioni migliori**, perché si evita il costo di accedere alla tabella delle pagine in RAM.
![[Pasted image 20241130111256.png|500]]
### TLB: Wiring Down e Flushing
1. **Wiring Down**:
    - Alcune pagine di memoria rimangono sempre in RAM e le loro associazioni nel TLB sono **permanenti**.
    - Queste chiavi non vengono rimosse quando il TLB è pieno.
2. **Indirizzi Lineari Simili per Processi Diversi**:
    - Ogni processo ha una propria tabella delle pagine.
    - Processi diversi possono usare lo stesso indirizzo lineare, mappato a indirizzi fisici distinti.
    - Questo semplifica la gestione degli indirizzi da parte del compilatore.
3. **Problema: Aggiornamento del TLB**:
    - Senza aggiornare il TLB durante un cambio di contesto, un processo potrebbe accedere ai dati o codice di un altro.
4. **Soluzione: TLB Flushing**:
    - Ad ogni cambio di contesto, il **TLB viene azzerato** per evitare errori.
    - **Svantaggio**: il flushing globale riduce le prestazioni a causa della perdita delle chiavi cache.
### Address Space Identifier
1. **Address Space Identifier (ASI)**:
    - È una chiave che identifica univocamente un processo nella macchina.
    - Permette di invalidare il **TLB** selettivamente per un singolo processo anziché globalmente.
    - Questo migliora notevolmente le **prestazioni** durante il flushing.
2. **Aggiornamento del TLB su Intel**:
    - Nei processori Intel, l'**inserimento di nuove chiavi** nel TLB avviene completamente in **hardware** durante la mappatura pagina-frame.
    - Il kernel si occupa solo del **flushing** (es. funzione `flush_tlb()` in x86-64).
3. **Problema: Dimensione della Tabella**:
    - Con spazi di indirizzamento logico ampi (es. 32 o 64 bit), le tabelle delle pagine diventano **enormi**.
    - Esempio a 32 bit:
        - Dimensione pagina: 4 KB.
        - Tabella per processo: **4 MB** di memoria.
4. **Soluzione: Paginazione Gerarchica**:
    - Si adotta una **struttura gerarchica** per le tabelle delle pagine:
        - La tabella principale punta a **sotto-tabelle** più piccole.
        - Le sotto-tabelle mappano direttamente ai frame fisici.
    - Questo schema riduce l'occupazione di memoria e richiede una **riprogettazione degli indirizzi logici**.
### Il nuovo formato degli indirizzi logici
Il nuovo **indirizzo lineare** è suddiviso in tre parti:
1. **Numero primario di pagina (p1)**:
    - Rappresenta l'indice nella **tabella delle pagine principale**.
    - Identifica la sotto-tabella che contiene il mapping desiderato.
2. **Numero secondario di pagina (p2)**:
    - Indice alla **tabella delle pagine secondaria**, specifica l'elemento all'interno della sotto-tabella.
3. **Offset di pagina (d)**:
    - Indica la posizione precisa del dato **all'interno della pagina** mappata.
![[Pasted image 20241130112833.png|350]]
![[Pasted image 20241130112927.png|500]]
## Physical Address Extension(PAE)
L'**estensione sull'indirizzamento fisico** consente a processori Intel a 32 bit di gestire fino a **64GB di RAM**, grazie a una paginazione a tre livelli.
### Caratteristiche:
1. **Mappatura a 36 bit**:
    - Indirizzi fisici fino a **64GB**.
    - Lo spazio logico rimane a **32 bit**, ma viene suddiviso in blocchi di massimo 4GB.
2. **Dimensione configurabile della pagina**:
    - **4KB** o **2MB**.
3. **Protezione di esecuzione**:
    - Possibilità di marcare una pagina come **non eseguibile**, migliorando la sicurezza.
4. **Attivazione**:
    - Impostare il **bit 5 del registro CR4** a **1**.
### Formato dell'indirizzo lineare con PAE
Un indirizzo lineare utilizza i 32 bit disponibili per rappresentare i 36 bit dell'indirizzo fisico, suddiviso in:
1. **Page Directory Pointer Table (p1)**:
    - Punta alla **tabella principale**, che contiene riferimenti alle directory delle pagine.
2. **Page Directory (p2)**:
    - Punta alla **directory specifica** per individuare la tabella delle pagine corretta.
3. **Page Table (p3)**:
    - Contiene il mapping diretto alla pagina fisica.
4. **Offset (d)**:
    - Specifica la posizione esatta **all'interno della pagina**.
![[Pasted image 20241130113815.png|350]]
![[Pasted image 20241130113851.png|500]]
## Paginazione a quattro livelli
I processori a 64 bit (architettura x86-64) gestiscono un vasto spazio di indirizzamento grazie alla **paginazione a quattro livelli**, estendendo lo schema a tre livelli con l'aggiunta di una **Page Map Level 4 Table (PML4)**.
1. **Spazi di indirizzamento**:
    - **Virtuale**: **48 bit** (fino a **256TB**).
    - **Fisico**: **40 bit** (fino a **1TB**).
2. **Struttura a quattro livelli**:
    - Organizza lo spazio virtuale suddividendo l'indirizzo in più livelli di tabelle.
    - Ogni livello riduce gradualmente lo spazio indirizzato fino a individuare il frame fisico corretto.
### Formato dell'indirizzo lineare (48 bit)
Un indirizzo virtuale è suddiviso in:
1. **Page Map Level 4 Table (PML4, p1)**:
    - Puntatore alla tabella di livello più alto.
2. **Page Directory Pointer Table (PDPT, p2)**:
    - Puntatore alla directory delle directory delle pagine.
3. **Page Directory (p3)**:
    - Puntatore alla directory specifica.
4. **Page Table (p4)**:
    - Puntatore alla tabella finale che mappa i frame fisici.
5. **Offset (d)**:
    - Specifica la posizione all'interno della pagina.
![[Pasted image 20241130114455.png|500]]
## Paginazione a quattro livelli in Linux
Linux supporta sia la **paginazione a tre livelli** (PAE) sia la **paginazione a quattro livelli** (utilizzata in modalità long mode su architetture x86-64). La struttura gerarchica a quattro livelli consente di gestire efficientemente lo spazio di indirizzamento virtuale e fisico esteso.
### Struttura delle tabelle di paginazione
1. **Page Global Directory (PGD)**:
    - Contiene **512 elementi**, ciascuno puntatore alla **Page Upper Directory (PUD)**.
2. **Page Upper Directory (PUD)**:
    - Contiene **512 elementi**, ciascuno puntatore alla **Page Middle Directory (PMD)**.
    - Presente **solo nella paginazione a quattro livelli**.
3. **Page Middle Directory (PMD)**:
    - Contiene **512 elementi**, ciascuno puntatore alla **Page Table Entry (PTE)**.
4. **Page Table Entry (PTE)**:
    - Contiene **512 elementi**, ciascuno mappa un frame fisico.
5. **Offset**:
    - Specifica una posizione all'interno della pagina (da 0 a 4KB).
![[Pasted image 20241130114905.png|350]]
### Rappresentazione degli elementi
- Gli elementi delle tabelle di paginazione sono rappresentati come **unsigned long**, incapsulati in strutture specifiche.
    - **PGD**: `pgdval_t`.
    - **PUD**: `pudval_t`.
    - **PMD**: `pmdval_t`.
    - **PTE**: `pteval_t`.
Questi tipi di dato opachi sono definiti in **`$LINUX/arch/x86/include/asm/pgtable_64_types.h`**.  
Ogni valore contiene:
1. **Puntatore** alla tabella successiva.
2. **Informazioni di stato** (come permessi di accesso e flag di utilizzo).
## PTE (Page Table Entry)
Il **Page Table Entry (PTE)** contiene informazioni cruciali per la gestione della memoria virtuale. I campi principali sono:
1. **P (Present)**:
    - **1**: Il frame è presente in memoria RAM.
    - **0**: Il frame non è presente in RAM (può essere su disco, in swap).
2. **R/W (Read/Write)**:
    - **1**: Il frame è accessibile in modalità lettura/scrittura (read-write).
    - **0**: Il frame è accessibile solo in lettura (read-only).
3. **U/S (User/Supervisor)**:
    - **1**: Accesso permesso con CPL (Current Privilege Level) da 0 a 3 (modo utente o supervisore).
    - **0**: Accesso permesso solo con CPL 0-2 (modo supervisore).
4. **PWT (Page-level Write Through)**:
    - **1**: La CPU usa la modalità "write-through" per la cache, i dati vengono scritti direttamente in memoria.
    - **0**: La CPU usa la modalità "write-back", i dati vengono scritti in cache prima di essere scritti in memoria.
5. **PCD (Page-level Cache Disable)**:
    - **1**: Disabilita la cache della CPU per la pagina, impedendo che i dati vengano memorizzati nella cache.
    - **0**: La pagina è cacheable dalla CPU.
6. **A (Accessed)**:
    - **1**: La pagina è stata accessibile per la prima volta (indicata come "acceduta").
    - **0**: La pagina non è stata più acceduta da molto tempo.
7. **D (Dirty)**:
    - **1**: Il frame è stato modificato rispetto al suo stato originale (è "sporco").
    - **0**: Il frame non è stato modificato (è "pulito").
8. **G (Global Page)**:
    - **1**: La pagina è marcata come globale, quindi non viene distrutta da un cambiamento di contesto.
    - **0**: La pagina può essere eliminata durante un cambio di contesto.
9. **NX (No eXecute)**:
    - **1**: La pagina è marcata come non eseguibile, impedendo l'esecuzione di codice da quella pagina (utile per la protezione contro malware).
    - **0**: La pagina è eseguibile.
    - **Nota**: Il flag NX è disponibile solo in modalità PAE (Physical Address Extension) compatibile.
## Gestione delle tabelle PGD, PUD, PMD e PTE in Linux
1. **PGD (Page Global Directory)**:
    - La **PGD** è un array di tipo **pgd_t** e viene memorizzata nel descrittore di memoria di un processo (**struct mm_struct**).
    - **Funzioni di allocazione e deallocazione**:
        - **pgd_alloc()**: Alloca una nuova PGD, che consiste in un frame fisico di 4KB contenente 512 elementi da 64 bit (un puntatore a una tabella di secondo livello).
        - **pgd_free()**: Dealloca una PGD.
    - Definite in `$LINUX/arch/x86/mm/pgtable.c`.
2. **PUD (Page Upper Directory), PMD (Page Middle Directory), PTE (Page Table Entry)**:
    - La gestione delle tabelle **PUD**, **PMD** e **PTE** avviene con funzioni simili a quelle della PGD.
        - **PUD**: Gestito da **pud_alloc()** e **pud_free()**.
        - **PMD**: Gestito da **pmd_alloc()** e **pmd_free()**.
        - **PTE**: Gestito da **__pte_alloc()** e **pte_free()**.
    - Definite in `$LINUX/include/linux/mm.h` e `$LINUX/mm/memory.c`.
### Modifica delle tabelle di paginazione in Linux
Le tabelle di paginazione (PGD, PUD, PMD, PTE) contengono elementi che non solo mappano gli indirizzi ma anche mantengono uno stato interno (come i permessi di accesso, la presenza del frame in memoria, ecc.). In Linux, per modificare questi elementi vengono utilizzate funzioni specifiche, spesso definite nel file **`$LINUX/arch/x86/include/asm/pgtable.h`**.
- **Funzioni per PGD**:
    - **`native_set_pgd()`**: Imposta un elemento della PGD. Utilizzata per modificare il puntatore alla tabella di secondo livello.
    - **`native_clear_pgd()`**: Pulisce un elemento della PGD, rimuovendo l'associazione tra la PGD e la tabella di secondo livello.
- **Funzioni per PTE (Page Table Entry)**:
    - **`mk_pte()`**: Imposta l'indirizzo fisico di un frame in un elemento della PTE. Questa funzione è usata per aggiornare un'entrata nella tabella delle pagine (PTE) con l'indirizzo fisico di un frame, settando i bit di controllo come "presente" e "accesso read-write" o "read-only".
## Flag di Stato del Frame Fisico
Nel kernel Linux, oltre ai flag di stato utilizzati nelle tabelle delle pagine (come **Present**, **Read/Write**, ecc.), anche i **frame fisici** (ovvero le pagine fisiche di memoria) possiedono flag di stato che indicano il loro stato all'interno del sistema di memoria virtuale. Questi flag sono memorizzati nel campo `flags` della struttura **`struct page`**, che rappresenta un singolo frame fisico.
### Tipi di Flag nella Struttura `struct page`
Ogni frame fisico ha una serie di flag che possono indicare vari stati, come ad esempio:
- **PG_referenced**: Indica se il frame è stato referenziato.
- **PG_uptodate**: Indica se i dati nel frame sono aggiornati.
- **PG_dirty**: Indica se i dati nel frame sono stati modificati.
I flag sono definiti in una **enum** chiamata `pageflags`, contenente vari valori che rappresentano differenti stati del frame fisico. Il file che gestisce questi flag è **`$LINUX/include/linux/page-flags.h`**.
### Modello di Funzione per la Gestione dei Flag
Per gestire i flag associati ai frame fisici, il kernel Linux definisce una serie di **macro parametriche**. Queste macro creano delle funzioni che permettono di leggere, modificare o testare i flag in modo generico, senza dover scrivere codice ripetitivo.
Esempio di modello di funzione:
```c
#define TESTPAGEFLAG(uname, lname) \
static inline int Page##uname(const struct page *page) \
{ \
    return test_bit(PG_##lname, &page->flags); \
}
```
In questo esempio, il modello `TESTPAGEFLAG` definisce una funzione che testa un flag (ad esempio `PG_dirty`) nel campo `flags` della struttura `page`. Gli argomenti `uname` e `lname` sono utilizzati per generare il nome della funzione e il nome del flag.
### Esempio di Invocazione del Modello
Per il flag **PG_dirty**, il modello genera una funzione come segue:
```c
TESTPAGEFLAG(Dirty, dirty)
```
Il preprocessore genera il seguente codice:
```c
static inline int PageDirty(const struct page *page) 
{ 
    return test_bit(PG_dirty, &page->flags); 
}
```
Questa funzione può quindi essere utilizzata per verificare se il flag `PG_dirty` è impostato su un determinato frame fisico.
- **Ricerca delle Funzioni**: Le funzioni generate tramite questi modelli (ad esempio `PageDirty()`, `SetPageDirty()`, `ClearPageDirty()`, ecc.) **non sono facilmente individuabili** con una semplice ricerca `grep`. È necessario investigare più a fondo nel codice e comprendere i modelli di funzione utilizzati per la loro generazione.
- **Funzioni per Modificare i Flag**: Oltre alle funzioni di test come `PageDirty()`, sono definite anche funzioni per modificare i flag, come `SetPageDirty()` per impostare il flag o `ClearPageDirty()` per resettarlo.
# Paginazione: Supporto alla Protezione
In Linux, la protezione della memoria viene gestita principalmente a livello di **paginazione**, piuttosto che attraverso la segmentazione, grazie al **flat memory model**.
## Flat Memory Model e Paginazione
Nel **flat memory model**, tutti gli indirizzi virtuali sono trattati come se appartenessero a un unico spazio di memoria lineare, senza la necessità di segmenti distinti come accade in altri modelli di memoria. La segmentazione, quindi, non viene più utilizzata per la protezione della memoria nei processi. Invece, la protezione dell'accesso alla memoria è implementata direttamente nel sistema di **paginazione**.
### Bit di Protezione nella Paginazione
I bit di protezione sono aggiunti agli **elementi delle tabelle delle pagine** per definire le operazioni consentite su ciascun frame di memoria. I principali bit di protezione includono:
- **Read/Write**: Specifica se un frame di memoria può essere letto e/o scritto.
- **U/S (User/Supervisor)**: Determina se l'accesso è permesso da un livello utente (CPL 3) o solo da un livello kernel (CPL 0-2).
- **NX (No Execute)**: Indica se il codice in un frame di memoria può essere eseguito o meno (utilizzato per prevenire l'esecuzione di codice da parti di memoria non eseguibili).
Quando un processo tenta di eseguire un'operazione che non è compatibile con i permessi associati al frame di memoria, il **processore** segnala l'anomalia al **kernel**, impedendo l'operazione.
### General Protection Fault
Se un processo tenta di eseguire un'operazione illegale, come un accesso fuori dai limiti di memoria o l'esecuzione di codice non eseguibile, il processore genera un **General Protection Fault**. Questo errore segnala una violazione dei permessi di accesso alla memoria.
Il kernel gestisce l'eccezione con un **handler** `do_general_protection()`, che può svolgere diverse operazioni in base alla natura dell'accesso illecito:
- Se l'accesso illegale è stato fatto dal **kernel**, il sistema si blocca.
- Se l'accesso illecito è stato fatto da un **processo utente**, il processo viene terminato con un **segnale 11** (che corrisponde a un **segmentation fault** o **SIGSEGV**), che indica un errore di accesso alla memoria.
# Paginazione: Supporto alla Memoria Vituale
La gestione della memoria virtuale in un sistema operativo come Linux si basa su un insieme di bit di stato all'interno delle tabelle delle pagine. Questi bit permettono di tracciare l'associazione delle pagine virtuali a frame fisici, di gestire l'allocazione dinamica della memoria e di rilevare errori come le violazioni di accesso a pagine non valide.
## Bit di Validità
Ogni elemento della tabella delle pagine è associato a un **bit di validità** che indica se la pagina virtuale è associata a un frame fisico o meno. Il **bit "Present"** nelle tabelle delle pagine viene utilizzato per determinare se la pagina è valida o meno. Ad ogni accesso, il processore verifica la validità della pagina:
- Se la pagina non è valida, il **processore segnala l'anomalia al kernel**, generando una **Page Fault**.
## Page Fault
Quando il processore accede a una pagina non valida, si verifica una **Page Fault**, un'eccezione che segnala il tentativo di accesso a una pagina che non è attualmente mappata in memoria. Il **handler** per la page fault, `do_page_fault()`, esegue le seguenti operazioni:
- Memorizza l'indirizzo dell'accesso invalido (contenuto nel registro CR2).
- Verifica se l'indirizzo è all'interno dello spazio di indirizzamento di un processo:
    - Se l'indirizzo non è valido, verifica se l'accesso è stato effettuato dal **kernel** (in tal caso causa un crash del sistema).
    - Se l'indirizzo è valido per un processo utente, si associa la pagina a un **frame fisico**.
### Associazione della Pagina al Frame
Per associare una pagina a un frame fisico, la funzione `handle_mm_fault()` aggiorna le tabelle di paginazione e invoca altre funzioni come `handle_pte_fault()` per gestire la mappatura. La funzione che gestisce l'allocazione dinamica di memoria è **`do_anonymous_page()`**, mentre per caricare un blocco da disco si utilizza **`do_linear_fault()`**.
## Bit di Lock
Per alcune pagine che devono rimanere permanentemente associate a un frame fisico (come nel caso di memoria condivisa o pagine di I/O), si usa un **bit di lock**:
- **Bit "Global"** nelle tabelle delle pagine e il flag **"PG_mlocked"** nella struct `page` indicano che una pagina è associata permanentemente a un frame fisico.
    - Se il bit è **1**, l'associazione è permanente e non può essere interrotta.
    - Se il bit è **0**, l'associazione può essere rimossa dal kernel per permettere la riallocazione del frame.
## Bit di Modifica
Il bit di **modifica** (Dirty) in una tabella delle pagine viene utilizzato per tracciare se una pagina caricata da disco è stata modificata rispetto al suo stato originale:
- **Bit "Dirty"** nelle tabelle e il flag **"PG_dirty"** nella struct `page` vengono impostati a **1** quando una pagina è stata modificata. In questo caso, la pagina deve essere **sincronizzata su disco** prima che venga sostituita o rimossa.
- Se il bit è **0**, la pagina non è stata modificata e non necessita di essere salvata su disco.
***
# T-13 Gestione memoria processi
## Riassunto dei Meccanismi di Gestione della Memoria
I meccanismi di gestione della memoria che sono emersi come vincenti per il funzionamento di un sistema operativo moderno sono i seguenti:
1. **Modello di Memoria Flat**: In questo modello, la memoria non è segmentata, ma trattata come un unico blocco continuo. Questo semplifica l'accesso e la gestione della memoria, eliminando la necessità di segmenti separati per dati e codice.
2. **Spazio di Indirizzamento Partizionato Dinamicamente**: Lo spazio di indirizzamento di ogni processo viene suddiviso dinamicamente in segmenti o pagine. In questo modo, la memoria può essere gestita in modo più flessibile e l'allocazione di memoria può essere ottimizzata.
3. **Allocazione Dinamica della Memoria**: La memoria viene allocata dinamicamente a ciascun processo durante la sua esecuzione, riducendo il rischio di allocare inutilmente grandi quantità di memoria che non sono subito necessarie.
4. **Separazione degli Spazi degli Indirizzi Kernel e User**: Il sistema operativo isola lo spazio di memoria riservato al kernel da quello utilizzato dai processi utente. Questo impedisce ai processi utente di accedere direttamente alla memoria del kernel, garantendo la protezione della memoria.
5. **Paginazione della Memoria**: La memoria virtuale viene gestita tramite il sistema di paginazione, in cui la memoria virtuale è suddivisa in pagine di dimensioni fisse. Le pagine sono mappate su frame fisici in modo flessibile, migliorando l'efficienza nell'uso della memoria.
6. **Associazione Ritardata delle Pagine ai Frame Fisici**: Le pagine virtuali non vengono necessariamente caricate in memoria immediatamente. Solo quando una pagina è effettivamente richiesta dal programma (ad esempio, tramite una page fault), essa viene mappata a un frame fisico. Questo meccanismo permette di risparmiare memoria e migliorare l'efficienza.
## Problema: Allocazione Completa
Un problema che emerge quando si cerca di implementare una gestione della memoria efficiente è l'**allocazione completa**. In un approccio semplice, si potrebbe pensare che caricare completamente un programma in memoria non appena viene eseguito sia un approccio naturale. Tuttavia, questo porterebbe a un'inefficienza enorme:
- Se un programma viene caricato completamente in memoria, si esaurirebbe rapidamente la memoria principale, specialmente in ambienti con molte applicazioni in esecuzione.
- Quando la memoria si esaurisce, le nuove applicazioni non possono partire, riducendo drasticamente il grado di multiprogrammazione, ovvero il numero di processi che possono essere eseguiti contemporaneamente.
Per evitare questa inefficienza, è necessario adottare un approccio che supporti la **memoria virtuale** e la **paginazione**, consentendo di caricare in memoria solo le pagine necessarie per l'esecuzione del programma in quel momento. Questo approccio consente di ottimizzare l'uso della memoria disponibile e aumentare l'efficienza del sistema.
### Esempio: LibreOffice
Quando si carica un'applicazione grande come **LibreOffice**, si rischia di trasferire in memoria un enorme quantitativo di dati, che può risultare inefficiente. Un esempio pratico di come calcolare la memoria richiesta da LibreOffice su Linux è:
- Usando il comando `pmap $(pgrep soffice.bin)`, si possono sommare i valori della seconda colonna per ottenere il totale della memoria in KB consumata dal processo.
### La Domanda Esistenziale: Serve davvero tutta quella qemoria?
Quando si carica un'applicazione come LibreOffice, si deve chiedere se è davvero necessario caricare tutto in memoria subito:
- **Tutto il codice di LibreOffice viene eseguito subito?**
- **Tutti i font sono usati immediatamente?**
- **Tutti i menu e le funzionalità vengono invocati al primo avvio?**
Molti dei dati caricati potrebbero essere inutilizzati in fase iniziale. Quindi, caricare tutto in memoria fin dall'inizio è inefficiente. Molti dati potrebbero essere caricati solo quando effettivamente necessari, attraverso il cosiddetto **caricamento pigro (lazy loading)**.
### Esempio di Allocazioni Grandi
Un altro esempio riguarda le applicazioni che richiedono grandi allocazioni di memoria, come **macchine virtuali** o **videogiochi**. Ad esempio, una macchina virtuale potrebbe richiedere 2 GB di memoria:
- **Tutta quella memoria è usata subito o a breve?**
- **Cosa fare se l'allocazione eccede la memoria fisica disponibile?**
Il rischio è che la memoria venga prenotata ma non utilizzata tutta subito, portando a inefficienze. Se l'allocazione eccede la memoria fisica disponibile, il sistema deve decidere come gestirla senza bloccare il processo, ad esempio con la **memoria virtuale**.
### La Soluzione: Caricamento Pigro (Lazy Loading)
Il caricamento pigro è un approccio in cui il sistema carica in memoria solo le porzioni necessarie di un programma, anziché tutto il programma in una volta. L'idea è la seguente:
1. **Associazione di Aree di Indirizzi Lineari alle Componenti**: Il kernel associa aree di indirizzi lineari alle diverse componenti di un'applicazione (es. codice del programma, dati, librerie, stack).
2. **Associazione dei File a Quelle Aree**: I file relativi all'applicazione (es. il file eseguibile `soffice.bin` e le librerie come `libc.so.6`) vengono associati alle aree di indirizzo, ma non vengono caricati completamente in memoria.
3. **Caricamento a Richiesta**: Quando la CPU accede a una parte del programma (ad esempio, una funzione specifica o un dato), il sistema carica in memoria **solo quella parte**, tramite **page fault**.
### È Possibile Implementarlo in Modo Efficiente?
Il caricamento pigro può essere implementato in modo efficiente sfruttando meccanismi hardware supportati dai processori Intel, come descritto precedentemente:
- **Bit delle PTE (Page Table Entry)**: Ogni PTE contiene informazioni sullo stato di validità delle pagine. Se una pagina non è valida, si genera un **page fault**.
- **Page Fault**: Quando si verifica un page fault, il sistema può associare una pagina a un frame fisico, caricandola dalla memoria secondaria (ad esempio, disco) a quello fisico in memoria centrale. In questo modo, si caricano in memoria solo le pagine effettivamente utilizzate.
### Vantaggi del Caricamento Pigro
1. **Efficienza della Memoria**: Si carica in memoria solo ciò che è necessario per l'esecuzione immediata dell'applicazione, risparmiando risorse.
2. **Riduzione del Consumo di Memoria**: Riduce il consumo di memoria fisica, soprattutto in applicazioni di grandi dimensioni come LibreOffice, evitando di caricare porzioni di codice o dati che non vengono utilizzati subito.
3. **Supporto alla Virtualizzazione**: Questo approccio è particolarmente utile in scenari di virtualizzazione (macchine virtuali), dove vengono richieste grandi allocazioni di memoria, ma solo una parte di essa viene utilizzata in un dato momento.
# Memoria virtuale
Il sistema di **memoria virtuale** è una estensione della *paginazione*:
L'idea è quella di legare una *pagina* a:
- un frame fisico(paginazione base).
- oppure un **blocco di file**.
- oppure un **blocco del disco**.
Così:
- alcune porzioni della memoria di un processo sono caricate in memoria, mentre altre no.
- alcune porzioni della memoria di un processo possono essere inserite in swap, mentre altre no.
![[Pasted image 20241130170957.png|500]]
## Spazio di indirizzamento lineare
Lo **spazio di indirizzamento lineare** di un processo rappresenta l'intervallo di indirizzi che il processo può utilizzare per accedere alla memoria. Questo spazio è una rappresentazione astratta della memoria, che permette al processo di lavorare come se avesse un'area di memoria dedicata e continua, indipendentemente dalla disposizione fisica della memoria stessa.
1. **Sequenza di indirizzi lineari**:
    - Ogni processo dispone di un **intervallo continuo di indirizzi**, detto spazio di indirizzamento.
    - Questi indirizzi sono **virtuali** e vengono tradotti dal kernel e dall'hardware (MMU - Memory Management Unit) in indirizzi fisici.
2. **Organizzazione in segmenti**:
    - Lo spazio è diviso in aree di memoria contigue, ognuna delle quali ha uno scopo specifico:
        - **Segmento codice**: contiene il codice eseguibile del programma.
        - **Segmento dati**: per variabili globali, dati statici, ecc.
        - **Heap**: utilizzato per la memoria dinamica (malloc, new).
        - **Stack**: utilizzato per le chiamate di funzione e le variabili locali.
3. **Gestione pigra (lazy)**:
    - Solo le parti di memoria effettivamente necessarie vengono caricate o allocate.
    - Le aree non usate rimangono non allocate, riducendo il consumo di memoria fisica.
    - Meccanismi come i **page fault** permettono di caricare dinamicamente le porzioni richieste.
![[Pasted image 20241130171348.png|500]]
## Descrittore di memoria
1. **Posizione del descrittore di memoria**:
    - Ogni processo in Linux ha una struttura `task_struct` che descrive tutte le sue caratteristiche principali.
    - Il campo `mm` all'interno di `task_struct` contiene un puntatore a una struttura `mm_struct`, che è il **descrittore di memoria** del processo.
2. **Struttura `mm_struct`**:
    - Definita nel file `mm_types.h`.
    - Contiene informazioni dettagliate sullo spazio di indirizzamento del processo, organizzate per segmento (testo, dati, heap, stack, ecc.).
### Campi principali di `mm_struct`

|Campo|Descrizione|
|---|---|
|**start_stack**|Indirizzo iniziale dello stack del processo.|
|**mmap_base**|Indirizzo iniziale dell'area `mmap`, utilizzata per il mapping di file e librerie.|
|**start_brk**|Indirizzo iniziale dell'heap, utilizzato per allocazioni dinamiche (`malloc`).|
|**brk**|Indirizzo corrente di fine dell'heap (variabile, in base alle allocazioni).|
|**start_data**|Indirizzo iniziale del segmento dati (dati globali e statici del programma).|
|**end_data**|Indirizzo finale del segmento dati.|
|**start_code**|Indirizzo iniziale del segmento testo (codice eseguibile).|
|**end_code**|Indirizzo finale del segmento testo.|
## Mappatura di memoria
In Linux, la gestione delle aree di memoria di un processo avviene tramite un approccio **pigro** e flessibile, che associa dinamicamente le aree di memoria a file, frame fisici, o blocchi di swap solo quando necessario. Di seguito una panoramica dettagliata del funzionamento.
1. **Mappatura Pigra**:
    - Le singole pagine di un'area possono puntare a:
        - Un **blocco di disco** (file-backed).
        - Un **frame fisico** (anonymous mapping).
        - Un **blocco di swap**.
        - **Nulla** (pagina non ancora mappata).
2. **Associazione On-Demand**:
    
    - L'associazione avviene solo quando la CPU genera un indirizzo lineare che appartiene all'area e tenta di accedervi (page fault).
### Aree di Memoria File-Backed
1. **Definizione**:
    - Un'area si dice **file-backed** quando il suo contenuto è associato a un file su disco.
2. **Campo `vm_file`**:
    - La struttura `vm_area_struct` contiene un campo `vm_file`, un puntatore alla struttura **`file`** che rappresenta il file associato.
3. **Gestione delle Operazioni**:
    - Le operazioni di mappatura variano in base al file system. Si utilizza la struttura **`vm_operations_struct`**, che contiene i puntatori alle funzioni per:
        - Creazione della mappa.
        - Distruzione della mappa.
        - Gestione dei page fault.
4. **Page Fault Handler**:
    - In caso di page fault, il kernel invoca la funzione `fault()` definita nella struttura `vm_operations_struct` tramite il puntatore `vm_ops` della `vm_area_struct`.
### Aree di Memoria Anonime
1. **Definizione**:
    - Un'area si dice **anonima** quando il suo contenuto non è associato a un file su disco, ma direttamente a frame fisici.
2. **Campo `anon_vma`**:
    - La `vm_area_struct` contiene un campo `anon_vma`, un puntatore alla struttura **`anon_vma`** che rappresenta i frame fisici mappati.
### Permessi di Accesso
1. **Tipologie di Permessi**:
    - **`VM_READ`**: Lettura.
    - **`VM_WRITE`**: Scrittura.
    - **`VM_EXEC`**: Esecuzione.
2. **Campo `vm_flags`**:
    - I permessi sono memorizzati nel campo `vm_flags` della `vm_area_struct` e vengono utilizzati dal kernel per verificare le operazioni richieste dagli utenti.
### Collegamento delle Aree di Memoria
- In passato, le `vm_area_struct` erano collegate tramite liste doppie (`vm_next`, `vm_prev`).
- **Limite**: La ricerca di un'area richiedeva una scansione lineare, risultando inefficiente.
- Oggi, le `vm_area_struct` sono organizzate in **alberi rosso-neri** ordinati in base all'indirizzo iniziale (`vm_start`).
- **Vantaggi**:
    - Efficienza: La ricerca di un'area è logaritmica rispetto al numero totale di aree.
- **Implementazione**:
    - Ogni nodo dell'albero contiene una `struct rb_node`.
    - La `vm_area_struct` include un campo `vm_rb` di tipo `struct rb_node` per l'inserimento nell'albero.
    - La radice dell'albero è memorizzata nel campo `mm_rb` della `mm_struct`.

|**Tipo di Area**|**Campo Associato**|**Gestione**|
|---|---|---|
|File-Backed|`vm_file`|Mappata a un file su disco.|
|Anonymous|`anon_vma`|Mappata a frame fisici in RAM.|
|Permessi|`vm_flags`|Lettura, Scrittura, Esecuzione.|
|Collegamento|`vm_rb` (rb_node)|Albero rosso-nero per lookup rapido.|
![[Pasted image 20241201120853.png|500]]
## Gestione aree di memoria
Linux offre diverse funzionalità per gestire dinamicamente le aree di memoria nei processi. Ogni operazione è implementata utilizzando strutture come **alberi rosso-neri** e **liste collegate**, rendendo il sistema efficiente e flessibile.
### Individuazione di un'Area di Memoria
- **Scopo**: Identificare l'area di memoria contenente (o vicina a) un dato indirizzo lineare.
- **Esempio d'uso**: Controlli di accesso.
- **Funzione**: `find_vma()`
    - Scandisce l'albero rosso-nero puntato da `mm_rb`.
    - Restituisce la `vm_area_struct` associata all'indirizzo o quella più vicina.
- **File**: `$LINUX/mm/mmap.c`.
### Individuazione di un'Area Libera
- **Scopo**: Trovare uno spazio libero per allocare una nuova area di memoria.
- **Esempi**:
    - Esecuzione di una nuova immagine.
    - Creazione manuale di mappe anonime.
- **Funzione**: `get_unmapped_area()`
    - Scandisce l'albero rosso-nero per identificare un intervallo di indirizzi non occupato.
- **File**: `$LINUX/mm/mmap.c`.
### Creazione di un'Area di Memoria
- **Scopo**: Creare una nuova area di memoria.
- **Funzione**: `insert_memory_region()`
    - Inserisce la nuova area sia nella lista collegata, sia nell'albero rosso-nero.
- **Responsabile**:
    - **Kernel**: Per scopi interni.
    - **Utente**: Tramite la chiamata di sistema `mmap()`.
- **File**: `$LINUX/mm/mmap.c`.
### Distruzione di un'Area di Memoria
- **Scopo**: Rimuovere un'area di memoria.
- **Funzione**: `do_munmap()`
    - Aggiorna sia la lista collegata sia l'albero rosso-nero.
- **Responsabile**:
    - **Kernel**: Per necessità interne.
    - **Utente**: Con la chiamata di sistema `munmap()`.
- **File**: `$LINUX/mm/mmap.c`.
### Spostamento di un'Area di Memoria
- **Scopo**: Evitare sovrapposizioni di aree in caso di espansione.
    - Ad esempio, se un'area cresce e collide con un'altra, può essere spostata in un'altra posizione.
- **Funzione**: `mremap()`
    - Permette anche l'estensione di un'area (spostando un estremo).
- **File**: `$LINUX/mm/mremap.c`.
### Memory Locking di un'Area
- **Scopo**: Impedire che un'area venga inserita in swap.
    - Gli accessi saranno sempre effettuati dalla memoria centrale, garantendo velocità.
- **Funzioni**:
    - `mlock()`: Blocca l'area in memoria, impostando il flag `VM_LOCKED`.
    - `munlock()`: Rimuove il blocco.
- **Attenzione**:
    - Un utilizzo eccessivo può ridurre la memoria centrale disponibile per altre operazioni.

|**Operazione**|**Funzione**|**Descrizione**|**File**|
|---|---|---|---|
|Individuazione area|`find_vma()`|Trova l'area che contiene un indirizzo.|`$LINUX/mm/mmap.c`|
|Ricerca area libera|`get_unmapped_area()`|Trova un'area libera per nuove allocazioni.|`$LINUX/mm/mmap.c`|
|Creazione area|`insert_memory_region()`|Crea e inserisce un'area in liste e alberi.|`$LINUX/mm/mmap.c`|
|Distruzione area|`do_munmap()`|Rimuove un'area di memoria.|`$LINUX/mm/mmap.c`|
|Spostamento area|`mremap()`|Sposta un'area o ne estende un estremo.|`$LINUX/mm/mremap.c`|
|Blocco in memoria|`mlock()` / `munlock()`|Blocca/sblocca un'area in memoria per evitare che venga spostata in swap.|`$LINUX/include/linux/mm.h`|
# Paginazione su richiesta
La **paginazione su richiesta** (_demand paging_) è una tecnica che gestisce in modo efficiente lo spazio di indirizzamento di un processo caricando in memoria centrale solo le pagine effettivamente richieste durante l'esecuzione. Questo meccanismo si basa su una gestione pigra delle aree di memoria, evitando di allocare o caricare preventivamente tutte le risorse di un processo.
La paginazione su richiesta richiede uno **sforzo congiunto** di diversi livelli del sistema:
1. **Hardware**:
    - **Page fault**: Interruzioni generate quando un processo accede a una pagina non presente in memoria.
    - **Bit di accesso e validità**: Utilizzati per determinare lo stato delle pagine (presente/non presente, lettura/scrittura/esecuzione).
2. **Kernel**:
    - **Gestione delle aree di memoria**: Il kernel utilizza strutture dati come `mm_struct` e `vm_area_struct` per rappresentare lo spazio di indirizzamento e le aree di memoria.
    - **Page fault handler**: Gestisce le eccezioni, carica le pagine richieste, aggiorna le tabelle delle pagine e, se necessario, utilizza lo swap.
3. **Librerie di sistema**:
    - **Caricamento del programma**: Preparano lo spazio di indirizzamento lineare mappando le risorse necessarie (codice, dati, stack).
    - **Creazione di nuove aree di memoria**: Tramite chiamate di sistema come `mmap()` per aree anonime o file-backed.











