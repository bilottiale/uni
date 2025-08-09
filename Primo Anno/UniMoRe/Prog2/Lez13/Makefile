# Makefile for gestione_lista_doppia_sol

CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wextra
TARGET = gestione_lista_doppia_sol
SOURCE = gestione_lista_doppia_sol.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
