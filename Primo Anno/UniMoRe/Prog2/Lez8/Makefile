# Makefile per Doxygen Example - Lez8
# Author: Alessandro Bilotti
# Date: 2 agosto 2025

# Configurazione compilatore
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

# ANSI Color codes per output colorato
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
NC = \033[0m

# File sorgente e eseguibile
SOURCE = doxygen_example.c
TARGET = doxygen_example

# Directory per la documentazione
DOCS_DIR = docs

.PHONY: all clean distclean run docs help install-doxygen check-doxygen

# Target principale
all: $(TARGET)
	@echo "$(BOLD)$(GREEN)✓ Programma compilato con successo!$(NC)"
	@echo "$(CYAN)Usa 'make run' per eseguire il programma$(NC)"
	@echo "$(CYAN)Usa 'make docs' per generare la documentazione$(NC)"

# Compilazione
$(TARGET): $(SOURCE)
	@echo "$(YELLOW)🔨 Compilando $(SOURCE)...$(NC)"
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

# Esecuzione
run: $(TARGET)
	@echo "$(MAGENTA)🚀 Eseguendo $(TARGET)...$(NC)"
	@echo "$(CYAN)================================================$(NC)"
	./$(TARGET)
	@echo "$(CYAN)================================================$(NC)"

# Controllo se Doxygen è installato
check-doxygen:
	@if ! command -v doxygen >/dev/null 2>&1; then \
		echo "$(RED)❌ Doxygen non è installato!$(NC)"; \
		echo "$(YELLOW)Usa 'make install-doxygen' per installarlo$(NC)"; \
		exit 1; \
	else \
		echo "$(GREEN)✓ Doxygen trovato: $$(doxygen --version)$(NC)"; \
	fi

# Installazione Doxygen su macOS
install-doxygen:
	@echo "$(YELLOW)📦 Installando Doxygen...$(NC)"
	@if command -v brew >/dev/null 2>&1; then \
		brew install doxygen; \
		echo "$(GREEN)✓ Doxygen installato con successo!$(NC)"; \
	else \
		echo "$(RED)❌ Homebrew non trovato!$(NC)"; \
		echo "$(CYAN)Installa Homebrew da: https://brew.sh$(NC)"; \
		echo "$(CYAN)Oppure installa Doxygen manualmente$(NC)"; \
		exit 1; \
	fi

# Generazione documentazione
docs: check-doxygen
	@echo "$(YELLOW)📚 Generando documentazione con Doxygen...$(NC)"
	@if [ ! -f Doxyfile ]; then \
		echo "$(RED)❌ File Doxyfile non trovato!$(NC)"; \
		exit 1; \
	fi
	doxygen Doxyfile
	@echo "$(GREEN)✓ Documentazione generata in $(DOCS_DIR)/html/$(NC)"
	@echo "$(CYAN)Apri $(DOCS_DIR)/html/index.html nel browser per visualizzarla$(NC)"

# Apertura documentazione nel browser
open-docs: docs
	@echo "$(YELLOW)🌐 Aprendo documentazione nel browser...$(NC)"
	@if [ -f "$(DOCS_DIR)/html/index.html" ]; then \
		open "$(DOCS_DIR)/html/index.html"; \
	else \
		echo "$(RED)❌ Documentazione non trovata. Esegui 'make docs' prima.$(NC)"; \
	fi

# Pulizia file temporanei
clean:
	@echo "$(YELLOW)🗑️  Rimozione eseguibile...$(NC)"
	rm -f $(TARGET)
	@echo "$(GREEN)✓ Pulizia completata!$(NC)"

# Pulizia completa (include documentazione)
distclean: clean
	@echo "$(YELLOW)🗑️  Rimozione documentazione...$(NC)"
	rm -rf $(DOCS_DIR)
	@echo "$(GREEN)✓ Pulizia completa!$(NC)"

# Debug con gdb
debug: $(TARGET)
	@echo "$(YELLOW)🐛 Avvio debug con gdb...$(NC)"
	gdb ./$(TARGET)

# Memory check con valgrind o AddressSanitizer
memcheck: $(TARGET)
	@echo "$(YELLOW)🔍 Memory check...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(CYAN)Usando Valgrind:$(NC)"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET); \
	else \
		echo "$(YELLOW)Valgrind non disponibile. Compilando con AddressSanitizer...$(NC)"; \
		$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer -o $(TARGET)_asan $(SOURCE) $(LDFLAGS); \
		echo "$(CYAN)Eseguendo con AddressSanitizer:$(NC)"; \
		./$(TARGET)_asan; \
		rm -f $(TARGET)_asan; \
	fi

# Verifica sintastica
check-syntax:
	@echo "$(YELLOW)🔍 Verifica sintassi...$(NC)"
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCE)
	@echo "$(GREEN)✓ Sintassi corretta!$(NC)"

# Informazioni sul progetto
info:
	@echo "$(BOLD)$(WHITE)📋 INFORMAZIONI PROGETTO$(NC)"
	@echo "$(CYAN)Nome:$(NC) Doxygen Example - Programmazione 2"
	@echo "$(CYAN)File sorgente:$(NC) $(SOURCE)"
	@echo "$(CYAN)Eseguibile:$(NC) $(TARGET)"
	@echo "$(CYAN)Compilatore:$(NC) $(CC) $(CFLAGS)"
	@echo "$(CYAN)Documentazione:$(NC) $(DOCS_DIR)/html/"
	@echo ""
	@echo "$(BOLD)$(YELLOW)📊 STATISTICHE FILE:$(NC)"
	@if [ -f "$(SOURCE)" ]; then \
		echo "$(CYAN)Righe di codice:$(NC) $$(wc -l < $(SOURCE))"; \
		echo "$(CYAN)Dimensione file:$(NC) $$(du -h $(SOURCE) | cut -f1)"; \
		echo "$(CYAN)Caratteri:$(NC) $$(wc -c < $(SOURCE))"; \
		echo "$(CYAN)Parole:$(NC) $$(wc -w < $(SOURCE))"; \
	fi

# Statistiche dettagliate del codice
stats:
	@echo "$(BOLD)$(WHITE)📊 STATISTICHE DETTAGLIATE$(NC)"
	@echo ""
	@echo "$(YELLOW)Analisi del file $(SOURCE):$(NC)"
	@if [ -f "$(SOURCE)" ]; then \
		echo "$(CYAN)Righe totali:$(NC) $$(wc -l < $(SOURCE))"; \
		echo "$(CYAN)Righe vuote:$(NC) $$(grep -c '^[[:space:]]*$$' $(SOURCE))"; \
		echo "$(CYAN)Righe di commenti:$(NC) $$(grep -c '^\s*/\*\|^\s*\*\|^\s*//\|^\s*\*/' $(SOURCE))"; \
		echo "$(CYAN)Righe di codice:$(NC) $$(grep -cv '^\s*$$\|^\s*/\*\|^\s*\*\|^\s*//\|^\s*\*/' $(SOURCE))"; \
		echo "$(CYAN)Funzioni:$(NC) $$(grep -c '^[a-zA-Z_][a-zA-Z0-9_]*.*(' $(SOURCE))"; \
		echo "$(CYAN)Include:$(NC) $$(grep -c '#include' $(SOURCE))"; \
		echo "$(CYAN)Define:$(NC) $$(grep -c '#define' $(SOURCE))"; \
	fi

# Backup del progetto
backup:
	@echo "$(YELLOW)💾 Creando backup...$(NC)"
	@BACKUP_NAME="doxygen_example_backup_$$(date +%Y%m%d_%H%M%S).tar.gz"; \
	tar -czf "$$BACKUP_NAME" $(SOURCE) Doxyfile Makefile README.md 2>/dev/null || \
	tar -czf "$$BACKUP_NAME" $(SOURCE) Doxyfile Makefile; \
	echo "$(GREEN)✓ Backup creato: $$BACKUP_NAME$(NC)"

# Esempio di utilizzo Doxygen
example:
	@echo "$(BOLD)$(WHITE)📚 GUIDA RAPIDA DOXYGEN$(NC)"
	@echo ""
	@echo "$(YELLOW)1. Documenta una funzione:$(NC)"
	@echo "$(CYAN)   /**$(NC)"
	@echo "$(CYAN)    * @brief Breve descrizione della funzione$(NC)"
	@echo "$(CYAN)    * @param param1 Descrizione del primo parametro$(NC)"
	@echo "$(CYAN)    * @param param2 Descrizione del secondo parametro$(NC)"
	@echo "$(CYAN)    * @return Descrizione del valore di ritorno$(NC)"
	@echo "$(CYAN)    */$(NC)"
	@echo ""
	@echo "$(YELLOW)2. Crea un gruppo di funzioni:$(NC)"
	@echo "$(CYAN)   /** @defgroup GroupName Nome del Gruppo */$(NC)"
	@echo "$(CYAN)   /** @{ */$(NC)"
	@echo "$(CYAN)   /* funzioni del gruppo */$(NC)"
	@echo "$(CYAN)   /** @} */$(NC)"
	@echo ""
	@echo "$(YELLOW)3. Documenta una struttura:$(NC)"
	@echo "$(CYAN)   /** @struct NomeStruct */$(NC)"
	@echo "$(CYAN)   typedef struct {$(NC)"
	@echo "$(CYAN)       int campo1;  /**< Descrizione campo1 */$(NC)"
	@echo "$(CYAN)       int campo2;  /**< Descrizione campo2 */$(NC)"
	@echo "$(CYAN)   } NomeStruct;$(NC)"
	@echo ""
	@echo "$(YELLOW)4. Tag utili:$(NC)"
	@echo "$(CYAN)   @warning  - Avvertimento importante$(NC)"
	@echo "$(CYAN)   @note     - Nota aggiuntiva$(NC)"
	@echo "$(CYAN)   @todo     - Cosa fare in futuro$(NC)"
	@echo "$(CYAN)   @bug      - Bug conosciuto$(NC)"
	@echo "$(CYAN)   @see      - Riferimento ad altro$(NC)"
	@echo "$(CYAN)   @code     - Inizio esempio di codice$(NC)"
	@echo "$(CYAN)   @endcode  - Fine esempio di codice$(NC)"

# Help
help:
	@echo "$(BOLD)$(WHITE)🆘 MAKEFILE HELP - Doxygen Example$(NC)"
	@echo ""
	@echo "$(YELLOW)TARGET PRINCIPALI:$(NC)"
	@echo "  $(GREEN)all$(NC)               - Compila il programma"
	@echo "  $(GREEN)clean$(NC)             - Rimuove eseguibili"
	@echo "  $(GREEN)distclean$(NC)         - Pulizia completa (include docs)"
	@echo ""
	@echo "$(YELLOW)ESECUZIONE:$(NC)"
	@echo "  $(GREEN)run$(NC)               - Esegue il programma"
	@echo "  $(GREEN)debug$(NC)             - Debug con gdb"
	@echo "  $(GREEN)memcheck$(NC)          - Controllo memoria"
	@echo ""
	@echo "$(YELLOW)DOCUMENTAZIONE:$(NC)"
	@echo "  $(GREEN)check-doxygen$(NC)     - Verifica se Doxygen è installato"
	@echo "  $(GREEN)install-doxygen$(NC)   - Installa Doxygen (macOS)"
	@echo "  $(GREEN)docs$(NC)              - Genera documentazione HTML"
	@echo "  $(GREEN)open-docs$(NC)         - Genera e apre documentazione"
	@echo ""
	@echo "$(YELLOW)ANALISI E UTILITÀ:$(NC)"
	@echo "  $(GREEN)check-syntax$(NC)      - Verifica sintassi"
	@echo "  $(GREEN)info$(NC)              - Informazioni progetto"
	@echo "  $(GREEN)stats$(NC)             - Statistiche dettagliate"
	@echo "  $(GREEN)backup$(NC)            - Crea backup del progetto"
	@echo "  $(GREEN)example$(NC)           - Mostra esempi Doxygen"
	@echo "  $(GREEN)help$(NC)              - Mostra questa guida"
	@echo ""
	@echo "$(CYAN)Esempi di utilizzo:$(NC)"
	@echo "  $(WHITE)make && make run$(NC)              - Compila ed esegue"
	@echo "  $(WHITE)make docs && make open-docs$(NC)   - Genera e apre documentazione"
	@echo "  $(WHITE)make install-doxygen$(NC)          - Installa Doxygen"

# Dichiara target phony
.PHONY: all clean distclean run docs open-docs help install-doxygen check-doxygen debug memcheck check-syntax info stats backup example
