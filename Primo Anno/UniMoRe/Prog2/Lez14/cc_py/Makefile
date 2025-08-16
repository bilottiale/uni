# Makefile for C++/Python integration project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
PYTHON_FLAGS = $(shell python3-config --includes --ldflags)
PYTHON_LIBS = -lpython3.13
TARGET = main
SOURCE = main.cc
PYTHON_SCRIPT = script.py

# Main target
all: $(TARGET)

# Compile the C++ program with Python integration
$(TARGET): $(SOURCE)
	@echo "🔨 Compiling C++/Python integration program..."
	$(CXX) $(CXXFLAGS) $(PYTHON_FLAGS) $(PYTHON_LIBS) $(SOURCE) -o $(TARGET)
	@echo "✅ Compilation successful!"

# Run the program
run: $(TARGET)
	@echo "🚀 Running the program..."
	./$(TARGET)

# Test Python script independently
test-python:
	@echo "🐍 Testing Python script..."
	python3 -c "import script; print(script.saluta('Test'))"

# Clean generated files
clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	rm -rf __pycache__/
	@echo "✅ Cleanup complete!"

# Check Python environment
check-env:
	@echo "🔍 Checking Python environment..."
	@echo "Python version: $(shell python3 --version)"
	@echo "Python config includes: $(shell python3-config --includes)"
	@echo "Python config ldflags: $(shell python3-config --ldflags)"

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Create a comprehensive test
test: $(TARGET) test-python
	@echo "🧪 Running comprehensive test..."
	./$(TARGET)

# Show help
help:
	@echo "📚 Available commands:"
	@echo "  make all        - Compile the program"
	@echo "  make run        - Compile and run"
	@echo "  make test       - Run comprehensive tests"
	@echo "  make test-python - Test Python script only"
	@echo "  make debug      - Compile with debug symbols"
	@echo "  make check-env  - Check Python environment"
	@echo "  make clean      - Clean generated files"
	@echo "  make help       - Show this help"

.PHONY: all run test test-python clean check-env debug help
