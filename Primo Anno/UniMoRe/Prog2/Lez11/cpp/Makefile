# Makefile per liste C++ 
# Compilatore e flag
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O2

# Target principali
TARGET_LISTE = liste
TARGET_DOPPIA = lista_doppia
SOURCE_LISTE = liste.cc
SOURCE_DOPPIA = lista_doppia.cc

# Regola predefinita
all: $(TARGET_LISTE) $(TARGET_DOPPIA)

# Compilazione del programma liste semplici
$(TARGET_LISTE): $(SOURCE_LISTE)
	$(CXX) $(CXXFLAGS) -o $(TARGET_LISTE) $(SOURCE_LISTE)
	@echo "Compilazione completata: $(TARGET_LISTE)"

# Compilazione del programma lista doppia
$(TARGET_DOPPIA): $(SOURCE_DOPPIA)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DOPPIA) $(SOURCE_DOPPIA)
	@echo "Compilazione completata: $(TARGET_DOPPIA)"

# Esecuzione del programma liste semplici
run-liste: $(TARGET_LISTE)
	@echo "=== Esecuzione di $(TARGET_LISTE) (C++) ==="
	./$(TARGET_LISTE)

# Esecuzione del programma lista doppia
run-doppia: $(TARGET_DOPPIA)
	@echo "=== Esecuzione di $(TARGET_DOPPIA) (C++) ==="
	./$(TARGET_DOPPIA)

# Esecuzione di tutti i programmi
run: run-liste run-doppia

# Pulizia dei file compilati
clean:
	rm -f $(TARGET_LISTE) $(TARGET_DOPPIA)
	rm -rf *.dSYM
	@echo "File compilati rimossi"

# Test con valgrind (se disponibile)
test-memory: $(TARGET_LISTE) $(TARGET_DOPPIA)
	@echo "=== Test memoria liste C++ con valgrind ==="
	@if command -v valgrind > /dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_LISTE); \
	else \
		echo "valgrind non trovato, eseguo il programma normale"; \
		./$(TARGET_LISTE); \
	fi
	@echo "=== Test memoria lista doppia C++ con valgrind ==="
	@if command -v valgrind > /dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET_DOPPIA); \
	else \
		echo "valgrind non trovato, eseguo il programma normale"; \
		./$(TARGET_DOPPIA); \
	fi

# Test performance
test-performance: $(TARGET_LISTE) $(TARGET_DOPPIA)
	@echo "=== Test performance (build ottimizzato) ==="
	$(CXX) $(CXXFLAGS) -O3 -DNDEBUG -o $(TARGET_LISTE)_fast $(SOURCE_LISTE)
	$(CXX) $(CXXFLAGS) -O3 -DNDEBUG -o $(TARGET_DOPPIA)_fast $(SOURCE_DOPPIA)
	@echo "Versioni ottimizzate create: $(TARGET_LISTE)_fast, $(TARGET_DOPPIA)_fast"

# Debug build
debug: CXXFLAGS += -DDEBUG -g3
debug: $(TARGET_LISTE) $(TARGET_DOPPIA)

# Controllo stile codice (se clang-tidy è disponibile)
lint:
	@if command -v clang-tidy > /dev/null 2>&1; then \
		echo "=== Controllo stile codice ==="; \
		clang-tidy $(SOURCE_LISTE) $(SOURCE_DOPPIA) -- $(CXXFLAGS); \
	else \
		echo "clang-tidy non trovato, salto il controllo stile"; \
	fi

# Aiuto
help:
	@echo "Target disponibili:"
	@echo "  all              - Compila tutti i programmi C++"
	@echo "  liste            - Compila solo il programma liste semplici"
	@echo "  lista_doppia     - Compila solo il programma lista doppia"
	@echo "  run              - Esegue tutti i programmi"
	@echo "  run-liste        - Esegue solo il programma liste semplici"
	@echo "  run-doppia       - Esegue solo il programma lista doppia"
	@echo "  clean            - Rimuove i file compilati"
	@echo "  test-memory      - Test con valgrind (se disponibile)"
	@echo "  test-performance - Crea versioni ottimizzate"
	@echo "  debug            - Build con simboli debug extra"
	@echo "  lint             - Controllo stile codice (se clang-tidy disponibile)"
	@echo "  help             - Mostra questo aiuto"

# Dichiarazione dei target phony
.PHONY: all run run-liste run-doppia clean test-memory test-performance debug lint help
