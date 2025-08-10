# To compile without linking
gcc -c 02-stampa.cpp

# To create static lib
ar rcs libstampa.a 02-stampa.o
# To link a lib
gcc 02-main.cpp -L . -l stampa -l stdc++

# object files for shared libraries need to be compiled as position independent
# code (-fPIC) because they are mapped to any position in the address space.
gcc -c -fPIC 02-stampa.cpp

# To link a dynamic lib (it won't be included in the executable)
gcc 02-stampa.o -shared -o libstampa.so