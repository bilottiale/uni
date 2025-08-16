# Makefile per VisitaDFS_Albero - Lez18
# Progetto: Implementazione visita Depth-First Search di alberi
# Autore: Alessandro Bilotti  
# Data: 11 agosto 2025

# ============================================================================
# CONFIGURAZIONE COMPILATORE
# ============================================================================

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -pedantic
DEBUG_FLAGS = -g -DDEBUG -O0
RELEASE_FLAGS = -O2 -DNDEBUG
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

# ============================================================================
# FILE E DIRECTORY
# ============================================================================

# File sorgenti
SOURCES = main.cc tree.cc tipo.cc
HEADERS = tree.h tipo.h

# File oggetto
OBJECTS = $(SOURCES:.cc=.o)
OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJECTS))

# Eseguibile
TARGET = visitaDFS_albero
TARGET_DEBUG = $(TARGET)_debug

# File di output e test
OUTPUT_FILE = output.txt
TREE_DIAGRAM = tree_structure.txt

# ============================================================================
# TARGET PRINCIPALI
# ============================================================================

# Target predefinito
all: $(TARGET)

# Compilazione release
$(TARGET): $(OBJ_FILES)
	@echo "🔗 Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -o $@ $^
	@echo "✅ $(TARGET) compilato con successo!"

# Compilazione debug
debug: $(TARGET_DEBUG)

$(TARGET_DEBUG): CXXFLAGS += $(DEBUG_FLAGS)
$(TARGET_DEBUG): $(OBJ_FILES)
	@echo "🐛 Linking $(TARGET_DEBUG)..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "✅ $(TARGET_DEBUG) compilato con successo!"

# ============================================================================
# COMPILAZIONE MODULI
# ============================================================================

# Creazione directory oggetti
$(OBJ_DIR):
	@echo "📁 Creazione directory $(OBJ_DIR)..."
	@mkdir -p $(OBJ_DIR)

# Compilazione main.cc
$(OBJ_DIR)/main.o: main.cc tree.h tipo.h | $(OBJ_DIR)
	@echo "🔨 Compilazione main.cc..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Compilazione tree.cc
$(OBJ_DIR)/tree.o: tree.cc tree.h tipo.h | $(OBJ_DIR)
	@echo "🔨 Compilazione tree.cc..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Compilazione tipo.cc
$(OBJ_DIR)/tipo.o: tipo.cc tipo.h | $(OBJ_DIR)
	@echo "🔨 Compilazione tipo.cc..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# ============================================================================
# ESECUZIONE E TEST
# ============================================================================

# Esecuzione normale
run: $(TARGET)
	@echo "🚀 Esecuzione di $(TARGET)..."
	@echo "🌳 Output della serializzazione dell'albero:"
	./$(TARGET)
	@echo ""

# Esecuzione debug
run-debug: $(TARGET_DEBUG)
	@echo "🐛 Esecuzione debug di $(TARGET_DEBUG)..."
	@echo "🌳 Output con informazioni di debug:"
	./$(TARGET_DEBUG)
	@echo ""

# Test con output salvato
test: $(TARGET)
	@echo "🧪 Test di $(TARGET) con salvataggio output..."
	./$(TARGET) > $(OUTPUT_FILE)
	@echo "📄 Output salvato in $(OUTPUT_FILE):"
	@cat $(OUTPUT_FILE)
	@echo ""
	@echo "✅ Test completato!"

# Test della struttura albero
test-structure: $(TARGET)
	@echo "🌳 TEST STRUTTURA ALBERO"
	@echo "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
	@echo "🎯 Albero creato nel programma:"
	@echo "        Luca (root)"
	@echo "       /  |  \\"
	@echo "   Paolo Marco Anna"
	@echo "           |"
	@echo "        Lucia"
	@echo ""
	@echo "📊 Serializzazione DFS (Pre-order):"
	./$(TARGET)
	@echo ""
	@echo "💡 La serializzazione dovrebbe essere: (Luca(Paolo)(Marco(Lucia))(Anna))"

# ============================================================================
# ANALISI E DEBUG
# ============================================================================

# Controllo sintassi
check:
	@echo "🔍 Controllo sintassi di tutti i moduli..."
	$(CXX) $(CXXFLAGS) -fsyntax-only main.cc
	$(CXX) $(CXXFLAGS) -fsyntax-only tree.cc
	$(CXX) $(CXXFLAGS) -fsyntax-only tipo.cc
	@echo "✅ Sintassi corretta!"

# Analisi statica
analyze:
	@echo "🔬 Analisi statica del codice..."
	@echo "📋 Dipendenze:"
	@echo "   main.cc → tree.h, tipo.h"
	@echo "   tree.cc → tree.h, tipo.h"
	@echo "   tipo.cc → tipo.h"
	@echo ""
	@echo "🏗️  Struttura dati:"
	@echo "   struct node { tipo_inf, parent*, firstChild*, nextSibling* }"
	@echo "   typedef char* tipo_inf"
	@echo ""
	@echo "⚙️  Algoritmo: Visita DFS con serializzazione ricorsiva"

# Debug con GDB
gdb: $(TARGET_DEBUG)
	@echo "🐛 Avvio debug con GDB..."
	gdb ./$(TARGET_DEBUG)

# Controllo memory leaks
valgrind: $(TARGET_DEBUG)
	@echo "🔍 Controllo memory leaks con Valgrind..."
	valgrind $(VALGRIND_FLAGS) ./$(TARGET_DEBUG)

# ============================================================================
# DOCUMENTAZIONE
# ============================================================================

# Informazioni sul progetto
info:
	@echo "📋 INFORMAZIONI PROGETTO"
	@echo "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
	@echo "🎯 Progetto: Visita DFS di Alberi (firstChild-nextSibling)"
	@echo "📁 Directory: Lez18/visitaDFS_albero"
	@echo "📄 File sorgenti: $(SOURCES)"
	@echo "📄 File header: $(HEADERS)"
	@echo "🎯 Algoritmo: Depth-First Search ricorsivo"
	@echo "🌳 Struttura: Albero generale con rappresentazione firstChild-nextSibling"
	@echo ""
	@echo "🔧 Funzionalità implementate:"
	@echo "   • Creazione nodi albero"
	@echo "   • Inserimento figli e fratelli"
	@echo "   • Visita DFS con serializzazione"
	@echo "   • Gestione tipo_inf (stringhe)"
	@echo ""
	@echo "📊 Complessità:"
	@echo "   • Spazio: O(altezza) per stack ricorsione"
	@echo "   • Tempo: O(n) dove n = numero nodi"

# Mostra dipendenze
deps:
	@echo "🔗 DIPENDENZE DEI MODULI"
	@echo "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
	@echo "main.cc:"
	@echo "  ├── tree.h (interfaccia albero)"
	@echo "  └── tipo.h (tipo di dato)"
	@echo ""
	@echo "tree.cc:"
	@echo "  ├── tree.h (propria interfaccia)"
	@echo "  └── tipo.h (tipo di dato)"
	@echo ""
	@echo "tipo.cc:"
	@echo "  └── tipo.h (propria interfaccia)"
	@echo ""
	@echo "📦 Ordine di compilazione: tipo.o → tree.o → main.o → linking"

# Genera documentazione con Doxygen (se disponibile)
docs:
	@echo "📚 Generazione documentazione..."
	@if command -v doxygen >/dev/null 2>&1; then \
		echo "🔧 Doxygen trovato, generazione in corso..."; \
		doxygen -g Doxyfile.tmp 2>/dev/null; \
		echo "PROJECT_NAME = \"VisitaDFS Albero\"" >> Doxyfile.tmp; \
		echo "INPUT = ." >> Doxyfile.tmp; \
		echo "RECURSIVE = YES" >> Doxyfile.tmp; \
		doxygen Doxyfile.tmp 2>/dev/null; \
		rm -f Doxyfile.tmp; \
		echo "✅ Documentazione generata in html/"; \
	else \
		echo "❌ Doxygen non trovato. Installa con: brew install doxygen"; \
	fi

# ============================================================================
# GESTIONE PROGETTO
# ============================================================================

# Pulizia file temporanei
clean:
	@echo "🧹 Pulizia file generati..."
	rm -f $(TARGET) $(TARGET_DEBUG)
	rm -rf $(OBJ_DIR)
	rm -f $(OUTPUT_FILE) $(TREE_DIAGRAM)
	@echo "✅ Pulizia completata!"

# Pulizia completa (include documentazione)
clean-all: clean
	@echo "🧹 Pulizia completa..."
	rm -rf html/ latex/ Doxyfile.tmp
	@echo "✅ Pulizia completa terminata!"

# Backup del progetto
backup:
	@echo "💾 Creazione backup del progetto..."
	@TIMESTAMP=$$(date +%Y%m%d_%H%M%S); \
	tar -czf ../visitaDFS_albero_backup_$$TIMESTAMP.tar.gz .; \
	echo "✅ Backup creato: ../visitaDFS_albero_backup_$$TIMESTAMP.tar.gz"

# Installazione (copia eseguibile in /usr/local/bin)
install: $(TARGET)
	@echo "📦 Installazione di $(TARGET)..."
	@if [ -w /usr/local/bin ]; then \
		cp $(TARGET) /usr/local/bin/; \
		echo "✅ $(TARGET) installato in /usr/local/bin/"; \
	else \
		echo "❌ Permessi insufficienti. Usa: sudo make install"; \
	fi

# ============================================================================
# COMANDI UTILI SVILUPPO
# ============================================================================

# Formattazione codice (se clang-format è disponibile)
format:
	@echo "🎨 Formattazione codice..."
	@if command -v clang-format >/dev/null 2>&1; then \
		clang-format -i *.cc *.h; \
		echo "✅ Codice formattato!"; \
	else \
		echo "❌ clang-format non trovato"; \
	fi

# Conta linee di codice
count:
	@echo "📊 STATISTICHE CODICE"
	@echo "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
	@echo "📄 File sorgenti:"
	@wc -l $(SOURCES) $(HEADERS) | tail -1
	@echo ""
	@echo "📋 Dettaglio per file:"
	@wc -l $(SOURCES) $(HEADERS)

# Controllo TODO e FIXME
todo:
	@echo "📝 TODO e FIXME nel codice:"
	@grep -n -E "TODO|FIXME|XXX|HACK" $(SOURCES) $(HEADERS) || echo "✅ Nessun TODO trovato!"

# ============================================================================
# AIUTO
# ============================================================================

help:
	@echo "🎯 MAKEFILE - VISITA DFS ALBERO"
	@echo "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "="
	@echo ""
	@echo "📋 TARGET PRINCIPALI:"
	@echo "   make all          - Compila il progetto"
	@echo "   make debug        - Compila versione debug"
	@echo "   make run          - Compila ed esegue"
	@echo "   make run-debug    - Compila ed esegue versione debug"
	@echo "   make test         - Test con output salvato"
	@echo ""
	@echo "🔧 SVILUPPO:"
	@echo "   make check        - Controllo sintassi"
	@echo "   make analyze      - Analisi statica codice"
	@echo "   make clean        - Rimuove file generati"
	@echo "   make clean-all    - Pulizia completa"
	@echo ""
	@echo "🐛 DEBUG:"
	@echo "   make gdb          - Debug con GDB"
	@echo "   make valgrind     - Controllo memory leaks"
	@echo ""
	@echo "📚 DOCUMENTAZIONE:"
	@echo "   make info         - Informazioni progetto"
	@echo "   make deps         - Mostra dipendenze"
	@echo "   make docs         - Genera documentazione"
	@echo ""
	@echo "🛠️  UTILITÀ:"
	@echo "   make backup       - Backup progetto"
	@echo "   make install      - Installa eseguibile"
	@echo "   make count        - Conta linee codice"
	@echo "   make todo         - Trova TODO nel codice"

# ============================================================================
# TARGET PHONY
# ============================================================================

.PHONY: all debug run run-debug test test-structure check analyze gdb valgrind
.PHONY: info deps docs clean clean-all backup install format count todo help
