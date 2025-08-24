# Compilatore e flag
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I../../Lez20/grafo

# Nome dell'eseguibile
TARGET = dijkstra

# Sorgenti principali
SRCS = dijkstra.cc codap.cc

# Oggetti principali (derivati dai sorgenti)
OBJS = $(SRCS:.cc=.o)

# Path e oggetti del modulo grafo
GRAFO_DIR = ../../Lez20/grafo
GRAFO_SRCS = $(GRAFO_DIR)/grafo.cc
GRAFO_OBJS = $(GRAFO_SRCS:.cc=.o)

# Tutti gli oggetti necessari
ALL_OBJS = $(OBJS) $(GRAFO_OBJS)

# Target di default
all: $(TARGET)

# Regola per linkare l'eseguibile
$(TARGET): $(ALL_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(ALL_OBJS)

# Regola per compilare i sorgenti nella directory corrente
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regola per compilare i sorgenti del modulo grafo
$(GRAFO_DIR)/%.o: $(GRAFO_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target per pulire la directory
clean:
	rm -f $(TARGET) $(ALL_OBJS)
	rm -rf doxygen_output

# Target per eseguire il programma
run: all
	./$(TARGET)

# Target per generare la documentazione
docs:
	./generate_docs.sh

# Evita conflitti con file chiamati 'all', 'clean', 'run', 'docs'
.PHONY: all clean run docs
