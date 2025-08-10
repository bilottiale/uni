# Makefile for primo_prog_multifile

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra
TARGET = main
SOURCES = main.cc fun.cc
OBJECTS = $(SOURCES:.cc=.o)

# Regola principale
all: $(TARGET)

# Regola per il target finale
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regola per compilare i file oggetto
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -f $(OBJECTS) $(TARGET)

# Esecuzione
run: $(TARGET)
	./$(TARGET)

# Test con input predefinito
test: $(TARGET)
	echo "42" | ./$(TARGET)

# Mostra informazioni
info:
	@echo "Sorgenti: $(SOURCES)"
	@echo "Oggetti: $(OBJECTS)"
	@echo "Target: $(TARGET)"

.PHONY: all clean run test info
