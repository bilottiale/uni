# Makefile per i programmi della Lez7
# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O2
LDFLAGS = 

# Definizione dei target (programmi eseguibili)  
TARGETS = dynamic_alloc matrix void_pointer

# Colori per output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
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
	@echo "$(GREEN)✓ Tutti i programmi eseguiti!$(NC)"

# Target per debug con gdb
debug-dynamic: dynamic_alloc
	@echo "$(YELLOW)🐛 Avvio debug di dynamic_alloc con gdb...$(NC)"
	gdb ./dynamic_alloc

debug-matrix: matrix
	@echo "$(YELLOW)🐛 Avvio debug di matrix con gdb...$(NC)"
	gdb ./matrix

# Target per memory check con valgrind (se disponibile)
memcheck-dynamic: dynamic_alloc
	@echo "$(YELLOW)🔍 Memory check di dynamic_alloc con valgrind...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./dynamic_alloc; \
	else \
		echo "$(RED)⚠️  Valgrind non installato. Installa con: brew install valgrind$(NC)"; \
	fi

memcheck-matrix: matrix
	@echo "$(YELLOW)🔍 Memory check di matrix con valgrind...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./matrix; \
	else \
		echo "$(RED)⚠️  Valgrind non installato. Installa con: brew install valgrind$(NC)"; \
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
	@echo ""
	@echo "$(CYAN)ESECUZIONE:$(NC)"
	@echo "  $(GREEN)run-dynamic$(NC)      - Esegue dynamic_alloc"
	@echo "  $(GREEN)run-matrix$(NC)       - Esegue matrix"
	@echo "  $(GREEN)run-all$(NC)          - Esegue tutti i programmi"
	@echo ""
	@echo "$(CYAN)DEBUG E ANALISI:$(NC)"
	@echo "  $(GREEN)debug-dynamic$(NC)    - Debug dynamic_alloc con gdb"
	@echo "  $(GREEN)debug-matrix$(NC)     - Debug matrix con gdb"
	@echo "  $(GREEN)memcheck-all$(NC)     - Memory check con valgrind"
	@echo "  $(GREEN)check-syntax$(NC)     - Controllo sintattico"
	@echo ""
	@echo "$(CYAN)UTILITÀ:$(NC)"
	@echo "  $(GREEN)info$(NC)             - Informazioni sui programmi"
	@echo "  $(GREEN)stats$(NC)            - Statistiche file sorgenti"
	@echo "  $(GREEN)backup$(NC)           - Backup dei sorgenti"
	@echo "  $(GREEN)install-deps-mac$(NC) - Installa dipendenze macOS"
	@echo "  $(GREEN)help$(NC)             - Mostra questa guida"

# Dichiarazione target non-file
.PHONY: all clean distclean run-dynamic run-matrix run-all debug-dynamic debug-matrix memcheck-dynamic memcheck-matrix memcheck-all info stats check-syntax backup install-deps-mac help
