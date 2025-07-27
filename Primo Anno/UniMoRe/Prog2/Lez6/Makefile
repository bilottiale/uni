# Makefile for C programs in Lez6
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS = -g -O0 -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

# Source files
POINTERS_SRC = pointers.c
FUNC_SRC = func.c

# Executable names
POINTERS_EXE = pointers
FUNC_EXE = func

# Default target
all: $(POINTERS_EXE) $(FUNC_EXE)

# Build pointers program
$(POINTERS_EXE): $(POINTERS_SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Build func program
$(FUNC_EXE): $(FUNC_SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Debug builds
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(POINTERS_EXE) $(FUNC_EXE)

# Release builds
release: CFLAGS += $(RELEASE_FLAGS)
release: $(POINTERS_EXE) $(FUNC_EXE)

# Run pointers program
run-pointers: $(POINTERS_EXE)
	./$(POINTERS_EXE)

# Run pointers program without colors
run-pointers-no-color: $(POINTERS_EXE)
	NO_COLOR=1 ./$(POINTERS_EXE)

# Run func program
run-func: $(FUNC_EXE)
	./$(FUNC_EXE)

# Run all programs
run: run-pointers run-func

# Clean build artifacts
clean:
	rm -f $(POINTERS_EXE) $(FUNC_EXE)
	rm -rf *.dSYM

# Clean and rebuild
rebuild: clean all

# Check for memory leaks (requires valgrind on Linux, or use leaks on macOS)
valgrind-pointers: $(POINTERS_EXE)
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind --leak-check=full --show-leak-kinds=all ./$(POINTERS_EXE); \
	elif command -v leaks >/dev/null 2>&1; then \
		leaks --atExit -- ./$(POINTERS_EXE); \
	else \
		echo "Neither valgrind nor leaks found. Install one for memory checking."; \
	fi

# Help target
help:
	@echo "Available targets:"
	@echo "  all                  - Build all programs (default)"
	@echo "  pointers             - Build pointers program"
	@echo "  func                 - Build func program"
	@echo "  debug                - Build with debug flags"
	@echo "  release              - Build with optimization flags"
	@echo "  run-pointers         - Build and run pointers program"
	@echo "  run-pointers-no-color- Build and run pointers program without colors"
	@echo "  run-func             - Build and run func program"
	@echo "  run                  - Build and run all programs"
	@echo "  clean                - Remove built executables and debug symbols"
	@echo "  rebuild              - Clean and build all"
	@echo "  valgrind-pointers    - Run pointers with memory checker"
	@echo "  help                 - Show this help message"

# Declare phony targets
.PHONY: all debug release run-pointers run-pointers-no-color run-func run clean rebuild valgrind-pointers help
