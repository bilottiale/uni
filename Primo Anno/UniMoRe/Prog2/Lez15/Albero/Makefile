# Makefile per progetto Albero - Strutture Dati Alberi
# Implementazione di alberi con rappresentazione firstChild-nextSibling

# Configurazione compilatore
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -g
TARGET = albero
SRCDIR = .
OBJDIR = obj

# File sorgenti e oggetti
SOURCES = main.cc tree.cc tipo.cc
OBJECTS = $(SOURCES:%.cc=$(OBJDIR)/%.o)
HEADERS = tree.h tipo.h

# Regola principale
all: $(OBJDIR) $(TARGET)

# Creazione directory oggetti
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regola per l'eseguibile finale
$(TARGET): $(OBJECTS)
	@echo "🌳 Linking del progetto Albero..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "✅ Compilazione completata: $(TARGET)"

# Regole per i file oggetto (con dipendenze dai headers)
$(OBJDIR)/main.o: main.cc tree.h tipo.h
	@echo "🔨 Compilando main.cc..."
	$(CXX) $(CXXFLAGS) -c main.cc -o $(OBJDIR)/main.o

$(OBJDIR)/tree.o: tree.cc tree.h tipo.h
	@echo "🔨 Compilando tree.cc..."
	$(CXX) $(CXXFLAGS) -c tree.cc -o $(OBJDIR)/tree.o

$(OBJDIR)/tipo.o: tipo.cc tipo.h
	@echo "🔨 Compilando tipo.cc..."
	$(CXX) $(CXXFLAGS) -c tipo.cc -o $(OBJDIR)/tipo.o

# Versione debug (con output di debug abilitato)
debug: CXXFLAGS += -DDEBUG -O0
debug: clean $(TARGET)
	@echo "🐛 Build debug completato con flag DEBUG abilitato"

# Versione release (senza debug, ottimizzata)
release: CXXFLAGS += -DNDEBUG -O2
release: clean $(TARGET)
	@echo "🚀 Build release completato (ottimizzato, no debug)"

# Pulizia
clean:
	@echo "🧹 Pulizia files generati..."
	rm -rf $(OBJDIR) $(TARGET)
	@echo "✅ Pulizia completata"

# Pulizia completa (inclusi backup e temporanei)
distclean: clean
	rm -f *~ *.bak *.tmp core

# Esecuzione del programma
run: $(TARGET)
	@echo "🚀 Esecuzione del programma Albero..."
	./$(TARGET)

# Esecuzione in modalità debug (mostra output di debug)
run-debug: debug
	@echo "🐛 Esecuzione in modalità debug..."
	./$(TARGET)

# Esecuzione in modalità release (senza output di debug)
run-release: release
	@echo "🚀 Esecuzione in modalità release..."
	./$(TARGET)

# Debug con gdb
gdb: debug
	@echo "🔍 Avvio debugger GDB..."
	gdb ./$(TARGET)

# Debug con valgrind (controllo memory leaks)
valgrind: debug
	@echo "🔍 Controllo memory leaks con Valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Informazioni sul progetto
info:
	@echo "🌳 Informazioni Progetto Albero:"
	@echo "  Target: $(TARGET)"
	@echo "  Sorgenti: $(SOURCES)"
	@echo "  Headers: $(HEADERS)"
	@echo "  Oggetti: $(OBJECTS)"
	@echo "  Compilatore: $(CXX) $(CXXFLAGS)"
	@echo "  Struttura: Albero con rappresentazione firstChild-nextSibling"

# Controllo dipendenze headers
deps:
	@echo "🔍 Analisi dipendenze:"
	@echo "  main.cc dipende da: tree.h tipo.h"
	@echo "  tree.cc dipende da: tree.h tipo.h"
	@echo "  tipo.cc dipende da: tipo.h"

# Controllo sintassi (solo compilazione, no linking)
check:
	@echo "✅ Controllo sintassi di tutti i moduli..."
	$(CXX) $(CXXFLAGS) -c main.cc -o /dev/null
	$(CXX) $(CXXFLAGS) -c tree.cc -o /dev/null
	$(CXX) $(CXXFLAGS) -c tipo.cc -o /dev/null
	@echo "✅ Tutti i moduli sono sintatticamente corretti"

# Analisi statica del codice
analyze:
	@echo "🔍 Analisi statica del codice..."
	$(CXX) $(CXXFLAGS) -fsyntax-only -Wall -Wextra -Wpedantic main.cc tree.cc tipo.cc
	@echo "✅ Analisi completata"

# Generazione documentazione con Doxygen (se disponibile)
docs:
	@if command -v doxygen >/dev/null 2>&1; then \
		echo "📚 Generazione documentazione con Doxygen..."; \
		doxygen -g Doxyfile.tmp; \
		echo "INPUT = ." >> Doxyfile.tmp; \
		echo "RECURSIVE = YES" >> Doxyfile.tmp; \
		doxygen Doxyfile.tmp; \
		rm Doxyfile.tmp; \
		echo "✅ Documentazione generata in html/"; \
	else \
		echo "❌ Doxygen non installato. Installa con: brew install doxygen"; \
	fi

# Installazione (copia in /usr/local/bin)
install: release
	@echo "📦 Installazione in /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✅ Installazione completata"

# Backup del progetto
backup:
	@echo "💾 Creazione backup..."
	tar -czf albero_backup_$(shell date +%Y%m%d_%H%M%S).tar.gz *.cc *.h Makefile
	@echo "✅ Backup completato"

# Test della struttura albero
test: $(TARGET)
	@echo "🧪 Test della struttura Albero..."
	@echo "Creazione albero con nodi: Luca (root), Paolo, Marco, Lucia, Anna"
	./$(TARGET)
	@echo "✅ Test completato"

# Benchmark performance (se necessario)
benchmark: release
	@echo "⚡ Benchmark performance..."
	time ./$(TARGET)

# Help
help:
	@echo "🆘 Comandi disponibili:"
	@echo "  make all         - Compila il progetto completo"
	@echo "  make debug       - Compila in modalità debug"
	@echo "  make release     - Compila in modalità release"
	@echo "  make clean       - Rimuove files generati"
	@echo "  make run         - Compila ed esegue"
	@echo "  make run-debug   - Esegue in modalità debug"
	@echo "  make run-release - Esegue in modalità release"
	@echo "  make gdb         - Avvia con debugger GDB"
	@echo "  make valgrind    - Controllo memory leaks"
	@echo "  make check       - Controllo sintassi"
	@echo "  make analyze     - Analisi statica codice"
	@echo "  make test        - Test della struttura"
	@echo "  make docs        - Genera documentazione"
	@echo "  make info        - Informazioni progetto"
	@echo "  make deps        - Mostra dipendenze"
	@echo "  make backup      - Crea backup del progetto"
	@echo "  make install     - Installa in sistema"
	@echo "  make benchmark   - Test performance"
	@echo "  make help        - Mostra questo aiuto"

# Regole PHONY (non corrispondono a file)
.PHONY: all debug release clean distclean run run-debug run-release gdb valgrind info deps check analyze docs install backup test benchmark help

# Regola di default se si scrive solo 'make'
.DEFAULT_GOAL := all
