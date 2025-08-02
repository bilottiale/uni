# Makefile per i programmi della Lez7
# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O2
LDFLAGS = 

# Definizione dei target (programmi eseguibili)  
TARGETS = dynamic_alloc matrix void_pointer stringhe esercizi_stringhe esercizi_p2 esercizi_p3 esercizi_p4

# Colori per output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
CYAN = \033[0;36m
NC = \033[0m # No Color

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
CFLAGS_OPT = -O2
CFLAGS_DEBUG = -g -DDEBUG
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[1;37m
NC = \033[0m # No Color

# Target predefinito: compila tutti i programmi
all: $(TARGETS)
	@echo "$(GREEN)✓ Tutti i programmi compilati con successo!$(NC)"
	@echo "$(CYAN)Programmi disponibili:$(NC)"
	@echo "  $(YELLOW)• dynamic_alloc$(NC) - Guida completa all'allocazione dinamica"
	@echo "  $(YELLOW)• matrix$(NC) - Guida completa alle matrici in C"
	@echo "  $(YELLOW)• void_pointer$(NC) - Guida completa al tipo void*"
	@echo "  $(YELLOW)• stringhe$(NC) - Guida completa alle stringhe in C"

# Regola per dynamic_alloc
dynamic_alloc: dynamic_alloc.c
	@echo "$(BLUE)🔨 Compilando dynamic_alloc...$(NC)"
	$(CC) $(CFLAGS) -o dynamic_alloc dynamic_alloc.c $(LDFLAGS)
	@echo "$(GREEN)✓ dynamic_alloc compilato!$(NC)"

# Regola per matrix
matrix: matrix.c
	@echo "$(BLUE)🔨 Compilando matrix...$(NC)"
	$(CC) $(CFLAGS) -o matrix matrix.c $(LDFLAGS)
	@echo "$(GREEN)✓ matrix compilato!$(NC)"

# Regola per void_pointer
void_pointer: void_pointer.c
	@echo "$(BLUE)🔨 Compilando void_pointer...$(NC)"
	$(CC) $(CFLAGS) -o void_pointer void_pointer.c $(LDFLAGS)
	@echo "$(GREEN)✓ void_pointer compilato!$(NC)"

# Regola per stringhe
stringhe: stringhe.c
	@echo "$(BLUE)🔨 Compilando stringhe...$(NC)"
	$(CC) $(CFLAGS) -o stringhe stringhe.c $(LDFLAGS)
	@echo "$(GREEN)✓ stringhe compilato!$(NC)"

# Regola per esercizi_stringhe
esercizi_stringhe: esercizi_stringhe.c
	@echo "$(BLUE)🔨 Compilando esercizi_stringhe...$(NC)"
	$(CC) $(CFLAGS) -o esercizi_stringhe esercizi_stringhe.c $(LDFLAGS)
	@echo "$(GREEN)✓ esercizi_stringhe compilato!$(NC)"

# Regola per esercizi_p2
esercizi_p2: esercizi_p2.c
	@echo "$(BLUE)🔨 Compilando esercizi_p2...$(NC)"
	$(CC) $(CFLAGS) -o esercizi_p2 esercizi_p2.c -lm $(LDFLAGS)
	@echo "$(GREEN)✓ esercizi_p2 compilato!$(NC)"

# Regola per esercizi_p3
esercizi_p3: esercizi_p3.c
	@echo "$(BLUE)🔨 Compilando esercizi_p3...$(NC)"
	$(CC) $(CFLAGS) -o esercizi_p3 esercizi_p3.c $(LDFLAGS)
	@echo "$(GREEN)✓ esercizi_p3 compilato!$(NC)"

# Target per eseguire dynamic_alloc
run-dynamic: dynamic_alloc
	@echo "$(MAGENTA)🚀 Eseguendo dynamic_alloc...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./dynamic_alloc
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire matrix
run-matrix: matrix
	@echo "$(MAGENTA)🚀 Eseguendo matrix...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./matrix
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire void_pointer
run-void: void_pointer
	@echo "$(MAGENTA)🚀 Eseguendo void_pointer...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./void_pointer
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire stringhe
run-stringhe: stringhe
	@echo "$(MAGENTA)🚀 Eseguendo stringhe...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./stringhe
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire esercizi_stringhe
run-esercizi-stringhe: esercizi_stringhe
	@echo "$(MAGENTA)🚀 Eseguendo esercizi_stringhe...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_stringhe
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire esercizi_p2
run-esercizi-p2: esercizi_p2
	@echo "$(MAGENTA)🚀 Eseguendo esercizi_p2...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p2
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire esercizi_p3
run-esercizi-p3: esercizi_p3
	@echo "$(MAGENTA)🚀 Eseguendo esercizi_p3...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p3
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire esercizi_p4
run-esercizi-p4: esercizi_p4
	@echo "$(MAGENTA)🚀 Eseguendo esercizi_p4...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p4
	@echo "$(CYAN)================================================$(NC)"

# Target per eseguire tutti i programmi
run-all: $(TARGETS)
	@echo "$(WHITE)🎯 Esecuzione di tutti i programmi:$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 1. Eseguendo dynamic_alloc...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./dynamic_alloc
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 2. Eseguendo matrix...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./matrix
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 3. Eseguendo void_pointer...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./void_pointer
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 4. Eseguendo stringhe...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./stringhe
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 5. Eseguendo esercizi_stringhe...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_stringhe
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 6. Eseguendo esercizi_p2...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p2
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 7. Eseguendo esercizi_p3...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p3
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(MAGENTA)🚀 8. Eseguendo esercizi_p4...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./esercizi_p4
	@echo "$(CYAN)================================================$(NC)"
	@echo ""
	@echo "$(GREEN)✓ Tutti i programmi eseguiti!$(NC)"

# Target per debug con gdb
debug-dynamic: dynamic_alloc
	@echo "$(YELLOW)🐛 Avvio debug di dynamic_alloc con gdb...$(NC)"
	gdb ./dynamic_alloc

debug-matrix: matrix
	@echo "$(YELLOW)🐛 Avvio debug di matrix con gdb...$(NC)"
	gdb ./matrix

debug-stringhe: stringhe
	@echo "$(YELLOW)🐛 Avvio debug di stringhe con gdb...$(NC)"
	gdb ./stringhe

debug-esercizi-stringhe: esercizi_stringhe
	@echo "$(YELLOW)🐛 Avvio debug di esercizi_stringhe con gdb...$(NC)"
	gdb ./esercizi_stringhe

debug-esercizi-p2: esercizi_p2
	@echo "$(YELLOW)🐛 Avvio debug di esercizi_p2 con gdb...$(NC)"
	gdb ./esercizi_p2

debug-esercizi-p3: esercizi_p3
	@echo "$(YELLOW)🐛 Avvio debug di esercizi_p3 con gdb...$(NC)"
	gdb ./esercizi_p3

debug-esercizi-p4: esercizi_p4
	@echo "$(YELLOW)🐛 Avvio debug di esercizi_p4 con gdb...$(NC)"
	gdb ./esercizi_p4

# Target per memory check con valgrind (se disponibile)
# Memory check targets
memcheck-dynamic: dynamic_alloc
	@echo "$(YELLOW)🔍 Memory check di dynamic_alloc...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./dynamic_alloc; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o dynamic_alloc_asan dynamic_alloc.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./dynamic_alloc_asan; \
		rm -f dynamic_alloc_asan; \
	fi

memcheck-matrix: matrix
	@echo "$(YELLOW)🔍 Memory check di matrix...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./matrix; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o matrix_asan matrix.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./matrix_asan; \
		rm -f matrix_asan; \
	fi

memcheck-stringhe: stringhe
	@echo "$(YELLOW)🔍 Memory check di stringhe...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./stringhe; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o stringhe_asan stringhe.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./stringhe_asan; \
		rm -f stringhe_asan; \
	fi

memcheck-esercizi-stringhe: esercizi_stringhe
	@echo "$(YELLOW)🔍 Memory check di esercizi_stringhe...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./esercizi_stringhe; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o esercizi_stringhe_asan esercizi_stringhe.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./esercizi_stringhe_asan; \
		rm -f esercizi_stringhe_asan; \
	fi

memcheck-esercizi-p2: esercizi_p2
	@echo "$(YELLOW)🔍 Memory check di esercizi_p2...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./esercizi_p2; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o esercizi_p2_asan esercizi_p2.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./esercizi_p2_asan; \
		rm -f esercizi_p2_asan; \
	fi

memcheck-esercizi-p3: esercizi_p3
	@echo "$(YELLOW)🔍 Memory check di esercizi_p3...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./esercizi_p3; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o esercizi_p3_asan esercizi_p3.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./esercizi_p3_asan; \
		rm -f esercizi_p3_asan; \
	fi

memcheck-esercizi-p4: esercizi_p4
	@echo "$(YELLOW)🔍 Memory check di esercizi_p4...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Using Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./esercizi_p4; \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		gcc -Wall -Wextra -std=c99 -g -fsanitize=address -fno-omit-frame-pointer -o esercizi_p4_asan esercizi_p4.c; \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./esercizi_p4_asan; \
		rm -f esercizi_p4_asan; \
	fi

# Target per memory check di tutti i programmi
memcheck-all: $(TARGETS)
	@echo "$(WHITE)🔍 Memory check di tutti i programmi:$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(YELLOW)Checking dynamic_alloc...$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./dynamic_alloc; \
		echo ""; \
		echo "$(YELLOW)Checking matrix...$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./matrix; \
	else \
		echo "$(RED)⚠️  Valgrind non installato. Installa con: brew install valgrind$(NC)"; \
	fi

# Target per la pulizia
clean:
	@echo "$(RED)🗑️  Rimozione file eseguibili...$(NC)"
	rm -f $(TARGETS)
	rm -f *_asan
	@echo "$(GREEN)✓ Pulizia completata!$(NC)"

# Target per la pulizia completa (include anche file temporanei)
distclean: clean
	@echo "$(RED)🗑️  Rimozione file temporanei...$(NC)"
	rm -f *.o *.dSYM -rf
	rm -f core.*
	rm -f a.out
	@echo "$(GREEN)✓ Pulizia completa!$(NC)"

# Target per visualizzare informazioni sui programmi
info:
	@echo "$(WHITE)📋 Informazioni sui programmi in Lez7:$(NC)"
	@echo ""
	@echo "$(CYAN)dynamic_alloc.c:$(NC)"
	@echo "  $(YELLOW)•$(NC) Guida completa all'allocazione dinamica in C"
	@echo "  $(YELLOW)•$(NC) Copre malloc, calloc, realloc, free"
	@echo "  $(YELLOW)•$(NC) Gestione errori e best practices"
	@echo "  $(YELLOW)•$(NC) Strutture dati dinamiche"
	@echo ""
	@echo "$(CYAN)matrix.c:$(NC)"
	@echo "  $(YELLOW)•$(NC) Guida completa alle matrici in C"
	@echo "  $(YELLOW)•$(NC) Matrici statiche e dinamiche"
	@echo "  $(YELLOW)•$(NC) Array 2D, array di puntatori, VLA"
	@echo "  $(YELLOW)•$(NC) Operazioni matriciali e performance"
	@echo ""
	@echo "$(CYAN)void_pointer.c:$(NC)"
	@echo "  $(YELLOW)•$(NC) Guida completa al tipo void* in C"
	@echo "  $(YELLOW)•$(NC) Conversioni, cast e best practices"
	@echo "  $(YELLOW)•$(NC) Funzioni generiche e callback"
	@echo "  $(YELLOW)•$(NC) Strutture dati generiche"
	@echo ""
	@echo "$(CYAN)Comandi disponibili:$(NC)"
	@echo "  $(GREEN)make$(NC) o $(GREEN)make all$(NC)     - Compila tutti i programmi"
	@echo "  $(GREEN)make run-dynamic$(NC)    - Esegue dynamic_alloc"
	@echo "  $(GREEN)make run-matrix$(NC)     - Esegue matrix"
	@echo "  $(GREEN)make run-void$(NC)       - Esegue void_pointer"
	@echo "  $(GREEN)make run-all$(NC)        - Esegue tutti i programmi"
	@echo "  $(GREEN)make debug-dynamic$(NC)  - Debug dynamic_alloc con gdb"
	@echo "  $(GREEN)make debug-matrix$(NC)   - Debug matrix con gdb"
	@echo "  $(GREEN)make memcheck-all$(NC)   - Memory check con valgrind"
	@echo "  $(GREEN)make clean$(NC)          - Rimuove eseguibili"
	@echo "  $(GREEN)make info$(NC)           - Mostra queste informazioni"

# Target per mostrare le statistiche dei file sorgenti
stats:
	@echo "$(WHITE)📊 Statistiche dei file sorgenti:$(NC)"
	@echo ""
	@for file in *.c; do \
		if [ -f "$$file" ]; then \
			lines=$$(wc -l < "$$file"); \
			chars=$$(wc -c < "$$file"); \
			words=$$(wc -w < "$$file"); \
			echo "$(CYAN)$$file:$(NC)"; \
			echo "  $(YELLOW)Righe:$(NC) $$lines"; \
			echo "  $(YELLOW)Caratteri:$(NC) $$chars"; \
			echo "  $(YELLOW)Parole:$(NC) $$words"; \
			echo ""; \
		fi \
	done

# Target per verificare la presenza di memory leaks nei sorgenti
check-syntax:
	@echo "$(YELLOW)🔍 Controllo sintattico dei file sorgenti...$(NC)"
	@for file in *.c; do \
		if [ -f "$$file" ]; then \
			echo "$(CYAN)Controllando $$file...$(NC)"; \
			$(CC) $(CFLAGS) -fsyntax-only "$$file" && \
			echo "$(GREEN)✓ $$file - Sintassi corretta$(NC)" || \
			echo "$(RED)✗ $$file - Errori di sintassi$(NC)"; \
		fi \
	done

# Target per backup dei sorgenti
backup:
	@echo "$(YELLOW)💾 Creazione backup dei file sorgenti...$(NC)"
	@mkdir -p backup
	@cp *.c backup/ 2>/dev/null || true
	@cp Makefile backup/ 2>/dev/null || true
	@echo "$(GREEN)✓ Backup creato nella cartella backup/$(NC)"

# Installazione dipendenze per macOS
install-deps-mac:
	@echo "$(YELLOW)📦 Installazione dipendenze per macOS...$(NC)"
	@if command -v brew >/dev/null 2>&1; then \
		echo "$(CYAN)Installando gdb e valgrind...$(NC)"; \
		brew install gdb valgrind || true; \
		echo "$(GREEN)✓ Dipendenze installate!$(NC)"; \
	else \
		echo "$(RED)⚠️  Homebrew non installato. Installa da: https://brew.sh$(NC)"; \
	fi

# Memory checking information
memcheck-info:
	@echo "$(WHITE)🔍 INFORMAZIONI MEMORY CHECKING$(NC)"
	@echo ""
	@echo "$(CYAN)Strumenti disponibili:$(NC)"
	@echo "  $(GREEN)Valgrind$(NC)        - Standard su Linux, limitato su macOS"
	@echo "  $(GREEN)AddressSanitizer$(NC) - Integrato in GCC/Clang, perfetto per Apple Silicon"
	@echo ""
	@echo "$(CYAN)Questo Makefile usa automaticamente:$(NC)"
	@echo "  • $(YELLOW)Valgrind$(NC) se disponibile ($(GREEN)valgrind --leak-check=full$(NC))"
	@echo "  • $(YELLOW)AddressSanitizer$(NC) come fallback ($(GREEN)-fsanitize=address$(NC))"
	@echo ""
	@echo "$(CYAN)AddressSanitizer rileva:$(NC)"
	@echo "  $(RED)•$(NC) Buffer overflow (heap e stack)"
	@echo "  $(RED)•$(NC) Use-after-free"
	@echo "  $(RED)•$(NC) Double-free"
	@echo "  $(RED)•$(NC) Memory leaks"
	@echo "  $(RED)•$(NC) Stack buffer overflow"
	@echo "  $(RED)•$(NC) Initialization order bugs"
	@echo ""
	@echo "$(CYAN)Comandi disponibili:$(NC)"
	@for target in dynamic matrix stringhe esercizi-stringhe esercizi-p2 esercizi-p3; do \
		echo "  $(GREEN)make memcheck-$$target$(NC) - Memory check di $$target"; \
	done
	@echo "  $(GREEN)make memcheck-all$(NC)        - Memory check di tutti i programmi"
	@echo ""
	@echo "$(YELLOW)💡 Su Apple Silicon, AddressSanitizer è più veloce e affidabile di Valgrind!$(NC)"

# Help - mostra tutti i target disponibili
help:
	@echo "$(WHITE)🆘 MAKEFILE HELP - Lez7$(NC)"
	@echo ""
	@echo "$(CYAN)TARGET PRINCIPALI:$(NC)"
	@echo "  $(GREEN)all$(NC)              - Compila tutti i programmi"
	@echo "  $(GREEN)clean$(NC)            - Rimuove eseguibili"
	@echo "  $(GREEN)distclean$(NC)        - Pulizia completa"
	@echo ""
	@echo "$(CYAN)COMPILAZIONE:$(NC)"
	@echo "  $(GREEN)dynamic_alloc$(NC)    - Compila solo dynamic_alloc"
	@echo "  $(GREEN)matrix$(NC)           - Compila solo matrix"
	@echo "  $(GREEN)stringhe$(NC)         - Compila solo stringhe"
	@echo "  $(GREEN)esercizi_stringhe$(NC) - Compila solo esercizi_stringhe"
	@echo "  $(GREEN)esercizi_p2$(NC)      - Compila solo esercizi_p2"
	@echo "  $(GREEN)esercizi_p3$(NC)      - Compila solo esercizi_p3"
	@echo "  $(GREEN)esercizi_p4$(NC)      - Compila solo esercizi_p4"
	@echo ""
	@echo "$(CYAN)ESECUZIONE:$(NC)"
	@echo "  $(GREEN)run-dynamic$(NC)      - Esegue dynamic_alloc"
	@echo "  $(GREEN)run-matrix$(NC)       - Esegue matrix"
	@echo "  $(GREEN)run-stringhe$(NC)     - Esegue stringhe"
	@echo "  $(GREEN)run-esercizi-stringhe$(NC) - Esegue esercizi_stringhe"
	@echo "  $(GREEN)run-esercizi-p2$(NC)  - Esegue esercizi_p2"
	@echo "  $(GREEN)run-esercizi-p3$(NC)  - Esegue esercizi_p3"
	@echo "  $(GREEN)run-esercizi-p4$(NC)  - Esegue esercizi_p4"
	@echo "  $(GREEN)run-all$(NC)          - Esegue tutti i programmi"
	@echo ""
	@echo "$(CYAN)DEBUG E ANALISI:$(NC)"
	@echo "  $(GREEN)debug-dynamic$(NC)    - Debug dynamic_alloc con gdb"
	@echo "  $(GREEN)debug-matrix$(NC)     - Debug matrix con gdb"
	@echo "  $(GREEN)debug-stringhe$(NC)   - Debug stringhe con gdb"
	@echo "  $(GREEN)debug-esercizi-stringhe$(NC) - Debug esercizi_stringhe con gdb"
	@echo "  $(GREEN)debug-esercizi-p2$(NC) - Debug esercizi_p2 con gdb"
	@echo "  $(GREEN)debug-esercizi-p3$(NC) - Debug esercizi_p3 con gdb"
	@echo "  $(GREEN)debug-esercizi-p4$(NC) - Debug esercizi_p4 con gdb"
	@echo ""
	@echo "$(CYAN)ANALISI MEMORIA:$(NC)"
	@echo "  $(GREEN)memcheck-dynamic$(NC) - Analisi memoria dynamic_alloc (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-matrix$(NC)  - Analisi memoria matrix (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-stringhe$(NC) - Analisi memoria stringhe (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-esercizi-stringhe$(NC) - Analisi memoria esercizi_stringhe (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-esercizi-p2$(NC) - Analisi memoria esercizi_p2 (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-esercizi-p3$(NC) - Analisi memoria esercizi_p3 (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-esercizi-p4$(NC) - Analisi memoria esercizi_p4 (Valgrind/AddressSanitizer)"
	@echo "  $(GREEN)memcheck-all$(NC)     - Memory check di tutti i programmi"
	@echo "  $(GREEN)memcheck-info$(NC)    - Informazioni sui tools di memory checking"
	@echo "  $(GREEN)check-syntax$(NC)     - Controllo sintattico"
	@echo ""
	@echo "$(CYAN)UTILITÀ:$(NC)"
	@echo "  $(GREEN)info$(NC)             - Informazioni sui programmi"
	@echo "  $(GREEN)stats$(NC)            - Statistiche file sorgenti"
	@echo "  $(GREEN)backup$(NC)           - Backup dei sorgenti"
	@echo "  $(GREEN)install-deps-mac$(NC) - Installa dipendenze macOS"
	@echo "  $(GREEN)help$(NC)             - Mostra questa guida"

# Dichiarazione target non-file
.PHONY: all clean distclean run-dynamic run-matrix run-stringhe run-esercizi-stringhe run-esercizi-p2 run-esercizi-p3 run-esercizi-p4 run-all debug-dynamic debug-matrix debug-stringhe debug-esercizi-stringhe debug-esercizi-p2 debug-esercizi-p3 debug-esercizi-p4 memcheck-dynamic memcheck-matrix memcheck-stringhe memcheck-esercizi-stringhe memcheck-esercizi-p2 memcheck-esercizi-p3 memcheck-esercizi-p4 memcheck-all memcheck-info info stats check-syntax backup install-deps-mac help
