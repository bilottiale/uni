/*
 *
 * Il programma seguente crea l'albero di processi
 * illustrato in figura:
 *
 *            +-------+
 *            | pid_p |
 *            +---+---+
 *                |
 *            +-------+
 *            | pid_f |
 *            +---+---+
 *                |
 *            +-------+
 *            | pid_g |
 *            +-------+
 *
 * Ciascun processo è messo in uno stato di sleep
 * per 1000 secondi (valore configurabile tramite
 * la macro SLEEP_INTVL), in modo tale da avere il
 * tempo materiale di verificare la gerarchia creata
 * (ad esempio con il comando pstree).
 */ 

#include <stdio.h>	/* printf() */
#include <unistd.h>	/* fork(), pid_t, sleep() */
#include <stdlib.h>	/* exit() */
#include <errno.h>	/* errno, perror() */

#define SLEEP_INTVL	1000

int main(void) {

	pid_t f = fork();

	if (f == 0) { /* sono il processo f? */

		/* sono il processo f -> creo g. */
		pid_t g = fork();

		if (g == 0) { /* sono il processo g? */

			/* sono il processo g -> dormo. */
			sleep(SLEEP_INTVL);

		} else if (g > 0) { /* sono il processo f? */

			/* sono il processo f -> dormo. */
			sleep(SLEEP_INTVL); 

		} else { /* si è verificato un errore */

			perror("fork()");
			exit(EXIT_FAILURE);
		}
	} else if (f > 0) { /* sono il processo p? */ 

		/* sono il processo p -> dormo. */
		sleep(SLEEP_INTVL); 

	} else { /* si è verificato un errore */

		perror("fork()");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);

}
