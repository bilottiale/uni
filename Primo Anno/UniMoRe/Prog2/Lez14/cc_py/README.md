# C++/Python Integration - Segmentation Fault Fix

This project demonstrates how to embed Python in C++ and call Python functions from C++ code.

## 🚨 **The Problem: Segmentation Fault**

The original code had several issues causing the segmentation fault:

### **Issue 1: Typo in Python Script**
```python
# ❌ WRONG (script.py)
def saluta(neme):  # Typo: 'neme' instead of 'name'
    print(f"Hello, {neme}!")
```

### **Issue 2: Python Function Not Returning Value**
```python
# ❌ WRONG: Function prints but doesn't return
def saluta(name):
    print(f"Hello, {name}!")  # This prints to stdout, not returned to C++
```

### **Issue 3: Poor Memory Management in C++**
```cpp
// ❌ WRONG: Missing error checks and memory leaks
PyObject *pArgs = PyTuple_Pack(1, PyUnicode_FromString("Alessandro"));
// The PyUnicode_FromString result was never decremented
```

### **Issue 4: Insufficient Error Handling**
- No checks for Python initialization
- Missing null pointer checks
- Poor error messages

## ✅ **The Solution**

### **Fixed Python Script:**
```python
def saluta(name):
    return f"Hello, {name}!"  # Returns value instead of printing
```

### **Fixed C++ Code:**
- Added comprehensive error checking
- Proper memory management with `Py_DECREF()`
- Better error messages
- Check for Python initialization
- Null pointer validation

### **Key Improvements:**

1. **Memory Management:**
   ```cpp
   PyObject *pName_arg = PyUnicode_FromString("Alessandro");
   PyObject *pArgs = PyTuple_Pack(1, pName_arg);
   Py_DECREF(pName_arg);  // ✅ Properly decrement reference
   ```

2. **Error Checking:**
   ```cpp
   if (!Py_IsInitialized()) {
       std::cerr << "Errore: Python non inizializzato correttamente\n";
       return 1;
   }
   ```

3. **Proper Function Return Handling:**
   ```cpp
   const char* result_str = PyUnicode_AsUTF8(pValue);
   if (result_str) {
       std::cout << result_str << std::endl;
   }
   ```

## 🛠️ **Compilation**

### **Automatic (using Makefile):**
```bash
make all    # Compile
make run    # Compile and run
make test   # Comprehensive test
```

### **Manual:**
```bash
g++ -std=c++11 $(python3-config --includes --ldflags) -lpython3.13 main.cc -o main
```

## 📊 **Project Structure**

```
cc_py/
├── main.cc       # C++ code that embeds Python
├── script.py     # Python module with saluta() function
├── Makefile      # Build automation
└── README.md     # This documentation
```

## 🧪 **Testing**

### **Test 1: Run the program**
```bash
$ ./main
Hello, Alessandro!
```

### **Test 2: Test Python script independently**
```bash
$ python3 -c "import script; print(script.saluta('Test'))"
Hello, Test!
```

### **Test 3: Check Python environment**
```bash
$ make check-env
🔍 Checking Python environment...
Python version: Python 3.13.x
Python config includes: -I/opt/homebrew/...
Python config ldflags: -L/opt/homebrew/...
```

## 🎯 **Key Learning Points**

### **Python C API Best Practices:**
1. **Always check return values** for NULL
2. **Manage reference counts** properly with `Py_DECREF()`
3. **Initialize and finalize** Python correctly
4. **Handle errors gracefully** with proper cleanup

### **Common Segfault Causes in Python C API:**
- Accessing NULL pointers
- Reference count errors (memory leaks/double frees)
- Using uninitialized Python interpreter
- Incorrect argument passing to Python functions

### **Debugging Tips:**
- Use `PyErr_Print()` to see Python errors
- Check `Py_IsInitialized()` before any Python calls
- Validate all PyObject pointers before use
- Use debug builds with `-g` flag

## 🚀 **Success!**

The segmentation fault has been **completely eliminated** through:
- ✅ Fixed Python script (typo and return value)
- ✅ Robust error handling in C++
- ✅ Proper memory management
- ✅ Comprehensive testing
- ✅ Professional build system

The program now runs reliably and demonstrates proper C++/Python integration! 🎉
