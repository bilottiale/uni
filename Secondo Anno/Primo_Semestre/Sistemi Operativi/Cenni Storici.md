**Sistema operativo**: software che agisce da intermediario fra l'utente e l'hardware del calcolatore stesso.
### Responsabilità
#### Allocazione di risorse
Il SO alloca le risorse a sua disposizione (tempo di CPU, spazio su disco, porzioni di memoria) a programmi e utenti, in base alle necessità. Il SO risolve i conflitti di assegnazione delle risorse in modo tale da operare efficientemente e correttamente.
#### Programma di controllo
Il SO è un gigantesco programma di controllo. Coordina l'esecuzione dei programmi, impedisce usi delle risorse non corretti, impedisce usi delle risorse maliziosi.

# Cenni storici
## Macchina di Atanassov-Berry (1937)
Uso di digit binari per la rappresentazione dei numeri. Calcolo tramite componenti elettronici. Unità di calcolo separata da unità di memoria. Uso di memoria “*rigenerativa*”. Assenza di stored program. Assenza di SO.
*Rigenerativa*: la macchina non perde mai davvero i dati, perché è capace di rigenerarli o ricrearli da zero se necessario.
## Colossus (1944)
Primo calcolatore digitale britannico. Sviluppato a Bletchley Park dal team di **Alan Turing**. Fu in grado di rompere il codice cifrato *ENIGMA*, usato dai nazisti per le comunicazioni. Programmabile mediante switch. Assenza di SO.
## Alan Turing (1912-1954)
Ideatore del modello matematico alla base di un calcolatore “*universale*”: la **Macchina di Turing**.
Pioniere della teoria della computazione.
Pioniere della crittoanalisi.
Pioniere della intelligenza artificiale (Test di Turing).
Pioniere della bioinformatica.
## John Von Neumann (1903-1957)
Inventore del modello architetturale di un moderno calcolatore. Studioso dei sistemi di telecontrollo dei missili. Fondatore della cosiddetta *teoria dei giochi*.
*Teoria dei giochi*: studia le decisioni che le persone o i gruppi prendono quando sono in competizione o cooperazione tra loro.
## Claude Elwood Shannon (1916-2001)
Il padre della teoria dell'informazione. Trasmissione digitale (1938).
Inventore del termine “*bit*” (1948). Studioso di ricostruzione e compressione dei segnali trasmessi. Teorema del campionamento. Fondatore della crittografia (1949).
[The sound of 56K connection... AMAZING!](https://www.youtube.com/watch?v=OGwlwZs9PxE&ab_channel=madD.)
## Harvard Mark I (1944)
Progettato da Howard Aiken. Primo calcolatore in grado di eseguire calcoli complessi per un lungo periodo di tempo. Lungo 16m, alto 2.4m, profondo 0.5m, peso 4.5Ton, memoria 72 numeri da 23 cifre decimali. Assenza di SO.
## Grace Murray Hopper (1906-1992)
Primo programmatore di calcolatori digitali (*Harvard Mark I*). Inventrice del *COBOL*. Inventrice del termine “*bug*” (1946) riferito agli errori nel software.
### Problemi dei primi sistemi
Schema di prenotazione scomodo e inefficiente.
Assenza di librerie generiche per la gestione delle risorse.
Immissione dei programmi scomoda.
Diagnosi e riparazione del sistema alquanto problematica.
### Migliorie
Ambiente di sviluppo standardizzato.
"*Driver*" per le periferiche (*ponte* tra hw/sw).
Assemblatori, compilatori, linker per eseguibili.
Librerie di funzioni comuni.
Periferiche avanzate (*lettori di schede*, *stampanti*, *nastri*).
- Es: *schede perforate IBM*: (Fortran, 1964)
![[Pasted image 20241014092344.png]]
## Sistemi Batch (1950-1960)
#### Idea di fondo
Risparmiare all'operatore le operazioni di gestione della macchina, ai tempi complesse e soggette ad errore umano.
#### Job
Un programma “*impacchettato*” in una sequenza di operazioni, memorizzate quasi tutte su schede perforate.
*Operazioni di un job*:
- Inserimento e caricamento nastro *compilatore*.
- Esecuzione nastro compilatore.
- Rimozione nastro compilatore.
- Inserimento e caricamento nastro *assemblatore*.
- Esecuzione nastro assemblatore.
- Rimozione nastro assemblatore.
- Inserimento e caricamento nastro *programma oggetto*.
- Esecuzione nastro programma oggetto.
- Rimozione nastro programma oggetto.
*Problemi dei job*:
- Tempo per la preparazione di un job elevato.
- Esecuzione alternata di programmi scritti in linguaggi diversi è scomoda.
- L'interruzione di un job è problematica.
#### Batch processing
Il calcolatore esegue una sequenza di job con ridotto ausilio dell'operatore.
### Soluzioni
- Operatore professionista.
- *Sequenzializzatore automatico dei job* (**monitor residente**).
## Monitor residenti
### Caricatore
Carica il programma in memoria.
### Sequenzializzatore
Sceglie il prossimo job da eseguire.
### Interprete
Gestisce le cosiddette “*schede di controllo*” che indicano al monitor quale programma eseguire.
**Schede di controllo**: ogni programma è descritto da una scheda di controllo che lo attiva.
Un job è delimitato da due schede speciali di controllo: $JOB, $END.
#### Problemi dei sistemi Batch
Velocità I/O << Velocità CPU, quindi spesso inattiva. Tempi morti -> consumo elettrico inutile.
## Sovrapposizione I/O (1950-1960)
Si cerca di far lavorare simultaneamente il processore e la periferica di I/O.
- Il disaccoppiamento fra I/O e calcolo dovrebbe permettere al processore di lavorare a pieno regime.
- Due nastri usati in parallelo la tengono occupata tutto il tempo.
### Funzionamento offline
L'elaboratore è separato fisicamente dalle periferiche.
- Le schede perforate sono riversate su nastri veloci.
- Il nastro veloce è montato sull'elaboratore.
- La CPU legge i dati dal nastro veloce.
- Il calcolatore riversa i dati su nastro veloce.
- Il nastro veloce viene montato su una periferica di I/O.
Nel frattempo, il calcolatore riceve un nuovo nastro veloce -> Funzionamento in pipeline.
*Problemi*:
- Uso di più macchine separate: maggiore ingombro e consumo elettrico.
- Le procedure “*fuori linea*” devono essere svolte a mano, lente e soggette ad errore umano.
- Il nastro è acceduto sequenzialmente.
*Soluzione*:
- **Unità a disco rigido**, accessibili in maniera diretta.
**Spool**:
![[Pasted image 20241014100059.png]]
### Spooling
*Simultaneous*
*Peripheral*
*Operations*
*On*
*Line*
I dati sono riversati sotto forma di file temporanei sul disco. L'accesso ai dati è diretto.
*Vantaggi*:
- *Multitasking*.
- Maggiore utilizzo CPU.
*Svantaggi*:
- Sovrapposizione limitata dalle periferiche lente.
## Multiprogrammazione (1960)
I job sono eseguiti fino a quando non si verifica attesa sull'I/O. Quando un job è in attesa di I/O, il sistema ripristina l'esecuzione di un altro job.
### Requisiti
**Spooler**: disco rigido per input e output.
**Scheduler dei job**: organizza l'esecuzione dei job.
**Gestore della memoria**: gestisce l'allocazione della memoria principale.
 ![[Pasted image 20241014100643.png|350]]
 ![[Pasted image 20241014100710.png|350]]
## Edsger W. Dijkstra (1930-2002)
**SO THE**.
Singolo utente.
Multitasking.
Batch.
Inventore del costrutto di sincronizzazione semaforo.
Inventore dell'algoritmo del banchiere per l'assegnazione delle risorse.
## Sir Charles Anthony Hoare (1934-Oggi)
Ideatore *ALGOL60*.
Ideatore *Quick Sort*.
Inventore del costrutto di sincronizzazione monitor.
## John Backus (1924-2007)
Ideatore *FORTRAN*.
Ideatore del formalismo *Backus Naur Form* per la descrizione formale della sintassi di un linguaggio.
### Problemi ancora non risolti
- Mancanza di *interattività* con l'utente.
- L'output richiede anche giorni per essere ricevuto.
## Time Sharing (1960)
La CPU esegue più job concorrentemente.
I job possiedono a turni la CPU per un intervallo di tempo detto *quanto*.
*Vantaggi*:
- Maggiore *interattività*.
- Sistemi multi-utente con interfaccia su **terminale fisico**.
![[Pasted image 20241014102051.png|350]]
## MULTICS (1964-1969)
Primo *SO*.
- Time sharing
- Multiprogrammato
- Multiutente
Antesignano di *UNIX*.
## DEC PDP-1 (1960)
*Programmed Data Processor I*.
Primo minicomputer a basso costo (120K$).
Primo SO in grado di eseguire un videogioco multi utente real time. **Spacewar!**
## DEC PDP-10 (1964-1983)
Usato in diverse università americane.
- MIT AI Lab
- Stanford AI Lab
- Carnegie Mellon
SO: *TOPS-10*.
## IBM System/370 (1970-1990)
Memoria principale basata su circuiti integrati.
Supporto per la memoria virtuale.
*Aritmetica floating point*.
Virtualizzazione.
OS: *VM/370*.
## DEC VAX (1977-1989)
Estensione a 32 bit del PDP (**V**irtual **A**ddress e**X**tension).
Paginazione su richiesta.
OS: *VMS*.
## UNIX (1969-)
Riscrittura semplificata di MULTICS.
*Obiettivo del progetto*: eseguire in maniera efficiente il videogioco “**Space Travel**”.
- Simulatore spaziale
- Antenato di ["Celestia"](https://celestiaproject.space/).
## Ken Thompson (1943-)
Coautore di *UNIX*.
Ideatore del linguaggio B (Precursore di C).
Coautore del *C*.
Autore dell'editor *ed* (antenato di *vi*).
Ideatore del sistema di codifica dei caratteri *UTF-8*.
Co-inventore del linguaggio *Go*.
## Dennis Ritchie (1941-2011)
Coatuore di *UNIX*.
Coutore del *C*.
## Brian Kernighan (1942-)
Coautore del *C*.
Autore di diverse utility UNIX.
## Bell Labs UNIX Time Sharing System
Prima distribuzione UNIX: UNIX Bell Labs.
## John Lions (1937-1998)
Decide di commentare l'intero codice di UNIX v6 e distribuisce in forma pirata il documento. Tale documento, passato di generazione in generazione, è oggi un libro.
## Bill Joy (1954-)
Creatore prime versioni di *BSD UNIX*.
Creatore dell'editor *vi*.
Fondatore della *Sun Microsystems*.
Ha corretto, migliorato e portato su BSD 4.3 lo stack **TCP/IP**, primo UNIX a *navigare su internet*.
## Richard Matthew Stallman (1953-)
Pioniere del *Free Software Movement*.
Creatore della *Free Software Foundation*.
Creatore del SO *GNU*.
Creatore di utility fondamentali quali *GCC*, *GDB*, *Gmake*, *GNU Emacs*.
## Pecca di GNU
Assenza di **Kernel** (il software che colloquia con le periferiche). Era necessario per installare GNU su un sistema UNIX esistente.
## Linus Benedict Torvalds (1969-)
scrivere un kernel sul suo 80386, “per hobby”.
Il kernel prenderà il nome di **Linux** e integrerà GNU.
Si parlerà di GNU/Linux.
È inoltre autore di:
- **GIT**.
- **SubSurface**.
## Home Computing (1970-)
Il calcolatore non viene più visto solo come uno strumento di calcolo. Si punta al mercato casalingo.
- Videogiochi.
- Small office.
## Nolan Bushnell (1943-)
Fondatore del primo grande colosso dei videogiochi. **Atari** (1972).
### Console videogiochi
Architetture hardware dedicate e poco costose.
Sistemi operativi dedicati, generalmente monoutente e monoprogrammati.
Sistemi programmabili in linguaggio macchina o in BASIC.
Periferiche alquanto primitive (nastri, floppy, ROM, joystick, video e audio).
## IBM Personal Computer (1981-1987)
Modello attuale di calcolatore pensato per uso domestico.
Realizzato con componenti producibili facilmente su larga scala.
Enormemente più potente e versatile delle console precedenti.
Architettura aperta ed espandibile.
## PC compatibili (1985-)
I PC vengono “assemblati” a partire da componenti prodotti a basso costo.
Il mercato del PC originale crolla.
Alcune aziende si specializzano sulla produzione di determinati componenti.
- *Intel*, *AMD*: processori.
- *Seagate*, *Western Digital*, *Samsung*, *Hitachi*: hard disk.
- *Matrox*, *NVIDIA*, *SIS*, *ATI*: schede video.
## Federico Faggin (1941-)
Inventore del primo processore **Intel**.
### Intel 4004
Inventore del processore Z80.
Inventore del *Touchpad*.
## William Henry Gates III (1955-) 
Per gli amici **Bill Gates**.
Fondatore *Microsoft Corporation*.
Autore del SO *MS-DOS*.
Autore del SO *Windows*.
## Sistemi distribuiti (1969-)
### Distribuzione del carico
Distribuzione del calcolo su diversi nodi.
- Sistemi *multiprocessore*.
- Sistemi *distribuiti in rete*.
**Vantaggi**:
- Condivisione delle risorse.
- Accelerazione del calcolo (calcolo parallelo).
- Aumento dell'affidabilità.
- Comunicazione fra utenti.
## ARPANET (1969-)
Progetto finanziato dal DARPA.
*Obiettivo dichiarato*: creare una rete resistente alle rotture dei collegamenti.
## Leonard Kleinrock (1934-)
Fondatore della *teoria delle code*.
Pioniere delle reti a *commutazione di pacchetto*.
Fautore della prima *comunicazione fra calcolatori*.
## Vinton Cerf (1943-)
Vicepresidente di *Google*.
Pioniere dei protocolli di trasmissione (*TCP*).
Promotore della *Internet Society*.
## Robert Elliot Kahn (1938-)
Pioniere dei protocolli di trasmissione (TCP).
Fu il primo ad avere l'intuizione di un *protocollo di trasporto*. (SSH, FTP, HTTP, IRC, TELNET, ...)
## Jon Postel (1943-1998)
**Il padre dell'attuale Internet**.
Editor dei documenti *RFC* (Request For Comment).
Membro del comitato di standardizzazione *Internet Engineering Task Force* (IETF).
## Tim Berners Lee (1955-)
Inventore del *World Wide Web*: la killer application di Internet.
*Obiettivo*: creazione di un ambiente di condivisione per gli articoli scientifici.
Collegamento ipertestuale fra documenti diversi (*hyperlink*).
