# Makefile per il progetto inverted index
CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -g
TARGET = main
OBJ = main.o liste.o tipo.o

# Regola principale
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "Compilazione completata: $(TARGET)"

main.o: main.cc tipo.h liste.h parola.h
	$(CC) $(CFLAGS) -c main.cc

liste.o: liste.cc tipo.h liste.h
	$(CC) $(CFLAGS) -c liste.cc

tipo.o: tipo.cc tipo.h
	$(CC) $(CFLAGS) -c tipo.cc

# Esecuzione
run: $(TARGET)
	@echo "=== Esecuzione del programma ==="
	./$(TARGET)

# Test con input automatico
test: $(TARGET)
	@echo "=== Test automatico ==="
	@echo -e "newdoc.txt\nhello\nworld" | ./$(TARGET)

# Pulizia
clean:
	rm -f *.o
	@echo "File oggetto rimossi"

cleanall:
	rm -f $(TARGET) *.o
	@echo "Tutti i file compilati rimossi"

# Help
help:
	@echo "Target disponibili:"
	@echo "  all      - Compila il programma"
	@echo "  run      - Esegue il programma"
	@echo "  test     - Esegue il test automatico"
	@echo "  clean    - Rimuove i file oggetto"
	@echo "  cleanall - Rimuove tutti i file compilati"
	@echo "  help     - Mostra questo aiuto"

.PHONY: all run test clean cleanall help