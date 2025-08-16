# ==============================================================================
# 🌳 MAKEFILE - BST PRINT (Binary Search Tree con stampa)
# ==============================================================================
# Progetto: Gestione e stampa di un Binary Search Tree
# Moduli: main.cc, bst.cc, tipo.cc
# Target: bst_print (programma interattivo per BST)
# ==============================================================================

# 🎯 CONFIGURAZIONE PROGETTO
PROJECT_NAME = bst_print
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

# Target completo con input interattivo
test: $(TARGET)
	@echo "$(CYAN)🧪 TEST BST PRINT$(NC)"
	@echo "$(CYAN)==================$(NC)"
	@echo "$(YELLOW)ℹ️  Programma interattivo per Binary Search Tree$(NC)"
	@echo "$(YELLOW)   Inserisci chiavi (int) e valori (string) per testare$(NC)"
	@echo "$(YELLOW)   Digita 0 per terminare l'inserimento$(NC)"
	@echo ""
	@./$(TARGET)

# Test rapido con dati predefiniti
test-simple: test_simple
	@echo "$(CYAN)🧪 TEST BST SEMPLIFICATO$(NC)"
	@echo "$(CYAN)========================$(NC)"
	@./test_simple

# Compilazione test semplificato
test_simple: obj/test_simple.o obj/bst.o obj/tipo.o
	@echo "$(CYAN)🔗 Linking test_simple...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Versione corretta con input robusto
bst_fixed: obj/main_fixed.o obj/bst.o obj/tipo.o
	@echo "$(CYAN)🔗 Linking bst_fixed...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilazione test_simple.o
obj/test_simple.o: test_simple.cc | $(OBJ_DIR)
	@echo "$(BLUE)🔨 Compilazione test_simple.cc...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilazione main_fixed.o
obj/main_fixed.o: main_fixed.cc | $(OBJ_DIR)
	@echo "$(BLUE)🔨 Compilazione main_fixed.cc...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Esecuzione diretta
run: $(TARGET)
	@echo "$(GREEN)🚀 Esecuzione $(TARGET)$(NC)"
	@./$(TARGET)

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
	@echo "$(YELLOW)🔍 Verifica include:$(NC)"
	@grep -n "#include" $(SOURCES) $(HEADERS) | head -10
	@echo ""
	@echo "$(YELLOW)🎯 Funzioni pubbliche:$(NC)"
	@grep -n "^[a-zA-Z_].*(" $(HEADERS) | head -10

# Verifica memory leak (se valgrind disponibile)
memcheck: debug
	@echo "$(RED)🔍 Memory Check con Valgrind$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(YELLOW)ℹ️  Input di test: 10 'test' 20 'hello' 0$(NC)"; \
		echo "10\ntest\n20\nhello\n0" | valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET); \
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
	@rm -f test_simple
	@rm -f bst_fixed
	@rm -f *.dSYM
	@rm -rf $(TARGET).dSYM
	@rm -rf test_simple.dSYM
	@rm -rf bst_fixed.dSYM
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
	@echo "# 🌳 BST Print - Binary Search Tree" > $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 📋 Descrizione" >> $(DOC_DIR)/README.md
	@echo "Programma per la gestione e stampa di un Binary Search Tree (BST)." >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🏗️ Struttura" >> $(DOC_DIR)/README.md
	@echo "- **main.cc**: Programma principale con interfaccia utente" >> $(DOC_DIR)/README.md
	@echo "- **bst.h/cc**: Implementazione Binary Search Tree" >> $(DOC_DIR)/README.md
	@echo "- **tipo.h/cc**: Gestione tipo dati (stringhe)" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## ⚡ Funzionalità" >> $(DOC_DIR)/README.md
	@echo "- Inserimento nodi con chiave (int) e valore (string)" >> $(DOC_DIR)/README.md
	@echo "- Stampa in-order del BST" >> $(DOC_DIR)/README.md
	@echo "- Gestione memoria dinamica" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🚀 Utilizzo" >> $(DOC_DIR)/README.md
	@echo "\`\`\`bash" >> $(DOC_DIR)/README.md
	@echo "make           # Compila il progetto" >> $(DOC_DIR)/README.md
	@echo "make test      # Compila ed esegue" >> $(DOC_DIR)/README.md
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

# Aiuto sui target disponibili
help:
	@echo "$(CYAN)🆘 AIUTO - MAKEFILE BST PRINT$(NC)"
	@echo "$(CYAN)==============================$(NC)"
	@echo "$(YELLOW)Target di compilazione:$(NC)"
	@echo "  make / make all    - Compila il progetto originale (con bug di input)"
	@echo "  make bst_fixed     - Compila la versione corretta (consigliata)"
	@echo "  make debug         - Compila in modalità debug"
	@echo ""
	@echo "$(YELLOW)Target di esecuzione:$(NC)"
	@echo "  make test          - Compila ed esegue il programma originale"
	@echo "  make test-simple   - Test rapido con dati predefiniti"
	@echo "  ./bst_fixed        - Esegue la versione corretta"
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
	@echo "$(GREEN)💡 RACCOMANDAZIONE: Usa 'make bst_fixed' per la versione senza bug!$(NC)"

# ==============================================================================
# 🎯 DICHIARAZIONE TARGET PHONY
# ==============================================================================

.PHONY: all debug test run check analyze memcheck clean distclean doc dist info help

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
# Progetto: Binary Search Tree con stampa in-order
# Compilatore: g++ con standard C++11
# Caratteristiche: Build modulare, debug, test, analisi
# ==============================================================================
