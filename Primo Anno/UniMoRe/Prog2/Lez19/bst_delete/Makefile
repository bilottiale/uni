# ==============================================================================
# 🗑️ MAKEFILE - BST DELETE (Binary Search Tree con cancellazione)
# ==============================================================================
# Progetto: Gestione completa di un Binary Search Tree con menu interattivo
# Moduli: main.cc, bst.cc, tipo.cc
# Target: bst_delete (programma con menu per BST)
# ==============================================================================

# 🎯 CONFIGURAZIONE PROGETTO
PROJECT_NAME = bst_delete
TARGET = $(PROJECT_NAME)
SOURCES = main.cc bst.cc tipo.cc
HEADERS = bst.h tipo.h
OBJECTS = $(SOURCES:%.cc=obj/%.o)

# 🔧 CONFIGURAZIONE COMPILATORE
CXX = g++
CXXFLAGS_BASE = -Wall -Wextra -std=c++11 -pedantic
CXXFLAGS_RELEASE = $(CXXFLAGS_BASE) -O2 -DNDEBUG
CXXFLAGS_DEBUG = $(CXXFLAGS_BASE) -g -O0 -DDEBUG
LDFLAGS = 

# 🎮 MODALITÀ DEFAULT (release)
CXXFLAGS = $(CXXFLAGS_RELEASE)

# 📁 DIRECTORY
OBJ_DIR = obj
DOC_DIR = doc

# 🎨 COLORI PER OUTPUT
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

# ==============================================================================
# 🎯 TARGET PRINCIPALI
# ==============================================================================

# Target di default
all: $(TARGET)
	@echo "$(GREEN)✅ $(TARGET) compilato con successo!$(NC)"

# Compilazione del target principale
$(TARGET): $(OBJECTS)
	@echo "$(CYAN)🔗 Linking $(TARGET)...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilazione oggetti con dipendenze automatiche
$(OBJ_DIR)/%.o: %.cc | $(OBJ_DIR)
	@echo "$(BLUE)🔨 Compilazione $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creazione directory oggetti
$(OBJ_DIR):
	@echo "$(YELLOW)📁 Creazione directory $(OBJ_DIR)...$(NC)"
	@mkdir -p $(OBJ_DIR)

# ==============================================================================
# 🎮 TARGET DI SVILUPPO
# ==============================================================================

# Modalità debug
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: clean $(TARGET)
	@echo "$(PURPLE)🐛 $(TARGET) compilato in modalità DEBUG$(NC)"

# Test completo
test: $(TARGET)
	@echo "$(CYAN)🧪 TEST BST DELETE$(NC)"
	@echo "$(CYAN)====================$(NC)"
	@echo "$(YELLOW)🎮 Programma con menu interattivo per Binary Search Tree$(NC)"
	@echo "$(YELLOW)   1: Inserimento nodo$(NC)"
	@echo "$(YELLOW)   2: Cancellazione nodo$(NC)"
	@echo "$(YELLOW)   3: Stampa BST$(NC)"
	@echo "$(YELLOW)   4: Ricerca chiave$(NC)"
	@echo "$(YELLOW)   5: Uscita$(NC)"
	@echo ""
	@./$(TARGET)

# Esecuzione diretta
run: $(TARGET)
	@echo "$(GREEN)🚀 Esecuzione $(TARGET)$(NC)"
	@./$(TARGET)

# Test automatico con dati predefiniti
demo: $(TARGET)
	@echo "$(CYAN)🎬 DEMO BST DELETE$(NC)"
	@echo "$(CYAN)==================$(NC)"
	@echo "$(YELLOW)Test automatico: inserimento, ricerca, cancellazione$(NC)"
	@echo ""
	@(echo "1"; echo "10"; echo "primo"; \
	  echo "1"; echo "5"; echo "secondo"; \
	  echo "1"; echo "15"; echo "terzo"; \
	  echo "3"; \
	  echo "4"; echo "10"; \
	  echo "2"; echo "10"; \
	  echo "3"; \
	  echo "5") | ./$(TARGET)

# ==============================================================================
# 🔍 TARGET DI ANALISI E VERIFICA
# ==============================================================================

# Verifica sintassi senza linking
check:
	@echo "$(CYAN)🔍 Verifica sintassi...$(NC)"
	@for file in $(SOURCES); do \
		echo "$(BLUE)   Controllo $$file$(NC)"; \
		$(CXX) $(CXXFLAGS) -fsyntax-only $$file; \
	done
	@echo "$(GREEN)✅ Sintassi corretta!$(NC)"

# Analisi statica
analyze:
	@echo "$(PURPLE)🔬 Analisi statica del codice$(NC)"
	@echo "$(CYAN)================================$(NC)"
	@echo "$(YELLOW)📊 Statistiche file:$(NC)"
	@wc -l $(SOURCES) $(HEADERS)
	@echo ""
	@echo "$(YELLOW)🔍 Funzioni BST principali:$(NC)"
	@grep -n "bst_.*(" $(HEADERS) | head -10
	@echo ""
	@echo "$(YELLOW)🎯 Operazioni implementate:$(NC)"
	@echo "   - Inserimento: bst_insert"
	@echo "   - Cancellazione: bst_delete"
	@echo "   - Ricerca: bst_search"
	@echo "   - Stampa: print_BST"

# Verifica memory leak (se valgrind disponibile)
memcheck: debug
	@echo "$(RED)🔍 Memory Check con Valgrind$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(YELLOW)ℹ️  Test automatico con valgrind$(NC)"; \
		echo "1\n10\ntest\n3\n5" | valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET); \
	else \
		echo "$(RED)❌ Valgrind non disponibile$(NC)"; \
	fi

# ==============================================================================
# 🧹 TARGET DI PULIZIA
# ==============================================================================

# Pulizia file temporanei
clean:
	@echo "$(YELLOW)🧹 Pulizia file temporanei...$(NC)"
	@rm -rf $(OBJ_DIR)
	@rm -f $(TARGET)
	@rm -f *.dSYM
	@rm -rf $(TARGET).dSYM
	@echo "$(GREEN)✅ Pulizia completata$(NC)"

# Pulizia completa (include documentazione)
distclean: clean
	@echo "$(YELLOW)🧹 Pulizia completa...$(NC)"
	@rm -rf $(DOC_DIR)
	@rm -f *.tar.gz
	@echo "$(GREEN)✅ Pulizia completa$(NC)"

# ==============================================================================
# 📚 TARGET DI DOCUMENTAZIONE
# ==============================================================================

# Generazione documentazione
doc:
	@echo "$(CYAN)📚 Generazione documentazione...$(NC)"
	@mkdir -p $(DOC_DIR)
	@echo "# 🗑️ BST Delete - Binary Search Tree con Cancellazione" > $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 📋 Descrizione" >> $(DOC_DIR)/README.md
	@echo "Programma completo per la gestione di un Binary Search Tree con operazioni di:" >> $(DOC_DIR)/README.md
	@echo "- Inserimento nodi" >> $(DOC_DIR)/README.md
	@echo "- Cancellazione nodi" >> $(DOC_DIR)/README.md
	@echo "- Ricerca per chiave" >> $(DOC_DIR)/README.md
	@echo "- Stampa in-order" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🏗️ Struttura" >> $(DOC_DIR)/README.md
	@echo "- **main.cc**: Menu interattivo con 5 opzioni" >> $(DOC_DIR)/README.md
	@echo "- **bst.h/cc**: Implementazione completa BST con cancellazione" >> $(DOC_DIR)/README.md
	@echo "- **tipo.h/cc**: Gestione tipo dati (stringhe)" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## ⚡ Menu Operazioni" >> $(DOC_DIR)/README.md
	@echo "1. **Inserimento**: Aggiunge un nuovo nodo con chiave e valore" >> $(DOC_DIR)/README.md
	@echo "2. **Cancellazione**: Rimuove un nodo per chiave (gestisce tutti i casi)" >> $(DOC_DIR)/README.md
	@echo "3. **Stampa**: Visualizza l'albero in ordine crescente" >> $(DOC_DIR)/README.md
	@echo "4. **Ricerca**: Trova un nodo per chiave" >> $(DOC_DIR)/README.md
	@echo "5. **Uscita**: Termina il programma" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🚀 Utilizzo" >> $(DOC_DIR)/README.md
	@echo "\`\`\`bash" >> $(DOC_DIR)/README.md
	@echo "make           # Compila il progetto" >> $(DOC_DIR)/README.md
	@echo "make test      # Compila ed esegue con menu" >> $(DOC_DIR)/README.md
	@echo "make demo      # Test automatico" >> $(DOC_DIR)/README.md
	@echo "make debug     # Compila in modalità debug" >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "$(GREEN)✅ Documentazione generata in $(DOC_DIR)/$(NC)"

# ==============================================================================
# 📦 TARGET DI DISTRIBUZIONE
# ==============================================================================

# Creazione archivio per distribuzione
dist: clean
	@echo "$(CYAN)📦 Creazione archivio distribuzione...$(NC)"
	@tar -czf $(PROJECT_NAME).tar.gz *.cc *.h Makefile
	@echo "$(GREEN)✅ Archivio $(PROJECT_NAME).tar.gz creato$(NC)"

# ==============================================================================
# 🔧 TARGET DI UTILITÀ
# ==============================================================================

# Informazioni progetto
info:
	@echo "$(CYAN)ℹ️  INFORMAZIONI PROGETTO$(NC)"
	@echo "$(CYAN)========================$(NC)"
	@echo "$(YELLOW)Nome:$(NC) $(PROJECT_NAME)"
	@echo "$(YELLOW)Target:$(NC) $(TARGET)"
	@echo "$(YELLOW)File sorgenti:$(NC) $(SOURCES)"
	@echo "$(YELLOW)File header:$(NC) $(HEADERS)"
	@echo "$(YELLOW)Compilatore:$(NC) $(CXX)"
	@echo "$(YELLOW)Flag correnti:$(NC) $(CXXFLAGS)"
	@echo "$(YELLOW)Directory oggetti:$(NC) $(OBJ_DIR)"
	@echo "$(YELLOW)Funzionalità:$(NC) BST con inserimento, cancellazione, ricerca"

# Aiuto sui target disponibili
help:
	@echo "$(CYAN)🆘 AIUTO - MAKEFILE BST DELETE$(NC)"
	@echo "$(CYAN)===============================$(NC)"
	@echo "$(YELLOW)Target di compilazione:$(NC)"
	@echo "  make / make all    - Compila il progetto (release)"
	@echo "  make debug         - Compila in modalità debug"
	@echo ""
	@echo "$(YELLOW)Target di esecuzione:$(NC)"
	@echo "  make test          - Compila ed esegue il menu interattivo"
	@echo "  make run           - Esegue il programma"
	@echo "  make demo          - Test automatico con dati predefiniti"
	@echo ""
	@echo "$(YELLOW)Target di verifica:$(NC)"
	@echo "  make check         - Verifica sintassi"
	@echo "  make analyze       - Analisi statica del codice"
	@echo "  make memcheck      - Verifica memory leak (richiede valgrind)"
	@echo ""
	@echo "$(YELLOW)Target di utilità:$(NC)"
	@echo "  make clean         - Rimuove file temporanei"
	@echo "  make distclean     - Pulizia completa"
	@echo "  make doc           - Genera documentazione"
	@echo "  make dist          - Crea archivio distribuzione"
	@echo "  make info          - Informazioni progetto"
	@echo "  make help          - Mostra questo aiuto"
	@echo ""
	@echo "$(GREEN)🎮 MENU INTERATTIVO:$(NC)"
	@echo "  1: Inserimento nodo    2: Cancellazione nodo"
	@echo "  3: Stampa BST          4: Ricerca chiave"
	@echo "  5: Uscita"

# ==============================================================================
# 🎯 DICHIARAZIONE TARGET PHONY
# ==============================================================================

.PHONY: all debug test run demo check analyze memcheck clean distclean doc dist info help

# ==============================================================================
# 📝 DIPENDENZE AUTOMATICHE
# ==============================================================================

# Dipendenze header per ricompilazione automatica
$(OBJ_DIR)/main.o: main.cc bst.h tipo.h
$(OBJ_DIR)/bst.o: bst.cc bst.h tipo.h  
$(OBJ_DIR)/tipo.o: tipo.cc tipo.h

# ==============================================================================
# 📊 INFORMAZIONI MAKEFILE
# ==============================================================================
# Creato: $(shell date)
# Progetto: Binary Search Tree con cancellazione e menu interattivo
# Compilatore: g++ con standard C++11
# Caratteristiche: Menu 5 opzioni, inserimento, cancellazione, ricerca, stampa
# ==============================================================================