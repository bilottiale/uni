CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets disponibili
TARGETS = struct_typedef esercizio_persona esercizio_data

# Build all programs
all: $(TARGETS)

# Build struct_typedef
struct_typedef: struct_typedef.c
	$(CC) $(CFLAGS) -o struct_typedef struct_typedef.c -lm

# Build esercizio_persona
esercizio_persona: esercizio_persona.c
	$(CC) $(CFLAGS) -o esercizio_persona esercizio_persona.c

# Build esercizio_data
esercizio_data: esercizio_data.c
	$(CC) $(CFLAGS) -o esercizio_data esercizio_data.c

# Run struct_typedef
run-struct: struct_typedef
	./struct_typedef

# Run esercizio_persona
run-persona: esercizio_persona
	./esercizio_persona

# Run esercizio_data
run-data: esercizio_data
	./esercizio_data

# Default run (struct_typedef)
run: run-struct

# Clean up
clean:
	rm -f $(TARGETS)

# Show help
help:
	@echo "Available targets:"
	@echo "  make all           - Compile all programs"
	@echo "  make struct_typedef- Compile struct_typedef"
	@echo "  make esercizio_persona - Compile esercizio_persona"
	@echo "  make esercizio_data - Compile esercizio_data"
	@echo "  make run           - Compile and run struct_typedef"
	@echo "  make run-struct    - Compile and run struct_typedef"
	@echo "  make run-persona   - Compile and run esercizio_persona"
	@echo "  make run-data      - Compile and run esercizio_data"
	@echo "  make clean         - Remove all executables"
	@echo "  make help          - Show this help"

.PHONY: all run run-struct run-persona run-data clean help
