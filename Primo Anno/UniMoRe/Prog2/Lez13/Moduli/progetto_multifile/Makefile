# Makefile per progetto_multifile - Gestione Liste Doppie
# Progetto modulare con separazione headers/implementazione

# Configurazione compilatore
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -g
TARGET = gestione_liste
SRCDIR = .
OBJDIR = obj

# File sorgenti e oggetti
SOURCES = main.cc liste.cc liste-tipo.cc fun-app.cc
OBJECTS = $(SOURCES:%.cc=$(OBJDIR)/%.o)
HEADERS = liste.h liste-tipo.h fun-app.h

# Regola principale
all: $(OBJDIR) $(TARGET)

# Creazione directory oggetti
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regola per l'eseguibile finale
$(TARGET): $(OBJECTS)
	@echo "🔗 Linking del progetto..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "✅ Compilazione completata: $(TARGET)"

# Regole per i file oggetto (con dipendenze dai headers)
$(OBJDIR)/main.o: main.cc liste-tipo.h fun-app.h
	@echo "🔨 Compilando main.cc..."
	$(CXX) $(CXXFLAGS) -c main.cc -o $(OBJDIR)/main.o

$(OBJDIR)/liste.o: liste.cc liste-tipo.h liste.h
	@echo "🔨 Compilando liste.cc..."
	$(CXX) $(CXXFLAGS) -c liste.cc -o $(OBJDIR)/liste.o

$(OBJDIR)/liste-tipo.o: liste-tipo.cc liste-tipo.h
	@echo "🔨 Compilando liste-tipo.cc..."
	$(CXX) $(CXXFLAGS) -c liste-tipo.cc -o $(OBJDIR)/liste-tipo.o

$(OBJDIR)/fun-app.o: fun-app.cc fun-app.h liste-tipo.h liste.h
	@echo "🔨 Compilando fun-app.cc..."
	$(CXX) $(CXXFLAGS) -c fun-app.cc -o $(OBJDIR)/fun-app.o

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
	@echo "🚀 Esecuzione del programma..."
	./$(TARGET)

# Test con input predefinito
test: $(TARGET)
	@echo "🧪 Test automatico del programma..."
	@echo -e "1\n3\nURL1\nURL2\nURL3\n3\n5" | ./$(TARGET)

# Debug con gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Informazioni sul progetto
info:
	@echo "📋 Informazioni Progetto:"
	@echo "  Target: $(TARGET)"
	@echo "  Sorgenti: $(SOURCES)"
	@echo "  Headers: $(HEADERS)"
	@echo "  Oggetti: $(OBJECTS)"
	@echo "  Compilatore: $(CXX) $(CXXFLAGS)"

# Controllo dipendenze headers
deps:
	@echo "🔍 Analisi dipendenze:"
	@echo "  main.cc dipende da: liste-tipo.h fun-app.h"
	@echo "  liste.cc dipende da: liste-tipo.h liste.h"
	@echo "  liste-tipo.cc dipende da: liste-tipo.h"
	@echo "  fun-app.cc dipende da: fun-app.h liste-tipo.h liste.h"

# Installazione (copia in /usr/local/bin)
install: $(TARGET)
	@echo "📦 Installazione in /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✅ Installazione completata"

# Backup del progetto
backup:
	@echo "💾 Creazione backup..."
	tar -czf progetto_multifile_backup_$(shell date +%Y%m%d_%H%M%S).tar.gz *.cc *.h Makefile
	@echo "✅ Backup completato"

# Controllo sintassi (solo compilazione, no linking)
check:
	@echo "✅ Controllo sintassi di tutti i moduli..."
	$(CXX) $(CXXFLAGS) -c main.cc -o /dev/null
	$(CXX) $(CXXFLAGS) -c liste.cc -o /dev/null
	$(CXX) $(CXXFLAGS) -c liste-tipo.cc -o /dev/null
	$(CXX) $(CXXFLAGS) -c fun-app.cc -o /dev/null
	@echo "✅ Tutti i moduli sono sintatticamente corretti"

# Help
help:
	@echo "🆘 Comandi disponibili:"
	@echo "  make all      - Compila il progetto completo"
	@echo "  make clean    - Rimuove files generati"
	@echo "  make run      - Compila ed esegue"
	@echo "  make test     - Test automatico"
	@echo "  make debug    - Avvia con debugger"
	@echo "  make check    - Controllo sintassi"
	@echo "  make info     - Informazioni progetto"
	@echo "  make deps     - Mostra dipendenze"
	@echo "  make backup   - Crea backup del progetto"
	@echo "  make install  - Installa in sistema"
	@echo "  make help     - Mostra questo aiuto"

# Regole PHONY (non corrispondono a file)
.PHONY: all clean distclean run test debug info deps install backup check help

# Regola di default se si scrive solo 'make'
.DEFAULT_GOAL := all
