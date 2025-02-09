`pgrep`
Stampa i PID di tutti i processi attivati a partire da una espressione regolare estesa.
```bash
man pgrep
pgrep '^ba.*$'
pgrep -n bash # PID del processo più recente con "bash"
pgrep -o bash # PID del processo meno recente con "bash"
pgrep -l bash # PID e noe dei processi con "bash"
```
---
`pstree`
Stampa una rappresentazione compatta dell'albero dei processi.
```bash
pstree | less -Mr
pstree -a # nomi e argomenti processi in exe
pstree -c # esplicito
pstree -p # mostra i PID
pstree -H PID # evidenzia il ramo da init a PID
```
---
`/usr/bin/time`
Misura il tempo di completamento ed il consumo delle principali risorse di sistema.
```bash
man time
/usr/bin/time -f "%E" ./test # tempo completamento
/usr/bin/time -f "%E %c %w" ./test # anche numero di cambi di contesto e richieste di I/O bloccanti
```
---
`ps`
Fornisce una “istantanea” del consumo di risorse di tutti i processi.
```bash
man ps
ps ax # stampa tutti i processi attivi
ps fax # vista ad albero (forest) di tutti i processi attivi
ps faxl # vista estesa (più campi)
ps faxl | less -Mr ./test
```
---
`top`
Monitor periodico dei processi.
```bash
man top
top
```
---
`pidstat`
Strumento di monitoraggio delle risorse consumate da singoli processi.
```bash
pidstat -u # mostra “one shot” l'utilizzazione per ciascuno dei processi attivi finora a partire dall'accensione del PC.
pidstat -u 1 # mostra ogni secondo l'utilizzazione di CPU per ciascuno dei processi attivi nell'ultimo secondo.
pidstat -u -p 4000 # mostra ogni secondo l'utilizzazione di CPU per il processo avente PID 4000
pidstat -u -C "bash|terminal" 1 # monitora l'uso CPU di "bash" o "terminal"
pidstat -u -p $(pgrep cpubound) 1
```
---
# Virtual file system
`mount`
Gestisce il processo di montaggio e smontaggio manuale di un file system.
```bash
mount # opzioni
```

```bash
mountpoint / # controlla se una data directory sia un mountpoint oppure no.
```
`proc`
File system che contiene statistiche sui componenti hardware e software del kernel.
```bash
man proc
/proc/<PID> # contengono le info sul processo
```
---
# Riposizionamento
```bash
apropos -s2,3 reposition # otteniamo
	lseek() # sys call per riposizionare un file
	fseek() # lib function per riposizionare uno stream
```
Un **file hole** è una porzione di un file che non è effettivamente memorizzata su disco, ma che viene trattata come se contenesse zeri quando il file viene letto. Questo avviene grazie a una tecnica chiamata **sparse file** (file sparsi).
```bash
dd if=/dev/zero of=file-con-hole bs=1M count=10 # crea file grande di zeri
ls -l file-con-hole # dimensione logica del file
ls -s file-con-hole # blocchi allocati dal file system
```
Si compila:
```c
#include <sys/types.h>	/* mode_t */
#include <fcntl.h>	/* S_IRUSR, ... */
#include <errno.h>	/* errno, perror() */
#include <unistd.h>	/* read(), lseek(), write() */
#include <stdlib.h>	/* exit() */
#include <stdio.h>	/* printf() */

#define OFFSET	1024 * 1024 * 10	/* 10 MB */

int main(int argc, char *argv[]) {

	const char file_to_read[] = "file-con-hole";
	char byte = 'a';
	int fd, flags;
	ssize_t ret;
	mode_t mode;
	off_t offset;

	/* apriamo il file in lettura e scrittura */
	flags = O_CREAT | O_RDWR;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(file_to_read, flags, mode)) == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	/*
	 * Riposizioniamo l'offset oltre la fine
	 * del file. Usiamo il flag SEEK_END.
	 */
	
	/* Riposizioniamo l'offset del file */
	if ((offset = lseek(fd, (off_t) OFFSET, SEEK_END)) == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	/* scriviamo un byte alla nuova posizione */
	ret = write(fd, (void *)&byte, sizeof(char));
	if (ret != sizeof(char)) {
		perror("write: non sono riuscito a scrivere un char");
		exit(EXIT_FAILURE);
	} 

	if ((close(fd) == -1)) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
```

```bash
ls -l file-con-hole # 21 MB
# 10MB partenza, 10MB salto, 4KB per memorizzare 'a'
ls -s file-con-hole
```
---
# Buffering
```
mpstat 1 | tr -s " " | cuty -f3 -d " "
```
! NON FUNZIONA
Analizzando il file `tr.c` si scopre che l'I/O è bufferizzato con record logici `BUFSIZ` di 32KB.
-> si imposta il comendo **line oriented**(`-oL`)
```bash
mpstat 1 | stdbuf -oL tr -s " " | cut -f3 -d " "
```
---
# Collegamenti
`link()` crea un **hard link** ad un file o directory.
`syslink()` crea un **soft link** ad un file o directory.
```bash
man 2 link
man 2 syslink
```
`unlink` rimuove un **hard link**.

---
# Misurazione contenuto
`df` riporta il consumo complessivo di ciascun file system attivo.
```bash
man df
df -f # stampa il report il modo leggibile
```
`du` mostr ail consumo di spazio di file e cartelle.
```bash
man du
du file
du -h file
du -s . # mostra il consumo complessivo della dir attuale
```
Ricerca delle directory più voluminose:
```bash
for d in $(ls); do du -hs $d; done 2> /dev/null
```
Tabella file aperti:
```bash
man lsof
lsof -u andreoli
lsof -c bash
lsof /home/andreoli
lsof -a -u andreoli -c bash
lsof -p 7606
lsof -L1
```
---
# Allocazione dinamica - HEAP



