Un linguaggio di programmazione è **scritto staticamente** se il tipo della variabile e determinato all’inizio dell’esecuzione del programma, serve al compilatore per controlli di tipo. (C)

Un linguaggio di programmazione è **scritto dinamicamente** se il tipo della variabile è determinato o può cambiare in fase di esecuzione, una sua parte può servire per i controlli durante l’esecuzione.

Un linguaggio **type-safe** garantisce che tutti gli errori di tipo siano catturati, ma non necessariamente durante la compilazione (un programma potrebbe fallire durante l’esecuzione a causa di violazioni di tipo).
C non è *type-safe* per scelta.

Un linguaggio *scritto staticamente* è **type-sound** se e solo se "programmi ben scritti non possono fallire", type-sound implica di essere type-safe.
Quindi C non è *type-sound*.