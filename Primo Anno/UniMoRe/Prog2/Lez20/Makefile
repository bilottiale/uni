# ==============================================================================
# 📊 MAKEFILE - GRAPH SOL (Rappresentazione Grafi con Liste di Adiacenza)
# ==============================================================================
# Progetto: Implementazione di grafi orientati/non orientati con liste di adiacenza
# Moduli: graph_sol.cc, grafo/grafo.cc, grafo/grafo.h
# Target: graph_sol (programma per caricare e visualizzare grafi da file)
# ==============================================================================

# 🎯 CONFIGURAZIONE PROGETTO
PROJECT_NAME = graph_sol
TARGET = $(PROJECT_NAME)
MAIN_SOURCE = graph_sol.cc
GRAFO_DIR = grafo
GRAFO_SOURCES = $(GRAFO_DIR)/grafo.cc
GRAFO_HEADERS = $(GRAFO_DIR)/grafo.h
ALL_SOURCES = $(MAIN_SOURCE) $(GRAFO_SOURCES)
ALL_HEADERS = $(GRAFO_HEADERS)
OBJECTS = $(ALL_SOURCES:%.cc=obj/%.o)

# 🔧 CONFIGURAZIONE COMPILATORE
CXX = g++
CXXFLAGS_BASE = -Wall -Wextra -std=c++11 -pedantic -I$(GRAFO_DIR)
CXXFLAGS_RELEASE = $(CXXFLAGS_BASE) -O2 -DNDEBUG
CXXFLAGS_DEBUG = $(CXXFLAGS_BASE) -g -O0 -DDEBUG
LDFLAGS = 

# 🎮 MODALITÀ DEFAULT (release)
CXXFLAGS = $(CXXFLAGS_RELEASE)

# 📁 DIRECTORY
OBJ_DIR = obj
DOC_DIR = doc
TEST_DIR = file-grafo

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
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creazione directory oggetti
$(OBJ_DIR):
	@echo "$(YELLOW)📁 Creazione directory $(OBJ_DIR)...$(NC)"
	@mkdir -p $(OBJ_DIR)/$(GRAFO_DIR)

# ==============================================================================
# 🎮 TARGET DI SVILUPPO
# ==============================================================================

# Modalità debug
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: clean $(TARGET)
	@echo "$(PURPLE)🐛 $(TARGET) compilato in modalità DEBUG$(NC)"

# Test con grafi di esempio
test: $(TARGET)
	@echo "$(CYAN)🧪 TEST GRAFI - LISTE DI ADIACENZA$(NC)"
	@echo "$(CYAN)=====================================$(NC)"
	@echo "$(YELLOW)📊 Test con grafi di esempio:$(NC)"
	@echo ""
	@echo "$(GREEN)🔹 Test Grafo 1 (non orientato, non pesato):$(NC)"
	@if [ -f $(TEST_DIR)/graph1 ]; then \
		echo "$(YELLOW)   Contenuto file:$(NC)"; \
		cat $(TEST_DIR)/graph1; \
		echo "$(YELLOW)   Output:$(NC)"; \
		./$(TARGET) $(TEST_DIR)/graph1 0 0; \
	else \
		echo "$(RED)   File $(TEST_DIR)/graph1 non trovato$(NC)"; \
	fi
	@echo ""
	@echo "$(GREEN)🔹 Test Grafo 1 pesato:$(NC)"
	@if [ -f $(TEST_DIR)/graph1.w ]; then \
		echo "$(YELLOW)   Contenuto file:$(NC)"; \
		cat $(TEST_DIR)/graph1.w; \
		echo "$(YELLOW)   Output:$(NC)"; \
		./$(TARGET) $(TEST_DIR)/graph1.w 0 1; \
	else \
		echo "$(RED)   File $(TEST_DIR)/graph1.w non trovato$(NC)"; \
	fi

# Test completo con tutti i grafi
test-all: $(TARGET)
	@echo "$(CYAN)🧪 TEST COMPLETO - TUTTI I GRAFI$(NC)"
	@echo "$(CYAN)================================$(NC)"
	@for file in $(TEST_DIR)/graph*; do \
		if [ -f "$$file" ]; then \
			echo "$(GREEN)🔹 Test file: $$file$(NC)"; \
			echo "$(YELLOW)   Contenuto:$(NC)"; \
			cat "$$file"; \
			echo "$(YELLOW)   Grafo non orientato non pesato:$(NC)"; \
			./$(TARGET) "$$file" 0 0; \
			echo "$(YELLOW)   Grafo orientato non pesato:$(NC)"; \
			./$(TARGET) "$$file" 1 0; \
			if [[ "$$file" == *.w ]]; then \
				echo "$(YELLOW)   Grafo non orientato pesato:$(NC)"; \
				./$(TARGET) "$$file" 0 1; \
				echo "$(YELLOW)   Grafo orientato pesato:$(NC)"; \
				./$(TARGET) "$$file" 1 1; \
			fi; \
			echo ""; \
		fi; \
	done

# Esecuzione interattiva
run: $(TARGET)
	@echo "$(GREEN)🚀 Esecuzione $(TARGET)$(NC)"
	@echo "$(YELLOW)Usage: ./$(TARGET) filename directed weighted$(NC)"
	@echo "$(YELLOW)  filename: file con definizione grafo$(NC)"
	@echo "$(YELLOW)  directed: 0=non orientato, 1=orientato$(NC)"
	@echo "$(YELLOW)  weighted: 0=non pesato, 1=pesato$(NC)"
	@echo ""
	@read -p "Inserisci nome file: " filename; \
	 read -p "Grafo orientato? (0/1): " directed; \
	 read -p "Grafo pesato? (0/1): " weighted; \
	 ./$(TARGET) "$$filename" "$$directed" "$$weighted"

# Demo con grafo predefinito
demo: $(TARGET)
	@echo "$(CYAN)🎬 DEMO GRAPH SOL$(NC)"
	@echo "$(CYAN)==================$(NC)"
	@echo "$(YELLOW)Demo con grafo triangolare (1-2-3-1)$(NC)"
	@echo ""
	@echo "3" > demo_graph.txt
	@echo "1 2" >> demo_graph.txt
	@echo "2 3" >> demo_graph.txt
	@echo "3 1" >> demo_graph.txt
	@echo "$(GREEN)🔹 Grafo generato:$(NC)"
	@cat demo_graph.txt
	@echo ""
	@echo "$(GREEN)🔹 Output non orientato:$(NC)"
	@./$(TARGET) demo_graph.txt 0 0
	@echo ""
	@echo "$(GREEN)🔹 Output orientato:$(NC)"
	@./$(TARGET) demo_graph.txt 1 0
	@rm -f demo_graph.txt

# ==============================================================================
# 🔍 TARGET DI ANALISI E VERIFICA
# ==============================================================================

# Verifica sintassi senza linking
check:
	@echo "$(CYAN)🔍 Verifica sintassi...$(NC)"
	@for file in $(ALL_SOURCES); do \
		echo "$(BLUE)   Controllo $$file$(NC)"; \
		$(CXX) $(CXXFLAGS) -fsyntax-only $$file; \
	done
	@echo "$(GREEN)✅ Sintassi corretta!$(NC)"

# Analisi statica
analyze:
	@echo "$(PURPLE)🔬 Analisi statica del codice$(NC)"
	@echo "$(CYAN)================================$(NC)"
	@echo "$(YELLOW)📊 Statistiche file:$(NC)"
	@wc -l $(ALL_SOURCES) $(ALL_HEADERS)
	@echo ""
	@echo "$(YELLOW)🔍 Funzioni principali grafo:$(NC)"
	@grep -n "^[a-zA-Z].*(" $(GRAFO_HEADERS) | head -10
	@echo ""
	@echo "$(YELLOW)🎯 Funzionalità implementate:$(NC)"
	@echo "   - Creazione grafo: new_graph"
	@echo "   - Arco orientato: add_arc"
	@echo "   - Spigolo non orientato: add_edge"
	@echo "   - Accesso lista adiacenza: get_adjlist"
	@echo "   - Navigazione liste: get_nextadj"
	@echo ""
	@echo "$(YELLOW)📁 File di test disponibili:$(NC)"
	@ls -la $(TEST_DIR)/ 2>/dev/null || echo "   Directory $(TEST_DIR) non trovata"

# Verifica memory leak (se valgrind disponibile)
memcheck: debug
	@echo "$(RED)🔍 Memory Check con Valgrind$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "$(YELLOW)ℹ️  Test con valgrind usando graph1$(NC)"; \
		if [ -f $(TEST_DIR)/graph1 ]; then \
			valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(TEST_DIR)/graph1 0 0; \
		else \
			echo "$(RED)❌ File di test non disponibile$(NC)"; \
		fi; \
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
	@rm -f demo_graph.txt
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
	@echo "# 📊 Graph Sol - Rappresentazione Grafi con Liste di Adiacenza" > $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 📋 Descrizione" >> $(DOC_DIR)/README.md
	@echo "Programma per la gestione di grafi mediante liste di adiacenza con supporto per:" >> $(DOC_DIR)/README.md
	@echo "- Grafi orientati e non orientati" >> $(DOC_DIR)/README.md
	@echo "- Archi pesati e non pesati" >> $(DOC_DIR)/README.md
	@echo "- Caricamento da file con formato specifico" >> $(DOC_DIR)/README.md
	@echo "- Visualizzazione liste di adiacenza" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🏗️ Struttura" >> $(DOC_DIR)/README.md
	@echo "- **graph_sol.cc**: Programma principale con parsing parametri" >> $(DOC_DIR)/README.md
	@echo "- **grafo/grafo.h**: Interfaccia strutture dati grafo" >> $(DOC_DIR)/README.md
	@echo "- **grafo/grafo.cc**: Implementazione operazioni su grafo" >> $(DOC_DIR)/README.md
	@echo "- **file-grafo/**: Directory con grafi di esempio" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 📄 Formato File Input" >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "n           # Numero di nodi" >> $(DOC_DIR)/README.md
	@echo "v1 v2 [w]   # Primo arco (peso opzionale)" >> $(DOC_DIR)/README.md
	@echo "v3 v4 [w]   # Secondo arco" >> $(DOC_DIR)/README.md
	@echo "..." >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## 🚀 Utilizzo" >> $(DOC_DIR)/README.md
	@echo "\`\`\`bash" >> $(DOC_DIR)/README.md
	@echo "make           # Compila il progetto" >> $(DOC_DIR)/README.md
	@echo "make test      # Test con grafi di esempio" >> $(DOC_DIR)/README.md
	@echo "make demo      # Demo con grafo triangolare" >> $(DOC_DIR)/README.md
	@echo "make debug     # Compila in modalità debug" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "# Esecuzione manuale:" >> $(DOC_DIR)/README.md
	@echo "./graph_sol filename directed weighted" >> $(DOC_DIR)/README.md
	@echo "# Esempi:" >> $(DOC_DIR)/README.md
	@echo "./graph_sol file-grafo/graph1 0 0    # Non orientato, non pesato" >> $(DOC_DIR)/README.md
	@echo "./graph_sol file-grafo/graph1.w 1 1  # Orientato, pesato" >> $(DOC_DIR)/README.md
	@echo "\`\`\`" >> $(DOC_DIR)/README.md
	@echo "" >> $(DOC_DIR)/README.md
	@echo "## ⚙️ Opzioni" >> $(DOC_DIR)/README.md
	@echo "- **directed**: 0 = grafo non orientato, 1 = grafo orientato" >> $(DOC_DIR)/README.md
	@echo "- **weighted**: 0 = archi non pesati (peso=1.0), 1 = archi pesati" >> $(DOC_DIR)/README.md
	@echo "$(GREEN)✅ Documentazione generata in $(DOC_DIR)/$(NC)"

# ==============================================================================
# 📦 TARGET DI DISTRIBUZIONE
# ==============================================================================

# Creazione archivio per distribuzione
dist: clean
	@echo "$(CYAN)📦 Creazione archivio distribuzione...$(NC)"
	@tar -czf $(PROJECT_NAME).tar.gz *.cc $(GRAFO_DIR)/ $(TEST_DIR)/ Makefile
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
	@echo "$(YELLOW)File principale:$(NC) $(MAIN_SOURCE)"
	@echo "$(YELLOW)Modulo grafo:$(NC) $(GRAFO_SOURCES)"
	@echo "$(YELLOW)Header grafo:$(NC) $(GRAFO_HEADERS)"
	@echo "$(YELLOW)Compilatore:$(NC) $(CXX)"
	@echo "$(YELLOW)Flag correnti:$(NC) $(CXXFLAGS)"
	@echo "$(YELLOW)Directory test:$(NC) $(TEST_DIR)"
	@echo "$(YELLOW)Funzionalità:$(NC) Grafi con liste di adiacenza (orientati/pesati)"

# Aiuto sui target disponibili
help:
	@echo "$(CYAN)🆘 AIUTO - MAKEFILE GRAPH SOL$(NC)"
	@echo "$(CYAN)=============================$(NC)"
	@echo "$(YELLOW)Target di compilazione:$(NC)"
	@echo "  make / make all    - Compila il progetto (release)"
	@echo "  make debug         - Compila in modalità debug"
	@echo ""
	@echo "$(YELLOW)Target di esecuzione:$(NC)"
	@echo "  make test          - Test con grafi di esempio"
	@echo "  make test-all      - Test completo con tutti i grafi"
	@echo "  make run           - Esecuzione interattiva"
	@echo "  make demo          - Demo con grafo triangolare"
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
	@echo "$(GREEN)📊 UTILIZZO PROGRAMMA:$(NC)"
	@echo "  ./graph_sol filename directed weighted"
	@echo "  - filename: file con definizione grafo"
	@echo "  - directed: 0=non orientato, 1=orientato"
	@echo "  - weighted: 0=non pesato, 1=pesato"

# ==============================================================================
# 🎯 DICHIARAZIONE TARGET PHONY
# ==============================================================================

.PHONY: all debug test test-all run demo check analyze memcheck clean distclean doc dist info help

# ==============================================================================
# 📝 DIPENDENZE AUTOMATICHE
# ==============================================================================

# Dipendenze header per ricompilazione automatica
$(OBJ_DIR)/graph_sol.o: graph_sol.cc $(GRAFO_HEADERS)
$(OBJ_DIR)/$(GRAFO_DIR)/grafo.o: $(GRAFO_SOURCES) $(GRAFO_HEADERS)

# ==============================================================================
# 📊 INFORMAZIONI MAKEFILE
# ==============================================================================
# Creato: $(shell date)
# Progetto: Rappresentazione grafi con liste di adiacenza
# Compilatore: g++ con standard C++11
# Caratteristiche: Grafi orientati/non orientati, pesati/non pesati, caricamento da file
# ==============================================================================
