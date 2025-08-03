# Makefile per Lez11 - Liste semplici, esercizi matrici e lista doppia
# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Target principali
TARGET_LISTE = liste
TARGET_MATRICI = esercizi_matrici
TARGET_DOPPIA = lista_doppia
SOURCE_LISTE = liste.c
SOURCE_MATRICI = esercizi_matrici.c
SOURCE_DOPPIA = lista_doppia.c

# Regola predefinita
all: $(TARGET_LISTE) $(TARGET_MATRICI) $(TARGET_DOPPIA)

# Compilazione del programma liste
$(TARGET_LISTE): $(SOURCE_LISTE)
	$(CC) $(CFLAGS) -o $(TARGET_LISTE) $(SOURCE_LISTE)
	@echo "Compilazione completata: $(TARGET_LISTE)"

# Compilazione del programma esercizi matrici
$(TARGET_MATRICI): $(SOURCE_MATRICI)
	$(CC) $(CFLAGS) -o $(TARGET_MATRICI) $(SOURCE_MATRICI)
	@echo "Compilazione completata: $(TARGET_MATRICI)"

# Esecuzione del programma liste
run-liste: $(TARGET_LISTE)
	@echo "=== Esecuzione di $(TARGET_LISTE) ==="
	./$(TARGET_LISTE)

# Esecuzione del programma esercizi matrici
run-matrici: $(TARGET_MATRICI)
	@echo "=== Esecuzione di $(TARGET_MATRICI) ==="
	./$(TARGET_MATRICI)

# Compilazione del programma lista doppia
$(TARGET_DOPPIA): $(SOURCE_DOPPIA)
	$(CC) $(CFLAGS) -o $(TARGET_DOPPIA) $(SOURCE_DOPPIA)
	@echo "Compilazione completata: $(TARGET_DOPPIA)"

# Esecuzione del programma lista doppia
run-doppia: $(TARGET_DOPPIA)
	@echo "=== Esecuzione di $(TARGET_DOPPIA) ==="
	./$(TARGET_DOPPIA)

# Esecuzione di tutti i programmi
run: run-liste run-matrici run-doppia

# Pulizia dei file compilati
clean:
	rm -f $(TARGET_LISTE) $(TARGET_MATRICI) $(TARGET_DOPPIA)
	@echo "File compilati rimossi"

# Test con valgrind (se disponibile)
test-memory: $(TARGET_LISTE) $(TARGET_MATRICI) $(TARGET_DOPPIA)
	@echo "=== Test memoria liste con valgrind ==="
	@if command -v valgrind > /dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_LISTE); \
	else \
		echo "valgrind non trovato, eseguo il programma normale"; \
		./$(TARGET_LISTE); \
	fi
	@echo "=== Test memoria matrici con valgrind ==="
	@if command -v valgrind > /dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_MATRICI); \
	else \
		echo "valgrind non trovato, eseguo il programma normale"; \
		./$(TARGET_MATRICI); \
	fi
	@echo "=== Test memoria lista doppia con valgrind ==="
	@if command -v valgrind > /dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_DOPPIA); \
	else \
		echo "valgrind non trovato, eseguo il programma normale"; \
		./$(TARGET_DOPPIA); \
	fi

# Aiuto
help:
	@echo "Target disponibili:"
	@echo "  all              - Compila tutti i programmi"
	@echo "  liste            - Compila solo il programma liste semplici"
	@echo "  esercizi_matrici - Compila solo il programma esercizi matrici"
	@echo "  lista_doppia     - Compila solo il programma lista doppia"
	@echo "  run              - Esegue tutti i programmi"
	@echo "  run-liste        - Esegue solo il programma liste semplici"
	@echo "  run-matrici      - Esegue solo il programma esercizi matrici"
	@echo "  run-doppia       - Esegue solo il programma lista doppia"
	@echo "  clean            - Rimuove i file compilati"
	@echo "  test-memory      - Test con valgrind (se disponibile)"
	@echo "  help             - Mostra questo aiuto"

# Dichiarazione dei target phony
.PHONY: all run run-liste run-matrici run-doppia clean test-memory help
