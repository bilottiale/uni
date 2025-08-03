CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets disponibili
TARGETS = stringhe string string-cli string-fgets string-strtol string-strtof

# Build all programs
all: $(TARGETS)

# Build stringhe
stringhe: stringhe.c
	$(CC) $(CFLAGS) -o stringhe stringhe.c

# Build string
string: string.c
	$(CC) $(CFLAGS) -o string string.c

# Build string-cli
string-cli: string-cli.c
	$(CC) $(CFLAGS) -o string-cli string-cli.c

# Build string-fgets
string-fgets: string-fgets.c
	$(CC) $(CFLAGS) -o string-fgets string-fgets.c

# Build string-strtol
string-strtol: string-strtol.c
	$(CC) $(CFLAGS) -o string-strtol string-strtol.c

# Build string-strtof
string-strtof: string-strtof.c
	$(CC) $(CFLAGS) -o string-strtof string-strtof.c

# Run stringhe
run-stringhe: stringhe
	./stringhe

# Run string
run-string: string
	./string

# Run string-cli
run-cli: string-cli
	./string-cli

# Run string-fgets
run-fgets: string-fgets
	./string-fgets

# Run string-strtol
run-strtol: string-strtol
	./string-strtol

# Run string-strtof
run-strtof: string-strtof
	./string-strtof

# Default run (stringhe)
run: run-stringhe

# Clean up
clean:
	rm -f $(TARGETS)

# Show help
help:
	@echo "Available targets:"
	@echo "  make all           - Compile all programs"
	@echo "  make stringhe      - Compile stringhe"
	@echo "  make string        - Compile string"
	@echo "  make string-cli    - Compile string-cli"
	@echo "  make string-fgets  - Compile string-fgets"
	@echo "  make string-strtol - Compile string-strtol"
	@echo "  make string-strtof - Compile string-strtof"
	@echo "  make run           - Compile and run stringhe"
	@echo "  make run-stringhe  - Compile and run stringhe"
	@echo "  make run-string    - Compile and run string"
	@echo "  make run-cli       - Compile and run string-cli"
	@echo "  make run-fgets     - Compile and run string-fgets"
	@echo "  make run-strtol    - Compile and run string-strtol"
	@echo "  make run-strtof    - Compile and run string-strtof"
	@echo "  make clean         - Remove all executables"
	@echo "  make help          - Show this help"

.PHONY: all run run-stringhe run-string run-cli run-fgets run-strtol run-strtof clean help
