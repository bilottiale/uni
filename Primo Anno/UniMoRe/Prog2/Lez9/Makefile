CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets disponibili
TARGETS = alert_example stringhe

# Build all programs
all: $(TARGETS)

# Build alert_example
alert_example: alert_example.c
	$(CC) $(CFLAGS) -o alert_example alert_example.c

# Build stringhe
stringhe: stringhe.c
	$(CC) $(CFLAGS) -o stringhe stringhe.c

# Run alert_example
run-alert: alert_example
	./alert_example

# Run stringhe
run-stringhe: stringhe
	./stringhe

# Default run (stringhe)
run: run-stringhe

# Clean up
clean:
	rm -f $(TARGETS)

# Show help
help:
	@echo "Available targets:"
	@echo "  make all           - Compile all programs"
	@echo "  make alert_example - Compile alert_example"
	@echo "  make stringhe      - Compile stringhe"
	@echo "  make run           - Compile and run stringhe"
	@echo "  make run-alert     - Compile and run alert_example"
	@echo "  make run-stringhe  - Compile and run stringhe"
	@echo "  make clean         - Remove all executables"
	@echo "  make help          - Show this help"

.PHONY: all run run-alert run-stringhe clean help
