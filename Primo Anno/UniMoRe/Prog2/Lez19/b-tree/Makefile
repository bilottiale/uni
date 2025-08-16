# Makefile per B-Tree - Lez19
# Progetto: Implementazione albero binario con gestione memoria
# Autore: Alessandro Bilotti
# Data: 14 agosto 2025

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
SOURCES = main.cc b-tree.cc tipo.cc
HEADERS = btree.h tipo.h b-tree.h

# File oggetto
OBJECTS = $(SOURCES:.cc=.o)
OBJ_DIR = obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJECTS))

# Eseguibile
TARGET = btree_test
TARGET_DEBUG = $(TARGET)_debug

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
$(OBJ_DIR)/main.o: main.cc btree.h tipo.h | $(OBJ_DIR)
	@echo "🔨 Compilazione main.cc..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Compilazione b-tree.cc
$(OBJ_DIR)/b-tree.o: b-tree.cc btree.h tipo.h | $(OBJ_DIR)
	@echo "🔨 Compilazione b-tree.cc..."
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
	@echo ""
	./$(TARGET)

# Esecuzione debug
run-debug: $(TARGET_DEBUG)
	@echo "🐛 Esecuzione debug di $(TARGET_DEBUG)..."
	@echo ""
	./$(TARGET_DEBUG)

# Test completo
test: $(TARGET)
	@echo "🧪 TEST COMPLETO ALBERO BINARIO"
	@echo "================================"
	./$(TARGET)
	@echo ""
	@echo "✅ Test completato!"

# Test con valgrind
test-memory: $(TARGET_DEBUG)
	@echo "🔍 Test memory leaks con Valgrind..."
	valgrind $(VALGRIND_FLAGS) ./$(TARGET_DEBUG)

# ============================================================================
# ANALISI E DEBUG
# ============================================================================

# Controllo sintassi
check:
	@echo "🔍 Controllo sintassi di tutti i moduli..."
	$(CXX) $(CXXFLAGS) -fsyntax-only main.cc
	$(CXX) $(CXXFLAGS) -fsyntax-only b-tree.cc
	$(CXX) $(CXXFLAGS) -fsyntax-only tipo.cc
	@echo "✅ Sintassi corretta!"

# Analisi statica
analyze:
	@echo "🔬 ANALISI STATICA PROGETTO B-TREE"
	@echo "==================================="
	@echo "📋 Struttura file:"
	@echo "   main.cc    - Programma di test"
	@echo "   b-tree.cc  - Implementazione albero binario"
	@echo "   tipo.cc    - Implementazione tipo dato"
	@echo "   btree.h    - Interfaccia albero"
	@echo "   tipo.h     - Interfaccia tipo"
	@echo ""
	@echo "🏗️  Struttura dati:"
	@echo "   struct bnode { tipo_inf, parent*, left*, right* }"
	@echo "   typedef char* tipo_inf"
	@echo "   typedef bnode* btree"
	@echo ""
	@echo "⚙️  Funzionalità:"
	@echo "   • Creazione e inserimento nodi"
	@echo "   • Navigazione (parent, left, right)"
	@echo "   • Gestione memoria stringhe"
	@echo "   • Confronto e copia tipo dato"

# Debug con GDB
gdb: $(TARGET_DEBUG)
	@echo "🐛 Avvio debug con GDB..."
	gdb ./$(TARGET_DEBUG)

# ============================================================================
# DOCUMENTAZIONE
# ============================================================================

# Informazioni sul progetto
info:
	@echo "📋 INFORMAZIONI PROGETTO B-TREE"
	@echo "================================"
	@echo "🎯 Progetto: Albero Binario con gestione memoria"
	@echo "📁 Directory: Lez19/b-tree"
	@echo "📄 File sorgenti: $(SOURCES)"
	@echo "📄 File header: $(HEADERS)"
	@echo "🌳 Struttura: Albero binario classico (left-right-parent)"
	@echo "💾 Tipo dato: Stringhe allocate dinamicamente"
	@echo ""
	@echo "🔧 Operazioni implementate:"
	@echo "   • new_node(tipo_inf) - Crea nuovo nodo"
	@echo "   • insert_left/right() - Inserisce figli"
	@echo "   • get_parent/left/right() - Navigazione"
	@echo "   • get_info() - Accesso informazioni"
	@echo "   • copy/compare/print/destroy() - Gestione tipo"
	@echo ""
	@echo "🎯 Caratteristiche:"
	@echo "   • Gestione memoria sicura"
	@echo "   • Puntatori bidirezionali"
	@echo "   • Interfacce modulari"

# Mostra dipendenze
deps:
	@echo "🔗 DIPENDENZE DEI MODULI"
	@echo "========================"
	@echo "main.cc:"
	@echo "  ├── btree.h (interfaccia albero)"
	@echo "  └── tipo.h (tipo di dato)"
	@echo ""
	@echo "b-tree.cc:"
	@echo "  ├── btree.h (propria interfaccia)"
	@echo "  └── tipo.h (tipo di dato)"
	@echo ""
	@echo "tipo.cc:"
	@echo "  └── tipo.h (propria interfaccia)"
	@echo ""
	@echo "⚠️  NOTA: Il file include \"btree.h\" ma esiste anche \"b-tree.h\""
	@echo "📦 Ordine di compilazione: tipo.o → b-tree.o → main.o → linking"

# ============================================================================
# GESTIONE FILE E PULIZIA
# ============================================================================

# Risoluzione conflitto nomi
fix-headers:
	@echo "🔧 Risoluzione conflitto header files..."
	@if [ -f "b-tree.h" ] && [ -f "btree.h" ]; then \
		echo "⚠️  Trovati sia b-tree.h che btree.h"; \
		echo "🔄 Rinomino b-tree.h in b-tree.h.backup"; \
		mv b-tree.h b-tree.h.backup; \
		echo "✅ btree.h è ora l'header principale"; \
	else \
		echo "✅ Nessun conflitto rilevato"; \
	fi

# Lista file generati
list-files:
	@echo "📄 FILE DEL PROGETTO"
	@echo "===================="
	@echo "📋 File sorgenti:"
	@ls -la *.cc 2>/dev/null || echo "   Nessun file .cc"
	@echo ""
	@echo "📋 File header:"
	@ls -la *.h 2>/dev/null || echo "   Nessun file .h"
	@echo ""
	@echo "📋 File oggetto:"
	@ls -la $(OBJ_DIR)/*.o 2>/dev/null || echo "   Nessun file oggetto"
	@echo ""
	@echo "📋 Eseguibili:"
	@ls -la $(TARGET) $(TARGET_DEBUG) 2>/dev/null || echo "   Nessun eseguibile"

# Pulizia file temporanei
clean:
	@echo "🧹 Pulizia file generati..."
	rm -f $(TARGET) $(TARGET_DEBUG)
	rm -rf $(OBJ_DIR)
	@echo "✅ Pulizia completata!"

# Pulizia completa
clean-all: clean
	@echo "🧹 Pulizia completa..."
	rm -f *.backup *~
	@echo "✅ Pulizia completa terminata!"

# ============================================================================
# UTILITÀ SVILUPPO
# ============================================================================

# Conta linee di codice
count:
	@echo "📊 STATISTICHE CODICE"
	@echo "====================="
	@echo "📄 File sorgenti:"
	@wc -l $(SOURCES) $(HEADERS) | tail -1
	@echo ""
	@echo "📋 Dettaglio per file:"
	@wc -l $(SOURCES) $(HEADERS)

# Backup del progetto
backup:
	@echo "💾 Creazione backup del progetto..."
	@TIMESTAMP=$$(date +%Y%m%d_%H%M%S); \
	tar -czf ../btree_backup_$$TIMESTAMP.tar.gz .; \
	echo "✅ Backup creato: ../btree_backup_$$TIMESTAMP.tar.gz"

# ============================================================================
# AIUTO
# ============================================================================

help:
	@echo "🎯 MAKEFILE - ALBERO BINARIO"
	@echo "============================="
	@echo ""
	@echo "📋 TARGET PRINCIPALI:"
	@echo "   make all          - Compila il progetto"
	@echo "   make debug        - Compila versione debug"
	@echo "   make run          - Compila ed esegue"
	@echo "   make run-debug    - Compila ed esegue versione debug"
	@echo "   make test         - Test completo"
	@echo ""
	@echo "🔧 SVILUPPO:"
	@echo "   make check        - Controllo sintassi"
	@echo "   make analyze      - Analisi statica"
	@echo "   make clean        - Rimuove file generati"
	@echo "   make fix-headers  - Risolve conflitti header"
	@echo ""
	@echo "🐛 DEBUG:"
	@echo "   make gdb          - Debug con GDB"
	@echo "   make test-memory  - Test memory leaks"
	@echo ""
	@echo "📚 DOCUMENTAZIONE:"
	@echo "   make info         - Informazioni progetto"
	@echo "   make deps         - Mostra dipendenze"
	@echo "   make list-files   - Lista tutti i file"
	@echo ""
	@echo "🛠️  UTILITÀ:"
	@echo "   make backup       - Backup progetto"
	@echo "   make count        - Conta linee codice"

# ============================================================================
# TARGET PHONY
# ============================================================================

.PHONY: all debug run run-debug test test-memory check analyze gdb
.PHONY: info deps fix-headers list-files clean clean-all count backup help
