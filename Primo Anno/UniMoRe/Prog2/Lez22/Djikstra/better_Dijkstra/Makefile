# Makefile per l'algoritmo di Dijkstra migliorato
# Versione con std::priority_queue, gestione errori e programmazione OOP

# Compilatore e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -g

# Directory e file
GRAFO_DIR = ../../../Lez20/grafo
CURRENT_DIR = .

# File sorgente
SOURCES = main.cc better_dijkstra.cc $(GRAFO_DIR)/grafo.cc
HEADERS = better_dijkstra.h $(GRAFO_DIR)/grafo.h

# File oggetto
OBJECTS = main.o better_dijkstra.o grafo.o

# Target principale
TARGET = better_dijkstra

# Include directory
INCLUDES = -I$(GRAFO_DIR)

# ==============================================================================
# REGOLE DI COMPILAZIONE
# ==============================================================================

# Regola principale: compila il programma
all: $(TARGET)
	@echo "✅ Compilazione completata!"
	@echo "🚀 Usa: ./$(TARGET) [file_grafo]"

# Linking dell'eseguibile
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilazione file main
main.o: main.cc better_dijkstra.h
	@echo "🔧 Compilando main.cc..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cc

# Compilazione implementazione Dijkstra migliorata  
better_dijkstra.o: better_dijkstra.cc better_dijkstra.h
	@echo "🔧 Compilando better_dijkstra.cc..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c better_dijkstra.cc

# Compilazione modulo grafo
grafo.o: $(GRAFO_DIR)/grafo.cc $(GRAFO_DIR)/grafo.h
	@echo "🔧 Compilando grafo.cc..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(GRAFO_DIR)/grafo.cc

# ==============================================================================
# REGOLE DI PULIZIA
# ==============================================================================

# Pulizia file oggetto
clean:
	@echo "🧹 Pulizia file oggetto..."
	rm -f $(OBJECTS)

# Pulizia completa
distclean: clean
	@echo "🧹 Pulizia completa..."
	rm -f $(TARGET)

# ==============================================================================
# REGOLE DI TEST E ESECUZIONE
# ==============================================================================

# Test con file di esempio
test: $(TARGET)
	@echo "🧪 Esecuzione test con graph1.w..."
	./$(TARGET) ../file-grafo/graph1.w

# Test interattivo
test-interactive: $(TARGET)
	@echo "🎮 Test interattivo - inserisci tu il nodo sorgente:"
	./$(TARGET)

# ==============================================================================
# REGOLE DI DOCUMENTAZIONE
# ==============================================================================

# Genera documentazione Doxygen
docs:
	@echo "📚 Generazione documentazione..."
	@if [ -f "Doxyfile" ]; then \
		doxygen Doxyfile; \
		echo "✅ Documentazione generata in docs/html/"; \
	else \
		echo "❌ File Doxyfile non trovato!"; \
	fi

# ==============================================================================
# REGOLE DI DEBUG E ANALISI
# ==============================================================================

# Compilazione per debug
debug: CXXFLAGS += -DDEBUG -O0
debug: $(TARGET)
	@echo "🐛 Versione debug compilata"

# Analisi con Valgrind (se disponibile)
valgrind: $(TARGET)
	@echo "🔍 Analisi memoria con Valgrind..."
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) ../file-grafo/graph1.w; \
	else \
		echo "❌ Valgrind non disponibile"; \
	fi

# ==============================================================================
# INFORMAZIONI E AIUTO
# ==============================================================================

# Mostra informazioni sui miglioramenti
info:
	@echo "📊 MIGLIORAMENTI IMPLEMENTATI:"
	@echo "1. 📊 std::priority_queue invece di lista custom"
	@echo "2. 🧹 Gestione automatica memoria (RAII)"  
	@echo "3. 🚦 Gestione errori completa"
	@echo "4. 🧩 Programmazione OOP (classe DijkstraSolver)"
	@echo "5. 📝 Documentazione Doxygen estesa"
	@echo ""
	@echo "🎯 VANTAGGI:"
	@echo "   • Complessità migliorata: O((V+E) log V)"
	@echo "   • Nessun memory leak (RAII)"
	@echo "   • Codice più robusto e manutenibile"
	@echo "   • Gestione errori granulare"
	@echo "   • Interfaccia pulita e riusabile"

# Aiuto comandi disponibili
help:
	@echo "🛠️  COMANDI MAKEFILE DISPONIBILI:"
	@echo ""
	@echo "📦 COMPILAZIONE:"
	@echo "   make          - Compila il programma"
	@echo "   make debug    - Compila versione debug"
	@echo "   make clean    - Rimuove file oggetto"
	@echo "   make distclean- Pulizia completa"
	@echo ""
	@echo "🧪 TEST:"
	@echo "   make test     - Test automatico con graph1.w"
	@echo "   make test-interactive - Test interattivo"
	@echo "   make valgrind - Analisi memoria"
	@echo ""
	@echo "📚 DOCUMENTAZIONE:"
	@echo "   make docs     - Genera documentazione Doxygen"
	@echo "   make info     - Mostra miglioramenti implementati"
	@echo "   make help     - Mostra questo aiuto"

# ==============================================================================
# DICHIARAZIONI PHONY
# ==============================================================================

.PHONY: all clean distclean test test-interactive docs debug valgrind info help
