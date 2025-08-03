# Makefile semplice per esempio Doxygen
# Generato con doxygen -g (configurazione standard)

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = esempio_semplice
SOURCE = esempio_semplice.c

.PHONY: all clean docs open help

# Compilazione
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Esecuzione
run: $(TARGET)
	./$(TARGET)

# Generazione documentazione (usa Doxyfile standard)
docs:
	@echo "Generando documentazione con Doxyfile standard..."
	doxygen
	@echo "Documentazione generata in html/index.html"

# Apertura documentazione
open: docs
	@if [ -f "html/index.html" ]; then \
		open html/index.html; \
	else \
		echo "Documentazione non trovata. Esegui 'make docs' prima."; \
	fi

# Pulizia
clean:
	rm -f $(TARGET)
	rm -rf html latex

# Aiuto
help:
	@echo "Comandi disponibili:"
	@echo "  make          - Compila il programma"
	@echo "  make run      - Esegue il programma"
	@echo "  make docs     - Genera documentazione (Doxyfile standard)"
	@echo "  make open     - Genera e apre documentazione"
	@echo "  make clean    - Rimuove eseguibili e documentazione"
	@echo "  make help     - Mostra questo aiuto"
